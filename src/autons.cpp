#include "vex.h"
#include "functions.h"
#include "Constants.h"
#include "Vision.h"
void default_constants(){
  chassis.set_drive_constants(12, 1.5, 0, 10, 0);
  chassis.set_heading_constants(12, .4, 0, 1, 0);
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
  chassis.set_drive_constants(12, 1, 0, 1.5, 0);
  chassis.set_heading_constants(12, .25, 0, 1, 0);
  chassis.set_turn_constants(12, 0.23, 0, 1, 0);
  chassis.drive_settle_time = 150;
  chassis.turn_settle_time = 150;
  chassis.drive_distance(-28,45);
  chassis.drive_distance(18, 0);
  chassis.left_swing_to_angle(300);
  Wings.set(true);
  Catapult.resetPosition();
  Catapult.setVelocity(100,percent);
  Catapult.spinTo((360*12),degrees, true);
  Wings.set(false);
  chassis.drive_distance(30,0);
  chassis.turn_to_angle((180-45));
  chassis.drive_distance(-80);
  Wings.set(true);
  chassis.drive_distance(-48, 45);
  chassis.drive_distance(10);
  chassis.drive_distance(-10);

}
void rd_winpoint_code() {
  chassis.set_drive_constants(12, 1, 0, 1.5, 0);
  chassis.set_heading_constants(12, .25, 0, 1, 0);
  chassis.set_turn_constants(12, 0.23, 0, 1, 0);
  chassis.drive_settle_time = 0.2;
  chassis.turn_settle_time = 0.2;
  chassis.drive_timeout = 750;
  chassis.turn_timeout = 500;
  chassis.drive_distance(30,45);
  chassis.drive_distance(-20);
  Wings.set(true);
  chassis.drive_distance(-12,315);
  chassis.drive_distance(-12, 325);
  Blocker.set(true);
  Wings.set(false);
  chassis.drive_distance(-36);
} 


void bo_6ball_code() {
  chassis.set_drive_constants(12, 1, 0, 1.5, 0);
  chassis.set_heading_constants(12, .25, 0, 1, 0);
  chassis.set_turn_constants(12, 0.23, 0, 1, 0);
  chassis.drive_settle_time = 0;
  chassis.turn_settle_time = 0;
  Blocker.set(true);
  vex::wait(100,msec);
  Blocker.set(false);
  Intake.spin(fwd,100,percent); //start intake
  chassis.drive_distance(6); // drive to 1st triball
  chassis.drive_distance(-40); // drive back
  chassis.turn_timeout = 500;
  chassis.turn_to_angle(330); //turn to push the preload
  Wings.set(true); // drop the wings
  chassis.heading_kp = 1.3;
  chassis.heading_kd = 1.5;
  chassis.drive_distance(-12,310); // push the preload a little bit towards the goal
  chassis.heading_kp = 0.25;
  chassis.heading_kd = 1;
  chassis.drive_distance(-5,280);
  chassis.drive_timeout = 500;
  chassis.drive_distance(-18, 270);
  chassis.drive_timeout = 1500;
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
  chassis.drive_distance(60, 43);;
  chassis.turn_to_angle(160);
  // Intake.spinFor(reverse,500,msec);
  // Turn180();
  // Wings.set(true);
  chassis.drive_timeout = 1200;
  chassis.drive_distance(38, 180);
  chassis.drive_distance(-24);
  chassis.turn_to_angle(305);
  chassis.drive_distance(24);
  chassis.drive_distance(-16);
  chassis.turn_to_angle(170);
  chassis.drive_distance(30);
  // chassis.turn_to_angle(90);
  // Intake.spin(fwd,100,percent); //start intake
  // chassis.drive_distance(15);
  // turnrelativeangle(180);
  // chassis.drive_distance(-20);
}

void pidTest() {
  chassis.set_drive_constants(12, 1, 0, 1.5, 0);
  chassis.set_heading_constants(12, .25, 0, 1, 0);
  chassis.set_turn_constants(12, 0.23, 0, 1, 0);
  chassis.drive_settle_time = 0;
  chassis.turn_settle_time = 0;
  // chassis.turn_to_angle(90);
  // chassis.drive_distance(12);
  // chassis.turn_to_angle(0);
  // chassis.drive_distance(36);
  // chassis.drive_distance(-24);
  chassis.drive_distance(26, 270);
}