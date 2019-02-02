#include <Adafruit_NeoPixel.h>

//VARS
int neo = 13;
int switch1 = 6;
int switch2 = 8;


  //neopixel strip on pin 13 with 5 LEDs
  #define PIN 13
  #define N_LEDS 5

   //declare the neopixel object
  Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
     

void setup() {
  //begin neo strip
  strip.begin();
  
  pinMode(neo, OUTPUT);
  int neoState = digitalRead(neo);
  
  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);
  

  //initialize serial stuff
  Serial.begin(9600); //allows us to use the serial monitor
  Serial.println("--- Start Serial Monitor ---");

}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("line"); is like a console.log()

  //get switch states
  int switch1State = digitalRead(switch1);
  int switch2State = digitalRead(switch2);
  
  Serial.println("switch 1:");
  Serial.println(switch1State);
  Serial.println("switch 2: ");
  Serial.println(switch2State);


  if (switch1State == HIGH && switch2State == HIGH) {
      chase(strip.Color(20, 10, 10));
      delay(25);
    }
  else if (switch1State == HIGH && switch2State == LOW) {
      chaseReverse(strip.Color(20, 10, 10));
      delay(25);
  }
  else {
    clearAll();
  }  

}

static void chase(uint32_t c) {
  for (int i=0; i<=6; i++) {
    strip.setPixelColor(i, c);
    strip.setPixelColor(i-1, 0);
    strip.show();
    delay(100);
  }
}

static void chaseReverse(uint32_t c) {
  for (int i=5; i>=-1; i--) {
    strip.setPixelColor(i, c);
    strip.setPixelColor(i+1, 0);
    strip.show();
    delay(100);
  }
}

static void clearAll() {
  for (int i=0; i<strip.numPixels(); i++) {
   strip.setPixelColor(i, 0);
   strip.show(); 
  }
}
