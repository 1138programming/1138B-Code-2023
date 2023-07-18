/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    9, 10, 3, 4, 20 
// Controller1          controller                    
// Intake               motor         7               
// IntakeSolenoid       digital_out   A               
// Catapult             motor         18              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "drive.h"
#include "functions.h"
#include "v5lvgl.h"
using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here
// define your global instances of motors and other devices here
lv_obj_t * myButton;
lv_obj_t * myButtonLabel;

static void btn_click_action(lv_event_t * event) {
    lv_event_code_t code = lv_event_get_code(event);

    if(code == LV_EVENT_CLICKED)
    {
  		lv_label_set_text(myButtonLabel, "clicked");
    }

    return ;
}

int demo() {
    /*Init the pressed style*/
    static lv_style_t style_pr;
    lv_style_init(&style_pr);
    lv_style_set_bg_color(&style_pr, lv_palette_darken(LV_PALETTE_BLUE, 3));

    myButton = lv_btn_create(lv_scr_act()); //create button, lv_scr_act() is deafult screen object
    lv_obj_add_event_cb(myButton, btn_click_action, LV_EVENT_ALL, NULL); //set function to be called on button click
    lv_obj_add_style(myButton, &style_pr, LV_STATE_PRESSED);
    lv_obj_set_size(myButton, 200, 50); //set the button size
    lv_obj_align(myButton, LV_ALIGN_TOP_LEFT, 10, 10); //set the position to top mid

    myButtonLabel = lv_label_create(myButton); //create label and puts it inside of the button
    lv_label_set_text(myButtonLabel, "Click the Button"); //sets label text
    lv_obj_center(myButtonLabel);

    return(0);
}
/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Intake.setStopping(coast);
  Intake.setVelocity(100, percent);
  Catapult.setMaxTorque(100,percent);
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    Drive::controller(Controller1);
    if (Controller1.ButtonR1.pressing()) {
      Intake.spin(forward);
    }
    else if (Controller1.ButtonR2.pressing()) {
      Intake.spin(reverse);
    }
    else {
      Intake.stop();
    }
    Controller1.ButtonY.pressed(IntakeSolenoidUp);
    Controller1.ButtonB.pressed(IntakeSolenoidDown);
    if (Controller1.ButtonL1.pressing()) {
      Catapult.spin(forward);
    }
    else {
      Catapult.stop();
    }
    
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
  
    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................
    
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();
  v5_lv_init();
  demo();
  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
