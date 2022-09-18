const uint8_t msg4[] = {
  SEG_A | SEG_B | SEG_C | SEG_G | SEG_E | SEG_F,  //A
  SEG_D | SEG_E | SEG_F,                          //L
  SEG_D | SEG_E | SEG_F,                          //L
};
const uint8_t msg12[] = {
  SEG_C | SEG_E | SEG_G,                          //n
  SEG_A | SEG_B | SEG_C | SEG_G | SEG_E | SEG_F,  //A
  SEG_D | SEG_E | SEG_F,                          //L
  SEG_D | SEG_E | SEG_F,                          //L
};
const uint8_t msg8[] = {
  SEG_A | SEG_B | SEG_C | SEG_G | SEG_E | SEG_F,  //A
  SEG_D | SEG_E | SEG_F,                          //L
  SEG_G | SEG_D | SEG_E | SEG_F,                  //t
};
/////////////////////////////////////rec messages///////////////////
  const uint8_t msg13[] = {
  SEG_E | SEG_G,                                  //r
  SEG_A | SEG_E | SEG_D | SEG_G | SEG_F,          //E
  SEG_A | SEG_D | SEG_E | SEG_F,                  //C
  };
    const uint8_t msg14[] = {
  SEG_C | SEG_B | SEG_D | SEG_E | SEG_G,          //d
  SEG_C | SEG_D | SEG_E | SEG_G,                  //o
  SEG_C | SEG_E | SEG_G,                          //n
  SEG_A | SEG_E | SEG_D | SEG_G | SEG_F,          //E
  };
    const uint8_t msg15[] = {
  SEG_A | SEG_D | SEG_E | SEG_F,                  //C
  SEG_A | SEG_B | SEG_C | SEG_G | SEG_E | SEG_F,  //A
  SEG_C | SEG_E | SEG_G,                          //n
  SEG_A | SEG_D | SEG_E | SEG_F,                  //C
  };
////////////////////////////////////////////////sync rec function (button 0)/////////////////////////////////////////////
void syncrec(){
  synccounter = synccounter+1;                  //incrementa el contador de controlsync
    Serial.print ("synccounter = ");
    Serial.println (synccounter);
    Display.showNumberDec(synccounter, false, 2, 2);
    
    if (synccounter == 1){
    digitalWrite (sw1ctrl, HIGH);       //activa la salida
    Serial.println("sw1ctrl 4066 HIGH primera vez");
    lastsynccounter = millis();             //millis control salida
    sw1ctrlstate = true;                //control de la salida
    Display.setSegments(msg13, 3, 0);
    }
    if (synccounter >= clickstocount+1){
    digitalWrite (sw1ctrl, HIGH);       //activa la salida
    Serial.println("sw1ctrl 4066 HIGH segunda vez");
    lastsynccounter = millis();             //millis control salida
    sw1ctrlstate = true;                //control de la salida
    Display.setSegments(msg14, 4, 0);
    msgsent = true;
    lastmsgsent = millis();
    shortpress = false;
    shortpress2 = false;
    shortpress3 = false;
    oneshotaction = false;
    synccounter = 0;
    }
}
void syncreccancel(){
    synccounter = 0;
//    shortpress = false;
    Display.setSegments(msg15, 4, 0);
    msgsent = true;
    lastmsgsent = millis();
    shortpress = false;
    shortpress2 = false;
    shortpress3 = false;
    oneshotaction = false;
    Serial.println("operación cancelada");
    Serial.print("sync counter = ");
    Serial.println(synccounter);
    return;
}
////////////////////////////////////////////////sw alt control//////////////////////////////////////
void swaltcontrol(){

  //////////alt button////////////
  if (shortpress8 == true) {
    alt = !alt;
    Serial.print("alt toogled ");
    Serial.println(alt);
    Display.clear();
    Display.setSegments(msg8, 3, 1);
    msgsent = true;
    lastmsgsent = millis();
    shortpress8 = false;
  }

  if (longpress8 == true) {
    syncall = !syncall;
    Display.clear();
    if (syncall == true){
    Display.setSegments(msg4, 3, 1);}
    if (syncall == false){
    Display.setSegments(msg12, 4, 0);}
    msgsent = true;
    lastmsgsent = millis();
    Serial.println("sync all");
    longpress8 = false;
  }
}
