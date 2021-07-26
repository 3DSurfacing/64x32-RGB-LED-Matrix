// RGB Panel GFX Demo example for 16x32 panel
// By Marc MERLIN <marc_soft@merlins.org>
// Contains code (c) Adafruit, license BSD

// WILL NOT FIT on ARDUINO UNO -- requires a Mega, M0 or M4 board

// Convert image to c file here http://www.rinkydinkelectronics.com/t_imageconverter565.php

#include <RGBmatrixPanel.h>

// Most of the signal pins are configurable, but the CLK pin has some
// special constraints.  On 8-bit AVR boards it must be on PORTB...
// Pin 8 works on the Arduino Uno & compatibles (e.g. Adafruit Metro),
// Pin 11 works on the Arduino Mega.  On 32-bit SAMD boards it must be
// on the same PORT as the RGB data pins (D2-D7)...
// Pin 8 works on the Adafruit Metro M0 or Arduino Zero,
// Pin A4 works on the Adafruit Metro M4 (if using the Adafruit RGB
// Matrix Shield, cut trace between CLK pads and run a wire to A4).

//#define CLK  8 // USE THIS ON ARDUINO UNO, ADAFRUIT METRO M0, etc.
//#define CLK A4 // USE THIS ON METRO M4 (not M0)
#define CLK 11   // USE THIS ON ARDUINO MEGA
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3


// Enable double buffering
RGBmatrixPanel *matrix = new RGBmatrixPanel(A, B, C, D, CLK, LAT, OE, true, 64);

// Panel Matrix doesn't fully work like Neomatrix (which I originally
// wrote this demo for), so map a few calls to be compatible. The rest
// comes from Adafruit_GFX and works the same on both backends.
#define setBrightness(x) fillScreen(0) // no-op, no brightness on this board
#define clear()          fillScreen(0)
#define show()           swapBuffers(true)

// vvvvv PASTE FRAME MATRIX BELOW vvvvv

/* 

const unsigned short EXAMPLE_NAME[2048] PROGMEM={
0xFFDF, 0xFFDF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF,...   // 0x0800 (2048) pixels
};

*/

// ^^^^^ PASTE FRAME MATRIX ABOVE ^^^^^


void loop() {

// vvvvv PASTE DISPLAY SCRIPT FOR EACH FRAME BELOW vvvvv
    //matrix->drawRGBBitmap(x, y, bitmap, w, h);
    matrix->drawRGBBitmap(0, 0, (const uint16_t *)EXAMPLE_NAME, 64, 32);
    matrix->show();
    delay(100);
    matrix->clear(); //Set image to black

// ^^^^^ PASTE DISPLAY SCRIPT FOR EACH FRAME ABOVE ^^^^^
}

void setup() {
    Serial.begin(115200);
    matrix->begin();
}
