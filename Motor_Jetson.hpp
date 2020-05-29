/*
 * MIT License
 */

/* 
 * File:   Motor_Jetson.hpp
 * Author: josh - JKI757
 *
 * Created on May 24, 2020, 7:49 PM
 */

#pragma once

#include "L298N_Jetson.hpp"
#include "Servo.hpp"
#include <memory>
#include <iostream>
#include <string>
#include "JetsonGPIO.h"

class Motor_Jetson {

public:
    
    typedef enum {FORWARD, BACKWARD, STOP} Direction;
    typedef enum {DRIVE, TURNLEFT, TURNRIGHT, CHANGEDIRECTION, BRAKE } Command;

    Motor_Jetson(
    int DrivePWMPin, 
    int DriveIn1Pin, 
    int DriveIn2Pin, 
    int SteeringPWMPin);
    
    Motor_Jetson(
        int DrivePWMPin, 
        int DriveIn1Pin,
        int DriveIn2Pin, 
        int SteeringPWMPin,
        const unsigned short minUs,
        const unsigned short maxUs,
        const unsigned short mapMin,
        const unsigned short mapMax);

    ~Motor_Jetson();

    Motor_Jetson(const Motor_Jetson& other); // copy constructor

    Motor_Jetson(Motor_Jetson&& other); // move constructor

    Motor_Jetson& operator=(const Motor_Jetson& other); // copy assignment
 \
    Motor_Jetson& operator=(Motor_Jetson&& other); // move assignment

    short setDriveSpeed(const unsigned short speed);
    void setDirection(Direction d);
    void run();
    void stop();
    void turnAbsolute(short angle);
    void turnRight(short angle);
    void turnLeft(short angle);

private:
    std::shared_ptr<GPIO::PWM> steer_pwm;
    std::shared_ptr<GPIO::PWM> drive_pwm;
    
    std::unique_ptr<Servo_Jetson> steer;
    std::unique_ptr<L298N_Jetson> drive;
    short currentSpeed;
    Direction currentDirection;
};
