/********************************************************************************
* setup.c: Innehåller initieringsrutiner. 
********************************************************************************/

#include "header.h"

/* Statiska funktioner */
static void init_ports(void);
static void init_interrupts(void);


/********************************************************************************
* setup: Initierar mikrodatorn. 
********************************************************************************/
void setup()
{
	init_ports();
	init_interrupts();
	fsm_reset();
	return;
}


/********************************************************************************
* init_ports: Sätter lysdiodernas pins till utportar. 
              Sätter tryckknapparnas pins till aktiva inportar.
********************************************************************************/
static void init_ports(void)
{
	DDRB |= (1 << LED_1) | (1 << LED_2) | (1 << LED_3);
	PORTD |= (1 << RESET_BUTTON) | (1 << BACK_2_BUTTON);
	PORTB |= (1 << BACK_1_BUTTON) | (1 << FORWARD_1_BUTTON) | (1 << FORWARD_2_BUTTON);
	return;
}


/********************************************************************************
* Init_interrupts: Aktiverar PCI-avbrott på pin 11 - 13 samt externa avbrott
                   på pin 2 (fallandeflank) och pin 3 (stigandeflank) 
********************************************************************************/
static void init_interrupts(void)
{
	asm("SEI");
	PCICR = (1 << PCIE0);
	PCMSK0 = ((1 << BACK_1_BUTTON) | (1 << FORWARD_1_BUTTON) | (1 << FORWARD_2_BUTTON));
	
	EICRA = ((1 << ISC01) | (1 << ISC11) | (1 << ISC10));
	EIMSK = ((1 << INT0) | (1 << INT1));

    return;
}