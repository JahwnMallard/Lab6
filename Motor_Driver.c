/*
 * Motor_Driver.c
 *
 *  Created on: Nov 20, 2013
 *      Author: Administrator
 */

#include <msp430.h>
#include "Motor_Driver.h"
void initRobot(){
     	WDTCTL = WDTPW|WDTHOLD;                 // stop the watchdog timer

	    TACTL &= ~MC1|MC0;            // stop timer A0

	    TACTL |= TACLR;                // clear timer A0

	    TACTL |= TASSEL1;           // configure for SMCLK

	    TACCR0 = 100;                // set signal period to 100 clock cycles (~100 microseconds)
	    TACCR1 = 25;                // set duty cycle to 25/100 (25%)

	    TACCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode

	    TACTL |= MC0;                // count up

}

void stopRobot(char time){
	TACCR1 = 0;
_delay_cycles(time);
}

void leftMotorForward(char dutyCycle){
	TACCR1 = dutyCycle;
    P1DIR |= BIT1;                // TA0CCR1 on P1.2
    P1SEL |= BIT1;                // TA0CCR1 on P1.2
}
void rightMotorForward(char dutyCycle){
	TACCR1 = dutyCycle;
    P2DIR |= BIT0;                // TA0CCR1 on P1.2
    P2SEL |= BIT0;                // TA0CCR1 on P1.2
}
void leftMotorBackward(char dutyCycle){
	TACCR1 = dutyCycle;
    P1DIR |= BIT2;                // TA0CCR1 on P1.2
    P1SEL |= BIT2;                // TA0CCR1 on P1.2
}
void rightMotorBackward(char dutyCycle){
	TACCR1 = dutyCycle;
    P2DIR |= BIT1;                // TA0CCR1 on P2.2
    P2SEL |= BIT1;                // TA0CCR1 on P2.2
}

void moveRobotForward(char dutyCycle, char movementTime){
	char i;
	for(i=0; i<movementTime; i++){
		rightMotorForward(dutyCycle);
		leftMotorForward(dutyCycle);
	}

}

void moveRobotBackward(char dutyCycle, char movementTime){
	char i;
	for(i=0; i<movementTime; i++){
		rightMotorBackward(dutyCycle);
		leftMotorBackward(dutyCycle);
	}
}
void turnRobotLeft(char dutyCycle, char movementTime){
	char i;
	for(i=0; i<movementTime; i++){
		rightMotorForward(dutyCycle);
		leftMotorBackward(dutyCycle);
	}
}
void turnRobotRight(char dutyCycle, char movementTime){
	char i;
	for(i=0; i<movementTime; i++){
		rightMotorBackward(dutyCycle);
		leftMotorForward(dutyCycle);
	}
}


