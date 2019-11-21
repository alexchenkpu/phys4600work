/*
 * task11.c
 *
 * Created: 2019/11/21 上午 11:03:47
 * Author : user
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

uint8_t keep_going = 1;

void loop()
{
	uint16_t lowbyte;
	uint16_t highbyte;
	uint16_t finalvalue;

	ADCSRA |= (1<<ADSC); //start data collection

	while(! (ADCSRA & (1<<ADIF))); //Loop until ADC complete

	lowbyte = ADCL; //ex 00000000 11101101
	highbyte = ADCH; //ex 00000000 00000010

	finalvalue = (highbyte<<8) | lowbyte;
	
	if(finalvalue<341)
	{
		PORTD |= (1 << PD7); //set
		PORTD &= ~(1 << PD6); //unset
		PORTD &= ~(1 << PD5);
	}
	
	if(finalvalue<681 && finalvalue>340)
	{
		PORTD |= (1 << PD6); //set
		PORTD &= ~(1 << PD7); //unset
		PORTD &= ~(1 << PD5);
	}
	
	if(finalvalue>680)
	{
		PORTD |= (1 << PD5); //set
		PORTD &= ~(1 << PD6); //unset
		PORTD &= ~(1 << PD7);
	}
}

void setup()
{
	DDRD |= (1<<PD5) | (1<<PD6) | (1<<PD7);
	
	PORTD &= ~(1<<PD5);
	PORTD &= ~(1<<PD6);
	PORTD &= ~(1<<PD7); //start all bit as 0
	
	ADMUX |= (1<<REFS0);
	ADMUX &= ~(1<<REFS1);
	
	ADMUX |= (1<<MUX2); 
	ADMUX |= (1<<MUX0);
	ADMUX &= ~(1<<MUX3);
	ADMUX &= ~(1<<MUX1);
	
	ADCSRA |= (1<<ADEN); //turn on adc system
}

int main()
{
	setup();
	while(keep_going) loop();
	
	return 0;
}

