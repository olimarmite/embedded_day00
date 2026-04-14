
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

}


void toogle_led_state(uint8_t *state)
{
    SET_BIT(PORTB, PB0, *state);

    *state = !*state;
}

int main()
{
    setup();
    
    uint8_t previous_button_state = 0;
    uint8_t led_state = 0;

    SET_BIT(PORTB, PB0, 0);

    while(1)
    {
        uint8_t button_pressed = (PIND & _BV(PD2)) == 0;
        uint8_t just_pressed = button_pressed && !previous_button_state;


        if (just_pressed)
        {
            toogle_led_state(&led_state);
            _delay_ms(25);
        }
        _delay_ms(10);

        previous_button_state = button_pressed;
    }
    return 0;
}