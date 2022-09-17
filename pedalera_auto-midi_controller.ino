//7seg display
#include <TM1637Display.h>
#define CLK 6
#define DIO 5
TM1637Display Display(CLK, DIO);

///////////////////////////////////////////1st PAIR OF BUTTONS///////////////////////////////////////////
byte  bothchecker = false;
byte longpressboth = false;

//// SWITCH 0 ////

static const int buttonPin = 4;                    // switch pin
byte buttonStatePrevious = LOW;                      // previousstate of the switch

unsigned long buttonLongPressMillis;                // Time in ms when we the button was pressed
byte buttonStateLongPress = false;                  // True if it is a long press

unsigned long previousButtonMillis;                 // Timestamp of the latest reading

unsigned long buttonPressDuration;                  // Time the button is pressed in ms

byte buttonState;
byte shortpress = false;
byte longpress = false;

//// SWITCH 1 ////

static const int button1Pin = 3;                    // switch pin
byte button1StatePrevious = LOW;                      // previousstate of the switch

unsigned long button1LongPressMillis;                // Time in ms when we the button was pressed
byte button1StateLongPress = false;                  // True if it is a long press

unsigned long previousButton1Millis;                 // Timestamp of the latest reading

unsigned long button1PressDuration;

byte button1State;
byte shortpress1 = false;
byte longpress1 = false;

///////////////////////////////////////////2nd PAIR OF BUTTONS///////////////////////////////////////////
byte  bothchecker2 = false;
byte longpressboth2 = false;

//// SWITCH 2 ////

static const int button2Pin = 7;                    // switch pin
byte button2StatePrevious = LOW;                      // previousstate of the switch

unsigned long button2LongPressMillis;                // Time in ms when we the button was pressed
byte button2StateLongPress = false;                  // True if it is a long press

unsigned long previousButton2Millis;                 // Timestamp of the latest reading

unsigned long button2PressDuration;                  // Time the button is pressed in ms

byte button2State;
byte shortpress2 = false;
byte longpress2 = false;

//// SWITCH 3 ////

static const int button3Pin = 8;                    // switch pin
byte button3StatePrevious = LOW;                      // previousstate of the switch

unsigned long button3LongPressMillis;                // Time in ms when we the button was pressed
byte button3StateLongPress = false;                  // True if it is a long press

unsigned long previousButton3Millis;                 // Timestamp of the latest reading

unsigned long button3PressDuration;

byte button3State;
byte shortpress3 = false;
byte longpress3 = false;

///////////////////////////////////////////3rd PAIR OF BUTTONS///////////////////////////////////////////
byte  bothchecker3 = false;
byte longpressboth3 = false;

//// SWITCH 4 ////

static const int button4Pin = 11;                    // switch pin
byte button4StatePrevious = LOW;                      // previousstate of the switch

unsigned long button4LongPressMillis;                // Time in ms when we the button was pressed
byte button4StateLongPress = false;                  // True if it is a long press

unsigned long previousButton4Millis;                 // Timestamp of the latest reading

unsigned long button4PressDuration;                  // Time the button is pressed in ms

byte button4State;
byte shortpress4 = false;
byte longpress4 = false;

//// SWITCH 5 ////
int analogsw5read;

//static const int button5Pin = 16;                    // esta la podría borrar!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int button5StatePrevious = LOW;                      // previousstate of the switch

unsigned long button5LongPressMillis;                // Time in ms when we the button was pressed
byte button5StateLongPress = false;                  // True if it is a long press

unsigned long previousButton5Millis;                 // Timestamp of the latest reading

unsigned long button5PressDuration;

byte button5State;
byte shortpress5 = false;
byte longpress5 = false;

///////////////////////////////////////////4th PAIR OF BUTTONS///////////////////////////////////////////
byte  bothchecker4 = false;
byte longpressboth4 = false;

//// SWITCH 6 ////

static const int button6Pin = 18;                    // A6
byte button6StatePrevious = LOW;                      // previousstate of the switch

unsigned long button6LongPressMillis;                // Time in ms when we the button was pressed
byte button6StateLongPress = false;                  // True if it is a long press

unsigned long previousButton6Millis;                 // Timestamp of the latest reading

unsigned long button6PressDuration;                  // Time the button is pressed in ms

byte button6State;
byte shortpress6 = false;
byte longpress6 = false;

//// SWITCH 7 ////

static const int button7Pin = 19;                    // A7
byte button7StatePrevious = LOW;                      // previousstate of the switch

unsigned long button7LongPressMillis;                // Time in ms when we the button was pressed
byte button7StateLongPress = false;                  // True if it is a long press

unsigned long previousButton7Millis;                 // Timestamp of the latest reading

unsigned long button7PressDuration;

byte button7State;
byte shortpress7 = false;
byte longpress7 = false;

////////////////////////////////////////////switch 8 (alt)/////////////////////////////////////////////

//// SWITCH 8 alt  ////

static const int button8Pin = 2;                    // switch pin
byte button8StatePrevious = LOW;                      // previousstate of the switch

unsigned long button8LongPressMillis;                // Time in ms when we the button was pressed
byte button8StateLongPress = false;                  // True if it is a long press

unsigned long previousButton8Millis;                 // Timestamp of the latest reading

unsigned long button8PressDuration;

byte button8State;
byte shortpress8 = false;
byte longpress8 = false;

byte alt = false;                                 //variable para revisar funciones alternas

////////////////////////////////////////////////// GENERAL /////////////////////////////////////////////
unsigned long minButtonLongPressDuration = 2000;    // Time we wait before we see the press as a long press
const int intervalButton = 50;                      // Time between two readings of the button state

unsigned long currentMillis;          // Variabele to store the number of milleseconds since the Arduino has started

unsigned long lastsyncread = 0;
byte sync = false;
byte syncallflag = false;
byte syncall = false;
unsigned long lastsyncallflag = 0;
byte synccounter = 0;                    //contador de clicks
unsigned long lastsynccounter = 0;          //millis para control del contador

byte clickstocount = 0;

byte ledpin = 13;

byte msgsent = false;
unsigned long lastmsgsent = 0;

////////////////////////////////////////////switches del cd4066/////////////////////////////////////////////
byte sw1;
byte sw2;
const int sw1ctrl = 9;
const int sw2ctrl = 10;
unsigned long lastSw1Ctrl = 0;
unsigned long lastSw2Ctrl = 0;
byte sw1ctrlstate;
byte sw2ctrlstate;

///////////////////////////////////////////////////menú///////////////////////////////////////////////////
byte trackuniarray[10];
byte trackdecarray[10];

