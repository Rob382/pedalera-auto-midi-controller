
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
byte shortpress01 = false;
byte shortpress0 = false;
byte longpress01 = false;
byte longpress0 = false;
byte longpressboth1 = false;
//// SWITCH 0 ////

byte buttonPin = 4;                    // switch pin
byte buttonStatePrevious = LOW;                      // previousstate of the switch

unsigned long buttonLongPressMillis;                // Time in ms when we the button was pressed
byte buttonStateLongPress = false;                  // True if it is a long press

unsigned long previousButtonMillis;                 // Timestamp of the latest reading

unsigned long buttonPressDuration;                  // Time the button is pressed in ms

byte buttonState;
byte shortpress = false;
byte longpress = false;

byte button0pressed = false;

//// SWITCH 1 ////

byte button1Pin = 3;                    // switch pin
byte button1StatePrevious = LOW;                      // previousstate of the switch

unsigned long button1LongPressMillis;                // Time in ms when we the button was pressed
byte button1StateLongPress = false;                  // True if it is a long press

unsigned long previousButton1Millis;                 // Timestamp of the latest reading

unsigned long button1PressDuration;

byte button1State;
byte shortpress1 = false;
byte longpress1 = false;

byte button1pressed = false;

///////////////////////////////////////////2nd PAIR OF BUTTONS///////////////////////////////////////////
byte longpressboth2 = false;
//// SWITCH 2 ////
byte shortpress2 = false;
byte longpress2 = false;
byte button2pressed = false;
//// SWITCH 3 ////
byte shortpress3 = false;
byte longpress3 = false;
byte button3pressed = false;

///////////////////////////////////////////3rd PAIR OF BUTTONS///////////////////////////////////////////
byte longpressboth3 = false;
//// SWITCH 4 ////
byte shortpress4 = false;
byte longpress4 = false;
byte button4pressed = false;
//// SWITCH 5 ////
byte shortpress5 = false;
byte longpress5 = false;
byte button5pressed = false;

///////////////////////////////////////////4th PAIR OF BUTTONS///////////////////////////////////////////
byte longpressboth4 = false;
//// SWITCH 6 ////
byte shortpress6 = false;
byte longpress6 = false;
byte button6pressed = false;
//// SWITCH 7 ////
byte shortpress7 = false;
byte longpress7 = false;
byte button7pressed = false;

////////////////////////////////////////////switch 8 (alt)/////////////////////////////////////////////
int button8Pin;                    // switch pin
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
unsigned long minButtonLongPressDuration = 1500;    // Time we wait before we see the press as a long press
const int intervalButton = 50;                      // Time between two readings of the button state

unsigned long currentMillis;          // Variabele to store the number of milleseconds since the Arduino has started

unsigned long lastsyncread = 0;
unsigned long lastledsyncread = 0;
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
byte singlemsg = false;                          //para cmprobar mensajes de una sola activación

byte out_release_flag = true;
byte out_release_flag1 = true;
byte buttoncomp = false;
byte buttoncomp1 = false;

byte synced_rec = false;                    //variable para mantener activo el sync rec con contador
byte prevplaysw = false;                    //mantiene activo prev rec
byte nextplaysw = false;                    //mantiene activo next rec
byte undo_button = false;
byte syncedundo = false;
byte stop_next = false;
byte stop_prev = false;

byte sum_botton_pessed = false;
byte displayallowed = false;

