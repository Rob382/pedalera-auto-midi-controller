////////////////////////////////////////////////menu functions////////////////////////////////////////////
void menu_1(){
  Display.setSegments(letter_T, 1, 0);
  Display.setSegments(letter_R, 1, 1);
  Display.showNumberDec(ntrackdec, false, 1, 2);
  Display.showNumberDec(ntrackuni, false, 1, 3);
}

void accion_1(){
   while (select == LOW){
        menu_3();
    
    if (cursor1 == false){                                          //estamos en unidades
      if ((currentMillis - lastunimillis > 250)){
        if (showunidigit == true){
        Display.showNumberDec(ntrackuni, false, 1, 3);
        }
        if (showunidigit == false){
        Display.setSegments(blank, 1, 3);
        }
        showunidigit = !showunidigit;
        lastunimillis = millis();
      }
      arriba = digitalRead(19);
      if ((arriba == HIGH) && (currentMillis - lastarriba > 350)){
        if (ntrackuni < 9){ntrackuni = ntrackuni+1;}
        else {ntrackuni = 0;
        ntrackdec = ntrackdec+1;
        Display.showNumberDec(ntrackdec, false, 1, 2);}
        lastarriba = millis();
      }
       abajo = digitalRead(18);
      if ((abajo == HIGH) && (currentMillis - lastarriba > 350)){
        if (ntrackuni > 0){ntrackuni = ntrackuni-1;}
        else {ntrackuni = 9;
        if (ntrackdec != 0){
        ntrackdec = ntrackdec-1;
        Display.showNumberDec(ntrackdec, false, 1, 2);}}
        lastarriba = millis();
      }
      
    }

    if (cursor1 == true){                                          //estamos en decenas
       if ((currentMillis - lastdecmillis > 250)){
        if (showdecdigit == true){
        Display.showNumberDec(ntrackdec, false, 1, 2);
        }
        if (showdecdigit == false){
        Display.setSegments(blank, 1, 2);
        }
        showdecdigit = !showdecdigit;
        lastdecmillis = millis();
      }
      arriba = digitalRead(19);
      if ((arriba == HIGH) && (currentMillis - lastarriba > 350)){
        if (ntrackdec < 9){ntrackdec = ntrackdec+1;}
        else {ntrackdec = 0;}
        lastarriba = millis();
      }
       abajo = digitalRead(18);
      if ((abajo == HIGH) && (currentMillis - lastabajo > 350)){
        if (ntrackdec > 0){ntrackdec = ntrackdec-1;}
        else {ntrackdec = 9;}
        lastabajo = millis();
      }
      
    }
    cursorpin = digitalRead(3);
    if ((cursorpin == HIGH)&&(currentMillis - lastcursorpin > 250)){
      Display.showNumberDec(ntrackdec, false, 1, 2);
      Display.showNumberDec(ntrackuni, false, 1, 3);
      cursor1 = !cursor1;
      lastcursorpin = millis();
    }
    currentMillis = millis();
    button8Pin = analogRead(A6);
    if (button8Pin <= 500){select = LOW;}
    if (button8Pin > 500){select = HIGH;}
    menu_out = digitalRead(4);             //boton 4 para salir del menú
    byte save = digitalRead(7);
    byte load = digitalRead(8);
    
    if (menu_out == true && currentMillis - lastmenu_out > 500){
    menustate = 1;
    menu_active = false;
    menu_out = false;
    cursor1 = false;
    lastmenu_out = millis();
    Display.setSegments(letter_P, 1, 0);
    Display.setSegments(letter_L, 1, 1);
    Display.setSegments(letter_A, 1, 2);
    Display.setSegments(letter_Y, 1, 3);
    delay (750);
    return;
  }
    if (save == HIGH && currentMillis - lastselect > 700){
        menustate = 4;
        save = LOW;
        cursor1 = false;
        lastselect = millis();
        select = HIGH;
        delay (300);
      }
    if (load == HIGH && currentMillis - lastselect > 700){
        menustate = 5;
        load = LOW;
        cursor1 = false;
        lastselect = millis();
        select = HIGH;
        delay (300);
      }
  }
  if (select == HIGH && currentMillis - lastselect > 700){
    menustate = 2;
    select = LOW;
    cursor1 = false;
    lastselect = millis();
    delay (300);
  }
}

