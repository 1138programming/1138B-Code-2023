#include "screen/screen.h"
#include "api.h"
#include "screen/pagehandler.h"
bool threadRunning;
void pageHandler(int page) {
    //vex::thread DebugUpdater(UpdateDebug);
    switch (page) {
    case 0:
        initScreen();
        //DebugUpdater.interrupt();
        break;
    case 1:
        autonSelectorNew();
        //DebugUpdater.interrupt();
        break;
    case 2:
        debugScreen();
        break;
}
}