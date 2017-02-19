#include <FastLED.h>

#define LED_PIN 13
#define NUM_LEDS 50
#define COLOR_ORDER RGB
CRGB leds[NUM_LEDS];

boolean ledState_1;
boolean ledState_2;
boolean ledState_3;
boolean ledState_4;
boolean ledState_5;
boolean ledState_6;
boolean ledState_7;
boolean ledState_8;
long currentTime;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  FastLED.addLeds<WS2811, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS); 
  FastLED.clear();
  FastLED.show();
  // Serial.print("hello from Arduino"); 
}

void loop() {
  // put your main code here, to run repeatedly:

  int sensor_1 = readCapacitivePin(12);
  int sensor_2 = readCapacitivePin(11);
  int sensor_3 = readCapacitivePin(10);
  int sensor_4 = readCapacitivePin(9);
  int sensor_5 = readCapacitivePin(8);
  int sensor_6 = readCapacitivePin(7);
  int sensor_7 = readCapacitivePin(6);
  int sensor_8 = readCapacitivePin(5);
  int sensor_9 = readCapacitivePin(4);
    




  if (millis() - currentTime > 10) {
    
    if (sensor_1 >= 10) {
      if (ledState_1 == false) {
        ledState_1 = true;
        leds[4] = CRGB(255, 0, 255);
        FastLED.show();
      }
      else {
        ledState_1 = false;
        leds[4] = CRGB(0, 0, 0);
        FastLED.show();
      }
    }
   
    if (sensor_2 >= 10) {
      if (ledState_2 == false) {
        ledState_2 = true;
        leds[3] = CRGB(0, 0, 255);
        FastLED.show();
      }
      else {
        ledState_2 = false;
        leds[3] = CRGB(0, 0, 0);
        FastLED.show();
      }
    }
  
    if (sensor_3 >=10) {
      if (ledState_3 == false) {
        ledState_3 = true;
        leds[2] = CRGB(0, 255, 100);
        FastLED.show();
      }
      else {
        ledState_3 = false;
        leds[2] = CRGB(0, 0, 0);
        FastLED.show();
      }
    }

    if (sensor_4 >=10) {
      if (ledState_4 == false) {
        ledState_4 = true;
        leds[1] = CRGB(0, 255, 100);
        FastLED.show();
      }
      else {
        ledState_4 = false;
        leds[1] = CRGB( 0, 0, 0);
        FastLED.show();
      }
    }

    if (sensor_5 >=10) {
      if (ledState_5 == false) {
        ledState_5 = true;
        leds[7] = CRGB(0, 255, 100);
        FastLED.show();
      }
      else {
        ledState_5 = false;
        leds[7] = CRGB( 0, 0, 0);
        FastLED.show();
      }
    }
    
    if (sensor_6 >=10) {
      if (ledState_6 == false) {
        ledState_6 = true;
        leds[8] = CRGB(0, 255, 100);
        FastLED.show();
      }
      else {
        ledState_6 = false;
        leds[8] = CRGB( 0, 0, 0);
        FastLED.show();
      }
    }

    if (sensor_7 >=10) {
      if (ledState_7 == false) {
        ledState_7 = true;
        leds[9] = CRGB(0, 255, 100);
        FastLED.show();
      }
      else {
        ledState_7 = false;
        leds[9] = CRGB( 0, 0, 0);
        FastLED.show();
      }
    }

      
    if (sensor_8 >=10) {
      if (ledState_8 == false) {
        ledState_8 = true;
        leds[10] = CRGB(0, 255, 100);
        FastLED.show();
      }
      else {
        ledState_8 = false;
        leds[10] = CRGB( 0, 0, 0);
        FastLED.show();
      }
    } 

    if (sensor_9 >=10) {
      FastLED.clear();
      FastLED.show();
    }
    currentTime = millis();
  }
}

    


//  leds[4]=CRGB(25, 0, 26);
//  FastLED.show();
//  delay(1000);
//  leds[4]=CRGB(0, 0, 0);
//  FastLED.show();

// readCapacitivePin
//  Input: Arduino pin number
//  Output: A number, from 0 to 17 expressing
//  how much capacitance is on the pin
//  When you touch the pin, or whatever you have
//  attached to it, the number will get higher

uint8_t readCapacitivePin(int pinToMeasure) {
  // Variables used to translate from Arduino to AVR pin naming
  volatile uint8_t* port;
  volatile uint8_t* ddr;
  volatile uint8_t* pin;

  // Here we translate the input pin number from
  //  Arduino pin number to the AVR PORT, PIN, DDR,
  //  and which bit of those registers we care about.

  byte bitmask;

  port = portOutputRegister(digitalPinToPort(pinToMeasure));
  ddr = portModeRegister(digitalPinToPort(pinToMeasure));
  bitmask = digitalPinToBitMask(pinToMeasure);
  pin = portInputRegister(digitalPinToPort(pinToMeasure));

  // Discharge the pin first by setting it low and output

  *port &= ~(bitmask);
  *ddr  |= bitmask;

  delay(1);

  uint8_t SREG_old = SREG; //back up the AVR Status Register

  // Prevent the timer IRQ from disturbing our measurement

  noInterrupts();

  // Make the pin an input with the internal pull-up on

  *ddr &= ~(bitmask);
  *port |= bitmask;



  // Now see how long the pin to get pulled up. This manual unrolling of the loop
  // decreases the number of hardware cycles between each read of the pin,
  // thus increasing sensitivity.

  uint8_t cycles = 17;

  if (*pin & bitmask) { cycles =  0;}
  else if (*pin & bitmask) { cycles =  1;}
  else if (*pin & bitmask) { cycles =  2;}
  else if (*pin & bitmask) { cycles =  3;}
  else if (*pin & bitmask) { cycles =  4;}
  else if (*pin & bitmask) { cycles =  5;}
  else if (*pin & bitmask) { cycles =  6;}
  else if (*pin & bitmask) { cycles =  7;}
  else if (*pin & bitmask) { cycles =  8;}
  else if (*pin & bitmask) { cycles =  9;}
  else if (*pin & bitmask) { cycles = 10;}
  else if (*pin & bitmask) { cycles = 11;}
  else if (*pin & bitmask) { cycles = 12;}
  else if (*pin & bitmask) { cycles = 13;}
  else if (*pin & bitmask) { cycles = 14;}
  else if (*pin & bitmask) { cycles = 15;}
  else if (*pin & bitmask) { cycles = 16;}

  // End of timing-critical section; turn interrupts back on if they were on before, or leave them off if they were off before

  SREG = SREG_old;


  // Discharge the pin again by setting it low and output
  //  It's important to leave the pins low if you want to 
  //  be able to touch more than 1 sensor at a time - if
  //  the sensor is left pulled high, when you touch
  //  two sensors, your body will transfer the charge between
  //  sensors.

  *port &= ~(bitmask);
  *ddr  |= bitmask;

  return cycles;

}
