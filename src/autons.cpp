#include "vex.h"
#include "functions.h"
#include "Constants.h"
#include "Vision.h"
void default_constants(){
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
}



void driveForward() {
  chassis.turn_settle_time = 0.2;
  chassis.drive_settle_time = 0.2;
  chassis.set_turn_constants(12, .25, .02, 5, 15);
  chassis.set_drive_constants(12, .25, .02, 5, 15);
  chassis.drive_distance(-52);
}
void VisionOdomTest() {
  chassis.turn_settle_time = 0.2;
  chassis.drive_settle_time = 0.2;
  chassis.set_turn_constants(12, .25, .02, 5, 15);
  chassis.set_drive_constants(12, .25, .02, 5, 15);
  Vision::Update(Eye__SIG_1);
  double currentHeading = fmod(chassis.get_absolute_heading(), 360.0);
  chassis.turn_to_angle(currentHeading + Vision::GetTrtgtxCord() );
  while (Vision::GetTrtgtDist() > IntakeStoppingDist && chassis.get_Y_position() < 60) {
    Vision::Update(Eye__SIG_1);
    chassis.drive_distance(10);
  }
  IntakeControls::run();
  while (!Vision::ObjectsExist()) {
    Vision::Update(Eye__SIG_2);
    currentHeading = fmod(chassis.get_absolute_heading(), 360.0);
    chassis.turn_to_angle(currentHeading - 15);
  }
  currentHeading = fmod(chassis.get_absolute_heading(), 360.0);
  chassis.turn_to_angle(currentHeading + Vision::GetTrtgtxCord() );
  while (Vision::GetTrtgtDist() > IntakeStoppingDist && chassis.get_Y_position() < 60) {
    Vision::Update(Eye__SIG_2);
    chassis.drive_distance(10);
  }
  IntakeControls::back();

}
void ThreeBallV2() {
  chassis.turn_settle_time = 0.2;
  chassis.drive_settle_time = 0.2;
  chassis.set_turn_constants(12, .25, .02, 5, 15);
  chassis.drive_distance(52);
  chassis.turn_to_angle(90);
  chassis.drive_distance(6.25);
  chassis.drive_distance(-2.5);
  chassis.turn_to_angle(326);
  IntakeControls::run();
  chassis.drive_distance(8);
  chassis.turn_to_angle(90);
  chassis.drive_distance(11.5);
  chassis.drive_distance(-25);
  chassis.turn_to_angle(295);
  IntakeControls::run();
  chassis.drive_distance(3);
  IntakeControls::stop();
  chassis.turn_to_angle(94);
  chassis.drive_distance(27);
}

void AttackingMatchAutonSkeletoncodeRouteTwo() {
  
}

void AttackingMatchAutonSkeletoncodeRouteOne() {
  chassis.turn_settle_time = 0.2;
  chassis.drive_settle_time = 0.2;
  chassis.set_turn_constants(6, .25, .02, 5, 15);
  chassis.drive_distance(52);
  turnrelativeangle(90);
}
void OffMatchAutonSkeletoncode() {
  chassis.turn_settle_time = 0.2;
  chassis.drive_settle_time = 0.2;
  chassis.drive_max_voltage = 10;
  
  chassis.set_turn_constants(6, .25, .02, 5, 15);

  Wings.set(false);

  chassis.drive_to_point(0,-45);

  chassis.turn_to_angle(270);

  chassis.drive_distance(16); // push it in
  //second
  chassis.drive_distance(-25);
 
  chassis.turn_to_angle(315);
  chassis.drive_distance(-52);
   Wings.set(true);
  chassis.drive_distance(-13);
 
  
  chassis.drive_distance(-10,270);
  Turn180();
  chassis.drive_distance(-30);
 



}
void JustdowinpointOffWorking() {
  chassis.turn_settle_time = 0.2;
  chassis.drive_settle_time = 0.2;
  chassis.drive_max_voltage = 10;
  chassis.set_turn_constants(6, .25, .02, 5, 15);
  // chassis.turn_to_angle(280);
  // chassis.drive_distance(-17);
  // chassis.turn_to_angle(45);
  Wings.set(true);
  

  chassis.drive_distance(-12);


  // chassis.drive_distance(-18);
  chassis.drive_distance(-10,315);
  
  chassis.drive_distance(-13);

  chassis.drive_distance(9);
  chassis.drive_distance(-12);
  chassis.drive_distance(9);
  chassis.drive_distance(-12);
  // chassis.drive_with_voltage(-10,-10);
  // wait(500,msec);
  // chassis.drive_with_voltage(0,0);
  // chassis.drive_distance(9);
  // chassis.drive_with_voltage(-10,-10);
  // wait(500,msec);
  // chassis.drive_with_voltage(0,0);


//   chassis.turn_to_angle(9);
//   // // chassis.drive_distance(10);
//   // turnrelativeangle(10);
//   chassis.drive_distance(35);
//   Wings.set(false);
//  chassis.turn_to_angle(45);
//   Turn180(); 
//   chassis.drive_distance(-23);

}
void JustdowinpointDeffworking() { // maybe
  chassis.turn_settle_time = 0.2;
  chassis.drive_settle_time = 0.2;
  chassis.drive_max_voltage = 10;
 chassis.set_turn_constants(6, .25, .02, 5, 15);
  // chassis.turn_to_angle(280);
  // chassis.drive_distance(-17);
  // chassis.turn_to_angle(45);
  chassis.drive_distance(43,1); //42,0

   chassis.drive_with_voltage(8,8);
   wait(500,msec);
   chassis.drive_with_voltage(0,0);
   wait(50,msec);
  //  chassis.drive_distance(-6);
  //  chassis.drive_with_voltage(8,8);
  // wait(500,msec);
  // chassis.drive_with_voltage(0,0);
  // wait(50,msec);
  chassis.drive_distance(-2);
  chassis.turn_to_angle(30);
  chassis.drive_distance(-20,2);
 
  Wings.set(true);
  
  
  chassis.drive_distance(-24,356);
  
  
  // chassis.drive_distance(-18);
  // chassis.drive_distance(-10,40);
  
  // chassis.drive_distance(-12);
  // chassis.drive_distance(8);
  // chassis.drive_distance(-12);
  // chassis.drive_distance(-18);
  // turnrelativeangle(-45);

  // chassis.drive_distance(25);

  Wings.set(false);
 chassis.turn_to_angle(303);
 chassis.drive_distance(-39);

  
  



}
void SkillsAuton() {
  chassis.drive_distance(20);
  chassis.drive_distance(-20);
  chassis.turn_to_angle(315);
  Catapult.spin(forward, 85, percent);

}

