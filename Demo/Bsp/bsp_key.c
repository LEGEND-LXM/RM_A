/****************************************************************************
 *  Copyright (C) 2018 RoboMaster.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of 
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/
 
#include "bsp_key.h"
#include "adc.h"

/**
  * @brief  detect key presse down event
  * @param  None
  * @retval event flag
  */
uint8_t KEY_Scan(void)
{
	uint32_t ADC_Value[20];
  uint8_t i,key_value;
  uint32_t button_value;
	
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&ADC_Value, 20);
	
	HAL_Delay(100);
	
	HAL_ADC_Stop_DMA(&hadc1);
        for(i = 0,button_value =0; i < 20;)
        {
            button_value += ADC_Value[i++];
            
        }
        button_value /= 2500;
				
	switch(button_value)
	{
		case 0 :
		case 1 :
		case 2 :	
			      key_value = OK_value;
		        break;
		case 7 :
		case 8 :
		case 9 :	
			      key_value = LEFT_value;
		        break;
		case 12 :
		case 13 :
		case 14 :	
			       key_value = RIGHT_value;
		        break;
		case 17 :
		case 18 :
		case 19 :	
			       key_value = UP_value;
		        break;
		case 21 :
		case 22 :
		case 23 :	
			       key_value = DOWN_value;
		        break;
		case 25 :
		case 26 :
    case 27 :			
			       key_value = INIT_value;
		        break;
  }		


	return key_value;
}



