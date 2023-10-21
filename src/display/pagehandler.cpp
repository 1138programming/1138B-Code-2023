#include "display/screen.h"
#include "v5lvgl.h"
#include "vex.h"
#include "display/pagehandler.h"
bool threadRunning;
void pageHandler(int page) {
    vex::thread DebugUpdater(UpdateDebug);
    switch (page) {
    case 0:
        initScreen();
        DebugUpdater.interrupt();
        break;
    case 1:
        autonSelectorNew();
        DebugUpdater.interrupt();
        break;
    case 2:
        debugScreen();
        break;
}
}