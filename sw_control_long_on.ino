//////////////////////////////////////////////sw control long///////////////////////////////////////////
void swcontrol_long_on(){

/////////1st pair/////////
if (longpressboth1 == true) {
    sync = !sync;
        Display.setSegments(letter_S, 1, 0);
        Display.setSegments(letter_Y, 1, 1);
        Display.setSegments(letter_N, 1, 2);
        Display.setSegments(letter_C, 1, 3);
        msgsent = true;
        lastmsgsent = millis();
        digitalWrite(ledpin, LOW);
//    Serial.println("longpressboth1 toogle sync");
    longpressboth1 = false;
  }
  if (longpress0 == true && longpressboth1 == false) {
    Display.showNumberDec(10, false, 2, 0);
//    Serial.println("longpress0");
    longpress0 = false;
  }
  if (shortpress01 == true) {undo_button = true;releaseallsp ();}
    if(undo_button == true){ 
    if (alt == false){
    digitalWrite (sw3ctrl, HIGH);       //activa el switch undo
    delay(3);
//    Serial.println("sw3ctrl undo switch cd4066 ");
    sw3ctrlstate = true;                  //control state del switch undo
    lastSw3Ctrl = currentMillis;               //inicia el conteo de tiempo de activación
    Display.setSegments(letter_U, 1, 0);
    Display.setSegments(letter_N, 1, 1);
    Display.setSegments(letter_D, 1, 2);
    Display.setSegments(letter_O, 1, 3);
    msgsent = true;
    lastmsgsent = millis();
//    Serial.println("undo");
    undo_button = false;}
    
    if (alt == true){
      if(sync == true){
        if (oneshotaction == false){
        digitalWrite (sw3ctrl, HIGH);       //activa el switch undo
        delay(3);
//    Serial.println("sw3ctrl undo switch cd4066 ");
    sw3ctrlstate = true;                  //control state del switch undo
    lastSw3Ctrl = currentMillis;
    Display.setSegments(letter_U, 1, 0);
    Display.setSegments(letter_N, 1, 1);
    Display.setSegments(letter_S, 1, 2);
    Display.setSegments(letter_R, 1, 3);
    oneshotaction = true;}
        if (syncallflag == true){
      digitalWrite (sw1ctrl, HIGH);       //activa el switch de rec
      delay(3);
//    Serial.println("activado el switch rec cd4066");
    sw1ctrlstate = true;                  //control state del switch rec
    lastSw1Ctrl = currentMillis;
    msgsent = true;
    lastmsgsent = millis();
//    Serial.println("undo synced record");
    undo_button = false;
    oneshotaction = false;}}
    
    if(sync == false){
      digitalWrite (sw3ctrl, HIGH);       //activa el switch undo
      delay(3);
//    Serial.println("sw3ctrl undo switch cd4066 ");
    sw3ctrlstate = true;                  //control state del switch undo
    lastSw3Ctrl = currentMillis;
      Display.setSegments(letter_U, 1, 0);
      Display.setSegments(letter_N, 1, 1);
      Display.setSegments(letter_D, 1, 2);
      Display.setSegments(letter_O, 1, 3);
    msgsent = true;
    lastmsgsent = millis();
//    Serial.println("undo");
    undo_button = false;
    }
    }
  }
/////////2nd pair/////////
  if (longpressboth2 == true) {
    midi_active = true;
//    Serial.println("activando midi");
    Display.setSegments(letter_M, 1, 0);
    Display.setSegments(letter_M, 1, 1);
    Display.setSegments(letter_I, 1, 2);
    Display.setSegments(letter_D, 1, 3);
    delay(750);
    midichanneldisplay();
    longpressboth2 = false;
  }
  if (longpress2 == true && longpressboth2 == false) {
    Display.showNumberDec(12, false, 2, 0);
//    Serial.println("longpress2");
    longpress2 = false;
  }
  if (longpress3 == true && longpressboth2 == false) {
    Display.showNumberDec(13, false, 2, 0);
//    Serial.println("longpress3");
    longpress3 = false;
  }
/////////3rd pair/////////
  if (longpressboth3 == true) {
    menu_active = true;
//    Serial.println("entrando al menu");
    Display.setSegments(letter_C, 1, 0);
    Display.setSegments(letter_L, 1, 1);
    Display.setSegments(letter_I, 1, 2);
    Display.setSegments(letter_C, 1, 3);
    delay(750);
    Display.setSegments(letter_C, 1, 0);
    Display.setSegments(letter_O, 1, 1);
    Display.setSegments(letter_F, 1, 2);
    Display.setSegments(letter_G, 1, 3);
    delay(750);
//    Serial.println("longpressboth3");
    longpressboth3 = false;
  }
  if (longpress4 == true && longpressboth3 == false) {
    Display.showNumberDec(14, false, 2, 0);
//    Serial.println("longpress4");
    longpress4 = false;
  }
  if (longpress5 == true && longpressboth3 == false) {
    Display.showNumberDec(15, false, 2, 0);
//    Serial.println("longpress5");
    longpress5 = false;
  }
/////////4th pair/////////
  if (longpressboth4 == true) {
    Display.showNumberDec(84, false, 2, 0);
//    Serial.println("longpressboth4");
    longpressboth4 = false;
  }
  if (longpress6 == true && longpressboth4 == false) {
    Display.showNumberDec(16, false, 2, 0);
//    Serial.println("longpress6");
    longpress6 = false;
  }
  if (longpress7 == true && longpressboth4 == false) {
    Display.showNumberDec(17, false, 2, 0);
//    Serial.println("longpress7");
    longpress7 = false;
  }
}
