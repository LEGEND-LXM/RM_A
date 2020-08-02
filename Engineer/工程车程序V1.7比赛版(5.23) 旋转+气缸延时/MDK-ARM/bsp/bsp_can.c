/******************************************************************************
/// @brief
/// @copyright Copyright (c) 2017 <dji-innovations, Corp. RM Dept.>
/// @license MIT License
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction,including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense,and/or sell
/// copies of the Software, and to permit persons to whom the Software is furnished
/// to do so,subject to the following conditions:
///
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
/// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
*******************************************************************************/

#include "can.h"
#include "bsp_can.h"



moto_measure_t moto_chassis[7] = {0};//4 chassis moto
moto_measure_t gimbal_pit_motor_measure,gimbal_yaw_motor_measure;
moto_measure_t moto1_chassis[7] = {0};//4 chassis moto

uint8_t MotorTxData[8] = {0};    //底盘控制
uint8_t HeadTxData[8] = {0,0,0,0,0,0,0,0};     //云台控制


void get_total_angle(moto_measure_t *p);
void get_moto_offset(moto_measure_t *ptr, CAN_HandleTypeDef* hcan);

/*******************************************************************************************
  * @Func		my_can_filter_init
  * @Brief    CAN1和CAN2滤波器配置
  * @Param		CAN_HandleTypeDef* hcan
  * @Retval		None
  * @Date     2015/11/30
 *******************************************************************************************/
void my_can_filter_init_recv_all(CAN_HandleTypeDef* _hcan)
{
	//can1 &can2 use same filter config
	CAN_FilterConfTypeDef		CAN_FilterConfigStructure;
	static CanTxMsgTypeDef		Tx1Message;
	static CanRxMsgTypeDef 		Rx1Message;
	static CanTxMsgTypeDef		Tx2Message;
	static CanRxMsgTypeDef 		Rx2Message;


//	CAN_FilterConfigStructure.FilterNumber = 0;
	CAN_FilterConfigStructure.FilterMode = CAN_FILTERMODE_IDMASK;
	CAN_FilterConfigStructure.FilterScale = CAN_FILTERSCALE_32BIT;
	CAN_FilterConfigStructure.FilterIdHigh = 0x0000;
	CAN_FilterConfigStructure.FilterIdLow = 0x0000;
	CAN_FilterConfigStructure.FilterMaskIdHigh = 0x0000;
	CAN_FilterConfigStructure.FilterMaskIdLow = 0x0000;
	CAN_FilterConfigStructure.FilterFIFOAssignment = CAN_FilterFIFO0;
	CAN_FilterConfigStructure.BankNumber = 14;//can1(0-13)和can2(14-27)分别得到一半的filter
	CAN_FilterConfigStructure.FilterActivation = ENABLE;

	if(HAL_CAN_ConfigFilter(_hcan, &CAN_FilterConfigStructure) != HAL_OK)
	{
		//err_deadloop(); //show error!
	}


if(_hcan == &hcan1)
  {
    CAN_FilterConfigStructure.FilterNumber = 0;
    _hcan->pTxMsg = &Tx1Message;
    _hcan->pRxMsg = &Rx1Message;
  }
  if(_hcan == &hcan2)
  {
		CAN_FilterConfigStructure.FilterNumber = 14;
    _hcan->pTxMsg = &Tx2Message;
    _hcan->pRxMsg = &Rx2Message;
  }


}

uint32_t FlashTimer;
uint8_t flag=RESET;
/*******************************************************************************************
  * @Func			void HAL_CAN_RxCpltCallback(CAN_HandleTypeDef* _hcan)
  * @Brief    HAL库中标准的CAN接收完成回调函数，需要在此处理通过CAN总线接收到的数据
  * @Param		
  * @Retval		None 
  * @Date     
 *******************************************************************************************/
void HAL_CAN_RxCpltCallback(CAN_HandleTypeDef* _hcan)
{

	if(HAL_GetTick() - FlashTimer>500)//每1s闪烁一次LED_S灯
	{
			
		HAL_GPIO_TogglePin(LED_S_GPIO_Port,LED_S_Pin);
		FlashTimer = HAL_GetTick();
		
	}
	//ignore can1 or can2.
	switch(_hcan->pRxMsg->StdId){
		case CAN_3508Moto1_ID:
		case CAN_3508Moto2_ID:
		case CAN_3508Moto3_ID:
		case CAN_3508Moto4_ID:
		case CAN_3508Moto5_ID:
		case CAN_3508Moto6_ID:
		case CAN_3508Moto7_ID:
			{
				static u8 i;
				i = _hcan->pRxMsg->StdId - CAN_3508Moto1_ID;//依次读取ID号
				if(_hcan->Instance==CAN1){
					get_moto_measure(&moto_chassis[i], _hcan);
					__HAL_CAN_ENABLE_IT(&hcan1, CAN_IT_FMP0);
				}
					if(_hcan->Instance==CAN2){
					get_moto_measure(&moto1_chassis[i], _hcan);
						__HAL_CAN_ENABLE_IT(&hcan2, CAN_IT_FMP0);
				}
			}
			break;
	}
	/*#### add enable can it again to solve can receive only one ID problem!!!####**/
	flag=SET;
}

