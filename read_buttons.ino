////////////////////////////////////////////1st pair reading///////////////////////////////////////////////////
// Function for reading the button0 state
void readButtonState() {

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
      Serial.println("Button pressed");
      msgsent = false;                    //cancela el mensaje enviado
    }

    // Calculate how long the button has been pressed
    buttonPressDuration = currentMillis - buttonLongPressMillis;

    //............................ if both buttons have been long pressed
    if  (button1State == HIGH && buttonState == HIGH && !button1StateLongPress && !buttonStateLongPress && ((buttonPressDuration >= minButtonLongPressDuration) )) {
      button1StateLongPress = true;
      buttonStateLongPress = true;
      bothchecker = true;
      Serial.println("both buttons long pressed");
      longpressboth = true;
    }
    //.......................................................................................................
    // If the button is pressed AND
    // If there is no measurement running to determine how long the button is pressed AND
    // If the time the button has been pressed is larger or equal to the time needed for a long press
    if (buttonState == HIGH && button1State == LOW && !buttonStateLongPress && ((buttonPressDuration >= minButtonLongPressDuration) )) {
      buttonStateLongPress = true;
      Serial.println("Button long pressed");
      longpress = true;
    }

    // If the button is released AND
    // If the button was pressed before
    if (buttonState == LOW && buttonStatePrevious == HIGH) {
      buttonStatePrevious = LOW;
      buttonStateLongPress = false;
      bothchecker = false;
      Serial.println("Button released");
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
        shortpress1 = false;
        shortpress2 = false;
        shortpress3 = false;
        shortpress4 = false;
        shortpress5 = false;
        shortpress6 = false;
        shortpress7 = false;
        Serial.println("Button pressed shortly");
      }
    }

    // store the current timestamp in previousButtonMillis
    previousButtonMillis = currentMillis;

  }

}


// Function for reading the button1 state
void readButton1State() {

  // If the difference in time between the previous reading is larger than intervalButton
  if (currentMillis - previousButton1Millis > intervalButton) {

    // Read the digital value of the button (LOW/HIGH)
    button1State = digitalRead(button1Pin);

    // If the button has been pushed AND
    // If the button wasn't pressed before AND
    // IF there was not already a measurement running to determine how long the button has been pressed
    if (button1State == HIGH && button1StatePrevious == LOW && !button1StateLongPress) {
      button1LongPressMillis = currentMillis;
      button1StatePrevious = HIGH;
      Serial.println("Button1 pressed");
      msgsent = false;                    //cancela el mensaje enviado
    }

    // Calculate how long the button has been pressed
    button1PressDuration = currentMillis - button1LongPressMillis;

    // If the button is pressed AND
    // If there is no measurement running to determine how long the button is pressed AND
    // If the time the button has been pressed is larger or equal to the time needed for a long press
    if (button1State == HIGH && buttonState == LOW && !button1StateLongPress && ((button1PressDuration >= minButtonLongPressDuration) )) {
      button1StateLongPress = true;
      Serial.println("Button1 long pressed");
      longpress1 = true;
    }

    // If the button is released AND
    // If the button was pressed before
    if (button1State == LOW && button1StatePrevious == HIGH) {
      button1StatePrevious = LOW;
      button1StateLongPress = false;
      Serial.println("Button1 released");

      // If there is no measurement running to determine how long the button was pressed AND
      // If the time the button has been pressed is smaller than the minimal time needed for a long press
      // Note: The video shows:
      //       if (!buttonStateLongPress && buttonPressDuration < minButtonLongPressDuration) {
      //       since buttonStateLongPress is set to FALSE on line 75, !buttonStateLongPress is always TRUE
      //       and can be removed.
      if (button1PressDuration < minButtonLongPressDuration) {
        if (synccounter <= 1){shortpress = false;
        shortpress1 = true;
        shortpress2 = false;
        shortpress3 = false;
        shortpress4 = false;
        shortpress5 = false;
        shortpress6 = false;
        shortpress7 = false;}
        if (synccounter > 1){syncreccancel();}
        Serial.println("Button1 pressed shortly");
      }
    }

    // store the current timestamp in previousButtonMillis
    previousButton1Millis = currentMillis;

  }

}

