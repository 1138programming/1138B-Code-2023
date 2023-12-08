#include "main.h"

void ledDefault(int type) {
    if (type == 1) { 
    base.gradient(0x191ca8, 0xff8605);
    intakeLEDS.gradient(0x191ca8, 0xff8605);
    }
    else if (type == 2) {
        base.gradient(0x00000, 0xff0000);
    }
    base.cycle(*base, 10);
    intakeLEDS.cycle(*intakeLEDS, 10);
}

void ledBowling() {
    base.set_all(0x00ff4c);
}

void ledMatchload() {
    base.set_all(0xf4fc03);
}

void ledOuttake() {
    intakeLEDS.set_all(0x191ca8);
}
