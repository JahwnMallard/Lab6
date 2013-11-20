/*
 * Motor_Driver.h
 *
 *  Created on: Nov 20, 2013
 *      Author: Administrator
 */

#ifndef MOTOR_DRIVER_H_
#define MOTOR_DRIVER_H_

void leftMotorForward(char dutyCycle);
void rightMotorForward(char dutyCycle);
void leftMotorBackward(char dutyCycle);
void leftMotorBackward(char dutyCycle);

void moveRobotForward(char dutyCycle, char movementTime);
void moveRobotBackward(char dutyCycle, char movementTime);
void turnRobotLeft(char dutyCycle, char movementTime);
void turnRobotRight(char dutyCycle, char movementTime);

#endif /* MOTOR_DRIVER_H_ */
