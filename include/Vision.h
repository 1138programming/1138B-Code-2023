#ifndef Vision_h
#define Vision_H
#ifdef __cplusplus
extern "C" {
#endif
#include "vex.h"
    class Vision {
        Vision();
       public:
       static double Getoffset();
       static double Getdist();
       private:
        long Count;
        static double Obxcord;
        static double Obycord;
    };
#ifdef __cplusplus
}
#endif
#endif 
