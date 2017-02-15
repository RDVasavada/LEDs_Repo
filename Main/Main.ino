// 2017 Cyberhawks 706 NeoPixel Code
// Developed by Rohan Vasavada

// NOTE - 150 LEDS IN COIL

#include <Adafruit_NeoPixel.h>

#define PIN 6

// NEO_KHZ800  800 KHz bitstream
// NEO_GRB     Pixels are wired for GRB bitstream

Adafruit_NeoPixel strip = Adafruit_NeoPixel(150, PIN, NEO_GRB + NEO_KHZ800);

const int STRIP_LENGTH = 150;
const int FLASH_DELAY = 300;
const int SNAKE_DELAY = 20;

// Rainbow RGB values
int rainbowCount = 0;
float rainbowRed;
float rainbowGreen;
float rainbowBlue;

int state = 2;

// Values for Joshua's rainbows
double n = 0;
char add = 'g';
char sub = 'r';
double r = 127;
double g = 0;
double b = 0;
double i = 0;
long t = 0L;
bool tStop = false;

// Determines LED state based on digital input
int findState() {
  int returnValue = 0;
  int secondValue = 0;

  if (digitalRead(10) == HIGH) {
    returnValue += 100;
  }
  if (digitalRead(9) == HIGH) {
    returnValue += 10;
  }
  if (digitalRead(8) == HIGH) {
    returnValue += 1;
  }

  switch (returnValue) {
    case 0:
      secondValue = 0;
    case 1:
      secondValue = 1;
    case 10:
      secondValue = 2;
    case 11:
      secondValue = 3;
    case 100:
      secondValue = 4;
    case 101:
      secondValue = 5;
    case 110:
      secondValue = 6;
    case 111:
      secondValue = 7;
    default:
      secondValue = 0;
  }

  return secondValue;
}

void setup() {
  strip.begin();
  strip.show();
  // state = findState();
}

void loop() {

  if (state == 0) { // Solid cyber pink

    int x = 0;

    // Sets the LEDs to a cyber pink color of fluctuating intensity
    for (int i = 0; i < STRIP_LENGTH; i++) {
      strip.setPixelColor((i), ((exp(sin((millis() + x) / 2000.0 * (PI / 1.5))) - 0.36787944) * 41) + 10, 0, (((exp(sin((millis() + x) / 2000.0 * (PI / 1.5))) - 0.36787944) * 20) + 10));
      x += 1;
    }
    strip.show();

  } else if (state == 1) { // Cyber snake and flash

    // Creates a snake of length 1
    colorSnake(51, 4, 30);

    // Flashes the LED set
    colorFlash(51, 4, 30);

  } else if (state == 2) { // Rainbow snake and flash

    // Same as above, but with rainbow colors
    rainbowSnake();

    rainbowFlash();

  } else if (state == 3) { // Green breathing

    // Sets the LEDs to a green color of fluctuating intensity
    float x = 0;
    for (int i = 0; i < STRIP_LENGTH; i++) {
      strip.setPixelColor((i), 0, ((exp(sin((millis() + x) / 2000.0 * (PI / 1.5))) - 0.36787944) * 60) + 10, 0);
      x += 100;
    }
    strip.show();

  } else if (state == 4) { // Joshua's rainbows

    joshuaRainbow();

  } else if (state == 5) { // Flowing rainbows

    theaterChaseRainbow();

  } else if (state == 6) { // Red Alliance (Breathing)

    // Sets the LEDs to a red color of fluctuating intensity
    float x = 0;
    for (int i = 0; i < STRIP_LENGTH; i++) {
      strip.setPixelColor((i), ((exp(sin((millis() + x) / 2000.0 * (PI / 1.5))) - 0.36787944) * 60) + 10, 0, 0);
      x += 100;
    }
    strip.show();

  } else if (state == 7) {   // Blue Alliance (Breathing)

    // Sets the LEDs to a blue color of fluctuating intensity
    float x = 0;
    for (int i = 0; i < STRIP_LENGTH; i++) {
      strip.setPixelColor((i), (0, 0, (exp(sin((millis() + x) / 2000.0 * (PI / 1.5))) - 0.36787944) * 60) + 10);
      x += 100;
    }
    strip.show();

  } else if (state == 8) { // Solud color test state
    for (int i = 0; i < STRIP_LENGTH; i++) {
      strip.setPixelColor((i), 51, 51, 51);
    }
    strip.show();
  }

}


