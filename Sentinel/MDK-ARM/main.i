#line 1 "../Src/main.c"
#line 1 "../Inc/main.h"
 

















 
 

 







 
#line 1 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal.h"


















  

 







 
#line 1 "../Inc/stm32f4xx_hal_conf.h"
































  

 







 
 

 


 


 
 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 


 
 
 
 

 
 
 
 
 
 
 
 
 
 
#line 101 "../Inc/stm32f4xx_hal_conf.h"

 




 












 






 







 












 





 

 


 
#line 166 "../Inc/stm32f4xx_hal_conf.h"

 



 
 

 

 

 
#line 185 "../Inc/stm32f4xx_hal_conf.h"

    





 

  

  

 





 



 
#line 219 "../Inc/stm32f4xx_hal_conf.h"




  
 





 




 



 


 

#line 1 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"

















 

 







 
#line 1 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_def.h"


















 

 







 
#line 1 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f4xx.h"











































 



 



 
    






   


 
  


 






 
#line 111 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f4xx.h"
   


 
#line 123 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f4xx.h"



 
#line 135 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f4xx.h"



 



 

#line 1 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"







































 



 



 
    









 



 








 
  


 




 
typedef enum
{
 
  NonMaskableInt_IRQn         = -14,     
  MemoryManagement_IRQn       = -12,     
  BusFault_IRQn               = -11,     
  UsageFault_IRQn             = -10,     
  SVCall_IRQn                 = -5,      
  DebugMonitor_IRQn           = -4,      
  PendSV_IRQn                 = -2,      
  SysTick_IRQn                = -1,      
 
  WWDG_IRQn                   = 0,       
  PVD_IRQn                    = 1,       
  TAMP_STAMP_IRQn             = 2,       
  RTC_WKUP_IRQn               = 3,       
  FLASH_IRQn                  = 4,       
  RCC_IRQn                    = 5,       
  EXTI0_IRQn                  = 6,       
  EXTI1_IRQn                  = 7,       
  EXTI2_IRQn                  = 8,       
  EXTI3_IRQn                  = 9,       
  EXTI4_IRQn                  = 10,      
  DMA1_Stream0_IRQn           = 11,      
  DMA1_Stream1_IRQn           = 12,      
  DMA1_Stream2_IRQn           = 13,      
  DMA1_Stream3_IRQn           = 14,      
  DMA1_Stream4_IRQn           = 15,      
  DMA1_Stream5_IRQn           = 16,      
  DMA1_Stream6_IRQn           = 17,      
  ADC_IRQn                    = 18,      
  CAN1_TX_IRQn                = 19,      
  CAN1_RX0_IRQn               = 20,      
  CAN1_RX1_IRQn               = 21,      
  CAN1_SCE_IRQn               = 22,      
  EXTI9_5_IRQn                = 23,      
  TIM1_BRK_TIM9_IRQn          = 24,      
  TIM1_UP_TIM10_IRQn          = 25,      
  TIM1_TRG_COM_TIM11_IRQn     = 26,      
  TIM1_CC_IRQn                = 27,      
  TIM2_IRQn                   = 28,      
  TIM3_IRQn                   = 29,      
  TIM4_IRQn                   = 30,      
  I2C1_EV_IRQn                = 31,      
  I2C1_ER_IRQn                = 32,      
  I2C2_EV_IRQn                = 33,      
  I2C2_ER_IRQn                = 34,      
  SPI1_IRQn                   = 35,      
  SPI2_IRQn                   = 36,      
  USART1_IRQn                 = 37,      
  USART2_IRQn                 = 38,      
  USART3_IRQn                 = 39,      
  EXTI15_10_IRQn              = 40,      
  RTC_Alarm_IRQn              = 41,      
  OTG_FS_WKUP_IRQn            = 42,      
  TIM8_BRK_TIM12_IRQn         = 43,      
  TIM8_UP_TIM13_IRQn          = 44,      
  TIM8_TRG_COM_TIM14_IRQn     = 45,      
  TIM8_CC_IRQn                = 46,      
  DMA1_Stream7_IRQn           = 47,      
  FMC_IRQn                    = 48,      
  SDIO_IRQn                   = 49,      
  TIM5_IRQn                   = 50,      
  SPI3_IRQn                   = 51,      
  UART4_IRQn                  = 52,      
  UART5_IRQn                  = 53,      
  TIM6_DAC_IRQn               = 54,      
  TIM7_IRQn                   = 55,      
  DMA2_Stream0_IRQn           = 56,      
  DMA2_Stream1_IRQn           = 57,      
  DMA2_Stream2_IRQn           = 58,      
  DMA2_Stream3_IRQn           = 59,      
  DMA2_Stream4_IRQn           = 60,      
  ETH_IRQn                    = 61,      
  ETH_WKUP_IRQn               = 62,      
  CAN2_TX_IRQn                = 63,      
  CAN2_RX0_IRQn               = 64,      
  CAN2_RX1_IRQn               = 65,      
  CAN2_SCE_IRQn               = 66,      
  OTG_FS_IRQn                 = 67,      
  DMA2_Stream5_IRQn           = 68,      
  DMA2_Stream6_IRQn           = 69,      
  DMA2_Stream7_IRQn           = 70,      
  USART6_IRQn                 = 71,      
  I2C3_EV_IRQn                = 72,      
  I2C3_ER_IRQn                = 73,      
  OTG_HS_EP1_OUT_IRQn         = 74,      
  OTG_HS_EP1_IN_IRQn          = 75,      
  OTG_HS_WKUP_IRQn            = 76,      
  OTG_HS_IRQn                 = 77,      
  DCMI_IRQn                   = 78,      
  HASH_RNG_IRQn               = 80,      
  FPU_IRQn                    = 81,      
  UART7_IRQn                  = 82,      
  UART8_IRQn                  = 83,      
  SPI4_IRQn                   = 84,      
  SPI5_IRQn                   = 85,      
  SPI6_IRQn                   = 86,      
  SAI1_IRQn                   = 87,      
  DMA2D_IRQn                  = 90       
} IRQn_Type;



 

#line 1 "../Drivers/CMSIS/Include/core_cm4.h"
 




 
















 










#line 1 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
 
 





 









     
#line 27 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
     











#line 46 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"





 

     

     
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

     
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

     

     
     
typedef   signed          char int_least8_t;
typedef   signed short     int int_least16_t;
typedef   signed           int int_least32_t;
typedef   signed       __int64 int_least64_t;

     
typedef unsigned          char uint_least8_t;
typedef unsigned short     int uint_least16_t;
typedef unsigned           int uint_least32_t;
typedef unsigned       __int64 uint_least64_t;

     

     
typedef   signed           int int_fast8_t;
typedef   signed           int int_fast16_t;
typedef   signed           int int_fast32_t;
typedef   signed       __int64 int_fast64_t;

     
typedef unsigned           int uint_fast8_t;
typedef unsigned           int uint_fast16_t;
typedef unsigned           int uint_fast32_t;
typedef unsigned       __int64 uint_fast64_t;

     




typedef   signed           int intptr_t;
typedef unsigned           int uintptr_t;


     
typedef   signed     long long intmax_t;
typedef unsigned     long long uintmax_t;




     

     





     





     





     

     





     





     





     

     





     





     





     

     






     






     






     

     


     


     


     

     
#line 216 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

     



     






     
    
 



#line 241 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

     







     










     











#line 305 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"






 
#line 35 "../Drivers/CMSIS/Include/core_cm4.h"

















 




 



 

#line 1 "../Drivers/CMSIS/Include/cmsis_version.h"
 




 
















 










 
#line 64 "../Drivers/CMSIS/Include/core_cm4.h"

 









 
#line 87 "../Drivers/CMSIS/Include/core_cm4.h"

#line 161 "../Drivers/CMSIS/Include/core_cm4.h"

#line 1 "../Drivers/CMSIS/Include/cmsis_compiler.h"
 




 
















 




#line 29 "../Drivers/CMSIS/Include/cmsis_compiler.h"



 
#line 1 "../Drivers/CMSIS/Include/cmsis_armcc.h"
 




 
















 









 













   
   


 
#line 103 "../Drivers/CMSIS/Include/cmsis_armcc.h"

 



 





 
 






 
 





 
static __inline uint32_t __get_CONTROL(void)
{
  register uint32_t __regControl         __asm("control");
  return(__regControl);
}






 
static __inline void __set_CONTROL(uint32_t control)
{
  register uint32_t __regControl         __asm("control");
  __regControl = control;
}






 
static __inline uint32_t __get_IPSR(void)
{
  register uint32_t __regIPSR          __asm("ipsr");
  return(__regIPSR);
}






 
static __inline uint32_t __get_APSR(void)
{
  register uint32_t __regAPSR          __asm("apsr");
  return(__regAPSR);
}






 
static __inline uint32_t __get_xPSR(void)
{
  register uint32_t __regXPSR          __asm("xpsr");
  return(__regXPSR);
}






 
static __inline uint32_t __get_PSP(void)
{
  register uint32_t __regProcessStackPointer  __asm("psp");
  return(__regProcessStackPointer);
}






 
static __inline void __set_PSP(uint32_t topOfProcStack)
{
  register uint32_t __regProcessStackPointer  __asm("psp");
  __regProcessStackPointer = topOfProcStack;
}






 
static __inline uint32_t __get_MSP(void)
{
  register uint32_t __regMainStackPointer     __asm("msp");
  return(__regMainStackPointer);
}






 
static __inline void __set_MSP(uint32_t topOfMainStack)
{
  register uint32_t __regMainStackPointer     __asm("msp");
  __regMainStackPointer = topOfMainStack;
}






 
static __inline uint32_t __get_PRIMASK(void)
{
  register uint32_t __regPriMask         __asm("primask");
  return(__regPriMask);
}






 
static __inline void __set_PRIMASK(uint32_t priMask)
{
  register uint32_t __regPriMask         __asm("primask");
  __regPriMask = (priMask);
}









 







 







 
static __inline uint32_t  __get_BASEPRI(void)
{
  register uint32_t __regBasePri         __asm("basepri");
  return(__regBasePri);
}






 
static __inline void __set_BASEPRI(uint32_t basePri)
{
  register uint32_t __regBasePri         __asm("basepri");
  __regBasePri = (basePri & 0xFFU);
}







 
static __inline void __set_BASEPRI_MAX(uint32_t basePri)
{
  register uint32_t __regBasePriMax      __asm("basepri_max");
  __regBasePriMax = (basePri & 0xFFU);
}






 
static __inline uint32_t __get_FAULTMASK(void)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  return(__regFaultMask);
}






 
static __inline void __set_FAULTMASK(uint32_t faultMask)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  __regFaultMask = (faultMask & (uint32_t)1U);
}









 
static __inline uint32_t __get_FPSCR(void)
{


  register uint32_t __regfpscr         __asm("fpscr");
  return(__regfpscr);



}






 
static __inline void __set_FPSCR(uint32_t fpscr)
{


  register uint32_t __regfpscr         __asm("fpscr");
  __regfpscr = (fpscr);



}


 


 



 




 






 







 






 








 










 










 






                  





 








 

__attribute__((section(".rev16_text"))) static __inline __asm uint32_t __REV16(uint32_t value)
{
  rev16 r0, r0
  bx lr
}








 

__attribute__((section(".revsh_text"))) static __inline __asm int16_t __REVSH(int16_t value)
{
  revsh r0, r0
  bx lr
}









 









 








 
#line 532 "../Drivers/CMSIS/Include/cmsis_armcc.h"







 











 












 












 














 














 














 










 









 









 









 

__attribute__((section(".rrx_text"))) static __inline __asm uint32_t __RRX(uint32_t value)
{
  rrx r0, r0
  bx lr
}








 








 








 








 








 








 


#line 780 "../Drivers/CMSIS/Include/cmsis_armcc.h"

   


 



 



#line 851 "../Drivers/CMSIS/Include/cmsis_armcc.h"











 


#line 35 "../Drivers/CMSIS/Include/cmsis_compiler.h"




 
#line 263 "../Drivers/CMSIS/Include/cmsis_compiler.h"




#line 163 "../Drivers/CMSIS/Include/core_cm4.h"

















 
#line 207 "../Drivers/CMSIS/Include/core_cm4.h"

 






 
#line 223 "../Drivers/CMSIS/Include/core_cm4.h"

 




 













 



 






 



 
typedef union
{
  struct
  {
    uint32_t _reserved0:16;               
    uint32_t GE:4;                        
    uint32_t _reserved1:7;                
    uint32_t Q:1;                         
    uint32_t V:1;                         
    uint32_t C:1;                         
    uint32_t Z:1;                         
    uint32_t N:1;                         
  } b;                                    
  uint32_t w;                             
} APSR_Type;

 





















 
typedef union
{
  struct
  {
    uint32_t ISR:9;                       
    uint32_t _reserved0:23;               
  } b;                                    
  uint32_t w;                             
} IPSR_Type;

 






 
typedef union
{
  struct
  {
    uint32_t ISR:9;                       
    uint32_t _reserved0:1;                
    uint32_t ICI_IT_1:6;                  
    uint32_t GE:4;                        
    uint32_t _reserved1:4;                
    uint32_t T:1;                         
    uint32_t ICI_IT_2:2;                  
    uint32_t Q:1;                         
    uint32_t V:1;                         
    uint32_t C:1;                         
    uint32_t Z:1;                         
    uint32_t N:1;                         
  } b;                                    
  uint32_t w;                             
} xPSR_Type;

 

































 
typedef union
{
  struct
  {
    uint32_t nPRIV:1;                     
    uint32_t SPSEL:1;                     
    uint32_t FPCA:1;                      
    uint32_t _reserved0:29;               
  } b;                                    
  uint32_t w;                             
} CONTROL_Type;

 









 







 



 
typedef struct
{
  volatile uint32_t ISER[8U];                
        uint32_t RESERVED0[24U];
  volatile uint32_t ICER[8U];                
        uint32_t RSERVED1[24U];
  volatile uint32_t ISPR[8U];                
        uint32_t RESERVED2[24U];
  volatile uint32_t ICPR[8U];                
        uint32_t RESERVED3[24U];
  volatile uint32_t IABR[8U];                
        uint32_t RESERVED4[56U];
  volatile uint8_t  IP[240U];                
        uint32_t RESERVED5[644U];
  volatile  uint32_t STIR;                    
}  NVIC_Type;

 



 







 



 
typedef struct
{
  volatile const  uint32_t CPUID;                   
  volatile uint32_t ICSR;                    
  volatile uint32_t VTOR;                    
  volatile uint32_t AIRCR;                   
  volatile uint32_t SCR;                     
  volatile uint32_t CCR;                     
  volatile uint8_t  SHP[12U];                
  volatile uint32_t SHCSR;                   
  volatile uint32_t CFSR;                    
  volatile uint32_t HFSR;                    
  volatile uint32_t DFSR;                    
  volatile uint32_t MMFAR;                   
  volatile uint32_t BFAR;                    
  volatile uint32_t AFSR;                    
  volatile const  uint32_t PFR[2U];                 
  volatile const  uint32_t DFR;                     
  volatile const  uint32_t ADR;                     
  volatile const  uint32_t MMFR[4U];                
  volatile const  uint32_t ISAR[5U];                
        uint32_t RESERVED0[5U];
  volatile uint32_t CPACR;                   
} SCB_Type;

 















 






























 



 





















 









 


















 










































 









 


















 





















 


















 









 















 







 



 
typedef struct
{
        uint32_t RESERVED0[1U];
  volatile const  uint32_t ICTR;                    
  volatile uint32_t ACTLR;                   
} SCnSCB_Type;

 



 















 







 



 
typedef struct
{
  volatile uint32_t CTRL;                    
  volatile uint32_t LOAD;                    
  volatile uint32_t VAL;                     
  volatile const  uint32_t CALIB;                   
} SysTick_Type;

 












 



 



 









 







 



 
typedef struct
{
  volatile  union
  {
    volatile  uint8_t    u8;                  
    volatile  uint16_t   u16;                 
    volatile  uint32_t   u32;                 
  }  PORT [32U];                          
        uint32_t RESERVED0[864U];
  volatile uint32_t TER;                     
        uint32_t RESERVED1[15U];
  volatile uint32_t TPR;                     
        uint32_t RESERVED2[15U];
  volatile uint32_t TCR;                     
        uint32_t RESERVED3[29U];
  volatile  uint32_t IWR;                     
  volatile const  uint32_t IRR;                     
  volatile uint32_t IMCR;                    
        uint32_t RESERVED4[43U];
  volatile  uint32_t LAR;                     
  volatile const  uint32_t LSR;                     
        uint32_t RESERVED5[6U];
  volatile const  uint32_t PID4;                    
  volatile const  uint32_t PID5;                    
  volatile const  uint32_t PID6;                    
  volatile const  uint32_t PID7;                    
  volatile const  uint32_t PID0;                    
  volatile const  uint32_t PID1;                    
  volatile const  uint32_t PID2;                    
  volatile const  uint32_t PID3;                    
  volatile const  uint32_t CID0;                    
  volatile const  uint32_t CID1;                    
  volatile const  uint32_t CID2;                    
  volatile const  uint32_t CID3;                    
} ITM_Type;

 



 



























 



 



 



 









   







 



 
typedef struct
{
  volatile uint32_t CTRL;                    
  volatile uint32_t CYCCNT;                  
  volatile uint32_t CPICNT;                  
  volatile uint32_t EXCCNT;                  
  volatile uint32_t SLEEPCNT;                
  volatile uint32_t LSUCNT;                  
  volatile uint32_t FOLDCNT;                 
  volatile const  uint32_t PCSR;                    
  volatile uint32_t COMP0;                   
  volatile uint32_t MASK0;                   
  volatile uint32_t FUNCTION0;               
        uint32_t RESERVED0[1U];
  volatile uint32_t COMP1;                   
  volatile uint32_t MASK1;                   
  volatile uint32_t FUNCTION1;               
        uint32_t RESERVED1[1U];
  volatile uint32_t COMP2;                   
  volatile uint32_t MASK2;                   
  volatile uint32_t FUNCTION2;               
        uint32_t RESERVED2[1U];
  volatile uint32_t COMP3;                   
  volatile uint32_t MASK3;                   
  volatile uint32_t FUNCTION3;               
} DWT_Type;

 






















































 



 



 



 



 



 



 



























   







 



 
typedef struct
{
  volatile const  uint32_t SSPSR;                   
  volatile uint32_t CSPSR;                   
        uint32_t RESERVED0[2U];
  volatile uint32_t ACPR;                    
        uint32_t RESERVED1[55U];
  volatile uint32_t SPPR;                    
        uint32_t RESERVED2[131U];
  volatile const  uint32_t FFSR;                    
  volatile uint32_t FFCR;                    
  volatile const  uint32_t FSCR;                    
        uint32_t RESERVED3[759U];
  volatile const  uint32_t TRIGGER;                 
  volatile const  uint32_t FIFO0;                   
  volatile const  uint32_t ITATBCTR2;               
        uint32_t RESERVED4[1U];
  volatile const  uint32_t ITATBCTR0;               
  volatile const  uint32_t FIFO1;                   
  volatile uint32_t ITCTRL;                  
        uint32_t RESERVED5[39U];
  volatile uint32_t CLAIMSET;                
  volatile uint32_t CLAIMCLR;                
        uint32_t RESERVED7[8U];
  volatile const  uint32_t DEVID;                   
  volatile const  uint32_t DEVTYPE;                 
} TPI_Type;

 



 



 












 






 



 





















 






 





















 






 



 


















 






   








 



 
typedef struct
{
  volatile const  uint32_t TYPE;                    
  volatile uint32_t CTRL;                    
  volatile uint32_t RNR;                     
  volatile uint32_t RBAR;                    
  volatile uint32_t RASR;                    
  volatile uint32_t RBAR_A1;                 
  volatile uint32_t RASR_A1;                 
  volatile uint32_t RBAR_A2;                 
  volatile uint32_t RASR_A2;                 
  volatile uint32_t RBAR_A3;                 
  volatile uint32_t RASR_A3;                 
} MPU_Type;



 









 









 



 









 






























 








 



 
typedef struct
{
        uint32_t RESERVED0[1U];
  volatile uint32_t FPCCR;                   
  volatile uint32_t FPCAR;                   
  volatile uint32_t FPDSCR;                  
  volatile const  uint32_t MVFR0;                   
  volatile const  uint32_t MVFR1;                   
} FPU_Type;

 



























 



 












 
























 












 







 



 
typedef struct
{
  volatile uint32_t DHCSR;                   
  volatile  uint32_t DCRSR;                   
  volatile uint32_t DCRDR;                   
  volatile uint32_t DEMCR;                   
} CoreDebug_Type;

 




































 






 







































 







 






 







 


 







 

 
#line 1562 "../Drivers/CMSIS/Include/core_cm4.h"

#line 1571 "../Drivers/CMSIS/Include/core_cm4.h"









 










 


 



 





 

#line 1625 "../Drivers/CMSIS/Include/core_cm4.h"

#line 1635 "../Drivers/CMSIS/Include/core_cm4.h"




 
#line 1646 "../Drivers/CMSIS/Include/core_cm4.h"










 
static __inline void __NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
  uint32_t reg_value;
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);              

  reg_value  =  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR;                                                    
  reg_value &= ~((uint32_t)((0xFFFFUL << 16U) | (7UL << 8U)));  
  reg_value  =  (reg_value                                   |
                ((uint32_t)0x5FAUL << 16U) |
                (PriorityGroupTmp << 8U)  );               
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR =  reg_value;
}






 
static __inline uint32_t __NVIC_GetPriorityGrouping(void)
{
  return ((uint32_t)((((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8U)) >> 8U));
}







 
static __inline void __NVIC_EnableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
  }
}









 
static __inline uint32_t __NVIC_GetEnableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[(((uint32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}







 
static __inline void __NVIC_DisableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICER[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);
  }
}









 
static __inline uint32_t __NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(((uint32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}







 
static __inline void __NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
  }
}







 
static __inline void __NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICPR[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
  }
}









 
static __inline uint32_t __NVIC_GetActive(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IABR[(((uint32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}










 
static __inline void __NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[((uint32_t)IRQn)]               = (uint8_t)((priority << (8U - 4U)) & (uint32_t)0xFFUL);
  }
  else
  {
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[(((uint32_t)IRQn) & 0xFUL)-4UL] = (uint8_t)((priority << (8U - 4U)) & (uint32_t)0xFFUL);
  }
}










 
static __inline uint32_t __NVIC_GetPriority(IRQn_Type IRQn)
{

  if ((int32_t)(IRQn) >= 0)
  {
    return(((uint32_t)((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[((uint32_t)IRQn)]               >> (8U - 4U)));
  }
  else
  {
    return(((uint32_t)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[(((uint32_t)IRQn) & 0xFUL)-4UL] >> (8U - 4U)));
  }
}












 
static __inline uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);    
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(4U)) ? (uint32_t)(4U) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(4U)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(4U));

  return (
           ((PreemptPriority & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL)) << SubPriorityBits) |
           ((SubPriority     & (uint32_t)((1UL << (SubPriorityBits    )) - 1UL)))
         );
}












 
static __inline void NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* const pPreemptPriority, uint32_t* const pSubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);    
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(4U)) ? (uint32_t)(4U) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(4U)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(4U));

  *pPreemptPriority = (Priority >> SubPriorityBits) & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL);
  *pSubPriority     = (Priority                   ) & (uint32_t)((1UL << (SubPriorityBits    )) - 1UL);
}










 
static __inline void __NVIC_SetVector(IRQn_Type IRQn, uint32_t vector)
{
  uint32_t *vectors = (uint32_t *)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->VTOR;
  vectors[(int32_t)IRQn + 16] = vector;
}









 
static __inline uint32_t __NVIC_GetVector(IRQn_Type IRQn)
{
  uint32_t *vectors = (uint32_t *)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->VTOR;
  return vectors[(int32_t)IRQn + 16];
}





 
__declspec(noreturn) static __inline void __NVIC_SystemReset(void)
{
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);                                                          
 
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR  = (uint32_t)((0x5FAUL << 16U)    |
                           (((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8U)) |
                            (1UL << 2U)    );          
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);                                                           

  for(;;)                                                            
  {
    __nop();
  }
}

 

 



