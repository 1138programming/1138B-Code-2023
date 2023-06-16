/**
* Code for Odometry and Gyro
*
* Two Motion Encoders, x and y axis
* Field Relative
* 
*
*/
#include "api.h"

#include "Odometry.h"
#include "Constants.cpp"
#include <functional>
#include <iostream>


pros::Rotation X_Encoder(x_Sesnor_Port);
pros::Rotation Y_Encoder(y_Sensor_Port);



void getxrawrot() {
  X_Encoder.get_position();

}

void getyrawrot() {

}

void Odometry() {
  
   //j
}


void getxcord() {

}


void getycord() {

}


