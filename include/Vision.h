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
        static inline long Count;
        static inline double Obxcord;
        static inline double Obycord;
        static inline double LargestDist;
        static inline int IndexofTarget;
        
        
    };
#ifdef __cplusplus

#endif
#endif 
