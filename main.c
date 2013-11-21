#include <msp430.h> 
#include "Motor_Driver.h"
/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	initRobot();

	moveRobotForward(100);
	__delay_cycles(10000);
//	stopRobot();
	moveRobotBackward(100);
	__delay_cycles(10000);
	moveRobotForward(100);
	__delay_cycles(10000);
	moveRobotBackward(100);
	__delay_cycles(10000);
	moveRobotForward(10);
	__delay_cycles(100000);
//	stopRobot();
//	turnRobotLeft(10);
//	__delay_cycles(100000);
//	stopRobot();
//	turnRobotRight(10);
//	__delay_cycles(100000);
//	stopRobot();
//	turnRobotLeft(10);
//	__delay_cycles(300000);
//	stopRobot();
//	turnRobotRight(10);
//	__delay_cycles(300000);
//	stopRobot();

}
