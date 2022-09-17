/*
   Bas on Tech - LONG PRESS BUTTON
   This course is part of the courses on https://arduino-tutorials.net

   (c) Copyright 2019 - Bas van Dijk / Bas on Tech
   This code and course is copyrighted. It is not allowed to use these courses commercially
   without explicit written approval

   YouTube:    https://www.youtube.com/c/BasOnTech
   Facebook:   https://www.facebook.com/BasOnTechChannel
   Instagram:  https://www.instagram.com/BasOnTech
   Twitter:    https://twitter.com/BasOnTech

*/
//7seg display
#include <TM1637Display.h>
#define CLK 6
#define DIO 5
TM1637Display Display(CLK, DIO);

///////////////////////////////////////////1st PAIR OF BUTTONS///////////////////////////////////////////
byte  bothchecker = false;
byte longpressboth = false;

//// SWITCH 0 ////

#define buttonPin 4                    // switch pin
byte buttonStatePrevious = LOW;                      // previousstate of the switch

unsigned long buttonLongPressMillis;                // Time in ms when we the button was pressed
byte buttonStateLongPress = false;                  // True if it is a long press

unsigned long previousButtonMillis;                 // Timestamp of the latest reading

unsigned long buttonPressDuration;                  // Time the button is pressed in ms

byte buttonState;
byte shortpress = false;
byte longpress = false;

//// SWITCH 1 ////

#define button1Pin 3                    // switch pin
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

#define button2Pin 7                    // switch pin
byte button2StatePrevious = LOW;                      // previousstate of the switch

unsigned long button2LongPressMillis;                // Time in ms when we the button was pressed
byte button2StateLongPress = false;                  // True if it is a long press

unsigned long previousButton2Millis;                 // Timestamp of the latest reading

unsigned long button2PressDuration;                  // Time the button is pressed in ms

byte button2State;
byte shortpress2 = false;
byte longpress2 = false;

//// SWITCH 3 ////

#define button3Pin 8                    // switch pin
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

#define button4Pin 11                    // switch pin
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

#define button6Pin 18                    // A6
byte button6StatePrevious = LOW;                      // previousstate of the switch

unsigned long button6LongPressMillis;                // Time in ms when we the button was pressed
byte button6StateLongPress = false;                  // True if it is a long press

unsigned long previousButton6Millis;                 // Timestamp of the latest reading

unsigned long button6PressDuration;                  // Time the button is pressed in ms

byte button6State;
byte shortpress6 = false;
byte longpress6 = false;

//// SWITCH 7 ////

#define button7Pin 19                    // A7
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

#define button8Pin 2                    // switch pin
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

byte oneshotaction = false;                 //variable para comprobar acciones oneshot

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
const uint8_t msg12[] = {
  SEG_C | SEG_E | SEG_G,                          //n
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
  const uint8_t msg11[] = {
  SEG_A | SEG_C | SEG_D | SEG_G | SEG_F,          //S
  SEG_B | SEG_C | SEG_D | SEG_G | SEG_F,          //Y
  SEG_C | SEG_B | SEG_D | SEG_E | SEG_F,          //u
  SEG_C | SEG_E | SEG_G,                          //n
  };
/////////////////////////////////////rec messages///////////////////
  const uint8_t msg13[] = {
  SEG_E | SEG_G,                                  //r
  SEG_A | SEG_E | SEG_D | SEG_G | SEG_F,          //E
  SEG_A | SEG_D | SEG_E | SEG_F,                  //C
  };
    const uint8_t msg14[] = {
  SEG_C | SEG_B | SEG_D | SEG_E | SEG_G,          //d
  SEG_C | SEG_D | SEG_E | SEG_G,                  //o
  SEG_C | SEG_E | SEG_G,                          //n
  SEG_A | SEG_E | SEG_D | SEG_G | SEG_F,          //E
  };
    const uint8_t msg15[] = {
  SEG_A | SEG_D | SEG_E | SEG_F,                  //C
  SEG_A | SEG_B | SEG_C | SEG_G | SEG_E | SEG_F,  //A
  SEG_C | SEG_E | SEG_G,                          //n
  SEG_A | SEG_D | SEG_E | SEG_F,                  //C
  };
  /////////////////////////////////////next+rec prev+rec messages///////////////////
  const uint8_t msg16[] = {
    SEG_C | SEG_E | SEG_G,                          //n
    SEG_B | SEG_C | SEG_G | SEG_E | SEG_F,          //H/x
    SEG_G | SEG_D | SEG_E | SEG_F,                  //t
    SEG_E | SEG_G,                                  //r
    };
    const uint8_t msg17[] = {
    SEG_A | SEG_B | SEG_G | SEG_E | SEG_F,          //P
    SEG_E | SEG_G,                                  //r
    SEG_A | SEG_E | SEG_D | SEG_G | SEG_F,          //E
    SEG_E | SEG_G,                                  //r
    };
    const uint8_t msg19[] = {
    SEG_A | SEG_C | SEG_D | SEG_G | SEG_F,          //S
    SEG_A | SEG_C | SEG_D | SEG_G | SEG_F,          //S
    SEG_G | SEG_D | SEG_E | SEG_F,                  //t
    SEG_A | SEG_B | SEG_G | SEG_E | SEG_F,          //P
    };
    const uint8_t msg18[] = {
    SEG_A | SEG_C | SEG_D | SEG_G | SEG_F,          //S
    SEG_A | SEG_B | SEG_G | SEG_E | SEG_F,          //P
    SEG_D | SEG_E | SEG_F,                          //L
    SEG_A | SEG_B | SEG_C | SEG_G | SEG_E | SEG_F,  //A
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
