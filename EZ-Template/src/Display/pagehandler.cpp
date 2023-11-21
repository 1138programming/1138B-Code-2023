#include "screen.h"
#include "api.h"
#include "liblvgl/lvgl.h"
#include "pagehandler.h"
bool threadRunning;
void pageHandler(int page) {
    pros::Task debugtask(UpdateDebug);
    switch (page) {
    case 0:
        initScreen();
        debugtask.suspend();
        break;
    case 1:
        autonSelectorNew();
        debugtask.suspend();
        
        break;
    case 2:
        debugScreen();
        
        break;
}
}

