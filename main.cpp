/*
 * MIT License
 */

/* 
 * File:   main.cpp
 * Author: josh
 *
 * Created on May 24, 2020, 7:40 PM
 * This is just a test program to exercise the motor_jetson library during
 * development.
 */


#include "definitions.h"
#include "Motor_Jetson.hpp"
#include <unistd.h>
int main(int argc, char** argv) {

    Motor_Jetson mj(JETSON_DRIVE_PIN, JETSON_IN1_PIN, 
                    JETSON_IN2_PIN,JETSON_STEER_PIN,
                    MAX_RIGHT_STEERING_US,
                    MAX_LEFT_STEERING_US,
                    MIN_STEERING_INPUT, MAX_STEERING_INPUT);

    
    while (true){
        mj.setDirection(Motor_Jetson::FORWARD);
        std::cout << "Driving Forward " << std::endl;
        mj.run();
        for (int i=0; i < 255; i++){
            mj.setDriveSpeed(i/2.6);
            usleep(1000);
           mj.turnAbsolute(i);
            usleep(10000);
        }
        
        mj.setDirection(Motor_Jetson::STOP);
        usleep(1000);
        std::cout << "Stopping " << std::endl;
        for (int i=255; i>0;i--){
            mj.setDriveSpeed(i/2.6);
            usleep (1000);
            mj.turnAbsolute(i);

            usleep(10000);
        }
        mj.setDirection(Motor_Jetson::BACKWARD);
        std::cout << "going backwards " << std::endl;
        usleep(1000000);
    }
    
    return 0;
}

