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
