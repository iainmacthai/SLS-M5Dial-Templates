#include "M5Dial.h"
#include <Arduino.h>
#include <lvgl.h>
#include <Wire.h>
#include <SPI.h>
#include "ui.h"
#include "ui_helpers.h"

// Hardware Configuration
const int Port_B_LedPin1 = 1;  // GPIO 1 on Port B (white cable)
const int Port_B_LedPin2 = 2;  // GPIO 2 on Port B (yellow cable)

// Display Configuration
#define EXAMPLE_LCD_H_RES 240
#define EXAMPLE_LCD_V_RES 240
#define LV_VER_RES_MAX 240
#define LV_HOR_RES_MAX 240

// LVGL Display Variables
static lv_disp_draw_buf_t draw_buf;      // Display buffer
static lv_disp_drv_t disp_drv;           // Display driver descriptor
static lv_indev_drv_t indev_drv;         // Touch driver descriptor
M5GFX* tft = nullptr;                    // Display object pointer

/**
 * Initialize LVGL and display buffers
 */
void tft_lv_initialization() {
    lv_init();
    
    // Declare buffers for 1/10 of screen size (double buffering)
    static lv_color_t buf1[(LV_HOR_RES_MAX * LV_VER_RES_MAX) / 10];
    static lv_color_t buf2[(LV_HOR_RES_MAX * LV_VER_RES_MAX) / 10];
    
    // Initialize display buffer with the buffers
    lv_disp_draw_buf_init(&draw_buf, buf1, buf2, (LV_HOR_RES_MAX * LV_VER_RES_MAX) / 10);
    
    // Assign M5Dial LCD to our tft pointer
    tft = &M5Dial.Lcd;
}

/**
 * Display flushing callback for LVGL
 * @param disp Pointer to display driver
 * @param area Area to flush
 * @param color_p Pointer to color data
 */
void my_disp_flush(lv_disp_drv_t* disp, const lv_area_t* area, lv_color_t* color_p) {
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);
    
    tft->startWrite();
    tft->setAddrWindow(area->x1, area->y1, w, h);
    tft->pushColors((uint16_t*)&color_p->full, w * h, true);
    tft->endWrite();
    
    lv_disp_flush_ready(disp);  // Inform LVGL flushing is done
}

/**
 * Initialize LVGL display driver
 */
void init_disp_driver() {
    lv_disp_drv_init(&disp_drv);          // Basic initialization
    disp_drv.flush_cb = my_disp_flush;    // Set flush callback
    disp_drv.draw_buf = &draw_buf;        // Assign display buffer
    disp_drv.hor_res = LV_HOR_RES_MAX;    // Set horizontal resolution
    disp_drv.ver_res = LV_VER_RES_MAX;    // Set vertical resolution
    
    lv_disp_drv_register(&disp_drv);                     // Register the driver
    lv_disp_set_bg_color(NULL, lv_color_hex3(0x000));    // Set black background
}

/**
 * Touchpad read callback for LVGL
 * @param drv Pointer to input device driver
 * @param data Pointer to data to be filled
 */
void my_touchpad_read(lv_indev_drv_t* drv, lv_indev_data_t* data) {
    uint32_t currentTime = millis();
    M5.Touch.update(currentTime);

    if (M5.Touch.getCount() > 0) {
        auto pos = M5.Touch.getDetail();
        data->state = LV_INDEV_STATE_PRESSED;
        data->point.x = pos.x;
        data->point.y = pos.y;
    } else {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}

/**
 * Initialize LVGL touch driver
 */
void init_touch_driver() {
    lv_disp_drv_register(&disp_drv);
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_t* my_indev = lv_indev_drv_register(&indev_drv);  // Register driver
}

/**
 * Blink LED on GPIO 1 twice (100ms intervals)
 * @param e LVGL event pointer
 */
void SLS_Function_1(lv_event_t* e) {
    digitalWrite(Port_B_LedPin1, HIGH);
    delay(100);
    digitalWrite(Port_B_LedPin1, LOW);
    delay(100);
    digitalWrite(Port_B_LedPin1, HIGH);
    delay(100);
    digitalWrite(Port_B_LedPin1, LOW);
}

/**
 * Blink LED on GPIO 2 twice (100ms intervals)
 * @param e LVGL event pointer
 */
void SLS_Function_2(lv_event_t* e) {
    digitalWrite(Port_B_LedPin2, HIGH);
    delay(100);
    digitalWrite(Port_B_LedPin2, LOW);
    delay(100);
    digitalWrite(Port_B_LedPin2, HIGH);
    delay(100);
    digitalWrite(Port_B_LedPin2, LOW);
}

/**
 * Arduino setup function - runs once at startup
 */
void setup() {
    // Initialize M5Dial hardware
    auto cfg = M5.config();
    M5Dial.begin(cfg, true, false);
    M5Dial.Display.setBrightness(80);
    
    // Initialize serial communication
    Serial.begin(115200);
    
    // Initialize display and touch interfaces
    tft_lv_initialization();
    init_disp_driver();
    init_touch_driver();
    
    // Initialize UI (from ui.h)
    ui_init();
    
    // Configure LED pins
    pinMode(Port_B_LedPin1, OUTPUT);
    pinMode(Port_B_LedPin2, OUTPUT);
    
    // Test LEDs at startup
    digitalWrite(Port_B_LedPin1, HIGH);
    digitalWrite(Port_B_LedPin2, HIGH);
    delay(2000);
    digitalWrite(Port_B_LedPin1, LOW);
    digitalWrite(Port_B_LedPin2, LOW);
}

/**
 * Arduino main loop - runs continuously
 */
void loop() {
    uint32_t wait_ms = lv_timer_handler();  // Handle LVGL tasks
    M5.delay(wait_ms);                     // Delay for next LVGL cycle
    M5Dial.update();                       // Update M5Dial hardware state
}