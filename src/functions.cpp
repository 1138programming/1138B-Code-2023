#include "api.h"
#include "motors.h"
#include "Constants.h"
#include "functions.h"

bool inRange(unsigned low, unsigned high, unsigned x) //check if rotational sensor data is within a range of degrees        
    { 
      if (low > high) {
        return (low <= x || x <= high);
      }
      else {  
        return (low <= x && x <= high);         
      }        
    }     
//intake/outtake
float Inatke_Voltage = 100;
float Outtake_Coefficient = 1;
float outtake_speed = (Inatke_Voltage * Outtake_Coefficient * -1);

        void Intake::run() {
            intakemotors.move(Inatke_Voltage);
        }
        void Intake::reverse() {
            intakemotors.move(outtake_speed);
        }
        void Intake::stop() {
            intakemotors.move(0);
        }

//catapult
inline float Cata_Voltage = 75;
pros::Rotation Cata_Rotation (CATA_ROT);

    void Catapult::init() {
        Catapultmotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD); // sets the catapult motor to hold
    }
    void Catapult::intake() {
        //move catapult to intake position
        float catarotationdegrees = Cata_Rotation.get_angle() / 100; //define the catapult rotation when the button is first pressed
        while (!inRange(358,2,catarotationdegrees)) {
            Catapultmotor.move(Cata_Voltage); // move catapult until it reaches position from rotation sensor
            catarotationdegrees = Cata_Rotation.get_angle() / 100; //check the catapult position while moving
      } 
    }  
    void Catapult::park() {
        //move catapult to parked position when using only intake/outtake
    }
    void Catapult::run() {
        //run the catapult
        Catapultmotor.move(Cata_Voltage);
    }
    void Catapult::stop() {
        Catapultmotor.brake();
    }