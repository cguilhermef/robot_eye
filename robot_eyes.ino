#include <U8glib.h>
#include <JC_Button.h>

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);
Button button(4);
bool angry = false;

void setup() {
  button.begin();
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  }
}

void loop() {
  button.read();

  if(button.wasPressed()){
    angry = !angry;
  }
  
  u8g.firstPage(); 
  do {
    if (angry) {
      draw_left_eye();
      draw_right_eye_angry();
    } else {
      draw_left_eye();
      draw_right_eye_sad();
    }
  } while (u8g.nextPage());
}

void draw_left_eye() {
  u8g.setColorIndex(1);
  u8g.drawRBox(10, 10, 30, 30, 8);
}
void draw_right_eye() {
  u8g.setColorIndex(1);
  u8g.drawRBox(50, 10, 30, 30, 8);
}
void draw_right_eye_angry() {
  u8g.setColorIndex(1);
  u8g.drawRBox(50, 10, 30, 30, 8);
  u8g.setColorIndex(0);
  u8g.drawBox(50, 10, 30, 15);
  u8g.setColorIndex(1);
  u8g.drawTriangle(50,25, 80,20, 80,30);
}

void draw_right_eye_sad() {
  u8g.setColorIndex(1);
  u8g.drawRBox(50, 10, 30, 30, 8);
  u8g.setColorIndex(0);
  u8g.drawBox(50, 10, 30, 15);
  u8g.setColorIndex(1);
  u8g.drawTriangle(80,25, 50,20, 50,30);
}