void menu_2(){
  Display.setSegments(letter_C, 1, 0);
  Display.setSegments(letter_L, 1, 1);
  nclicksuni = trackuniarray[ntrackuni];
  nclicksdec = trackdecarray[ntrackuni];
  Display.showNumberDec(nclicksdec, false, 1, 2);
  Display.showNumberDec(nclicksuni, false, 1, 3);
  

}

void accion_2(){     
     while (select == LOW){
        menu_3();
      
    if (cursor1 == false){                                          //estamos en unidades
      if ((currentMillis - lastunimillis > 250)){
        if (showunidigit == true){
        Display.showNumberDec(nclicksuni, false, 1, 3);
        }
        if (showunidigit == false){
        Display.setSegments(blank, 1, 3);
        }
        showunidigit = !showunidigit;
        lastunimillis = millis();
      }
      arriba = digitalRead(19);
      if ((arriba == HIGH) && (currentMillis - lastarriba > 350)){
        if (nclicksuni < 9){nclicksuni = nclicksuni+1;}
        else {nclicksuni = 0;
        nclicksdec = nclicksdec+1;
        Display.showNumberDec(nclicksdec, false, 1, 2);}
        lastarriba = millis();
      }
       abajo = digitalRead(18);
      if ((abajo == HIGH) && (currentMillis - lastarriba > 350)){
        if (nclicksuni > 0){nclicksuni = nclicksuni-1;}
        else {nclicksuni = 9;
         if (nclicksdec != 0){
        nclicksdec = nclicksdec-1;
        Display.showNumberDec(nclicksdec, false, 1, 2);}}
        lastarriba = millis();
      }
      
    }

    if (cursor1 == true){                                          //estamos en decenas
       if ((currentMillis - lastdecmillis > 250)){
        if (showdecdigit == true){
        Display.showNumberDec(nclicksdec, false, 1, 2);
        }
        if (showdecdigit == false){
        Display.setSegments(blank, 1, 2);
        }
        showdecdigit = !showdecdigit;
        lastdecmillis = millis();
      }
      arriba = digitalRead(19);
      if ((arriba == HIGH) && (currentMillis - lastarriba > 350)){
        if (nclicksdec < 9){nclicksdec = nclicksdec+1;}
        else {nclicksdec = 0;}
        lastarriba = millis();
      }
      abajo = digitalRead(18);
      if ((abajo == HIGH) && (currentMillis - lastarriba > 350)){
        if (nclicksdec > 0){nclicksdec = nclicksdec-1;}
        else {nclicksdec = 9;}
        lastarriba = millis();
      }
      
    }
    cursorpin = digitalRead(3);
    if ((cursorpin == HIGH)&&(currentMillis - lastcursorpin > 250)){
      Display.showNumberDec(nclicksdec, false, 1, 2);
      Display.showNumberDec(nclicksuni, false, 1, 3);
      cursor1 = !cursor1;
      lastcursorpin = millis();
    }
    currentMillis = millis();
    button8Pin = analogRead(A6);
    if (button8Pin <= 500){select = LOW;}
    if (button8Pin > 500){select = HIGH;}
  } 
  if (select == HIGH && currentMillis - lastselect > 700){
    trackdecarray[ntrackuni] = nclicksdec;    //guarda valores en el arreglo
    trackuniarray[ntrackuni] = nclicksuni;
    menustate = 1;
    select = LOW;
    cursor1 = false;
    lastselect = millis();
    delay (300);
  }
}

void menu_3(){
//   mostrararray = digitalRead(7);

    if (mostrararray == HIGH && currentMillis - lastmostrararray > 500){
      Serial.print("array [0] = "); Serial.print(trackdecarray[0]);Serial.println(trackuniarray[0]);
      Serial.print("array [1] = "); Serial.print(trackdecarray[1]);Serial.println(trackuniarray[1]);
      Serial.print("array [2] = "); Serial.print(trackdecarray[2]);Serial.println(trackuniarray[2]);
      Serial.print("array [3] = "); Serial.print(trackdecarray[3]);Serial.println(trackuniarray[3]);
      Serial.print("array [4] = "); Serial.print(trackdecarray[4]);Serial.println(trackuniarray[4]);
      Serial.print("array [5] = "); Serial.print(trackdecarray[5]);Serial.println(trackuniarray[5]);
      Serial.print("array [6] = "); Serial.print(trackdecarray[6]);Serial.println(trackuniarray[6]);
      Serial.print("array [7] = "); Serial.print(trackdecarray[7]);Serial.println(trackuniarray[7]);
      Serial.print("array [8] = "); Serial.print(trackdecarray[8]);Serial.println(trackuniarray[8]);
      Serial.print("array [9] = "); Serial.print(trackdecarray[9]);Serial.println(trackuniarray[9]);

      mostrararray = LOW;
      lastmostrararray = millis();}
}

