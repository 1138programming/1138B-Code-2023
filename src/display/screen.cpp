﻿#include "vex.h"
#include "v5lvgl.h"
#include "display/screen.h"
#include "Vision.h"
#include "display/pagehandler.h"
#include "robot-config.h"
#include "Constants.h"
#include <string>
extern "C" {
#include "display/images.h"

}


static const char* btn_map[] = { "1", "2", "\n", "3", "4", NULL };
lv_color32_t White = LV_COLOR_MAKE(255, 255, 255);
void clearScreen() {
    lv_obj_clean(lv_scr_act());
}
void initscreen() {
    lv_obj_t* img = lv_img_create(lv_scr_act());
    lv_img_set_src(img, &LogoScreen);
   
}
lv_obj_t* AutonTitle;
lv_obj_t* DebugNote;
static lv_style_t AutonStyle;
int CurrentAuton;
int getCurrentAuton() {
    return CurrentAuton;
}
static void AutonHandler(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* obj = lv_event_get_target(e);
    if (code == LV_EVENT_VALUE_CHANGED) {
        uint32_t id = lv_btnmatrix_get_selected_btn(obj);
        const char* txt = lv_btnmatrix_get_btn_text(obj, id);
        if (txt, "1") {
            CurrentAuton = 1;
        }
        if (txt, "2") {
            CurrentAuton = 2;
        }
        lv_label_set_text_fmt(AutonTitle, "Current Auton is: %s", txt);
        //LV_UNUSED(txt);
        //LV_LOG_USER("Current auton is: %s\n", txt);
    }
}

static void BackHandler(lv_event_t* e) {
    clearScreen();
    pageHandler(0);
}

