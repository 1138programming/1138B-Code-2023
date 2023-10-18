#include "vex.h"

class IntakeControls {
  public:
    static void init();
    static void run();
    static void back(); 
    static void stop();   
};

extern void HangCB();
extern void WingsCB();
extern void BlockerCB();
extern void Turn180();
extern void turnrelativeangle(float angle);