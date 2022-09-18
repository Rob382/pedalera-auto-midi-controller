void complemento(){
  currentMillis = millis();    // store the current time
  if (msgsent == true && currentMillis - lastmsgsent >= 2000){//mantiene mensajes por 2 segundos en pantalla
    inicio();
    msgsent = false;
  }
  readButtonALTState();
  if (sync == true) {
    syncfn ();
  }
  if (syncall == true){
    if (syncallflag == true){swcontrol_short_on();}} //si se activa syncall espera a la flag para activar las salidas
  if (syncall == false){
    swcontrol_short_on();}        //si se desactiva syncall activa salidas sin esperar
  swcontrol_long_on();
  swaltcontrol();
  swcontrol_off ();
  if (menu_active == true){
    if(menustate == 3){menu_3();}
    if(menustate == 2){menu_2(); accion_2();}
    if(menustate == 1){menu_1(); accion_1();}
    inicio ();
  }
}
