/*
 * task9.c
 *
 * Created: 2019/11/14 上午 10:43:27
 * Author : user
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

uint8_t keep_going = 1;

void loop()
{
	/*PORTD |= (1 << PD1);
	_delay_ms(100);
	PORTD &= ~(1 << PD1);
	_delay_ms(100);
	
	TCNT0=0; //set timer to zero
	TCCR0B=(1 << CS00) | (1 << CS02);
	
	while(1)
	{
		while((TIFR0 & 1)==0); //delay the program
		PORTD ^= (1<<PD1);
	}*/
	
}

ISR(TIMER0_OVF_vect)
{
	//PORTD &= ~(1 << PD1); //unset
	PORTD ^= (1 << PD1);
}

ISR(TIMER0_COMPA_vect)
{
	//PORTD |= (1 << PD1); //set
	PORTD ^= (1 << PD1);
}

void setup()
{
	DDRD |= (1<<PD1); //set as output
	PORTD &= (1<<PD1); //start PB3 as 0
	
	TCCR0B = 0x01; //set clock run on no prescaling
	//TIMSK0 = 3;
	TIMSK0 |= (1<<OCIE0A)|(1<<TOIE0);
	
	OCR0A = 50; //number to compare
	
	sei();
}

int main()
{
	setup();
	while(keep_going) loop();
	
	return 0;
}

