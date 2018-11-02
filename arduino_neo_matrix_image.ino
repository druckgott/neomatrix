
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>


// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 3

// Max is 255, 32 is a conservative value to not overload
// a USB power supply (500mA) for 12x12 pixels.
#define BRIGHTNESS 96

// Define matrix width and height.
#define mw 8
#define mh 8

#define LED_BLACK    0

int counter = 0;
int bilderanzahl = 0;

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoMatrix *matrix = new Adafruit_NeoMatrix(mw, mh, PIN,
    NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
    NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
    NEO_GRB            + NEO_KHZ800);
    
static const uint16_t PROGMEM
// These bitmaps were written for a backend that only supported
// 4 bits per color with Blue/Green/Red ordering while neomatrix
// uses native 565 color mapping as RGB.
// I'm leaving the arrays as is because it's easier to read
// which color is what when separated on a 4bit boundary
// The demo code will modify the arrays at runtime to be compatible
// with the neomatrix color ordering and bit depth.


RGB_bmp[][64] = {

//Mario 1
{
0x000,  0x000,  0x000,  0x50F,  0x50F,  0x50F,  0xEEF,  0x000,
0x50F,  0x50F,  0x50F,  0x50F,  0x50F,  0x000,  0x000,  0x000,
0x000,  0x000,  0x35A,  0xACF,  0x35A,  0x000,  0xACF,  0x000,
0xACF,  0x35A,  0x35A,  0xACF,  0xACF,  0x35A,  0x000,  0x000,
0x000,  0x000,  0x000,  0x35A,  0xACF,  0xACF,  0xACF,  0x000,
0x000,  0x0AF,  0xFA2,  0xFA2,  0x2FF,  0x50F,  0x50F,  0x000,
0xEEF,  0x000,  0xFA2,  0xFA2,  0xFA2,  0xFA2,  0x532,  0x978,
0x000,  0x527,  0x000,  0x000,  0x000,  0x35A,  0x000,  0x000,

},

//Mario 2
{
  0x000,  0x000,  0x000,  0x50F,  0x50F,  0x50F,  0xEEF,  0x000,
0x50F,  0x50F,  0x50F,  0x50F,  0x50F,  0x000,  0x000,  0x000,
0x000,  0x000,  0x35A,  0xACF,  0x35A,  0x000,  0xACF,  0x000,
0xACF,  0x35A,  0x35A,  0xACF,  0xACF,  0x35A,  0x000,  0x000,
0x000,  0x000,  0x000,  0x35A,  0xACF,  0xACF,  0xACF,  0x000,
0x000,  0x532,  0xFA2,  0x2FF,  0x50F,  0x50F,  0x000,  0x000,
0x000,  0x000,  0x50F,  0xEEF,  0xFA2,  0xFA2,  0x532,  0x000,
0x000,  0x000,  0x527,  0x35A,  0x35A,  0x000,  0x000,  0x000,

},

//Mario 3
{

0x000,  0x000,  0x000,  0x50F,  0x50F,  0xEEF,  0x50F,  0x000,
0x50F,  0x50F,  0x50F,  0x50F,  0x50F,  0x000,  0x000,  0x000,
0x000,  0x000,  0xACF,  0x35A,  0x000,  0xACF,  0x000,  0x000,
0x35A,  0xACF,  0x35A,  0x35A,  0xACF,  0xACF,  0x000,  0x000,
0x000,  0x000,  0x000,  0xACF,  0xACF,  0xACF,  0xACF,  0x000,
0x000,  0x0AF,  0xFA2,  0xFA2,  0x2FF,  0x50F,  0x50F,  0x000,
0xEEF,  0x000,  0xFA2,  0xFA2,  0xFA2,  0xFA2,  0x532,  0x978,
0x000,  0x000,  0x35A,  0x000,  0x000,  0x527,  0x000,  0x000,

},
//Mario 4
{

0x000,  0x000,  0x000,  0x50F,  0x50F,  0xEEF,  0x50F,  0x000,
0x50F,  0x50F,  0x50F,  0x50F,  0x50F,  0x000,  0x000,  0x000,
0x000,  0x000,  0xACF,  0x35A,  0x000,  0xACF,  0x000,  0x000,
0x35A,  0xACF,  0x35A,  0x35A,  0xACF,  0xACF,  0x000,  0x000,
0x000,  0x50F,  0x50F,  0xACF,  0xACF,  0xACF,  0xACF,  0x000,
0xEEF,  0x0AF,  0xFA2,  0xFA2,  0x2FF,  0x50F,  0x000,  0xEEF,
0x000,  0x527,  0xFA2,  0xFA2,  0xFA2,  0xFA2,  0x532,  0x000,
0x000,  0x35A,  0x000,  0x000,  0x000,  0x000,  0x000,  0x000,

},

};