#line 1 "../Drivers/CMSIS/Include/mpu_armv7.h"





 
















 
 





 



#line 62 "../Drivers/CMSIS/Include/mpu_armv7.h"

#line 69 "../Drivers/CMSIS/Include/mpu_armv7.h"





 












   














 




  











                          









  










  












  




 




 




 




 





 
typedef struct {
  uint32_t RBAR; 
  uint32_t RASR; 
} ARM_MPU_Region_t;
    


 
static __inline void ARM_MPU_Enable(uint32_t MPU_Control)
{
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);
  do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->CTRL = MPU_Control | (1UL );

  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHCSR |= (1UL << 16U);

}


 
static __inline void ARM_MPU_Disable(void)
{
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);
  do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);

  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHCSR &= ~(1UL << 16U);

  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->CTRL  &= ~(1UL );
}



 
static __inline void ARM_MPU_ClrRegion(uint32_t rnr)
{
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RNR = rnr;
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RASR = 0U;
}




    
static __inline void ARM_MPU_SetRegion(uint32_t rbar, uint32_t rasr)
{
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RBAR = rbar;
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RASR = rasr;
}





    
static __inline void ARM_MPU_SetRegionEx(uint32_t rnr, uint32_t rbar, uint32_t rasr)
{
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RNR = rnr;
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RBAR = rbar;
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RASR = rasr;
}





 
static __inline void orderedCpy(volatile uint32_t* dst, const uint32_t* __restrict src, uint32_t len)
{
  uint32_t i;
  for (i = 0U; i < len; ++i) 
  {
    dst[i] = src[i];
  }
}




 
static __inline void ARM_MPU_Load(ARM_MPU_Region_t const* table, uint32_t cnt) 
{
  const uint32_t rowWordSize = sizeof(ARM_MPU_Region_t)/4U;
  while (cnt > 4U) {
    orderedCpy(&(((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RBAR), &(table->RBAR), 4U*rowWordSize);
    table += 4U;
    cnt -= 4U;
  }
  orderedCpy(&(((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RBAR), &(table->RBAR), cnt*rowWordSize);
}

#line 1961 "../Drivers/CMSIS/Include/core_cm4.h"




 





 








 
static __inline uint32_t SCB_GetFPUType(void)
{
  uint32_t mvfr0;

  mvfr0 = ((FPU_Type *) ((0xE000E000UL) + 0x0F30UL) )->MVFR0;
  if      ((mvfr0 & ((0xFUL << 4U) | (0xFUL << 8U))) == 0x020U)
  {
    return 1U;            
  }
  else
  {
    return 0U;            
  }
}


 



 





 













 
static __inline uint32_t SysTick_Config(uint32_t ticks)
{
  if ((ticks - 1UL) > (0xFFFFFFUL ))
  {
    return (1UL);                                                    
  }

  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD  = (uint32_t)(ticks - 1UL);                          
  __NVIC_SetPriority (SysTick_IRQn, (1UL << 4U) - 1UL);  
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL   = 0UL;                                              
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL  = (1UL << 2U) |
                   (1UL << 1U)   |
                   (1UL );                          
  return (0UL);                                                      
}



 



 





 

extern volatile int32_t ITM_RxBuffer;                               










 
static __inline uint32_t ITM_SendChar (uint32_t ch)
{
  if (((((ITM_Type *) (0xE0000000UL) )->TCR & (1UL )) != 0UL) &&       
      ((((ITM_Type *) (0xE0000000UL) )->TER & 1UL               ) != 0UL)   )      
  {
    while (((ITM_Type *) (0xE0000000UL) )->PORT[0U].u32 == 0UL)
    {
      __nop();
    }
    ((ITM_Type *) (0xE0000000UL) )->PORT[0U].u8 = (uint8_t)ch;
  }
  return (ch);
}







 
static __inline int32_t ITM_ReceiveChar (void)
{
  int32_t ch = -1;                            

  if (ITM_RxBuffer != ((int32_t)0x5AA55AA5U))
  {
    ch = ITM_RxBuffer;
    ITM_RxBuffer = ((int32_t)0x5AA55AA5U);        
  }

  return (ch);
}







 
static __inline int32_t ITM_CheckChar (void)
{

  if (ITM_RxBuffer == ((int32_t)0x5AA55AA5U))
  {
    return (0);                               
  }
  else
  {
    return (1);                               
  }
}

 










#line 189 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
#line 1 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/system_stm32f4xx.h"

































  



 



   
  


 









 



 




 
  






 
extern uint32_t SystemCoreClock;           

extern const uint8_t  AHBPrescTable[16];     
extern const uint8_t  APBPrescTable[8];      



 



 



 



 



 



 
  
extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);


 









 
  


   
 
#line 190 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
#line 191 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"



    



 

typedef struct
{
  volatile uint32_t SR;      
  volatile uint32_t CR1;     
  volatile uint32_t CR2;     
  volatile uint32_t SMPR1;   
  volatile uint32_t SMPR2;   
  volatile uint32_t JOFR1;   
  volatile uint32_t JOFR2;   
  volatile uint32_t JOFR3;   
  volatile uint32_t JOFR4;   
  volatile uint32_t HTR;     
  volatile uint32_t LTR;     
  volatile uint32_t SQR1;    
  volatile uint32_t SQR2;    
  volatile uint32_t SQR3;    
  volatile uint32_t JSQR;    
  volatile uint32_t JDR1;    
  volatile uint32_t JDR2;    
  volatile uint32_t JDR3;    
  volatile uint32_t JDR4;    
  volatile uint32_t DR;      
} ADC_TypeDef;

typedef struct
{
  volatile uint32_t CSR;     
  volatile uint32_t CCR;     
  volatile uint32_t CDR;    
 
} ADC_Common_TypeDef;




 

typedef struct
{
  volatile uint32_t TIR;   
  volatile uint32_t TDTR;  
  volatile uint32_t TDLR;  
  volatile uint32_t TDHR;  
} CAN_TxMailBox_TypeDef;



 
  
typedef struct
{
  volatile uint32_t RIR;   
  volatile uint32_t RDTR;  
  volatile uint32_t RDLR;  
  volatile uint32_t RDHR;  
} CAN_FIFOMailBox_TypeDef;



 
  
typedef struct
{
  volatile uint32_t FR1;  
  volatile uint32_t FR2;  
} CAN_FilterRegister_TypeDef;



 
  
typedef struct
{
  volatile uint32_t              MCR;                  
  volatile uint32_t              MSR;                  
  volatile uint32_t              TSR;                  
  volatile uint32_t              RF0R;                 
  volatile uint32_t              RF1R;                 
  volatile uint32_t              IER;                  
  volatile uint32_t              ESR;                  
  volatile uint32_t              BTR;                  
  uint32_t                   RESERVED0[88];        
  CAN_TxMailBox_TypeDef      sTxMailBox[3];        
  CAN_FIFOMailBox_TypeDef    sFIFOMailBox[2];      
  uint32_t                   RESERVED1[12];        
  volatile uint32_t              FMR;                  
  volatile uint32_t              FM1R;                 
  uint32_t                   RESERVED2;            
  volatile uint32_t              FS1R;                 
  uint32_t                   RESERVED3;            
  volatile uint32_t              FFA1R;                
  uint32_t                   RESERVED4;            
  volatile uint32_t              FA1R;                 
  uint32_t                   RESERVED5[8];          
  CAN_FilterRegister_TypeDef sFilterRegister[28];  
} CAN_TypeDef;



 

typedef struct
{
  volatile uint32_t DR;          
  volatile uint8_t  IDR;         
  uint8_t       RESERVED0;   
  uint16_t      RESERVED1;   
  volatile uint32_t CR;          
} CRC_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;        
  volatile uint32_t SWTRIGR;   
  volatile uint32_t DHR12R1;   
  volatile uint32_t DHR12L1;   
  volatile uint32_t DHR8R1;    
  volatile uint32_t DHR12R2;   
  volatile uint32_t DHR12L2;   
  volatile uint32_t DHR8R2;    
  volatile uint32_t DHR12RD;   
  volatile uint32_t DHR12LD;   
  volatile uint32_t DHR8RD;    
  volatile uint32_t DOR1;      
  volatile uint32_t DOR2;      
  volatile uint32_t SR;        
} DAC_TypeDef;



 

typedef struct
{
  volatile uint32_t IDCODE;   
  volatile uint32_t CR;       
  volatile uint32_t APB1FZ;   
  volatile uint32_t APB2FZ;   
}DBGMCU_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;        
  volatile uint32_t SR;        
  volatile uint32_t RISR;      
  volatile uint32_t IER;       
  volatile uint32_t MISR;      
  volatile uint32_t ICR;       
  volatile uint32_t ESCR;      
  volatile uint32_t ESUR;      
  volatile uint32_t CWSTRTR;   
  volatile uint32_t CWSIZER;   
  volatile uint32_t DR;        
} DCMI_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;      
  volatile uint32_t NDTR;    
  volatile uint32_t PAR;     
  volatile uint32_t M0AR;    
  volatile uint32_t M1AR;    
  volatile uint32_t FCR;     
} DMA_Stream_TypeDef;

typedef struct
{
  volatile uint32_t LISR;    
  volatile uint32_t HISR;    
  volatile uint32_t LIFCR;   
  volatile uint32_t HIFCR;   
} DMA_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;             
  volatile uint32_t ISR;            
  volatile uint32_t IFCR;           
  volatile uint32_t FGMAR;          
  volatile uint32_t FGOR;           
  volatile uint32_t BGMAR;          
  volatile uint32_t BGOR;           
  volatile uint32_t FGPFCCR;        
  volatile uint32_t FGCOLR;         
  volatile uint32_t BGPFCCR;        
  volatile uint32_t BGCOLR;         
  volatile uint32_t FGCMAR;         
  volatile uint32_t BGCMAR;         
  volatile uint32_t OPFCCR;         
  volatile uint32_t OCOLR;          
  volatile uint32_t OMAR;           
  volatile uint32_t OOR;            
  volatile uint32_t NLR;            
  volatile uint32_t LWR;            
  volatile uint32_t AMTCR;          
  uint32_t      RESERVED[236];  
  volatile uint32_t FGCLUT[256];    
  volatile uint32_t BGCLUT[256];    
} DMA2D_TypeDef;



 

typedef struct
{
  volatile uint32_t MACCR;
  volatile uint32_t MACFFR;
  volatile uint32_t MACHTHR;
  volatile uint32_t MACHTLR;
  volatile uint32_t MACMIIAR;
  volatile uint32_t MACMIIDR;
  volatile uint32_t MACFCR;
  volatile uint32_t MACVLANTR;              
  uint32_t      RESERVED0[2];
  volatile uint32_t MACRWUFFR;              
  volatile uint32_t MACPMTCSR;
  uint32_t      RESERVED1;
  volatile uint32_t MACDBGR;
  volatile uint32_t MACSR;                  
  volatile uint32_t MACIMR;
  volatile uint32_t MACA0HR;
  volatile uint32_t MACA0LR;
  volatile uint32_t MACA1HR;
  volatile uint32_t MACA1LR;
  volatile uint32_t MACA2HR;
  volatile uint32_t MACA2LR;
  volatile uint32_t MACA3HR;
  volatile uint32_t MACA3LR;                
  uint32_t      RESERVED2[40];
  volatile uint32_t MMCCR;                  
  volatile uint32_t MMCRIR;
  volatile uint32_t MMCTIR;
  volatile uint32_t MMCRIMR;
  volatile uint32_t MMCTIMR;                
  uint32_t      RESERVED3[14];
  volatile uint32_t MMCTGFSCCR;             
  volatile uint32_t MMCTGFMSCCR;
  uint32_t      RESERVED4[5];
  volatile uint32_t MMCTGFCR;
  uint32_t      RESERVED5[10];
  volatile uint32_t MMCRFCECR;
  volatile uint32_t MMCRFAECR;
  uint32_t      RESERVED6[10];
  volatile uint32_t MMCRGUFCR;
  uint32_t      RESERVED7[334];
  volatile uint32_t PTPTSCR;
  volatile uint32_t PTPSSIR;
  volatile uint32_t PTPTSHR;
  volatile uint32_t PTPTSLR;
  volatile uint32_t PTPTSHUR;
  volatile uint32_t PTPTSLUR;
  volatile uint32_t PTPTSAR;
  volatile uint32_t PTPTTHR;
  volatile uint32_t PTPTTLR;
  volatile uint32_t RESERVED8;
  volatile uint32_t PTPTSSR;
  uint32_t      RESERVED9[565];
  volatile uint32_t DMABMR;
  volatile uint32_t DMATPDR;
  volatile uint32_t DMARPDR;
  volatile uint32_t DMARDLAR;
  volatile uint32_t DMATDLAR;
  volatile uint32_t DMASR;
  volatile uint32_t DMAOMR;
  volatile uint32_t DMAIER;
  volatile uint32_t DMAMFBOCR;
  volatile uint32_t DMARSWTR;
  uint32_t      RESERVED10[8];
  volatile uint32_t DMACHTDR;
  volatile uint32_t DMACHRDR;
  volatile uint32_t DMACHTBAR;
  volatile uint32_t DMACHRBAR;
} ETH_TypeDef;



 

typedef struct
{
  volatile uint32_t IMR;     
  volatile uint32_t EMR;     
  volatile uint32_t RTSR;    
  volatile uint32_t FTSR;    
  volatile uint32_t SWIER;   
  volatile uint32_t PR;      
} EXTI_TypeDef;



 

typedef struct
{
  volatile uint32_t ACR;       
  volatile uint32_t KEYR;      
  volatile uint32_t OPTKEYR;   
  volatile uint32_t SR;        
  volatile uint32_t CR;        
  volatile uint32_t OPTCR;     
  volatile uint32_t OPTCR1;    
} FLASH_TypeDef;



 

typedef struct
{
  volatile uint32_t BTCR[8];     
} FMC_Bank1_TypeDef; 



 
  
typedef struct
{
  volatile uint32_t BWTR[7];     
} FMC_Bank1E_TypeDef;


 
  
typedef struct
{
  volatile uint32_t PCR2;        
  volatile uint32_t SR2;         
  volatile uint32_t PMEM2;       
  volatile uint32_t PATT2;       
  uint32_t      RESERVED0;   
  volatile uint32_t ECCR2;       
  uint32_t      RESERVED1;   
  uint32_t      RESERVED2;   
  volatile uint32_t PCR3;        
  volatile uint32_t SR3;         
  volatile uint32_t PMEM3;       
  volatile uint32_t PATT3;       
  uint32_t      RESERVED3;   
  volatile uint32_t ECCR3;       
} FMC_Bank2_3_TypeDef;



 
  
typedef struct
{
  volatile uint32_t PCR4;        
  volatile uint32_t SR4;         
  volatile uint32_t PMEM4;       
  volatile uint32_t PATT4;       
  volatile uint32_t PIO4;        
} FMC_Bank4_TypeDef;



 
  
typedef struct
{
  volatile uint32_t SDCR[2];         
  volatile uint32_t SDTR[2];         
  volatile uint32_t SDCMR;           
  volatile uint32_t SDRTR;           
  volatile uint32_t SDSR;            
} FMC_Bank5_6_TypeDef;



 

typedef struct
{
  volatile uint32_t MODER;     
  volatile uint32_t OTYPER;    
  volatile uint32_t OSPEEDR;   
  volatile uint32_t PUPDR;     
  volatile uint32_t IDR;       
  volatile uint32_t ODR;       
  volatile uint32_t BSRR;      
  volatile uint32_t LCKR;      
  volatile uint32_t AFR[2];    
} GPIO_TypeDef;



 

typedef struct
{
  volatile uint32_t MEMRMP;        
  volatile uint32_t PMC;           
  volatile uint32_t EXTICR[4];     
  uint32_t      RESERVED[2];   
  volatile uint32_t CMPCR;         
} SYSCFG_TypeDef;



 

typedef struct
{
  volatile uint32_t CR1;         
  volatile uint32_t CR2;         
  volatile uint32_t OAR1;        
  volatile uint32_t OAR2;        
  volatile uint32_t DR;          
  volatile uint32_t SR1;         
  volatile uint32_t SR2;         
  volatile uint32_t CCR;         
  volatile uint32_t TRISE;       
  volatile uint32_t FLTR;        
} I2C_TypeDef;



 

typedef struct
{
  volatile uint32_t KR;    
  volatile uint32_t PR;    
  volatile uint32_t RLR;   
  volatile uint32_t SR;    
} IWDG_TypeDef;




 

typedef struct
{
  volatile uint32_t CR;    
  volatile uint32_t CSR;   
} PWR_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;             
  volatile uint32_t PLLCFGR;        
  volatile uint32_t CFGR;           
  volatile uint32_t CIR;            
  volatile uint32_t AHB1RSTR;       
  volatile uint32_t AHB2RSTR;       
  volatile uint32_t AHB3RSTR;       
  uint32_t      RESERVED0;      
  volatile uint32_t APB1RSTR;       
  volatile uint32_t APB2RSTR;       
  uint32_t      RESERVED1[2];   
  volatile uint32_t AHB1ENR;        
  volatile uint32_t AHB2ENR;        
  volatile uint32_t AHB3ENR;        
  uint32_t      RESERVED2;      
  volatile uint32_t APB1ENR;        
  volatile uint32_t APB2ENR;        
  uint32_t      RESERVED3[2];   
  volatile uint32_t AHB1LPENR;      
  volatile uint32_t AHB2LPENR;      
  volatile uint32_t AHB3LPENR;      
  uint32_t      RESERVED4;      
  volatile uint32_t APB1LPENR;      
  volatile uint32_t APB2LPENR;      
  uint32_t      RESERVED5[2];   
  volatile uint32_t BDCR;           
  volatile uint32_t CSR;            
  uint32_t      RESERVED6[2];   
  volatile uint32_t SSCGR;          
  volatile uint32_t PLLI2SCFGR;     
  volatile uint32_t PLLSAICFGR;     
  volatile uint32_t DCKCFGR;        
} RCC_TypeDef;



 

typedef struct
{
  volatile uint32_t TR;       
  volatile uint32_t DR;       
  volatile uint32_t CR;       
  volatile uint32_t ISR;      
  volatile uint32_t PRER;     
  volatile uint32_t WUTR;     
  volatile uint32_t CALIBR;   
  volatile uint32_t ALRMAR;   
  volatile uint32_t ALRMBR;   
  volatile uint32_t WPR;      
  volatile uint32_t SSR;      
  volatile uint32_t SHIFTR;   
  volatile uint32_t TSTR;     
  volatile uint32_t TSDR;     
  volatile uint32_t TSSSR;    
  volatile uint32_t CALR;     
  volatile uint32_t TAFCR;    
  volatile uint32_t ALRMASSR; 
  volatile uint32_t ALRMBSSR; 
  uint32_t RESERVED7;     
  volatile uint32_t BKP0R;    
  volatile uint32_t BKP1R;    
  volatile uint32_t BKP2R;    
  volatile uint32_t BKP3R;    
  volatile uint32_t BKP4R;    
  volatile uint32_t BKP5R;    
  volatile uint32_t BKP6R;    
  volatile uint32_t BKP7R;    
  volatile uint32_t BKP8R;    
  volatile uint32_t BKP9R;    
  volatile uint32_t BKP10R;   
  volatile uint32_t BKP11R;   
  volatile uint32_t BKP12R;   
  volatile uint32_t BKP13R;   
  volatile uint32_t BKP14R;   
  volatile uint32_t BKP15R;   
  volatile uint32_t BKP16R;   
  volatile uint32_t BKP17R;   
  volatile uint32_t BKP18R;   
  volatile uint32_t BKP19R;   
} RTC_TypeDef;



 
  
typedef struct
{
  volatile uint32_t GCR;       
} SAI_TypeDef;

typedef struct
{
  volatile uint32_t CR1;       
  volatile uint32_t CR2;       
  volatile uint32_t FRCR;      
  volatile uint32_t SLOTR;     
  volatile uint32_t IMR;       
  volatile uint32_t SR;        
  volatile uint32_t CLRFR;     
  volatile uint32_t DR;        
} SAI_Block_TypeDef;



 

typedef struct
{
  volatile uint32_t POWER;                  
  volatile uint32_t CLKCR;                  
  volatile uint32_t ARG;                    
  volatile uint32_t CMD;                    
  volatile const uint32_t  RESPCMD;         
  volatile const uint32_t  RESP1;           
  volatile const uint32_t  RESP2;           
  volatile const uint32_t  RESP3;           
  volatile const uint32_t  RESP4;           
  volatile uint32_t DTIMER;                 
  volatile uint32_t DLEN;                   
  volatile uint32_t DCTRL;                  
  volatile const uint32_t  DCOUNT;          
  volatile const uint32_t  STA;             
  volatile uint32_t ICR;                    
  volatile uint32_t MASK;                   
  uint32_t      RESERVED0[2];           
  volatile const uint32_t  FIFOCNT;         
  uint32_t      RESERVED1[13];          
  volatile uint32_t FIFO;                   
} SDIO_TypeDef;



 

typedef struct
{
  volatile uint32_t CR1;         
  volatile uint32_t CR2;         
  volatile uint32_t SR;          
  volatile uint32_t DR;          
  volatile uint32_t CRCPR;       
  volatile uint32_t RXCRCR;      
  volatile uint32_t TXCRCR;      
  volatile uint32_t I2SCFGR;     
  volatile uint32_t I2SPR;       
} SPI_TypeDef;




 

