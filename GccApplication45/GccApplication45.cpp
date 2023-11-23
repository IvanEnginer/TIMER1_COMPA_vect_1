#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR(TIMER1_COMPA_vect)
	{
		PORTD |= (1 << 0);
		for (int i=0; i<5; i++) _delay_loop_2(65535);
		PORTD &= ~(1 << 0);
	}


int main(void)
{
	DDRD |= (1 << 7);
	
	DDRD |= (1 << 6);
	PORTD &= ~(1 << 0);
	
	OCR1AH = 0x80;
	OCR1AL = 0x00;
	
	TCCR1A = 0x40;
	
	TCCR1B = 0x03;
	
	TIMSK |= (1 << 6);
	
	sei();
	
    while(1)
    {

    }
}