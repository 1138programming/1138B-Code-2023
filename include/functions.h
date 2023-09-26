#include "vex.h"

class IntakeControls {
  public:
    static void init();
    static void run();
    static void back();    
};

extern void HangCB();
extern void WingsCB();
extern void Turn180();