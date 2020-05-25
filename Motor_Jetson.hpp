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

class Motor_Jetson {

public:
    
    typedef enum {FORWARD, BACKWARD, STOP} Direction;
    typedef enum {DRIVE, TURNLEFT, TURNRIGHT, CHANGEDIRECTION, BRAKE } Command;

    Motor_Jetson(const unsigned char DrivePWMPin, const unsigned char DriveIn1Pin, 
    const unsigned char DriveIn2Pin, const unsigned char SteeringPWMPin);

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

    std::unique_ptr<Servo> steering;
    std::unique_ptr<L298N_Jetson> drive;
    short currentSpeed;
    Direction currentDirection;
};
