#include "M5Dial.h"
#include <Arduino.h>
#include <lvgl.h>
//#include <Wire.h>
#include <SPI.h>
#include "ui.h"
#include "ui_helpers.h"
#include "UNIT_8ENCODER.h"

UNIT_8ENCODER sensor;

// init the tft espi
static lv_disp_draw_buf_t draw_buf;
static lv_disp_drv_t disp_drv;  // Descriptor of a display driver
static lv_indev_drv_t indev_drv; // Descriptor of a touch driver

#define EXAMPLE_LCD_H_RES 240
#define EXAMPLE_LCD_V_RES 240
#define LV_VER_RES_MAX 240
#define LV_HOR_RES_MAX 240
M5GFX *tft;
#define WIRE Wire


void tft_lv_initialization() {
  lv_init();
  static lv_color_t buf1[(LV_HOR_RES_MAX * LV_VER_RES_MAX) / 10];  // Declare a buffer for 1/10 screen size
  static lv_color_t buf2[(LV_HOR_RES_MAX * LV_VER_RES_MAX) / 10];  // second buffer is optionnal
  // Initialize `disp_buf` display buffer with the buffer(s).
  lv_disp_draw_buf_init(&draw_buf, buf1, buf2, (LV_HOR_RES_MAX * LV_VER_RES_MAX) / 10);
  tft=&M5Dial.Lcd;
}

// Display flushing
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);
  tft->startWrite();
  tft->setAddrWindow(area->x1, area->y1, w, h);
  tft->pushColors((uint16_t *)&color_p->full, w * h, true);
  tft->endWrite();
  lv_disp_flush_ready(disp);
}

void init_disp_driver() {
  lv_disp_drv_init(&disp_drv);  // Basic initialization
  disp_drv.flush_cb = my_disp_flush;  // Set your driver function
  disp_drv.draw_buf = &draw_buf;      // Assign the buffer to the display
  disp_drv.hor_res = LV_HOR_RES_MAX;  // Set the horizontal resolution of the display
  disp_drv.ver_res = LV_VER_RES_MAX;  // Set the vertical resolution of the display
  lv_disp_drv_register(&disp_drv);                   // Finally register the driver
  lv_disp_set_bg_color(NULL, lv_color_hex3(0x000));  // Set default background color to black
}

void my_touchpad_read(lv_indev_drv_t * drv, lv_indev_data_t * data)
{
  uint32_t currentTime = millis(); 
  M5.Touch.update(currentTime);

  if(M5.Touch.getCount() > 0)
  {

 
  auto pos = M5.Touch.getDetail();
    data->state = LV_INDEV_STATE_PRESSED; 
    data->point.x = pos.x;
    data->point.y = pos.y;
  }
  else
  {
 data->state = LV_INDEV_STATE_RELEASED;
  }
}

void init_touch_driver() {
  lv_disp_drv_register(&disp_drv);
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_t * my_indev = lv_indev_drv_register(&indev_drv);  // register
}

void setup()
{
  auto cfg = M5.config();
  M5Dial.begin(cfg, true, false);
  M5Dial.Display.setBrightness(80);
  Serial.begin(115200);
  tft_lv_initialization();
  init_disp_driver();
  init_touch_driver();
  ui_init();

  WIRE.begin(13,15);
  sensor.begin(&Wire, ENCODER_ADDR, 13, 15, 100000UL);
}


void loop()
{
    uint32_t wait_ms = lv_timer_handler();
    M5.delay(wait_ms);
    M5Dial.update();
}


void SLS_Function_1(lv_event_t *e) {            // Squareline Studio Function 1 Code Runs Here

bool switch_status = false;  
sensor.setAllLEDColor(0x00ff00);  // GREEN
switch_status = sensor.getSwitchStatus();
Serial.println("function-1 Set All Leds Green - Switch Status is:  " + String(switch_status));    
}

void SLS_Function_2(lv_event_t *e) {            // Squareline Studio Function 2 Code Runs Here           

bool switch_status = false;
sensor.setAllLEDColor(0x0000ff);  // BLUE
switch_status = sensor.getSwitchStatus();
Serial.println("function-2 Set All Leds Blue - Switch Status is:  " + String(switch_status));
    
}