void menu_5(){
  Serial.println("load menu");
  Display.setSegments(letter_L, 1, 0);
  Display.setSegments(letter_O, 1, 1);
  Display.setSegments(letter_A, 1, 2);
  Display.setSegments(letter_D, 1, 3);
  delay(1500);
  Display.setSegments(letter_P, 1, 0);
  Display.setSegments(letter_R, 1, 1);
  Display.setSegments(letter_E, 1, 2);
  Display.setSegments(letter_S, 1, 3);
  delay(1500);

  Display.setSegments(letter_L, 1, 0);
  Display.setSegments(letter_D, 1, 1);
  Display.showNumberDec(membankdec, false, 1, 2);
  Display.showNumberDec(membankuni, false, 1, 3);
}

void accion_5(){
   while (select == LOW){    
    if (cursor1 == false){                                          //estamos en unidades
      if ((currentMillis - lastunimillis > 250)){
        if (showunidigit == true){
        Display.showNumberDec(membankuni, false, 1, 3);
        }
        if (showunidigit == false){
        Display.setSegments(blank, 1, 3);
        }
        showunidigit = !showunidigit;
        lastunimillis = millis();
      }
      arriba = digitalRead(19);
      if ((arriba == HIGH) && (currentMillis - lastarriba > 350)){
        if (membankuni < 9){membankuni = membankuni+1;}
        else {membankuni = 0;
        membankdec = membankdec+1;
        Display.showNumberDec(membankdec, false, 1, 2);}
        lastarriba = millis();
      }
       abajo = digitalRead(18);
      if ((abajo == HIGH) && (currentMillis - lastarriba > 350)){
        if (membankuni > 0){membankuni = membankuni-1;}
        else {membankuni = 9;
        if (membankdec != 0){
        membankdec = membankdec-1;
        Display.showNumberDec(membankdec, false, 1, 2);}}
        lastarriba = millis();
      }
      
    }

    if (cursor1 == true){                                          //estamos en decenas
       if ((currentMillis - lastdecmillis > 250)){
        if (showdecdigit == true){
        Display.showNumberDec(membankdec, false, 1, 2);
        }
        if (showdecdigit == false){
        Display.setSegments(blank, 1, 2);
        }
        showdecdigit = !showdecdigit;
        lastdecmillis = millis();
      }
      arriba = digitalRead(19);
      if ((arriba == HIGH) && (currentMillis - lastarriba > 350)){
        if (membankdec < 5){membankdec = membankdec+1;if(membankdec == 5){membankuni = 0;}}
        else {membankdec = 0;}
        lastarriba = millis();
      }
       abajo = digitalRead(18);
      if ((abajo == HIGH) && (currentMillis - lastabajo > 350)){
        if (membankdec > 0){membankdec = membankdec-1;}
        else {membankdec = 5;membankuni = 0;}
        lastabajo = millis();
      }
      
    }
    cursorpin = digitalRead(3);
    if ((cursorpin == HIGH)&&(currentMillis - lastcursorpin > 250)){
      Display.showNumberDec(membankdec, false, 1, 2);
      Display.showNumberDec(membankuni, false, 1, 3);
      cursor1 = !cursor1;
      lastcursorpin = millis();
    }
    currentMillis = millis();
    button8Pin = analogRead(A6);
    if (button8Pin <= 500){select = LOW;}
    if (button8Pin > 500){select = HIGH;}
  }
  if (select == HIGH && currentMillis - lastselect > 700){
    presetbank = (membankdec * 10) + membankuni;
    eeprombank = (presetbank * 20);
    for (byte indice = 0; indice < 10; indice++){
      trackdecarray[indice] = EEPROM.read(eeprombank + indice);
      Serial.print("eeprom dir = ");
      Serial.print(eeprombank + indice);
      Serial.print(", valor dec cargado = ");
      Serial.println(trackdecarray[indice]);
    }
    for (indice = 10; indice < 20; indice++){
      trackuniarray[indice - 10] = EEPROM.read(eeprombank + indice);
      Serial.print("eeprom dir = ");
      Serial.print(eeprombank + (indice));
      Serial.print(", valor uni cargado = ");
      Serial.println(trackuniarray[indice - 10]);
    }
    menustate = 1;
    select = LOW;
    cursor1 = false;
    lastselect = millis();
    delay (300);
  }
}

