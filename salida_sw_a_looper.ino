/////////////////////////////////////////////sw control off/////////////////////////////////////////////////////
void swcontrol_off () {
  if ((currentMillis - lastSw1Ctrl > 6) && (sw1ctrlstate == HIGH)) {
    digitalWrite (sw1ctrl, LOW);                //play switch
//    Serial.println("sw1ctrl LOW");
    sw1ctrlstate = false;
    lastSw1Ctrl = millis();
  }
                    //stop switch
  if ((currentMillis - lastSw2Ctrl > 6) && (sw2ctrlstate == HIGH)) {
    digitalWrite (sw2ctrl, LOW);    //desactiva la salida
//    Serial.println("sw2ctrl LOW");
    sw2ctrlstate = false;
    lastSw2Ctrl = millis();
  }
                    //undo switch
  if ((currentMillis - lastSw3Ctrl > 6) && (sw3ctrlstate == HIGH)) {
    digitalWrite (sw3ctrl, LOW);    //desactiva la salida
//    Serial.println("sw3ctrl LOW");
    sw3ctrlstate = false;
    lastSw3Ctrl = millis();
  }
                  //abajo sw
  if ((currentMillis - lastSw4Ctrl > 6) && (sw4ctrlstate == HIGH)) {
    digitalWrite (sw4ctrl, LOW);    //desactiva la salida
//    Serial.println("sw4ctrl LOW");
    sw4ctrlstate = false;
    lastSw4Ctrl = millis();
  }
                  //arriba sw
  if ((currentMillis - lastSw5Ctrl > 6) && (sw5ctrlstate == HIGH)) {
    digitalWrite (sw5ctrl, LOW);    //desactiva la salida
//    Serial.println("sw5ctrl LOW");
    sw5ctrlstate = false;
    lastSw5Ctrl = millis();
  }
//  sw1 = digitalRead(A0);
//  sw2 = digitalRead(A1);

//  if (sw1 == HIGH) {
//    Serial.println("A0 high");
//  }
//  if (sw2 == HIGH) {
//    Serial.println("A1 high");
//  }
}
