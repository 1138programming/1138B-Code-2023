//constants file for ports
#include "Constants.h"
#define Constants.cpp

//odom ports
const int x_Sesnor_Port = 15;
const int gyroPort = 20;
const int y_Sensor_Port = 16;

//drive ports
const int RIGHT_FRONT_WHEELS_PORT = 2;
const int RIGHT_BACK_WHEELS_PORT = 4; 
const int RIGHT_TOP_WHEELS_PORT = 3;

const int LEFT_FRONT_WHEELS_PORT = 9;
const int LEFT_BACK_WHEELS_PORT = 10;
const int LEFT_TOP_WHEELS_PORT = 7;

//intake options
int INTAKE_LEFT = 8; 
int INTAKE_RIGHT =  1;
float Inatke_Speed = 100;
float Outtake_Coefficient = 1;


//cata options
int CATA_PORT = 11;
int CATA_ROT = 12;
float Cata_Speed = 75;