/*******************************************************************************************
  * @Func			void get_moto_measure(moto_measure_t *ptr, CAN_HandleTypeDef* hcan)
  * @Brief    接收3508和2006电机通过CAN发过来的信息
  * @Param		
  * @Retval		None
  * @Date    
 *******************************************************************************************/
void get_moto_measure(moto_measure_t *ptr, CAN_HandleTypeDef* hcan)
{

//	ptr->last_angle = ptr->angle;
	ptr->angle = (uint16_t)(hcan->pRxMsg->Data[0]<<8 | hcan->pRxMsg->Data[1]) ;  //获得机械角度
	ptr->speed_rpm  = (int16_t)(hcan->pRxMsg->Data[2]<<8 | hcan->pRxMsg->Data[3]);//获得转速
	ptr->real_current = (hcan->pRxMsg->Data[4]<<8 | hcan->pRxMsg->Data[5])*5.f/16384.f;//获得转矩

	ptr->hall = hcan->pRxMsg->Data[6];//获得电机温度，注意：2006电机无法获得
	
	
	if(ptr->angle - ptr->last_angle > 4096)
		ptr->round_cnt --;
	else if (ptr->angle - ptr->last_angle < -4096)
		ptr->round_cnt ++;
	get_total_angle(ptr);
}

/*this function should be called after system+can init */
void get_moto_offset(moto_measure_t *ptr, CAN_HandleTypeDef* hcan)
{
	ptr->angle = (uint16_t)(hcan->pRxMsg->Data[0]<<8 | hcan->pRxMsg->Data[1]) ;
	ptr->offset_angle = ptr->angle;
}

#define ABS(x)	( (x>0) ? (x) : (-x) )
/**
*@bref 电机上电角度=0， 之后用这个函数更新3510电机的相对开机后（为0）的相对角度。
	*/
void get_total_angle(moto_measure_t *p){
	int res1, res2;
	float delta, temp;
	if(p->angle < p->last_angle){			//可能的情况
		res1 = p->angle + 8192 - p->last_angle;	//正转，delta=+
		res2 = p->angle - p->last_angle;				//反转	delta=-
		if(ABS(res1)<ABS(res2)){//不管正反转，肯定是转的角度小的那个是真的
			delta = res1;
			p->round_cnt++;
		}
		else{
			delta = res2;
			p->round_cnt--;
		}
	}else{	//angle > last
		res1 = p->angle - 8192 - p->last_angle ;//反转	delta -
		res2 = p->angle - p->last_angle;				//正转	delta +
		if(ABS(res1)<ABS(res2)){
			delta = res1;
			p->round_cnt--;
		}
		else{
			delta = res2;
			p->round_cnt++;
		}
	}
	temp = delta*0.002313;//输出轴角度
	p->total_angle += temp;
	p->last_angle = p->angle;
}

void set_moto_current(CAN_HandleTypeDef* hcan, s16 iq1, s16 iq2, s16 iq3, s16 iq4){

	hcan->pTxMsg->StdId = 0x200;
	hcan->pTxMsg->IDE = CAN_ID_STD;
	hcan->pTxMsg->RTR = CAN_RTR_DATA;
	hcan->pTxMsg->DLC = 0x08;
	hcan->pTxMsg->Data[0] = (iq1 >> 8);
	hcan->pTxMsg->Data[1] = iq1;
	hcan->pTxMsg->Data[2] = (iq2 >> 8);
	hcan->pTxMsg->Data[3] = iq2;
	hcan->pTxMsg->Data[4] = iq3 >> 8;
	hcan->pTxMsg->Data[5] = iq3;
	hcan->pTxMsg->Data[6] = iq4 >> 8;
	hcan->pTxMsg->Data[7] = iq4;
	HAL_CAN_Transmit(hcan, 100);
}	
//后面3个电机是1FF开始
void set_upthrow_current(CAN_HandleTypeDef* hcan, s16 iq1){

	hcan->pTxMsg->StdId = 0x1FF;
	hcan->pTxMsg->IDE = CAN_ID_STD;
	hcan->pTxMsg->RTR = CAN_RTR_DATA;
	hcan->pTxMsg->DLC = 0x08;
	hcan->pTxMsg->Data[0] = (iq1 >> 8);
	hcan->pTxMsg->Data[1] = iq1;
//	hcan->pTxMsg->Data[2] = (iq2 >> 8);
//	hcan->pTxMsg->Data[3] = iq2;
//	hcan->pTxMsg->Data[4] = iq3 >> 8;
//	hcan->pTxMsg->Data[5] = iq3;
//	hcan->pTxMsg->Data[6] = iq4 >> 8;
//	hcan->pTxMsg->Data[7] = iq4;
	HAL_CAN_Transmit(hcan, 100);
}	

void CAN_Send_Msg(CAN_HandleTypeDef* hcan, uint8_t *msg, uint32_t id, uint8_t len)
{
  uint8_t index = 0;
  
  hcan->pTxMsg->StdId = id;
  hcan->pTxMsg->IDE = CAN_ID_STD;
  hcan->pTxMsg->RTR = CAN_RTR_DATA;
  hcan->pTxMsg->DLC = len;
  
  for(index = 0; index <len; index++)
    hcan->pTxMsg->Data[index] = msg[index];
  
  HAL_CAN_Transmit_IT(hcan);

}