////////////////////////////////////////////switches del cd4066/////////////////////////////////////////////
byte sw1;
byte sw2;
const int sw1ctrl = 9;
const int sw2ctrl = 10;
const int sw3ctrl = 14;
const int sw4ctrl = 16;
const int sw5ctrl = 15;
unsigned long lastSw1Ctrl = 0;
unsigned long lastSw2Ctrl = 0;
unsigned long lastSw3Ctrl = 0;
unsigned long lastSw4Ctrl = 0;
unsigned long lastSw5Ctrl = 0;
byte sw1ctrlstate;
byte sw2ctrlstate;
byte sw3ctrlstate;
byte sw4ctrlstate;
byte sw5ctrlstate;

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
/////////////////////////////////////////////letras//////////////////////////////////////
const uint8_t letter_T[] = {SEG_G | SEG_D | SEG_E | SEG_F,};
const uint8_t letter_R[] = {SEG_E | SEG_G,};
const uint8_t blank[] = {SEG_D,};
const uint8_t letter_C[] = {SEG_A | SEG_D | SEG_E | SEG_F,};
const uint8_t letter_L[] = {SEG_D | SEG_E | SEG_F,};
const uint8_t letter_S[] = {SEG_A | SEG_C | SEG_D | SEG_G | SEG_F,};          //S
const uint8_t letter_Y[] = {SEG_B | SEG_C | SEG_D | SEG_G | SEG_F,};          //Y
const uint8_t letter_N[] = {SEG_C | SEG_E | SEG_G,};                          //n
const uint8_t letter_A[] = {SEG_A | SEG_B | SEG_C | SEG_G | SEG_E | SEG_F,};
const uint8_t letter_O[] = {SEG_C | SEG_D | SEG_E | SEG_G,};                  //o
const uint8_t letter_F[] = {SEG_A | SEG_G | SEG_E | SEG_F,};                  //F
const uint8_t letter_G[] = {SEG_A | SEG_B | SEG_D | SEG_C | SEG_G | SEG_F,};  //g
const uint8_t letter_I[] = {SEG_B | SEG_C,};
const uint8_t letter_P[] = {SEG_A | SEG_B | SEG_G | SEG_E | SEG_F,};
const uint8_t letter_U[] = {SEG_C | SEG_B | SEG_D | SEG_E | SEG_F,};
const uint8_t letter_D[] = {SEG_C | SEG_B | SEG_D | SEG_E | SEG_G,};
const uint8_t letter_E[] = {SEG_A | SEG_E | SEG_D | SEG_G | SEG_F,};
const uint8_t letter_X[] = {SEG_B | SEG_C | SEG_G | SEG_E | SEG_F,};

//     para saber el tiempo que tardan las acciones
//unsigned long resta1 = 0;
//unsigned long restaresultado = 0;
//unsigned long resta2 = 0;

//resta1 = millis();
//        resta2 = millis();
//        restaresultado = resta2 - resta1;
//        Serial.print("resta resultado = ");
//        Serial.println(restaresultado);
void setup() {
  Serial.begin(9600);                 // Initialise the serial monitor

  pinMode(buttonPin, INPUT);          // set buttonPin as input
  pinMode(button1Pin, INPUT);         // set buttonPin as input
  pinMode(2, OUTPUT);                 
  pinMode(12, OUTPUT);                 
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  
//  Serial.println("Press button");

  Display.setBrightness(5);
    inicio ();
}

void inicio(){
    Display.setSegments(letter_T, 1, 0);
    Display.setSegments(letter_R, 1, 1);
    Display.showNumberDec(ntrackdec, false, 1, 2);
    Display.showNumberDec(ntrackuni, false, 1, 3);
    clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
    return;
}


void loop() {
  currentMillis = millis();    // store the current time
  if (msgsent == true && currentMillis - lastmsgsent >= 1500){//mantiene mensajes por 2 segundos en pantalla
    inicio();
    msgsent = false;
  }
  buttonPin = 4;
  button1Pin = 3;
  first_read();
  readButtonState();           // read the button state
  firstpair();
  releasefunction();
  complemento();
  buttonPin = 7;
  button1Pin = 8;
  first_read();
  readButtonState();
  secondpair();
  releasefunction();
  complemento();
  buttonPin = 11;
  button1Pin = 17;
  first_read();
  readButtonState();
  thirdpair();
  releasefunction();
  complemento();
  buttonPin = 18;
  button1Pin = 19;
  first_read();
  readButtonState();
  fourthpair();
  releasefunction();
  complemento();  
}
