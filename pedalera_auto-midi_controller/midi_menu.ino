void midi_menu_1(){
  Display.setSegments(letter_B, 1, 0);
  Display.setSegments(letter_U, 1, 1);
  Display.setSegments(letter_T, 1, 2);
  Display.showNumberDec(nbutton, false, 1, 3);
}

void midi_menu_accion_1(){
   while (select == LOW){
        midi_menu_3();
    
      if ((currentMillis - lastunimillis > 250)){
        if (showunidigit == true){
        Display.showNumberDec(nbutton, false, 1, 3);
        }
        if (showunidigit == false){
        Display.setSegments(blank, 1, 3);
        }
        showunidigit = !showunidigit;
        lastunimillis = millis();
      }
      arriba = digitalRead(19);
      if ((arriba == HIGH) && (currentMillis - lastarriba > 350)){
        if (nbutton < 8){nbutton = nbutton+1;}
        else {nbutton = 1;}
        lastarriba = millis();
      }
       abajo = digitalRead(18);
      if ((abajo == HIGH) && (currentMillis - lastarriba > 350)){
        if (nbutton > 1){nbutton = nbutton-1;}
        else {nbutton = 8;}
        lastarriba = millis();
      }
    currentMillis = millis();
    button8Pin = analogRead(A6);
    if (button8Pin <= 500){select = LOW;}
    if (button8Pin > 500){select = HIGH;}
    menu_out = digitalRead(4);             //boton 4 para salir del menú
    
    if (menu_out == true && currentMillis - lastmenu_out > 500){
    midi_menustate = 1;
    midi_menu_active = false;
    menu_out = false;
    cursor2 = 0;
    lastmenu_out = millis();
    Display.setSegments(letter_P, 1, 0);
    Display.setSegments(letter_L, 1, 1);
    Display.setSegments(letter_A, 1, 2);
    Display.setSegments(letter_Y, 1, 3);
    delay (750);
    midichanneldisplay();
    return;
  }
  }
  if (select == HIGH && currentMillis - lastselect > 700){
    midi_menustate = 2;
    cursor2 = 0;
    lastselect = millis();
    select = LOW;
    delay (300);
  }
}
void midi_menu_2(){
      Display.clear();
      byte notevalue = note[midichannel -1][nbutton - 1];
          noteC = notevalue/100;
          noteD = (notevalue - (noteC*100))/10;
          noteU = notevalue - (noteC*100 + noteD*10);
  Display.showNumberDec(noteC, false, 1, 1);
  Display.showNumberDec(noteD, false, 1, 2);
  Display.showNumberDec(noteU, false, 1, 3);
  

}