void menu_4(){
  Serial.println("save menu");
  Display.setSegments(letter_S, 1, 0);
  Display.setSegments(letter_A, 1, 1);
  Display.setSegments(letter_V, 1, 2);
  Display.setSegments(letter_E, 1, 3);
  delay(1500);
  Display.setSegments(letter_P, 1, 0);
  Display.setSegments(letter_R, 1, 1);
  Display.setSegments(letter_E, 1, 2);
  Display.setSegments(letter_S, 1, 3);
  delay(1500);

  Display.setSegments(letter_S, 1, 0);
  Display.setSegments(letter_V, 1, 1);
  Display.showNumberDec(membankdec, false, 1, 2);
  Display.showNumberDec(membankuni, false, 1, 3);
}

void accion_4(){
   while (select == LOW){    
    if (cursor1 == false){                                          //estamos en unidades
      if ((currentMillis - lastunimillis > 250)){
        if (showunidigit == true){
        Display.showNumberDec(membankuni, false, 1, 3);
        }
        if (showunidigit == false){
        Display.setSegments(blank, 1, 3);
        }
        showunidigit = !showunidigit;
        lastunimillis = millis();
      }
      arriba = digitalRead(19);
      if ((arriba == HIGH) && (currentMillis - lastarriba > 350)){
        if (membankuni < 9){membankuni = membankuni+1;}
        else {membankuni = 0;
        membankdec = membankdec+1;
        Display.showNumberDec(membankdec, false, 1, 2);}
        lastarriba = millis();
      }
       abajo = digitalRead(18);
      if ((abajo == HIGH) && (currentMillis - lastarriba > 350)){
        if (membankuni > 0){membankuni = membankuni-1;}
        else {membankuni = 9;
        if (membankdec != 0){
        membankdec = membankdec-1;
        Display.showNumberDec(membankdec, false, 1, 2);}}
        lastarriba = millis();
      }
      
    }

    if (cursor1 == true){                                          //estamos en decenas
       if ((currentMillis - lastdecmillis > 250)){
        if (showdecdigit == true){
        Display.showNumberDec(membankdec, false, 1, 2);
        }
        if (showdecdigit == false){
        Display.setSegments(blank, 1, 2);
        }
        showdecdigit = !showdecdigit;
        lastdecmillis = millis();
      }
      arriba = digitalRead(19);
      if ((arriba == HIGH) && (currentMillis - lastarriba > 350)){
        if (membankdec < 5){membankdec = membankdec+1;if(membankdec == 5){membankuni = 0;}}
        else {membankdec = 0;}
        lastarriba = millis();
      }
       abajo = digitalRead(18);
      if ((abajo == HIGH) && (currentMillis - lastabajo > 350)){
        if (membankdec > 0){membankdec = membankdec-1;}
        else {membankdec = 5;membankuni = 0;}
        lastabajo = millis();
      }
      
    }
    cursorpin = digitalRead(3);
    if ((cursorpin == HIGH)&&(currentMillis - lastcursorpin > 250)){
      Display.showNumberDec(membankdec, false, 1, 2);
      Display.showNumberDec(membankuni, false, 1, 3);
      cursor1 = !cursor1;
      lastcursorpin = millis();
    }
    currentMillis = millis();
    button8Pin = analogRead(A6);
    if (button8Pin <= 500){select = LOW;}
    if (button8Pin > 500){select = HIGH;}
  }
  if (select == HIGH && currentMillis - lastselect > 700){
    presetbank = (membankdec * 10) + membankuni;
    eeprombank = (presetbank * 20);
    for (byte indice = 0; indice < 10; indice++){
      EEPROM.update(eeprombank + indice, trackdecarray[indice]);
      Serial.print("eeprom dir = ");
      Serial.print(eeprombank + indice);
      Serial.print(", valor dec a guardar = ");
      Serial.println(trackdecarray[indice]);
    }
    for (indice = 10; indice < 20; indice++){
      EEPROM.update(eeprombank + indice , trackuniarray[indice - 10]);
      Serial.print("eeprom dir = ");
      Serial.print(eeprombank + (indice));
      Serial.print(", valor uni a guardar = ");
      Serial.println(trackuniarray[indice - 10]);
    }
    menustate = 1;
    select = LOW;
    cursor1 = false;
    lastselect = millis();
    delay (300);
  }
}
