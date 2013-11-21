#include <msp430.h> 
#include "Motor_Driver.h"
/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	initRobot();
moveRobotForward(0);
	  while (1) {
	        __delay_cycles(1000000);
	        TA0CCR1 = 50;
	        TA1CCR1 = 50;// set duty cycle to 50/100 (50%)
	        __delay_cycles(1000000);
	        TA0CCR1 = 75;            // set duty cycle to 75/100 (75%)
	        TA1CCR1 = 75;
	        __delay_cycles(1000000);
	        TA0CCR1 = 100;            // set duty cycle to 100/100 (100%)
	        TA1CCR1 = 100;
	        __delay_cycles(1000000);
	        TA0CCR1 = 25;            // set duty cycle to 25/100 (25%)
	        TA1CCR1 = 25;
	  }


}
