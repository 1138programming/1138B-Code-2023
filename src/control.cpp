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

// leds
static bool ledSet{true};

void ledDefault(int type) {
    if (type == 1) { 
    baseLeds.gradient(0x191ca8, 0xff8605);
    intakeLeds.gradient(0x191ca8, 0xff8605);
    }
    else if (type == 2) {
        baseLeds.gradient(0x00000, 0xff0000);
    }
    baseLeds.cycle(*baseLeds, 10);
    intakeLeds.cycle(*intakeLeds, 10);
}

void ledBowling() {
    baseLeds.set_all(0x00ff4c);
}

void ledMatchload() {
    baseLeds.set_all(0xf4fc03);
}

void ledOuttake() {
    intakeLeds.set_all(0x191ca8);
}


void intakeControl() {
    if (master.get_digital(DIGITAL_R2)) {
        intake.move(127);
    }
    else if (master.get_digital(DIGITAL_R1)) {
        intake.move(-127);
    }
    else {
        intake.brake();
    }
}

void flywheelControl() {
     //flywheel control
    if (master.get_digital(DIGITAL_B))
    {
      flywheel.set_velocity_custom_controller(450);
      //run fw pid
      master.print(1,1,"RPM: %f", flywheel.get_velocity());
      ledMatchload();
      ledSet = false;
    }
    else if (master.get_digital(DIGITAL_DOWN))
    {
      flywheel.set_velocity_custom_controller(-300);
      //run fw pid
      ledBowling();
      ledSet = false;
    }
    else if (master.get_digital(DIGITAL_UP)) {
      flywheel.set_velocity_custom_controller(600);
      if(!ledSet) {
        ledDefault(1);
        ledSet = true;
      };
      flywheel.stop();
    }
    else {
      if(!ledSet) {
        ledDefault(1);
        ledSet = true;
      };
      flywheel.stop();
    }
}
static bool hangValue{false};
static bool balanceValue{false};
//pneumatic control
void pneumaticControl() {
  // toggle states
  wings.set_value(master.get_digital(DIGITAL_L1));
  if (master.get_digital_new_press(DIGITAL_Y)) {
      hang.set_value(!hangValue);
      hangValue = !hangValue;
  }
  if (master.get_digital_new_press(DIGITAL_A)) {
    balance.set_value(!balanceValue);
    balanceValue = !balanceValue;
  }
}