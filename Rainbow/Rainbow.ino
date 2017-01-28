#include <Adafruit_NeoPixel.h>
#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(150, PIN, NEO_GRB + NEO_KHZ800);
long n = 0L;
char add = 'g';
char sub = 'r';
long r = 127L;
long g = 0L;
long b = 0L;
long i = 0L;
long t = 0L;
bool tStop = false;


void flashSet() {
  r = 126;
  g = 0;
  b = 0;
  add = 'g';
  sub = 'r';
}
void flash() {
  for (int i = 0; i < 150; i++) {
    strip.setPixelColor(i, r, g, b);
  }
}


void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // put your main code here, to run repeatedly:
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

  if (i < 150 and tStop == false) {
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
