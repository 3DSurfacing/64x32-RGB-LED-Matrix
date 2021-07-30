const int DIN_PIN1 = 8;
const int DIN_PIN2 = 7;
const int DIN_PIN3 = 6;

#include <RGBmatrixPanel.h>
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns

char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {41, 43, 45, 47}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {49, 51, 53}; //connect to the column pinouts of the keypad

//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

#define CLK 11   // USE THIS ON ARDUINO MEGA
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

RGBmatrixPanel *matrix = new RGBmatrixPanel(A, B, C, D, CLK, LAT, OE, true, 64);

#define setBrightness(x) fillScreen(0) // no-op, no brightness on this board
#define clear()          fillScreen(0)
#define show()           swapBuffers(true)


/* FRAME EXAMPLE BELOW:

const unsigned short binKet[2048] PROGMEM={
};

*/

int speed = 150;

void a() {
  matrix->begin();

    // draw a pixel in solid white
  matrix->drawPixel(0, 0, matrix->Color333(7, 7, 7));
  matrix->show();
  delay(500);

  // fix the screen with green
  matrix->fillRect(0, 0, matrix->width(), matrix->height(), matrix->Color333(0, 7, 0));
  matrix->show();
  delay(500);

  // draw a box in yellow
  matrix->drawRect(0, 0, matrix->width(), matrix->height(), matrix->Color333(7, 7, 0));
  matrix->show();
  delay(500);

  // draw an 'X' in red
  matrix->drawLine(0, 0, matrix->width()-1, matrix->height()-1, matrix->Color333(7, 0, 0));
  matrix->drawLine(matrix->width()-1, 0, 0, matrix->height()-1, matrix->Color333(7, 0, 0));
  matrix->show();
  delay(500);

  // draw a blue circle
  matrix->drawCircle(10, 10, 10, matrix->Color333(0, 0, 7));
  matrix->show();
  delay(500);

  // fill a violet circle
  matrix->fillCircle(40, 21, 10, matrix->Color333(7, 0, 7));
  matrix->show();
  delay(500);
// fill the screen with 'black'
  matrix->fillScreen(matrix->Color333(0, 0, 0));

  // draw some text!
  matrix->setTextSize(1);     // size 1 == 8 pixels high
  matrix->setTextWrap(false); // Don't wrap at end of line - will do ourselves

  matrix->setCursor(8, 0);    // start at top left, with 8 pixel of spacing
  uint8_t w = 0;
  char *str = "SUMMER";
  for (w=0; w<6; w++) {
    matrix->setTextColor(Wheel(w));
    matrix->print(str[w]);
  }
  matrix->setCursor(2, 8);    // next line
  for (w=8; w<18; w++) {
    matrix->setTextColor(Wheel(w));
    matrix->print(str[w]);
  }
  matrix->println();
  //matrix->setTextColor(matrix->Color333(4,4,4));
  //matrix->println("Industries");
  matrix->setTextColor(matrix->Color333(7,7,7));
  matrix->println("LED MATRIX!");

  // print each letter with a rainbow color
  matrix->setTextColor(matrix->Color333(7,0,0));  // red
  matrix->print('3');
  matrix->setTextColor(matrix->Color333(7,4,0));  // orange
  matrix->print('2');
  matrix->setTextColor(matrix->Color333(7,7,0));  // yellow
  matrix->print('x');
  matrix->setTextColor(matrix->Color333(4,7,0));  // yellow2
  matrix->print('6');
  matrix->setTextColor(matrix->Color333(0,7,0));  // green
  matrix->print('4');
  matrix->setCursor(34, 24);
  matrix->setTextColor(matrix->Color333(0,7,7));  // lightBlue
  matrix->print('*');
  matrix->setTextColor(matrix->Color333(0,4,7));  // lightBlue2
  matrix->print('R');
  matrix->setTextColor(matrix->Color333(0,0,7));  // darkBlue
  matrix->print('G');
  matrix->setTextColor(matrix->Color333(4,0,7));  // magenta1
  matrix->print('B');
  matrix->setTextColor(matrix->Color333(7,0,4));  // magenta2
  matrix->print('*');

  matrix->show();
  delay(500);
  // whew!
}

