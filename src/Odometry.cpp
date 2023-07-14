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
#include "Constants.h"
#include <functional>
#include <iostream>





pros::Rotation X_Encoder(x_Sesnor_Port);
pros::Imu Gyro(gyroPort);

void OdometryI() {
  
 
}

double Odometry::absD(double num) {
  return num < 0? - num: num; 
}

double Odometry::getxrawrot() {
  return X_Encoder.get_position();
  

}



double Odometry::getGyro() {
  return Gyro.get_rotation(); 
}


double Odometry::getxcorddiffrence() {
  double degreesnormalized = absD(fmod(getGyro(),360));
  if (degreesnormalized <= 90 && degreesnormalized >= 270) {
    return cos(degreesnormalized) * (getxrawrot() - xencoderbuffer);
  }
  else if (degreesnormalized >=90 && degreesnormalized <= 270) {
    return cos(degreesnormalized) * (getxrawrot() - xencoderbuffer);
  }
  else {
    return 0;
  }
  
}


double Odometry::getycorddiffrence() {
  double degreesnormalized = absD(fmod(getGyro(),360));
  if (degreesnormalized <= 90 && degreesnormalized >= 270) {
    return sin(degreesnormalized);
  }
  else if (degreesnormalized >=90 && degreesnormalized <= 270) {
    return sin(degreesnormalized) * (getxrawrot() - xencoderbuffer);
  }
  else {
    return 0;
  }
}

double Odometry::getycord() {
 return ycord;
}

double Odometry::getxcord() {
  return xcord;
}

void Odometry::updateOdometry() {

  xcord = xcord + getxcord();
  ycord = ycord + getycord();

  xencoderbuffer = getxrawrot();

}



