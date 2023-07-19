extern void IntakeSolenoidUp(void);
extern void IntakeSolenoidDown(void);

class IntakeCommands {
  public:
    static void Run();
    static void Reverse();
};