#include <stdint.h>

#define SRAM_START	0x20000000U
#define SRAM_SIZE 	(128 * 1024)
#define SRAM_END	((SRAM_START) + (SRAM_SIZE))

#define STACK_START	SRAM_END

// Exceptions and interrupts handlers definitions
// The weak attribute allows for the user to redefine them
// The alias attribute sets all functions's addresses to the address of the Default Handler

void Reset_Handler();
void NMI_Handler() __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler() __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler() __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler() __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler() __attribute__((weak, alias("Default_Handler")));
void SVC_Handler() __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler() __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler() __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler() __attribute__((weak, alias("Default_Handler")));
void WWDG_IRQHandler() __attribute__((weak, alias("Default_Handler")));
void PVD_IRQHandler() __attribute__((weak, alias("Default_Handler")));              			
void TAMP_STAMP_IRQHandler() __attribute__((weak, alias("Default_Handler")));        			
void RTC_WKUP_IRQHandler() __attribute__((weak, alias("Default_Handler")));          			
void FLASH_IRQHandler() __attribute__((weak, alias("Default_Handler")));             			
void RCC_IRQHandler() __attribute__((weak, alias("Default_Handler")));               			
void EXTI0_IRQHandler() __attribute__((weak, alias("Default_Handler")));             			
void EXTI1_IRQHandler() __attribute__((weak, alias("Default_Handler")));             			
void EXTI2_IRQHandler() __attribute__((weak, alias("Default_Handler")));             			
void EXTI3_IRQHandler() __attribute__((weak, alias("Default_Handler")));             			
void EXTI4_IRQHandler() __attribute__((weak, alias("Default_Handler")));             			
void DMA1_Stream0_IRQHandler() __attribute__((weak, alias("Default_Handler")));      			
void DMA1_Stream1_IRQHandler() __attribute__((weak, alias("Default_Handler")));      			
void DMA1_Stream2_IRQHandler() __attribute__((weak, alias("Default_Handler")));	
void DMA1_Stream3_IRQHandler() __attribute__((weak, alias("Default_Handler")));      			
void DMA1_Stream4_IRQHandler() __attribute__((weak, alias("Default_Handler")));      			
void DMA1_Stream5_IRQHandler() __attribute__((weak, alias("Default_Handler")));      			
void DMA1_Stream6_IRQHandler() __attribute__((weak, alias("Default_Handler")));      			
void ADC_IRQHandler() __attribute__((weak, alias("Default_Handler")));               			                      			
void EXTI9_5_IRQHandler() __attribute__((weak, alias("Default_Handler")));           			
void TIM1_BRK_TIM9_IRQHandler() __attribute__((weak, alias("Default_Handler")));     			
void TIM1_UP_TIM10_IRQHandler() __attribute__((weak, alias("Default_Handler")));     			
void TIM1_TRG_COM_TIM11_IRQHandler() __attribute__((weak, alias("Default_Handler")));			
void TIM1_CC_IRQHandler() __attribute__((weak, alias("Default_Handler")));           			
void TIM2_IRQHandler() __attribute__((weak, alias("Default_Handler")));              			
void TIM3_IRQHandler() __attribute__((weak, alias("Default_Handler")));              			
void TIM4_IRQHandler() __attribute__((weak, alias("Default_Handler")));              			
void I2C1_EV_IRQHandler() __attribute__((weak, alias("Default_Handler")));           			
void I2C1_ER_IRQHandler() __attribute__((weak, alias("Default_Handler")));           			
void I2C2_EV_IRQHandler() __attribute__((weak, alias("Default_Handler")));           			
void I2C2_ER_IRQHandler() __attribute__((weak, alias("Default_Handler")));           			
void SPI1_IRQHandler() __attribute__((weak, alias("Default_Handler")));              			
void SPI2_IRQHandler() __attribute__((weak, alias("Default_Handler")));              			
void USART1_IRQHandler() __attribute__((weak, alias("Default_Handler")));            			
void USART2_IRQHandler() __attribute__((weak, alias("Default_Handler")));            			                           			
void EXTI15_10_IRQHandler() __attribute__((weak, alias("Default_Handler")));         			
void RTC_Alarm_IRQHandler() __attribute__((weak, alias("Default_Handler")));         			
void OTG_FS_WKUP_IRQHandler() __attribute__((weak, alias("Default_Handler")));       			                          			
void DMA1_Stream7_IRQHandler() __attribute__((weak, alias("Default_Handler")));      			                        			
void SDIO_IRQHandler() __attribute__((weak, alias("Default_Handler")));              			
void TIM5_IRQHandler() __attribute__((weak, alias("Default_Handler")));              			
void SPI3_IRQHandler() __attribute__((weak, alias("Default_Handler")));              			                          			
void DMA2_Stream0_IRQHandler() __attribute__((weak, alias("Default_Handler")));      			
void DMA2_Stream1_IRQHandler() __attribute__((weak, alias("Default_Handler")));      			
void DMA2_Stream2_IRQHandler() __attribute__((weak, alias("Default_Handler")));      			
void DMA2_Stream3_IRQHandler() __attribute__((weak, alias("Default_Handler")));      			
void DMA2_Stream4_IRQHandler() __attribute__((weak, alias("Default_Handler")));      			                            			
void OTG_FS_IRQHandler() __attribute__((weak, alias("Default_Handler")));            			
void DMA2_Stream5_IRQHandler() __attribute__((weak, alias("Default_Handler")));      			
void DMA2_Stream6_IRQHandler() __attribute__((weak, alias("Default_Handler")));      			
void DMA2_Stream7_IRQHandler() __attribute__((weak, alias("Default_Handler")));      			
void USART6_IRQHandler() __attribute__((weak, alias("Default_Handler")));            			
void I2C3_EV_IRQHandler() __attribute__((weak, alias("Default_Handler")));           			
void I2C3_ER_IRQHandler() __attribute__((weak, alias("Default_Handler")));           			                          			
void FPU_IRQHandler() __attribute__((weak, alias("Default_Handler")));               			                      	                         			
void SPI4_IRQHandler() __attribute__((weak, alias("Default_Handler")));              			
void SPI5_IRQHandler() __attribute__((weak, alias("Default_Handler"))); 

