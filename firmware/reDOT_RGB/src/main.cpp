// based on example form Adafruit's Lib 

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>


#define PIN        PIN_PB4

#define mw 5
#define mh 7
Adafruit_NeoMatrix *matrix = new Adafruit_NeoMatrix(5, 7, 
  1, 1, 
  PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT+
    NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800 );

void setup() {
  matrix->begin();
  matrix->setTextWrap(false);
  matrix->setBrightness(25);
  matrix->setTextSize(1);
  matrix->setRotation(0);
  // Test full bright of all LEDs. If brightness is too high
  // for your current limit (i.e. USB), decrease it.
 // matrix->fillScreen(0xFFFF);
 // matrix->show();
 // delay(3000);
 // matrix->clear();
}

void display_scrollText(void) {
    //uint8_t size = max(int(mw/8), 1);
    
   // matrix->setTextWrap(false);  // we don't wrap text so it scrolls nicely
    
    //matrix->setRotation(0);
    for (int8_t x=7; x>=-32; x--) {
	matrix->clear();
	matrix->setCursor(x,0);
	//matrix->setTextColor(color);
	matrix->print("Alex");

	matrix->show();
       delay(80);
    }
}


// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return matrix->Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return matrix->Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return matrix->Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

uint8_t pos=0;

void loop() {

  matrix->setTextColor(Wheel(pos));
  pos+=3;
  display_scrollText();


//matrix->drawPixel(1,1, LED_BLUE_MEDIUM);
//matrix->show();

  }