byte arriba = LOW;
byte select = LOW;
byte abajo = LOW;
byte mostrararray = LOW;
byte cursorpin = LOW;
//menú
byte cursor1 = false;
byte showunidigit = true;
byte showdecdigit = true;
byte menustate = 1;
byte nclicksuni = 0;
byte nclicksdec = 0;
byte ntrackdec = 0;
byte ntrackuni = 0;
byte menu_active = false;
byte menu_out = false;
unsigned long lastmenu_out = 0;
unsigned long lastunimillis = 0;
unsigned long lastdecmillis = 0;
unsigned long lastarriba = 0;
unsigned long lastselect = 0;
unsigned long lastabajo = 0;
unsigned long lastmostrararray = 0;
unsigned long lastcursorpin = 0;
const uint8_t msg[] = {
  SEG_G | SEG_D | SEG_E | SEG_F,                  //t
  SEG_E | SEG_G,                                  //r
};
const uint8_t blank[] = {SEG_D,};

const uint8_t msg2[] = {
  SEG_A | SEG_D | SEG_E | SEG_F,                  //C
  SEG_D | SEG_E | SEG_F,                          //L
};
const uint8_t msg3[] = {
  SEG_A | SEG_C | SEG_D | SEG_G | SEG_F,          //S
  SEG_B | SEG_C | SEG_D | SEG_G | SEG_F,          //Y
  SEG_C | SEG_E | SEG_G,                          //n
  SEG_A | SEG_D | SEG_E | SEG_F,                  //C
};
const uint8_t msg4[] = {
  SEG_A | SEG_B | SEG_C | SEG_G | SEG_E | SEG_F,  //A
  SEG_D | SEG_E | SEG_F,                          //L
  SEG_D | SEG_E | SEG_F,                          //L
};
///////////////////////////////////menu messages/////////////////////////
const uint8_t msg5[] = {
 SEG_A | SEG_D | SEG_E | SEG_F,                  //C
  SEG_A | SEG_B | SEG_D | SEG_C | SEG_E | SEG_F,  //O
  SEG_A | SEG_G | SEG_E | SEG_F,                  //F
  SEG_A | SEG_B | SEG_D | SEG_C | SEG_G | SEG_F,  //g
};
const uint8_t msg6[] = {
  SEG_A | SEG_D | SEG_E | SEG_F,                  //C
  SEG_D | SEG_E | SEG_F,                          //L
  SEG_B | SEG_C,                                  //i
  SEG_A | SEG_D | SEG_E | SEG_F,                  //C
};
const uint8_t msg7[] = {
  SEG_A | SEG_B | SEG_G | SEG_E | SEG_F,          //P
  SEG_D | SEG_E | SEG_F,                          //L
  SEG_A | SEG_B | SEG_C | SEG_G | SEG_E | SEG_F,  //A
  SEG_B | SEG_C | SEG_D | SEG_G | SEG_F,          //Y
};
///////////////////////////////////////////alt message///////////////
  const uint8_t msg8[] = {
  SEG_A | SEG_B | SEG_C | SEG_G | SEG_E | SEG_F,  //A
  SEG_D | SEG_E | SEG_F,                          //L
  SEG_G | SEG_D | SEG_E | SEG_F,                  //t
};
///////////////////////////////////////////undo messages///////////////
  const uint8_t msg9[] = {
  SEG_C | SEG_B | SEG_D | SEG_E | SEG_F,          //u
  SEG_C | SEG_E | SEG_G,                          //n
  SEG_C | SEG_B | SEG_D | SEG_E | SEG_G,          //d
  SEG_C | SEG_D | SEG_E | SEG_G,                  //o
  };
  const uint8_t msg10[] = {
  SEG_C | SEG_B | SEG_D | SEG_E | SEG_F,          //u
  SEG_C | SEG_E | SEG_G,                          //n
  SEG_A | SEG_C | SEG_D | SEG_G | SEG_F,          //S
  SEG_E | SEG_G,                                  //r
  };
void setup() {
  Serial.begin(9600);                 // Initialise the serial monitor

  pinMode(buttonPin, INPUT);          // set buttonPin as input
  pinMode(button1Pin, INPUT);          // set buttonPin as input
  pinMode(button2Pin, INPUT);          // set buttonPin as input
  pinMode(button3Pin, INPUT);          // set buttonPin as input
  pinMode(button4Pin, INPUT);          // set buttonPin as input
//  pinMode(button5Pin, INPUT);          // set buttonPin as input
  pinMode(button6Pin, INPUT);          // set buttonPin as input
  pinMode(button7Pin, INPUT);          // set buttonPin as input
  pinMode(button8Pin, INPUT);          // set buttonPin as input
  //  pinMode(sw1pin, INPUT);          // set buttonPin as input
  //  pinMode(sw2pin, INPUT);          // set buttonPin as input
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  //pinMode(A6, INPUT);
  //pinMode(A7, INPUT);
  Serial.println("Press button");

  Display.setBrightness(5);
    inicio ();
}

void inicio(){
    Display.setSegments(msg, 2, 0);
    Display.showNumberDec(ntrackdec, false, 1, 2);
    Display.showNumberDec(ntrackuni, false, 1, 3);
    clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
    return;
}

////////////////////////////////////////////1st pair reading///////////////////////////////////////////////////
// Function for reading the button0 state
void readButtonState() {

  // If the difference in time between the previous reading is larger than intervalButton
  if (currentMillis - previousButtonMillis > intervalButton) {

    // Read the digital value of the button (LOW/HIGH)
    buttonState = digitalRead(buttonPin);

    // If the button has been pushed AND
    // If the button wasn't pressed before AND
    // IF there was not already a measurement running to determine how long the button has been pressed
    if (buttonState == HIGH && buttonStatePrevious == LOW && !buttonStateLongPress) {
      buttonLongPressMillis = currentMillis;
      buttonStatePrevious = HIGH;
      Serial.println("Button pressed");
      msgsent = false;                    //cancela el mensaje enviado
    }

    // Calculate how long the button has been pressed
    buttonPressDuration = currentMillis - buttonLongPressMillis;

    //............................ if both buttons have been long pressed
    if  (button1State == HIGH && buttonState == HIGH && !button1StateLongPress && !buttonStateLongPress && ((buttonPressDuration >= minButtonLongPressDuration) )) {
      button1StateLongPress = true;
      buttonStateLongPress = true;
      bothchecker = true;
      Serial.println("both buttons long pressed");
      longpressboth = true;
    }
    //.......................................................................................................
    // If the button is pressed AND
    // If there is no measurement running to determine how long the button is pressed AND
    // If the time the button has been pressed is larger or equal to the time needed for a long press
    if (buttonState == HIGH && button1State == LOW && !buttonStateLongPress && ((buttonPressDuration >= minButtonLongPressDuration) )) {
      buttonStateLongPress = true;
      Serial.println("Button long pressed");
      longpress = true;
    }

    // If the button is released AND
    // If the button was pressed before
    if (buttonState == LOW && buttonStatePrevious == HIGH) {
      buttonStatePrevious = LOW;
      buttonStateLongPress = false;
      bothchecker = false;
      Serial.println("Button released");
      button1StatePrevious = LOW;
      button1StateLongPress = false;

      // If there is no measurement running to determine how long the button was pressed AND
      // If the time the button has been pressed is smaller than the minimal time needed for a long press
      // Note: The video shows:
      //       if (!buttonStateLongPress && buttonPressDuration < minButtonLongPressDuration) {
      //       since buttonStateLongPress is set to FALSE on line 75, !buttonStateLongPress is always TRUE
      //       and can be removed.
      if (buttonPressDuration < minButtonLongPressDuration) {
        shortpress = true;
        shortpress1 = false;
        shortpress2 = false;
        shortpress3 = false;
        shortpress4 = false;
        shortpress5 = false;
        shortpress6 = false;
        shortpress7 = false;
        Serial.println("Button pressed shortly");
      }
    }

    // store the current timestamp in previousButtonMillis
    previousButtonMillis = currentMillis;

  }

}


