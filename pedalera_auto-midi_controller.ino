//7seg display
#include <TM1637Display.h>
#define CLK 6
#define DIO 5
TM1637Display Display(CLK, DIO);

///////////////////////////////////////////1st PAIR OF BUTTONS///////////////////////////////////////////
bool  bothchecker = false;
bool longpressboth = false;

//// SWITCH 0 ////

static const int buttonPin = 4;                    // switch pin
int buttonStatePrevious = LOW;                      // previousstate of the switch

unsigned long buttonLongPressMillis;                // Time in ms when we the button was pressed
bool buttonStateLongPress = false;                  // True if it is a long press

unsigned long previousButtonMillis;                 // Timestamp of the latest reading

unsigned long buttonPressDuration;                  // Time the button is pressed in ms

int buttonState;
bool shortpress = false;
bool longpress = false;

//// SWITCH 1 ////

static const int button1Pin = 3;                    // switch pin
int button1StatePrevious = LOW;                      // previousstate of the switch

unsigned long button1LongPressMillis;                // Time in ms when we the button was pressed
bool button1StateLongPress = false;                  // True if it is a long press

unsigned long previousButton1Millis;                 // Timestamp of the latest reading

unsigned long button1PressDuration;

int button1State;
bool shortpress1 = false;
bool longpress1 = false;

///////////////////////////////////////////2nd PAIR OF BUTTONS///////////////////////////////////////////
bool  bothchecker2 = false;
bool longpressboth2 = false;

//// SWITCH 2 ////

static const int button2Pin = 7;                    // switch pin
int button2StatePrevious = LOW;                      // previousstate of the switch

unsigned long button2LongPressMillis;                // Time in ms when we the button was pressed
bool button2StateLongPress = false;                  // True if it is a long press

unsigned long previousButton2Millis;                 // Timestamp of the latest reading

unsigned long button2PressDuration;                  // Time the button is pressed in ms

int button2State;
bool shortpress2 = false;
bool longpress2 = false;

//// SWITCH 3 ////

static const int button3Pin = 8;                    // switch pin
int button3StatePrevious = LOW;                      // previousstate of the switch

unsigned long button3LongPressMillis;                // Time in ms when we the button was pressed
bool button3StateLongPress = false;                  // True if it is a long press

unsigned long previousButton3Millis;                 // Timestamp of the latest reading

unsigned long button3PressDuration;

int button3State;
bool shortpress3 = false;
bool longpress3 = false;

///////////////////////////////////////////3rd PAIR OF BUTTONS///////////////////////////////////////////
bool  bothchecker3 = false;
bool longpressboth3 = false;

//// SWITCH 4 ////

static const int button4Pin = 11;                    // switch pin
int button4StatePrevious = LOW;                      // previousstate of the switch

unsigned long button4LongPressMillis;                // Time in ms when we the button was pressed
bool button4StateLongPress = false;                  // True if it is a long press

unsigned long previousButton4Millis;                 // Timestamp of the latest reading

unsigned long button4PressDuration;                  // Time the button is pressed in ms

int button4State;
bool shortpress4 = false;
bool longpress4 = false;

//// SWITCH 5 ////
int analogsw5read;

static const int button5Pin = 16;                    // switch pin
int button5StatePrevious = LOW;                      // previousstate of the switch

unsigned long button5LongPressMillis;                // Time in ms when we the button was pressed
bool button5StateLongPress = false;                  // True if it is a long press

unsigned long previousButton5Millis;                 // Timestamp of the latest reading

unsigned long button5PressDuration;

int button5State;
bool shortpress5 = false;
bool longpress5 = false;

///////////////////////////////////////////4th PAIR OF BUTTONS///////////////////////////////////////////
bool  bothchecker4 = false;
bool longpressboth4 = false;

//// SWITCH 6 ////

static const int button6Pin = 18;                    // A6
int button6StatePrevious = LOW;                      // previousstate of the switch

unsigned long button6LongPressMillis;                // Time in ms when we the button was pressed
bool button6StateLongPress = false;                  // True if it is a long press

unsigned long previousButton6Millis;                 // Timestamp of the latest reading

unsigned long button6PressDuration;                  // Time the button is pressed in ms

int button6State;
bool shortpress6 = false;
bool longpress6 = false;

//// SWITCH 7 ////

static const int button7Pin = 19;                    // A7
int button7StatePrevious = LOW;                      // previousstate of the switch

unsigned long button7LongPressMillis;                // Time in ms when we the button was pressed
bool button7StateLongPress = false;                  // True if it is a long press

unsigned long previousButton7Millis;                 // Timestamp of the latest reading

unsigned long button7PressDuration;

int button7State;
bool shortpress7 = false;
bool longpress7 = false;

////////////////////////////////////////////switch 8 (alt)/////////////////////////////////////////////

//// SWITCH 8 alt  ////

static const int button8Pin = 2;                    // switch pin
int button8StatePrevious = LOW;                      // previousstate of the switch

unsigned long button8LongPressMillis;                // Time in ms when we the button was pressed
bool button8StateLongPress = false;                  // True if it is a long press