////////////////////////////////////////////2nd pair reading///////////////////////////////////////////////////
// Function for reading the button2 state
void readButton2State() {

  // If the difference in time between the previous reading is larger than intervalButton
  if (currentMillis - previousButtonMillis > intervalButton) {

    // Read the digital value of the button (LOW/HIGH)
    button2State = digitalRead(button2Pin);

    // If the button has been pushed AND
    // If the button wasn't pressed before AND
    // IF there was not already a measurement running to determine how long the button has been pressed
    if (button2State == HIGH && buttonStatePrevious == LOW && !button2StateLongPress) {
      button2LongPressMillis = currentMillis;
      buttonStatePrevious = HIGH;
      Serial.println("Button2 pressed");
      msgsent = false;                    //cancela el mensaje enviado
    }

    // Calculate how long the button has been pressed
    buttonPressDuration = currentMillis - button2LongPressMillis;

    //............................ if both buttons have been long pressed
    if  (button3State == HIGH && button2State == HIGH && !button3StateLongPress && !button2StateLongPress && ((buttonPressDuration >= minButtonLongPressDuration) )) {
      button3StateLongPress = true;
      button2StateLongPress = true;
      bothchecker2 = true;
      Serial.println("second pair of buttons long pressed");
      longpressboth2 = true;
    }
    //.......................................................................................................
    // If the button is pressed AND
    // If there is no measurement running to determine how long the button is pressed AND
    // If the time the button has been pressed is larger or equal to the time needed for a long press
    if (button2State == HIGH && button3State == LOW && !button2StateLongPress && ((buttonPressDuration >= minButtonLongPressDuration) )) {
      button2StateLongPress = true;
      Serial.println("Button2 long pressed");
      longpress2 = true;
    }

    // If the button is released AND
    // If the button was pressed before
    if (button2State == LOW && buttonStatePrevious == HIGH) {
      buttonStatePrevious = LOW;
      button2StateLongPress = false;
      bothchecker2 = false;
      Serial.println("Button2 released");
      button1StatePrevious = LOW;
      button3StateLongPress = false;

      // If there is no measurement running to determine how long the button was pressed AND
      // If the time the button has been pressed is smaller than the minimal time needed for a long press
      // Note: The video shows:
      //       if (!buttonStateLongPress && buttonPressDuration < minButtonLongPressDuration) {
      //       since buttonStateLongPress is set to FALSE on line 75, !buttonStateLongPress is always TRUE
      //       and can be removed.
      if (buttonPressDuration < minButtonLongPressDuration) {
         if (synccounter <= 1){shortpress = false;
        shortpress1 = false;
        shortpress2 = true;
        shortpress3 = false;
        shortpress4 = false;
        shortpress5 = false;
        shortpress6 = false;
        shortpress7 = false;}
        Serial.println("Button2 pressed shortly");
      }
    }

    // store the current timestamp in previousButtonMillis
    previousButtonMillis = currentMillis;

  }

}


