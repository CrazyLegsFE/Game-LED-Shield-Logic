#include <FastLED.h>

#define NUM_LEDS 4 
#define DATA_PIN_TOP 6
#define DATA_PIN_BOTTOM 7
#define DATA_PIN_LEFT 8
#define DATA_PIN_RIGHT 9

#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define BRIGHTNESS 100

CRGB leds[NUM_LEDS];

const int topButton = 2;
const int bottomButton = 3;
const int leftButton = 4;
const int rightButton = 5;
const int resetButton = 10;

enum ShieldState {
  BALANCED,
  TOP_BLUE_BOTTOM_YELLOW,
  TOP_CYAN_BOTTOM_RED,
  BOTTOM_BLUE_TOP_YELLOW,
  BOTTOM_CYAN_TOP_RED,
  LEFT_BLUE_RIGHT_YELLOW,
  LEFT_CYAN_RIGHT_RED,
  RIGHT_BLUE_LEFT_YELLOW,
  RIGHT_CYAN_LEFT_RED
};
//This sets our initial shield state elaborated during the update led case 
ShieldState shieldTop = BALANCED;
ShieldState shieldBottom = BALANCED;
ShieldState shieldLeft = BALANCED;
ShieldState shieldRight = BALANCED;

void setup() {
  Serial.begin(9600);
  //LED defined pins for each light determined by #define lines earlier, Color order of your LEDS set by #define line earlier
  FastLED.addLeds<LED_TYPE, DATA_PIN_TOP, COLOR_ORDER>(leds, 1).setCorrection(TypicalLEDStrip);   
  FastLED.addLeds<LED_TYPE, DATA_PIN_BOTTOM, COLOR_ORDER>(leds + 1, 1).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, DATA_PIN_LEFT, COLOR_ORDER>(leds + 2, 1).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, DATA_PIN_RIGHT, COLOR_ORDER>(leds + 3, 1).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);

  //Starts LED's in a green state was having early issues with lights starting green this has been deprecated
  //fill_solid(leds, NUM_LEDS, CRGB::Green);
  //FastLED.show();

  //Set your buttons
  pinMode(topButton, INPUT_PULLUP);
  pinMode(bottomButton, INPUT_PULLUP);
  pinMode(leftButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(resetButton, INPUT_PULLUP);
}

