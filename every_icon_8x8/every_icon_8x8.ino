/***************************************************
  Every Icon 8x8
  Andy Doro

  displays every possible 8x8 icon on 8x8 LED matrix

  https://www.adafruit.com/product/1857

  runs on Trinket 5V

  based on every icon by John F. Simon Jr. http://numeral.com/appletsoftware/eicon.html

 ****************************************************/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

#define BRIGHTNESS 64
#define DELAY 10

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

uint64_t icon = 0;

void setup() {
  //Serial.begin(9600);
  //Serial.println("8x8 LED Matrix Test");

  matrix.begin(0x70);  // pass in the address
  matrix.clear();
  matrix.writeDisplay(); // clear display

  matrix.setBrightness(BRIGHTNESS);

  delay(500);

  matrix.setTextSize(1);
  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextColor(LED_ON);
  for (int8_t x = 0; x >= -100; x--) {
    matrix.clear();
    matrix.setCursor(x, 0);
    matrix.print("EVERY 8X8 ICON");
    matrix.writeDisplay();
    delay(80);
  }

  delay(500);

}

void loop() {

  matrix.clear();
  // draw the icon
  for (byte i = 0; i < 64; i++) {
    boolean masker = bitRead(icon, i);
    switch (masker) {
      case 0:
        // leave blank
        break;
      case 1:
        matrix.drawPixel(i % 8, i / 8, LED_ON); // set that pixel
        break;
    }
  }
  matrix.writeDisplay();
  delay(DELAY);

  if (icon < 0xFFFFFFFFFFFFFFFF) {
    icon++; // increase icon
  }

}
