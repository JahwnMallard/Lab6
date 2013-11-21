/*
 * Motor_Driver.c
 *
 *  Created on: Nov 20, 2013
 *      Author: Administrator
 */

#include <msp430.h>
#include "Motor_Driver.h"
void initRobot() {
	WDTCTL = WDTPW | WDTHOLD;                 // stop the watchdog timer

	TACTL &= ~MC1 | MC0;            // stop timer A0

	TA0CTL |= TACLR;                // clear timer A0
	TA1CTL &= ~MC1 | MC0;
	TA0CTL |= TASSEL1;           // configure for SMCLK
	TA1CTL &= ~MC1 | MC0;

	TA0CCR0 = 100;  // set signal period to 100 clock cycles (~100 microseconds)
	TA1CCR0 = 100;
	TA0CCR1 = 0;
	TA1CCR1 = 0;

	TA0CCTL1 |= OUTMOD_7;
	TA0CCTL0 |= OUTMOD_5;
	TA1CCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode
	TA1CCTL0 |= OUTMOD_5;

	TA0CTL |= MC0;
	TA1CTL |= MC0;               // count up

}

void stopRobot() {
	TACCR1 = 0;
	TACTL &= ~MC1 | MC0;            // stop timer A0

	__delay_cycles(1000);

}

void leftMotorForward(char dutyCycle) {
//	TACCR1 = dutyCycle;
//	P1DIR &= ~BIT1;                // TA0CCR1 on P1.2
//	P1SEL &= ~BIT1;                // TA0CCR1 on P1.2
	P1DIR |= BIT2;                // TA0CCR1 on P1.2
	P1SEL |= BIT2;                // TA0CCR1 on P1.2
}
void rightMotorForward(char dutyCycle) {
//	TACCR1 = dutyCycle;
//	P2DIR &= ~BIT0;                // TA0CCR1 on P2.2
//	P2SEL &= ~BIT0;                // TA0CCR1 on P2.2
	P2DIR |= BIT1;                // TA0CCR1 on P1.2
	P2SEL |= BIT1;                // TA0CCR1 on P1.2
}
void leftMotorBackward(char dutyCycle) {
//	TACCR1 = dutyCycle;
	P1DIR &= ~BIT2;                // TA0CCR1 on P1.2
	P1SEL &= ~BIT2;                // TA0CCR1 on P1.2
	P1DIR |= BIT1;                // TA0CCR1 on P1.2
	P1SEL |= BIT1;                // TA0CCR1 on P1.2
}
void rightMotorBackward(char dutyCycle) {
//	TACCR1 = dutyCycle;
	P2DIR &= ~BIT1;                // TA0CCR1 on P1.2
	P2SEL &= ~BIT1;                // TA0CCR1 on P1.2
	P2DIR |= BIT0;                // TA0CCR1 on P2.2
	P2SEL |= BIT0;                // TA0CCR1 on P2.2
}

void moveRobotForward(char dutyCycle) {

	rightMotorForward(dutyCycle);
	leftMotorForward(dutyCycle);

}

void moveRobotBackward(char dutyCycle) {

	rightMotorBackward(dutyCycle);
	leftMotorBackward(dutyCycle);

}
void turnRobotLeft(char dutyCycle) {

	rightMotorForward(dutyCycle);
	leftMotorBackward(dutyCycle);

}
void turnRobotRight(char dutyCycle) {

	rightMotorBackward(dutyCycle);
	leftMotorForward(dutyCycle);

}