void midi_menu_accion_2(){
        
     while (select == LOW){
        midi_menu_3();
      
    if (cursor2 == 0){                                          //estamos en unidades
      if ((currentMillis - lastunimillis > 250)){
        if (showunidigit == true){
        Display.showNumberDec(noteU, false, 1, 3);
        }
        if (showunidigit == false){
        Display.setSegments(blank, 1, 3);
        }
        showunidigit = !showunidigit;
        lastunimillis = millis();
      }
      arriba = digitalRead(19);
      if ((arriba == HIGH) && (currentMillis - lastarriba > 350)){
        if (noteU < 9){noteU = noteU+1;}
        else {noteU = 0;
        noteD = noteD+1;
        Display.showNumberDec(noteD, false, 1, 2);}
        lastarriba = millis();
      }
       abajo = digitalRead(18);
      if ((abajo == HIGH) && (currentMillis - lastarriba > 350)){
        if (noteU > 0){noteU = noteU-1;}
        else {noteU = 9;
         if (noteD != 0){
        noteD = noteD-1;
        Display.showNumberDec(noteD, false, 1, 2);}}
        lastarriba = millis();
      }
      
    }

    if (cursor2 == 1){                                          //estamos en decenas
       if ((currentMillis - lastdecmillis > 250)){
        if (showdecdigit == true){
        Display.showNumberDec(noteD, false, 1, 2);
        }
        if (showdecdigit == false){
        Display.setSegments(blank, 1, 2);
        }
        showdecdigit = !showdecdigit;
        lastdecmillis = millis();
      }
      
      arriba = digitalRead(19);
      if ((arriba == HIGH) && (currentMillis - lastarriba > 350)){
        if (noteD < 9){noteD = noteD+1;}
        else {noteD = 0;
        noteC = noteC+1;
        Display.showNumberDec(noteC, false, 1, 1);}
        lastarriba = millis();
      }
       abajo = digitalRead(18);
      if ((abajo == HIGH) && (currentMillis - lastarriba > 350)){
        if (noteD > 0){noteD = noteD-1;}
        else {noteD = 9;
         if (noteC != 0){
        noteC = noteC-1;
        Display.showNumberDec(noteC, false, 1, 1);}}
        lastarriba = millis();
      }
    }

    if (cursor2 == 2){                                          //estamos en centenas
       if ((currentMillis - lastdecmillis > 250)){
        if (showdecdigit == true){
        Display.showNumberDec(noteC, false, 1, 1);
        }
        if (showdecdigit == false){
        Display.setSegments(blank, 1, 1);
        }
        showdecdigit = !showdecdigit;
        lastdecmillis = millis();
      }
      arriba = digitalRead(19);
      if ((arriba == HIGH) && (currentMillis - lastarriba > 350)){
        if (noteC < 2){noteC = noteC+1;}
        else {noteC = 0;}
        lastarriba = millis();
      }
      abajo = digitalRead(18);
      if ((abajo == HIGH) && (currentMillis - lastarriba > 350)){
        if (noteC > 0){noteC = noteC-1;}
        else {noteC = 2;}
        lastarriba = millis();
      }
    }
    cursorpin = digitalRead(3);
    if ((cursorpin == HIGH)&&(currentMillis - lastcursorpin > 250)){
      Display.showNumberDec(noteC, false, 1, 1);
      Display.showNumberDec(noteD, false, 1, 2);
      Display.showNumberDec(noteU, false, 1, 3);
      if (cursor2 != 2){cursor2 = cursor2 + 1;}
      else{cursor2 = 0;}
      lastcursorpin = millis();
    }
    currentMillis = millis();
    button8Pin = analogRead(A6);
    if (button8Pin <= 500){select = LOW;}
    if (button8Pin > 500){select = HIGH;}
  } 
  if (select == HIGH && currentMillis - lastselect > 700){
    int suma = ((noteC*100) + (noteD*10) + noteU);
    if(suma <= 255){
      note[midichannel -1][nbutton - 1] = suma;
      EEPROM.update((621 + (nbutton -1)+((midichannel - 1) * 8)), suma);
    }
    else{
     Display.setSegments(letter_E, 1, 0);
     Display.setSegments(letter_R, 1, 1);
     Display.setSegments(letter_R, 1, 2);
     Display.setSegments(letter_O, 1, 2);
    }
    midi_menustate = 4;
    select = LOW;
    cursor2 = 0;
    lastselect = millis();
    delay (300);
  }
}
void midi_menu_3(){
  mostrararray = digitalRead(11);

    if (mostrararray == HIGH && currentMillis - lastmostrararray > 500){
      Serial.print("note [0] = ");Serial.print(command[midichannel-1][0]);Serial.println(note[midichannel-1][0]);
      Serial.print("note [1] = ");Serial.print(command[midichannel-1][1]);Serial.println(note[midichannel-1][1]);
      Serial.print("note [2] = ");Serial.print(command[midichannel-1][2]);Serial.println(note[midichannel-1][2]);
      Serial.print("note [3] = ");Serial.print(command[midichannel-1][3]);Serial.println(note[midichannel-1][3]);
      Serial.print("note [4] = ");Serial.print(command[midichannel-1][4]);Serial.println(note[midichannel-1][4]);
      Serial.print("note [5] = ");Serial.print(command[midichannel-1][5]);Serial.println(note[midichannel-1][5]);
      Serial.print("note [6] = ");Serial.print(command[midichannel-1][6]);Serial.println(note[midichannel-1][6]);
      Serial.print("note [7] = ");Serial.print(command[midichannel-1][7]);Serial.println(note[midichannel-1][7]);

      mostrararray = LOW;
      lastmostrararray = millis();}
}

void midi_menu_4(){
  commandvalue = command[midichannel -1][nbutton - 1];
  
  Display.setSegments(letter_F, 1, 0);
  Display.setSegments(letter_U, 1, 1);
  Display.setSegments(letter_N, 1, 2);
  Display.setSegments(letter_C, 1, 3);
  delay(500);
}

void midi_menu_accion_4(){
   while (select == LOW){
        midi_menu_3();
    
      if ((currentMillis - lastunimillis > 250)){
        if (showunidigit == true){
          if(commandvalue == 0){
        Display.setSegments(letter_N, 1, 0);
        Display.setSegments(letter_O, 1, 1);
        Display.setSegments(letter_T, 1, 2);
        Display.setSegments(letter_E, 1, 3);
          }
          if(commandvalue == 1){
            Display.clear();
        Display.setSegments(letter_C, 1, 0);
        Display.setSegments(letter_C, 1, 1);
          }
          if(commandvalue == 2){
        Display.setSegments(letter_T, 1, 0);
        Display.setSegments(letter_O, 1, 1);
        Display.setSegments(letter_G, 1, 2);
        Display.setSegments(letter_G, 1, 3);
          }
        }
        if (showunidigit == false){
        Display.setSegments(blank, 1, 0);
        Display.setSegments(blank, 1, 1);
        Display.setSegments(blank, 1, 2);
        Display.setSegments(blank, 1, 3);
        }
        showunidigit = !showunidigit;
        lastunimillis = millis();
      }
      arriba = digitalRead(19);
      if ((arriba == HIGH) && (currentMillis - lastarriba > 350)){
        if (commandvalue < 2){commandvalue = commandvalue+1;}
        else {commandvalue = 0;}
        lastarriba = millis();
      }
       abajo = digitalRead(18);
      if ((abajo == HIGH) && (currentMillis - lastarriba > 350)){
        if (commandvalue > 0){commandvalue = commandvalue-1;}
        else {commandvalue = 2;}
        lastarriba = millis();
      }
    currentMillis = millis();
    button8Pin = analogRead(A6);
    if (button8Pin <= 500){select = LOW;}
    if (button8Pin > 500){select = HIGH;}
  }
  if (select == HIGH && currentMillis - lastselect > 700){
    command[midichannel -1][nbutton - 1] = commandvalue;
    EEPROM.update((685 + (nbutton -1)+((midichannel - 1) * 8)), commandvalue);
    midi_menustate = 1;
    lastselect = millis();
    select = LOW;
    delay (300);
  }
}
