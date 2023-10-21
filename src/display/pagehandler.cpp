#include "display/screen.h"
#include "v5lvgl.h"
#include "display/pagehandler.h"
void pageHandler(int page) {
    switch (page) {
    case 0:
        initScreen();
        break;
    case 1:
        autonSelectorNew();
        break;
    case 2:
        debugScreen();
        break;
        
    }
}
