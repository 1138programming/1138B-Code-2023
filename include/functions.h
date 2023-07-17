#ifndef function_h
#define function_h

class Intake {
    public:
        static void run();
        static void reverse();
        static void stop();
        static double getTorque();
        static double getRPMs();
        static void init();
};

class Catapult {
public:
    static void intake();
    static void park();
    static void run();
    static void stop();
    static double GetCatapultRot();
    static void init();
};
#endif