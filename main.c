/********************************************************************************
* main.c: Implementering av tillståndsmaskin som kan anta 5 tillstånd
          med 3 lysdioder.
		  
		  Tillstånd:           Resultat:
		  OFF                  Lysdioderna är släckta
		  Slow                 Lysdioderna blinkar med 500 mlilisekunders delay
		  Medium               Lysdioderna blinkar med 250 mlilisekunders delay
		  Fast                 Lysdioderna blinkar med 50 mlilisekunders delay
		  ON                   Lysdioderna är tända
		  
		  Tryckknapparna är anslutna till pin 2/PORTD2, 3/PORTD3, 11/PORTB3, 
		  4/PORTB4, 5/PORTB5. 
		  Tryckknapparna används för att uppdatera tillståndsmaskinen. 
********************************************************************************/

#include "header.h"


/********************************************************************************
* main: Initierar mikrodatorn. 
        Programmet hålls igång sålänge matningsspänning är på. 
********************************************************************************/
int main(void)
{
    setup();
	
    while (1) 
    {
		fsm_set_output(0);
    }
	
	return 0;
}
