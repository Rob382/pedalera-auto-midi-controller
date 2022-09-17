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
