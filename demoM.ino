#include <SoftwareSerial.h> // Include XBee library
char val; // Initialize value that will store XBee incoming data
const int XB_tx = 11; // Define where you have connected the XBee's tx pin on the LilyPad
const int XB_rx = 10; // Define where you have connected the XBee's rx pin on the Lilypad
SoftwareSerial xb (XB_tx, XB_rx); // Creating a new instance of the XBee

#include <Adafruit_NeoPixel.h> //Include NeoPixel library
#ifdef __AVR__
#include <avr/power.h>
#endif

const int RA_pin = A2; // Define where you have connected the right arm (RA) LEDs on the Lilypad
const int LA_pin = A3; // Define where you have connected the left arm (LA) LEDs on the Lilypad
const int LL_pin = A4; // Define where you have connected the left leg (LL) LEDs on the Lilypad
const int RL_pin = A5; // Define where you have connected the right leg (RL) LEDs on the Lilypad


const int arm_LED_num =  12; // Define the number of LEDs on each arm
const int leg_LED_num = 20; // Define the number of LEDs on each leg

const int LEG = leg_LED_num;
const int brightness_value = 15; //THIS IS VERY IMPORTANT. DO NOT LET THIS EXCEED 20.

Adafruit_NeoPixel RA = Adafruit_NeoPixel(arm_LED_num, RA_pin, NEO_GRBW + NEO_KHZ800); // Initialize RA LED strip
Adafruit_NeoPixel LA = Adafruit_NeoPixel(arm_LED_num, LA_pin, NEO_GRBW + NEO_KHZ800); // Initialize LA LED strip
Adafruit_NeoPixel LL = Adafruit_NeoPixel(leg_LED_num, LL_pin, NEO_GRBW + NEO_KHZ800); // Initialize LL LED strip
Adafruit_NeoPixel RL = Adafruit_NeoPixel(leg_LED_num, RL_pin, NEO_GRBW + NEO_KHZ800); // Initialize RL LED strip

int flag0,flag1,flag2,flag3,flag4,flag5,flag6,flag7,flag8;


void setup() {
  xb.begin(9600); // Start the XBee transmission
  delay(1000); // Soft startup to ease the flow of electrons.
  LA.setBrightness(brightness_value); // THIS IS VERY IMPORTANT. SET BRIGHTNESS VALUES FOR EACH OF THE FOUR STRIPS OR YOU RISK SHORTING THE BOARD.
  RA.setBrightness(brightness_value);
  LL.setBrightness(brightness_value);
  RL.setBrightness(brightness_value);

  LA.begin(); // Call this function to start the LEDs
  RA.begin();
  LL.begin();
  RL.begin();

  flag0=0;
  flag1=0;
  flag2=0;
  flag3=0;
  flag4=0;
  flag5=0;
  flag6=0;
  flag7=0;
  flag8=0;
  
  uint32_t ORANGE = LA.Color(255, 50, 0);
  fillAll(ORANGE, 200);


}

//Respository of preset LED colors
uint32_t MAGENTA = LA.Color(255, 0, 127);
uint32_t RED = LA.Color(255, 0, 0);
uint32_t ORANGE = LA.Color(255, 50, 0);
uint32_t YELLOW = LA.Color(255, 255, 0);
uint32_t LIME = LA.Color(80, 255, 0);
uint32_t GREEN = LA.Color(25, 255, 0);
uint32_t TURQUOISE = LA.Color(0, 255, 255);
uint32_t  BLUE = LA.Color(0, 40, 255);
uint32_t PURPLE = LA.Color(51, 0, 102);
uint32_t WHITE = LA.Color(255, 255, 255);
uint32_t NO_LIGHT = LA.Color(0, 0, 0);

