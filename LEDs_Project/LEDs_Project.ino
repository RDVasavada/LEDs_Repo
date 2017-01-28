// NOTE - 150 LEDS IN COIL

#include <Adafruit_NeoPixel.h>

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)

Adafruit_NeoPixel strip = Adafruit_NeoPixel(150, PIN, NEO_GRB + NEO_KHZ800);

int rainbowCount = 0;
float rainbowRed;
float rainbowGreen;
float rainbowBlue;

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  for (int i = 0; i < 150; i++) {
    strip.setPixelColor((i), 255, 0, 0);
    strip.setPixelColor((i - 1), 0, 0, 0);
    delay(30);
    strip.show();
  }

  for (int i = 149; i  >= 0; i--) {
    strip.setPixelColor((i), 255, 0, 0);
    strip.setPixelColor((i + 1), 0, 0, 0);
    delay(20);
    strip.show();
  }

  for (int i = 0; i < 4; i++) {

    for (int i = 0; i < 150; i++) {
      strip.setPixelColor((i), 255, 0, 0);
    }
    strip.show();

    delay(500);

    for (int i = 0; i < 150; i++) {
      strip.setPixelColor((i), 0, 0, 0);
    }
    strip.show();

    delay(500);
  }

}

// Rainbow patterns
// Insert into void draw

/*
  Snake and then flashing red

  for (int i = 0; i < 150; i++) {
    strip.setPixelColor((i), 255, 0, 0);
    strip.setPixelColor((i - 1), 0, 0, 0);
    delay(30);
    strip.show();
  }

  for (int i = 149; i  >= 0; i--) {
    strip.setPixelColor((i), 255, 0, 0);
    strip.setPixelColor((i + 1), 0, 0, 0);
    delay(20);
    strip.show();
  }

  for (int i = 0; i < 4; i++) {

    for (int i = 0; i < 150; i++) {
      strip.setPixelColor((i), 255, 0, 0);
    }
    strip.show();

    delay(500);

    for (int i = 0; i < 150; i++) {
      strip.setPixelColor((i), 0, 0, 0);
    }
    strip.show();

    delay(500);
  }
*/

/*
  Snake and then flashing with rainbow

  for (int i = 0; i < 150; i++) {
    rainbowCount++;
    rainbowRed = sin(radians(rainbowCount)) * 128 + 127;
    rainbowGreen = sin(radians(rainbowCount + 120)) * 128 + 127;
    rainbowBlue = sin(radians(rainbowCount + 240)) * 128 + 127;
    strip.setPixelColor((i), rainbowRed, rainbowGreen, rainbowBlue);
    strip.setPixelColor((i - 1), 0, 0, 0);
    delay(30);
    strip.show();
  }

  for (int i = 149; i  >= 0; i--) {
    rainbowCount++;
    rainbowRed = sin(radians(rainbowCount)) * 128 + 127;
    rainbowGreen = sin(radians(rainbowCount + 120)) * 128 + 127;
    rainbowBlue = sin(radians(rainbowCount + 240)) * 128 + 127;
    strip.setPixelColor((i), rainbowRed, rainbowGreen, rainbowBlue);
    strip.setPixelColor((i + 1), 0, 0, 0);
    delay(20);
    strip.show();
  }

  for (int i = 0; i < 4; i++) {
    rainbowCount++;
    rainbowRed = sin(radians(rainbowCount)) * 128 + 127;
    rainbowGreen = sin(radians(rainbowCount + 120)) * 128 + 127;
    rainbowBlue = sin(radians(rainbowCount + 240)) * 128 + 127;
    for (int i = 0; i < 150; i++) {
      strip.setPixelColor((i), rainbowRed, rainbowGreen, rainbowBlue);
    }
    strip.show();

    delay(500);

    for (int i = 0; i < 150; i++) {
      strip.setPixelColor((i), 0, 0, 0);
    }
    strip.show();

    delay(500);
  }
*/


