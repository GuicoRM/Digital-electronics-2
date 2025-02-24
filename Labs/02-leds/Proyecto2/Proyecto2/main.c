/***********************************************************************
 * 
 * Alternately toggle two LEDs when a push button is pressed.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) Guillermo Cort�s
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Defines -----------------------------------------------------------*/
#define LED_GREEN   PB5     // AVR pin where green LED is connected
#define LED_BLUE    PC0     // AVR pin where blue LED is connected
#define BLINK_DELAY 500
#ifndef F_CPU
#define F_CPU 16000000      // CPU frequency in Hz required for delay
#endif

/* Includes ----------------------------------------------------------*/
#include <util/delay.h>     // Functions for busy-wait delay loops (PAUSAS)
#include <avr/io.h>         // AVR device-specific IO definitions (ENTRADA/SALIDA)

/* Functions ---------------------------------------------------------*/
/**
 * Main function where the program execution begins. Toggle two LEDs 
 * when a push button is pressed.
 */
int main(void)
{
    /* GREEN LED */
    // Set pin as OUTPUT in Data Direction Register... (PIN COMO SALIDA)
    DDRB = DDRB | (1<<LED_GREEN);
    // ...and turn LED off in Data Register (Inicialmente APAGADO)
    PORTB = PORTB & ~(1<<LED_GREEN);

    /* BLUE LED */
    // Set pin as OUTPUT in Data Direction Register...(PIN COMO SALIDA)
    DDRC = DDRC | (1<<LED_BLUE);
    // ...and turn LED off in Data Register (Inicialmente APAGADO)
    PORTC = PORTC | (1<<LED_BLUE);
	
    /* push button */
    // WRITE YOUR CODE HERE

    // Infinite loop
    while (1)
    {
        // Pause several milliseconds
        _delay_ms(BLINK_DELAY);

        // Invertimos valores (PARPADEO)
		PORTB = PORTB ^ (1<<LED_GREEN);
		PORTC = PORTC ^ (1<<LED_BLUE);
    }

    // Will never reach this
    return 0;
}