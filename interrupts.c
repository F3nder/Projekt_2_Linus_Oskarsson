/********************************************************************************
* interrupts.c: Inneh�ller avbrottsrutiner.
********************************************************************************/

#include "header.h"


/********************************************************************************
* ISR (PCINT0_vect): Avbrottsrutin f�r PCI-avbrott p� I/O-port B, som anropas
                     vid nedtryckning eller uppsl�pp av tryckknapparna p�
					 pin 11 - 13.
********************************************************************************/
ISR(PCINT0_vect)
{
	if(BACK_1_BUTTON_PRESSED || FORWARD_1_BUTTON_PRESSED || FORWARD_2_BUTTON_PRESSED)
	{
		fsm_update();
	}
	return;
}


/********************************************************************************
* ISR (INT1_vect): Avbrottsrutin f�r tryckknapp ansluten till pin 3. 
                   Aktiveras p� stigandeflank.
********************************************************************************/
ISR(INT1_vect)
{
	fsm_update();
	return;
}


/********************************************************************************
* ISR (INT0_vect): Avbrottsrutin f�r tryckknapp ansluten till pin 2. 
                   Aktiveras p� fallandeflank.
********************************************************************************/
ISR(INT0_vect)
{
	fsm_reset();
    return;
}