typedef struct
{
  volatile uint32_t CR1;          
  volatile uint32_t CR2;          
  volatile uint32_t SMCR;         
  volatile uint32_t DIER;         
  volatile uint32_t SR;           
  volatile uint32_t EGR;          
  volatile uint32_t CCMR1;        
  volatile uint32_t CCMR2;        
  volatile uint32_t CCER;         
  volatile uint32_t CNT;          
  volatile uint32_t PSC;          
  volatile uint32_t ARR;          
  volatile uint32_t RCR;          
  volatile uint32_t CCR1;         
  volatile uint32_t CCR2;         
  volatile uint32_t CCR3;         
  volatile uint32_t CCR4;         
  volatile uint32_t BDTR;         
  volatile uint32_t DCR;          
  volatile uint32_t DMAR;         
  volatile uint32_t OR;           
} TIM_TypeDef;



 
 
typedef struct
{
  volatile uint32_t SR;          
  volatile uint32_t DR;          
  volatile uint32_t BRR;         
  volatile uint32_t CR1;         
  volatile uint32_t CR2;         
  volatile uint32_t CR3;         
  volatile uint32_t GTPR;        
} USART_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;    
  volatile uint32_t CFR;   
  volatile uint32_t SR;    
} WWDG_TypeDef;



 
  
typedef struct 
{
  volatile uint32_t CR;   
  volatile uint32_t SR;   
  volatile uint32_t DR;   
} RNG_TypeDef;



 
typedef struct
{
  volatile uint32_t GOTGCTL;               
  volatile uint32_t GOTGINT;               
  volatile uint32_t GAHBCFG;               
  volatile uint32_t GUSBCFG;               
  volatile uint32_t GRSTCTL;               
  volatile uint32_t GINTSTS;               
  volatile uint32_t GINTMSK;               
  volatile uint32_t GRXSTSR;               
  volatile uint32_t GRXSTSP;               
  volatile uint32_t GRXFSIZ;               
  volatile uint32_t DIEPTXF0_HNPTXFSIZ;    
  volatile uint32_t HNPTXSTS;              
  uint32_t Reserved30[2];              
  volatile uint32_t GCCFG;                 
  volatile uint32_t CID;                   
  uint32_t  Reserved40[48];            
  volatile uint32_t HPTXFSIZ;              
  volatile uint32_t DIEPTXF[0x0F];         
} USB_OTG_GlobalTypeDef;



 
typedef struct 
{
  volatile uint32_t DCFG;             
  volatile uint32_t DCTL;             
  volatile uint32_t DSTS;             
  uint32_t Reserved0C;            
  volatile uint32_t DIEPMSK;          
  volatile uint32_t DOEPMSK;          
  volatile uint32_t DAINT;            
  volatile uint32_t DAINTMSK;         
  uint32_t  Reserved20;           
  uint32_t Reserved9;             
  volatile uint32_t DVBUSDIS;         
  volatile uint32_t DVBUSPULSE;       
  volatile uint32_t DTHRCTL;          
  volatile uint32_t DIEPEMPMSK;       
  volatile uint32_t DEACHINT;         
  volatile uint32_t DEACHMSK;         
  uint32_t Reserved40;            
  volatile uint32_t DINEP1MSK;        
  uint32_t  Reserved44[15];       
  volatile uint32_t DOUTEP1MSK;       
} USB_OTG_DeviceTypeDef;



 
typedef struct 
{
  volatile uint32_t DIEPCTL;            
  uint32_t Reserved04;              
  volatile uint32_t DIEPINT;            
  uint32_t Reserved0C;              
  volatile uint32_t DIEPTSIZ;           
  volatile uint32_t DIEPDMA;            
  volatile uint32_t DTXFSTS;            
  uint32_t Reserved18;              
} USB_OTG_INEndpointTypeDef;



 
typedef struct 
{
  volatile uint32_t DOEPCTL;        
  uint32_t Reserved04;          
  volatile uint32_t DOEPINT;        
  uint32_t Reserved0C;          
  volatile uint32_t DOEPTSIZ;       
  volatile uint32_t DOEPDMA;        
  uint32_t Reserved18[2];       
} USB_OTG_OUTEndpointTypeDef;



 
typedef struct 
{
  volatile uint32_t HCFG;              
  volatile uint32_t HFIR;              
  volatile uint32_t HFNUM;             
  uint32_t Reserved40C;            
  volatile uint32_t HPTXSTS;           
  volatile uint32_t HAINT;             
  volatile uint32_t HAINTMSK;          
} USB_OTG_HostTypeDef;



 
typedef struct
{
  volatile uint32_t HCCHAR;            
  volatile uint32_t HCSPLT;            
  volatile uint32_t HCINT;             
  volatile uint32_t HCINTMSK;          
  volatile uint32_t HCTSIZ;            
  volatile uint32_t HCDMA;             
  uint32_t Reserved[2];            
} USB_OTG_HostChannelTypeDef;



 



 
#line 1008 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 



 





 
#line 1049 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 1059 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
 
#line 1074 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 1114 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 



 







 

 



#line 1145 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"






 



   
#line 1194 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
 
#line 1253 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"



 



 
  
  

 
    
 
 
 

 
 
 
 
 


 


 
#line 1299 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 1353 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
  
 
#line 1403 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 1459 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 1521 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 




 




 




 




 




 
#line 1592 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 1642 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 1692 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 1731 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 




 




 




 
#line 1759 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 1815 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 
#line 1856 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 1864 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 



 
 
 
 
 
 
 
#line 1906 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
 
#line 1934 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 1984 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 1997 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 2010 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 2024 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 2038 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 2083 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 2094 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 2101 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 2108 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 2137 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"


 
 
#line 2156 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 2167 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 2181 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 2195 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 2212 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 2223 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 2237 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 2251 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 2268 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

   
#line 2279 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 2293 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 2307 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 2321 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 2332 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 2346 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 2360 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 2374 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 2385 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 2399 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 2413 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
 
#line 2422 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 2511 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 2600 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 2689 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 2778 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"


 
#line 2877 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 2975 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 3073 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 3171 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 3269 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 3367 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 3465 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 3563 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 3661 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 3759 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 3857 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 3955 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 4053 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 4151 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 4249 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 4347 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 4445 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 4543 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 4641 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 4739 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 4837 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 4935 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 5033 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 5131 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 5229 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 5327 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 5425 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 5523 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
 
 
 
 
 





 





 




 
 
 
 
 


 

 
#line 5565 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 5572 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"







#line 5586 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 5602 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 5609 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"







#line 5623 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 5630 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 5638 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 




 




 




 




 




 
#line 5676 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 5684 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 5692 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 




 
#line 5710 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
 
 
 
 
 
#line 5748 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 5759 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 5776 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
 
#line 5783 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 5800 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
 


 
#line 5819 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 






 
#line 5843 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 


 
#line 5860 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 5874 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 5882 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 5890 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 5904 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
 
 
 
 
 
#line 5983 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 
#line 6009 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

  
#line 6028 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

  
#line 6090 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

  
#line 6152 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

  
#line 6214 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

  
#line 6276 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 




 





 
 
 
 
 

 

#line 6333 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 

#line 6354 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 

#line 6375 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 6383 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 





 





 





 





 

#line 6434 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 

#line 6446 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 

#line 6473 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 

#line 6485 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 





 





 

#line 6506 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 

 






 




 





 





 





 





 

#line 6553 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 





 

#line 6568 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
                                                                     
 


 
 
 
 
 
 
#line 6649 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 6677 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 6748 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 6773 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 6844 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 6915 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 6986 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 7057 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
 
 
 
 
 
#line 7075 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7105 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 7131 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 7168 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 7176 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7226 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
                                             
 
#line 7243 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
 
 
 
 
 
#line 7256 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"













#line 7308 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 7316 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"













#line 7365 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 7373 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"













#line 7422 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 7430 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"













#line 7479 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 7488 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7496 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7508 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7516 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7524 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7532 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"







 
#line 7547 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7555 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7567 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7575 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7583 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7591 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"







 
#line 7606 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7614 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7626 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7634 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7642 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7650 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"







 
#line 7665 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7673 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7685 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7693 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7701 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7709 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"







 
#line 7724 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7732 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7744 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7752 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"







 
#line 7767 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7775 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7787 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7795 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"







 
#line 7810 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7818 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7830 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7838 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"







 
#line 7853 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7861 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7873 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7881 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"







 

#line 7899 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"











#line 7917 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7925 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7932 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 7943 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"











#line 7961 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7969 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 7976 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 7987 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"











#line 8005 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8013 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8020 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 8043 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 8066 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 8089 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 8102 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8114 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8126 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8138 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 8151 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8163 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8175 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8187 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 8200 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8212 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8224 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8236 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 8249 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8261 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8273 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8285 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 8298 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8310 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8322 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8334 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 8347 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8359 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8371 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8383 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 8396 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8408 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8420 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8432 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"


 




 




 
















































 
















































 
#line 8550 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
                                            
#line 8558 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8566 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8573 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8580 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8587 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8594 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 8603 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
                                            
#line 8611 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8619 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8626 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8633 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8640 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 8647 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 8655 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
                                            








#line 8671 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"





 












 










#line 8708 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
 
 
 
 
 
#line 8795 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 8877 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 8927 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 8945 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 9027 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 9077 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 9159 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 9209 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 9259 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 9277 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 9327 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
 
#line 9344 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 9442 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 9524 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
 
#line 9576 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
 
#line 9633 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 9675 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 9733 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 9775 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"


 
 
 
 
 
 
#line 9825 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 9836 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 9852 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 



#line 9887 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"





 
#line 9899 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 
#line 9948 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 9974 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 9985 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 
#line 9998 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
 
 
 
 
 




 
#line 10016 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 
#line 10029 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"



 
 
 
 
 
 
#line 10053 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 10060 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 10101 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 
#line 10138 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
 


 


 
 
 
 
 
 
#line 10156 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 10165 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 10177 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 10196 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"


 


#line 10207 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"


 


#line 10218 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 10229 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 10242 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"







#line 10256 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 10264 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"


 
 










 










 
#line 10297 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 10307 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 10315 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"







 
#line 10329 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"







 
#line 10345 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 










#line 10363 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 10370 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"







 
#line 10396 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 10421 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 10446 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"





 
#line 10503 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 10514 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
 





 
#line 10596 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 10643 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 


 
#line 10717 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
 


 


#line 10732 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 


 






 
#line 10819 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 10872 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 10931 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 10950 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 10961 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 
#line 11043 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 11096 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 11107 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"







#line 11120 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 11152 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
 



 
#line 11169 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 11183 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 11197 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 11211 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"


#line 11220 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 11227 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 11237 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
                   
#line 11251 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 11265 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"


 
 
 
 
 
 
#line 11279 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 11296 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
 
 
 
 


 


 
#line 11349 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 11393 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 11463 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 


 
#line 11516 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 11524 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 
#line 11537 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 11607 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 11677 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 




 
#line 11695 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 11738 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 11768 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 
#line 11796 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 11844 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 


 
#line 11859 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 11871 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 

    
 
 
 
 
 
 












 












#line 12012 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 12019 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"







#line 12041 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 12049 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 12057 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 12070 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 12080 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"











 
#line 12103 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 12114 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 12124 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
 


 
#line 12136 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"







#line 12150 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"





 
#line 12177 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 12200 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 12207 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 12230 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 





 
 
 
 
 
 






 
#line 12262 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"







#line 12275 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 










#line 12313 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 




 




 




 




 




 




 




 
#line 12367 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 12375 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 12388 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 
#line 12467 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 12508 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 12582 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 




 
 
 
 
 


 
#line 12610 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 12617 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 12648 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 12671 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 12700 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 




 




 




 






























#line 12758 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 12769 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
 
 
 
 
 
#line 12789 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
 

 
#line 12807 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
 


 
#line 12823 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"


 
#line 12837 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"



 
#line 12852 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"



 
#line 12867 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"



 
#line 12882 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 12896 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"



 
#line 12911 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"



 
#line 12926 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"



 
#line 12941 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"



 
#line 12956 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 12970 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"



 
#line 12984 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"



 
#line 12998 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"



 
#line 13012 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"



 
#line 13026 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"


 
#line 13041 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"



 
#line 13055 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"



 
#line 13069 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"



 
#line 13083 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"



 
#line 13097 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 13105 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
 
 
 
 
 
#line 13127 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

















 
#line 13154 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 13161 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 13186 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 13194 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 13201 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"





#line 13213 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"







#line 13226 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 13273 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 13311 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 13337 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 






#line 13351 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 13358 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"











#line 13375 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 13382 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"





 







#line 13402 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"







#line 13416 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 






#line 13430 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 13437 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"











#line 13454 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 13461 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"





 







#line 13481 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"







#line 13495 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 13542 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 




 




 




 




 




 




 




 
#line 13595 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"







#line 13620 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 13630 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 13639 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 






#line 13662 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"


 
 
 
 
 
 
#line 13700 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 
#line 13713 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 13760 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 13783 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"











 
#line 13831 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 13844 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"





 
 
 
 
 
 
#line 13865 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
 
#line 13873 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"





 
#line 13889 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
 
#line 13897 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"






 







 





 
 
 
 
 
 
#line 13929 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 13943 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"







 
#line 14002 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
 


 
#line 14021 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
 
 
 
 
 
#line 14086 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 14130 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 




 
#line 14170 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 
#line 14208 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 14216 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

  




 








 

  
#line 14255 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 14335 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 14352 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 14360 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 




 
#line 14390 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 
#line 14415 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 
#line 14440 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 
 
 

 
#line 14469 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 14480 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 14491 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 14502 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 14513 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 




 




 




 




 




 
 
 

 
#line 14576 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 14595 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 




 
#line 14613 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 
#line 14626 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 




 




 
#line 14649 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
 
 

 
#line 14716 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 




 




 




 
#line 14750 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
   
#line 14843 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 14893 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 14940 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 14954 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 




 




 




 
 
 
 
 
 
#line 15011 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 

#line 15022 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 

#line 15033 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 15044 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"





















 
#line 15075 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 15095 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 15109 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 15131 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 
#line 15144 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




#line 15161 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 15183 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 

#line 15247 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 15264 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"


#line 15280 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 15306 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 15322 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 15334 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 
#line 15377 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
 
#line 15456 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 15536 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 15544 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 
#line 15563 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 15571 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 




 
#line 15595 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 




#line 15617 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 15628 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 15636 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 15652 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 15668 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 
#line 15681 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 15701 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 15709 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 
#line 15743 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 15772 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 15781 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 15789 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"







 
#line 15830 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 15838 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 15852 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 15861 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 15887 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




#line 15906 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"













#line 15938 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 

#line 15951 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 15962 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 15974 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 16009 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 16050 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 16085 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 

#line 16097 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
 
#line 16112 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 




 




 
#line 16135 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 

#line 16176 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 16211 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
 

#line 16219 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"







 
#line 16236 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
 
#line 16249 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"







#line 16263 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 16271 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

#line 16279 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"


  



 



 

 








 


 


 


 


 


 
#line 16332 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 16345 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 


 




 


 


 


 


 


 



 
#line 16385 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"


 
#line 16402 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 


 
#line 16419 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 16429 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 16437 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 16445 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 



 
#line 16457 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 16467 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 16475 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 16483 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 16491 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 16501 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 16511 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
 



 
#line 16522 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 
#line 16585 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 16597 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 16605 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 16619 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 




 
#line 16632 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 16642 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 16650 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 16660 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 
#line 16670 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 



 
#line 16684 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
 
#line 16691 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
 



 





 
#line 16710 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 


 




 


 





 
#line 16737 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"

 



 



 


 


 


 







 




#line 16776 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f427xx.h"
























 
 
 
 
 
 
 
 


 




 



 



 









 
#line 154 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f4xx.h"
#line 193 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f4xx.h"



 



  
typedef enum 
{
  RESET = 0U, 
  SET = !RESET
} FlagStatus, ITStatus;

typedef enum 
{
  DISABLE = 0U, 
  ENABLE = !DISABLE
} FunctionalState;


typedef enum
{
  SUCCESS = 0U,
  ERROR = !SUCCESS
} ErrorStatus;



 




 



















 

#line 1 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal.h"


















  

 
#line 285 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal.h"

 
#line 251 "../Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f4xx.h"









 



 
  



 
#line 31 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_def.h"
#line 1 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


















 

 







 
 
 



 








 



 
#line 89 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 97 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"






 



 





 



 
#line 135 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 202 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 



 



 






 



 

#line 238 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 



 
#line 260 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"





#line 300 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 359 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 



 

#line 454 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 



 

#line 471 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 



 

#line 489 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 




 
#line 508 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 





 



 


















#line 551 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"





#line 562 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 569 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"










 



 
#line 593 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 602 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 
#line 625 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 





 



 






 



 















 
 






 



 














 



 










 



 




























 



 


#line 758 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"






 



 

 
#line 780 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

 












 



 






























 




 















 




 
#line 867 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 









#line 897 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 



 



#line 935 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 945 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 964 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"












 



 




 



 

























 




 








 



 




 



 
#line 1053 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 



 

#line 1070 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 1082 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 1113 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 



 











 






 






#line 1157 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 




 



 

 



 



 



 
#line 1189 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

 













 



 
#line 1224 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 
#line 1238 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

 

 



 







#line 1263 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 1274 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"
 

 



 
#line 1297 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 1305 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"






#line 1321 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 

 



 





 



 



 



 
#line 1361 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 



 



 






 




 



 

 



 





 



 
#line 1422 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"









 




 
#line 1450 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 1471 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 1482 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 1491 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 1504 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 1513 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 



 







 



 
#line 1549 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 1564 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


#line 1597 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 



 
#line 1764 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



#line 1774 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 

#line 1788 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 







 



 

#line 1811 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 



 

#line 1839 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 










 



 














 




 




 




 







 




 
#line 1917 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 




 
#line 1961 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 1975 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 




 







#line 2248 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 2262 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 2505 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 2653 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

 



#line 2678 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 2699 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 2816 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 2833 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 2848 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"






#line 2877 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

















#line 2903 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"





#line 2930 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 2937 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 2946 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 2979 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 2997 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"












#line 3015 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 3036 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 3044 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 



 




 



 
#line 3067 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 3095 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 3110 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"






 



 




#line 3146 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"
 




#line 3176 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 3183 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 3195 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 

#line 3209 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"








 



 
#line 3230 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 







 



 













 




 











 



 












#line 3303 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 3312 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 3321 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"








 



 








#line 3354 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"




 



 

#line 3371 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"






 



 




 



 
#line 3405 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 







 



 
#line 3432 "../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 



 







 

#line 32 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_def.h"
#line 1 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"
 






 

 
 
 





 





#line 34 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"




  typedef signed int ptrdiff_t;



  



    typedef unsigned int size_t;    
#line 57 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"



   



      typedef unsigned short wchar_t;  
#line 82 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"



    




   










#line 107 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"



 

#line 33 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_def.h"

 



   
typedef enum 
{
  HAL_OK       = 0x00U,
  HAL_ERROR    = 0x01U,
  HAL_BUSY     = 0x02U,
  HAL_TIMEOUT  = 0x03U
} HAL_StatusTypeDef;



 
typedef enum 
{
  HAL_UNLOCKED = 0x00U,
  HAL_LOCKED   = 0x01U  
} HAL_LockTypeDef;

 




























 


#line 103 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_def.h"







#line 118 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_def.h"


 
#line 140 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_def.h"




  









 


#line 173 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_def.h"



  



 


#line 190 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_def.h"







 
#line 30 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"

 
 
#line 1 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"

















  

 







 
#line 30 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"



 



  

 


 



 
typedef struct
{
  uint32_t PLLState;   
 

  uint32_t PLLSource;  
 

  uint32_t PLLM;       
 

  uint32_t PLLN;       

 

  uint32_t PLLP;       
 

  uint32_t PLLQ;       
 
#line 75 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"
}RCC_PLLInitTypeDef;

#line 176 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"

#line 202 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"

#line 293 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"





 
typedef struct
{
  uint32_t PLLI2SN;    

 

  uint32_t PLLI2SR;    

 

  uint32_t PLLI2SQ;    

 
}RCC_PLLI2SInitTypeDef;



 
typedef struct
{
  uint32_t PLLSAIN;    

  





                                 
  uint32_t PLLSAIQ;    

 
                              
  uint32_t PLLSAIR;    

 

}RCC_PLLSAIInitTypeDef;



 
typedef struct
{
  uint32_t PeriphClockSelection; 
 

  RCC_PLLI2SInitTypeDef PLLI2S;  
 

  RCC_PLLSAIInitTypeDef PLLSAI;  
 

  uint32_t PLLI2SDivQ;           

 

  uint32_t PLLSAIDivQ;           

 

  uint32_t PLLSAIDivR;           
 

  uint32_t RTCClockSelection;      
 

  uint8_t TIMPresSelection;      
 
#line 375 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"
}RCC_PeriphCLKInitTypeDef;



#line 421 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"


  

 


 



 
 
#line 454 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"
 

 
#line 464 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"
 

 
#line 481 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"
 
    
 
#line 495 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"
 

 
#line 507 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"
 

 
#line 519 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"
 


 






 




 





 
#line 548 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"


 



 
#line 562 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"


 



 
#line 575 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"


 




 





  



 





  

      
#line 629 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"

#line 722 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"

#line 777 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"

#line 856 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"

#line 890 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"








 




 




#line 922 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"








 






 




#line 954 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"



 
     
 


 
 







 
#line 1108 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"



 







 







 
  






 
#line 1156 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"

#line 1177 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"


 
  






 
#line 1196 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"

#line 1216 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"




                                        


#line 1231 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"


 
  






  



#line 1252 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"








    







 
#line 1287 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"


 








 
#line 1305 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"


 
    






 
#line 1467 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"


 







 
#line 1496 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"

#line 1515 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"


 
    






 
#line 1598 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"

#line 1610 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"

#line 1622 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"


 
  






   
#line 1642 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"

#line 1652 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"












 




 
#line 1681 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"

#line 1693 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"


 




 










#line 1718 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"


 




  











 




  
#line 1761 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"

#line 1780 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"


 




 
#line 1795 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"

#line 1803 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"












 








 
#line 1845 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"

#line 1865 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"


 








 









#line 1893 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"


 








 









 








   
#line 1942 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"

#line 1961 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"


 
                                        







  
#line 1982 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"

#line 1992 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"













 

 

 
#line 2875 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"
 

 
#line 3256 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"
 

 
#line 3526 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"
 

 
#line 3902 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"
 

 
#line 4706 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"
 

 
#line 5735 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"
 

 
#line 5781 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"




























 
#line 5816 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"
 
                             
 








 



#line 5899 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"














 





#line 5944 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"


















 




 

 




 



#line 6010 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"
                                 
#line 6034 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"















 







 

 
#line 6076 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"
                                 







 







 











 


 

 











 








 


                                 

                                 












 














 