// Function for reading the button3 state
void readButton3State() {

  // If the difference in time between the previous reading is larger than intervalButton
  if (currentMillis - previousButton1Millis > intervalButton) {

    // Read the digital value of the button (LOW/HIGH)
    button3State = digitalRead(button3Pin);

    // If the button has been pushed AND
    // If the button wasn't pressed before AND
    // IF there was not already a measurement running to determine how long the button has been pressed
    if (button3State == HIGH && button1StatePrevious == LOW && !button3StateLongPress) {
      button3LongPressMillis = currentMillis;
      button1StatePrevious = HIGH;
      Serial.println("Button3 pressed");
      msgsent = false;                    //cancela el mensaje enviado
    }

    // Calculate how long the button has been pressed
    button1PressDuration = currentMillis - button3LongPressMillis;

    // If the button is pressed AND
    // If there is no measurement running to determine how long the button is pressed AND
    // If the time the button has been pressed is larger or equal to the time needed for a long press
    if (button3State == HIGH && button2State == LOW && !button3StateLongPress && ((button1PressDuration >= minButtonLongPressDuration) )) {
      button3StateLongPress = true;
      Serial.println("Button3 long pressed");
      longpress3 = true;
    }

    // If the button is released AND
    // If the button was pressed before
    if (button3State == LOW && button1StatePrevious == HIGH) {
      button1StatePrevious = LOW;
      button3StateLongPress = false;
      Serial.println("Button3 released");

      // If there is no measurement running to determine how long the button was pressed AND
      // If the time the button has been pressed is smaller than the minimal time needed for a long press
      // Note: The video shows:
      //       if (!buttonStateLongPress && buttonPressDuration < minButtonLongPressDuration) {
      //       since buttonStateLongPress is set to FALSE on line 75, !buttonStateLongPress is always TRUE
      //       and can be removed.
      if (button1PressDuration < minButtonLongPressDuration) {
        Serial.println("Button3 pressed shortly");
         if (synccounter <= 1){shortpress = false;
        shortpress1 = false;
        shortpress2 = false;
        shortpress3 = true;
        shortpress4 = false;
        shortpress5 = false;
        shortpress6 = false;
        shortpress7 = false;}
      }
    }

    // store the current timestamp in previousButtonMillis
    previousButton1Millis = currentMillis;

  }

}

////////////////////////////////////////////3rd pair reading///////////////////////////////////////////////////
// Function for reading the button4 state
void readButton4State() {

  // If the difference in time between the previous reading is larger than intervalButton
  if (currentMillis - previousButtonMillis > intervalButton) {

    // Read the digital value of the button (LOW/HIGH)
    button4State = digitalRead(button4Pin);

    // If the button has been pushed AND
    // If the button wasn't pressed before AND
    // IF there was not already a measurement running to determine how long the button has been pressed
    if (button4State == HIGH && buttonStatePrevious == LOW && !button4StateLongPress) {
      button4LongPressMillis = currentMillis;
      buttonStatePrevious = HIGH;
      Serial.println("Button4 pressed");
      msgsent = false;                    //cancela el mensaje enviado
    }

    // Calculate how long the button has been pressed
    buttonPressDuration = currentMillis - button4LongPressMillis;

    //............................ if both buttons have been long pressed
    if  (button5State == HIGH && button4State == HIGH && !button5StateLongPress && !button4StateLongPress && ((buttonPressDuration >= minButtonLongPressDuration) )) {
      button5StateLongPress = true;
      button4StateLongPress = true;
      bothchecker3 = true;
      Serial.println("3rd pair of buttons long pressed");
      longpressboth3 = true;
    }
    //.......................................................................................................
    // If the button is pressed AND
    // If there is no measurement running to determine how long the button is pressed AND
    // If the time the button has been pressed is larger or equal to the time needed for a long press
    if (button4State == HIGH && button5State == LOW && !button4StateLongPress && ((buttonPressDuration >= minButtonLongPressDuration) )) {
      button4StateLongPress = true;
      Serial.println("Button4 long pressed");
      longpress4 = true;
    }

    // If the button is released AND
    // If the button was pressed before
    if (button4State == LOW && buttonStatePrevious == HIGH) {
      buttonStatePrevious = LOW;
      button4StateLongPress = false;
      bothchecker3 = false;
      Serial.println("Button4 released");
      button1StatePrevious = LOW;
      button5StateLongPress = false;

      // If there is no measurement running to determine how long the button was pressed AND
      // If the time the button has been pressed is smaller than the minimal time needed for a long press
      // Note: The video shows:
      //       if (!buttonStateLongPress && buttonPressDuration < minButtonLongPressDuration) {
      //       since buttonStateLongPress is set to FALSE on line 75, !buttonStateLongPress is always TRUE
      //       and can be removed.
      if (buttonPressDuration < minButtonLongPressDuration) {
         if (synccounter <= 1){shortpress = false;
        shortpress1 = false;
        shortpress2 = false;
        shortpress3 = false;
        shortpress4 = true;
        shortpress5 = false;
        shortpress6 = false;
        shortpress7 = false;}
        Serial.println("Button4 pressed shortly");
      }
    }

    // store the current timestamp in previousButtonMillis
    previousButtonMillis = currentMillis;

  }

}