// Function for reading the button1 state
void readButton1State() {

  // If the difference in time between the previous reading is larger than intervalButton
  if (currentMillis - previousButton1Millis > intervalButton) {

    // Read the digital value of the button (LOW/HIGH)
    button1State = digitalRead(button1Pin);

    // If the button has been pushed AND
    // If the button wasn't pressed before AND
    // IF there was not already a measurement running to determine how long the button has been pressed
    if (button1State == HIGH && button1StatePrevious == LOW && !button1StateLongPress) {
      button1LongPressMillis = currentMillis;
      button1StatePrevious = HIGH;
      Serial.println("Button1 pressed");
      msgsent = false;                    //cancela el mensaje enviado
    }

    // Calculate how long the button has been pressed
    button1PressDuration = currentMillis - button1LongPressMillis;

    // If the button is pressed AND
    // If there is no measurement running to determine how long the button is pressed AND
    // If the time the button has been pressed is larger or equal to the time needed for a long press
    if (button1State == HIGH && buttonState == LOW && !button1StateLongPress && ((button1PressDuration >= minButtonLongPressDuration) )) {
      button1StateLongPress = true;
      Serial.println("Button1 long pressed");
      longpress1 = true;
    }

    // If the button is released AND
    // If the button was pressed before
    if (button1State == LOW && button1StatePrevious == HIGH) {
      button1StatePrevious = LOW;
      button1StateLongPress = false;
      Serial.println("Button1 released");

      // If there is no measurement running to determine how long the button was pressed AND
      // If the time the button has been pressed is smaller than the minimal time needed for a long press
      // Note: The video shows:
      //       if (!buttonStateLongPress && buttonPressDuration < minButtonLongPressDuration) {
      //       since buttonStateLongPress is set to FALSE on line 75, !buttonStateLongPress is always TRUE
      //       and can be removed.
      if (button1PressDuration < minButtonLongPressDuration) {
        if (synccounter <= 1){shortpress = false;
        shortpress1 = true;
        shortpress2 = false;
        shortpress3 = false;
        shortpress4 = false;
        shortpress5 = false;
        shortpress6 = false;
        shortpress7 = false;}
        if (synccounter > 1){syncreccancel();}
        Serial.println("Button1 pressed shortly");
      }
    }

    // store the current timestamp in previousButtonMillis
    previousButton1Millis = currentMillis;

  }

}

////////////////////////////////////////////2nd pair reading///////////////////////////////////////////////////
// Function for reading the button2 state
void readButton2State() {

  // If the difference in time between the previous reading is larger than intervalButton
  if (currentMillis - previousButton2Millis > intervalButton) {

    // Read the digital value of the button (LOW/HIGH)
    button2State = digitalRead(button2Pin);

    // If the button has been pushed AND
    // If the button wasn't pressed before AND
    // IF there was not already a measurement running to determine how long the button has been pressed
    if (button2State == HIGH && button2StatePrevious == LOW && !button2StateLongPress) {
      button2LongPressMillis = currentMillis;
      button2StatePrevious = HIGH;
      Serial.println("Button2 pressed");
      msgsent = false;                    //cancela el mensaje enviado
    }

    // Calculate how long the button has been pressed
    button2PressDuration = currentMillis - button2LongPressMillis;

    //............................ if both buttons have been long pressed
    if  (button3State == HIGH && button2State == HIGH && !button3StateLongPress && !button2StateLongPress && ((button2PressDuration >= minButtonLongPressDuration) )) {
      button3StateLongPress = true;
      button2StateLongPress = true;
      bothchecker2 = true;
      Serial.println("second pair of buttons long pressed");
      longpressboth2 = true;
    }
    //.......................................................................................................
    // If the button is pressed AND
    // If there is no measurement running to determine how long the button is pressed AND
    // If the time the button has been pressed is larger or equal to the time needed for a long press
    if (button2State == HIGH && button3State == LOW && !button2StateLongPress && ((button2PressDuration >= minButtonLongPressDuration) )) {
      button2StateLongPress = true;
      Serial.println("Button2 long pressed");
      longpress2 = true;
    }

    // If the button is released AND
    // If the button was pressed before
    if (button2State == LOW && button2StatePrevious == HIGH) {
      button2StatePrevious = LOW;
      button2StateLongPress = false;
      bothchecker2 = false;
      Serial.println("Button2 released");
      button3StatePrevious = LOW;
      button3StateLongPress = false;

      // If there is no measurement running to determine how long the button was pressed AND
      // If the time the button has been pressed is smaller than the minimal time needed for a long press
      // Note: The video shows:
      //       if (!buttonStateLongPress && buttonPressDuration < minButtonLongPressDuration) {
      //       since buttonStateLongPress is set to FALSE on line 75, !buttonStateLongPress is always TRUE
      //       and can be removed.
      if (button2PressDuration < minButtonLongPressDuration) {
         if (synccounter <= 1){shortpress = false;
        shortpress1 = false;
        shortpress2 = true;
        shortpress3 = false;
        shortpress4 = false;
        shortpress5 = false;
        shortpress6 = false;
        shortpress7 = false;}
        Serial.println("Button2 pressed shortly");
      }
    }

    // store the current timestamp in previousButtonMillis
    previousButton2Millis = currentMillis;

  }

}