#line 6331 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"
      
#line 6380 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"

#line 6614 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"

#line 6669 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"
      

















      






 



 



 



 




 




 




#line 6733 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"



 

 


 



 
HAL_StatusTypeDef HAL_RCCEx_PeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);
void HAL_RCCEx_GetPeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);

uint32_t HAL_RCCEx_GetPeriphCLKFreq(uint32_t PeriphClk);

#line 6758 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"
HAL_StatusTypeDef HAL_RCCEx_EnablePLLI2S(RCC_PLLI2SInitTypeDef  *PLLI2SInit);
HAL_StatusTypeDef HAL_RCCEx_DisablePLLI2S(void);


HAL_StatusTypeDef HAL_RCCEx_EnablePLLSAI(RCC_PLLSAIInitTypeDef  *PLLSAIInit);
HAL_StatusTypeDef HAL_RCCEx_DisablePLLSAI(void);



  



 
 
 
 


 




 
   


 











 






 





 
#line 6818 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"

 





 


      



      
#line 6843 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"

#line 6853 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"




 



 

 


 


 
#line 6880 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"
      



























      



      






















#line 6942 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"

#line 6962 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"

#line 7014 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"

#line 7035 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"

#line 7099 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc_ex.h"






      













 



 



  



   






 
#line 34 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"



 



 

 


 



 
typedef struct
{
  uint32_t OscillatorType;       
 

  uint32_t HSEState;             
 

  uint32_t LSEState;             
 

  uint32_t HSIState;             
 

  uint32_t HSICalibrationValue;  
 

  uint32_t LSIState;             
 

  RCC_PLLInitTypeDef PLL;         
}RCC_OscInitTypeDef;



 
typedef struct
{
  uint32_t ClockType;             
 

  uint32_t SYSCLKSource;          
 

  uint32_t AHBCLKDivider;         
 

  uint32_t APB1CLKDivider;        
 

  uint32_t APB2CLKDivider;        
 

}RCC_ClkInitTypeDef;



 

 


 



 







 



 





 



 





 



 






 



 




 



 





 



 






 



 




 



 






 





 






 





 






 



 
#line 236 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"


 



 







 



 
#line 289 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"


 



 




 



 






 



 







 



 
#line 335 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"


 









 
 





 


 
#line 366 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"


 



 

 


 







 
#line 428 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"

#line 435 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"


 







 
#line 452 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"

#line 459 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"


 







 
#line 519 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"

#line 527 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"


 







 
#line 545 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"

#line 553 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"


 







 
#line 620 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"

#line 629 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"


 







 
#line 648 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"

#line 657 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"


 




 
#line 672 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"

#line 680 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"


 




 
#line 696 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"

#line 705 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"


 




 
#line 722 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"

#line 732 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"


 








 
#line 750 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"

#line 757 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"


 








 
#line 776 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"

#line 784 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"


 








 
#line 804 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"

#line 813 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"


 



 















 









 




 



 








 




 



 





















 
#line 912 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"


 



 


















 
#line 955 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"


 



 



 
























 













 







 






 




 



 







 










 










 



 



 









 










 







 



 



 















 




















 




 




 











 












 













 













 




 



















 





 



 

 
 

 



 
 
HAL_StatusTypeDef HAL_RCC_DeInit(void);
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct);
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t FLatency);


 



 
 
void     HAL_RCC_MCOConfig(uint32_t RCC_MCOx, uint32_t RCC_MCOSource, uint32_t RCC_MCODiv);
void     HAL_RCC_EnableCSS(void);
void     HAL_RCC_DisableCSS(void);
uint32_t HAL_RCC_GetSysClockFreq(void);
uint32_t HAL_RCC_GetHCLKFreq(void);
uint32_t HAL_RCC_GetPCLK1Freq(void);
uint32_t HAL_RCC_GetPCLK2Freq(void);
void     HAL_RCC_GetOscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct);
void     HAL_RCC_GetClockConfig(RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t *pFLatency);

 
void HAL_RCC_NMI_IRQHandler(void);

 
void HAL_RCC_CSSCallback(void);



 



 

 
 
 


 




 

 
 



 


 



 
 



 



 
 




 


 


 


 












 



 

 


 



 






















#line 1413 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"































 



 



 



 







 
#line 246 "../Inc/stm32f4xx_hal_conf.h"


#line 1 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_exti.h"

















 

 







 
#line 30 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_exti.h"



 




 

 



 
typedef enum
{
  HAL_EXTI_COMMON_CB_ID          = 0x00U,
  HAL_EXTI_RISING_CB_ID          = 0x01U,
  HAL_EXTI_FALLING_CB_ID         = 0x02U,
} EXTI_CallbackIDTypeDef;



 
typedef struct
{
  uint32_t Line;                     
  void (* RisingCallback)(void);     
  void (* FallingCallback)(void);    
} EXTI_HandleTypeDef;



 
typedef struct
{
  uint32_t Line;      
 
  uint32_t Mode;      
 
  uint32_t Trigger;   
   
} EXTI_ConfigTypeDef;



 

 


 



 
#line 110 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_exti.h"



 



 




 



 






 
    


 

 


 



 

 


 


 




 




 




 

 


 
#line 198 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_exti.h"












 

 



 




 
 
HAL_StatusTypeDef HAL_EXTI_SetConfigLine(EXTI_HandleTypeDef *hexti, EXTI_ConfigTypeDef *pExtiConfig);
HAL_StatusTypeDef HAL_EXTI_GetConfigLine(EXTI_HandleTypeDef *hexti, EXTI_ConfigTypeDef *pExtiConfig);
HAL_StatusTypeDef HAL_EXTI_ClearConfigLine(EXTI_HandleTypeDef *hexti);
HAL_StatusTypeDef HAL_EXTI_RegisterCallback(EXTI_HandleTypeDef *hexti, EXTI_CallbackIDTypeDef CallbackID, void (*pPendingCbfn)(void));
HAL_StatusTypeDef HAL_EXTI_GetHandle(EXTI_HandleTypeDef *hexti, uint32_t ExtiLine);


 




 
 
void HAL_EXTI_IRQHandler(EXTI_HandleTypeDef *hexti);
uint32_t HAL_EXTI_GetPending(EXTI_HandleTypeDef *hexti, uint32_t Edge);
void HAL_EXTI_ClearPending(EXTI_HandleTypeDef *hexti, uint32_t Edge);
void HAL_EXTI_GenerateSWI(EXTI_HandleTypeDef *hexti);



 



 



 



 







 
#line 250 "../Inc/stm32f4xx_hal_conf.h"


#line 1 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio.h"

















  

 







 
#line 30 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio.h"



 



  

 


 



  
typedef struct
{
  uint32_t Pin;       
 

  uint32_t Mode;      
 

  uint32_t Pull;      
 

  uint32_t Speed;     
 

  uint32_t Alternate;  
 
}GPIO_InitTypeDef;



 
typedef enum
{
  GPIO_PIN_RESET = 0,
  GPIO_PIN_SET = 1,
}GPIO_PinState;


 

 



  



 
#line 103 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio.h"




 










  







    



 





 




 






 

 


   





 
  


 

 


 






 







 







 







 







 



 

 
#line 1 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio_ex.h"

















  

 







 
#line 30 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio_ex.h"



 



  

 
 


 
  


 

 
#line 166 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio_ex.h"
 

 



  








  





  






  







  






  
#line 216 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio_ex.h"

 




  






  







  








  








  





  




  






  




  


 

 
#line 387 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio_ex.h"
 

 
#line 483 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio_ex.h"

 

 
#line 573 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio_ex.h"
 

 
#line 682 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio_ex.h"

 

 
#line 816 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio_ex.h"

 
#line 908 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio_ex.h"

 
#line 982 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio_ex.h"

 
#line 1102 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio_ex.h"
 

 
#line 1225 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio_ex.h"
 


  



 

 


 


 

 


 


 

 
 
 


 


 

 


 


 
#line 1277 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio_ex.h"

#line 1291 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio_ex.h"







#line 1305 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio_ex.h"

#line 1333 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio_ex.h"



 



   
 
#line 1367 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio_ex.h"
 

 
#line 1392 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio_ex.h"


 

 
#line 1418 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio_ex.h"
 

 
#line 1441 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio_ex.h"

 

 
#line 1461 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio_ex.h"
 
 




 
#line 1486 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio_ex.h"
 

 
#line 1518 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio_ex.h"
 

 
#line 1547 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio_ex.h"
 

 



 

 



 



  



 

 


 



 



  



  
  






 
#line 215 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio.h"

 


 



 
 
void  HAL_GPIO_Init(GPIO_TypeDef  *GPIOx, GPIO_InitTypeDef *GPIO_Init);
void  HAL_GPIO_DeInit(GPIO_TypeDef  *GPIOx, uint32_t GPIO_Pin);


 



 
 
GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
void HAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
HAL_StatusTypeDef HAL_GPIO_LockPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void HAL_GPIO_EXTI_IRQHandler(uint16_t GPIO_Pin);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);



  



  
 
 
 


 



 

 


 
#line 282 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_gpio.h"


 

 


 



 



  



 







 
#line 254 "../Inc/stm32f4xx_hal_conf.h"


