/*
 * Motor_Driver.h
 *
 *  Created on: Nov 20, 2013
 *      Author: Administrator
 */

#ifndef MOTOR_DRIVER_H_
#define MOTOR_DRIVER_H_

void initRobot();

void leftMotorForward(char dutyCycle);
void rightMotorForward(char dutyCycle);
void leftMotorBackward(char dutyCycle);
void leftMotorBackward(char dutyCycle);

void stopRobot();
void moveRobotForward(char dutyCycle);
void moveRobotBackward(char dutyCycle);
void turnRobotLeft(char dutyCycle);
void turnRobotRight(char dutyCycle);

#endif /* MOTOR_DRIVER_H_ */
