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
	_delay_ms(100);*/
	
	TCNT0=0; //set timer to zero
	TCCR0B=(1 << CS00) | (1 << CS02);
	
	while(1)
	{
		while((TIFR0 & 1)==0); //delay the program
		PORTD ^= (1<<PD1);
	}
	
}

void setup()
{

}

int main()
{
	setup();
	while(keep_going) loop();
	
	return 0;
}