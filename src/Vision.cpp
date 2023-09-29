#include "vex.h"
#include "Vision.h"
#include "Constants.h"
#include <math.h>      

Vision::Vision() {
    IndexofTarget = 0;
    Eye.takeSnapshot(Eye__SIG_1);

    Obycord = Eye.objects[IndexofTarget].height;
    Obxcord = Eye.objects[IndexofTarget].angle; 
    Count = Eye.objectCount;
    LargestDist = 0;
    
    
    
}
void Vision::Update() {

    double Objectssize[Count];
    for (int i = 0; i < Count; i++) {
        if (Vision::Getdist(i) > LargestDist) {
            LargestDist = Vision::Getdist(i);
            IndexofTarget = i;
        }
        Objectssize[i] = Vision::Getdist(i);
    }

}

double Vision::Getdist(int Obnum) {

    return tan(Eye.objects[Obnum].height * (400/FOV))*Height; 
};

double Vision::GetTrtgtDisyt() {
    return Vision::Getdist(IndexofTarget);
}
double Vision::GetxCord() {
    return Eye.objects[IndexofTarget].angle; 
}