void a2() {
  coloredVersion();
  whiteVersion();
  coloredVersion();
  whiteVersion();
  coloredVersion();
  whiteVersion();
  coloredVersion();
  whiteVersion();
}

  void coloredVersion() {
    char *str = "HARDSUMMER";
    matrix->begin();
    // draw a box in yellow
    matrix->drawRect(0, 0, matrix->width(), matrix->height(), matrix->Color333(0, 0, 7));
    uint8_t w = 0;
    matrix->setTextSize(2);
    matrix->setCursor(9, 2);
    for (w=0; w<10; w++) {
      if (w < 4) {
        matrix->setTextColor(Wheel(w));
        matrix->print(str[w]);
      } else if (w == 4) {
        matrix->setTextSize(1.5);
        matrix->setCursor(16, 20);    // next line
        matrix->setTextColor(Wheel(w));
        matrix->print(str[w]);
      } else {
        matrix->setTextColor(Wheel(w));
        matrix->print(str[w]);
      }
    }
    matrix->println();
    matrix->show();
    delay(500);
    matrix->clear();
  }

  void whiteVersion() {
    char *str = "HARDSUMMER";
    matrix->begin();
    matrix->drawRect(0, 0, matrix->width(), matrix->height(), matrix->Color333(15, 15, 15));
    uint8_t x = 0;
    matrix->setTextSize(2);
    matrix->setCursor(9, 2);
    for (x=0; x<10; x++) {
      if (x < 4) {
        matrix->setTextColor(matrix->Color333(15, 15, 15));
        matrix->print(str[x]);
      } else if (x == 4) {
        matrix->setTextSize(1.5);
        matrix->setCursor(16, 20);    // next line
        matrix->setTextColor(matrix->Color333(15, 15, 15));
        matrix->print(str[x]);
      } else {
        matrix->setTextColor(matrix->Color333(15, 15, 15));
        matrix->print(str[x]);
      }
    }
    matrix->println();
    matrix->show();
    delay(500);
    matrix->clear();
  }

void mine() {
  matrix->begin();
  matrix->fillRect(0, 0, 64, 32, matrix->Color333(13, 13, 13));
  matrix->show();
  delay(500);
  matrix->show();
}

void loop() {
    bool button1on = digitalRead( DIN_PIN1 ) == LOW;
    bool button2on = digitalRead( DIN_PIN2 ) == LOW;
    bool button3on = digitalRead( DIN_PIN3 ) == LOW;

    bool key1on = keypad.getKey() == '1';

    char key = keypad.getKey();// Read the key

    // Print if key pressed
    if (key){
      Serial.print("Key Pressed : ");
      Serial.println(key);
    }

    if ( button1on ){
      a();
    } else if ( key1on ) {
      a2();
    } else if ( button3on ) {
      a();
      mine();
    } else {
      matrix->clear();
    }

}

void setup() {
    Serial.begin(115200);
    matrix->begin();
    pinMode( DIN_PIN1, INPUT_PULLUP );
    pinMode( DIN_PIN2, INPUT_PULLUP );
    pinMode( DIN_PIN3, INPUT_PULLUP );
    a2();

   char key = keypad.getKey();

  if (key){
    Serial.println(key);
  }
}

uint16_t Wheel(byte WheelPos) {
  if(WheelPos < 8) {
   return matrix->Color333(7 - WheelPos, WheelPos, 0);
  } else if(WheelPos < 16) {
   WheelPos -= 8;
   return matrix->Color333(0, 7-WheelPos, WheelPos);
  } else {
   WheelPos -= 16;
   return matrix->Color333(WheelPos, 0, 7 - WheelPos);
  }
}