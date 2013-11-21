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
	      moveRobotForward(100);
	        __delay_cycles(1000000);
	        moveRobotBackward(100);
	        __delay_cycles(1000000);
	        moveRobotForward(100);
	        __delay_cycles(1000000);
	        moveRobotBackward(100);

	  }


}