void loop() {
  //Here I use plain language so you can follow through the states in a logical matter (This takes some serious thought as you will notice if you take a careful look at the code)
  //Top lights become the master for the top and bottom lights and the leftlights become the master for the left and right lights so make your logic based off these conditions if code density and complexity is a concern
  if (digitalRead(topButton) == LOW) {
    //Top bottom logic We make balanced our starting point so that all logic moves our shields from this point using the top button it was early code I used to ensure a starting point and here for human logic to step through the sequence
    if (shieldTop == BALANCED) {
      shieldTop = TOP_BLUE_BOTTOM_YELLOW;
    } else if (shieldTop == BOTTOM_CYAN_TOP_RED) {
      shieldTop = BOTTOM_BLUE_TOP_YELLOW;
    } else if (shieldTop == BOTTOM_BLUE_TOP_YELLOW) {
      shieldTop = BALANCED;
    } else if (shieldTop == TOP_BLUE_BOTTOM_YELLOW) {
      shieldTop = TOP_CYAN_BOTTOM_RED;
    }
    delay(200);
  }

  if (digitalRead(bottomButton) == LOW) {
    if (shieldTop == TOP_CYAN_BOTTOM_RED) {
      shieldTop = TOP_BLUE_BOTTOM_YELLOW;
    } else if (shieldTop == TOP_BLUE_BOTTOM_YELLOW) {
      shieldTop = BALANCED;
    } else if (shieldTop == BALANCED) {
      shieldTop = BOTTOM_BLUE_TOP_YELLOW;
    } else if (shieldTop == BOTTOM_BLUE_TOP_YELLOW) {
      shieldTop = BOTTOM_CYAN_TOP_RED;
    }
    delay(200);
  }

  if (digitalRead(leftButton) == LOW) {
    //Left right logic We make balanced our starting point so that all logic moves our shields from this point using the left button it was early code I used to ensure a starting point and here for human logic to step through the sequence
    if (shieldLeft == BALANCED) {
      shieldLeft = LEFT_BLUE_RIGHT_YELLOW;
    } else if (shieldLeft == RIGHT_CYAN_LEFT_RED) {
      shieldLeft = RIGHT_BLUE_LEFT_YELLOW;
    } else if (shieldLeft == RIGHT_BLUE_LEFT_YELLOW) {
      shieldLeft = BALANCED;
    } else if (shieldLeft == LEFT_BLUE_RIGHT_YELLOW) {
      shieldLeft = LEFT_CYAN_RIGHT_RED;
    }
    delay(200);
  }

  if (digitalRead(rightButton) == LOW) {
    if (shieldLeft == LEFT_CYAN_RIGHT_RED) {
      shieldLeft = LEFT_BLUE_RIGHT_YELLOW;
    } else if (shieldLeft == LEFT_BLUE_RIGHT_YELLOW) {
      shieldLeft = BALANCED;
    } else if (shieldLeft == BALANCED) {
      shieldLeft = RIGHT_BLUE_LEFT_YELLOW;
    } else if (shieldLeft == RIGHT_BLUE_LEFT_YELLOW) {
      shieldLeft = RIGHT_CYAN_LEFT_RED;
    }
    delay(200);
  }
 if (digitalRead(resetButton) == LOW) {
    // Reset all shields to BALANCED state (Remember earlier in the structure we have Top and Left as master so technically the bottom and right function DO NOTHING here currently)
    // Logic provided for a quick return to the "default" state
    shieldTop = BALANCED;
    shieldBottom = BALANCED;
    shieldLeft = BALANCED;
    shieldRight = BALANCED;
    delay(200);
  }
  updateLEDs();
}

void updateLEDs() {
  //ShieldTop for manipiluation of top AND bottom shields pay careful attention whats here and how it applies above
  switch (shieldTop) {
    case BALANCED:
      // Set the first (top and bottom) two LEDs to the color green FASTLED line above for clarification and the FASTLED library documentation if there are other requirements
      fill_solid(leds, 2, CRGB::Green);
      break;
      //Here are your sequence colors modify these and nomenclature to define your colors if you want to use this structure
    case TOP_BLUE_BOTTOM_YELLOW:
      leds[0] = CRGB::Blue;
      leds[1] = CRGB::Yellow;
      break;
    case TOP_CYAN_BOTTOM_RED:
      leds[0] = CRGB::Cyan;
      leds[1] = CRGB::Red;
      break;
    case BOTTOM_BLUE_TOP_YELLOW:
      leds[1] = CRGB::Blue;
      leds[0] = CRGB::Yellow;
      break;
    case BOTTOM_CYAN_TOP_RED:
      leds[1] = CRGB::Cyan;
      leds[0] = CRGB::Red;
      break;
  }

  switch (shieldLeft) {
    case BALANCED:
      // Set the next (left and right) two LEDs to the color green FASTLED line above for clarification and the FASTLED library documentation if there are other requirements
      // Set LEDs 3 and 4 (indexes 2 and 3) to the color green
      fill_solid(leds + 2, 2, CRGB::Green);
      break;
    case LEFT_BLUE_RIGHT_YELLOW:
      leds[2] = CRGB::Blue;
      leds[3] = CRGB::Yellow;
      break;
    case LEFT_CYAN_RIGHT_RED:
      leds[2] = CRGB::Cyan;
      leds[3] = CRGB::Red;
      break;
    case RIGHT_BLUE_LEFT_YELLOW:
      leds[3] = CRGB::Blue;
      leds[2] = CRGB::Yellow;
      break;
    case RIGHT_CYAN_LEFT_RED:
      leds[3] = CRGB::Cyan;
      leds[2] = CRGB::Red;
      break;
  }

  FastLED.show();
}
