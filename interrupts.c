/********************************************************************************
* interrupts.c: Innehåller avbrottsrutiner.
********************************************************************************/

#include "header.h"


/********************************************************************************
* ISR (PCINT0_vect): Avbrottsrutin för PCI-avbrott på I/O-port B, som anropas
                     vid nedtryckning eller uppsläpp av tryckknapparna på
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
* ISR (INT1_vect): Avbrottsrutin för tryckknapp ansluten till pin 3. 
                   Aktiveras på stigandeflank.
********************************************************************************/
ISR(INT1_vect)
{
	fsm_update();
	return;
}


/********************************************************************************
* ISR (INT0_vect): Avbrottsrutin för tryckknapp ansluten till pin 2. 
                   Aktiveras på fallandeflank.
********************************************************************************/
ISR(INT0_vect)
{
	fsm_reset();
    return;
}
