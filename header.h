/********************************************************************************
*header.h: Innehåller definitioner och deklarationer för implementering
*          av tillståndsmaskinen.
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

/* Klockfrekvens */
#define F_CPU 16000000UL

/* Inkluderingsdirektiv */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/* Makron */
#define LED_1 0   //LED ansluten till pin 8 / PORTB 0
#define LED_2 1   //LED ansluten till pin 9 / PORTB 1
#define LED_3 2   //LED ansluten till pin 10 / PORTB 2

#define RESET_BUTTON 2       //Tryckknapp ansluten till pin 2 / PORTD 2
#define BACK_2_BUTTON 3      //Tryckknapp ansluten till pin 3 / PORTD 3
#define BACK_1_BUTTON 3      //Tryckknapp ansluten till pin 11 / PORTB 3
#define FORWARD_1_BUTTON 4   //Tryckknapp ansluten till pin 12 / PORTB 4
#define FORWARD_2_BUTTON 5   //Tryckknapp ansluten till pin 13 / PORTB 5

#define LED_1_ON PORTB |= (1 << LED_1)                                   //Tänder LED ansluten till pin 8
#define LED_2_ON PORTB |= (1 << LED_2)                                   //Tänder LED ansluten till pin 9
#define LED_3_ON PORTB |= (1 << LED_3)                                   //Tänder LED ansluten till pin 10
#define LEDS_ON PORTB |= ((1 << LED_1) | (1 << LED_2) | (1  << LED_3))   //Tänder samtliga LEDs

#define LED_1_OFF PORTB &= ~(1 << LED_1)                                  //Släcker LED ansluten till pin 8
#define LED_2_OFF PORTB &= ~(1 << LED_2)                                  //Släcker LED ansluten till pin 9
#define LED_3_OFF PORTB &= ~(1 << LED_3)                                  //Släcker LED ansluten till pin 10
#define LEDS_OFF PORTB &= ~((1 << LED_1) | (1 << LED_2) | (1 << LED_3))   //Släcker samtliga LEDs

#define RESET_BUTTON_PRESSED (PIND &(1 << RESET_BUTTON))           //Indikerar att reset-knappen har tryckts ner.
#define BACK_2_BUTTON_PRESSED (PIND &(1 << BACK_2_BUTTON))         //Indikerar hopp två steg bak.
#define BACK_1_BUTTON_PRESSED (PINB &(1 << BACK_1_BUTTON))         //Indikerar hopp ett steg bak.
#define FORWARD_1_BUTTON_PRESSED (PINB &(1 << FORWARD_1_BUTTON))   //Indikerar hopp ett steg fram.
#define FORWARD_2_BUTTON_PRESSED (PINB &(1 << FORWARD_2_BUTTON))   //Indikerar hopp två steg fram.


/* Enumerationer */ 
typedef enum { LED_STATE_OFF, LED_STATE_SLOW, LED_STATE_MEDIUM, LED_STATE_FAST, LED_STATE_ON } led_state_t; //´Lagrar lysdiodernas tillstånd.


/* Funktionsdeklarationer  */
void setup(void);                                     //Initierar mikrodatorn. 

void fsm_reset(void);                                 //Uppdaterar tillståndsmaskinen till startläge (lysdiderna släcks)

void fsm_update(void);                                //Uppdaterar tillståndsmaskinens tillstånd beroende på vilken tryckknapp som aktiverats.

void fsm_set_output(const uint16_t blink_speed_ms);   //Uppdaterar lysdiodernas tillstånd.

#endif /* HEADER_H_ */