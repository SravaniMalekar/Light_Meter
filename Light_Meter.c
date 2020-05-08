/*
 * adc.c
 *
 * Created: 07-05-2020 20:46:47
 *  Author: hp
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#define LED_PORT PORTB
void Init_ADC0(void);
int main(void)
{
	Init_ADC0();
	uint8_t led;
	uint16_t adc;
	uint8_t i;
	DDRB |= 0XFF;
	
    while(1)
    {
         ADCSRA |= (1 << ADSC);
		 while(ADCSRA & (1 << ADSC));
		 adc = ADC;
		 led=(adc >> 7);
		 LED_PORT =0;
		 for(i=0;i<led;i++){
			 LED_PORT |= (1 << i);
		 }
		 _delay_ms(50);
    }
	return 0;
}
void Init_ADC0(void){
	ADMUX |= (1 << REFS0);
	ADCSRA |= (1 << ADEN);
	ADCSRA |= (1 << ADPS1)|(1 << ADPS0);
	
}