// Vector table is placed in a separate section called .isr_vector
// See controller datasheed for padding 
uint32_t vector[] __attribute__((section(".isr_vector"))) = {
	STACK_START,
	(uint32_t) Reset_Handler,
    (uint32_t) NMI_Handler,
    (uint32_t) HardFault_Handler,
    (uint32_t) MemManage_Handler,
    (uint32_t) BusFault_Handler,
    (uint32_t) UsageFault_Handler,
    0,
    0,
    0,
    0,
    (uint32_t) SVC_Handler,
    (uint32_t) DebugMon_Handler,
    0,
    (uint32_t) PendSV_Handler,
    (uint32_t) SysTick_Handler,
    (uint32_t) WWDG_IRQHandler,
    (uint32_t) PVD_IRQHandler,
    (uint32_t) TAMP_STAMP_IRQHandler,
    (uint32_t) RTC_WKUP_IRQHandler,
    (uint32_t) FLASH_IRQHandler,
    (uint32_t) RCC_IRQHandler,
    (uint32_t) EXTI0_IRQHandler,
    (uint32_t) EXTI1_IRQHandler,
    (uint32_t) EXTI2_IRQHandler,
    (uint32_t) EXTI3_IRQHandler,
    (uint32_t) EXTI4_IRQHandler,
    (uint32_t) DMA1_Stream0_IRQHandler,
    (uint32_t) DMA1_Stream1_IRQHandler,
    (uint32_t) DMA1_Stream2_IRQHandler,
    (uint32_t) DMA1_Stream3_IRQHandler,
    (uint32_t) DMA1_Stream4_IRQHandler,		
    (uint32_t) DMA1_Stream5_IRQHandler,
    (uint32_t) DMA1_Stream6_IRQHandler,
    (uint32_t) ADC_IRQHandler,
    0,
    0,
    0,
    0,
    (uint32_t) EXTI9_5_IRQHandler,
    (uint32_t) TIM1_BRK_TIM9_IRQHandler,
    (uint32_t) TIM1_UP_TIM10_IRQHandler,
    (uint32_t) TIM1_TRG_COM_TIM11_IRQHandler,
    (uint32_t) TIM1_CC_IRQHandler,
    (uint32_t) TIM2_IRQHandler,
    (uint32_t) TIM3_IRQHandler,
    (uint32_t) TIM4_IRQHandler,
    (uint32_t) I2C1_EV_IRQHandler,
    (uint32_t) I2C1_ER_IRQHandler,
    (uint32_t) I2C2_EV_IRQHandler,
    (uint32_t) I2C2_ER_IRQHandler,
    (uint32_t) SPI1_IRQHandler,
    (uint32_t) SPI2_IRQHandler,
    (uint32_t) USART1_IRQHandler,
    (uint32_t) USART2_IRQHandler,
    0,
    (uint32_t) EXTI15_10_IRQHandler,
    (uint32_t) RTC_Alarm_IRQHandler,
    (uint32_t) OTG_FS_WKUP_IRQHandler,
    0,
    0,
    0,
    0,
    (uint32_t) DMA1_Stream7_IRQHandler,
    0,
    (uint32_t) SDIO_IRQHandler,
    (uint32_t) TIM5_IRQHandler,
    (uint32_t) SPI3_IRQHandler,
    0,
    0,
    0,
    0,
    (uint32_t) DMA2_Stream0_IRQHandler,
    (uint32_t) DMA2_Stream1_IRQHandler,
    (uint32_t) DMA2_Stream2_IRQHandler,
    (uint32_t) DMA2_Stream3_IRQHandler,
    (uint32_t) DMA2_Stream4_IRQHandler,
    0,
    0,
    0,
    0,
    0,
    0,
    (uint32_t) OTG_FS_IRQHandler,
    (uint32_t) DMA2_Stream5_IRQHandler,
    (uint32_t) DMA2_Stream6_IRQHandler,
    (uint32_t) DMA2_Stream7_IRQHandler,
    (uint32_t) USART6_IRQHandler,
    (uint32_t) I2C3_EV_IRQHandler,
    (uint32_t) I2C3_ER_IRQHandler,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    (uint32_t) FPU_IRQHandler,
    0,
    0,
    (uint32_t) SPI4_IRQHandler,
    (uint32_t) SPI5_IRQHandler
};

/* The Reset handler is the first function which executes upon boot,
and initializes .data and .bss sections before calling main() */
void Reset_Handler()
{
	// copy .data to sram
	
	// intialize .bss to zero in SRAM
	
	// call init function of standard library, if used
	
	// call main
	
};

void Default_Handler()
{
	while(1);
};