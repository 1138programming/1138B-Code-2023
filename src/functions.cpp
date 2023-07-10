#include "api.h"
#include "motors.h"
#include "Constants.h"
#include "functions.h"
#include "screens.h"
#include "pagehandler.h"

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
float Inatke_Voltage = 100;
float Outtake_Coefficient = 1;
float outtake_speed = 127;

        void Intake::run() {
            intakemotors.move(Inatke_Voltage);
        }
        void Intake::reverse() {
            intakemotors.move(-outtake_speed);
        }
        void Intake::stop() {
            intakemotors.move(0);
        }

//catapult
float Cata_Voltage = 90;
bool catainterupt;
pros::Rotation Cata_Rotation (CATA_ROT);

    void Catapult::init() {
        Catapultmotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD); // sets the catapult motor to hold
    }
    void Catapult::intake() {
        //move catapult to intake position
        float catarotationdegrees = Cata_Rotation.get_angle() / 100; //define the catapult rotation when the button is first pressed
        while (!inRange(1800, 1900, Cata_Rotation.get_angle())) {
            Catapultmotor.move(Cata_Voltage); // move catapult until it reaches position from rotation sensor
            catarotationdegrees = Cata_Rotation.get_angle() / 100; //check the catapult position while moving
      } 
    }  
    void Catapult::park() {
        //move catapult to parked position when using only intake/outtake
        float catarotationdegrees = Cata_Rotation.get_angle() / 100; //define the catapult rotation when the button is first pressed
        pageHandler(2);
            while (!inRange(34500, 34600, Cata_Rotation.get_angle())) {
            Catapultmotor.move(50); // move catapult until it reaches position from rotation sensor
            catarotationdegrees = Cata_Rotation.get_angle() / 100; //check the catapult position while moving
            //debugValues(1,Cata_Rotation.get_angle());
        }
        Catapultmotor.move(0);
    }
    void Catapult::run() {
        //run the catapult
        pageHandler(2);
        catainterupt = false;
        float catarotationdegrees = Cata_Rotation.get_angle() / 100; //define the catapult rotation when the button is first pressed
        Catapultmotor.move(Cata_Voltage);
        catarotationdegrees = Cata_Rotation.get_angle() / 100; //check the catapult position while moving
        debugValues(1,catarotationdegrees);
    }
    void Catapult::stop() {
        catainterupt = true;
        Catapultmotor.brake();
    }