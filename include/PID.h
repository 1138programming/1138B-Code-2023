#include "api.h"
#ifndef PID_h
#define PID_h
#ifdef __cplusplus
extern "C" {
#endif

class PID {
    
    public:
    PID(double setpoint, double Kp, double Ki, double Kd, double outputMax, double outputMin, double allowedError);
    double setSetpoint(double setpoint);
    double calculate(double process_var);
  
    private:
    double setpoint;

    double Kp = 0.0;
    double Ki = 0.0;
    double Kd = 0.0;

    double error = 0;
    double previousIntegral = 0;
    double previousError = 0;

    double outputMin = 0;
    double outputMax = 0;

    double bias = 0;
    double allowedError = 0.001;

    std::uint32_t iterationTime = 0; // PLEASE change this to use UNIX time on the actual bot code, I'm just doing this to write it rn.
    std::uint32_t lastMillis = 1;

    double abs(double num);
};
#ifdef __cplusplus
}
#endif
#endif