unsigned long previousButton8Millis;                 // Timestamp of the latest reading

unsigned long button8PressDuration;

int button8State;
bool shortpress8 = false;
bool longpress8 = false;

////////////////////////////////////////////////// GENERAL /////////////////////////////////////////////
unsigned long minButtonLongPressDuration = 3000;    // Time we wait before we see the press as a long press
const int intervalButton = 50;                      // Time between two readings of the button state

unsigned long currentMillis;          // Variabele to store the number of milleseconds since the Arduino has started

unsigned long lastsyncread = 0;
bool sync = false;

int ledpin = 13;

////////////////////////////////////////////switches del cd4066/////////////////////////////////////////////
int sw1;
int sw2;
const int sw1ctrl = 9;
const int sw2ctrl = 10;
unsigned long lastSw1Ctrl = 0;
unsigned long lastSw2Ctrl = 0;
bool sw1ctrlstate;
bool sw2ctrlstate;




void setup() {
  Serial.begin(9600);                 // Initialise the serial monitor

  pinMode(buttonPin, INPUT);          // set buttonPin as input
  pinMode(button1Pin, INPUT);          // set buttonPin as input
  pinMode(button2Pin, INPUT);          // set buttonPin as input
  pinMode(button3Pin, INPUT);          // set buttonPin as input
  pinMode(button4Pin, INPUT);          // set buttonPin as input
  pinMode(button5Pin, INPUT);          // set buttonPin as input
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
        Serial.println("Button1 pressed shortly");
        shortpress1 = true;
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
        shortpress2 = true;
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
        shortpress3 = true;
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
        shortpress4 = true;
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
        shortpress5 = true;
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
        shortpress6 = true;
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
        shortpress7 = true;
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

/////////////////////////////////////////////sw control/////////////////////////////////////////////////////
void swcontrl () {
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

////////////////////////////////////////////////display sw pushed////////////////////////////////////////////
void sw_number () {
  //////////1st pair////////////
  if (shortpress == true) {
    digitalWrite (sw1ctrl, HIGH);       //activa la salida
    Serial.println("sw1ctrl HIGH");
    lastSw1Ctrl = millis();             //millis control salida
    sw1ctrlstate = true;                //control de la salida
    Display.showNumberDec(50, false, 2, 0);
    shortpress = false;
  }

  if (shortpress1 == true) {
    Display.showNumberDec(51, false, 2, 0);
    shortpress1 = false;
  }

  if (longpressboth == true) {
    digitalWrite (sw2ctrl, HIGH);         //activa la salida
    Serial.println("sw2ctrl HIGH");
    sw2ctrlstate = true;                  //control de la salida
    lastSw2Ctrl = millis();               //millis control salida
    sync = !sync;
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

  //////////2nd pair////////////
  if (shortpress2 == true) {
    Display.showNumberDec(52, false, 2, 0);
    shortpress2 = false;
  }

  if (shortpress3 == true) {
    Display.showNumberDec(53, false, 2, 0);
    shortpress3 = false;
  }

  if (longpressboth2 == true) {
    Display.showNumberDec(82, false, 2, 0);
    Serial.println("longpressboth2");
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

  //////////3rd pair////////////
  if (shortpress4 == true) {
    Display.showNumberDec(54, false, 2, 0);
    shortpress4 = false;
  }

  if (shortpress5 == true) {
    Display.showNumberDec(55, false, 2, 0);
    shortpress5 = false;
  }

  if (longpressboth3 == true) {
    Display.showNumberDec(83, false, 2, 0);
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

  //////////4th pair////////////
  if (shortpress6 == true) {
    Display.showNumberDec(56, false, 2, 0);
    shortpress6 = false;
  }

  if (shortpress7 == true) {
    Display.showNumberDec(57, false, 2, 0);
    shortpress7 = false;
  }

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

  //////////alt button////////////
  if (shortpress8 == true) {
    Display.showNumberDec(58, false, 2, 0);
    shortpress8 = false;
  }

  if (longpress8 == true) {
    Display.showNumberDec(18, false, 2, 0);
    Serial.println("longpress8");
    longpress8 = false;
  }
}

/////////////////////////////////////////////////sync//////////////////////////////////////////////////////
void syncfn() {
  currentMillis = millis();
  // read the input on analog pin 7:
  int sensorValue = analogRead(A7);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  if ((sensorValue >= 50) && (currentMillis - lastsyncread >= intervalButton)) {
    digitalWrite(ledpin, HIGH);
    Serial.println(sensorValue);
//    Display.showNumberDecEx(99, 0b01000000, false, 2, 0);
    lastsyncread = millis();
  }
  else {
    digitalWrite(ledpin, LOW);
//    Display.showNumberDecEx(9, 0b00000000, false, 1, 3);
  }
}
void loop() {

  currentMillis = millis();    // store the current time
  readButtonState();           // read the button state
  readButton1State();
  readButton2State();
  readButton3State();
  readButton4State();
  readButton5State();
  readButton6State();
  readButton7State();
  readButton8State();
  sw_number ();
  swcontrl ();
  if (sync == true) {
    syncfn ();
  }
}
