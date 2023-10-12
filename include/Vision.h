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
       static double GetTrtgtDist();
       static double GetTrtgtxCord();
       static double GetTrtgtyCord();
       static bool ObjectsExist();
       private:
        static long Count;
        static double Obxcord;
        static double Obycord;
        static double LargestDist;
        static int IndexofTarget;
        
        
    };
#ifdef __cplusplus

#endif
#endif 