#line 1 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_dma.h"

















  

 







 
#line 30 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_dma.h"



 



  

 




 
   


 
typedef struct
{
  uint32_t Channel;              
 

  uint32_t Direction;            

 

  uint32_t PeriphInc;            
 

  uint32_t MemInc;               
 

  uint32_t PeriphDataAlignment;  
 

  uint32_t MemDataAlignment;     
 

  uint32_t Mode;                 


 

  uint32_t Priority;             
 

  uint32_t FIFOMode;             


 

  uint32_t FIFOThreshold;        
 

  uint32_t MemBurst;             



 

  uint32_t PeriphBurst;          



 
}DMA_InitTypeDef;




 
typedef enum
{
  HAL_DMA_STATE_RESET             = 0x00U,   
  HAL_DMA_STATE_READY             = 0x01U,   
  HAL_DMA_STATE_BUSY              = 0x02U,   
  HAL_DMA_STATE_TIMEOUT           = 0x03U,   
  HAL_DMA_STATE_ERROR             = 0x04U,   
  HAL_DMA_STATE_ABORT             = 0x05U,   
}HAL_DMA_StateTypeDef;



 
typedef enum
{
  HAL_DMA_FULL_TRANSFER           = 0x00U,   
  HAL_DMA_HALF_TRANSFER           = 0x01U    
}HAL_DMA_LevelCompleteTypeDef;



 
typedef enum
{
  HAL_DMA_XFER_CPLT_CB_ID         = 0x00U,   
  HAL_DMA_XFER_HALFCPLT_CB_ID     = 0x01U,   
  HAL_DMA_XFER_M1CPLT_CB_ID       = 0x02U,   
  HAL_DMA_XFER_M1HALFCPLT_CB_ID   = 0x03U,   
  HAL_DMA_XFER_ERROR_CB_ID        = 0x04U,   
  HAL_DMA_XFER_ABORT_CB_ID        = 0x05U,   
  HAL_DMA_XFER_ALL_CB_ID          = 0x06U    
}HAL_DMA_CallbackIDTypeDef;



 
typedef struct __DMA_HandleTypeDef
{
  DMA_Stream_TypeDef         *Instance;                                                         

  DMA_InitTypeDef            Init;                                                               

  HAL_LockTypeDef            Lock;                                                                

  volatile HAL_DMA_StateTypeDef  State;                                                             

  void                       *Parent;                                                            

  void                       (* XferCpltCallback)( struct __DMA_HandleTypeDef * hdma);          

  void                       (* XferHalfCpltCallback)( struct __DMA_HandleTypeDef * hdma);      

  void                       (* XferM1CpltCallback)( struct __DMA_HandleTypeDef * hdma);        
  
  void                       (* XferM1HalfCpltCallback)( struct __DMA_HandleTypeDef * hdma);    
  
  void                       (* XferErrorCallback)( struct __DMA_HandleTypeDef * hdma);         
  
  void                       (* XferAbortCallback)( struct __DMA_HandleTypeDef * hdma);           

  volatile uint32_t              ErrorCode;                                                         
  
  uint32_t                   StreamBaseAddress;                                                 

  uint32_t                   StreamIndex;                                                       
 
}DMA_HandleTypeDef;



 

 




 




  
#line 194 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_dma.h"


 




  
#line 220 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_dma.h"


 




  





 
        



  




  




  




 




  





  




 





 




  





 




 






  




 




  




 






  




  






  




  






 




 







 




  
#line 383 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_dma.h"


 



 
 
 




 













 






 






 


 





 
#line 448 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_dma.h"





       
#line 468 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_dma.h"





 
#line 488 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_dma.h"





 
#line 508 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_dma.h"





 
#line 528 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_dma.h"













 

















 
















 














 














 




















 







 



 
#line 1 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_dma_ex.h"

















 

 







 
#line 30 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_dma_ex.h"



 



  

 



 
   


  
typedef enum
{
  MEMORY0      = 0x00U,     
  MEMORY1      = 0x01U      
}HAL_DMA_MemoryTypeDef;



 

 



 




 

 
HAL_StatusTypeDef HAL_DMAEx_MultiBufferStart(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t SecondMemAddress, uint32_t DataLength);
HAL_StatusTypeDef HAL_DMAEx_MultiBufferStart_IT(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t SecondMemAddress, uint32_t DataLength);
HAL_StatusTypeDef HAL_DMAEx_ChangeMemory(DMA_HandleTypeDef *hdma, uint32_t Address, HAL_DMA_MemoryTypeDef memory);



 


 
         
 



 


 



 



 







 
#line 641 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_dma.h"

 




 




 
HAL_StatusTypeDef HAL_DMA_Init(DMA_HandleTypeDef *hdma); 
HAL_StatusTypeDef HAL_DMA_DeInit(DMA_HandleTypeDef *hdma);


 




 
HAL_StatusTypeDef HAL_DMA_Start (DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
HAL_StatusTypeDef HAL_DMA_Start_IT(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
HAL_StatusTypeDef HAL_DMA_Abort(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_Abort_IT(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_PollForTransfer(DMA_HandleTypeDef *hdma, HAL_DMA_LevelCompleteTypeDef CompleteLevel, uint32_t Timeout);
void              HAL_DMA_IRQHandler(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_CleanCallbacks(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_RegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID, void (* pCallback)(DMA_HandleTypeDef *_hdma));
HAL_StatusTypeDef HAL_DMA_UnRegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID);



  




 
HAL_DMA_StateTypeDef HAL_DMA_GetState(DMA_HandleTypeDef *hdma);
uint32_t             HAL_DMA_GetError(DMA_HandleTypeDef *hdma);


  


  
 



 


  

 



 
#line 730 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_dma.h"

















































  

 



 


 



  



 







 
#line 258 "../Inc/stm32f4xx_hal_conf.h"

   
#line 1 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_cortex.h"

















  

 







 
#line 30 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_cortex.h"



 



  
 


 





 
typedef struct
{
  uint8_t                Enable;                
 
  uint8_t                Number;                
 
  uint32_t               BaseAddress;            
  uint8_t                Size;                  
 
  uint8_t                SubRegionDisable;      
          
  uint8_t                TypeExtField;          
                  
  uint8_t                AccessPermission;      
 
  uint8_t                DisableExec;           
 
  uint8_t                IsShareable;           
 
  uint8_t                IsCacheable;           
 
  uint8_t                IsBufferable;          
 
}MPU_Region_InitTypeDef;


 




 

 



 



 
#line 100 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_cortex.h"


 



 





 




 







 



 




 



 




 



 




 



 




 



 




 



 





 



 
#line 213 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_cortex.h"


 
   


 
#line 226 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_cortex.h"


 



 
#line 241 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_cortex.h"


 




 


 

 


 
  


 
 
void HAL_NVIC_SetPriorityGrouping(uint32_t PriorityGroup);
void HAL_NVIC_SetPriority(IRQn_Type IRQn, uint32_t PreemptPriority, uint32_t SubPriority);
void HAL_NVIC_EnableIRQ(IRQn_Type IRQn);
void HAL_NVIC_DisableIRQ(IRQn_Type IRQn);
void HAL_NVIC_SystemReset(void);
uint32_t HAL_SYSTICK_Config(uint32_t TicksNumb);


 



 
 
uint32_t HAL_NVIC_GetPriorityGrouping(void);
void HAL_NVIC_GetPriority(IRQn_Type IRQn, uint32_t PriorityGroup, uint32_t* pPreemptPriority, uint32_t* pSubPriority);
uint32_t HAL_NVIC_GetPendingIRQ(IRQn_Type IRQn);
void HAL_NVIC_SetPendingIRQ(IRQn_Type IRQn);
void HAL_NVIC_ClearPendingIRQ(IRQn_Type IRQn);
uint32_t HAL_NVIC_GetActive(IRQn_Type IRQn);
void HAL_SYSTICK_CLKSourceConfig(uint32_t CLKSource);
void HAL_SYSTICK_IRQHandler(void);
void HAL_SYSTICK_Callback(void);


void HAL_MPU_Enable(uint32_t MPU_Control);
void HAL_MPU_Disable(void);
void HAL_MPU_ConfigRegion(MPU_Region_InitTypeDef *MPU_Init);



 



 

 
 
 
 


 



































#line 347 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_cortex.h"

#line 356 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_cortex.h"

#line 385 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_cortex.h"






 

 



  



 
  





 

 
#line 262 "../Inc/stm32f4xx_hal_conf.h"






#line 1 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_can.h"

















 

 







 
#line 30 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_can.h"



 




 

 


 


 
typedef enum
{
  HAL_CAN_STATE_RESET             = 0x00U,   
  HAL_CAN_STATE_READY             = 0x01U,   
  HAL_CAN_STATE_LISTENING         = 0x02U,   
  HAL_CAN_STATE_SLEEP_PENDING     = 0x03U,   
  HAL_CAN_STATE_SLEEP_ACTIVE      = 0x04U,   
  HAL_CAN_STATE_ERROR             = 0x05U    

} HAL_CAN_StateTypeDef;



 
typedef struct
{
  uint32_t Prescaler;                  
 

  uint32_t Mode;                       
 

  uint32_t SyncJumpWidth;              

 

  uint32_t TimeSeg1;                   
 

  uint32_t TimeSeg2;                   
 

  FunctionalState TimeTriggeredMode;   
 

  FunctionalState AutoBusOff;          
 

  FunctionalState AutoWakeUp;          
 

  FunctionalState AutoRetransmission;  
 

  FunctionalState ReceiveFifoLocked;   
 

  FunctionalState TransmitFifoPriority;
 

} CAN_InitTypeDef;



 
typedef struct
{
  uint32_t FilterIdHigh;          

 

  uint32_t FilterIdLow;           

 

  uint32_t FilterMaskIdHigh;      


 

  uint32_t FilterMaskIdLow;       


 

  uint32_t FilterFIFOAssignment;  
 

  uint32_t FilterBank;            



 

  uint32_t FilterMode;            
 

  uint32_t FilterScale;           
 

  uint32_t FilterActivation;      
 

  uint32_t SlaveStartFilterBank;  




 

} CAN_FilterTypeDef;



 
typedef struct
{
  uint32_t StdId;    
 

  uint32_t ExtId;    
 

  uint32_t IDE;      
 

  uint32_t RTR;      
 

  uint32_t DLC;      
 

  FunctionalState TransmitGlobalTime; 



 

} CAN_TxHeaderTypeDef;



 
typedef struct
{
  uint32_t StdId;    
 

  uint32_t ExtId;    
 

  uint32_t IDE;      
 

  uint32_t RTR;      
 

  uint32_t DLC;      
 

  uint32_t Timestamp; 

 

  uint32_t FilterMatchIndex; 
 

} CAN_RxHeaderTypeDef;



 
typedef struct __CAN_HandleTypeDef
{
  CAN_TypeDef                 *Instance;                  

  CAN_InitTypeDef             Init;                       

  volatile HAL_CAN_StateTypeDef   State;                      

  volatile uint32_t               ErrorCode;                 
 

#line 239 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_can.h"
} CAN_HandleTypeDef;

#line 272 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_can.h"


 

 



 



 
#line 308 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_can.h"








 



 




 



 






 




 






 



 
#line 369 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_can.h"


 



 
#line 384 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_can.h"


 



 




 



 




 



 




 



 




 



 




 



 




 



 




 



 





 



 
 
#line 483 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_can.h"

 





 






 





 




 
 


 
#line 519 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_can.h"

 



 







 



 

 


 




 
#line 556 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_can.h"







 








 







 







 
#line 595 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_can.h"
























 








 

 


 




 

 
HAL_StatusTypeDef HAL_CAN_Init(CAN_HandleTypeDef *hcan);
HAL_StatusTypeDef HAL_CAN_DeInit(CAN_HandleTypeDef *hcan);
void HAL_CAN_MspInit(CAN_HandleTypeDef *hcan);
void HAL_CAN_MspDeInit(CAN_HandleTypeDef *hcan);

#line 652 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_can.h"


 




 

 
HAL_StatusTypeDef HAL_CAN_ConfigFilter(CAN_HandleTypeDef *hcan, CAN_FilterTypeDef *sFilterConfig);



 




 

 
HAL_StatusTypeDef HAL_CAN_Start(CAN_HandleTypeDef *hcan);
HAL_StatusTypeDef HAL_CAN_Stop(CAN_HandleTypeDef *hcan);
HAL_StatusTypeDef HAL_CAN_RequestSleep(CAN_HandleTypeDef *hcan);
HAL_StatusTypeDef HAL_CAN_WakeUp(CAN_HandleTypeDef *hcan);
uint32_t HAL_CAN_IsSleepActive(CAN_HandleTypeDef *hcan);
HAL_StatusTypeDef HAL_CAN_AddTxMessage(CAN_HandleTypeDef *hcan, CAN_TxHeaderTypeDef *pHeader, uint8_t aData[], uint32_t *pTxMailbox);
HAL_StatusTypeDef HAL_CAN_AbortTxRequest(CAN_HandleTypeDef *hcan, uint32_t TxMailboxes);
uint32_t HAL_CAN_GetTxMailboxesFreeLevel(CAN_HandleTypeDef *hcan);
uint32_t HAL_CAN_IsTxMessagePending(CAN_HandleTypeDef *hcan, uint32_t TxMailboxes);
uint32_t HAL_CAN_GetTxTimestamp(CAN_HandleTypeDef *hcan, uint32_t TxMailbox);
HAL_StatusTypeDef HAL_CAN_GetRxMessage(CAN_HandleTypeDef *hcan, uint32_t RxFifo, CAN_RxHeaderTypeDef *pHeader, uint8_t aData[]);
uint32_t HAL_CAN_GetRxFifoFillLevel(CAN_HandleTypeDef *hcan, uint32_t RxFifo);



 




 
 
HAL_StatusTypeDef HAL_CAN_ActivateNotification(CAN_HandleTypeDef *hcan, uint32_t ActiveITs);
HAL_StatusTypeDef HAL_CAN_DeactivateNotification(CAN_HandleTypeDef *hcan, uint32_t InactiveITs);
void HAL_CAN_IRQHandler(CAN_HandleTypeDef *hcan);



 




 
 

void HAL_CAN_TxMailbox0CompleteCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_TxMailbox1CompleteCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_TxMailbox2CompleteCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_TxMailbox0AbortCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_TxMailbox1AbortCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_TxMailbox2AbortCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_RxFifo0FullCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_RxFifo1FullCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_SleepCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_WakeUpFromRxMsgCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_ErrorCallback(CAN_HandleTypeDef *hcan);



 




 
 
HAL_CAN_StateTypeDef HAL_CAN_GetState(CAN_HandleTypeDef *hcan);
uint32_t HAL_CAN_GetError(CAN_HandleTypeDef *hcan);
HAL_StatusTypeDef HAL_CAN_ResetError(CAN_HandleTypeDef *hcan);



 



 

 


 



 

 


 



 

 


 



 

 


 

#line 825 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_can.h"



 
 



 





 








 
#line 270 "../Inc/stm32f4xx_hal_conf.h"


























#line 1 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash.h"

















  

 







 
#line 30 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash.h"



 



  

 


 
 


 
typedef enum 
{
  FLASH_PROC_NONE = 0U, 
  FLASH_PROC_SECTERASE,
  FLASH_PROC_MASSERASE,
  FLASH_PROC_PROGRAM
} FLASH_ProcedureTypeDef;



 
typedef struct
{
  volatile FLASH_ProcedureTypeDef ProcedureOnGoing;    
  
  volatile uint32_t               NbSectorsToErase;    
  
  volatile uint8_t                VoltageForErase;     
  
  volatile uint32_t               Sector;              
  
  volatile uint32_t               Bank;                
  
  volatile uint32_t               Address;             
  
  HAL_LockTypeDef             Lock;                

  volatile uint32_t               ErrorCode;           

}FLASH_ProcessTypeDef;



 

 


   



  
#line 97 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash.h"


 
  


  






 




  
#line 126 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash.h"


 
  



  




   



 







  



  







  



  
  
 


 





  






  





  





  





  





  





  





  






 








 










   









   
















 















 



 

 
#line 1 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"

















  

 







 
#line 30 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"



 



  

 


 



 
typedef struct
{
  uint32_t TypeErase;   
 

  uint32_t Banks;       
 

  uint32_t Sector;      
 

  uint32_t NbSectors;   
 

  uint32_t VoltageRange;
 

} FLASH_EraseInitTypeDef;



 
typedef struct
{
  uint32_t OptionType;   
 

  uint32_t WRPState;     
 

  uint32_t WRPSector;         
 

  uint32_t Banks;        
         

  uint32_t RDPLevel;     
 

  uint32_t BORLevel;     
 

  uint8_t  USERConfig;    

} FLASH_OBProgramInitTypeDef;



 





typedef struct
{
  uint32_t OptionType;     
 

  uint32_t PCROPState;     
 

#line 115 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"


  uint32_t Banks;          
 

  uint16_t SectorsBank1;   
 

  uint16_t SectorsBank2;   
 

  uint8_t BootConfig;      
 


}FLASH_AdvOBProgramInitTypeDef;




 

 



 



  




 
  


  






 
  


  




 
  


  






 
  


 






  
  


  




  
  


  




  




  




     



   






 








  




 






  






#line 266 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"


 



 
   
#line 293 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"
 

  
#line 311 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"
 



  
  



 
#line 327 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"

#line 336 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"


  
    


 





#line 356 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"


  



 
    
#line 391 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"
 

    
#line 412 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"
       

  
#line 430 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"
 

  
#line 441 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"
 

  
#line 451 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"
 

 
#line 464 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"
 



  



 
   
#line 502 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"
 

  
#line 524 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"
     
      
  
#line 543 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"
 

 
#line 555 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"
 
 
 
#line 566 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"
 

 
#line 580 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"
 


 
  


 
    
#line 617 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"
 
      
 
#line 639 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"
       

 
#line 651 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"
 

 
#line 662 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"
 

 
#line 677 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"
 



 
  


 







 



 
#line 708 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"


 



  
  
 

 


 



 
 
HAL_StatusTypeDef HAL_FLASHEx_Erase(FLASH_EraseInitTypeDef *pEraseInit, uint32_t *SectorError);
HAL_StatusTypeDef HAL_FLASHEx_Erase_IT(FLASH_EraseInitTypeDef *pEraseInit);
HAL_StatusTypeDef HAL_FLASHEx_OBProgram(FLASH_OBProgramInitTypeDef *pOBInit);
void              HAL_FLASHEx_OBGetConfig(FLASH_OBProgramInitTypeDef *pOBInit);






HAL_StatusTypeDef HAL_FLASHEx_AdvOBProgram (FLASH_AdvOBProgramInitTypeDef *pAdvOBInit);
void              HAL_FLASHEx_AdvOBGetConfig(FLASH_AdvOBProgramInitTypeDef *pAdvOBInit);
HAL_StatusTypeDef HAL_FLASHEx_OB_SelectPCROP(void);
HAL_StatusTypeDef HAL_FLASHEx_OB_DeSelectPCROP(void);






uint16_t          HAL_FLASHEx_OB_GetBank2WRP(void);



 



 
 
 
 


 
  




 




  





  




  




 






  






 

 


 



 



























#line 849 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"







#line 863 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"
  
#line 883 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"

#line 898 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"







#line 913 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"
 
#line 928 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"

#line 939 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"

#line 949 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"













#line 968 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"





  
























   


























#line 1034 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"


 



 

 


 
void FLASH_Erase_Sector(uint32_t Sector, uint8_t VoltageRange);
void FLASH_FlushCaches(void);


  



  



 







 
#line 298 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash.h"
#line 1 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ramfunc.h"

















  

 



#line 75 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ramfunc.h"




 
#line 299 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash.h"

 


 


 
 
HAL_StatusTypeDef HAL_FLASH_Program(uint32_t TypeProgram, uint32_t Address, uint64_t Data);
HAL_StatusTypeDef HAL_FLASH_Program_IT(uint32_t TypeProgram, uint32_t Address, uint64_t Data);
 
void HAL_FLASH_IRQHandler(void);
  
void HAL_FLASH_EndOfOperationCallback(uint32_t ReturnValue);
void HAL_FLASH_OperationErrorCallback(uint32_t ReturnValue);


 



 
 
HAL_StatusTypeDef HAL_FLASH_Unlock(void);
HAL_StatusTypeDef HAL_FLASH_Lock(void);
HAL_StatusTypeDef HAL_FLASH_OB_Unlock(void);
HAL_StatusTypeDef HAL_FLASH_OB_Lock(void);
 
HAL_StatusTypeDef HAL_FLASH_OB_Launch(void);


 



 
 
uint32_t HAL_FLASH_GetError(void);
HAL_StatusTypeDef FLASH_WaitForLastOperation(uint32_t Timeout);


 



  
 
 


 



 
 


 



  



  



  



  



  




 

 


 



 






 



 

 


 



 



  



 







 
#line 298 "../Inc/stm32f4xx_hal_conf.h"

 















  
























#line 1 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pwr.h"

















  

 







 
#line 30 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pwr.h"



 



  

 



 
   


 
typedef struct
{
  uint32_t PVDLevel;   
 

  uint32_t Mode;      
 
}PWR_PVDTypeDef;



 

 


 
  


 



 



  
#line 86 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pwr.h"


    
 


 
#line 100 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pwr.h"


 




 




 
    


 




 



 




 



 







 



  
  
 


 





















 







 





 





 





 





 





 





 





 






 






 








 







 





 





 




 

 
#line 1 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pwr_ex.h"

















  

 







 
#line 30 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pwr_ex.h"



 



  

  
 


 


   


 




  
  


 





 




 
#line 80 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pwr_ex.h"


 
#line 99 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pwr_ex.h"



  
  
 


 

#line 127 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pwr_ex.h"









 
#line 145 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pwr_ex.h"





 





 












 














 




 





 

 


 
 


 
void HAL_PWREx_EnableFlashPowerDown(void);
void HAL_PWREx_DisableFlashPowerDown(void); 
HAL_StatusTypeDef HAL_PWREx_EnableBkUpReg(void);
HAL_StatusTypeDef HAL_PWREx_DisableBkUpReg(void); 
uint32_t HAL_PWREx_GetVoltageRange(void);
HAL_StatusTypeDef HAL_PWREx_ControlVoltageScaling(uint32_t VoltageScaling);

#line 221 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pwr_ex.h"



HAL_StatusTypeDef HAL_PWREx_EnableOverDrive(void);
HAL_StatusTypeDef HAL_PWREx_DisableOverDrive(void);
HAL_StatusTypeDef HAL_PWREx_EnterUnderDriveSTOPMode(uint32_t Regulator, uint8_t STOPEntry);




 



 
 
 
 


 



 
 
 
 



 



 


    
 



 



 

 



   
 
 





 



 

 


 



 






#line 310 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pwr_ex.h"

#line 321 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pwr_ex.h"


 



 



  



 
  







 
#line 275 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pwr.h"

 


 
  


 
 
void HAL_PWR_DeInit(void);
void HAL_PWR_EnableBkUpAccess(void);
void HAL_PWR_DisableBkUpAccess(void);


 



 
 
 
void HAL_PWR_ConfigPVD(PWR_PVDTypeDef *sConfigPVD);
void HAL_PWR_EnablePVD(void);
void HAL_PWR_DisablePVD(void);

 
void HAL_PWR_EnableWakeUpPin(uint32_t WakeUpPinx);
void HAL_PWR_DisableWakeUpPin(uint32_t WakeUpPinx);

 
void HAL_PWR_EnterSTOPMode(uint32_t Regulator, uint8_t STOPEntry);
void HAL_PWR_EnterSLEEPMode(uint32_t Regulator, uint8_t SLEEPEntry);
void HAL_PWR_EnterSTANDBYMode(void);

 
void HAL_PWR_PVD_IRQHandler(void);
void HAL_PWR_PVDCallback(void);

 
void HAL_PWR_EnableSleepOnExit(void);
void HAL_PWR_DisableSleepOnExit(void);
void HAL_PWR_EnableSEVOnPend(void);
void HAL_PWR_DisableSEVOnPend(void);


 



 

 
 
 


 



 



 



 
 







 



 
 
 



 



 




 



 
 
 




 



 
 


 



 
#line 408 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pwr.h"


 



 



  



 
  







 
#line 342 "../Inc/stm32f4xx_hal_conf.h"


























#line 1 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim.h"

















 

 







 
#line 30 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim.h"



 



 

 


 



 
typedef struct
{
  uint32_t Prescaler;         
 

  uint32_t CounterMode;       
 

  uint32_t Period;            

 

  uint32_t ClockDivision;     
 

  uint32_t RepetitionCounter;  






 

  uint32_t AutoReloadPreload;  
 
} TIM_Base_InitTypeDef;



 
typedef struct
{
  uint32_t OCMode;        
 

  uint32_t Pulse;         
 

  uint32_t OCPolarity;    
 

  uint32_t OCNPolarity;   

 

  uint32_t OCFastMode;    

 


  uint32_t OCIdleState;   

 

  uint32_t OCNIdleState;  

 
} TIM_OC_InitTypeDef;



 
typedef struct
{
  uint32_t OCMode;        
 

  uint32_t Pulse;         
 

  uint32_t OCPolarity;    
 

  uint32_t OCNPolarity;   

 

  uint32_t OCIdleState;   

 

  uint32_t OCNIdleState;  

 

  uint32_t ICPolarity;    
 

  uint32_t ICSelection;   
 

  uint32_t ICFilter;      
 
} TIM_OnePulse_InitTypeDef;



 
typedef struct
{
  uint32_t  ICPolarity;  
 

  uint32_t ICSelection;  
 

  uint32_t ICPrescaler;  
 

  uint32_t ICFilter;     
 
} TIM_IC_InitTypeDef;



 
typedef struct
{
  uint32_t EncoderMode;   
 

  uint32_t IC1Polarity;   
 

  uint32_t IC1Selection;  
 

  uint32_t IC1Prescaler;  
 

  uint32_t IC1Filter;     
 

  uint32_t IC2Polarity;   
 

  uint32_t IC2Selection;  
 

  uint32_t IC2Prescaler;  
 

  uint32_t IC2Filter;     
 
} TIM_Encoder_InitTypeDef;



 
typedef struct
{
  uint32_t ClockSource;     
 
  uint32_t ClockPolarity;   
 
  uint32_t ClockPrescaler;  
 
  uint32_t ClockFilter;     
 
} TIM_ClockConfigTypeDef;



 
typedef struct
{
  uint32_t ClearInputState;      
 
  uint32_t ClearInputSource;     
 
  uint32_t ClearInputPolarity;   
 
  uint32_t ClearInputPrescaler;  
 
  uint32_t ClearInputFilter;     
 
} TIM_ClearInputConfigTypeDef;



 
typedef struct
{
  uint32_t  MasterOutputTrigger;   
 
  uint32_t  MasterSlaveMode;       
 
} TIM_MasterConfigTypeDef;



 
typedef struct
{
  uint32_t  SlaveMode;         
 
  uint32_t  InputTrigger;      
 
  uint32_t  TriggerPolarity;   
 
  uint32_t  TriggerPrescaler;  
 
  uint32_t  TriggerFilter;     
 

} TIM_SlaveConfigTypeDef;





 
typedef struct
{
  uint32_t OffStateRunMode;      
 
  uint32_t OffStateIDLEMode;     
 
  uint32_t LockLevel;            
 
  uint32_t DeadTime;             
 
  uint32_t BreakState;           
 
  uint32_t BreakPolarity;        
 
  uint32_t BreakFilter;          
 
  uint32_t AutomaticOutput;      
 
} TIM_BreakDeadTimeConfigTypeDef;



 
typedef enum
{
  HAL_TIM_STATE_RESET             = 0x00U,     
  HAL_TIM_STATE_READY             = 0x01U,     
  HAL_TIM_STATE_BUSY              = 0x02U,     
  HAL_TIM_STATE_TIMEOUT           = 0x03U,     
  HAL_TIM_STATE_ERROR             = 0x04U      
} HAL_TIM_StateTypeDef;



 
typedef enum
{
  HAL_TIM_ACTIVE_CHANNEL_1        = 0x01U,     
  HAL_TIM_ACTIVE_CHANNEL_2        = 0x02U,     
  HAL_TIM_ACTIVE_CHANNEL_3        = 0x04U,     
  HAL_TIM_ACTIVE_CHANNEL_4        = 0x08U,     
  HAL_TIM_ACTIVE_CHANNEL_CLEARED  = 0x00U      
} HAL_TIM_ActiveChannel;



 



typedef struct

{
  TIM_TypeDef                 *Instance;      
  TIM_Base_InitTypeDef        Init;           
  HAL_TIM_ActiveChannel       Channel;        
  DMA_HandleTypeDef           *hdma[7];      
 
  HAL_LockTypeDef             Lock;           
  volatile HAL_TIM_StateTypeDef   State;          

#line 350 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim.h"
} TIM_HandleTypeDef;

#line 394 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim.h"



 
 

 


 



 




 



 
#line 437 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim.h"


 



 
#line 452 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim.h"


 



 





 



 




 



 






 



 







 



 





 



 




 



 





 



 




 



 




 



 




 



 




 



 




 



 




 



 





 



 







 



 






 



 




 



 





 



 
#line 644 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim.h"


 



 




 



 
#line 667 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim.h"


 



 
#line 686 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim.h"


 



 







 



 
#line 715 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim.h"


 



 







 



 






 



 




 



 






 



 




 



 




 


 






 



 




 



 




 



 





 



 
#line 829 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim.h"


 



 




 



 







 



 
#line 865 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim.h"


 



 
#line 881 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim.h"


 



 







 



 






 



 




 



 
#line 938 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim.h"


 



 
#line 952 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim.h"


 



 






 



 
 

 


 




 
#line 1002 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim.h"





 






 






 
#line 1032 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim.h"






 
#line 1049 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim.h"






 















 















 














 














 



















 



















 
















 















 








 







 







 






 








 










 












 
#line 1262 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim.h"








 



















 




















 

















 
















 
















 
















 













 













 

















 








 
 

 


 

 




 
 

 


 



#line 1476 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim.h"


































































#line 1552 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim.h"















































#line 1607 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim.h"













#line 1626 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim.h"

#line 1635 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim.h"























#line 1676 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim.h"

































 
 

 
#line 1 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim_ex.h"

















 

 







 
#line 30 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim_ex.h"



 



 

 


 



 

typedef struct
{
  uint32_t IC1Polarity;         
 

  uint32_t IC1Prescaler;        
 

  uint32_t IC1Filter;           
 

  uint32_t Commutation_Delay;   
 
} TIM_HallSensor_InitTypeDef;


 
 

 


 



 
#line 84 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim_ex.h"












#line 108 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim_ex.h"


 



 
 

 


 



 
 

 


 
#line 193 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim_ex.h"



 
 

 


 




 
 
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Init(TIM_HandleTypeDef *htim, TIM_HallSensor_InitTypeDef *sConfig);
HAL_StatusTypeDef HAL_TIMEx_HallSensor_DeInit(TIM_HandleTypeDef *htim);

void HAL_TIMEx_HallSensor_MspInit(TIM_HandleTypeDef *htim);
void HAL_TIMEx_HallSensor_MspDeInit(TIM_HandleTypeDef *htim);

 
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Start(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Stop(TIM_HandleTypeDef *htim);
 
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Start_IT(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Stop_IT(TIM_HandleTypeDef *htim);
 
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Start_DMA(TIM_HandleTypeDef *htim, uint32_t *pData, uint16_t Length);
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Stop_DMA(TIM_HandleTypeDef *htim);


 




 
 
 
HAL_StatusTypeDef HAL_TIMEx_OCN_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIMEx_OCN_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);

 
HAL_StatusTypeDef HAL_TIMEx_OCN_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIMEx_OCN_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);

 
HAL_StatusTypeDef HAL_TIMEx_OCN_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData, uint16_t Length);
HAL_StatusTypeDef HAL_TIMEx_OCN_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);


 




 
 
 
HAL_StatusTypeDef HAL_TIMEx_PWMN_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIMEx_PWMN_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);

 
HAL_StatusTypeDef HAL_TIMEx_PWMN_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIMEx_PWMN_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
 
HAL_StatusTypeDef HAL_TIMEx_PWMN_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData, uint16_t Length);
HAL_StatusTypeDef HAL_TIMEx_PWMN_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);


 




 
 
 
HAL_StatusTypeDef HAL_TIMEx_OnePulseN_Start(TIM_HandleTypeDef *htim, uint32_t OutputChannel);
HAL_StatusTypeDef HAL_TIMEx_OnePulseN_Stop(TIM_HandleTypeDef *htim, uint32_t OutputChannel);

 
HAL_StatusTypeDef HAL_TIMEx_OnePulseN_Start_IT(TIM_HandleTypeDef *htim, uint32_t OutputChannel);
HAL_StatusTypeDef HAL_TIMEx_OnePulseN_Stop_IT(TIM_HandleTypeDef *htim, uint32_t OutputChannel);


 




 
 
HAL_StatusTypeDef HAL_TIMEx_ConfigCommutEvent(TIM_HandleTypeDef *htim, uint32_t  InputTrigger, uint32_t  CommutationSource);
HAL_StatusTypeDef HAL_TIMEx_ConfigCommutEvent_IT(TIM_HandleTypeDef *htim, uint32_t  InputTrigger, uint32_t  CommutationSource);
HAL_StatusTypeDef HAL_TIMEx_ConfigCommutEvent_DMA(TIM_HandleTypeDef *htim, uint32_t  InputTrigger, uint32_t  CommutationSource);
HAL_StatusTypeDef HAL_TIMEx_MasterConfigSynchronization(TIM_HandleTypeDef *htim, TIM_MasterConfigTypeDef *sMasterConfig);
HAL_StatusTypeDef HAL_TIMEx_ConfigBreakDeadTime(TIM_HandleTypeDef *htim, TIM_BreakDeadTimeConfigTypeDef *sBreakDeadTimeConfig);
HAL_StatusTypeDef HAL_TIMEx_RemapConfig(TIM_HandleTypeDef *htim, uint32_t Remap);


 




 
 
void HAL_TIMEx_CommutCallback(TIM_HandleTypeDef *htim);
void HAL_TIMEx_CommutHalfCpltCallback(TIM_HandleTypeDef *htim);
void HAL_TIMEx_BreakCallback(TIM_HandleTypeDef *htim);


 




 
 
HAL_TIM_StateTypeDef HAL_TIMEx_HallSensor_GetState(TIM_HandleTypeDef *htim);


 



 
 

 


 
void TIMEx_DMACommutationCplt(DMA_HandleTypeDef *hdma);
void TIMEx_DMACommutationHalfCplt(DMA_HandleTypeDef *hdma);


 
 



 



 








 
#line 1714 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_tim.h"

 


 




 
 
HAL_StatusTypeDef HAL_TIM_Base_Init(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_Base_DeInit(TIM_HandleTypeDef *htim);
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim);
void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef *htim);
 
HAL_StatusTypeDef HAL_TIM_Base_Start(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_Base_Stop(TIM_HandleTypeDef *htim);
 
HAL_StatusTypeDef HAL_TIM_Base_Start_IT(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_Base_Stop_IT(TIM_HandleTypeDef *htim);
 
HAL_StatusTypeDef HAL_TIM_Base_Start_DMA(TIM_HandleTypeDef *htim, uint32_t *pData, uint16_t Length);
HAL_StatusTypeDef HAL_TIM_Base_Stop_DMA(TIM_HandleTypeDef *htim);


 




 
 
HAL_StatusTypeDef HAL_TIM_OC_Init(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_OC_DeInit(TIM_HandleTypeDef *htim);
void HAL_TIM_OC_MspInit(TIM_HandleTypeDef *htim);
void HAL_TIM_OC_MspDeInit(TIM_HandleTypeDef *htim);
 
HAL_StatusTypeDef HAL_TIM_OC_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_OC_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);
 
HAL_StatusTypeDef HAL_TIM_OC_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_OC_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
 
HAL_StatusTypeDef HAL_TIM_OC_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData, uint16_t Length);
HAL_StatusTypeDef HAL_TIM_OC_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);


 




 
 
HAL_StatusTypeDef HAL_TIM_PWM_Init(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_PWM_DeInit(TIM_HandleTypeDef *htim);
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim);
void HAL_TIM_PWM_MspDeInit(TIM_HandleTypeDef *htim);
 
HAL_StatusTypeDef HAL_TIM_PWM_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_PWM_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);
 
