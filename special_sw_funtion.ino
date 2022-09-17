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
