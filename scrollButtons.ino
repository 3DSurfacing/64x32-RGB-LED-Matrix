const int DIN_PIN1 = 7;
const int DIN_PIN2 = 9;
const int LED_PIN = 13;
int count = 0;

void setup(){
    Serial.begin(9600);
    pinMode( DIN_PIN1, INPUT_PULLUP );
    pinMode( DIN_PIN2, INPUT_PULLUP );
    pinMode( LED_PIN, OUTPUT );
}

void loop(){

    int value1;
    int value2;




    bool isPlaying;
    bool isLit;


    isPlaying = false;
    isLit = false;

    value1 = digitalRead( DIN_PIN1 );
    value2 = digitalRead( DIN_PIN2 );

    if ( value1 == LOW ){
        count += 1;
        isPlaying = true;
        Serial.print("isPlaying = ");
        Serial.println(isPlaying);
        Serial.print("count = ");
        Serial.println(count);
        digitalWrite( LED_PIN, HIGH );
    } else if ( value2 == LOW ) {
        count -= 1;
        isLit = true;
        Serial.print("isLit = ");
        Serial.println(isLit);
        Serial.print("count = ");
        Serial.println(count);
        digitalWrite( LED_PIN, HIGH );
    } else{
        digitalWrite( LED_PIN, LOW );
    }

    delay( 100 );
}