// Function for reading the button3 state
void readButton3State() {

  // If the difference in time between the previous reading is larger than intervalButton
  if (currentMillis - previousButton3Millis > intervalButton) {

    // Read the digital value of the button (LOW/HIGH)
    button3State = digitalRead(button3Pin);

    // If the button has been pushed AND
    // If the button wasn't pressed before AND
    // IF there was not already a measurement running to determine how long the button has been pressed
    if (button3State == HIGH && button3StatePrevious == LOW && !button3StateLongPress) {
      button3LongPressMillis = currentMillis;
      button3StatePrevious = HIGH;
      Serial.println("Button3 pressed");
      msgsent = false;                    //cancela el mensaje enviado
    }

    // Calculate how long the button has been pressed
    button3PressDuration = currentMillis - button3LongPressMillis;

    // If the button is pressed AND
    // If there is no measurement running to determine how long the button is pressed AND
    // If the time the button has been pressed is larger or equal to the time needed for a long press
    if (button3State == HIGH && button2State == LOW && !button3StateLongPress && ((button3PressDuration >= minButtonLongPressDuration) )) {
      button3StateLongPress = true;
      Serial.println("Button3 long pressed");
      longpress3 = true;
    }

    // If the button is released AND
    // If the button was pressed before
    if (button3State == LOW && button3StatePrevious == HIGH) {
      button3StatePrevious = LOW;
      button3StateLongPress = false;
      Serial.println("Button3 released");

      // If there is no measurement running to determine how long the button was pressed AND
      // If the time the button has been pressed is smaller than the minimal time needed for a long press
      // Note: The video shows:
      //       if (!buttonStateLongPress && buttonPressDuration < minButtonLongPressDuration) {
      //       since buttonStateLongPress is set to FALSE on line 75, !buttonStateLongPress is always TRUE
      //       and can be removed.
      if (button3PressDuration < minButtonLongPressDuration) {
        Serial.println("Button3 pressed shortly");
         if (synccounter <= 1){shortpress = false;
        shortpress1 = false;
        shortpress2 = false;
        shortpress3 = true;
        shortpress4 = false;
        shortpress5 = false;
        shortpress6 = false;
        shortpress7 = false;}
      }
    }

    // store the current timestamp in previousButtonMillis
    previousButton3Millis = currentMillis;

  }

}

////////////////////////////////////////////3rd pair reading///////////////////////////////////////////////////
// Function for reading the button4 state
void readButton4State() {

  // If the difference in time between the previous reading is larger than intervalButton
  if (currentMillis - previousButton4Millis > intervalButton) {

    // Read the digital value of the button (LOW/HIGH)
    button4State = digitalRead(button4Pin);

    // If the button has been pushed AND
    // If the button wasn't pressed before AND
    // IF there was not already a measurement running to determine how long the button has been pressed
    if (button4State == HIGH && button4StatePrevious == LOW && !button4StateLongPress) {
      button4LongPressMillis = currentMillis;
      button4StatePrevious = HIGH;
      Serial.println("Button4 pressed");
      msgsent = false;                    //cancela el mensaje enviado
    }

    // Calculate how long the button has been pressed
    button4PressDuration = currentMillis - button4LongPressMillis;

    //............................ if both buttons have been long pressed
    if  (button5State == HIGH && button4State == HIGH && !button5StateLongPress && !button4StateLongPress && ((button4PressDuration >= minButtonLongPressDuration) )) {
      button5StateLongPress = true;
      button4StateLongPress = true;
      bothchecker3 = true;
      Serial.println("3rd pair of buttons long pressed");
      longpressboth3 = true;
    }
    //.......................................................................................................
    // If the button is pressed AND
    // If there is no measurement running to determine how long the button is pressed AND
    // If the time the button has been pressed is larger or equal to the time needed for a long press
    if (button4State == HIGH && button5State == LOW && !button4StateLongPress && ((button4PressDuration >= minButtonLongPressDuration) )) {
      button4StateLongPress = true;
      Serial.println("Button4 long pressed");
      longpress4 = true;
    }

    // If the button is released AND
    // If the button was pressed before
    if (button4State == LOW && button4StatePrevious == HIGH) {
      button4StatePrevious = LOW;
      button4StateLongPress = false;
      bothchecker3 = false;
      Serial.println("Button4 released");
      button5StatePrevious = LOW;
      button5StateLongPress = false;

      // If there is no measurement running to determine how long the button was pressed AND
      // If the time the button has been pressed is smaller than the minimal time needed for a long press
      // Note: The video shows:
      //       if (!buttonStateLongPress && buttonPressDuration < minButtonLongPressDuration) {
      //       since buttonStateLongPress is set to FALSE on line 75, !buttonStateLongPress is always TRUE
      //       and can be removed.
      if (button4PressDuration < minButtonLongPressDuration) {
         if (synccounter <= 1){shortpress = false;
        shortpress1 = false;
        shortpress2 = false;
        shortpress3 = false;
        shortpress4 = true;
        shortpress5 = false;
        shortpress6 = false;
        shortpress7 = false;}
        Serial.println("Button4 pressed shortly");
      }
    }

    // store the current timestamp in previousButtonMillis
    previousButton4Millis = currentMillis;

  }

}


// Function for reading the button5 state
void readButton5State() {

  // If the difference in time between the previous reading is larger than intervalButton
  if (currentMillis - previousButton5Millis > intervalButton) {

    // Read the digital value of the button (LOW/HIGH)
//    button5State = digitalRead(button5Pin);
    analogsw5read = analogRead(A6);
    if (analogsw5read < 500){
      button5State = LOW;
    }
    else if (analogsw5read > 500){
      button5State = HIGH;
    }

    // If the button has been pushed AND
    // If the button wasn't pressed before AND
    // IF there was not already a measurement running to determine how long the button has been pressed
    if (button5State == HIGH && button5StatePrevious == LOW && !button5StateLongPress) {
      button5LongPressMillis = currentMillis;
      button5StatePrevious = HIGH;
      Serial.println("Button5 pressed");
      msgsent = false;                    //cancela el mensaje enviado
    }

    // Calculate how long the button has been pressed
    button5PressDuration = currentMillis - button5LongPressMillis;

    // If the button is pressed AND
    // If there is no measurement running to determine how long the button is pressed AND
    // If the time the button has been pressed is larger or equal to the time needed for a long press
    if (button5State == HIGH && button4State == LOW && !button5StateLongPress && ((button5PressDuration >= minButtonLongPressDuration) )) {
      button5StateLongPress = true;
      Serial.println("Button5 long pressed");
      longpress5 = true;
    }

    // If the button is released AND
    // If the button was pressed before
    if (button5State == LOW && button5StatePrevious == HIGH) {
      button5StatePrevious = LOW;
      button5StateLongPress = false;
      Serial.println("Button5 released");

      // If there is no measurement running to determine how long the button was pressed AND
      // If the time the button has been pressed is smaller than the minimal time needed for a long press
      // Note: The video shows:
      //       if (!buttonStateLongPress && buttonPressDuration < minButtonLongPressDuration) {
      //       since buttonStateLongPress is set to FALSE on line 75, !buttonStateLongPress is always TRUE
      //       and can be removed.
      if (button5PressDuration < minButtonLongPressDuration) {
        Serial.println("Button5 pressed shortly");
         if (synccounter <= 1){shortpress = false;
        shortpress1 = false;
        shortpress2 = false;
        shortpress3 = false;
        shortpress4 = false;
        shortpress5 = true;
        shortpress6 = false;
        shortpress7 = false;}
      }
    }

    // store the current timestamp in previousButtonMillis
    previousButton5Millis = currentMillis;

  }

}

