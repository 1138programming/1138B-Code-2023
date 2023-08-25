#include "vex.h"
#include "Vision.h"


Vision::Vision() {
    
    Eye.takeSnapshot(Eye__SIG_1);

    Obxcord = Eye.objects[0].angle;
    Count = Eye.objectCount;

}

double Vision::Getdist() {
    //return Tan(OBxcord * (400/FOV))*height
};
