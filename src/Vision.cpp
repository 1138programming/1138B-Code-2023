#include "vex.h"
#include "Vision.h"
#include "Constants.h"
#include "robot-config.h"
#include <math.h>   



Vision::Vision() {


    IndexofTarget = 0;
    

    Obycord = Eye.objects[IndexofTarget].height;
    Obxcord = Eye.objects[IndexofTarget].angle; 
    Count = Eye.objectCount;
    LargestDist = 0;
    
    
    
}
void Vision::Update(signature Sig) {
    Eye.takeSnapshot(Sig);
    double Objectssize[Count];
    for (int i = 0; i < Count; i++) {
        if (Vision::Getdist(i) > LargestDist) {
            LargestDist = Vision::Getdist(i);
            IndexofTarget = i;
        }
        Objectssize[i] = Vision::Getdist(i);
    }

}
bool Vision::ObjectsExist() {
    return Eye.objectCount > 0;
}

double Vision::Getdist(int Obnum) {

    return tan(Eye.objects[Obnum].height * (Vres/VFOV))*Height; 
}

double Vision::GetTrtgtDist() {
    return Vision::Getdist(IndexofTarget);
}
double Vision::GetTrtgtxCord() {
    return Eye.objects[IndexofTarget].angle * (Hres/HFOV); 
}
double Vision::GetTrtgtyCord() {
    return Eye.objects[IndexofTarget].angle * (Hres/HFOV); 
}
     


