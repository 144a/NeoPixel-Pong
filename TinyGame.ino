#include <Adafruit_NeoPixel.h>

long randNumber;

#define SWITCH 0
#define PIN 4
#define NUMPIXELS 24 

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 20;
bool ledOn = true;

void setup() {
  
  pixels.begin();
  pinMode(4, OUTPUT);
  pixels.setBrightness(20);
  pinMode(SWITCH, INPUT_PULLUP); 
}

void loop() {
  int r = random(128);
  int g = random(128);
  int b = random(128);
  
  pixels.setPixelColor(0, pixels.Color(r,g,b));
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(delayval); // Delay for a period of time (in milliseconds).
  
  int i = 1;
  while(i < NUMPIXELS) {
    pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).
    pixels.setPixelColor(i - 1, pixels.Color(0,0,0));
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).
    i++;
    while(!digitalRead(SWITCH)) {
    }
  }
  pixels.setPixelColor(23, pixels.Color(0,0,0));
  pixels.show(); // This sends the updated pixel color to the hardware.
  
    

}

