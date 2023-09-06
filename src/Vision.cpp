#include "vex.h"
#include "Vision.h"
#include "Constants.h"
#include <math.h>      

Vision::Vision() {
    
    Eye.takeSnapshot(Eye__SIG_1);

    Obycord = Eye.objects[0].height;
    Obxcord = Eye.objects[0].angle; 
    Count = Eye.objectCount;

}

double Vision::Getdist() {

    return tan(Obycord * (400/FOV))*Height; 
};

