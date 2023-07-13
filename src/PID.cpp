#include "main.h"
#include "PID.h"

  
    double PID::abs(double num) {
        return num < 0 ? -num : num;
    }


     void PID(double setpoint, double Kp, double Ki, double Kd, double outputMax, double outputMin, double allowedError) {
      
       std::uint32_t iterationTime = 0; // PLEASE change this to use UNIX time on the actual bot code, I'm just doing this to write it rn.
       std::uint32_t lastMillis = 1;
    }

    double PID::setSetpoint(double setpoint) {
      this->setpoint = setpoint;
    }

    double PID::calculate(double process_var) {

      iterationTime = pros::millis() - lastMillis;

      if (abs(setpoint - process_var) < allowedError) {
        return 0.0;
      }

      error = setpoint - process_var;

      double integral = previousIntegral + error * iterationTime;
      double derivative = (error - previousError) / iterationTime;

      double output = (Kp * error) + (Ki * integral) + (Kd * derivative) + (bias);

      this->previousError = error;
      this->previousIntegral = integral;

      // if (output > outputMax) {
      //   return outputMax;
      // }
      // else if (output < outputMin) {
      //   return outputMin;
      // }
      
      this->lastMillis = pros::millis();

      return output;
    }
