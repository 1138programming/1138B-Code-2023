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
       static double Getdist(int Obnum);
       static void Update();
       static double GetTrtgtDisyt();
       static double GetxCord();
       private:
        static long Count;
        static double Obxcord;
        static double Obycord;
        static double LargestDist;
        static int IndexofTarget;
        
        
    };
#ifdef __cplusplus
}
#endif
#endif 
