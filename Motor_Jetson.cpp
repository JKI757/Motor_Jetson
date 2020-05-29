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
    Motor_Jetson::Motor_Jetson(
    int DrivePWMPin, 
    int DriveIn1Pin, 
    int DriveIn2Pin, 
    int SteeringPWMPin){
        GPIO::setmode(GPIO::BOARD);
        GPIO::setup(DrivePWMPin, GPIO::OUT, GPIO::HIGH);
        GPIO::setup(SteeringPWMPin, GPIO::OUT, GPIO::HIGH);
        this->steer_pwm = std::make_shared<GPIO::PWM>(SteeringPWMPin, 1500);
        this->drive_pwm = std::make_shared<GPIO::PWM>(DrivePWMPin, 50);
        
        drive = std::make_unique<L298N_Jetson> (this->steer_pwm, 
                                                DriveIn1Pin, 
                                                DriveIn2Pin, false);

        steer = std::make_unique<Servo_Jetson> (this->steer_pwm, false);

        currentSpeed = 0;
        currentDirection = STOP;

    }

Motor_Jetson::Motor_Jetson(
        int DrivePWMPin, 
        int DriveIn1Pin, 
        int DriveIn2Pin, 
        int SteeringPWMPin,
        const unsigned short minUs,
        const unsigned short maxUs,
        const unsigned short mapMin,
        const unsigned short mapMax) {
    
    drive = std::make_unique<L298N_Jetson> (DrivePWMPin, 
                                            DriveIn1Pin, 
                                            DriveIn2Pin);
    std::cerr << "after make driver" << std::endl;
    std::cerr << "steering pin: "  << SteeringPWMPin << std::endl;
    steer = std::make_unique<Servo_Jetson> (SteeringPWMPin,  
                                            minUs,  maxUs, 
                                            mapMin, mapMax);

    currentSpeed = 0;
    currentDirection = STOP;
    
    
}

Motor_Jetson::~Motor_Jetson() {
    this->steer_pwm->stop();
    this->drive_pwm->stop();
            GPIO::cleanup();

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
    currentSpeed = speed;
    drive->setSpeed(speed);
    drive->run();

}

void Motor_Jetson::setDirection(Direction d) {
    currentDirection = d;
    switch(currentDirection){
        case FORWARD:
            drive->forward();
            break;
        case BACKWARD:
            drive->backward();
            break;
        case STOP:
            drive->stop();
            break;
    };
    drive->run();
}

void Motor_Jetson::run() {
    drive->run();
}

void Motor_Jetson::stop() {
    drive->stop();
}

void Motor_Jetson::turnAbsolute(short angle) {
    std::cout << "steering value passed in: " << angle << std::endl;
    steer->writeMappedValue(angle);
}

void Motor_Jetson::turnRight(short angle) {

}

void Motor_Jetson::turnLeft(short angle) {

}