////////////////////////////////////////////4th pair reading///////////////////////////////////////////////////
// Function for reading the button6 state
void readButton6State() {

  // If the difference in time between the previous reading is larger than intervalButton
  if (currentMillis - previousButton6Millis > intervalButton) {

    // Read the digital value of the button (LOW/HIGH)
    button6State = digitalRead(button6Pin);

    // If the button has been pushed AND
    // If the button wasn't pressed before AND
    // IF there was not already a measurement running to determine how long the button has been pressed
    if (button6State == HIGH && button6StatePrevious == LOW && !button6StateLongPress) {
      button6LongPressMillis = currentMillis;
      button6StatePrevious = HIGH;
      Serial.println("Button6 pressed");
      msgsent = false;                    //cancela el mensaje enviado
    }

    // Calculate how long the button has been pressed
    button6PressDuration = currentMillis - button6LongPressMillis;

    //............................ if both buttons have been long pressed
    if  (button7State == HIGH && button6State == HIGH && !button7StateLongPress && !button6StateLongPress && ((button6PressDuration >= minButtonLongPressDuration) )) {
      button7StateLongPress = true;
      button6StateLongPress = true;
      bothchecker4 = true;
      Serial.println("4th pair of buttons long pressed");
      longpressboth4 = true;
    }
    //.......................................................................................................
    // If the button is pressed AND
    // If there is no measurement running to determine how long the button is pressed AND
    // If the time the button has been pressed is larger or equal to the time needed for a long press
    if (button6State == HIGH && button7State == LOW && !button6StateLongPress && ((button6PressDuration >= minButtonLongPressDuration) )) {
      button6StateLongPress = true;
      Serial.println("Button6 long pressed");
      longpress6 = true;
    }

    // If the button is released AND
    // If the button was pressed before
    if (button6State == LOW && button6StatePrevious == HIGH) {
      button6StatePrevious = LOW;
      button6StateLongPress = false;
      bothchecker4 = false;
      Serial.println("Button6 released");
      button7StatePrevious = LOW;
      button7StateLongPress = false;

      // If there is no measurement running to determine how long the button was pressed AND
      // If the time the button has been pressed is smaller than the minimal time needed for a long press
      // Note: The video shows:
      //       if (!buttonStateLongPress && buttonPressDuration < minButtonLongPressDuration) {
      //       since buttonStateLongPress is set to FALSE on line 75, !buttonStateLongPress is always TRUE
      //       and can be removed.
      if (button6PressDuration < minButtonLongPressDuration) {
         if (synccounter <= 1){shortpress = false;
        shortpress1 = false;
        shortpress2 = false;
        shortpress3 = false;
        shortpress4 = false;
        shortpress5 = false;
        shortpress6 = true;
        shortpress7 = false;}
        Serial.println("Button6 pressed shortly");
      }
    }

    // store the current timestamp in previousButtonMillis
    previousButton6Millis = currentMillis;

  }

}


// Function for reading the button7 state
void readButton7State() {

  // If the difference in time between the previous reading is larger than intervalButton
  if (currentMillis - previousButton7Millis > intervalButton) {

    // Read the digital value of the button (LOW/HIGH)
    button7State = digitalRead(button7Pin);

    // If the button has been pushed AND
    // If the button wasn't pressed before AND
    // IF there was not already a measurement running to determine how long the button has been pressed
    if (button7State == HIGH && button7StatePrevious == LOW && !button7StateLongPress) {
      button7LongPressMillis = currentMillis;
      button7StatePrevious = HIGH;
      Serial.println("Button7 pressed");
      msgsent = false;                    //cancela el mensaje enviado
    }

    // Calculate how long the button has been pressed
    button7PressDuration = currentMillis - button7LongPressMillis;

    // If the button is pressed AND
    // If there is no measurement running to determine how long the button is pressed AND
    // If the time the button has been pressed is larger or equal to the time needed for a long press
    if (button7State == HIGH && button6State == LOW && !button7StateLongPress && ((button7PressDuration >= minButtonLongPressDuration) )) {
      button7StateLongPress = true;
      Serial.println("Button7 long pressed");
      longpress7 = true;
    }

    // If the button is released AND
    // If the button was pressed before
    if (button7State == LOW && button7StatePrevious == HIGH) {
      button7StatePrevious = LOW;
      button7StateLongPress = false;
      Serial.println("Button7 released");

      // If there is no measurement running to determine how long the button was pressed AND
      // If the time the button has been pressed is smaller than the minimal time needed for a long press
      // Note: The video shows:
      //       if (!buttonStateLongPress && buttonPressDuration < minButtonLongPressDuration) {
      //       since buttonStateLongPress is set to FALSE on line 75, !buttonStateLongPress is always TRUE
      //       and can be removed.
      if (button7PressDuration < minButtonLongPressDuration) {
        Serial.println("Button7 pressed shortly");
         if (synccounter <= 1){shortpress = false;
        shortpress1 = false;
        shortpress2 = false;
        shortpress3 = false;
        shortpress4 = false;
        shortpress5 = false;
        shortpress6 = false;
        shortpress7 = true;}
      }
    }

    // store the current timestamp in previousButtonMillis
    previousButton7Millis = currentMillis;

  }

}

