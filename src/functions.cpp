#include "api.h"
#include "motors.h"
#include "Constants.h"
#include "functions.h"
#include "screens.h"
#include "pagehandler.h"
#include "NewPID.h"
#include "sensors.h"

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
        void Intake::init() {
            intakeMotor.set_gearing(pros::E_MOTOR_GEARSET_06);
            intakeMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
        }
        void Intake::run() {
            intakeMotor.move(127);
        }
        void Intake::reverse() {
            intakeMotor.move(-outtake_speed);
        }
        void Intake::stop() {
            intakeMotor.move(0);
        }
        double Intake::getTorque() {
            intakeMotor.get_torque();
        }
        double Intake::getRPMs() {
            intakeMotor.get_actual_velocity();
        }
//catapult doesnt work :( 
float Cata_Voltage = 90;
bool catainterupt;


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