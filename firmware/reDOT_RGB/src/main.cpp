#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN        PIN_PB4
#define NUMPIXELS 35
#define DELAYVAL 200

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ400);

void setup() {
  pixels.begin();
}

void loop() {
  pixels.clear();

  for(int i=0; i<NUMPIXELS; i++) {

    pixels.setPixelColor(i, pixels.Color(4, 1, 2));
    //pixels.setPixelColor(2, pixels.Color(10, 0, 10));
    pixels.show();
    delay(DELAYVAL);
  }
}