HAL_StatusTypeDef HAL_TIM_PWM_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_PWM_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
 
HAL_StatusTypeDef HAL_TIM_PWM_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData, uint16_t Length);
HAL_StatusTypeDef HAL_TIM_PWM_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);


 




 
 
HAL_StatusTypeDef HAL_TIM_IC_Init(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_IC_DeInit(TIM_HandleTypeDef *htim);
void HAL_TIM_IC_MspInit(TIM_HandleTypeDef *htim);
void HAL_TIM_IC_MspDeInit(TIM_HandleTypeDef *htim);
 
HAL_StatusTypeDef HAL_TIM_IC_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_IC_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);
 
HAL_StatusTypeDef HAL_TIM_IC_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_IC_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
 
HAL_StatusTypeDef HAL_TIM_IC_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData, uint16_t Length);
HAL_StatusTypeDef HAL_TIM_IC_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);


 




 
 
HAL_StatusTypeDef HAL_TIM_OnePulse_Init(TIM_HandleTypeDef *htim, uint32_t OnePulseMode);
HAL_StatusTypeDef HAL_TIM_OnePulse_DeInit(TIM_HandleTypeDef *htim);
void HAL_TIM_OnePulse_MspInit(TIM_HandleTypeDef *htim);
void HAL_TIM_OnePulse_MspDeInit(TIM_HandleTypeDef *htim);
 
HAL_StatusTypeDef HAL_TIM_OnePulse_Start(TIM_HandleTypeDef *htim, uint32_t OutputChannel);
HAL_StatusTypeDef HAL_TIM_OnePulse_Stop(TIM_HandleTypeDef *htim, uint32_t OutputChannel);
 
HAL_StatusTypeDef HAL_TIM_OnePulse_Start_IT(TIM_HandleTypeDef *htim, uint32_t OutputChannel);
HAL_StatusTypeDef HAL_TIM_OnePulse_Stop_IT(TIM_HandleTypeDef *htim, uint32_t OutputChannel);


 




 
 
HAL_StatusTypeDef HAL_TIM_Encoder_Init(TIM_HandleTypeDef *htim,  TIM_Encoder_InitTypeDef *sConfig);
HAL_StatusTypeDef HAL_TIM_Encoder_DeInit(TIM_HandleTypeDef *htim);
void HAL_TIM_Encoder_MspInit(TIM_HandleTypeDef *htim);
void HAL_TIM_Encoder_MspDeInit(TIM_HandleTypeDef *htim);
 
HAL_StatusTypeDef HAL_TIM_Encoder_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_Encoder_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);
 
HAL_StatusTypeDef HAL_TIM_Encoder_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_Encoder_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
 
HAL_StatusTypeDef HAL_TIM_Encoder_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData1, uint32_t *pData2, uint16_t Length);
HAL_StatusTypeDef HAL_TIM_Encoder_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);


 




 
 
void HAL_TIM_IRQHandler(TIM_HandleTypeDef *htim);


 




 
 
