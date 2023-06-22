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
pros::Imu Gyro(gyroPort);
double xcord;
double ycord; 



double absD(double num) {
  return num < 0? - num: num;
}

double getxrawrot() {
  return X_Encoder.get_position();


}

double getyrawrot() {
  return Y_Encoder.get_position();
}

double getGyro() {
  return Gyro.get_rotation(); 
}


double getxcord() {
  double degreesnormalized = absD(fmod(getGyro(),360));
  if (degreesnormalized <= 90 && degreesnormalized >= 270) {
    return absD((-fmod(degreesnormalized,180)/ 90)+1);
  }
  else if (degreesnormalized >=90 && degreesnormalized <= 270) {
    return -absD((-fmod(degreesnormalized,180)/ 90)+1);
  }
  
}


double getycord() {
  double degreesnormalized = absD(fmod(getGyro(),360));
  if (degreesnormalized <= 90 && degreesnormalized >= 270) {
    return absD((fmod(degreesnormalized,180)/ 90) - 1);
  }
  else if (degreesnormalized >=90 && degreesnormalized <= 270) {
    return -absD((fmod(degreesnormalized,180)/ 90) - 1);
  }
}