////////////////////////////////////////////////alt button reading///////////////////////////////////////////
// Function for reading the button8 state
void readButton8State() {

  // If the difference in time between the previous reading is larger than intervalButton
  if (currentMillis - previousButton8Millis > intervalButton) {

    // Read the digital value of the button (LOW/HIGH)
    button8State = digitalRead(button8Pin);

    // If the button has been pushed AND
    // If the button wasn't pressed before AND
    // IF there was not already a measurement running to determine how long the button has been pressed
    if (button8State == HIGH && button8StatePrevious == LOW && !button8StateLongPress) {
      button8LongPressMillis = currentMillis;
      button8StatePrevious = HIGH;
      Serial.println("alt Button pressed");
      msgsent = false;                    //cancela el mensaje enviado
    }

    // Calculate how long the button has been pressed
    button8PressDuration = currentMillis - button8LongPressMillis;

    // If the button is pressed AND
    // If there is no measurement running to determine how long the button is pressed AND
    // If the time the button has been pressed is larger or equal to the time needed for a long press
    if (button8State == HIGH && !button8StateLongPress && ((button8PressDuration >= minButtonLongPressDuration) )) {
      button8StateLongPress = true;
      Serial.println("alt Button long pressed");
      longpress8 = true;
    }

    // If the button is released AND
    // If the button was pressed before
    if (button8State == LOW && button8StatePrevious == HIGH) {
      button8StatePrevious = LOW;
      button8StateLongPress = false;
      Serial.println("alt Button released");

      // If there is no measurement running to determine how long the button was pressed AND
      // If the time the button has been pressed is smaller than the minimal time needed for a long press
      // Note: The video shows:
      //       if (!buttonStateLongPress && buttonPressDuration < minButtonLongPressDuration) {
      //       since buttonStateLongPress is set to FALSE on line 75, !buttonStateLongPress is always TRUE
      //       and can be removed.
      if (button8PressDuration < minButtonLongPressDuration) {
        Serial.println("alt Button pressed shortly");
        shortpress8 = true;
      }
    }

    // store the current timestamp in previousButtonMillis
    previousButton8Millis = currentMillis;

  }

}

/////////////////////////////////////////////sw control off/////////////////////////////////////////////////////
void swcontrol_off () {
  if ((currentMillis - lastSw1Ctrl > 1) && (sw1ctrlstate == HIGH)) {
    digitalWrite (sw1ctrl, LOW);
    Serial.println("sw1ctrl LOW");
    sw1ctrlstate = false;
    lastSw1Ctrl = millis();
  }

  if ((currentMillis - lastSw2Ctrl > 1) && (sw2ctrlstate == HIGH)) {
    digitalWrite (sw2ctrl, LOW);    //desactiva la salida
    Serial.println("sw2ctrl LOW");
    sw2ctrlstate = false;
    lastSw2Ctrl = millis();
  }
  sw1 = digitalRead(A0);
  sw2 = digitalRead(A1);

  if (sw1 == HIGH) {
    Serial.println("A0 high");
  }
  if (sw2 == HIGH) {
    Serial.println("A1 high");
  }
}

////////////////////////////////////////////////sw control short////////////////////////////////////////////
void swcontrol_short_on () {
  //////////1st pair////////////
  if (shortpress == true && currentMillis - lastsynccounter >= 60 ) {
    if (sync == true && syncall == true) 
    {syncrec();}
    
    if (sync == true && syncall == false){
      if (syncallflag == true){syncrec();}}
      
    if (sync == false && syncall == false) {
      //falta agregar la función stop+play(rec) unsynced
      Serial.println("no hay función programada aún");
      Display.showNumberDec(50, false, 2, 0);
    shortpress = false;
    }
  }
  if (shortpress1 == true) {
    if (alt == false){
    Display.setSegments(msg9, 4, 0);
    msgsent = true;
    lastmsgsent = millis();
    shortpress1 = false;}
    if (alt == true){
    Display.setSegments(msg10, 4, 0);
    msgsent = true;
    lastmsgsent = millis();
    shortpress1 = false;}
  }
  //////////2nd pair////////////
  if (shortpress2 == true) {
    Display.showNumberDec(52, false, 2, 0);
    shortpress2 = false;
  }
  if (shortpress3 == true) {
    Display.showNumberDec(53, false, 2, 0);
    shortpress3 = false;
  }
  //////////3rd pair////////////
  if (shortpress4 == true) {
    Display.showNumberDec(54, false, 2, 0);
    shortpress4 = false;
  }
  if (shortpress5 == true) {
    Display.showNumberDec(55, false, 2, 0);
    shortpress5 = false;
  }
  //////////4th pair////////////
  if (shortpress6 == true) {
    if (ntrackuni > 0){ntrackuni = ntrackuni-1;}
        else {ntrackuni = 9;}
    Display.setSegments(msg, 2, 0);
    Display.showNumberDec(ntrackdec, false, 1, 2);
    Display.showNumberDec(ntrackuni, false, 1, 3);
    clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
    Serial.print("track abajo ");
    Serial.print(ntrackdec);
    Serial.println(ntrackuni);
    Serial.print("clicks to be counted = ");
    Serial.println(clickstocount);
    shortpress6 = false;
  }
  if (shortpress7 == true) {
     if (ntrackuni < 9){ntrackuni = ntrackuni+1;}
        else {ntrackuni = 0;}
     Display.setSegments(msg, 2, 0);
     Display.showNumberDec(ntrackdec, false, 1, 2);
     Display.showNumberDec(ntrackuni, false, 1, 3);
     clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
     Serial.print("track arriba ");
     Serial.print(ntrackdec);
    Serial.println(ntrackuni);
     Serial.print("clicks to be counted = ");
    Serial.println(clickstocount);
    shortpress7 = false;
  }
}

