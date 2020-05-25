/*
*  nMIT License
 * 
 *  */


/* 
 * File:   L298N_Jetson.h
 * Author: josh -- JKI757
 *
 * Created on May 23, 2020, 12:58 AM
 */

#ifndef L298N_JETSON_H
#define L298N_JETSON_H

#include <JetsonGPIO.h>
#include <memory>

class L298N_Jetson {
public:
    
    L298N_Jetson();
    
    ~L298N_Jetson();
  
   L298N_Jetson(const unsigned char EnablePin, 
   const unsigned char IN1, const unsigned char IN2);
   L298N_Jetson(const unsigned char IN1, const unsigned char IN2);
   void setSpeed(const unsigned char pwmVal);
   const unsigned char getSpeed();
   void forward();
   void backward();
   void run();
   void stop();
   void reset();

private:
   unsigned char Enable;
   unsigned char IN1;
   unsigned char IN2;
   unsigned char pwmVal;

   std::shared_ptr<GPIO::PWM> Drive_PWM;
   

};

#endif /* L298N_JETSON_H */

