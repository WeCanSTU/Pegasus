#include "config.h"
#include "delay.h"

#define LED_PIN  			4
#define BUTTON_PIN  		3

uint32_t count = 0;

void tim4_isr() __interrupt(TIM4_ISR)
{
    static uint16_t ctr = 0;
    if (++ctr >= 100) {
		count++;
        ctr = 0;
    }
    TIM4_SR &= ~(1 << TIM4_SR_UIF);
}

static void set_timer()
{
    TIM4_PSCR = 7;
    TIM4_ARR = 124;
    TIM4_IER |= (1 << TIM4_IER_UIE);
    TIM4_CR1 |= (1 << TIM4_CR1_CEN);
}

static void init_button()
{
    PD_DDR &= ~(1 << BUTTON_PIN);
    PD_CR1 |= (1 << BUTTON_PIN);	
}

void main(void)
{
	static uint8_t testBuffer[32] = {0};
	static uint8_t k = 0;
	disable_interrupts();
	for (uint16_t i = 0; i < sizeof(testBuffer); i++)
	{
		testBuffer[i] = i;
	}
	enable_interrupts();
	LOG("Startup...\r\n");
	DUMP(testBuffer,sizeof(testBuffer));
	set_timer();
	init_button();
    while (1)
    {      
		PD_ODR ^= (1 << LED_PIN);
        LOG("main app_sdcc == %u -- %lu, key %s\r\n",k++,count, (PD_IDR & (1 << BUTTON_PIN)) ? "up" : "down");	
		delay(500);
    }
} 