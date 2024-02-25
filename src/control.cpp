#include "main.h"

void baseControl() {

int drive = master.get_analog(ANALOG_LEFT_Y); // get left joystick
int turn = master.get_analog(ANALOG_RIGHT_X); // get right joystick
left_side = drive + turn ; // set the left motor group
right_side = drive - turn; // set the right motor group

}

void setDriveBrake(pros::motor_brake_mode_e_t mode) {
    left_side.set_brake_modes(mode);
    right_side.set_brake_modes(mode);
}
static bool kickerState{false};
void kickerControl() {
  if (master.get_digital_new_press(DIGITAL_Y)) {
    kickerState = !kickerState;
  }
  if (kickerState) {
    kicker.move(127);
  }
  else {
    kicker.move(0);
  }
}

void intakeControl() {
  if (master.get_digital(DIGITAL_R2)) {
    intake.move(127);
  }
  else if (master.get_digital(DIGITAL_R1)) {
    intake.move(-127);
  }
  else {
    intake.move(0);
  }
}

static bool hangState{false};
//pneumatic control
void pneumaticControl() {
  // toggle states
  //wings.set_value(master.get_digital(DIGITAL_L1));
  leftWing.set_value(master.get_digital(DIGITAL_L1));
  rightWing.set_value(master.get_digital(DIGITAL_L2));
  if (master.get_digital_new_press(DIGITAL_A)) {
    hang.set_value(!hangState);
    hangState = !hangState;
  }
}