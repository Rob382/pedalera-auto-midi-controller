/*
 * Bas on Tech - LONG PRESS BUTTON
 * This course is part of the courses on https://arduino-tutorials.net
 *  
 * (c) Copyright 2019 - Bas van Dijk / Bas on Tech
 * This code and course is copyrighted. It is not allowed to use these courses commercially
 * without explicit written approval
 * 
 * YouTube:    https://www.youtube.com/c/BasOnTech
 * Facebook:   https://www.facebook.com/BasOnTechChannel
 * Instagram:  https://www.instagram.com/BasOnTech
 * Twitter:    https://twitter.com/BasOnTech
 *
 */
//7seg display
#include <TM1637Display.h>
#define CLK 6
#define DIO 5
TM1637Display Display(CLK, DIO);

//// SWITCH 1 ////

static const int buttonPin = 4;                    // switch pin
int buttonStatePrevious = LOW;                      // previousstate of the switch

unsigned long minButtonLongPressDuration = 3000;    // Time we wait before we see the press as a long press
unsigned long buttonLongPressMillis;                // Time in ms when we the button was pressed
bool buttonStateLongPress = false;                  // True if it is a long press

const int intervalButton = 50;                      // Time between two readings of the button state
unsigned long previousButtonMillis;                 // Timestamp of the latest reading

unsigned long buttonPressDuration;                  // Time the button is pressed in ms

//// SWITCH 2 ////

static const int button1Pin = 3;                    // switch pin
int button1StatePrevious = LOW;                      // previousstate of the switch

unsigned long button1LongPressMillis;                // Time in ms when we the button was pressed
bool button1StateLongPress = false;                  // True if it is a long press

unsigned long previousButton1Millis;                 // Timestamp of the latest reading

unsigned long button1PressDuration;  

//// GENERAL ////
int buttonState;
int button1State;
bool  bothchecker = false;
bool bothbuttonsStateLongPress = false;
bool shortpress = false;
bool shortpress1 = false;
bool longpress = false;
bool longpress1 = false;
bool longpressboth = false;

unsigned long currentMillis;          // Variabele to store the number of milleseconds since the Arduino has started

void setup() {
  Serial.begin(9600);                 // Initialise the serial monitor

  pinMode(buttonPin, INPUT);          // set buttonPin as input
  Serial.println("Press button");

  Display.setBrightness(5);

}

// Function for reading the button state
void readButtonState() {

  // If the difference in time between the previous reading is larger than intervalButton
  if(currentMillis - previousButtonMillis > intervalButton) {
    
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
    if  (button1State == HIGH && buttonState == HIGH && !button1StateLongPress && !buttonStateLongPress && ((buttonPressDuration >= minButtonLongPressDuration) )){
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
      if (buttonPressDuration < minButtonLongPressDuration){
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
  if(currentMillis - previousButton1Millis > intervalButton) {
    
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
    if (button1State == HIGH && buttonState == LOW &&!button1StateLongPress && ((button1PressDuration >= minButtonLongPressDuration) )) {
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

void sw_number (){
  if (shortpress == true){
  Display.showNumberDec(51, false, 2, 0);
  shortpress = false;
  }
  if (shortpress1 == true){
  Display.showNumberDec(52, false, 2, 0);
  shortpress1 = false;
  }

  if (longpressboth == true){
  Display.showNumberDec(81, false, 2, 0);
  Serial.println("longpressboth");
  longpressboth = false;
  }
   if (longpress == true && longpressboth == false){
  Display.showNumberDec(11, false, 2, 0);
  Serial.println("longpress");
  longpress = false;}
  if (longpress1 == true && longpressboth == false){
  Display.showNumberDec(12, false, 2, 0);
  Serial.println("longpress1");
  longpress1 = false;}

}
void loop() {

  currentMillis = millis();    // store the current time
  readButtonState();           // read the button state
  readButton1State();
  sw_number ();
}
