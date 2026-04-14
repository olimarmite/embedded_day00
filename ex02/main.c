
#ifndef F_CPU
    #define F_CPU 1000000UL
#endif

#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif


#include <avr/io.h>
#include <util/delay.h>

 
int main()
{
    // DDRB |= 1 << DDB0; // Data Direction Bit
    // PORTB |= 1 << PB0; // Value
    DDRB |= _BV(PB0);
    PORTB |= _BV(PB0);    

    DDRD &= ~_BV(PD2);


    while(1)
    {
        uint8_t pressed = (PIND & _BV(PD2)) == 0;
        
        PORTB = pressed << PB0;
        _delay_ms(1);
    }
    return 0;
}