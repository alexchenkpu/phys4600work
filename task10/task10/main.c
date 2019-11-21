/*
 * task10.c
 *
 * Created: 2019/11/18 上午 10:40:11
 * Author : user
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

uint8_t keep_going = 1;

void loop()
{
	
}

void setup()
{
	DDRD |= (1<<PD6); //set as output

	TCCR0A |= (1<<COM0A0)|(1<<COM0A1);
	TCCR0A |= (1<<WGM00);//|(1<<WGM01); //PWM
	TCCR0B |= (1<<CS00);
	
	OCR0A = 200; //number to compare
}

int main()
{
	setup();
	while(keep_going) loop();
	
	return 0;
}