HAL_StatusTypeDef HAL_TIM_OC_ConfigChannel(TIM_HandleTypeDef *htim, TIM_OC_InitTypeDef *sConfig, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_PWM_ConfigChannel(TIM_HandleTypeDef *htim, TIM_OC_InitTypeDef *sConfig, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_IC_ConfigChannel(TIM_HandleTypeDef *htim, TIM_IC_InitTypeDef *sConfig, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_OnePulse_ConfigChannel(TIM_HandleTypeDef *htim, TIM_OnePulse_InitTypeDef *sConfig, uint32_t OutputChannel,  uint32_t InputChannel);
HAL_StatusTypeDef HAL_TIM_ConfigOCrefClear(TIM_HandleTypeDef *htim, TIM_ClearInputConfigTypeDef *sClearInputConfig, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_ConfigClockSource(TIM_HandleTypeDef *htim, TIM_ClockConfigTypeDef *sClockSourceConfig);
HAL_StatusTypeDef HAL_TIM_ConfigTI1Input(TIM_HandleTypeDef *htim, uint32_t TI1_Selection);
HAL_StatusTypeDef HAL_TIM_SlaveConfigSynchro(TIM_HandleTypeDef *htim, TIM_SlaveConfigTypeDef *sSlaveConfig);
HAL_StatusTypeDef HAL_TIM_SlaveConfigSynchro_IT(TIM_HandleTypeDef *htim, TIM_SlaveConfigTypeDef *sSlaveConfig);
HAL_StatusTypeDef HAL_TIM_DMABurst_WriteStart(TIM_HandleTypeDef *htim, uint32_t BurstBaseAddress, uint32_t BurstRequestSrc,                                               uint32_t  *BurstBuffer, uint32_t  BurstLength);

HAL_StatusTypeDef HAL_TIM_DMABurst_WriteStop(TIM_HandleTypeDef *htim, uint32_t BurstRequestSrc);
HAL_StatusTypeDef HAL_TIM_DMABurst_ReadStart(TIM_HandleTypeDef *htim, uint32_t BurstBaseAddress, uint32_t BurstRequestSrc,                                              uint32_t  *BurstBuffer, uint32_t  BurstLength);

HAL_StatusTypeDef HAL_TIM_DMABurst_ReadStop(TIM_HandleTypeDef *htim, uint32_t BurstRequestSrc);
HAL_StatusTypeDef HAL_TIM_GenerateEvent(TIM_HandleTypeDef *htim, uint32_t EventSource);
uint32_t HAL_TIM_ReadCapturedValue(TIM_HandleTypeDef *htim, uint32_t Channel);


 




 
 
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void HAL_TIM_PeriodElapsedHalfCpltCallback(TIM_HandleTypeDef *htim);
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim);
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);
void HAL_TIM_IC_CaptureHalfCpltCallback(TIM_HandleTypeDef *htim);
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim);
void HAL_TIM_PWM_PulseFinishedHalfCpltCallback(TIM_HandleTypeDef *htim);
void HAL_TIM_TriggerCallback(TIM_HandleTypeDef *htim);
void HAL_TIM_TriggerHalfCpltCallback(TIM_HandleTypeDef *htim);
void HAL_TIM_ErrorCallback(TIM_HandleTypeDef *htim);

 







 




 
 
HAL_TIM_StateTypeDef HAL_TIM_Base_GetState(TIM_HandleTypeDef *htim);
HAL_TIM_StateTypeDef HAL_TIM_OC_GetState(TIM_HandleTypeDef *htim);
HAL_TIM_StateTypeDef HAL_TIM_PWM_GetState(TIM_HandleTypeDef *htim);
HAL_TIM_StateTypeDef HAL_TIM_IC_GetState(TIM_HandleTypeDef *htim);
HAL_TIM_StateTypeDef HAL_TIM_OnePulse_GetState(TIM_HandleTypeDef *htim);
HAL_TIM_StateTypeDef HAL_TIM_Encoder_GetState(TIM_HandleTypeDef *htim);


 



 
 

 


 
void TIM_Base_SetConfig(TIM_TypeDef *TIMx, TIM_Base_InitTypeDef *Structure);
void TIM_TI1_SetConfig(TIM_TypeDef *TIMx, uint32_t TIM_ICPolarity, uint32_t TIM_ICSelection, uint32_t TIM_ICFilter);
void TIM_OC2_SetConfig(TIM_TypeDef *TIMx, TIM_OC_InitTypeDef *OC_Config);
void TIM_ETR_SetConfig(TIM_TypeDef *TIMx, uint32_t TIM_ExtTRGPrescaler,
                       uint32_t TIM_ExtTRGPolarity, uint32_t ExtTRGFilter);

void TIM_DMADelayPulseCplt(DMA_HandleTypeDef *hdma);
void TIM_DMADelayPulseHalfCplt(DMA_HandleTypeDef *hdma);
void TIM_DMAError(DMA_HandleTypeDef *hdma);
void TIM_DMACaptureCplt(DMA_HandleTypeDef *hdma);
void TIM_DMACaptureHalfCplt(DMA_HandleTypeDef *hdma);
void TIM_CCxChannelCmd(TIM_TypeDef *TIMx, uint32_t Channel, uint32_t ChannelState);







 
 



 



 







 
#line 370 "../Inc/stm32f4xx_hal_conf.h"


#line 1 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_uart.h"

















 

 







 
#line 30 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_uart.h"



 



 

 


 



 
typedef struct
{
  uint32_t BaudRate;                  



 

  uint32_t WordLength;                
 

  uint32_t StopBits;                  
 

  uint32_t Parity;                    




 

  uint32_t Mode;                      
 

  uint32_t HwFlowCtl;                 
 

  uint32_t OverSampling;              
 
} UART_InitTypeDef;







































 
typedef enum
{
  HAL_UART_STATE_RESET             = 0x00U,    
 
  HAL_UART_STATE_READY             = 0x20U,    
 
  HAL_UART_STATE_BUSY              = 0x24U,    
 
  HAL_UART_STATE_BUSY_TX           = 0x21U,    
 
  HAL_UART_STATE_BUSY_RX           = 0x22U,    
 
  HAL_UART_STATE_BUSY_TX_RX        = 0x23U,    

 
  HAL_UART_STATE_TIMEOUT           = 0xA0U,    
 
  HAL_UART_STATE_ERROR             = 0xE0U     
 
} HAL_UART_StateTypeDef;



 
typedef struct __UART_HandleTypeDef
{
  USART_TypeDef                 *Instance;         

  UART_InitTypeDef              Init;              

  uint8_t                       *pTxBuffPtr;       

  uint16_t                      TxXferSize;        

  volatile uint16_t                 TxXferCount;       

  uint8_t                       *pRxBuffPtr;       

  uint16_t                      RxXferSize;        

  volatile uint16_t                 RxXferCount;       

  DMA_HandleTypeDef             *hdmatx;           

  DMA_HandleTypeDef             *hdmarx;           

  HAL_LockTypeDef               Lock;              

  volatile HAL_UART_StateTypeDef    gState;           

 

  volatile HAL_UART_StateTypeDef    RxState;          
 

  volatile uint32_t                 ErrorCode;         

#line 188 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_uart.h"

} UART_HandleTypeDef;

#line 218 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_uart.h"



 

 


 



 
#line 240 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_uart.h"


 



 




 



 




 



 





 



 






 



 





 



 




 



 




 



 




 



 




 





 
#line 344 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_uart.h"


 









 













 



 

 


 






 
#line 400 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_uart.h"





 



















 























 







 
#line 465 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_uart.h"






 







 







 







 

















 



















 


















 
















 



















 



















 



















 









 





 





 





 



 

 


 



 

 
HAL_StatusTypeDef HAL_UART_Init(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_HalfDuplex_Init(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_LIN_Init(UART_HandleTypeDef *huart, uint32_t BreakDetectLength);
HAL_StatusTypeDef HAL_MultiProcessor_Init(UART_HandleTypeDef *huart, uint8_t Address, uint32_t WakeUpMethod);
HAL_StatusTypeDef HAL_UART_DeInit(UART_HandleTypeDef *huart);
void HAL_UART_MspInit(UART_HandleTypeDef *huart);
void HAL_UART_MspDeInit(UART_HandleTypeDef *huart);

 







 



 

 
HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_UART_Receive(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_UART_Transmit_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_Transmit_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_Receive_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_DMAPause(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_DMAResume(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_DMAStop(UART_HandleTypeDef *huart);
 
HAL_StatusTypeDef HAL_UART_Abort(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortTransmit(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortReceive(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_Abort_IT(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortTransmit_IT(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortReceive_IT(UART_HandleTypeDef *huart);

void HAL_UART_IRQHandler(UART_HandleTypeDef *huart);
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_TxHalfCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart);
void HAL_UART_AbortCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_AbortTransmitCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_AbortReceiveCpltCallback(UART_HandleTypeDef *huart);



 



 
 
HAL_StatusTypeDef HAL_LIN_SendBreak(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_MultiProcessor_EnterMuteMode(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_MultiProcessor_ExitMuteMode(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_HalfDuplex_EnableTransmitter(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_HalfDuplex_EnableReceiver(UART_HandleTypeDef *huart);


 



 
 
HAL_UART_StateTypeDef HAL_UART_GetState(UART_HandleTypeDef *huart);
uint32_t              HAL_UART_GetError(UART_HandleTypeDef *huart);


 



 
 
 
 


 


 







 

 


 
#line 800 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_uart.h"





 








 






 

 


 



 



 



 







 
#line 374 "../Inc/stm32f4xx_hal_conf.h"


















#line 1 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pcd.h"

















 

 







 
#line 1 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_ll_usb.h"

















 

 







 
#line 30 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_ll_usb.h"




 



 

 



 


typedef enum
{
  USB_DEVICE_MODE  = 0,
  USB_HOST_MODE    = 1,
  USB_DRD_MODE     = 2
} USB_OTG_ModeTypeDef;



 
typedef enum
{
  URB_IDLE = 0,
  URB_DONE,
  URB_NOTREADY,
  URB_NYET,
  URB_ERROR,
  URB_STALL
} USB_OTG_URBStateTypeDef;



 
typedef enum
{
  HC_IDLE = 0,
  HC_XFRC,
  HC_HALTED,
  HC_NAK,
  HC_NYET,
  HC_STALL,
  HC_XACTERR,
  HC_BBLERR,
  HC_DATATGLERR
} USB_OTG_HCStateTypeDef;



 
typedef struct
{
  uint32_t dev_endpoints;           

 

  uint32_t Host_channels;           

 

  uint32_t speed;                   
 

  uint32_t dma_enable;               

  uint32_t ep0_mps;                  

  uint32_t phy_itface;              
 

  uint32_t Sof_enable;               

  uint32_t low_power_enable;         

  uint32_t lpm_enable;               

  uint32_t battery_charging_enable;  

  uint32_t vbus_sensing_enable;      

  uint32_t use_dedicated_ep1;        

  uint32_t use_external_vbus;        
} USB_OTG_CfgTypeDef;

typedef struct
{
  uint8_t   num;                  
 

  uint8_t   is_in;                
 

  uint8_t   is_stall;             
 

  uint8_t   type;                 
 

  uint8_t   data_pid_start;       
 

  uint8_t   even_odd_frame;       
 

  uint16_t  tx_fifo_num;          
 

  uint32_t  maxpacket;            
 

  uint8_t   *xfer_buff;            

  uint32_t  dma_addr;              

  uint32_t  xfer_len;              

  uint32_t  xfer_count;            
} USB_OTG_EPTypeDef;

typedef struct
{
  uint8_t   dev_addr ;          
 

  uint8_t   ch_num;             
 

  uint8_t   ep_num;             
 

  uint8_t   ep_is_in;           
 

  uint8_t   speed;              
 

  uint8_t   do_ping;             

  uint8_t   process_ping;        

  uint8_t   ep_type;            
 

  uint16_t  max_packet;         
 

  uint8_t   data_pid;           
 

  uint8_t   *xfer_buff;          

  uint32_t  xfer_len;            

  uint32_t  xfer_count;          

  uint8_t   toggle_in;          
 

  uint8_t   toggle_out;         
 

  uint32_t  dma_addr;            

  uint32_t  ErrCnt;              

  USB_OTG_URBStateTypeDef  urb_state;  
 

  USB_OTG_HCStateTypeDef   state;     
 
} USB_OTG_HCTypeDef;



 



 




 




 



 





 



 





 



 




 



 
#line 266 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_ll_usb.h"


 



 





 



 






 



 






 



 






 



 





 



 







 



 







 



 





 



 





 































 

 


 









 

 


 

HAL_StatusTypeDef USB_CoreInit(USB_OTG_GlobalTypeDef *USBx, USB_OTG_CfgTypeDef cfg);
HAL_StatusTypeDef USB_DevInit(USB_OTG_GlobalTypeDef *USBx, USB_OTG_CfgTypeDef cfg);
HAL_StatusTypeDef USB_EnableGlobalInt(USB_OTG_GlobalTypeDef *USBx);
HAL_StatusTypeDef USB_DisableGlobalInt(USB_OTG_GlobalTypeDef *USBx);
HAL_StatusTypeDef USB_SetTurnaroundTime(USB_OTG_GlobalTypeDef *USBx, uint32_t hclk, uint8_t speed);
HAL_StatusTypeDef USB_SetCurrentMode(USB_OTG_GlobalTypeDef *USBx, USB_OTG_ModeTypeDef mode);
HAL_StatusTypeDef USB_SetDevSpeed(USB_OTG_GlobalTypeDef *USBx, uint8_t speed);
HAL_StatusTypeDef USB_FlushRxFifo(USB_OTG_GlobalTypeDef *USBx);
HAL_StatusTypeDef USB_FlushTxFifo(USB_OTG_GlobalTypeDef *USBx, uint32_t num);
HAL_StatusTypeDef USB_ActivateEndpoint(USB_OTG_GlobalTypeDef *USBx, USB_OTG_EPTypeDef *ep);
HAL_StatusTypeDef USB_DeactivateEndpoint(USB_OTG_GlobalTypeDef *USBx, USB_OTG_EPTypeDef *ep);
HAL_StatusTypeDef USB_ActivateDedicatedEndpoint(USB_OTG_GlobalTypeDef *USBx, USB_OTG_EPTypeDef *ep);
HAL_StatusTypeDef USB_DeactivateDedicatedEndpoint(USB_OTG_GlobalTypeDef *USBx, USB_OTG_EPTypeDef *ep);
HAL_StatusTypeDef USB_EPStartXfer(USB_OTG_GlobalTypeDef *USBx, USB_OTG_EPTypeDef *ep, uint8_t dma);
HAL_StatusTypeDef USB_EP0StartXfer(USB_OTG_GlobalTypeDef *USBx, USB_OTG_EPTypeDef *ep, uint8_t dma);
HAL_StatusTypeDef USB_WritePacket(USB_OTG_GlobalTypeDef *USBx, uint8_t *src, uint8_t ch_ep_num, uint16_t len, uint8_t dma);
void             *USB_ReadPacket(USB_OTG_GlobalTypeDef *USBx, uint8_t *dest, uint16_t len);
HAL_StatusTypeDef USB_EPSetStall(USB_OTG_GlobalTypeDef *USBx, USB_OTG_EPTypeDef *ep);
HAL_StatusTypeDef USB_EPClearStall(USB_OTG_GlobalTypeDef *USBx, USB_OTG_EPTypeDef *ep);
HAL_StatusTypeDef USB_SetDevAddress(USB_OTG_GlobalTypeDef *USBx, uint8_t address);
HAL_StatusTypeDef USB_DevConnect(USB_OTG_GlobalTypeDef *USBx);
HAL_StatusTypeDef USB_DevDisconnect(USB_OTG_GlobalTypeDef *USBx);
HAL_StatusTypeDef USB_StopDevice(USB_OTG_GlobalTypeDef *USBx);
HAL_StatusTypeDef USB_ActivateSetup(USB_OTG_GlobalTypeDef *USBx);
HAL_StatusTypeDef USB_EP0_OutStart(USB_OTG_GlobalTypeDef *USBx, uint8_t dma, uint8_t *psetup);
uint8_t           USB_GetDevSpeed(USB_OTG_GlobalTypeDef *USBx);
uint32_t          USB_GetMode(USB_OTG_GlobalTypeDef *USBx);
uint32_t          USB_ReadInterrupts(USB_OTG_GlobalTypeDef *USBx);
uint32_t          USB_ReadDevAllOutEpInterrupt(USB_OTG_GlobalTypeDef *USBx);
uint32_t          USB_ReadDevOutEPInterrupt(USB_OTG_GlobalTypeDef *USBx, uint8_t epnum);
uint32_t          USB_ReadDevAllInEpInterrupt(USB_OTG_GlobalTypeDef *USBx);
uint32_t          USB_ReadDevInEPInterrupt(USB_OTG_GlobalTypeDef *USBx, uint8_t epnum);
void              USB_ClearInterrupts(USB_OTG_GlobalTypeDef *USBx, uint32_t interrupt);

HAL_StatusTypeDef USB_HostInit(USB_OTG_GlobalTypeDef *USBx, USB_OTG_CfgTypeDef cfg);
HAL_StatusTypeDef USB_InitFSLSPClkSel(USB_OTG_GlobalTypeDef *USBx, uint8_t freq);
HAL_StatusTypeDef USB_ResetPort(USB_OTG_GlobalTypeDef *USBx);
HAL_StatusTypeDef USB_DriveVbus(USB_OTG_GlobalTypeDef *USBx, uint8_t state);
uint32_t          USB_GetHostSpeed(USB_OTG_GlobalTypeDef *USBx);
uint32_t          USB_GetCurrentFrame(USB_OTG_GlobalTypeDef *USBx);
HAL_StatusTypeDef USB_HC_Init(USB_OTG_GlobalTypeDef *USBx,
                              uint8_t ch_num,
                              uint8_t epnum,
                              uint8_t dev_address,
                              uint8_t speed,
                              uint8_t ep_type,
                              uint16_t mps);
HAL_StatusTypeDef USB_HC_StartXfer(USB_OTG_GlobalTypeDef *USBx, USB_OTG_HCTypeDef *hc, uint8_t dma);
uint32_t          USB_HC_ReadInterrupt(USB_OTG_GlobalTypeDef *USBx);
HAL_StatusTypeDef USB_HC_Halt(USB_OTG_GlobalTypeDef *USBx, uint8_t hc_num);
HAL_StatusTypeDef USB_DoPing(USB_OTG_GlobalTypeDef *USBx, uint8_t ch_num);
HAL_StatusTypeDef USB_StopHost(USB_OTG_GlobalTypeDef *USBx);
HAL_StatusTypeDef USB_ActivateRemoteWakeup(USB_OTG_GlobalTypeDef *USBx);
HAL_StatusTypeDef USB_DeActivateRemoteWakeup(USB_OTG_GlobalTypeDef *USBx);




 



 



 



 









 
#line 30 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pcd.h"





 



 

 


 



 
typedef enum
{
  HAL_PCD_STATE_RESET   = 0x00,
  HAL_PCD_STATE_READY   = 0x01,
  HAL_PCD_STATE_ERROR   = 0x02,
  HAL_PCD_STATE_BUSY    = 0x03,
  HAL_PCD_STATE_TIMEOUT = 0x04
} PCD_StateTypeDef;

 
typedef enum
{
  LPM_L0 = 0x00,  
  LPM_L1 = 0x01,  
  LPM_L2 = 0x02,  
  LPM_L3 = 0x03,  
} PCD_LPM_StateTypeDef;

typedef enum
{
  PCD_LPM_L0_ACTIVE = 0x00,  
  PCD_LPM_L1_ACTIVE = 0x01,  
} PCD_LPM_MsgTypeDef;

typedef enum
{
  PCD_BCD_ERROR                     = 0xFF,
  PCD_BCD_CONTACT_DETECTION         = 0xFE,
  PCD_BCD_STD_DOWNSTREAM_PORT       = 0xFD,
  PCD_BCD_CHARGING_DOWNSTREAM_PORT  = 0xFC,
  PCD_BCD_DEDICATED_CHARGING_PORT   = 0xFB,
  PCD_BCD_DISCOVERY_COMPLETED       = 0x00,

} PCD_BCD_MsgTypeDef;


typedef USB_OTG_GlobalTypeDef  PCD_TypeDef;
typedef USB_OTG_CfgTypeDef     PCD_InitTypeDef;
typedef USB_OTG_EPTypeDef      PCD_EPTypeDef;




 



typedef struct

{
  PCD_TypeDef             *Instance;    
  PCD_InitTypeDef         Init;         
  volatile uint8_t            USB_Address;  
  PCD_EPTypeDef           IN_ep[16];    
  PCD_EPTypeDef           OUT_ep[16];   
  HAL_LockTypeDef         Lock;         
  volatile PCD_StateTypeDef   State;        
  volatile  uint32_t          ErrorCode;    
  uint32_t                Setup[12];    
  PCD_LPM_StateTypeDef    LPM_State;    
  uint32_t                BESL;


  uint32_t lpm_active;                 
 

  uint32_t battery_charging_active;    
 
  void                    *pData;       

#line 138 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pcd.h"
} PCD_HandleTypeDef;



 

 
#line 1 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pcd_ex.h"

















 

 







 
#line 30 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pcd_ex.h"




 



 
 
 
 
 


 


 


HAL_StatusTypeDef HAL_PCDEx_SetTxFiFo(PCD_HandleTypeDef *hpcd, uint8_t fifo, uint16_t size);
HAL_StatusTypeDef HAL_PCDEx_SetRxFiFo(PCD_HandleTypeDef *hpcd, uint16_t size);


#line 64 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pcd_ex.h"
void HAL_PCDEx_LPM_Callback(PCD_HandleTypeDef *hpcd, PCD_LPM_MsgTypeDef msg);
void HAL_PCDEx_BCD_Callback(PCD_HandleTypeDef *hpcd, PCD_BCD_MsgTypeDef msg);



 



 



 



 









 
#line 146 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pcd.h"

 


 



 





 



 





 




 






 



 

 



 





















#line 223 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pcd.h"

#line 230 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pcd.h"




 

 


 

 


 
HAL_StatusTypeDef HAL_PCD_Init(PCD_HandleTypeDef *hpcd);
HAL_StatusTypeDef HAL_PCD_DeInit(PCD_HandleTypeDef *hpcd);
void HAL_PCD_MspInit(PCD_HandleTypeDef *hpcd);
void HAL_PCD_MspDeInit(PCD_HandleTypeDef *hpcd);

#line 311 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_pcd.h"


 

 
 


 
HAL_StatusTypeDef HAL_PCD_Start(PCD_HandleTypeDef *hpcd);
HAL_StatusTypeDef HAL_PCD_Stop(PCD_HandleTypeDef *hpcd);
void HAL_PCD_IRQHandler(PCD_HandleTypeDef *hpcd);

void HAL_PCD_SOFCallback(PCD_HandleTypeDef *hpcd);
void HAL_PCD_SetupStageCallback(PCD_HandleTypeDef *hpcd);
void HAL_PCD_ResetCallback(PCD_HandleTypeDef *hpcd);
void HAL_PCD_SuspendCallback(PCD_HandleTypeDef *hpcd);
void HAL_PCD_ResumeCallback(PCD_HandleTypeDef *hpcd);
void HAL_PCD_ConnectCallback(PCD_HandleTypeDef *hpcd);
void HAL_PCD_DisconnectCallback(PCD_HandleTypeDef *hpcd);

void HAL_PCD_DataOutStageCallback(PCD_HandleTypeDef *hpcd, uint8_t epnum);
void HAL_PCD_DataInStageCallback(PCD_HandleTypeDef *hpcd, uint8_t epnum);
void HAL_PCD_ISOOUTIncompleteCallback(PCD_HandleTypeDef *hpcd, uint8_t epnum);
void HAL_PCD_ISOINIncompleteCallback(PCD_HandleTypeDef *hpcd, uint8_t epnum);


 

 


 
HAL_StatusTypeDef HAL_PCD_DevConnect(PCD_HandleTypeDef *hpcd);
HAL_StatusTypeDef HAL_PCD_DevDisconnect(PCD_HandleTypeDef *hpcd);
HAL_StatusTypeDef HAL_PCD_SetAddress(PCD_HandleTypeDef *hpcd, uint8_t address);
HAL_StatusTypeDef HAL_PCD_EP_Open(PCD_HandleTypeDef *hpcd, uint8_t ep_addr, uint16_t ep_mps, uint8_t ep_type);
HAL_StatusTypeDef HAL_PCD_EP_Close(PCD_HandleTypeDef *hpcd, uint8_t ep_addr);
HAL_StatusTypeDef HAL_PCD_EP_Receive(PCD_HandleTypeDef *hpcd, uint8_t ep_addr, uint8_t *pBuf, uint32_t len);
HAL_StatusTypeDef HAL_PCD_EP_Transmit(PCD_HandleTypeDef *hpcd, uint8_t ep_addr, uint8_t *pBuf, uint32_t len);
uint32_t          HAL_PCD_EP_GetRxCount(PCD_HandleTypeDef *hpcd, uint8_t ep_addr);
HAL_StatusTypeDef HAL_PCD_EP_SetStall(PCD_HandleTypeDef *hpcd, uint8_t ep_addr);
HAL_StatusTypeDef HAL_PCD_EP_ClrStall(PCD_HandleTypeDef *hpcd, uint8_t ep_addr);
HAL_StatusTypeDef HAL_PCD_EP_Flush(PCD_HandleTypeDef *hpcd, uint8_t ep_addr);
HAL_StatusTypeDef HAL_PCD_ActivateRemoteWakeup(PCD_HandleTypeDef *hpcd);
HAL_StatusTypeDef HAL_PCD_DeActivateRemoteWakeup(PCD_HandleTypeDef *hpcd);


 

 


 
PCD_StateTypeDef HAL_PCD_GetState(PCD_HandleTypeDef *hpcd);


 



 

 


 


 
















 


 



























 


 



 



 



 








 
#line 394 "../Inc/stm32f4xx_hal_conf.h"





   



























   
 
#line 444 "../Inc/stm32f4xx_hal_conf.h"






 

 
#line 31 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal.h"



 



  

 
 



 



 
typedef enum
{
  HAL_TICK_FREQ_10HZ         = 100U,
  HAL_TICK_FREQ_100HZ        = 10U,
  HAL_TICK_FREQ_1KHZ         = 1U,
  HAL_TICK_FREQ_DEFAULT      = HAL_TICK_FREQ_1KHZ
} HAL_TickFreqTypeDef;


 



 
   
 


 


 
#line 94 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal.h"

#line 117 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal.h"


 



 





 




#line 141 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal.h"




 





 





#line 186 "../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal.h"


 



 





 

 


 


 
 
HAL_StatusTypeDef HAL_Init(void);
HAL_StatusTypeDef HAL_DeInit(void);
void HAL_MspInit(void);
void HAL_MspDeInit(void);
HAL_StatusTypeDef HAL_InitTick (uint32_t TickPriority);


 



 
 
void HAL_IncTick(void);
void HAL_Delay(uint32_t Delay);
uint32_t HAL_GetTick(void);
uint32_t HAL_GetTickPrio(void);
HAL_StatusTypeDef HAL_SetTickFreq(HAL_TickFreqTypeDef Freq);
HAL_TickFreqTypeDef HAL_GetTickFreq(void);
void HAL_SuspendTick(void);
void HAL_ResumeTick(void);
uint32_t HAL_GetHalVersion(void);
uint32_t HAL_GetREVID(void);
uint32_t HAL_GetDEVID(void);
void HAL_DBGMCU_EnableDBGSleepMode(void);
void HAL_DBGMCU_DisableDBGSleepMode(void);
void HAL_DBGMCU_EnableDBGStopMode(void);
void HAL_DBGMCU_DisableDBGStopMode(void);
void HAL_DBGMCU_EnableDBGStandbyMode(void);
void HAL_DBGMCU_DisableDBGStandbyMode(void);
void HAL_EnableCompensationCell(void);
void HAL_DisableCompensationCell(void);
uint32_t HAL_GetUIDw0(void);
uint32_t HAL_GetUIDw1(void);
uint32_t HAL_GetUIDw2(void);


void HAL_EnableMemorySwappingBank(void);
void HAL_DisableMemorySwappingBank(void);



 



 
 
 


 


 
 


 


 
 
 


 



  
  






 
#line 32 "../Inc/main.h"

 
 

 

 
 

 

 
 

 

 
 

 

 
void Error_Handler(void);

 
typedef float fp32;
typedef double fp64;
 

 
#line 98 "../Inc/main.h"
 
#line 106 "../Inc/main.h"

void SystemClock_Config(void);
 







 
#line 2 "../Src/main.c"
#line 1 "..\\TASK\\bsp_init.h"



#line 5 "..\\TASK\\bsp_init.h"
#line 6 "..\\TASK\\bsp_init.h"
#line 1 "../Inc/can.h"

















 
 






 
#line 28 "../Inc/can.h"

 

 

extern CAN_HandleTypeDef hcan1;

 

 

void MX_CAN1_Init(void);

 

 








 



 

 
#line 7 "..\\TASK\\bsp_init.h"
#line 1 "../Inc/dma.h"

















 
 







 
#line 29 "../Inc/dma.h"

 

 

 

 

 

void MX_DMA_Init(void);

 

 









 

 
#line 8 "..\\TASK\\bsp_init.h"
#line 1 "../Inc/tim.h"

















 
 






 
#line 28 "../Inc/tim.h"

 

 

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim7;
extern TIM_HandleTypeDef htim12;

 

 

void MX_TIM1_Init(void);
void MX_TIM2_Init(void);
void MX_TIM7_Init(void);
void MX_TIM12_Init(void);
                        
void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);
                                        
 

 








 



 

 
#line 9 "..\\TASK\\bsp_init.h"
#line 1 "../Inc/usart.h"

















 
 






 
#line 28 "../Inc/usart.h"

 
 

extern UART_HandleTypeDef huart8;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart6;

 
HAL_StatusTypeDef UART_Receive_DMA_NoIT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_Receive_IT_IDLE(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
void HAL_UART_IDLE_IRQHandler(UART_HandleTypeDef *huart);
 

void MX_UART8_Init(void);
void MX_USART1_UART_Init(void);
void MX_USART6_UART_Init(void);

 
extern uint8_t UART_Buffer[100];
 








 



 

 
#line 10 "..\\TASK\\bsp_init.h"
#line 1 "../Inc/usb_device.h"
 

















 
 

 







 
#line 32 "../Inc/usb_device.h"
#line 33 "../Inc/usb_device.h"
#line 1 "../Middlewares/ST/STM32_USB_Device_Library/Core/Inc/usbd_def.h"

















 

 







 
#line 1 "../Inc/usbd_conf.h"
 

















 
 

 







 
#line 1 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"
 
 
 





 






 







 




  
 








#line 47 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"


  



    typedef unsigned int size_t;    









 
 

 



    typedef struct __va_list __va_list;






   




 




typedef struct __fpos_t_struct {
    unsigned __int64 __pos;
    



 
    struct {
        unsigned int __state1, __state2;
    } __mbstate;
} fpos_t;
   


 


   

 

typedef struct __FILE FILE;
   






 

#line 136 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"


extern FILE __stdin, __stdout, __stderr;
extern FILE *__aeabi_stdin, *__aeabi_stdout, *__aeabi_stderr;

#line 166 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"
    

    

    





     



   


 


   


 

   



 

   


 




   


 





    


 






extern __declspec(__nothrow) int remove(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int rename(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) FILE *tmpfile(void);
   




 
extern __declspec(__nothrow) char *tmpnam(char *  );
   











 

extern __declspec(__nothrow) int fclose(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) int fflush(FILE *  );
   







 
extern __declspec(__nothrow) FILE *fopen(const char * __restrict  ,
                           const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   








































 
extern __declspec(__nothrow) FILE *freopen(const char * __restrict  ,
                    const char * __restrict  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(2,3)));
   








 
extern __declspec(__nothrow) void setbuf(FILE * __restrict  ,
                    char * __restrict  ) __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) int setvbuf(FILE * __restrict  ,
                   char * __restrict  ,
                   int  , size_t  ) __attribute__((__nonnull__(1)));
   















 
#pragma __printf_args
extern __declspec(__nothrow) int fprintf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   


















 
#pragma __printf_args
extern __declspec(__nothrow) int _fprintf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   




 
#pragma __printf_args
extern __declspec(__nothrow) int _printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






 
#pragma __printf_args
extern __declspec(__nothrow) int _sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

#pragma __printf_args
extern __declspec(__nothrow) int snprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   















 

#pragma __printf_args
extern __declspec(__nothrow) int _snprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int fscanf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






























 
#pragma __scanf_args
extern __declspec(__nothrow) int _fscanf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   






 
#pragma __scanf_args
extern __declspec(__nothrow) int _scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int sscanf(const char * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   








 
#pragma __scanf_args
extern __declspec(__nothrow) int _sscanf(const char * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

 
extern __declspec(__nothrow) int vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int _vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int _vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int _vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int _vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int vfprintf(FILE * __restrict  ,
                    const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int vsprintf(char * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 

extern __declspec(__nothrow) int vsnprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   







 

extern __declspec(__nothrow) int _vsprintf(char * __restrict  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vfprintf(FILE * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vsnprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   



 
extern __declspec(__nothrow) int fgetc(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) char *fgets(char * __restrict  , int  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   










 
extern __declspec(__nothrow) int fputc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   







 
extern __declspec(__nothrow) int fputs(const char * __restrict  , FILE * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int getc(FILE *  ) __attribute__((__nonnull__(1)));
   







 




    extern __declspec(__nothrow) int (getchar)(void);

   





 
extern __declspec(__nothrow) char *gets(char *  ) __attribute__((__nonnull__(1)));
   









 
extern __declspec(__nothrow) int putc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   





 




    extern __declspec(__nothrow) int (putchar)(int  );

   



 
extern __declspec(__nothrow) int puts(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int ungetc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   






















 

extern __declspec(__nothrow) size_t fread(void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   











 

extern __declspec(__nothrow) size_t __fread_bytes_avail(void * __restrict  ,
                    size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   











 

extern __declspec(__nothrow) size_t fwrite(const void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   







 

extern __declspec(__nothrow) int fgetpos(FILE * __restrict  , fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) int fseek(FILE *  , long int  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) int fsetpos(FILE * __restrict  , const fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   










 
extern __declspec(__nothrow) long int ftell(FILE *  ) __attribute__((__nonnull__(1)));
   











 
extern __declspec(__nothrow) void rewind(FILE *  ) __attribute__((__nonnull__(1)));
   





 

extern __declspec(__nothrow) void clearerr(FILE *  ) __attribute__((__nonnull__(1)));
   




 

extern __declspec(__nothrow) int feof(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) int ferror(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) void perror(const char *  );
   









 

extern __declspec(__nothrow) int _fisatty(FILE *   ) __attribute__((__nonnull__(1)));
    
 

extern __declspec(__nothrow) void __use_no_semihosting_swi(void);
extern __declspec(__nothrow) void __use_no_semihosting(void);
    





 











#line 985 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"



 

#line 32 "../Inc/usbd_conf.h"
#line 1 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"
 
 
 




 
 



 






   














  


 








#line 54 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"


  



    typedef unsigned int size_t;    
#line 70 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"






    



    typedef unsigned short wchar_t;  
#line 91 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"

typedef struct div_t { int quot, rem; } div_t;
    
typedef struct ldiv_t { long int quot, rem; } ldiv_t;
    

typedef struct lldiv_t { long long quot, rem; } lldiv_t;
    


#line 112 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"
   



 

   




 
#line 131 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"
   


 
extern __declspec(__nothrow) int __aeabi_MB_CUR_MAX(void);

   




 

   




 




extern __declspec(__nothrow) double atof(const char *  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int atoi(const char *  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) long int atol(const char *  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) long long atoll(const char *  ) __attribute__((__nonnull__(1)));
   



 


extern __declspec(__nothrow) double strtod(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
   

















 

extern __declspec(__nothrow) float strtof(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) long double strtold(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
   

 

extern __declspec(__nothrow) long int strtol(const char * __restrict  ,
                        char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   



























 
extern __declspec(__nothrow) unsigned long int strtoul(const char * __restrict  ,
                                       char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   


























 

 
extern __declspec(__nothrow) long long strtoll(const char * __restrict  ,
                                  char ** __restrict  , int  )
                          __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) unsigned long long strtoull(const char * __restrict  ,
                                            char ** __restrict  , int  )
                                   __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) int rand(void);
   







 
extern __declspec(__nothrow) void srand(unsigned int  );
   






 

struct _rand_state { int __x[57]; };
extern __declspec(__nothrow) int _rand_r(struct _rand_state *);
extern __declspec(__nothrow) void _srand_r(struct _rand_state *, unsigned int);
struct _ANSI_rand_state { int __x[1]; };
extern __declspec(__nothrow) int _ANSI_rand_r(struct _ANSI_rand_state *);
extern __declspec(__nothrow) void _ANSI_srand_r(struct _ANSI_rand_state *, unsigned int);
   


 

extern __declspec(__nothrow) void *calloc(size_t  , size_t  );
   



 
extern __declspec(__nothrow) void free(void *  );
   





 
extern __declspec(__nothrow) void *malloc(size_t  );
   



 
extern __declspec(__nothrow) void *realloc(void *  , size_t  );
   













 

extern __declspec(__nothrow) int posix_memalign(void **  , size_t  , size_t  );
   









 

typedef int (*__heapprt)(void *, char const *, ...);
extern __declspec(__nothrow) void __heapstats(int (*  )(void *  ,
                                           char const *  , ...),
                        void *  ) __attribute__((__nonnull__(1)));
   










 
extern __declspec(__nothrow) int __heapvalid(int (*  )(void *  ,
                                           char const *  , ...),
                       void *  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) __declspec(__noreturn) void abort(void);
   







 

extern __declspec(__nothrow) int atexit(void (*  )(void)) __attribute__((__nonnull__(1)));
   




 
#line 436 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"


extern __declspec(__nothrow) __declspec(__noreturn) void exit(int  );
   












 

extern __declspec(__nothrow) __declspec(__noreturn) void _Exit(int  );
   







      

extern __declspec(__nothrow) char *getenv(const char *  ) __attribute__((__nonnull__(1)));
   









 

extern __declspec(__nothrow) int  system(const char *  );
   









 

extern  void *bsearch(const void *  , const void *  ,
              size_t  , size_t  ,
              int (*  )(const void *, const void *)) __attribute__((__nonnull__(1,2,5)));
   












 
#line 524 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"


extern  void qsort(void *  , size_t  , size_t  ,
           int (*  )(const void *, const void *)) __attribute__((__nonnull__(1,4)));
   









 

#line 553 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"

extern __declspec(__nothrow) __attribute__((const)) int abs(int  );
   



 

extern __declspec(__nothrow) __attribute__((const)) div_t div(int  , int  );
   









 
extern __declspec(__nothrow) __attribute__((const)) long int labs(long int  );
   



 




extern __declspec(__nothrow) __attribute__((const)) ldiv_t ldiv(long int  , long int  );
   











 







extern __declspec(__nothrow) __attribute__((const)) long long llabs(long long  );
   



 




extern __declspec(__nothrow) __attribute__((const)) lldiv_t lldiv(long long  , long long  );
   











 
#line 634 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"




 
typedef struct __sdiv32by16 { int quot, rem; } __sdiv32by16;
typedef struct __udiv32by16 { unsigned int quot, rem; } __udiv32by16;
    
typedef struct __sdiv64by32 { int rem, quot; } __sdiv64by32;

__value_in_regs extern __declspec(__nothrow) __attribute__((const)) __sdiv32by16 __rt_sdiv32by16(
     int  ,
     short int  );
   

 
__value_in_regs extern __declspec(__nothrow) __attribute__((const)) __udiv32by16 __rt_udiv32by16(
     unsigned int  ,
     unsigned short  );
   

 
__value_in_regs extern __declspec(__nothrow) __attribute__((const)) __sdiv64by32 __rt_sdiv64by32(
     int  , unsigned int  ,
     int  );
   

 




 
extern __declspec(__nothrow) unsigned int __fp_status(unsigned int  , unsigned int  );
   







 























 
extern __declspec(__nothrow) int mblen(const char *  , size_t  );
   












 
extern __declspec(__nothrow) int mbtowc(wchar_t * __restrict  ,
                   const char * __restrict  , size_t  );
   















 
extern __declspec(__nothrow) int wctomb(char *  , wchar_t  );
   













 





 
extern __declspec(__nothrow) size_t mbstowcs(wchar_t * __restrict  ,
                      const char * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   














 
extern __declspec(__nothrow) size_t wcstombs(char * __restrict  ,
                      const wchar_t * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   














 

extern __declspec(__nothrow) void __use_realtime_heap(void);
extern __declspec(__nothrow) void __use_realtime_division(void);
extern __declspec(__nothrow) void __use_two_region_memory(void);
extern __declspec(__nothrow) void __use_no_heap(void);
extern __declspec(__nothrow) void __use_no_heap_region(void);

extern __declspec(__nothrow) char const *__C_library_version_string(void);
extern __declspec(__nothrow) int __C_library_version_number(void);











#line 892 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"





 
#line 33 "../Inc/usbd_conf.h"
#line 1 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
 
 
 
 




 








 












#line 38 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\string.h"


  



    typedef unsigned int size_t;    
#line 54 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\string.h"




extern __declspec(__nothrow) void *memcpy(void * __restrict  ,
                    const void * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) void *memmove(void *  ,
                    const void *  , size_t  ) __attribute__((__nonnull__(1,2)));
   







 
extern __declspec(__nothrow) char *strcpy(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) char *strncpy(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   





 

extern __declspec(__nothrow) char *strcat(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) char *strncat(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 






 

extern __declspec(__nothrow) int memcmp(const void *  , const void *  , size_t  ) __attribute__((__nonnull__(1,2)));
   





 
extern __declspec(__nothrow) int strcmp(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int strncmp(const char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int strcasecmp(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   





 
extern __declspec(__nothrow) int strncasecmp(const char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int strcoll(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   







 

extern __declspec(__nothrow) size_t strxfrm(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   













 


#line 193 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) void *memchr(const void *  , int  , size_t  ) __attribute__((__nonnull__(1)));

   





 

#line 209 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strchr(const char *  , int  ) __attribute__((__nonnull__(1)));

   




 

extern __declspec(__nothrow) size_t strcspn(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   




 

#line 232 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strpbrk(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));

   




 

#line 247 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strrchr(const char *  , int  ) __attribute__((__nonnull__(1)));

   





 

extern __declspec(__nothrow) size_t strspn(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   



 

#line 270 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strstr(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));

   





 

extern __declspec(__nothrow) char *strtok(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) char *_strtok_r(char *  , const char *  , char **  ) __attribute__((__nonnull__(2,3)));

extern __declspec(__nothrow) char *strtok_r(char *  , const char *  , char **  ) __attribute__((__nonnull__(2,3)));

   

































 

extern __declspec(__nothrow) void *memset(void *  , int  , size_t  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) char *strerror(int  );
   





 
extern __declspec(__nothrow) size_t strlen(const char *  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) size_t strlcpy(char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   
















 

extern __declspec(__nothrow) size_t strlcat(char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






















 

extern __declspec(__nothrow) void _membitcpybl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpybb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpyhl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpyhb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpywl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpywb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovebl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovebb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovehl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovehb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovewl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovewb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
    














































 







#line 502 "D:\\MDK\\ARM\\ARMCC\\Bin\\..\\include\\string.h"



 

#line 34 "../Inc/usbd_conf.h"
#line 35 "../Inc/usbd_conf.h"
#line 36 "../Inc/usbd_conf.h"
#line 37 "../Inc/usbd_conf.h"

 

 




 




 




 



 




 

 

 

 

 

 

 

 


 
 





 




 

 

 


 


 


 


 


 

#line 120 "../Inc/usbd_conf.h"

#line 129 "../Inc/usbd_conf.h"

#line 137 "../Inc/usbd_conf.h"



 




 



 




 

 



 



 



 







 
#line 30 "../Middlewares/ST/STM32_USB_Device_Library/Core/Inc/usbd_def.h"



 




 



 

























#line 76 "../Middlewares/ST/STM32_USB_Device_Library/Core/Inc/usbd_def.h"

#line 83 "../Middlewares/ST/STM32_USB_Device_Library/Core/Inc/usbd_def.h"











#line 105 "../Middlewares/ST/STM32_USB_Device_Library/Core/Inc/usbd_def.h"

#line 114 "../Middlewares/ST/STM32_USB_Device_Library/Core/Inc/usbd_def.h"














 






 
#line 143 "../Middlewares/ST/STM32_USB_Device_Library/Core/Inc/usbd_def.h"









 




 

typedef  struct  usb_setup_req
{

    uint8_t   bmRequest;
    uint8_t   bRequest;
    uint16_t  wValue;
    uint16_t  wIndex;
    uint16_t  wLength;
}USBD_SetupReqTypedef;

struct _USBD_HandleTypeDef;

typedef struct _Device_cb
{
  uint8_t  (*Init)             (struct _USBD_HandleTypeDef *pdev , uint8_t cfgidx);
  uint8_t  (*DeInit)           (struct _USBD_HandleTypeDef *pdev , uint8_t cfgidx);
  
  uint8_t  (*Setup)            (struct _USBD_HandleTypeDef *pdev , USBD_SetupReqTypedef  *req);
  uint8_t  (*EP0_TxSent)       (struct _USBD_HandleTypeDef *pdev );
  uint8_t  (*EP0_RxReady)      (struct _USBD_HandleTypeDef *pdev );
   
  uint8_t  (*DataIn)           (struct _USBD_HandleTypeDef *pdev , uint8_t epnum);
  uint8_t  (*DataOut)          (struct _USBD_HandleTypeDef *pdev , uint8_t epnum);
  uint8_t  (*SOF)              (struct _USBD_HandleTypeDef *pdev);
  uint8_t  (*IsoINIncomplete)  (struct _USBD_HandleTypeDef *pdev , uint8_t epnum);
  uint8_t  (*IsoOUTIncomplete) (struct _USBD_HandleTypeDef *pdev , uint8_t epnum);

  uint8_t  *(*GetHSConfigDescriptor)(uint16_t *length);
  uint8_t  *(*GetFSConfigDescriptor)(uint16_t *length);
  uint8_t  *(*GetOtherSpeedConfigDescriptor)(uint16_t *length);
  uint8_t  *(*GetDeviceQualifierDescriptor)(uint16_t *length);




} USBD_ClassTypeDef;

 
typedef enum
{
  USBD_SPEED_HIGH  = 0U,
  USBD_SPEED_FULL  = 1U,
  USBD_SPEED_LOW   = 2U,
}USBD_SpeedTypeDef;

 
typedef enum {
  USBD_OK   = 0U,
  USBD_BUSY,
  USBD_FAIL,
}USBD_StatusTypeDef;

 
typedef struct
{
  uint8_t  *(*GetDeviceDescriptor)( USBD_SpeedTypeDef speed , uint16_t *length);
  uint8_t  *(*GetLangIDStrDescriptor)( USBD_SpeedTypeDef speed , uint16_t *length);
  uint8_t  *(*GetManufacturerStrDescriptor)( USBD_SpeedTypeDef speed , uint16_t *length);
  uint8_t  *(*GetProductStrDescriptor)( USBD_SpeedTypeDef speed , uint16_t *length);
  uint8_t  *(*GetSerialStrDescriptor)( USBD_SpeedTypeDef speed , uint16_t *length);
  uint8_t  *(*GetConfigurationStrDescriptor)( USBD_SpeedTypeDef speed , uint16_t *length);
  uint8_t  *(*GetInterfaceStrDescriptor)( USBD_SpeedTypeDef speed , uint16_t *length);



} USBD_DescriptorsTypeDef;

 
typedef struct
{
  uint32_t                status;
  uint32_t                is_used;
  uint32_t                total_length;
  uint32_t                rem_length;
  uint32_t                maxpacket;
} USBD_EndpointTypeDef;

 
typedef struct _USBD_HandleTypeDef
{
  uint8_t                 id;
  uint32_t                dev_config;
  uint32_t                dev_default_config;
  uint32_t                dev_config_status;
  USBD_SpeedTypeDef       dev_speed;
  USBD_EndpointTypeDef    ep_in[15];
  USBD_EndpointTypeDef    ep_out[15];
  uint32_t                ep0_state;
  uint32_t                ep0_data_len;
  uint8_t                 dev_state;
  uint8_t                 dev_old_state;
  uint8_t                 dev_address;
  uint8_t                 dev_connection_status;
  uint8_t                 dev_test_mode;
  uint32_t                dev_remote_wakeup;

  USBD_SetupReqTypedef    request;
  USBD_DescriptorsTypeDef *pDesc;
  USBD_ClassTypeDef       *pClass;
  void                    *pClassData;
  void                    *pUserData;
  void                    *pData;
} USBD_HandleTypeDef;



 





 









#line 289 "../Middlewares/ST/STM32_USB_Device_Library/Core/Inc/usbd_def.h"



 

#line 307 "../Middlewares/ST/STM32_USB_Device_Library/Core/Inc/usbd_def.h"




 



 



 



 



 









 



 
 
#line 34 "../Inc/usb_device.h"

 

 



 




 




 

 
 

 

 
 

 



 
 

 


 




 

 
void MX_USB_DEVICE_Init(void);



 
 

 


 



 



 







 
#line 11 "..\\TASK\\bsp_init.h"
#line 1 "../Inc/gpio.h"

















 

 






 
#line 29 "../Inc/gpio.h"

 

 

 

 

void MX_GPIO_Init(void);

 

 








 



 

 
#line 12 "..\\TASK\\bsp_init.h"
#line 1 "../Inc/myiic.h"



#line 5 "../Inc/myiic.h"

							  





#line 23 "../Inc/myiic.h"

#line 35 "../Inc/myiic.h"













































void IIC_Init(void);                
void IIC_Start(void);				
void IIC_Stop(void);	  			
void IIC_Send_Byte(uint8_t txd);			
uint8_t IIC_Read_Byte(unsigned char ack);
uint8_t IIC_Wait_Ack(void); 				
void IIC_Ack(void);					
void IIC_NAck(void);				

void IIC_Write_One_Byte(uint8_t daddr,uint8_t addr,uint8_t data);
uint8_t IIC_Read_One_Byte(uint8_t daddr,uint8_t addr);	 


#line 13 "..\\TASK\\bsp_init.h"

void param_init(void);
void system_init(void);
void hardware_init(void);
extern void SELFCHECK_param_init(void);


#line 3 "../Src/main.c"
#line 1 "..\\bsp\\bsp_headfile.h"



#line 1 "..\\bsp\\bsp_can.h"















 




#line 22 "..\\bsp\\bsp_can.h"












typedef struct
{
    uint16_t can_id;
    int16_t  set_voltage;
    uint16_t rotor_angle;
    int16_t  rotor_speed;
    int16_t  torque_current;
    uint8_t  temp;
}moto_info_t;

extern moto_info_t motor_info[4];

void can_user_init(CAN_HandleTypeDef* hcan);
void set_motor_voltage(uint8_t id_range, int16_t v1, int16_t v2, int16_t v3, int16_t v4);

void set_yuntaimotor_voltage(int16_t v1, int16_t v2,int16_t v3);
void set_bodanmotor_voltage(int16_t v1);
void set_chassismotor_voltage(int16_t v1, int16_t v2);
#line 5 "..\\bsp\\bsp_headfile.h"
#line 1 "..\\bsp\\led.h"



#line 5 "..\\bsp\\led.h"
#line 6 "..\\bsp\\led.h"

void greenled_ctrl_on(uint16_t GPIO_Pin);
void greenled_ctrl_off(uint16_t GPIO_Pin);

void single_green_off(void);
void single_green_on(void);
void single_red_off(void);
void single_red_on(void);

#line 6 "..\\bsp\\bsp_headfile.h"
#line 1 "..\\bsp\\power_ctrl.h"
#line 4 "..\\bsp\\power_ctrl.h"
#line 5 "..\\bsp\\power_ctrl.h"






extern void power_ctrl_onall(void);
extern void power_ctrl_offall(void);
extern void power_ctrl_on(uint8_t num);
extern void power_ctrl_off(uint8_t num);

#line 7 "..\\bsp\\bsp_headfile.h"
#line 1 "..\\bsp\\fric.h"
#line 4 "..\\bsp\\fric.h"
#line 5 "..\\bsp\\fric.h"




extern void fric_PWM_configuration(void);
void PWM_SetDuty(TIM_HandleTypeDef *tim,uint32_t tim_channel,float duty);
extern void fric_off(void);
extern void fric1_on(uint32_t cmd1);
extern void fric2_on(uint32_t cmd2);
#line 8 "..\\bsp\\bsp_headfile.h"
#line 1 "..\\bsp\\buzzer.h"
#line 4 "..\\bsp\\buzzer.h"
#line 5 "..\\bsp\\buzzer.h"

extern void buzzer_on(uint16_t psc, uint16_t pwm);
extern void buzzer_off(void);

#line 9 "..\\bsp\\bsp_headfile.h"
#line 1 "..\\bsp\\laser.h"



#line 5 "..\\bsp\\laser.h"

extern void laser_on(void);
extern void laser_off(void);

#line 10 "..\\bsp\\bsp_headfile.h"
#line 1 "..\\bsp\\user_lib.h"
#line 4 "..\\bsp\\user_lib.h"




typedef __packed struct
{
    fp32 input;        
    fp32 out;          
    fp32 min_value;    
    fp32 max_value;    
    fp32 frame_period; 
} ramp_function_source_t;

typedef __packed struct
{
    fp32 input;        
    fp32 out;          
    fp32 num[1];       
    fp32 frame_period; 
} first_order_filter_type_t;


extern fp32 invSqrt(fp32 num);


void ramp_init(ramp_function_source_t *ramp_source_type, fp32 frame_period, fp32 max, fp32 min);


void ramp_calc(ramp_function_source_t *ramp_source_type, fp32 input);

extern void first_order_filter_init(first_order_filter_type_t *first_order_filter_type, fp32 frame_period, const fp32 num[1]);

extern void first_order_filter_cali(first_order_filter_type_t *first_order_filter_type, fp32 input);

extern void abs_limit(fp32 *num, fp32 Limit);

extern fp32 sign(fp32 value);

extern fp32 fp32_deadline(fp32 Value, fp32 minValue, fp32 maxValue);

extern int16_t int16_deadline(int16_t Value, int16_t minValue, int16_t maxValue);

extern fp32 fp32_constrain(fp32 Value, fp32 minValue, fp32 maxValue);

extern int16_t int16_constrain(int16_t Value, int16_t minValue, int16_t maxValue);

extern fp32 loop_fp32_constrain(fp32 Input, fp32 minValue, fp32 maxValue);

extern fp32 theta_format(fp32 Ang);





extern ramp_function_source_t fric_pwm;
#line 11 "..\\bsp\\bsp_headfile.h"
#line 1 "..\\bsp\\scope.h"



#line 5 "..\\bsp\\scope.h"
#line 6 "..\\bsp\\scope.h"


extern float Variable[16];
extern void my_putchar(uint8_t temp);
extern void my_putchar_usb(uint8_t temp);
extern void Send_Begin(void);
extern void Send_Variable(void);

extern short wave_form_data[6];
extern void shanwai_send_wave_form(void);

#line 12 "..\\bsp\\bsp_headfile.h"
#line 1 "..\\bsp\\Remote_Control.h"











 
	


 
#line 18 "..\\bsp\\Remote_Control.h"
#line 19 "..\\bsp\\Remote_Control.h"

typedef struct {
	int16_t ch1;	
	int16_t ch2;
	int16_t ch3;
	int16_t ch4;
	
	uint8_t switch_left;	
	uint8_t switch_right;
	
	struct {
		int16_t x;
		int16_t y;
		int16_t z;
	
		uint8_t press_left;
		uint8_t press_right;
	}mouse;
	
	struct {
		uint16_t key_code;



 

	}keyBoard;
	

}RC_Type;



enum{
	Switch_Up = 1,
	Switch_Middle = 3,
	Switch_Down = 2,
};

enum{
	Key_W,
	Key_S,
	
};





extern uint32_t  Latest_Remote_Control_Pack_Time ;
void uart_receive_handler(UART_HandleTypeDef *huart);
void dbus_uart_init(void);
extern RC_Type remote_control;




#line 13 "..\\bsp\\bsp_headfile.h"
#line 1 "..\\bsp\\pid.h"



#line 5 "..\\bsp\\pid.h"

enum{
    LLAST	= 0,
    LAST 	= 1,
    NOW 	= 2,
    
    POSITION_PID,
    DELTA_PID,
};

typedef struct __pid_t
{
    float p;
    float i;
    float d;
    
    float set[3];				
    float get[3];				
    float err[3];				
	
    
    float pout;							
    float iout;							
    float dout;							
    
    float pos_out;						
    float last_pos_out;				
    float delta_u;						
    float delta_out;					
    float last_delta_out;
    
	  float max_err;
	  float deadband;				
    uint32_t pid_mode;
    uint32_t MaxOutput;				
    uint32_t IntegralLimit;		
    
    void (*f_param_init)(struct __pid_t *pid,  
													uint32_t pid_mode,
													uint32_t maxOutput,
													uint32_t integralLimit,
													float p,
													float i,
													float d);
													
    void (*f_pid_reset)(struct __pid_t *pid, float p, float i, float d);		

}pid_t;

void PID_struct_init(
											pid_t* pid,
											uint32_t mode,
											uint32_t maxout,
											uint32_t intergral_limit,
											
											float 	kp, 
											float 	ki, 
											float 	kd);
    
float pid_calc(pid_t* pid, float fdb, float ref);
		

		
extern pid_t pid_yuntai_pitch;
extern pid_t pid_yuntai_yaw;
extern pid_t pid_moto_bodan;
extern pid_t pid_yuntai_pitch_speed;
extern pid_t pid_yuntai_yaw_speed;
											
extern pid_t check_pitch;
extern pid_t check_yaw;
extern pid_t check_bodan;

extern pid_t pid_moto1_move;
extern pid_t pid_moto2_move;											
											
extern void PID_struct_init(
														pid_t* pid,
														uint32_t mode,
														uint32_t maxout,
														uint32_t intergral_limit,
														
														float 	kp, 
														float 	ki, 
														float 	kd);


 
														
#line 14 "..\\bsp\\bsp_headfile.h"
#line 1 "..\\bsp\\timdelay.h"



#line 5 "..\\bsp\\timdelay.h"

void TIM7_Delay_Init(void);
void TIM7_Delay_Us(uint16_t us);
void TIM_Delay_ms(uint16_t nms);

#line 15 "..\\bsp\\bsp_headfile.h"
#line 1 "..\\bsp\\exti.h"
#line 4 "..\\bsp\\exti.h"


void EXTI_Init(void);
#line 16 "..\\bsp\\bsp_headfile.h"
#line 1 "..\\MPU6050\\mpu6050.h"



#line 5 "..\\MPU6050\\mpu6050.h"
  												  	  















#line 49 "..\\MPU6050\\mpu6050.h"






#line 61 "..\\MPU6050\\mpu6050.h"




#line 71 "..\\MPU6050\\mpu6050.h"






#line 87 "..\\MPU6050\\mpu6050.h"
 









uint8_t MPU_Init(void); 								
uint8_t MPU_Write_Len(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf);
uint8_t MPU_Read_Len(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf); 
uint8_t MPU_Write_Byte(uint8_t reg,uint8_t data);				
uint8_t MPU_Read_Byte(uint8_t reg);						

uint8_t MPU_Set_Gyro_Fsr(uint8_t fsr);
uint8_t MPU_Set_Accel_Fsr(uint8_t fsr);
uint8_t MPU_Set_LPF(uint16_t lpf);
uint8_t MPU_Set_Rate(uint16_t rate);
uint8_t MPU_Set_Fifo(uint8_t sens);


short MPU_Get_Temperature(void);
uint8_t MPU_Get_Gyroscope(short *gx,short *gy,short *gz);
uint8_t MPU_Get_Accelerometer(short *ax,short *ay,short *az);
uint8_t MPU_Init(void);




#line 17 "..\\bsp\\bsp_headfile.h"
#line 1 "..\\MPU6050\\mpu_dmp_useapi.h"



#line 5 "..\\MPU6050\\mpu_dmp_useapi.h"



extern short gyro_mpu[3], accel_mpu[3];			
extern float pit,rol,yaw;				

void gyro_data_ready_cb(void);
void SetReportFlag(uint8_t rawDataReportCmd,uint8_t quatDataReportCmd);

uint8_t mpu_dmp_init(void);
uint8_t dmp_getdata(void);

#line 18 "..\\bsp\\bsp_headfile.h"
#line 1 "..\\MPU6050\\dmp_exti.h"
#line 4 "..\\MPU6050\\dmp_exti.h"

void DMP_EXTIConfig(void);

#line 19 "..\\bsp\\bsp_headfile.h"

#line 4 "../Src/main.c"
#line 1 "..\\TASK\\gimbal_task.h"



#line 5 "..\\TASK\\gimbal_task.h"

typedef struct
{
    int input_angle;  
   	int exp_angle;    
    int out;          
    int min_angle;    
    int max_angle;    
    int add;          
} gimbal_checktask;




extern gimbal_checktask GIMBALCHECK;
extern int16_t mpuspeed_pit,mpuspeed_yaw,mpu_pit,mpu_yaw;	

extern void Get_Anglespeed(void);
extern void control_fricon (void);

extern void gimablcheck_init(gimbal_checktask *gimbal_check_type, int add, int max, int min);
extern void gimablcheck_calc(gimbal_checktask *gimbal_check_type, int input_angle, int exp_angle);

extern void offline_control(void);
extern void manual_control(void);
extern void MPU6050_control(void);
extern void moto_control(void);

#line 5 "../Src/main.c"
#line 1 "..\\bsp\\Robomaster_Control.h"
#line 37 "..\\bsp\\Robomaster_Control.h"
 
#line 45 "..\\bsp\\Robomaster_Control.h"



void task(void);
#line 6 "../Src/main.c"

extern RC_Type remote_control;
extern int cnt1;
uint16_t SYSTEM_STATION=0;
uint16_t count_1 = 0; 

int main(void)
{
	
  system_init(); 
	
	
	hardware_init();
  HAL_TIM_Base_Start_IT(&htim2);
  while (1)
  {
		count_1++;







		





	  Variable[0]=pit;        
	  Variable[1]=yaw;      
    Variable[2]=mpuspeed_pit;	    		
		Variable[3]=mpuspeed_yaw;	
		Variable[4]=gyro_mpu[2];
		Variable[5]=accel_mpu[0];
		Variable[6]=remote_control.ch1;
		Variable[7]=pid_yuntai_yaw_speed.pos_out;
		HAL_Delay(10);
		  Send_Begin();
      Send_Variable();


	
	
	
		
		 




			
			 

















			
			
			if (count_1==500)
			{HAL_GPIO_TogglePin(((GPIO_TypeDef *) ((0x40000000UL + 0x00020000UL) + 0x1000UL)), ((uint16_t)0x0800));
				count_1=0;}
			
	
  }
}












 
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  
 
  do { volatile uint32_t tmpreg = 0x00U; ((((RCC_TypeDef *) ((0x40000000UL + 0x00020000UL) + 0x3800UL))->APB1ENR) |= ((0x1UL << (28U)))); tmpreg = ((((RCC_TypeDef *) ((0x40000000UL + 0x00020000UL) + 0x3800UL))->APB1ENR) & ((0x1UL << (28U)))); (void)tmpreg; } while(0U);
  do { volatile uint32_t tmpreg = 0x00U; (((((PWR_TypeDef *) (0x40000000UL + 0x7000UL))->CR)) = ((((((((PWR_TypeDef *) (0x40000000UL + 0x7000UL))->CR))) & (~((0x3UL << (14U))))) | (((0x3UL << (14U))))))); tmpreg = ((((PWR_TypeDef *) (0x40000000UL + 0x7000UL))->CR) & ((0x3UL << (14U)))); (void)tmpreg; } while(0U);
  
 
  RCC_OscInitStruct.OscillatorType = 0x00000001U;
  RCC_OscInitStruct.HSEState = (0x1UL << (16U));
  RCC_OscInitStruct.PLL.PLLState = ((uint8_t)0x02);
  RCC_OscInitStruct.PLL.PLLSource = (0x1UL << (22U));
  RCC_OscInitStruct.PLL.PLLM = 6;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = 0x00000002U;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  
 
  RCC_ClkInitStruct.ClockType = 0x00000002U|0x00000001U
                              |0x00000004U|0x00000008U;
  RCC_ClkInitStruct.SYSCLKSource = 0x00000002U;
  RCC_ClkInitStruct.AHBCLKDivider = 0x00000000U;
  RCC_ClkInitStruct.APB1CLKDivider = 0x00001400U;
  RCC_ClkInitStruct.APB2CLKDivider = 0x00001000U;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, 0x00000005U) != HAL_OK)
  {
    Error_Handler();
  }
}

 

 




 
void Error_Handler(void)
{
   
   

   
}

#line 169 "../Src/main.c"

 
