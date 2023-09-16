#include "vex.h"

class IntakeControls {
  public:
    static void init();
    static void run();
    static void back();    
};

extern void RightWingCB();
extern void LeftWingCB();
extern void HangCB();
extern void BothWingsCB();
extern void Intake2Wings();