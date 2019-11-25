/*
 * task12.c
 *
 * Created: 2019/11/25 上午 10:58:45
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
	DDRB |= (1<<PB3); //output MOSI
	DDRB |= (1<<PB5); //output SCK
	DDRB |= (1<<PB6); //output chip select
	
	SPCR &= ~(1<<SPIE);
	SPCR |= (1<<SPE);
	SPCR &= ~(1<<DORD);
	SPCR |= (1<<MSTR);
	SPCR |= (1<<CPOL);
	SPCR &= ~(1<<CPHA);
	SPCR &= ~(1<<SPR1);
	SPCR &= ~(1<<SPR0);
	
	uint8_t data =5;
	uint8_t datarecieved;
	
	PORTB &= ~(1<<PB6); //pulls chip select low
	SPDR = data;
	
	while(!(SPSR & (1<<SPIF)));
	datarecieved = SPDR;
}

int main()
{
	setup();
	while(keep_going) loop();
	
	return 0;
}