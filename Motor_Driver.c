/*
 * Motor_Driver.c
 *
 *  Created on: Nov 20, 2013
 *      Author: Administrator
 */
void leftMotorForward(char dutyCycle){

}
void rightMotorForward(char dutyCycle){

}
void leftMotorBackward(char dutyCycle){

}
void leftMotorBackward(char dutyCycle){

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