void display_rgbBitmap(uint8_t bmp_num) {
  static uint16_t bmx, bmy;

  fixdrawRGBBitmap(bmx, bmy, RGB_bmp[bmp_num], 8, 8);
  bmx += 8;
  if (bmx >= mw) bmx = 0;
  if (!bmx) bmy += 8;
  if (bmy >= mh) bmy = 0;
  matrix->show();
}

// Convert a BGR 4/4/4 bitmap to RGB 5/6/5 used by Adafruit_GFX
void fixdrawRGBBitmap(int16_t x, int16_t y, const uint16_t *bitmap, int16_t w, int16_t h) {
  uint16_t RGB_bmp_fixed[w * h];
  for (uint16_t pixel = 0; pixel < w * h; pixel++) {
    uint8_t r, g, b;
    uint16_t color = pgm_read_word(bitmap + pixel);

    //Serial.print(color, HEX);
    b = (color & 0xF00) >> 8;
    g = (color & 0x0F0) >> 4;
    r = color & 0x00F;
    //Serial.print(" ");
    //Serial.print(b);
    //Serial.print("/");
    //Serial.print(g);
    //Serial.print("/");
    //Serial.print(r);
    //Serial.print(" -> ");
    // expand from 4/4/4 bits per color to 5/6/5
    b = map(b, 0, 15, 0, 31);
    g = map(g, 0, 15, 0, 63);
    r = map(r, 0, 15, 0, 31);
    //Serial.print(r);
    //Serial.print("/");
    //Serial.print(g);
    //Serial.print("/");
    //Serial.print(b);
    RGB_bmp_fixed[pixel] = (r << 11) + (g << 5) + b;
   // Serial.print(" -> ");
    //Serial.print(pixel);
    //Serial.print(" -> ");
    //Serial.println(RGB_bmp_fixed[pixel], HEX);
  }
  matrix->drawRGBBitmap(x, y, RGB_bmp_fixed, w, h);
}

void setup() {
  Serial.begin(115200);

  matrix->begin();
  matrix->setTextWrap(false);
  matrix->setBrightness(BRIGHTNESS);
  // Test full bright of all LEDs. If brightness is too high
  // for your current limit (i.e. USB), decrease it.
  //matrix->fillScreen(LED_WHITE_HIGH);
  //matrix->show();
  //delay(1000);
  matrix->clear();
  bilderanzahl=(sizeof(RGB_bmp) / sizeof(RGB_bmp[0]));
  Serial.print("Anzahl Bilder: ");
  Serial.println(bilderanzahl);
}



void loop() {

  // clear the screen after X bitmaps have been displayed and we
  // loop back to the top left corner
  // 8x8 => 1, 16x8 => 2, 17x9 => 6
  static uint8_t pixmap_count = ((mw + 7) / 8) * ((mh + 7) / 8);
  // Cycle through red, green, blue, display 2 checkered patterns
  // useful to debug some screen types and alignment.

  Serial.print("Screen pixmap capacity: ");
  Serial.println(pixmap_count);

  display_rgbBitmap(counter++);
  delay(500);

  if (counter >=bilderanzahl){
    counter = 0;
  }

  Serial.println ("----------------------------------------------------------------");
  //delay(1000);
}


