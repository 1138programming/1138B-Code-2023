#include "display/lvgl.h"
#include <stdint.h>
#include "display/lv_conf.h"
#include "screens.h"
#include "pagehandler.h"

void pageHandler(int page) {
    switch (page){
        case 0:
        homescreen();
        break;
        case 1:
        autonselector();
        break;
        case 2:
        debugScreen();
        break;
    }
}

