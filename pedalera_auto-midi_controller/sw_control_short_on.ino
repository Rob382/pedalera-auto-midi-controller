////////////////////////////////////////////////sw control short////////////////////////////////////////////
void swcontrol_short_on () {
  //////////1st pair////////////
//  if (shortpress0 == false){Serial.println("shortpress0 está en false amigou");}
  if (shortpress0 == true && currentMillis - lastsynccounter >= 60 ) {synced_rec = true;releaseallsp ();}
  if (synced_rec == true){
    if (sync == true && syncall == true) 
    {syncrec();}
    
    if (sync == true && syncall == false){
      if (syncallflag == true){syncrec();}}
      
    if (sync == false && syncall == false) {
      //falta agregar la función stop+play(rec) unsynced
//      Serial.println("no hay función programada aún");
      Display.showNumberDec(50, false, 2, 0);
      shortpress0 = false;
      synced_rec = false;
    }
    }
    if (longpress01 == true && longpressboth1 == false) {syncedundo = true;longpress01 = false; releaseallsp ();}
     if (syncedundo == true && syncallflag == true){ 
    digitalWrite (sw3ctrl, HIGH);       //activa el switch undo
    delay(3);
//    Serial.println("sw3ctrl undo switch cd4066 ");
    sw3ctrlstate = true;                  //control state del switch undo
    lastSw3Ctrl = currentMillis; 
      Display.setSegments(letter_S, 1, 0);
      Display.setSegments(letter_Y, 1, 1);
      Display.setSegments(letter_U, 1, 2);
      Display.setSegments(letter_N, 1, 3);
      msgsent = true;
      lastmsgsent = millis();
//      Serial.println("longpress01 synced undo");
      syncedundo = false;
    }
//////////2nd pair////////////
  if (shortpress2 == true && currentMillis - lastsynccounter >= 60 ) {
    nextplaysw = true; 
    if (alt == false)  {
        Display.setSegments(letter_N, 1, 0);
        Display.setSegments(letter_X, 1, 1);
        Display.setSegments(letter_T, 1, 2);
        Display.setSegments(letter_R, 1, 3);
    }
    if (alt == true && sync == true)  {
        Display.setSegments(letter_S, 1, 0);
        Display.setSegments(letter_S, 1, 1);
        Display.setSegments(letter_T, 1, 2);
        Display.setSegments(letter_P, 1, 3);
    }
     if (alt == true && sync == false)  {
        Display.showNumberDec(3, false, 1, 0);
        Display.setSegments(letter_N, 1, 1);
        Display.setSegments(letter_X, 1, 2);
        Display.setSegments(letter_T, 1, 3);
    }
    releaseallsp ();}
  if (nextplaysw == true){
   if (alt == false){
      if (sync == true && syncall == true){
      if (oneshotaction == false){
      if (ntrackuni < 9){ntrackuni = ntrackuni+1;}
          else {ntrackuni = 0;}
        digitalWrite(sw5ctrl, HIGH);
        delay(3);
        digitalWrite(sw5ctrl, LOW);
        delay(6);
       clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
//       Serial.print("NEXT + REC ");
//       Serial.print(ntrackdec);
//      Serial.println(ntrackuni);
//       Serial.print("clicks to be counted = ");
//      Serial.println(clickstocount);
      oneshotaction = true;
      }
        syncrec();
        
        if (trackmessage == true){
       Display.setSegments(letter_T, 1, 0);
       Display.setSegments(letter_R, 1, 1);
       Display.showNumberDec(ntrackdec, false, 1, 2);
       Display.showNumberDec(ntrackuni, false, 1, 3);
       trackmessage = false;
        }
        }
      
      if (sync == true && syncall == false){
        if (syncallflag == true){
      if (oneshotaction == false){
      if (ntrackuni < 9){ntrackuni = ntrackuni+1;}
          else {ntrackuni = 0;}
        digitalWrite(sw5ctrl, HIGH);
        delay(3);
        digitalWrite(sw5ctrl, LOW);
        delay(6);
       clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
//       Serial.print("NEXT + REC ");
//       Serial.print(ntrackdec);
//      Serial.println(ntrackuni);
//       Serial.print("clicks to be counted = ");
//      Serial.println(clickstocount);
      oneshotaction = true;
      }
          syncrec();
          
          if (trackmessage == true){
       Display.setSegments(letter_T, 1, 0);
       Display.setSegments(letter_R, 1, 1);
       Display.showNumberDec(ntrackdec, false, 1, 2);
       Display.showNumberDec(ntrackuni, false, 1, 3);
       trackmessage = false;
        }
          }}
        
      if (sync == false && syncall == false) {
        if (ntrackuni < 9){ntrackuni = ntrackuni+1;}
        else {ntrackuni = 0;}
        digitalWrite(sw5ctrl, HIGH);
        delay(3);
        digitalWrite(sw5ctrl, LOW);
        delay(6);
       clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
//       Serial.print("NEXT + REC ");
//       Serial.print(ntrackdec);
//      Serial.println(ntrackuni);
        digitalWrite (sw1ctrl, HIGH);       //activa la salida
        delay(3);
//        Serial.println("sw1ctrl 4066 HIGH unica vez");
        sw1ctrlstate = true;                  //control de la salida
        lastSw1Ctrl = currentMillis;
            Display.clear();
            Display.setSegments(letter_N, 1, 0);
            Display.setSegments(letter_X, 1, 1);
            Display.setSegments(letter_T, 1, 2);
            Display.setSegments(letter_R, 1, 3);
            msgsent = true;
            lastmsgsent = millis();
        oneshotaction = false;
        singlemsg = false;
      shortpress2 = false;
      nextplaysw = false;
      }
    }
  if (alt == true){
      if (sync == true && syncall == true){
        digitalWrite (sw2ctrl, HIGH);         //activa la salida2 (stop)
        delay(3);
//        Serial.println("synced stop");
        sw2ctrlstate = true;                  //control2 de la salida (stop)
        lastSw2Ctrl = currentMillis;
        Display.setSegments(letter_S, 1, 0);
        Display.setSegments(letter_S, 1, 1);
        Display.setSegments(letter_T, 1, 2);
        Display.setSegments(letter_P, 1, 3);
          msgsent = true;
          lastmsgsent = millis();
          nextplaysw = false;
      }
      if (sync == true && syncall == false){
        if (syncallflag == true){
          digitalWrite (sw2ctrl, HIGH);         //activa la salida2 (stop)
          delay(3);
//        Serial.println("synced stop");
        sw2ctrlstate = true;                  //control2 de la salida (stop)
        lastSw2Ctrl = currentMillis;
          Display.setSegments(letter_S, 1, 0);
          Display.setSegments(letter_S, 1, 1);
          Display.setSegments(letter_T, 1, 2);
          Display.setSegments(letter_P, 1, 3);
          msgsent = true;
          lastmsgsent = millis();
          nextplaysw = false;
        }
      }
      if (sync == false && syncall == false) {
    if (ntrackuni < 9){ntrackuni = ntrackuni+1;}
        else {ntrackuni = 0;}
    if (ntrackuni < 9){ntrackuni = ntrackuni+1;}
        else {ntrackuni = 0;}
    if (ntrackuni < 9){ntrackuni = ntrackuni+1;}
        else {ntrackuni = 0;}
        digitalWrite(sw5ctrl, HIGH);
        delay(3);
        digitalWrite(sw5ctrl, LOW);
        delay(6);
        digitalWrite(sw5ctrl, HIGH);
        delay(3);
        digitalWrite(sw5ctrl, LOW);
        delay(6);
        digitalWrite(sw5ctrl, HIGH);
        sw5ctrlstate = true;                  //control de la salida
        lastSw5Ctrl = currentMillis;
        delay(3);
//    Display.setSegments(letter_T, 1, 0);
//    Display.setSegments(letter_R, 1, 1);
//    Display.showNumberDec(ntrackdec, false, 1, 2);
//    Display.showNumberDec(ntrackuni, false, 1, 3);
    clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
//    Serial.print("3 next ");
//    Serial.print(ntrackdec);
//    Serial.println(ntrackuni);
//    Serial.print("clicks to be counted = ");
//    Serial.println(clickstocount);
    Display.showNumberDec(3, false, 1, 0);
    Display.setSegments(letter_N, 1, 1);
    Display.setSegments(letter_X, 1, 2);
    Display.setSegments(letter_T, 1, 3);
    msgsent = true;
    lastmsgsent = millis();
    shortpress2 = false;
    nextplaysw = false;
    }
   }
  }
  
if (shortpress3 == true && currentMillis - lastsynccounter >= 60 ) {
  prevplaysw = true;
   if (alt == false)  {
        Display.setSegments(letter_P, 1, 0);
        Display.setSegments(letter_R, 1, 1);
        Display.setSegments(letter_E, 1, 2);
        Display.setSegments(letter_R, 1, 3);
    }
    if (alt == true && sync == true)  {
        Display.setSegments(letter_S, 1, 0);
        Display.setSegments(letter_P, 1, 1);
        Display.setSegments(letter_L, 1, 2);
        Display.setSegments(letter_A, 1, 3);
    }
     if (alt == true && sync == false)  {
        Display.showNumberDec(3, false, 1, 0);
        Display.setSegments(letter_P, 1, 1);
        Display.setSegments(letter_R, 1, 2);
        Display.setSegments(letter_E, 1, 3);
    }
  releaseallsp ();
  }
  
   if (prevplaysw == true){
    if (alt == false){        
    if (sync == true && syncall == true){
      if (oneshotaction == false){
    if (ntrackuni > 0){ntrackuni = ntrackuni-1;}
        else {ntrackuni = 9;}
      digitalWrite(sw4ctrl, HIGH);
      delay(3);
      digitalWrite(sw4ctrl, LOW);
      delay(6);
    clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
//    Serial.print("PREV+REC ");
//    Serial.print(ntrackdec);
//    Serial.println(ntrackuni);
//    Serial.print("clicks to be counted = ");
//    Serial.println(clickstocount);
    oneshotaction = true;
    }
      syncrec();
      if (trackmessage == true){
    Display.setSegments(letter_T, 1, 0);
    Display.setSegments(letter_R, 1, 1);
    Display.showNumberDec(ntrackdec, false, 1, 2);
    Display.showNumberDec(ntrackuni, false, 1, 3);
    trackmessage = false;
      }
      }
    
    if (sync == true && syncall == false){
      if (syncallflag == true){
        if (oneshotaction == false){
    if (ntrackuni > 0){ntrackuni = ntrackuni-1;}
        else {ntrackuni = 9;}
      digitalWrite(sw4ctrl, HIGH);
      delay(3);
      digitalWrite(sw4ctrl, LOW);
      delay(6);
    clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
//    Serial.print("PREV+REC ");
//    Serial.print(ntrackdec);
//    Serial.println(ntrackuni);
//    Serial.print("clicks to be counted = ");
//    Serial.println(clickstocount);
    oneshotaction = true;
    }
        syncrec();
        if (trackmessage == true){
    Display.setSegments(letter_T, 1, 0);
    Display.setSegments(letter_R, 1, 1);
    Display.showNumberDec(ntrackdec, false, 1, 2);
    Display.showNumberDec(ntrackuni, false, 1, 3);
    trackmessage = false;
      }
        }}
      
    if (sync == false && syncall == false) {
      if (ntrackuni > 0){ntrackuni = ntrackuni-1;}
        else {ntrackuni = 9;}
      digitalWrite(sw4ctrl, HIGH);
      delay(3);
      digitalWrite(sw4ctrl, LOW);
      delay(6);
    clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
//    Serial.print("PREV+REC ");
//    Serial.print(ntrackdec);
//    Serial.println(ntrackuni);
      digitalWrite (sw1ctrl, HIGH);       //activa la salida
      delay(3);
//      Serial.println("sw1ctrl HIGH unica vez");
      sw1ctrlstate = true;                  //control de la salida
      lastSw1Ctrl = currentMillis;
        Display.setSegments(letter_P, 1, 0);
        Display.setSegments(letter_R, 1, 1);
        Display.setSegments(letter_E, 1, 2);
        Display.setSegments(letter_R, 1, 3);
          msgsent = true;
          lastmsgsent = millis();
      oneshotaction = false;
      singlemsg = false;
    shortpress3 = false;
    prevplaysw = false;
    }
    }
    if (alt == true){
      if (sync == true && syncall == true){
        digitalWrite (sw1ctrl, HIGH);         //activa la salida
        delay(3);
//        Serial.println("synced play");
        sw1ctrlstate = true;                  //control de la salida
        lastSw1Ctrl = currentMillis;
          Display.setSegments(letter_S, 1, 0);
          Display.setSegments(letter_P, 1, 1);
          Display.setSegments(letter_L, 1, 2);
          Display.setSegments(letter_A, 1, 3);
          msgsent = true;
          lastmsgsent = millis();
          prevplaysw = false;
      }
      if (sync == true && syncall == false){
        if (syncallflag == true){
          digitalWrite (sw1ctrl, HIGH);         //activa la salida
          delay(3);
//          Serial.println("synced play");
          sw1ctrlstate = true;                  //control de la salida
          lastSw1Ctrl = currentMillis;
            Display.setSegments(letter_S, 1, 0);
            Display.setSegments(letter_P, 1, 1);
            Display.setSegments(letter_L, 1, 2);
            Display.setSegments(letter_A, 1, 3);
            msgsent = true;
            lastmsgsent = millis();
            prevplaysw = false;
        }
      }
      if (sync == false && syncall == false) {
    if (ntrackuni > 0){ntrackuni = ntrackuni-1;}
        else {ntrackuni = 9;}
    if (ntrackuni > 0){ntrackuni = ntrackuni-1;}
        else {ntrackuni = 9;}
    if (ntrackuni > 0){ntrackuni = ntrackuni-1;}
        else {ntrackuni = 9;}
      digitalWrite(sw4ctrl, HIGH);
      delay(3);
      digitalWrite(sw4ctrl, LOW);
      delay(6);
      digitalWrite(sw4ctrl, HIGH);
      delay(3);
      digitalWrite(sw4ctrl, LOW);
      delay(6);
      digitalWrite(sw4ctrl, HIGH);
      sw4ctrlstate = true;                  //control de la salida
      lastSw4Ctrl = currentMillis;
      delay(3);
//    Display.setSegments(letter_T, 1, 0);
//    Display.setSegments(letter_R, 1, 1);
//    Display.showNumberDec(ntrackdec, false, 1, 2);
//    Display.showNumberDec(ntrackuni, false, 1, 3);
    clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
//    Serial.print("3 PREV ");
//    Serial.print(ntrackdec);
//    Serial.println(ntrackuni);
//    Serial.print("clicks to be counted = ");
//    Serial.println(clickstocount);
    Display.showNumberDec(3, false, 1, 0);
    Display.setSegments(letter_P, 1, 1);
    Display.setSegments(letter_R, 1, 2);
    Display.setSegments(letter_E, 1, 3);
    msgsent = true;
    lastmsgsent = millis();
    shortpress3 = false;
    prevplaysw = false;
    }
  }}
  //////////3rd pair////////////
  if (shortpress4 == true) {
    stop_prev = true; 
    if (alt == false)  {
        Display.setSegments(letter_S, 1, 0);
        Display.setSegments(letter_T, 1, 1);
        Display.setSegments(letter_P, 1, 2);
        Display.setSegments(letter_R, 1, 3);
    }
    if (alt == true)  {
        Display.setSegments(letter_P, 1, 0);
        Display.setSegments(letter_R, 1, 1);
        Display.setSegments(letter_U, 1, 2);
        Display.setSegments(letter_N, 1, 3);
    }
    releaseallsp ();}
    
  if (stop_prev == true){
    if (alt == false){        
      if (syncall == false){
        if (ntrackuni > 0){ntrackuni = ntrackuni-1;}
        else {ntrackuni = 9;}
        digitalWrite(sw1ctrl, HIGH);
        delay(3);
        digitalWrite(sw1ctrl, LOW);
        delay(6);
        digitalWrite(sw4ctrl, HIGH);
        sw4ctrlstate = true;                  //control de la salida
        lastSw4Ctrl = currentMillis;
        delay(3);
       clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
//       Serial.print("stop + prev NO synced all");
//       Serial.print(ntrackdec);
//      Serial.println(ntrackuni);
//       Serial.print("clicks to be counted = ");
//      Serial.println(clickstocount);
      msgsent = true;
      lastmsgsent = millis();
      stop_prev = false;
        releaseallsp ();
      }
        
      if (sync == true && syncall == true){
        if (ntrackuni > 0){ntrackuni = ntrackuni-1;}
        else {ntrackuni = 9;}
        digitalWrite(sw1ctrl, HIGH);
        delay(3);
        digitalWrite(sw1ctrl, LOW);
        delay(6);
        digitalWrite(sw4ctrl, HIGH);
        sw4ctrlstate = true;                  //control de la salida
        lastSw4Ctrl = currentMillis;
        delay(3);
       clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
//       Serial.print("stop + prev synced all");
//       Serial.print(ntrackdec);
//      Serial.println(ntrackuni);
//       Serial.print("clicks to be counted = ");
//      Serial.println(clickstocount);
      msgsent = true;
      lastmsgsent = millis();
      singlemsg = false;
      stop_prev = false;
        releaseallsp ();
      }
    }
    if (alt == true){        
      if (syncall == false){
        if (ntrackuni > 0){ntrackuni = ntrackuni-1;}
        else {ntrackuni = 9;}
        digitalWrite(sw4ctrl, HIGH);
        delay(3);
        digitalWrite(sw4ctrl, LOW);
        delay(6);
        digitalWrite(sw3ctrl, HIGH);
        sw3ctrlstate = true;                  //control de la salida
        lastSw3Ctrl = currentMillis;
        delay(3);
       clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
//       Serial.print("prev + undo unsynced");
//       Serial.print(ntrackdec);
//      Serial.println(ntrackuni);
//       Serial.print("clicks to be counted = ");
//      Serial.println(clickstocount);
      msgsent = true;
      lastmsgsent = millis();
      singlemsg = false;
      stop_prev = false;
        releaseallsp ();
      }
      if (sync == true && syncall == true){
        if (ntrackuni > 0){ntrackuni = ntrackuni-1;}
        else {ntrackuni = 9;}
        digitalWrite(sw4ctrl, HIGH);
        delay(3);
        digitalWrite(sw4ctrl, LOW);
        delay(6);
        digitalWrite(sw3ctrl, HIGH);
        sw3ctrlstate = true;                  //control de la salida
        lastSw3Ctrl = currentMillis;
        delay(3);
       clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
//       Serial.print("prev + undo synced all");
//       Serial.print(ntrackdec);
//      Serial.println(ntrackuni);
//       Serial.print("clicks to be counted = ");
//      Serial.println(clickstocount);
      msgsent = true;
      lastmsgsent = millis();
      singlemsg = false;
      stop_prev = false;
        releaseallsp ();
      }
    }
  }
  if (shortpress5 == true) {
    stop_next = true;
    if (alt == false)  {
        Display.setSegments(letter_S, 1, 0);
        Display.setSegments(letter_T, 1, 1);
        Display.setSegments(letter_N, 1, 2);
        Display.setSegments(letter_X, 1, 3);
    }
    if (alt == true)  {
        Display.setSegments(letter_N, 1, 0);
        Display.setSegments(letter_X, 1, 1);
        Display.setSegments(letter_U, 1, 2);
        Display.setSegments(letter_N, 1, 3);
    }
    releaseallsp ();}
    
  if (stop_next == true){
    if (alt == false){        
      if (syncall == false){
        if (ntrackuni < 9){ntrackuni = ntrackuni+1;}
          else {ntrackuni = 0;}
        digitalWrite(sw1ctrl, HIGH);
        delay(3);
        digitalWrite(sw1ctrl, LOW);
        delay(6);
        digitalWrite(sw5ctrl, HIGH);
        sw5ctrlstate = true;                  //control de la salida
        lastSw5Ctrl = currentMillis;
        delay(3);
       clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
//       Serial.print("stop + next NO synced all");
//       Serial.print(ntrackdec);
//      Serial.println(ntrackuni);
//       Serial.print("clicks to be counted = ");
//      Serial.println(clickstocount);
      msgsent = true;
      lastmsgsent = millis();
      singlemsg = false;
      stop_next = false;
        releaseallsp ();
      }
        
      if (sync == true && syncall == true){
        if (ntrackuni < 9){ntrackuni = ntrackuni+1;}
          else {ntrackuni = 0;}
        digitalWrite(sw1ctrl, HIGH);
        delay(3);
        digitalWrite(sw1ctrl, LOW);
        delay(6);
        digitalWrite(sw5ctrl, HIGH);
        sw5ctrlstate = true;                  //control de la salida
        lastSw5Ctrl = currentMillis;
        delay(3);
       clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
//       Serial.print("stop + next synced all");
//       Serial.print(ntrackdec);
//      Serial.println(ntrackuni);
//       Serial.print("clicks to be counted = ");
//      Serial.println(clickstocount);
      msgsent = true;
      lastmsgsent = millis();
      singlemsg = false;
      stop_next = false;
        releaseallsp ();
      }
    }
    if (alt == true){
      if (syncall == false){
        if (ntrackuni < 9){ntrackuni = ntrackuni+1;}
          else {ntrackuni = 0;}
        digitalWrite(sw5ctrl, HIGH);
        delay(3);
        digitalWrite(sw5ctrl, LOW);
        delay(6);
        digitalWrite(sw3ctrl, HIGH);
        sw3ctrlstate = true;                  //control de la salida
        lastSw3Ctrl = currentMillis;
        delay(3);
       clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
//       Serial.print("next + undo unsynced");
//       Serial.print(ntrackdec);
//      Serial.println(ntrackuni);
//       Serial.print("clicks to be counted = ");
//      Serial.println(clickstocount);
      msgsent = true;
      lastmsgsent = millis();
      singlemsg = false;
      stop_next = false;
        releaseallsp ();
      }
      if (sync == true && syncall == true){
        if (ntrackuni < 9){ntrackuni = ntrackuni+1;}
          else {ntrackuni = 0;}
        digitalWrite(sw5ctrl, HIGH);
        delay(3);
        digitalWrite(sw5ctrl, LOW);
        delay(6);
        digitalWrite(sw3ctrl, HIGH);
        sw3ctrlstate = true;                  //control de la salida
        lastSw3Ctrl = currentMillis;
        delay(3);
       clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
//       Serial.print("next + undo synced all");
//       Serial.print(ntrackdec);
//      Serial.println(ntrackuni);
//       Serial.print("clicks to be counted = ");
//      Serial.println(clickstocount);
      msgsent = true;
      lastmsgsent = millis();
      singlemsg = false;
      stop_next = false;
        releaseallsp ();
      }
    }
  }
  //////////4th pair////////////
  if (shortpress6 == true) {
    if (alt == false){
    if (ntrackuni > 0){ntrackuni = ntrackuni-1;}
        else {ntrackuni = 9;}
    digitalWrite (sw4ctrl, HIGH);       //activa el switch undo
    delay(3);
//    Serial.println("sw4ctrl abajo switch cd4066 ");
    sw4ctrlstate = true;                  //control state del switch undo
    lastSw4Ctrl = currentMillis;               //inicia el conteo de tiempo de activación
    Display.setSegments(letter_T, 1, 0);
    Display.setSegments(letter_R, 1, 1);
    Display.showNumberDec(ntrackdec, false, 1, 2);
    Display.showNumberDec(ntrackuni, false, 1, 3);
    clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
//    Serial.print("track abajo ");
//    Serial.print(ntrackdec);
//    Serial.println(ntrackuni);
//    Serial.print("clicks to be counted = ");
//    Serial.println(clickstocount);
    shortpress6 = false;
    releaseallsp ();
  }
    if (alt == true){
    if (ntrackuni > 0){ntrackuni = ntrackuni-1;}
        else {ntrackuni = 9;}
    if (ntrackuni > 0){ntrackuni = ntrackuni-1;}
        else {ntrackuni = 9;}
    digitalWrite (sw4ctrl, HIGH);       //activa el switch undo
    delay(3);
    digitalWrite (sw4ctrl, LOW);
    delay(6);
    digitalWrite (sw4ctrl, HIGH);       //activa el switch undo
    delay(3);
//    Serial.println("sw4ctrl abajo switch cd4066 ");
    sw4ctrlstate = true;                  //control state del switch undo
    lastSw4Ctrl = currentMillis;               //inicia el conteo de tiempo de activación
    Display.setSegments(letter_T, 1, 0);
    Display.setSegments(letter_R, 1, 1);
    Display.showNumberDec(ntrackdec, false, 1, 2);
    Display.showNumberDec(ntrackuni, false, 1, 3);
    clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
//    Serial.print("track abajo ");
//    Serial.print(ntrackdec);
//    Serial.println(ntrackuni);
//    Serial.print("clicks to be counted = ");
//    Serial.println(clickstocount);
//    Display.showNumberDec(2, false, 1, 0);
//    Display.setSegments(letter_P, 1, 1);
//    Display.setSegments(letter_R, 1, 2);
//    Display.setSegments(letter_E, 1, 3);
    msgsent = true;
    lastmsgsent = millis();
    shortpress6 = false;
    releaseallsp ();
    }
  }
  
  if (shortpress7 == true) {
    if (alt == false){
     if (ntrackuni < 9){ntrackuni = ntrackuni+1;}
        else {ntrackuni = 0;}
    digitalWrite (sw5ctrl, HIGH);       //activa el switch undo
    delay(3);
//    Serial.println("sw5ctrl arriba switch cd4066 ");
    sw5ctrlstate = true;                  //control state del switch undo
    lastSw5Ctrl = currentMillis;               //inicia el conteo de tiempo de activación
     Display.setSegments(letter_T, 1, 0);
     Display.setSegments(letter_R, 1, 1);
     Display.showNumberDec(ntrackdec, false, 1, 2);
     Display.showNumberDec(ntrackuni, false, 1, 3);
     clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
//     Serial.print("track arriba ");
//     Serial.print(ntrackdec);
//    Serial.println(ntrackuni);
//     Serial.print("clicks to be counted = ");
//    Serial.println(clickstocount);
    shortpress7 = false;
    releaseallsp ();
    }
    if (alt == true){
     if (ntrackuni < 9){ntrackuni = ntrackuni+1;}
        else {ntrackuni = 0;}
     if (ntrackuni < 9){ntrackuni = ntrackuni+1;}
        else {ntrackuni = 0;}
    digitalWrite (sw5ctrl, HIGH);       //activa el switch undo
    delay(3);
    digitalWrite (sw5ctrl, LOW);
    delay(6);
    digitalWrite (sw5ctrl, HIGH);
    delay(3);
//    Serial.println("sw5ctrl arriba switch cd4066 ");
    sw5ctrlstate = true;                  //control state del switch undo
    lastSw5Ctrl = currentMillis;               //inicia el conteo de tiempo de activación
     Display.setSegments(letter_T, 1, 0);
     Display.setSegments(letter_R, 1, 1);
     Display.showNumberDec(ntrackdec, false, 1, 2);
     Display.showNumberDec(ntrackuni, false, 1, 3);
     clickstocount = ((trackdecarray[ntrackuni] * 10) + trackuniarray[ntrackuni]);
//     Serial.print("track arriba ");
//     Serial.print(ntrackdec);
//    Serial.println(ntrackuni);
//     Serial.print("clicks to be counted = ");
//    Serial.println(clickstocount);
//    Display.showNumberDec(2, false, 1, 0);
//    Display.setSegments(letter_N, 1, 1);
//    Display.setSegments(letter_X, 1, 2);
//    Display.setSegments(letter_T, 1, 3);
    msgsent = true;
    lastmsgsent = millis();
    shortpress7 = false;
    releaseallsp ();
    }
  }
}

void releaseallsp (){      //función para apagar todas las variables cuando se realizó una acción
  shortpress0 = false;
  shortpress01 = false;
  shortpress2 = false;
  shortpress3 = false;
  shortpress4 = false;
  shortpress5 = false;
  shortpress6 = false;
  shortpress7 = false;
  longpress01 = false;
}
