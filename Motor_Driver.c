/*
 * Motor_Driver.c
 *
 *  Created on: Nov 20, 2013
 *      Author: Administrator
 */

#include <msp430.h>
#include "Motor_Driver.h"
void initRobot() {

	P1DIR |= BIT2;                // TA0CCR1 on P1.2
	P1SEL |= BIT2;                // TA0CCR1 on P1.2

	P2DIR |= BIT1;                // TA0CCR1 on P1.2
	P2SEL |= BIT1;                // TA0CCR1 on P1.2

	P2DIR |= BIT5;                // TA0CCR1 on P1.2
	P2SEL |= BIT5;               // TA0CCR1 on P1.2

	P2DIR |= BIT4;                // TA0CCR1 on P2.2
	P2SEL |= BIT4;                // TA0CCR1 on P2.2

	WDTCTL = WDTPW | WDTHOLD;          // stop the watchdog timer

	TA0CTL &= ~MC1 | MC0;
	TA1CTL &= ~MC1 | MC0;

	TA0CTL |= TACLR;                // clear timer A0
	TA1CTL |= TACLR;                // clear timer A0

	TA0CTL |= TASSEL1;           // configure for SMCLK
	TA1CTL |= TASSEL1;           // configure for SMCLK

	TA0CCR0 = 100;  // set signal period to 100 clock cycles (~100 microseconds)
	TA1CCR0 = 100;
	TA0CCR1 = 0;
	TA1CCR1 = 0;
	TA1CCR2 = 0;  //BACK WHEELS        TA1.2

	TA0CCTL1 |= OUTMOD_7;
	TA1CCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode
	TA1CCTL2 |= OUTMOD_7;

	TA0CTL |= MC0;
	TA1CTL |= MC0;               // count up

}

void stopRobot() {
	TACCR1 = 0;
	TACTL &= ~MC1 | MC0;            // stop timer A0

	__delay_cycles(1000);

}

void leftMotorForward() {
	TA0CCR1 = 100;
	TA1CCR2 = 0;
}

void leftMotorStop() {
	TA0CCR1 = 0;
	TA1CCR2 = 0;
}

void rightMotorStop() {
	TA1CCR1 = 0;
	TA1CCR2 = 0;
}

void rightMotorForward() {
	TA1CCR1 = 100;
	TA1CCR2 = 0;
}

void MotorsBackward() {
	rightMotorStop();
	leftMotorStop();
	TA1CCR2 = 100;
}

void moveRobotForward(char dutyCycle) {

	rightMotorForward();
	leftMotorForward();

}

void moveRobotBackward(char dutyCycle) {

	MotorsBackward();

}
void turnRobotLeft(char dutyCycle) {
	leftMotorStop();
	rightMotorForward();

}
void turnRobotRight(char dutyCycle) {

	rightMotorStop();
	leftMotorForward();

}