// Function for reading the button5 state
void readButton5State() {

  // If the difference in time between the previous reading is larger than intervalButton
  if (currentMillis - previousButton1Millis > intervalButton) {

    // Read the digital value of the button (LOW/HIGH)
//    button5State = digitalRead(button5Pin);
    analogsw5read = analogRead(A6);
    if (analogsw5read < 500){
      button5State = LOW;
    }
    else if (analogsw5read > 500){
      button5State = HIGH;
    }

    // If the button has been pushed AND
    // If the button wasn't pressed before AND
    // IF there was not already a measurement running to determine how long the button has been pressed
    if (button5State == HIGH && button1StatePrevious == LOW && !button5StateLongPress) {
      button5LongPressMillis = currentMillis;
      button1StatePrevious = HIGH;
      Serial.println("Button5 pressed");
      msgsent = false;                    //cancela el mensaje enviado
    }

    // Calculate how long the button has been pressed
    button1PressDuration = currentMillis - button5LongPressMillis;

    // If the button is pressed AND
    // If there is no measurement running to determine how long the button is pressed AND
    // If the time the button has been pressed is larger or equal to the time needed for a long press
    if (button5State == HIGH && button4State == LOW && !button5StateLongPress && ((button1PressDuration >= minButtonLongPressDuration) )) {
      button5StateLongPress = true;
      Serial.println("Button5 long pressed");
      longpress5 = true;
    }

    // If the button is released AND
    // If the button was pressed before
    if (button5State == LOW && button1StatePrevious == HIGH) {
      button1StatePrevious = LOW;
      button5StateLongPress = false;
      Serial.println("Button5 released");

      // If there is no measurement running to determine how long the button was pressed AND
      // If the time the button has been pressed is smaller than the minimal time needed for a long press
      // Note: The video shows:
      //       if (!buttonStateLongPress && buttonPressDuration < minButtonLongPressDuration) {
      //       since buttonStateLongPress is set to FALSE on line 75, !buttonStateLongPress is always TRUE
      //       and can be removed.
      if (button1PressDuration < minButtonLongPressDuration) {
        Serial.println("Button5 pressed shortly");
         if (synccounter <= 1){shortpress = false;
        shortpress1 = false;
        shortpress2 = false;
        shortpress3 = false;
        shortpress4 = false;
        shortpress5 = true;
        shortpress6 = false;
        shortpress7 = false;}
      }
    }

    // store the current timestamp in previousButtonMillis
    previousButton1Millis = currentMillis;

  }

}

////////////////////////////////////////////4th pair reading///////////////////////////////////////////////////
// Function for reading the button6 state
void readButton6State() {

  // If the difference in time between the previous reading is larger than intervalButton
  if (currentMillis - previousButtonMillis > intervalButton) {

    // Read the digital value of the button (LOW/HIGH)
    button6State = digitalRead(button6Pin);

    // If the button has been pushed AND
    // If the button wasn't pressed before AND
    // IF there was not already a measurement running to determine how long the button has been pressed
    if (button6State == HIGH && buttonStatePrevious == LOW && !button6StateLongPress) {
      button6LongPressMillis = currentMillis;
      buttonStatePrevious = HIGH;
      Serial.println("Button6 pressed");
      msgsent = false;                    //cancela el mensaje enviado
    }

    // Calculate how long the button has been pressed
    buttonPressDuration = currentMillis - button6LongPressMillis;

    //............................ if both buttons have been long pressed
    if  (button7State == HIGH && button6State == HIGH && !button7StateLongPress && !button6StateLongPress && ((buttonPressDuration >= minButtonLongPressDuration) )) {
      button7StateLongPress = true;
      button6StateLongPress = true;
      bothchecker4 = true;
      Serial.println("4th pair of buttons long pressed");
      longpressboth4 = true;
    }
    //.......................................................................................................
    // If the button is pressed AND
    // If there is no measurement running to determine how long the button is pressed AND
    // If the time the button has been pressed is larger or equal to the time needed for a long press
    if (button6State == HIGH && button7State == LOW && !button6StateLongPress && ((buttonPressDuration >= minButtonLongPressDuration) )) {
      button6StateLongPress = true;
      Serial.println("Button6 long pressed");
      longpress6 = true;
    }

    // If the button is released AND
    // If the button was pressed before
    if (button6State == LOW && buttonStatePrevious == HIGH) {
      buttonStatePrevious = LOW;
      button6StateLongPress = false;
      bothchecker4 = false;
      Serial.println("Button6 released");
      button1StatePrevious = LOW;
      button7StateLongPress = false;

      // If there is no measurement running to determine how long the button was pressed AND
      // If the time the button has been pressed is smaller than the minimal time needed for a long press
      // Note: The video shows:
      //       if (!buttonStateLongPress && buttonPressDuration < minButtonLongPressDuration) {
      //       since buttonStateLongPress is set to FALSE on line 75, !buttonStateLongPress is always TRUE
      //       and can be removed.
      if (buttonPressDuration < minButtonLongPressDuration) {
         if (synccounter <= 1){shortpress = false;
        shortpress1 = false;
        shortpress2 = false;
        shortpress3 = false;
        shortpress4 = false;
        shortpress5 = false;
        shortpress6 = true;
        shortpress7 = false;}
        Serial.println("Button6 pressed shortly");
      }
    }

    // store the current timestamp in previousButtonMillis
    previousButtonMillis = currentMillis;

  }

}


