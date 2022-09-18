////////////////////////////////////////////lectura inicial/////////////////////////////////////////////////
void first_read(){
   buttonState = digitalRead(buttonPin);
   if (buttonState == HIGH && buttonStatePrevious == LOW && !buttonStateLongPress && out_release_flag == true) {
      buttonLongPressMillis = currentMillis;
      buttonStatePrevious = HIGH;
      Serial.print("Button ");
      Serial.print(buttonPin);
      Serial.println(" pressed");
      msgsent = false;                    //cancela el mensaje enviado
      out_release_flag = false;
      if (buttonPin == 4){button0pressed = true;}
      if (buttonPin == 7){button2pressed = true;}
      if (buttonPin == 11){button4pressed = true;}
      if (buttonPin == 18){button6pressed = true;}
      sum_botton_pessed = true;
    }
    button1State = digitalRead(button1Pin);
 if (button1State == HIGH && button1StatePrevious == LOW && !button1StateLongPress && out_release_flag1 == true) {
      button1LongPressMillis = currentMillis;
      button1StatePrevious = HIGH;
      Serial.print("Button ");
      Serial.print(button1Pin);
      Serial.println(" pressed");
      msgsent = false;                    //cancela el mensaje enviado
      out_release_flag1 = false;
      if (button1Pin == 3){button1pressed = true;}
      if (button1Pin == 8){button3pressed = true;}
      if (button1Pin == 17){button5pressed = true;}
      if (button1Pin == 19){button7pressed = true;}
      sum_botton_pessed = true;
    }
}

