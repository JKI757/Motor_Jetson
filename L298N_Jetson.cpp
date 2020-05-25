/*
 * MIT License
 */

/* 
 * File:   L298N_Jetson.cpp
 * Author: josh
 * 
 * Created on May 23, 2020, 12:58 AM
 */

#include "L298N_Jetson.h"

L298N_Jetson::L298N_Jetson() = default;

L298N_Jetson::~L298N_Jetson() {
    this->Drive_PWM->stop();
    GPIO::cleanup();
};

L298N_Jetson::L298N_Jetson(const unsigned char EnablePin,
        const unsigned char IN1, const unsigned char IN2) {
    this->Enable = EnablePin;
    this->IN1 = IN1;
    this->IN2 = IN2;
    this->pwmVal = 0;
    GPIO::setmode(GPIO::BOARD);
    GPIO::setup(this->IN1, GPIO::OUT,GPIO::LOW);
    GPIO::setup(this->IN2, GPIO::OUT,GPIO::LOW);
    GPIO::setup(this->Enable, GPIO::OUT, GPIO::HIGH);
    this->Drive_PWM = std::make_shared<GPIO::PWM>(this->Enable, 50);
    // approximately 50hz is the correct frequency for the L298N board
}

L298N_Jetson::L298N_Jetson(const unsigned char pinIN1, const unsigned char pinIN2) {
    this->IN1 = IN1;
    this->IN2 = IN2;
    this->pwmVal = 0;
    GPIO::setmode(GPIO::BOARD);
    GPIO::setup(this->IN1, GPIO::OUT,GPIO::LOW);
    GPIO::setup(this->IN2, GPIO::OUT,GPIO::LOW);

}
void L298N_Jetson::setSpeed(const unsigned char  pwmVal){
    this->pwmVal = pwmVal;
}
const unsigned char L298N_Jetson::getSpeed(){
    return pwmVal;
}
void L298N_Jetson::forward(){
        GPIO::output(this->IN1, GPIO::HIGH);
        GPIO::output(this->IN2, GPIO::LOW);
        run();
}
void L298N_Jetson::backward(){
        GPIO::output(this->IN1, GPIO::LOW);
        GPIO::output(this->IN2, GPIO::HIGH);
        run();
}
void L298N_Jetson::run(){
    //this->Drive_PWM->ChangeDutyCycle( (this->pwmVal) / 255.0 );
    this->Drive_PWM->start((this->pwmVal) / 255.0);
    //important -- you need to send in values from [0, 255].  These are mapped to
    //a percentage for the GPIO library
}
void L298N_Jetson::stop(){
        GPIO::output(this->IN1, GPIO::LOW);
        GPIO::output(this->IN2, GPIO::LOW);
        this->Drive_PWM->stop();
}
