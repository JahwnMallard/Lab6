#include <msp430.h> 
#include "Motor_Driver.h"
/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	initRobot();
	moveRobotForward(10, 2000);
	stopRobot(500);
	moveRobotBackward(10,2000);
	stopRobot(500);
	turnRobotLeft(10,500);
	stopRobot(500);
	turnRobotRight(10,500);
	stopRobot(500);
	turnRobotLeft(10,2000);
	stopRobot(500);
	turnRobotRight(10,2000);
	stopRobot(1000);
	return 0;
}