////////////////////////////////////////////1st pair reading///////////////////////////////////////////////////
// Function for reading the button0 state
void readButtonState() {
while (buttonStatePrevious == HIGH || button1StatePrevious == HIGH){
  // If the difference in time between the previous reading is larger than intervalButton
  if (currentMillis - previousButtonMillis > intervalButton) {

    // Read the digital value of the button (LOW/HIGH)
    buttonState = digitalRead(buttonPin);

    // If the button has been pushed AND
    // If the button wasn't pressed before AND
    // IF there was not already a measurement running to determine how long the button has been pressed
    if (buttonState == HIGH && buttonStatePrevious == LOW && !buttonStateLongPress) {
      buttonLongPressMillis = currentMillis;
      buttonStatePrevious = HIGH;
      Serial.print("Button ");
      Serial.print(buttonPin);
      Serial.println(" pressed inside");
      msgsent = false;                    //cancela el mensaje enviado
    }

    // Calculate how long the button has been pressed
    buttonPressDuration = currentMillis - buttonLongPressMillis;

    //............................ if both buttons have been long pressed
    if (button1State == HIGH && buttonState == HIGH && !button1StateLongPress && !buttonStateLongPress && ((buttonPressDuration >= minButtonLongPressDuration) )) {
      button1StateLongPress = true;
      buttonStateLongPress = true;
      bothchecker = true;
      Serial.print("both buttons (");
      Serial.print(buttonPin);
      Serial.print(" & ");
      Serial.print(button1Pin);
      Serial.println(") pressed");
      longpressboth = true;
    }
    //.......................................................................................................
    // If the button is pressed AND
    // If there is no measurement running to determine how long the button is pressed AND
    // If the time the button has been pressed is larger or equal to the time needed for a long press
    if (buttonState == HIGH && button1State == LOW && !buttonStateLongPress && ((buttonPressDuration >= minButtonLongPressDuration) )) {
      buttonStateLongPress = true;
      Serial.print("button ");
      Serial.print(buttonPin);
      Serial.println(" long pressed ");
      longpress = true;
    }

    // If the button is released AND
    // If the button was pressed before
    if ((buttonState == LOW && buttonStatePrevious == HIGH)||(longpress == true)||(longpressboth == true) ) {
      buttonStatePrevious = LOW;
      buttonStateLongPress = false;
      bothchecker = false;
      Serial.print("button ");
      Serial.print(buttonPin);
      Serial.println(" released ");
      button1StatePrevious = LOW;
      button1StateLongPress = false;

      // If there is no measurement running to determine how long the button was pressed AND
      // If the time the button has been pressed is smaller than the minimal time needed for a long press
      // Note: The video shows:
      //       if (!buttonStateLongPress && buttonPressDuration < minButtonLongPressDuration) {
      //       since buttonStateLongPress is set to FALSE on line 75, !buttonStateLongPress is always TRUE
      //       and can be removed.
      if (buttonPressDuration < minButtonLongPressDuration) {
        shortpress = true;
      Serial.print("button ");
      Serial.print(buttonPin);
      Serial.println(" pressed shortly");
      }
    }

    // store the current timestamp in previousButtonMillis
    previousButtonMillis = currentMillis;

  }
// Function for reading the button1 state

  // If the difference in time between the previous reading is larger than intervalButton
  if (millis() - previousButton1Millis > 50) {

    // Read the digital value of the button (LOW/HIGH)
    button1State = digitalRead(button1Pin);

    // If the button has been pushed AND
    // If the button wasn't pressed before AND
    // IF there was not already a measurement running to determine how long the button has been pressed
    if (button1State == HIGH && button1StatePrevious == LOW && !button1StateLongPress) {
      button1LongPressMillis = currentMillis;
      button1StatePrevious = HIGH;
      Serial.print("Button ");
      Serial.print(button1Pin);
      Serial.println(" pressed inside");
      msgsent = false;                    //cancela el mensaje enviado
    }

    // Calculate how long the button1 has been pressed
    button1PressDuration = millis() - button1LongPressMillis;

    // If the button is pressed AND
    // If there is no measurement running to determine how long the button is pressed AND
    // If the time the button has been pressed is larger or equal to the time needed for a long press
    if (button1State == HIGH && buttonState == LOW && !button1StateLongPress && ((button1PressDuration >= minButtonLongPressDuration) )) {
      button1StateLongPress = true;
      Serial.print("button ");
      Serial.print(button1Pin);
      Serial.println(" long pressed ");
      longpress1 = true;
    }

    // If the button is released AND
    // If the button was pressed before
    if ((button1State == LOW && button1StatePrevious == HIGH)||(longpress1 == true) ) {
      button1StatePrevious = LOW;
      button1StateLongPress = false;
      Serial.print("button ");
      Serial.print(button1Pin);
      Serial.println(" released ");

      // If there is no measurement running to determine how long the button was pressed AND
      // If the time the button has been pressed is smaller than the minimal time needed for a long press
      // Note: The video shows:
      //       if (!buttonStateLongPress && buttonPressDuration < minButtonLongPressDuration) {
      //       since buttonStateLongPress is set to FALSE on line 75, !buttonStateLongPress is always TRUE
      //       and can be removed.
      if (button1PressDuration < minButtonLongPressDuration) {
        shortpress1 = true;
        Serial.print("button ");
      Serial.print(button1Pin);
      Serial.println(" pressed shortly");
      }
    }

    // store the current timestamp in previousButtonMillis
    previousButton1Millis = currentMillis;

  }
 currentMillis = millis();
}
}
////////////////////////////////////////////1st pair reading///////////////////////////////////////////////////
void firstpair(){
  if (sum_botton_pessed == true){
  longpressboth1 = longpressboth;
  longpressboth = false;
  longpress0 = longpress;
  longpress = false;
  longpress01 = longpress1;
  longpress1 = false;
  shortpress0 = shortpress;
  shortpress = false;
  if (shortpress0 == HIGH){
        shortpress1 = false;
        shortpress2 = false;
        shortpress3 = false;
        shortpress4 = false;
        shortpress5 = false;
        shortpress6 = false;
        shortpress7 = false;
        Serial.println("shortpress0");
  }
  shortpress01 = shortpress1;
  shortpress1 = false;
  if (shortpress01 == HIGH){
    if (synccounter <= 1){
        shortpress0 = false;
        shortpress2 = false;
        shortpress3 = false;
        shortpress4 = false;
        shortpress5 = false;
        shortpress6 = false;
        shortpress7 = false;
        Serial.println("shortpress01");
  }
  if (synccounter > 1){shortpress01 = false;syncreccancel();}
  }
  sum_botton_pessed = false;
  }
  if (longpress01 == true){
    Display.setSegments(letter_S, 1, 0);
    Display.setSegments(letter_Y, 1, 1);
    Display.setSegments(letter_U, 1, 2);
    Display.setSegments(letter_N, 1, 3);         //envia mensaje synced undo antes de ser gatillado por metrónomo
  }
}
////////////////////////////////////////////2nd pair reading///////////////////////////////////////////////////
void secondpair(){  
  if (sum_botton_pessed == true){
longpressboth2 = longpressboth;
  longpressboth = false;
  longpress2 = longpress;
  longpress = false;
  longpress3 = longpress1;
  longpress1 = false;
  shortpress2 = shortpress;
  shortpress = false;
  if (shortpress2 == HIGH){
        shortpress0 = false;
        shortpress01 = false;
        shortpress3 = false;
        shortpress4 = false;
        shortpress5 = false;
        shortpress6 = false;
        shortpress7 = false;
        Serial.println("shortpress2");
  }
  shortpress3 = shortpress1;
  shortpress1 = false;
  if (shortpress3 == HIGH){
        shortpress0 = false;
        shortpress01 = false;
        shortpress2 = false;
        shortpress4 = false;
        shortpress5 = false;
        shortpress6 = false;
        shortpress7 = false;
        Serial.println("shortpress3");
  }
  sum_botton_pessed = false;
  }
}
////////////////////////////////////////////3rd pair reading///////////////////////////////////////////////////
void thirdpair(){  
  if (sum_botton_pessed == true){
  longpressboth3 = longpressboth;
  longpressboth = false;
  longpress4 = longpress;
  longpress = false;
  longpress5 = longpress1;
  longpress1 = false;
  shortpress4 = shortpress;
  shortpress = false;
  if (shortpress4 == HIGH){
        shortpress0 = false;
        shortpress01 = false;
        shortpress2 = false;
        shortpress3 = false;
        shortpress5 = false;
        shortpress6 = false;
        shortpress7 = false;
        Serial.println("shortpress4");
  }
  shortpress5 = shortpress1;
  shortpress1 = false;
  if (shortpress5 == HIGH){
        shortpress0 = false;
        shortpress01 = false;
        shortpress2 = false;
        shortpress3 = false;
        shortpress4 = false;
        shortpress6 = false;
        shortpress7 = false;
        Serial.println("shortpress5");
  }
  sum_botton_pessed = false;
  }
}
////////////////////////////////////////////4th pair reading///////////////////////////////////////////////////
void fourthpair(){  
  if (sum_botton_pessed == true){
  longpressboth4 = longpressboth;
  longpressboth = false;
  longpress6 = longpress;
  longpress = false;
  longpress7 = longpress1;
  longpress1 = false;
  shortpress6 = shortpress;
  shortpress = false;
  if (shortpress6 == HIGH){
        shortpress0 = false;
        shortpress01 = false;
        shortpress2 = false;
        shortpress3 = false;
        shortpress4 = false;
        shortpress5 = false;
        shortpress7 = false;
  }
  shortpress7 = shortpress1;
  shortpress1 = false;
  if (shortpress7 == HIGH){
        shortpress0 = false;
        shortpress01 = false;
        shortpress2 = false;
        shortpress3 = false;
        shortpress4 = false;
        shortpress5 = false;
        shortpress6 = false;
  }
  sum_botton_pessed = false;
  }
}
////////////////////////////////////////////////alt button reading///////////////////////////////////////////
// Function for reading the button8 state
void readButtonALTState() {

  // If the difference in time between the previous reading is larger than intervalButton
  if (currentMillis - previousButton8Millis > intervalButton) {

    // Read the digital value of the button (LOW/HIGH)
    button8Pin = analogRead(A6);
    if (button8Pin <= 500){button8State = LOW;}
    if (button8Pin > 500){button8State = HIGH;}

    // If the button has been pushed AND
    // If the button wasn't pressed before AND
    // IF there was not already a measurement running to determine how long the button has been pressed
    if (button8State == HIGH && button8StatePrevious == LOW && !button8StateLongPress) {
      button8LongPressMillis = currentMillis;
      button8StatePrevious = HIGH;
      Serial.println("alt Button pressed");
      msgsent = false;                    //cancela el mensaje enviado
    }

    // Calculate how long the button has been pressed
    button8PressDuration = currentMillis - button8LongPressMillis;

    // If the button is pressed AND
    // If there is no measurement running to determine how long the button is pressed AND
    // If the time the button has been pressed is larger or equal to the time needed for a long press
    if (button8State == HIGH && !button8StateLongPress && ((button8PressDuration >= minButtonLongPressDuration) )) {
      button8StateLongPress = true;
      Serial.println("alt Button long pressed");
      longpress8 = true;
    }

    // If the button is released AND
    // If the button was pressed before
    if (button8State == LOW && button8StatePrevious == HIGH) {
      button8StatePrevious = LOW;
      button8StateLongPress = false;
      Serial.println("alt Button released");

      // If there is no measurement running to determine how long the button was pressed AND
      // If the time the button has been pressed is smaller than the minimal time needed for a long press
      // Note: The video shows:
      //       if (!buttonStateLongPress && buttonPressDuration < minButtonLongPressDuration) {
      //       since buttonStateLongPress is set to FALSE on line 75, !buttonStateLongPress is always TRUE
      //       and can be removed.
      if (button8PressDuration < minButtonLongPressDuration) {
        Serial.println("alt Button pressed shortly");
        shortpress8 = true;
      }
    }

    // store the current timestamp in previousButtonMillis
    previousButton8Millis = currentMillis;

  }

}
///////////////////////////////////////////////función release////////////////////////////////////////////////
void releasefunction(){
  byte buttoncomp = digitalRead(buttonPin);
  byte buttoncomp1 = digitalRead(button1Pin);
  if (buttonPin == 4){
    if (buttoncomp == LOW && button0pressed == true){
      button0pressed = false;
      out_release_flag = true;
      Serial.print("released buttonpin ");
      Serial.println(buttonPin);}}
  if (button1Pin == 3){
    if (buttoncomp1 == LOW && button1pressed == true){
      button1pressed = false;
      out_release_flag1 = true;
      Serial.print("released buttonpin ");
      Serial.println(button1Pin);}}    
  if (buttonPin == 7){
    if (buttoncomp == LOW && button2pressed == true){
      button2pressed = false;
      out_release_flag = true;
      Serial.print("released buttonpin ");
      Serial.println(buttonPin);}}
  if (button1Pin == 8){
    if (buttoncomp1 == LOW && button3pressed == true){
      button3pressed = false;
      out_release_flag1 = true;
      Serial.print("released buttonpin ");
      Serial.println(button1Pin);}}
  if (buttonPin == 11){
    if (buttoncomp == LOW && button4pressed == true){
      button4pressed = false;
      out_release_flag = true;
      Serial.print("released buttonpin ");
      Serial.println(buttonPin);}} 
  if (button1Pin == 17){
    if (buttoncomp1 == LOW && button5pressed == true){
      button5pressed = false;
      out_release_flag1 = true;
      Serial.print("released buttonpin ");
      Serial.println(button1Pin);}}     
  if (buttonPin == 18){
    if (buttoncomp == LOW && button6pressed == true){
      button6pressed = false;
      out_release_flag = true;
      Serial.print("released buttonpin ");
      Serial.println(buttonPin);}}
  if (button1Pin == 19){
    if (buttoncomp1 == LOW && button7pressed == true){
      button7pressed = false;
      out_release_flag1 = true;
      Serial.print("released buttonpin ");
      Serial.println(button1Pin);}}      
}
