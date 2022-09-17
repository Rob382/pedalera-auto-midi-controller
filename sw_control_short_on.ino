////////////////////////////////////////////////sw control short////////////////////////////////////////////
void swcontrol_short_on () {
  //////////1st pair////////////
  if (shortpress == true && currentMillis - lastsynccounter >= 60 ) {
    if (sync == true && syncall == true) 
    {syncrec();}
    
    if (sync == true && syncall == false){
      if (syncallflag == true){syncrec();}}
      
    if (sync == false && syncall == false) {
      //falta agregar la función stop+play(rec) unsynced
      Serial.println("no hay función programada aún");
      Display.showNumberDec(50, false, 2, 0);
    shortpress = false;
    }
  }
  if (longpress1 == true && longpressboth == false) {
    Display.setSegments(msg11, 4, 0);
    msgsent = true;
    lastmsgsent = millis();
    Serial.println("longpress1 synced undo");
    longpress1 = false;
  }
//////////2nd pair////////////
  if (shortpress2 == true && currentMillis - lastsynccounter >= 60 ) {
   if (alt == false){
    if (oneshotaction == false){
    if (ntrackuni < 9){ntrackuni = ntrackuni+1;}
        else {ntrackuni = 0;}
     Display.setSegments(msg, 2, 0);
     Display.showNumberDec(ntrackdec, false, 1, 2);
     Display.showNumberDec(ntrackuni, false, 1, 3);
     clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
     Serial.print("NEXT + REC ");
     Serial.print(ntrackdec);
    Serial.println(ntrackuni);
     Serial.print("clicks to be counted = ");
    Serial.println(clickstocount);
    oneshotaction = true;
    }
    if (sync == true && syncall == true) 
    {syncrec();}
    
    if (sync == true && syncall == false){
      if (syncallflag == true){syncrec();}}
      
    if (sync == false && syncall == false) {
      digitalWrite (sw1ctrl, HIGH);       //activa la salida
      Serial.println("sw1ctrl 4066 HIGH unica vez");
      sw1ctrlstate = true;                  //control de la salida
      lastSw1Ctrl = millis();
          Display.clear();
          Display.setSegments(msg16, 4, 0);
          msgsent = true;
          lastmsgsent = millis();
      oneshotaction = false;
    shortpress2 = false;
    }
  }
  if (alt == true){
      if (sync == true && syncall == true){
        digitalWrite (sw2ctrl, HIGH);         //activa la salida2 (stop)
        Serial.println("synced stop");
        sw2ctrlstate = true;                  //control2 de la salida (stop)
        lastSw2Ctrl = millis();
          Display.setSegments(msg19, 4, 0);
          msgsent = true;
          lastmsgsent = millis();
      }
      if (sync == true && syncall == false){
        if (syncallflag == true){
          digitalWrite (sw2ctrl, HIGH);         //activa la salida2 (stop)
        Serial.println("synced stop");
        sw2ctrlstate = true;                  //control2 de la salida (stop)
        lastSw2Ctrl = millis();
          Display.setSegments(msg19, 4, 0);
          msgsent = true;
          lastmsgsent = millis();
        }
      }
      if (sync == false && syncall == false) {
    if (ntrackuni < 9){ntrackuni = ntrackuni+1;}
        else {ntrackuni = 0;}
    if (ntrackuni < 9){ntrackuni = ntrackuni+1;}
        else {ntrackuni = 0;}
    if (ntrackuni < 9){ntrackuni = ntrackuni+1;}
        else {ntrackuni = 0;}
    Display.setSegments(msg, 2, 0);
    Display.showNumberDec(ntrackdec, false, 1, 2);
    Display.showNumberDec(ntrackuni, false, 1, 3);
    clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
    Serial.print("3 next ");
    Serial.print(ntrackdec);
    Serial.println(ntrackuni);
    Serial.print("clicks to be counted = ");
    Serial.println(clickstocount);
    shortpress3 = false;
    }
   }
  }
  
  if (shortpress3 == true&& currentMillis - lastsynccounter >= 60 ) {
    if (alt == false){
      if (oneshotaction == false){
    if (ntrackuni > 0){ntrackuni = ntrackuni-1;}
        else {ntrackuni = 9;}
    Display.setSegments(msg, 2, 0);
    Display.showNumberDec(ntrackdec, false, 1, 2);
    Display.showNumberDec(ntrackuni, false, 1, 3);
    clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
    Serial.print("PREV+REC ");
    Serial.print(ntrackdec);
    Serial.println(ntrackuni);
    Serial.print("clicks to be counted = ");
    Serial.println(clickstocount);
    oneshotaction = true;
    }
    if (sync == true && syncall == true) 
    {syncrec();}
    
    if (sync == true && syncall == false){
      if (syncallflag == true){syncrec();}}
      
    if (sync == false && syncall == false) {
      digitalWrite (sw1ctrl, HIGH);         //activa la salida
      Serial.println("sw1ctrl HIGH unica vez");
      sw1ctrlstate = true;                  //control de la salida
      lastSw1Ctrl = millis();
          Display.setSegments(msg17, 4, 0);
          msgsent = true;
          lastmsgsent = millis();
      oneshotaction = false;
    shortpress3 = false;
    }
    }
    if (alt == true){
      if (sync == true && syncall == true){
        digitalWrite (sw1ctrl, HIGH);         //activa la salida
        Serial.println("synced play");
        sw1ctrlstate = true;                  //control de la salida
        lastSw1Ctrl = millis();
          Display.setSegments(msg18, 4, 0);
          msgsent = true;
          lastmsgsent = millis();
      }
      if (sync == true && syncall == false){
        if (syncallflag == true){
          digitalWrite (sw1ctrl, HIGH);         //activa la salida
          Serial.println("synced play");
          sw1ctrlstate = true;                  //control de la salida
          lastSw1Ctrl = millis();
            Display.setSegments(msg18, 4, 0);
            msgsent = true;
            lastmsgsent = millis();
        }
      }
      if (sync == false && syncall == false) {
    if (ntrackuni > 0){ntrackuni = ntrackuni-1;}
        else {ntrackuni = 9;}
    if (ntrackuni > 0){ntrackuni = ntrackuni-1;}
        else {ntrackuni = 9;}
    if (ntrackuni > 0){ntrackuni = ntrackuni-1;}
        else {ntrackuni = 9;}
    Display.setSegments(msg, 2, 0);
    Display.showNumberDec(ntrackdec, false, 1, 2);
    Display.showNumberDec(ntrackuni, false, 1, 3);
    clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
    Serial.print("3 PREV ");
    Serial.print(ntrackdec);
    Serial.println(ntrackuni);
    Serial.print("clicks to be counted = ");
    Serial.println(clickstocount);
    shortpress3 = false;
    }
  }}
  //////////3rd pair////////////
  if (shortpress4 == true) {
    Display.showNumberDec(54, false, 2, 0);
    shortpress4 = false;
  }
  if (shortpress5 == true) {
    Display.showNumberDec(55, false, 2, 0);
    shortpress5 = false;
  }
  //////////4th pair////////////
  if (shortpress6 == true) {
    if (ntrackuni > 0){ntrackuni = ntrackuni-1;}
        else {ntrackuni = 9;}
    Display.setSegments(msg, 2, 0);
    Display.showNumberDec(ntrackdec, false, 1, 2);
    Display.showNumberDec(ntrackuni, false, 1, 3);
    clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
    Serial.print("track abajo ");
    Serial.print(ntrackdec);
    Serial.println(ntrackuni);
    Serial.print("clicks to be counted = ");
    Serial.println(clickstocount);
    shortpress6 = false;
  }
  if (shortpress7 == true) {
     if (ntrackuni < 9){ntrackuni = ntrackuni+1;}
        else {ntrackuni = 0;}
     Display.setSegments(msg, 2, 0);
     Display.showNumberDec(ntrackdec, false, 1, 2);
     Display.showNumberDec(ntrackuni, false, 1, 3);
     clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
     Serial.print("track arriba ");
     Serial.print(ntrackdec);
    Serial.println(ntrackuni);
     Serial.print("clicks to be counted = ");
    Serial.println(clickstocount);
    shortpress7 = false;
  }
}
