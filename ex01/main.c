
#ifndef F_CPU
#define F_CPU 16000000UL
#endif


#include <avr/io.h>
// #include <iom328p.h>
 
int main()
{
    DDRB = 1 << DDB0; // Data Direction Bit
    PORTB = 1 << PB0; // Value

    while(1)
    {

    }
    return 0;
}