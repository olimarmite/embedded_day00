
#ifndef F_CPU
    #define F_CPU 1000000UL
#endif

#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif


#include <avr/io.h>
#include <util/delay.h>

#define SET_BIT(addr, bit_position, value) addr = (addr & ~((value ^ 1) << bit_position)) | (value << bit_position);


void setup()
{
    // Inputs
    DDRD &= ~_BV(PD2);
    
    // Outputs
    DDRB |= _BV(PB0);
    DDRB |= _BV(PB1);
    DDRB |= _BV(PB2);
    DDRB |= _BV(PB4);
    
    // PORTB |= _BV(PB0);
    // PORTB |= _BV(PB1);
    // PORTB |= _BV(PB2);
    // PORTB |= _BV(PB4);
}


void toogle_led_state(uint8_t *state)
{
    SET_BIT(PORTB, PB0, *state);

    *state = !*state;
}


void display_number_binary(uint8_t number)
{
    SET_BIT(PORTB, PB0, ((number & 0b0001) != 0));
    SET_BIT(PORTB, PB1, ((number & 0b0010) != 0));
    SET_BIT(PORTB, PB2, ((number & 0b0100) != 0));
    SET_BIT(PORTB, PB4, ((number & 0b1000) != 0));
}


int main()
{
    setup();
    
    uint8_t previous_button_state = 0;
    uint8_t led_state = 0;

    display_number_binary(led_state);
    while(1)
    {
        uint8_t button_pressed = (PIND & _BV(PD2)) == 0;
        uint8_t just_pressed = button_pressed && !previous_button_state;

        if (just_pressed)
        {
            ++led_state;
            display_number_binary(led_state);
            _delay_ms(25);
        }
        _delay_ms(10);

        previous_button_state = button_pressed;
    }
    return 0;
}