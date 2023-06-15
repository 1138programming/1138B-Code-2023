/**
* Code for Odometry and Gyro
*
* Two Motion Encoders, x and y axis
* Field Relative
* 
*
*/

#include "Odometry.h"
#include "Constants"
#include <functional>
#include <iostream>


pros::Rotation X_Encoder(x_Sesnor_Port);
pros::Rotation Y_Encoder(y_Sensor_Port);

void getxrawrot() {
  X_Encoder.get_position

}

void getyrawrot() {

}

void Odometry() {
  
    pros::screen::set_pen(COLOR_BLUE);
    while(1){
       // Will print seconds started since program started on line 3
       pros::screen::print(pros::TEXT_MEDIUM, 3, "gttttttt",getxrawrot());
    }
}


void getxcord() {

}


void getycord() {

}

