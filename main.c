#include <msp430.h> 
#include "Motor_Driver.h"
/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	initRobot();

	  while (1) {
	        __delay_cycles(5000000);
	      moveRobotForward(100);
	        __delay_cycles(5000000);
	        moveRobotBackward(100);
	        __delay_cycles(5000000);
	        turnRobotLeft(100);
	        __delay_cycles(5000000);
	        turnRobotRight(100);

	  }


}