void loop() {
  if (xb.available()) {
    val = xb.read();
  }

//Initialize
if(val=='Z'&&flag0==0){
  fillAll(ORANGE,100);
  flag0=1;
}
//Prelude
  if ((val == 'A'||val=='I'||val=='R')&&flag1==0) {
    flag1=1;
    for(int i=0;i<5;i++){
      strobeArms(YELLOW,1,600);
      off(211);
      strobeLegs(LIME,1,600);
      off(212);
    }
    for(int i=0;i<16;i++){
      fillAll(LA.Color(255*i/16,255*(16-i)/16,255*i/16),500);
      off(205);
      if(i%2==0)
        off(1);
      if(i%4==0)
        off(1);
      if(i%8==0)
        off(1);
    }
    
  }

 //Verse1
  if ((val == 'B'||val=='J'||val=='S')&&flag2==0) {
    flag2=1;
     //tryna reign 
    colorWipeArm(BLUE,15,0);
    colorWipeLeg(BLUE,15,300);
    off(1200);
    //thunder 2m 03.8s
    fillAll(LIME, 250);
    off(100);
    fillAll(RED, 250);
    off(100);
    off(3000);
    //I'm a walk 2m 07.617s
    colorWipeArm(PURPLE,15,0);
    colorWipeLeg(PURPLE,15,300);
    off(900);
    //regular 2m 09.547s
    fillAll(YELLOW, 180);
    off(50);
    fillAll(WHITE,180);
    off(50);
    fillAll(BLUE,180);
    off(50);
    off(300);
    off(2923);
    //love forgive me 2m 13.371s
    colorWipeArm(RED,15,0);
    colorWipeLeg(RED,15,300);
    off(4577);
    //I am rain 2m 18.848s
    colorWipeArm(GREEN,15,0);
    colorWipeLeg(GREEN,15,300);
    off(1171);
    //bitter love 2m 20.819s
    fillAll(LIME, 250);
    off(100);
    fillAll(PURPLE, 250);
    off(100);   
  }

//Pre-Chorus
  if ((val == 'C'||val=='K'||val=='T')&&flag3==0){ 
    flag3=1;
   rainbowSmooth(50,20,9);
  }

//Chorus
 if ((val == 'D'||val=='L'||val=='U')&&flag4==0) {
    flag4=1;
    for(int i=0;i<16;i++){
      colorWipeArm(RED,30,0);
      colorWipeLeg(RED,30,300);
      off(100);
    }
  }

//Prelude
 if ((val == 'E'||val=='N'||val=='V')&&flag5==0) {
    flag5=1;
    rainbowSmooth(50,20,9);
 }

  //Verse2
 if ((val == 'F'||val=='O'||val=='W')&&flag6==0) {
    flag6=1;
    //I'ma wade ripple
    off(706);
    colorWipeLeg(BLUE,15,200);
    off(205);
    off(706);
    //water 2m 03.8s
    fillAll(LIME, 250);
    off(100);
    fillAll(RED, 250);
    off(100);
    off(2800);
    //I'm a riot
    colorWipeArm(PURPLE,15,0);
    colorWipeLeg(PURPLE,15,300);
    off(1400);
    //borders 
    fillAll(YELLOW, 250);
    off(100);
    off(3268);
    //love forgive me 
    colorWipeArm(RED,15,0);
    colorWipeLeg(RED,15,300);
    off(4777);
    //I am wade 
    colorWipeArm(GREEN,15,0);
    colorWipeLeg(GREEN,15,300);
    off(1171);
    //shallow love 
    fillAll(LIME, 250);
    off(100);
    fillAll(RED, 250);
    off(100);   
    
  }

  //Pre-Chorus
  if ((val == 'G'||val=='P'||val=='X')&&flag7==0) {
    flag7=1;
    rainbowSmooth(2, 20, 63);
  }

//Chorus
 if ((val == 'H'||val=='Q'||val=='Y')&&flag8==0) {
    flag8=1;
    for(int i=0;i<16;i++){
      colorWipeArm(RED,30,0);
      colorWipeLeg(RED,30,300);
      off(100);
    }
    for(int i=0;i<110;i++){
      fillAll(LA.Color(random(255),random(255),random(255)),50);
      off(50);
    }
    for(int i=0;i<50;i++){
      fillAll(LA.Color(random(255),random(255),random(255)),500);
      off(205);
      
    }
  }
  
}

void showLEDs() {
  RA.show();
  LA.show();
  RL.show();
  LL.show();
}


void fill(Adafruit_NeoPixel *strip, uint32_t color, int display_time) {
  for (int i = 0; i < strip->numPixels(); i++) {
    strip->setPixelColor(i, color);
  }
  showLEDs();
  delay(display_time);
}

void fillAll(uint32_t color, int display_time) {
  for (int i = 0; i < arm_LED_num; i++) {
    LA.setPixelColor(i, color);
    RA.setPixelColor(i, color);
  }
  for (int i = 0; i < leg_LED_num; i++) {
    LL.setPixelColor(i, color);
    RL.setPixelColor(i, color);
  }
  showLEDs();
  delay(display_time);
}


void off(int display_time) {
  fillAll(NO_LIGHT, display_time);
}

void strobeAll(uint32_t color, int strobe_count, int wait_time) {
  for (int i = 0; i < strobe_count; i++) {
    fillAll(color, wait_time);
    off(wait_time);
  }
}