//////////////////////////////////////////////sw control long///////////////////////////////////////////
void swcontrol_long_on(){

/////////1st pair/////////
if (longpressboth == true) {
    Display.showNumberDec(81, false, 2, 0);
    Serial.println("longpressboth");
    longpressboth = false;
  }
  if (longpress == true && longpressboth == false) {
    Display.showNumberDec(10, false, 2, 0);
    Serial.println("longpress");
    longpress = false;
  }
  if (longpress1 == true && longpressboth == false) {
    Display.showNumberDec(11, false, 2, 0);
    Serial.println("longpress1");
    longpress1 = false;
  }
/////////2nd pair/////////
  if (longpressboth2 == true) {
    digitalWrite (sw2ctrl, HIGH);         //activa la salida
    Serial.println("sw2ctrl HIGH");
    sw2ctrlstate = true;                  //control de la salida
    lastSw2Ctrl = millis();               //millis control salida
    sync = !sync;
    Display.setSegments(msg3, 4, 0);
    msgsent = true;
    lastmsgsent = millis();
    Serial.println("longpressboth2 toogle sync");
    longpressboth2 = false;
  }
  if (longpress2 == true && longpressboth2 == false) {
    Display.showNumberDec(12, false, 2, 0);
    Serial.println("longpress2");
    longpress2 = false;
  }
  if (longpress3 == true && longpressboth2 == false) {
    Display.showNumberDec(13, false, 2, 0);
    Serial.println("longpress3");
    longpress3 = false;
  }
/////////3rd pair/////////
  if (longpressboth3 == true) {
    menu_active = true;
    Serial.println("entrando al menu");
    Display.setSegments(msg6, 4, 0);
    delay(750);
    Display.setSegments(msg5, 4, 0);
    delay(750);
    Serial.println("longpressboth3");
    longpressboth3 = false;
  }
  if (longpress4 == true && longpressboth3 == false) {
    Display.showNumberDec(14, false, 2, 0);
    Serial.println("longpress4");
    longpress4 = false;
  }
  if (longpress5 == true && longpressboth3 == false) {
    Display.showNumberDec(15, false, 2, 0);
    Serial.println("longpress5");
    longpress5 = false;
  }
/////////4th pair/////////
  if (longpressboth4 == true) {
    Display.showNumberDec(84, false, 2, 0);
    Serial.println("longpressboth4");
    longpressboth4 = false;
  }
  if (longpress6 == true && longpressboth4 == false) {
    Display.showNumberDec(16, false, 2, 0);
    Serial.println("longpress6");
    longpress6 = false;
  }
  if (longpress7 == true && longpressboth4 == false) {
    Display.showNumberDec(17, false, 2, 0);
    Serial.println("longpress7");
    longpress7 = false;
  }
}
////////////////////////////////////////////////sync rec function/////////////////////////////////////////////
void syncrec(){
  synccounter = synccounter+1;                  //incrementa el contador de controlsync
    Serial.print ("synccounter = ");
    Serial.println (synccounter);
    
    if (synccounter == 1){
    digitalWrite (sw1ctrl, HIGH);       //activa la salida
    Serial.println("sw1ctrl 4066 HIGH primera vez");
    lastsynccounter = millis();             //millis control salida
    sw1ctrlstate = true;                //control de la salida
    Display.showNumberDec(50, false, 2, 0);
    }
    if (synccounter >= clickstocount+1){
    digitalWrite (sw1ctrl, HIGH);       //activa la salida
    Serial.println("sw1ctrl 4066 HIGH segunda vez");
    lastsynccounter = millis();             //millis control salida
    sw1ctrlstate = true;                //control de la salida
    Display.showNumberDec(50, false, 2, 0);
    shortpress = false;
    synccounter = 0;
    }
}
void syncreccancel(){
    synccounter = 0;
    shortpress = false;
    Serial.println("operación cancelada");
    Serial.print("sync counter = ");
    Serial.println(synccounter);
    return;
}
////////////////////////////////////////////////sw alt control//////////////////////////////////////
void swaltcontrol(){

  //////////alt button////////////
  if (shortpress8 == true) {
    alt = !alt;
    Serial.print("alt toogled ");
    Serial.println(alt);
    Display.clear();
    Display.setSegments(msg8, 3, 1);
    msgsent = true;
    lastmsgsent = millis();
    shortpress8 = false;
  }

  if (longpress8 == true) {
    syncall = !syncall;
    Display.clear();
    Display.setSegments(msg4, 3, 1);
    msgsent = true;
    lastmsgsent = millis();
    Serial.println("sync all");
    longpress8 = false;
  }
}
////////////////////////////////////////////////menu functions////////////////////////////////////////////
void menu_1(){
  Display.setSegments(msg, 2, 0);
  Display.showNumberDec(ntrackdec, false, 1, 2);
  Display.showNumberDec(ntrackuni, false, 1, 3);
}

void accion_1(){
   while (select == LOW){
        menu_3();
    
    if (cursor1 == false){                                          //estamos en unidades
      if ((currentMillis - lastunimillis > 250)){
        if (showunidigit == true){
        Display.showNumberDec(ntrackuni, false, 1, 3);
        }
        if (showunidigit == false){
        Display.setSegments(blank, 1, 3);
        }
        showunidigit = !showunidigit;
        lastunimillis = millis();
      }
      arriba = digitalRead(19);
      if ((arriba == HIGH) && (currentMillis - lastarriba > 350)){
        if (ntrackuni < 9){ntrackuni = ntrackuni+1;}
        else {ntrackuni = 0;
        ntrackdec = ntrackdec+1;
        Display.showNumberDec(ntrackdec, false, 1, 2);}
        lastarriba = millis();
      }
       abajo = digitalRead(18);
      if ((abajo == HIGH) && (currentMillis - lastarriba > 350)){
        if (ntrackuni > 0){ntrackuni = ntrackuni-1;}
        else {ntrackuni = 9;
        if (ntrackdec != 0){
        ntrackdec = ntrackdec-1;
        Display.showNumberDec(ntrackdec, false, 1, 2);}}
        lastarriba = millis();
      }
      
    }

    if (cursor1 == true){                                          //estamos en decenas
       if ((currentMillis - lastdecmillis > 250)){
        if (showdecdigit == true){
        Display.showNumberDec(ntrackdec, false, 1, 2);
        }
        if (showdecdigit == false){
        Display.setSegments(blank, 1, 2);
        }
        showdecdigit = !showdecdigit;
        lastdecmillis = millis();
      }
      arriba = digitalRead(19);
      if ((arriba == HIGH) && (currentMillis - lastarriba > 350)){
        if (ntrackdec < 9){ntrackdec = ntrackdec+1;}
        else {ntrackdec = 0;}
        lastarriba = millis();
      }
       abajo = digitalRead(18);
      if ((abajo == HIGH) && (currentMillis - lastabajo > 350)){
        if (ntrackdec > 0){ntrackdec = ntrackdec-1;}
        else {ntrackdec = 9;}
        lastabajo = millis();
      }
      
    }
    cursorpin = digitalRead(3);
    if ((cursorpin == HIGH)&&(currentMillis - lastcursorpin > 250)){
      Display.showNumberDec(ntrackdec, false, 1, 2);
      Display.showNumberDec(ntrackuni, false, 1, 3);
      cursor1 = !cursor1;
      lastcursorpin = millis();
    }
    currentMillis = millis();
    select = digitalRead(2);
    menu_out = digitalRead(4);             //boton 4 para salir del menú
    
    if (menu_out == true && currentMillis - lastmenu_out > 500){
    menustate = 1;
    menu_active = false;
    menu_out = false;
    cursor1 = false;
    lastmenu_out = millis();
    Display.setSegments(msg7, 4, 0);
    delay (750);
    return;
  }
  }
  if (select == HIGH && currentMillis - lastselect > 500){
    menustate = 2;
    select = LOW;
    cursor1 = false;
    lastselect = millis();
    delay (300);
  }
}

