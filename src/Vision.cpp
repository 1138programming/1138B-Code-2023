#include "vex.h"
#include "Vision.h"
#include "math.h"

Vision::Vision() {
    
    Eye.takeSnapshot(Eye__SIG_1);

    Obycord = Eye.objects[0].height;
    Count = Eye.objectCount;

}

double Vision::Getdist() {
    double height = 8;
    double FOV = 20;
    return tan(Obycord * (400/FOV))*height;
    
};