void WinPointAuton() {
  //setup
  chassis.turn_settle_time = 0.2;
  chassis.drive_settle_time = 0.2;
  chassis.set_turn_constants(6, .25, .02, 5, 15);
  chassis.drive_distance(52); //drive to the goal
  chassis.turn_to_angle(270); // turn to the goal
  chassis.drive_timeout = 5;
  chassis.drive_distance(14); // score
  chassis.drive_timeout = 0;
  chassis.drive_distance(-14); //backup
  chassis.turn_to_angle(170);
  chassis.drive_distance(45,270);
  chassis.drive_distance(15,90);
}

void rd_winpoint_code() {
  chassis.turn_settle_time = 0.2;
  chassis.drive_settle_time = 0.2;
  chassis.set_turn_constants(6, .25, .02, 5, 15);
  chassis.drive_distance(30,45);
  chassis.drive_distance(-18);
  Wings.set(true);
  chassis.drive_distance(-12,315);
  chassis.drive_distance(-10, 325);
  Wings.set(false);
  chassis.turn_to_angle(150);
  chassis.drive_distance(36);
  Blocker.set(true);
} 

void bd_winpoint_code() {
  chassis.turn_settle_time = 0.2;
  chassis.drive_settle_time = 0.2;
  chassis.set_turn_constants(6, .25, .02, 5, 15);
  chassis.drive_distance(30,45);
  chassis.drive_distance(-18);
  Wings.set(true);
  chassis.drive_distance(-12,315);
  chassis.drive_distance(-10, 325);
  Wings.set(false);
  chassis.turn_to_angle(150);
  chassis.drive_distance(36);
  Blocker.set(true);
}

void bo_6ball_code() {
  chassis.turn_settle_time = 0.2;
  chassis.drive_settle_time = 0.2;
  chassis.set_turn_constants(6, .25, .02, 5, 15);
  Blocker.set(true);
  vex::wait(100,msec);
  Blocker.set(false);
  Intake.spin(fwd,100,percent); //start intake
  chassis.drive_distance(26); // drive to 1st triball
  chassis.drive_distance(-42); // drive back
  chassis.turn_to_angle(330); //turn to push the preload
  Wings.set(true); // drop the wings
  chassis.drive_distance(-12,310); // push the preload a little bit towards the goal
  chassis.drive_distance(-5,280);
  chassis.drive_distance(-15, 270);
  Wings.set(false); // raise the wings
  chassis.drive_distance(5);
  chassis.turn_to_angle(110);
  Intake.spinFor(reverse,500,msec); // outtake
  chassis.drive_timeout = 750;
  chassis.drive_distance(20);
  chassis.drive_timeout = 2000;
  chassis.drive_distance(-15);
  chassis.turn_to_angle(0);
  
  // chassis.turn_to_angle(45);
  Intake.spin(fwd,100,percent);
  chassis.drive_distance(60, 47);
  chassis.turn_to_angle(180);
  // Intake.spinFor(reverse,500,msec);
  // Turn180();
  // Wings.set(true);
  chassis.drive_timeout = 1200;
  chassis.drive_distance(35);
  chassis.drive_distance(-24);
  chassis.turn_to_angle(312);
  chassis.drive_distance(16);
  chassis.drive_distance(-16);
  chassis.turn_to_angle(180);
  chassis.drive_distance(25);
  // chassis.turn_to_angle(90);
  // Intake.spin(fwd,100,percent); //start intake
  // chassis.drive_distance(15);
  // turnrelativeangle(180);
  // chassis.drive_distance(-20);
}