void autonSelector() {

    lv_style_init(&AutonStyle);
    lv_style_set_text_color(&AutonStyle, White);
    lv_style_set_bg_opa(&AutonStyle, LV_OPA_TRANSP);
    lv_style_set_border_width(&AutonStyle, 0);
    lv_style_set_outline_width(&AutonStyle, 0);
    lv_obj_t* bg = lv_img_create(lv_scr_act());
    lv_img_set_src(bg, &background);
    lv_obj_t* back = lv_btn_create(lv_scr_act());
    lv_obj_set_size(back, 40, 40);
    lv_obj_t* backlabel = lv_label_create(back);
    lv_label_set_text(backlabel,"<-");
    lv_obj_align(back, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_add_event_cb(back, BackHandler, LV_EVENT_PRESSED, NULL);
    AutonTitle = lv_label_create(lv_scr_act());
    if (CurrentAuton == 0) {
        lv_label_set_text(AutonTitle, "No Auton Selected");
    }
    else {
        lv_label_set_text_fmt(AutonTitle, "Current Auton is: %i", CurrentAuton);
    }
    lv_obj_add_style(AutonTitle, &AutonStyle, 0);
    lv_obj_align(AutonTitle, LV_ALIGN_TOP_MID, 0, 10);
    lv_obj_t* AutonButtons = lv_btnmatrix_create(lv_scr_act());
    lv_btnmatrix_set_map(AutonButtons, btn_map);
    lv_btnmatrix_set_btn_ctrl_all(AutonButtons, LV_BTNMATRIX_CTRL_CHECKABLE);
    lv_btnmatrix_set_one_checked(AutonButtons, true);
    lv_obj_add_event_cb(AutonButtons, AutonHandler, LV_EVENT_ALL, NULL);
    lv_obj_align(AutonButtons, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_style(AutonButtons, &AutonStyle, LV_STATE_FOCUS_KEY);
}

lv_obj_t* CurrentAutonText;
lv_obj_t* Autonbg;
static void newAutonCB(lv_event_t* e) {
    // autonList
    // 1 = red defensive wp
    // 2 = blue defensive wp
    // 3 = red offensive 6 ball
    // 4 = blue offensive 6 ball
    lv_obj_t* selectedDD = lv_event_get_target(e);
    char buf[64];
    lv_dropdown_get_selected_str(selectedDD, buf, sizeof(buf));
    const char* starting_pos = lv_dropdown_get_text(selectedDD);
    lv_label_set_text_fmt(CurrentAutonText, "%s: %s", starting_pos, buf);
    if (strcmp(buf, "Winpoint") + strcmp(starting_pos, "Red Defensive") == 0) {
        lv_img_set_src(Autonbg, &rd_winpoint);
        CurrentAuton = 1;

    }
    else if (strcmp(buf, "Winpoint") + strcmp(starting_pos, "Blue Defensive") == 0) {
        lv_img_set_src(Autonbg, &bd_winpoint);
        CurrentAuton = 2;
    }
    else if (strcmp(buf, "6 Ball") + strcmp(starting_pos, "Red Offensive") == 0) {
        lv_img_set_src(Autonbg, &ro_6ball);
        CurrentAuton = 3;
    }
    else if (strcmp(buf, "6 Ball") + strcmp(starting_pos, "Blue Offensive") == 0) {
        lv_img_set_src(Autonbg, &bo_6ball);
        CurrentAuton = 4;
    }
    else {
        lv_img_set_src(Autonbg, &overunderfield);
    }
}

void autonSelectorNew() {
    clearScreen();
    Autonbg = lv_img_create(lv_scr_act());
    lv_img_set_src(Autonbg, &overunderfield);
    lv_obj_align(Autonbg, LV_ALIGN_CENTER, 0, 0);
    lv_obj_t* back = lv_btn_create(lv_scr_act());
    lv_obj_set_size(back, 40, 40);
    lv_obj_t* backlabel = lv_label_create(back);
    lv_label_set_text(backlabel,"<-");
    lv_obj_align(back, LV_ALIGN_LEFT_MID, 0, -25);
    lv_obj_add_event_cb(back, BackHandler, LV_EVENT_PRESSED, NULL);
    CurrentAutonText = lv_label_create(lv_scr_act());
    lv_label_set_text(CurrentAutonText, "No Auton Selected!");
    lv_obj_align(CurrentAutonText, LV_ALIGN_CENTER,0,0);
    lv_obj_t* bo = lv_dropdown_create(lv_scr_act());
    lv_dropdown_set_options(bo, "6 Ball");
    lv_dropdown_set_text(bo, "Blue Offensive");
    lv_obj_add_event_cb(bo, newAutonCB, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_t* bd = lv_dropdown_create(lv_scr_act());
    lv_dropdown_set_options(bd, "Winpoint");
    lv_dropdown_set_text(bd, "Blue Defensive");
    lv_obj_align(bd, LV_ALIGN_TOP_RIGHT,0,0);
    lv_obj_add_event_cb(bd,newAutonCB, LV_EVENT_VALUE_CHANGED,NULL);
    lv_obj_t* rd = lv_dropdown_create(lv_scr_act());
    lv_dropdown_set_options(rd, "Winpoint");
    lv_dropdown_set_text(rd, "Red Defensive");
    lv_dropdown_set_dir(rd, LV_DIR_TOP);
    lv_obj_align(rd, LV_ALIGN_BOTTOM_LEFT,0,0);
    lv_obj_add_event_cb(rd,newAutonCB, LV_EVENT_VALUE_CHANGED,NULL);
    lv_obj_t* ro = lv_dropdown_create(lv_scr_act());
    lv_dropdown_set_options(ro, "6 Ball");
    lv_dropdown_set_text(ro, "Red Offensive");
    lv_dropdown_set_dir(ro, LV_DIR_TOP);
    lv_obj_align(ro, LV_ALIGN_BOTTOM_RIGHT,0,0);
    lv_obj_add_event_cb(ro,newAutonCB, LV_EVENT_VALUE_CHANGED,NULL);
}
void debugScreen() {
    
    Vision::Update(Eye__SIG_1);
    lv_obj_t* bge = lv_img_create(lv_scr_act());
    lv_img_set_src(bge, &background);
    DebugNote = lv_label_create(lv_scr_act());
    lv_label_set_text_fmt(DebugNote, "AutonDist", Vision::GetTrtgtDist());
    lv_obj_t* backd = lv_btn_create(lv_scr_act());
    lv_obj_set_size(backd, 40, 40);
    lv_obj_t* backlabeld = lv_label_create(backd);
    lv_label_set_text(backlabeld,"<-");
    lv_obj_align(backd, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_align(DebugNote, LV_ALIGN_TOP_MID,0,0);
    lv_obj_add_event_cb(backd, BackHandler, LV_EVENT_PRESSED, NULL);
    lv_obj_t* CurrentAuton = lv_label_create(lv_scr_act());
    lv_label_set_text_fmt(CurrentAuton, "CurrentAuton: %i", getCurrentAuton());
    lv_obj_align(CurrentAuton, LV_ALIGN_TOP_RIGHT,0,0);
}


lv_obj_t* BravoLogo;
lv_obj_t* Debug;
lv_obj_t* Autonbtn;
// Define the button sequence to detect
lv_obj_t* BTN1;
lv_obj_t* BTN2;
lv_obj_t* BTN3;
lv_obj_t* BTN4;
int buttonSequence[] = { 0, 1, 2, 3 };
int currentStep = 0;

// Timer variable to track the elapsed time
lv_timer_t* sequenceTimer;
lv_timer_t* FadeTimer;
void timerCallback(lv_timer_t* timer) {
    // Reset the sequence tracking
    currentStep = 0;
}
void FadetimerCallback(lv_timer_t* timer) {
    clearScreen();
    pageHandler(1);
    lv_timer_del(timer);
    currentStep = 0;
}
void anim_ready_cb(lv_anim_t* anim) {
    // Check if the image has finished fading in
    if (lv_obj_get_style_opa((lv_obj_t *)anim->var, LV_PART_MAIN) == LV_OPA_TRANSP) {
        // Execute another function here
        LV_LOG("fade done...");
    }
}
// Button press callback
static void buttonPressCallback(lv_event_t* event) {
    if (lv_event_get_code(event) == LV_EVENT_CLICKED) {
        lv_obj_t* button = lv_event_get_target(event);
        int* btndata;
        btndata = (int*)lv_event_get_user_data(event);
        // LV_LOG("%d", *btndata);
    //     if (*btndata == buttonSequence[currentStep]) {
    //         currentStep++;
    //         if (currentStep == sizeof(buttonSequence) / sizeof(buttonSequence[0])) {
    //             // Sequence completed within 5 seconds
    //             // Perform the desired action here
    //             // For example, you can toggle a LED (replace this with your desired action)
    //             //lv_led_on(BTN4);
    //             LV_LOG("OK");
        if (*btndata == 3) {
        lv_obj_fade_out(BravoLogo, 500, 0);
        FadeTimer = lv_timer_create(FadetimerCallback, 500, NULL); // 5000 ms = 5 seconds
        lv_timer_enable(FadeTimer);
        pageHandler(1);
        }
    //             currentStep = 0; // Reset the sequence tracking for the next time
    //         }
        // Button press not in the expected sequence

        else  if (*btndata == 5) {
                pageHandler(2);
        }

    }
        
          

        
    
}

void initScreen() {

   
    

    lv_obj_t* BG = lv_img_create(lv_scr_act());
    lv_img_set_src(BG, &background);
    BravoLogo = lv_img_create(lv_scr_act());
    lv_img_set_src(BravoLogo, &LogoScreen);
    
    //debug
    Debug = lv_btn_create(lv_scr_act());
    lv_obj_set_size(Debug, 100,40);
    lv_obj_align(Debug, LV_ALIGN_CENTER, -200, 0);
    lv_obj_t* Debuglabel = lv_label_create(Debug);
    lv_label_set_text(Debuglabel,"Debug");
    

    // Auton button 
    Autonbtn = lv_btn_create(lv_scr_act());
    lv_obj_set_size(Autonbtn, 100, 40);
    lv_obj_align(Autonbtn, LV_ALIGN_CENTER, 200, 0);
    lv_obj_t* Autonlabel = lv_label_create(Autonbtn);
    lv_label_set_text(Autonlabel,"Auton");


    //button1
    // BTN1 = lv_btn_create(lv_scr_act());
    // lv_obj_remove_style_all(BTN1);
    // lv_obj_set_size(BTN1, 75, 75);
    // lv_obj_align(BTN1, LV_ALIGN_TOP_LEFT, 0, 0);
    
    // static int btn1_data = 0;
    // BTN2 = lv_btn_create(lv_scr_act());
    // lv_obj_remove_style_all(BTN2);
    // lv_obj_set_size(BTN2, 75, 75);
    // lv_obj_align(BTN2, LV_ALIGN_TOP_RIGHT, 0, 0);
    
    // static int btn2_data = 1;
    // BTN3 = lv_btn_create(lv_scr_act());
    // lv_obj_remove_style_all(BTN3);
    // lv_obj_set_size(BTN3, 75, 75);
    // lv_obj_align(BTN3, LV_ALIGN_BOTTOM_LEFT, 0, 0);
    
    // static int btn3_data = 2;
    // BTN4 = lv_btn_create(lv_scr_act());
    // lv_obj_remove_style_all(BTN4);
    // lv_obj_set_size(BTN4, 75, 75);
    // lv_obj_align(BTN4, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
    
    static int AutonData = 3;
    static int debug_data = 5;
    // Set button press callbacks for each button
    // lv_obj_add_event_cb(BTN1, buttonPressCallback, LV_EVENT_ALL, &btn1_data);
    // lv_obj_add_event_cb(BTN2, buttonPressCallback, LV_EVENT_ALL, &btn2_data);
    // lv_obj_add_event_cb(BTN3, buttonPressCallback, LV_EVENT_ALL, &btn3_data);
    lv_obj_add_event_cb(Autonbtn, buttonPressCallback, LV_EVENT_ALL, &AutonData);
    lv_obj_add_event_cb(Debug, buttonPressCallback, LV_EVENT_ALL, &debug_data);

    // Create and start the timer (5 seconds interval)
    // sequenceTimer = lv_timer_create(timerCallback, 5000, NULL); // 5000 ms = 5 seconds
    // lv_timer_enable(sequenceTimer);
}