void rainbowSnake() {
  for (int i = 0; i < STRIP_LENGTH; i++) {
    rainbowCount += 5;
    rainbowRed = sin(radians(rainbowCount)) * 128 + 127;
    rainbowGreen = sin(radians(rainbowCount + 120)) * 128 + 127;
    rainbowBlue = sin(radians(rainbowCount + 240)) * 128 + 127;
    strip.setPixelColor((i), rainbowRed, rainbowGreen, rainbowBlue);
    strip.setPixelColor((i - 1), 0, 0, 0);
    delay(SNAKE_DELAY);
    strip.show();
  }

  for (int i = STRIP_LENGTH - 1; i  >= 0; i--) {
    rainbowCount += 5;
    rainbowRed = sin(radians(rainbowCount)) * 128 + 127;
    rainbowGreen = sin(radians(rainbowCount + 120)) * 128 + 127;
    rainbowBlue = sin(radians(rainbowCount + 240)) * 128 + 127;
    strip.setPixelColor((i), rainbowRed, rainbowGreen, rainbowBlue);
    strip.setPixelColor((i + 1), 0, 0, 0);
    delay(SNAKE_DELAY);
    strip.show();
  }
}

void rainbowFlash() {
  for (int i = 0; i < 4; i++) {
    for (int i = 0; i < STRIP_LENGTH; i++) {
      rainbowCount += 20;
      rainbowRed = sin(radians(rainbowCount)) * 128 + 127;
      rainbowGreen = sin(radians(rainbowCount + 120)) * 128 + 127;
      rainbowBlue = sin(radians(rainbowCount + 240)) * 128 + 127;
      strip.setPixelColor((i), rainbowRed, rainbowGreen, rainbowBlue);
    }
    strip.show();

    delay(FLASH_DELAY);

    for (int i = 0; i < STRIP_LENGTH; i++) {
      strip.setPixelColor((i), 0, 0, 0);
    }
    strip.show();

    delay(FLASH_DELAY);
  }
}

void colorSnake(float r, float g, float b) {
  for (int i = 0; i < STRIP_LENGTH; i++) {
    strip.setPixelColor((i), r, g, b);
    strip.setPixelColor((i - 1), 0, 0, 0);
    delay(SNAKE_DELAY);
    strip.show();
  }

  for (int i = STRIP_LENGTH - 1; i  >= 0; i--) {
    strip.setPixelColor((i), r, g, b);
    strip.setPixelColor((i + 1), 0, 0, 0);
    delay(SNAKE_DELAY);
    strip.show();
  }
}

void colorFlash(float r, float g, float b) {
  for (int i = 0; i < 4; i++) {
    for (int i = 0; i < STRIP_LENGTH; i++) {
      strip.setPixelColor((i), r, g, b);
    }
    strip.show();

    delay(FLASH_DELAY);

    for (int i = 0; i < STRIP_LENGTH; i++) {
      strip.setPixelColor((i), 0, 0, 0);
    }
    strip.show();

    delay(FLASH_DELAY);
  }
}

void joshuaRainbow() {
  if (r < 127 and add == 'r') {
    r++;
  } else if ( r > 0 and sub == 'r') {
    add = 'g';
    r--;
  } else if (r == 127) {
    sub = 'r';
  }
  if (g < 127 and add == 'g') {
    g++;
  } else if ( g > 0 and sub == 'g') {
    add = 'b';
    g--;
  } else if (g == 127) {
    sub = 'g';
  }
  if (b < 127 and add == 'b') {
    b++;
  } else if ( b > 0 and sub == 'b') {
    add = 'r';
    b--;
  } else if (b == 127) {
    sub = 'b';
  }

  if (i < STRIP_LENGTH and tStop == false) {
    strip.setPixelColor(i, r, g, b);
    i++;
  } else {
    i = 0;
  }
  t++;
  if (tStop == true) {
    flash();
  }
  if (t % 1000 == 0) {
    flashSet();
    tStop = true;
  }
  if (t % 1000 == 300) {
    flashSet();
    tStop = false;
  }
  strip.show();
  delay(3);
}

// Functions for Joshua's rainbows
void flashSet() {
  r = 126;
  g = 0;
  b = 0;
  add = 'g';
  sub = 'r';
}

void flash() {
  for (int i = 0; i < STRIP_LENGTH; i++) {
    strip.setPixelColor(i, r, g, b);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256; j++) {
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Functions for flowing rainbows
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow() {
  for (int j = 0; j < 256; j++) {   // cycle all 256 colors in the wheel
    for (int q = 0; q < 3; q++) {
      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, Wheel( (i + j) % 255)); //turn every third pixel on
      }
      strip.show();

      delay(90);

      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, 0);      //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

