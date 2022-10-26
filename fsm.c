/********************************************************************************
* fsm.c: Innehåller funktionalitet för implementering av tillståndsmaskinen. 
********************************************************************************/

#include "header.h"



/* Statiska funktioner */
static void leds_blink(const volatile uint16_t* blink_speed_ms);
static void delay_ms(const volatile uint16_t* delay_time_ms);

/* Statiska datamedlemmar */
static led_state_t state = LED_STATE_OFF;
static uint16_t speed_ms = 0;


/********************************************************************************
* fsm_reset: Återställer tillståndsmaskinen till startläge (lysdioderna släckta)
********************************************************************************/
void fsm_reset()
{
	state = LED_STATE_OFF;
	speed_ms = 0;
	LEDS_OFF;
	return;
}


/********************************************************************************
* fsm_update: Uppdaterar tillståndsmaskinen beroende på nuvarande tillstånd 
              och vilken tryckknapp som aktiverats. 
********************************************************************************/
void fsm_update()
{
	switch (state)
	{
		case LED_STATE_OFF:
		{
			if (BACK_1_BUTTON_PRESSED)
			{
				state = LED_STATE_ON;
			}
			else if (BACK_2_BUTTON_PRESSED)
			{
				state = LED_STATE_FAST;
			}
			else if (FORWARD_1_BUTTON_PRESSED)
			{
				state = LED_STATE_SLOW;
			}
			else if (FORWARD_2_BUTTON_PRESSED)
			{
				state = LED_STATE_MEDIUM;
			}
			break;
		}
		
		case LED_STATE_SLOW:
		{
			if (BACK_1_BUTTON_PRESSED)
			{
				state = LED_STATE_OFF;
			}
			else if (BACK_2_BUTTON_PRESSED)
			{
				state = LED_STATE_ON;
			}
			else if (FORWARD_1_BUTTON_PRESSED)
			{
				state = LED_STATE_MEDIUM;
			}
			else if (FORWARD_2_BUTTON_PRESSED)
			{
				state = LED_STATE_FAST;
			}
			break;
		}
		
	    case LED_STATE_MEDIUM:
		{
			if (BACK_1_BUTTON_PRESSED)
			{
				state = LED_STATE_SLOW;
			}
			else if (BACK_2_BUTTON_PRESSED)
			{
				state = LED_STATE_OFF;
			}
			else if (FORWARD_1_BUTTON_PRESSED)
			{
				state = LED_STATE_FAST;
			}
			else if (FORWARD_2_BUTTON_PRESSED)
			{
				state = LED_STATE_ON;
			}
			break;
		}
		
		case LED_STATE_FAST:
		{
			if (BACK_1_BUTTON_PRESSED)
			{
				state = LED_STATE_MEDIUM;
			}
			else if (BACK_2_BUTTON_PRESSED)
			{
				state = LED_STATE_SLOW;
			}
			else if (FORWARD_1_BUTTON_PRESSED)
			{
				state = LED_STATE_ON;
			}
			else if (FORWARD_2_BUTTON_PRESSED)
			{
				state = LED_STATE_OFF;
			}
			break;
		}
		
		case LED_STATE_ON:
		{
			if (BACK_1_BUTTON_PRESSED)
			{
				state = LED_STATE_FAST;
			}
			else if (BACK_2_BUTTON_PRESSED)
			{
				state = LED_STATE_MEDIUM;
			}
			else if (FORWARD_1_BUTTON_PRESSED)
			{
				state = LED_STATE_OFF;
			}
			else if (FORWARD_2_BUTTON_PRESSED)
			{
				state = LED_STATE_SLOW;
			}
			break;
		}
		
		default:
		{
			fsm_reset();
			break;
		}
	}
	
	if (state == LED_STATE_OFF || state == LED_STATE_ON)
	{
		speed_ms = 0;
	}
	
	fsm_set_output(0);
	return;
}


/********************************************************************************
* fsm_set_update: Uppdaterar lysdiodernas tillstånd. 
********************************************************************************/
void fsm_set_output(const uint16_t blink_speed_ms)
{
	if (state == LED_STATE_OFF)
	{
		LEDS_OFF;
	}
	else if (state == LED_STATE_SLOW)
	{
		speed_ms = 500;
		leds_blink(&speed_ms);
	}
	else if (state == LED_STATE_MEDIUM)
	{
		speed_ms = 250;
		leds_blink(&speed_ms);
	}
	else if (state == LED_STATE_FAST)
	{
		speed_ms = 50;
		leds_blink(&speed_ms);
	}
	else if (state == LED_STATE_ON)
	{
		LEDS_ON;
	}
	else
	{
		fsm_reset();
	}
}


/********************************************************************************
* leds_blink: Blinkar lysdioderna med angiven delay tid.
********************************************************************************/
static void leds_blink(const volatile uint16_t* blink_speed_ms)
{
	LED_1_ON;
	LED_2_OFF;
	LED_3_OFF;
	delay_ms(blink_speed_ms);
	
	LED_1_OFF;
	LED_2_ON;
	LED_3_OFF;
	delay_ms(blink_speed_ms);
	
	LED_1_OFF;
	LED_2_OFF;
	LED_3_ON;
	delay_ms(blink_speed_ms);
	
	LED_3_OFF;
	return;
}


/********************************************************************************
* delay_ms: Genererar delay i millisekunder. 
********************************************************************************/
static void delay_ms(const volatile uint16_t* delay_time_ms)
{
	for (uint16_t i = 0; i < *delay_time_ms; i++)
	{
		_delay_ms(1);
	}
	return;
}