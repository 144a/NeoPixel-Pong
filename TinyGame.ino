#include <Adafruit_NeoPixel.h>

long randNumber;

#define SWITCH 0
#define PIN 4
#define NUMPIXELS 24 

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// 0 = Red; 1 = Green; 2 = Blue
int colors[3][3] = {{100, 0, 0}, {0, 100, 0}, {0, 0, 100}};

int delayval = 20;
int paddleColor = 0;

void setup() {
  
  pixels.begin();
  pinMode(4, OUTPUT);
  pixels.setBrightness(20);
  pinMode(SWITCH, INPUT_PULLUP); 
}

void loop() {
  
  // Color Of Ball
  int r = random(3);
 
  // Sets First Led to correct color 
  pixels.setPixelColor(0, pixels.Color(colors[paddleColor][0], colors[paddleColor][1], colors[paddleColor][2]));
  pixels.show(); 
  delay(delayval);
  
  int i = 1;
  while(i < NUMPIXELS) {
    // Reset paddle led because Im lazy
    pixels.setPixelColor(0, pixels.Color(colors[paddleColor][0], colors[paddleColor][1], colors[paddleColor][2]));
    
    pixels.setPixelColor(i, pixels.Color(colors[r][0], colors[r][1], colors[r][2]));
    pixels.show();
    delay(delayval); 
    pixels.setPixelColor(i - 1, pixels.Color(0, 0, 0));
    pixels.show(); 
    delay(delayval); 
    i++;
    
    // Changes Paddle Color
    if(!digitalRead(SWITCH)) {
      // Needs to be changed if there is going to be more than 3 colors
      if(paddleColor == 2) {
        paddleColor = -1;
      }
      paddleColor++;
      pixels.setPixelColor(0, pixels.Color(colors[paddleColor][0], colors[paddleColor][1], colors[paddleColor][2]));
      pixels.show();
      delay(50);
    }
  }
 
  //---------------------
  // Opposite Direction
  //---------------------
  
  // Color Of Ball
  r = random(3);
 
  // Sets First Led to correct color 
  pixels.setPixelColor(23, pixels.Color(colors[paddleColor][0], colors[paddleColor][1], colors[paddleColor][2]));
  pixels.show(); 
  delay(delayval);
  
  i = NUMPIXELS - 1;
  while(1 < i) {
    // Reset paddle led because Im lazy
    pixels.setPixelColor(0, pixels.Color(colors[paddleColor][0], colors[paddleColor][1], colors[paddleColor][2]));
    
    pixels.setPixelColor(i - 1, pixels.Color(colors[r][0], colors[r][1], colors[r][2]));
    pixels.show();
    delay(delayval); 
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show(); 
    delay(delayval); 
    i--;
    
    // Changes Paddle Color
    if(!digitalRead(SWITCH)) {
      // Needs to be changed if there is going to be more than 3 colors
      if(paddleColor == 2) {
        paddleColor = -1;
      }
      paddleColor++;
      pixels.setPixelColor(0, pixels.Color(colors[paddleColor][0], colors[paddleColor][1], colors[paddleColor][2]));
      pixels.show();
      delay(50);
    }
  }

  
    

}

