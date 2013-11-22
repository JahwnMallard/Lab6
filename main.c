#include <msp430.h> 
#include "Motor_Driver.h"
/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	initRobot();

	  while (1) {

	      moveRobotForward(100);
	        __delay_cycles(700000);
	        moveRobotBackward(100);
	        __delay_cycles(700000);
	        turnRobotLeft(100);
	        __delay_cycles(700000);
	        turnRobotRight(100);
	        __delay_cycles(700000);
	        turnRobotLeft(100);
	        __delay_cycles(1500000);
	        turnRobotRight(100);
	        __delay_cycles(1500000);

	  }


}
