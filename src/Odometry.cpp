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

pros::Imu Gyro(gyroPort);
double xencoderbuffer;
double yencoderbuffer;
double xcord;
double ycord; 



double absD(double num) {
  return num < 0? - num: num; 
}

double getxrawrot() {
  return X_Encoder.get_position();
  

}



double getGyro() {
  return Gyro.get_rotation(); 
}


double getxcord() {
  double degreesnormalized = absD(fmod(getGyro(),360));
  if (degreesnormalized <= 90 && degreesnormalized >= 270) {
    return cos(degreesnormalized) * (getxrawrot() - xencoderbuffer);
  }
  else if (degreesnormalized >=90 && degreesnormalized <= 270) {
    return cos(degreesnormalized) * (getxrawrot() - xencoderbuffer);
  }
  
}


double getycord() {
  double degreesnormalized = absD(fmod(getGyro(),360));
  if (degreesnormalized <= 90 && degreesnormalized >= 270) {
    return sin(degreesnormalized);
  }
  else if (degreesnormalized >=90 && degreesnormalized <= 270) {
    return sin(degreesnormalized) * (getxrawrot() - xencoderbuffer);
  }
}
void updateOdometry() {
  xcord = xcord +getxcord();
  ycord = ycord +getycord();
}