void strobeLegs(uint32_t color, int strobe_count, int wait_time) {
  for (int j = 0; j < strobe_count; j++) {
    for (int i = 0; i < leg_LED_num; i++) {
      LL.setPixelColor(i, color);
      RL.setPixelColor(i, color);
    }
    showLEDs();
    delay(wait_time);
    off(wait_time);
  }
}

void strobeArms(uint32_t color, int strobe_count, int wait_time) {
  for (int j = 0; j < strobe_count; j++) {
    for (int i = 0; i < arm_LED_num; i++) {
      LA.setPixelColor(i, color);
      RA.setPixelColor(i, color);
    }
    showLEDs();
    delay(wait_time);
    off(wait_time);
  }
}

void rainbowStrobeAll(int strobe_count, int wait_time) {
  for (int j = 0; j < strobe_count; j++) {
    for (int i = 0; i < arm_LED_num; i++) {
      LA.setPixelColor(i, random(0, 120), random(0, 120), random(0, 120));
      RA.setPixelColor(i, random(0, 120), random(0, 120), random(0, 120));
    }
    for (int i = 0; i < leg_LED_num; i++) {
      LL.setPixelColor(i, random(0, 120), random(0, 120), random(0, 120));
      RL.setPixelColor(i, random(0, 120), random(0, 120), random(0, 120));
    }
    showLEDs();
    delay(wait_time);
    off(wait_time);
  }
}

void rainbowSmooth(uint8_t wait_time, int cycle_num, int color_num) {
  uint16_t i, j;
  for (j = 0; j < color_num * cycle_num; j++) { // 5 cycles of all colors on wheel
    for (i = 0; i < arm_LED_num; i++) {
      RA.setPixelColor(i, Wheel(((i * 256 / RA.numPixels()) + j) & 255));
      LA.setPixelColor(i, Wheel(((i * 256 / LA.numPixels()) + j) & 255));
    }
    for (i = 0; i < leg_LED_num; i++) {
      RL.setPixelColor(i, Wheel(((i * 256 / RL.numPixels()) + j) & 255));
      LL.setPixelColor(i, Wheel(((i * 256 / LL.numPixels()) + j) & 255));
    }
    showLEDs();
    delay(wait_time);
  }
}

void altEven(Adafruit_NeoPixel *strip, uint32_t color, int display_time) {
  for (int i = 0; i < strip->numPixels(); i++) {
    if (i % 2 == 0) {
      strip->setPixelColor(i, color);
    }
  }
  showLEDs();
  delay(display_time);
}

void altOdd(Adafruit_NeoPixel *strip, uint32_t color, int display_time) {
  for (int i = 0; i < strip->numPixels(); i++) {
    if (i % 2 == 1) {
      strip->setPixelColor(i, color);
    }
  }
  showLEDs();
  delay(display_time);
}


void altAllOdd(uint32_t color, int display_time) {
  altOdd(&RA, color, 0);
  altOdd(&LA, color, 0);
  altOdd(&RL, color, 0);
  altOdd(&LL, color, display_time);
}

void altAllEven(uint32_t color, int display_time) {
  altEven(&RA,  color, 0);
  altEven(&LA, color, 0);
  altEven(&RL, color, 0);
  altEven(&LL, color, display_time);
}

void colorWipe(Adafruit_NeoPixel *strip, uint32_t color, int effect_time, int display_time){
  for (int i =0; i<strip->numPixels(); i++){
    strip->setPixelColor(i,color);
    strip->show();
    delay(effect_time);
  }
  delay(display_time);
}

void colorWipeArm(uint32_t color, uint8_t effect_time, int display_time) {
  for (uint16_t i = 0; i < arm_LED_num; i++) {
    LA.setPixelColor(i, color);
    RA.setPixelColor(i, color);
    LA.show();
    RA.show();
    delay(effect_time);
  }
  delay(display_time);
}



void colorWipeLeg(uint32_t color, uint8_t effect_time, int display_time) {
  for (uint16_t i = 0; i < leg_LED_num; i++) {
    LL.setPixelColor(i, color);
    RL.setPixelColor(i, color);
    LL.show();
    RL.show();
    delay(effect_time);
  }
  delay(display_time);
}






//Color wheel generator for rainbow effects
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return LL.Color(255 - WheelPos * 3, 0, WheelPos * 3, 0);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return LL.Color(0, WheelPos * 3, 255 - WheelPos * 3, 0);
  }
  WheelPos -= 170;
  return LL.Color(WheelPos * 3, 255 - WheelPos * 3, 0, 0);
}

uint8_t red(uint32_t c) {
  return (c >> 16);
}
uint8_t green(uint32_t c) {
  return (c >> 8);
}
uint8_t blue(uint32_t c) {
  return (c);
}
