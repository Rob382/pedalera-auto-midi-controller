
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
/////////2nd pair/////////
const uint8_t msg3[] = {
  SEG_A | SEG_C | SEG_D | SEG_G | SEG_F,          //S
  SEG_B | SEG_C | SEG_D | SEG_G | SEG_F,          //Y
  SEG_C | SEG_E | SEG_G,                          //n
  SEG_A | SEG_D | SEG_E | SEG_F,                  //C
};
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
const uint8_t msg6[] = {
  SEG_A | SEG_D | SEG_E | SEG_F,                  //C
  SEG_D | SEG_E | SEG_F,                          //L
  SEG_B | SEG_C,                                  //i
  SEG_A | SEG_D | SEG_E | SEG_F,                  //C
};
const uint8_t msg5[] = {
 SEG_A | SEG_D | SEG_E | SEG_F,                  //C
  SEG_A | SEG_B | SEG_D | SEG_C | SEG_E | SEG_F,  //O
  SEG_A | SEG_G | SEG_E | SEG_F,                  //F
  SEG_A | SEG_B | SEG_D | SEG_C | SEG_G | SEG_F,  //g
};

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
