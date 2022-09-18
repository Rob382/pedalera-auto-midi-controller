////////////////////////////////////////////////sync rec function (button 0)/////////////////////////////////////////////
void syncrec(){
  synccounter = synccounter+1;                  //incrementa el contador de controlsync
//    Serial.print ("synccounter = ");
//    Serial.println (synccounter);
    if (displayallowed == true){
    Display.showNumberDec(synccounter, false, 2, 2);
    }
    
    if (synccounter == 1){
    digitalWrite (sw1ctrl, HIGH);       //activa la salida
    delay(3);
    sw1ctrlstate = true;                //control de la salida
    lastSw1Ctrl = currentMillis;
    displayallowed = true;
//    Serial.println("sw1ctrl 4066 HIGH primera vez");
    lastsynccounter = millis();             //millis control salida
    Display.clear();
    Display.setSegments(letter_R, 1, 0);
    Display.setSegments(letter_E, 1, 1);
    Display.setSegments(letter_C, 1, 2);
    }
    if (synccounter >= clickstocount+1){
    digitalWrite (sw1ctrl, HIGH);       //activa la salida
    delay(3);
    sw1ctrlstate = true;                //control de la salida
    lastSw1Ctrl = currentMillis;
//    Serial.println("sw1ctrl 4066 HIGH segunda vez");
    lastsynccounter = millis();             //millis control salida
    Display.setSegments(letter_D, 1, 0);
    Display.setSegments(letter_O, 1, 1);
    Display.setSegments(letter_N, 1, 2);
    Display.setSegments(letter_E, 1, 3);
    msgsent = true;
    lastmsgsent = millis();
    synced_rec = false;
    nextplaysw = false;
    prevplaysw = false;
    oneshotaction = false;
    singlemsg = false;
    displayallowed = false;
    synccounter = 0;
    trackmessage = true;
    }
}
void syncreccancel(){
    synccounter = 0;
    Display.setSegments(letter_C, 1, 0);
    Display.setSegments(letter_A, 1, 1);
    Display.setSegments(letter_N, 1, 2);
    Display.setSegments(letter_C, 1, 3);
    msgsent = true;
    lastmsgsent = millis();
    synced_rec = false;
    prevplaysw = false;
    nextplaysw = false;
    oneshotaction = false;
    singlemsg = false;
    displayallowed = false;
//    Serial.println("operación cancelada");
//    Serial.print("sync counter = ");
//    Serial.println(synccounter);
    return;
}
////////////////////////////////////////////////sw alt control//////////////////////////////////////
void swaltcontrol(){

  //////////alt button////////////
  if (shortpress8 == true) {
    alt = !alt;
//    Serial.print("alt toogled ");
//    Serial.println(alt);
    Display.clear();
    if (alt == 0){
    Display.setSegments(letter_N, 1, 0);
    Display.setSegments(letter_A, 1, 1);
    Display.setSegments(letter_L, 1, 2);
    Display.setSegments(letter_T, 1, 3);  
    digitalWrite(2, LOW);
    msgsent = true;
    lastmsgsent = currentMillis;
    shortpress8 = false;
    }
    if (alt == 1){
    Display.setSegments(letter_A, 1, 1);
    Display.setSegments(letter_L, 1, 2);
    Display.setSegments(letter_T, 1, 3);
    digitalWrite(2, HIGH);
    if (midi_active  == false){
    msgsent = true;
    lastmsgsent = currentMillis;
    }
    shortpress8 = false;} 
  }

  if (longpress8 == true) {
    if (midi_active == false){
    syncall = !syncall;
    Display.clear();
    if (syncall == true){
    Display.setSegments(letter_A, 1, 1);
    Display.setSegments(letter_L, 1, 2);
    Display.setSegments(letter_L, 1, 3);
    digitalWrite(12, HIGH);}
    if (syncall == false){
    Display.setSegments(letter_N, 1, 0);
    Display.setSegments(letter_A, 1, 1);
    Display.setSegments(letter_L, 1, 2);
    Display.setSegments(letter_L, 1, 3);
    digitalWrite(12, LOW);}
    //    Serial.println("sync all");
  }
    if (midi_active == true){
      midi_menu_active = true;
    Display.setSegments(letter_M, 1, 0);
    Display.setSegments(letter_M, 1, 1);
    Display.setSegments(letter_I, 1, 2);
    Display.setSegments(letter_D, 1, 3);
    delay(750);
    Display.setSegments(letter_C, 1, 0);
    Display.setSegments(letter_O, 1, 1);
    Display.setSegments(letter_F, 1, 2);
    Display.setSegments(letter_G, 1, 3);
    delay(750);
    }
    msgsent = true;
    lastmsgsent = millis();
    longpress8 = false;
}
}