// Function for reading the button7 state
void readButton7State() {

  // If the difference in time between the previous reading is larger than intervalButton
  if (currentMillis - previousButton1Millis > intervalButton) {

    // Read the digital value of the button (LOW/HIGH)
    button7State = digitalRead(button7Pin);

    // If the button has been pushed AND
    // If the button wasn't pressed before AND
    // IF there was not already a measurement running to determine how long the button has been pressed
    if (button7State == HIGH && button1StatePrevious == LOW && !button7StateLongPress) {
      button7LongPressMillis = currentMillis;
      button1StatePrevious = HIGH;
      Serial.println("Button7 pressed");
      msgsent = false;                    //cancela el mensaje enviado
    }

    // Calculate how long the button has been pressed
    button1PressDuration = currentMillis - button7LongPressMillis;

    // If the button is pressed AND
    // If there is no measurement running to determine how long the button is pressed AND
    // If the time the button has been pressed is larger or equal to the time needed for a long press
    if (button7State == HIGH && button6State == LOW && !button7StateLongPress && ((button1PressDuration >= minButtonLongPressDuration) )) {
      button7StateLongPress = true;
      Serial.println("Button7 long pressed");
      longpress7 = true;
    }

    // If the button is released AND
    // If the button was pressed before
    if (button7State == LOW && button1StatePrevious == HIGH) {
      button1StatePrevious = LOW;
      button7StateLongPress = false;
      Serial.println("Button7 released");

      // If there is no measurement running to determine how long the button was pressed AND
      // If the time the button has been pressed is smaller than the minimal time needed for a long press
      // Note: The video shows:
      //       if (!buttonStateLongPress && buttonPressDuration < minButtonLongPressDuration) {
      //       since buttonStateLongPress is set to FALSE on line 75, !buttonStateLongPress is always TRUE
      //       and can be removed.
      if (button1PressDuration < minButtonLongPressDuration) {
        Serial.println("Button7 pressed shortly");
         if (synccounter <= 1){shortpress = false;
        shortpress1 = false;
        shortpress2 = false;
        shortpress3 = false;
        shortpress4 = false;
        shortpress5 = false;
        shortpress6 = false;
        shortpress7 = true;}
      }
    }

    // store the current timestamp in previousButtonMillis
    previousButton1Millis = currentMillis;

  }

}

////////////////////////////////////////////////alt button reading///////////////////////////////////////////
// Function for reading the button8 state
void readButton8State() {

  // If the difference in time between the previous reading is larger than intervalButton
  if (currentMillis - previousButton8Millis > intervalButton) {

    // Read the digital value of the button (LOW/HIGH)
    button8State = digitalRead(button8Pin);

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
