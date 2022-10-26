/********************************************************************************
* main.c: Implementering av tillst�ndsmaskin som kan anta 5 tillst�nd
          med 3 lysdioder.
		  
		  Tillst�nd:           Resultat:
		  OFF                  Lysdioderna �r sl�ckta
		  Slow                 Lysdioderna blinkar med 500 mlilisekunders delay
		  Medium               Lysdioderna blinkar med 250 mlilisekunders delay
		  Fast                 Lysdioderna blinkar med 50 mlilisekunders delay
		  ON                   Lysdioderna �r t�nda
		  
		  Tryckknapparna �r anslutna till pin 2/PORTD2, 3/PORTD3, 11/PORTB3, 
		  4/PORTB4, 5/PORTB5. 
		  Tryckknapparna anv�nds f�r att uppdatera tillst�ndsmaskinen. 
********************************************************************************/

#include "header.h"


/********************************************************************************
* main: Initierar mikrodatorn. 
        Programmet h�lls ig�ng s�l�nge matningssp�nning �r p�. 
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
