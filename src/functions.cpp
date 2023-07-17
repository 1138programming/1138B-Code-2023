#include "api.h"
#include "motors.h"
#include "Constants.h"
#include "functions.h"
#include "screens.h"
#include "pagehandler.h"
#include "NewPID.h"

bool inRange(float low, float high, float x) //check if rotational sensor data is within a range of degrees        
    { 
      if (low > high) {
        return (low <= x || x <= high);
      }
      else {  
        return (low <= x && x <= high);    
      }        
    }     
//intake/outtake

pros::Optical Intake_Optical(INTAKE_COLOR_PORT);

        void Intake::run() {
            intakeMotor.move(127);
        }
        void Intake::reverse() {
            intakeMotor.move(-outtake_speed);
        }
        void Intake::stop() {
            intakeMotor.move(0);
        }

//catapult doesnt work :( 
float Cata_Voltage = 90;
bool catainterupt;
pros::Rotation Cata_Rotation (CATA_ROT);

    void Catapult::init() {
        Catapultmotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD); // sets the catapult motor to hold
    }
    void Catapult::park() {
        
    }
    void Catapult::run() {
        
    }
    void Catapult::stop() {
        catainterupt = true;
        Catapultmotor.brake();
    }
    double Catapult::GetCatapultRot() {
        return Cata_Rotation.get_angle();
    }