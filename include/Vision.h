#ifndef Vision_h
#define Vision_H
#ifdef __cplusplus

#endif
#include "vex.h"
    class Vision {
        Vision();
       public:
       static double Getoffset();
       static double Getdist(int Obnum);
       static void Update(signature Sig);
       static double GetTrtgtDist(void* you);
       static double GetTrtgtxCord();
       static double GetTrtgtyCord();
       static bool ObjectsExist();
       private:
        inline static long Count;
        inline static double Obxcord;
        inline static double Obycord;
        inline static double LargestDist;
        inline static int IndexofTarget;
        
        
    };
// #ifdef __cplusplus

// #endif
#endif 