void menu_2(){
  Display.setSegments(msg2, 2, 0);
  nclicksuni = trackuniarray[ntrackuni];
  nclicksdec = trackdecarray[ntrackuni];
  Display.showNumberDec(nclicksdec, false, 1, 2);
  Display.showNumberDec(nclicksuni, false, 1, 3);
  

}

void accion_2(){     
     while (select == LOW){
        menu_3();
      
    if (cursor1 == false){                                          //estamos en unidades
      if ((currentMillis - lastunimillis > 250)){
        if (showunidigit == true){
        Display.showNumberDec(nclicksuni, false, 1, 3);
        }
        if (showunidigit == false){
        Display.setSegments(blank, 1, 3);
        }
        showunidigit = !showunidigit;
        lastunimillis = millis();
      }
      arriba = digitalRead(19);
      if ((arriba == HIGH) && (currentMillis - lastarriba > 350)){
        if (nclicksuni < 9){nclicksuni = nclicksuni+1;}
        else {nclicksuni = 0;
        nclicksdec = nclicksdec+1;
        Display.showNumberDec(nclicksdec, false, 1, 2);}
        lastarriba = millis();
      }
       abajo = digitalRead(18);
      if ((abajo == HIGH) && (currentMillis - lastarriba > 350)){
        if (nclicksuni > 0){nclicksuni = nclicksuni-1;}
        else {nclicksuni = 9;
         if (nclicksdec != 0){
        nclicksdec = nclicksdec-1;
        Display.showNumberDec(nclicksdec, false, 1, 2);}}
        lastarriba = millis();
      }
      
    }

    if (cursor1 == true){                                          //estamos en decenas
       if ((currentMillis - lastdecmillis > 250)){
        if (showdecdigit == true){
        Display.showNumberDec(nclicksdec, false, 1, 2);
        }
        if (showdecdigit == false){
        Display.setSegments(blank, 1, 2);
        }
        showdecdigit = !showdecdigit;
        lastdecmillis = millis();
      }
      arriba = digitalRead(19);
      if ((arriba == HIGH) && (currentMillis - lastarriba > 350)){
        if (nclicksdec < 9){nclicksdec = nclicksdec+1;}
        else {nclicksdec = 0;}
        lastarriba = millis();
      }
      abajo = digitalRead(18);
      if ((abajo == HIGH) && (currentMillis - lastarriba > 350)){
        if (nclicksdec > 0){nclicksdec = nclicksdec-1;}
        else {nclicksdec = 9;}
        lastarriba = millis();
      }
      
    }
    cursorpin = digitalRead(3);
    if ((cursorpin == HIGH)&&(currentMillis - lastcursorpin > 250)){
      Display.showNumberDec(nclicksdec, false, 1, 2);
      Display.showNumberDec(nclicksuni, false, 1, 3);
      cursor1 = !cursor1;
      lastcursorpin = millis();
    }
    currentMillis = millis();
    select = digitalRead(2);
  } 
  if (select == HIGH && currentMillis - lastselect > 500){
    trackdecarray[ntrackuni] = nclicksdec;    //guarda valores en el arreglo
    trackuniarray[ntrackuni] = nclicksuni;
    menustate = 1;
    select = LOW;
    cursor1 = false;
    lastselect = millis();
    delay (300);
  }
}

void menu_3(){
   mostrararray = digitalRead(7);

    if (mostrararray == HIGH && currentMillis - lastmostrararray > 500){
      Serial.print("array [0] = "); Serial.print(trackdecarray[0]);Serial.println(trackuniarray[0]);
      Serial.print("array [1] = "); Serial.print(trackdecarray[1]);Serial.println(trackuniarray[1]);
      Serial.print("array [2] = "); Serial.print(trackdecarray[2]);Serial.println(trackuniarray[2]);
      Serial.print("array [3] = "); Serial.print(trackdecarray[3]);Serial.println(trackuniarray[3]);
      Serial.print("array [4] = "); Serial.print(trackdecarray[4]);Serial.println(trackuniarray[4]);
      Serial.print("array [5] = "); Serial.print(trackdecarray[5]);Serial.println(trackuniarray[5]);
      Serial.print("array [6] = "); Serial.print(trackdecarray[6]);Serial.println(trackuniarray[6]);
      Serial.print("array [7] = "); Serial.print(trackdecarray[7]);Serial.println(trackuniarray[7]);
      Serial.print("array [8] = "); Serial.print(trackdecarray[8]);Serial.println(trackuniarray[8]);
      Serial.print("array [9] = "); Serial.print(trackdecarray[9]);Serial.println(trackuniarray[9]);

      mostrararray = LOW;
      lastmostrararray = millis();}
}

/////////////////////////////////////////////////sync//////////////////////////////////////////////////////
void syncfn() {

    if ((syncallflag == true) && (currentMillis - lastsyncallflag >= 50)){
      syncallflag = false;
//      Serial.println("syncall flag false");
    }
  
  //currentMillis = millis();
  // read the input on analog pin 7:
  int sensorValue = analogRead(A7);
  // print out the value you read:
  if ((sensorValue >= 50) && (currentMillis - lastsyncread >= 50)) {
    syncallflag = true;
//    Serial.println("syncall flag true");
    lastsyncallflag == millis();
    digitalWrite(ledpin, HIGH);
    Serial.println(sensorValue);
    lastsyncread = millis();
  }
  else {
    digitalWrite(ledpin, LOW);
  }
}
void loop() {
  currentMillis = millis();    // store the current time
  if (msgsent == true && currentMillis - lastmsgsent >= 2000){//mantiene mensajes por 2 segundos en pantalla
    inicio();
    msgsent = false;
  }
  readButtonState();           // read the button state
  readButton1State();
  readButton2State();
  readButton3State();
  readButton4State();
  readButton5State();
  readButton6State();
  readButton7State();
  readButton8State();
  if (sync == true) {
    syncfn ();
  }
  if (syncall == true){
    if (syncallflag == true){swcontrol_short_on();}} //si se activa syncall espera a la flag para activar las salidas
  if (syncall == false){
    swcontrol_short_on();}        //si se desactiva syncall activa salidas sin esperar
  swcontrol_long_on();
  swaltcontrol();
  swcontrol_off ();
  if (menu_active == true){
    if(menustate == 3){menu_3();}
    if(menustate == 2){menu_2(); accion_2();}
    if(menustate == 1){menu_1(); accion_1();}
    inicio ();
  }
}
