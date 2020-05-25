/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Motor_Jetson.hpp
 * Author: josh
 *
 * Created on May 24, 2020, 7:49 PM
 */

#pragma once

#include "L298N_Jetson.hpp"
#include "Servo.hpp"

class Motor_Jetson {
public:
    Motor_Jetson();
    Motor_Jetson(const Motor_Jetson& orig);

    Motor_Jetson(const char* arg)
    : cstring(new char[std::strlen(arg) + 1]) // allocate
    {
        std::strcpy(cstring, arg); // populate
    }

    ~Motor_Jetson() {
        delete[] cstring; // deallocate
    }

    Motor_Jetson(const Motor_Jetson& other) // copy constructor
    {
        cstring = new char[std::strlen(other.cstring) + 1];
        std::strcpy(cstring, other.cstring);
    }

    Motor_Jetson(Motor_Jetson&& other) : cstring(other.cstring) // move constructor
    {
        other.cstring = nullptr;
    }

    Motor_Jetson& operator=(const Motor_Jetson& other) // copy assignment
    {
        char* tmp_cstring = new char[std::strlen(other.cstring) + 1];
        std::strcpy(tmp_cstring, other.cstring);
        delete[] cstring;
        cstring = tmp_cstring;
        return *this;
    }

    Motor_Jetson& operator=(Motor_Jetson&& other) // move assignment
    {
        delete[] cstring;
        cstring = other.cstring;
        other.cstring = nullptr;
        return *this;
    }
    virtual ~Motor_Jetson();


private:

    
};
