/*
 * MIT License
 */

/* 
 * File:   Motor_Jetson.cpp
 * Author: josh- -JKI757
 * 
 * Created on May 24, 2020, 7:49 PM
 */

#include "Motor_Jetson.hpp"

Motor_Jetson::Motor_Jetson(const unsigned char DrivePWMPin, 
        const unsigned char DriveIn1Pin,
        const unsigned char DriveIn2Pin, 
        const unsigned char SteeringPWMPin) {
    
}

Motor_Jetson::~Motor_Jetson() {
}

Motor_Jetson::Motor_Jetson(const Motor_Jetson& other) // copy constructor
{
}

Motor_Jetson::Motor_Jetson(Motor_Jetson&& other) // move constructor
{
}

Motor_Jetson& Motor_Jetson::operator=(const Motor_Jetson& other) // copy assignment
{
}

Motor_Jetson& Motor_Jetson::operator=(Motor_Jetson&& other) // move assignment
{
}

short Motor_Jetson::setDriveSpeed(const unsigned short speed) {

}

void Motor_Jetson::setDirection(Direction d) {

}

void Motor_Jetson::run() {

}

void Motor_Jetson::stop() {

}

void Motor_Jetson::turnAbsolute(short angle) {

}

void Motor_Jetson::turnRight(short angle) {

}

void Motor_Jetson::turnLeft(short angle) {

}
