#include <TM1637Display.h>
#define CLK 6
#define DIO 5
TM1637Display Display(CLK, DIO);

unsigned long currentMillis = 0;

int trackuniarray[10];
int trackdecarray[10];

int arriba = LOW;
int select = LOW;
int abajo = LOW;
int mostrararray = LOW;
int cursorpin = LOW;
//menú
bool cursor1 = false;
bool showunidigit = true;
bool showdecdigit = true;
int menustate = 1;
int nclicksuni = 0;
int nclicksdec = 0;
int ntrackdec = 0;
int ntrackuni = 0;
unsigned long lastunimillis = 0;
unsigned long lastdecmillis = 0;
unsigned long lastarriba = 0;
unsigned long lastselect = 0;
unsigned long lastabajo = 0;
unsigned long lastmostrararray = 0;
unsigned long lastcursorpin = 0;
const uint8_t msg[] = {
  SEG_A | SEG_B | SEG_C,                          //t
  SEG_E | SEG_G,                                  //r
  
};
const uint8_t blank[] = {SEG_D,};

const uint8_t msg2[] = {
  SEG_A | SEG_D | SEG_E | SEG_F,                  //C
  SEG_D | SEG_E | SEG_F,                          //L
};
const uint8_t msg3[] = {
  SEG_A | SEG_B | SEG_E | SEG_F | SEG_G,          //p
  SEG_A | SEG_B | SEG_C | SEG_E | SEG_F | SEG_G,  //a
  SEG_A | SEG_C | SEG_D | SEG_G | SEG_F,          //s
  SEG_A | SEG_B | SEG_C | SEG_E | SEG_F | SEG_G,  //a
  };
  
void setup() {

  Serial.begin(9600);
  // put your setup code here, to run once:
Display.setBrightness(5);
pinMode(select, INPUT);          // set buttonPin1 as input
pinMode(arriba, INPUT);          // set buttonPin as input
pinMode(abajo, INPUT);          // set buttonPin as input
pinMode(mostrararray, INPUT);          // set buttonPin as input
pinMode(cursorpin, INPUT);          // set buttonPin as input


Serial.println("listo xd");

}

void loop() {
  // put your main code here, to run repeatedly:
//Display.setSegments(msg2, 2, 0);
//delay(500);
//Display.setSegments(msg3, 4, 0);
//delay(500);
//Display.setSegments(msg, 2, 0);
//delay(500);

currentMillis = millis();
    if(menustate == 1){menu_1(); accion_1();}
    if(menustate == 2){menu_2(); accion_2();}
    if(menustate == 3){menu_3(); accion_3();}
}

void menu_1(){
  Display.setSegments(msg, 2, 0);
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
      arriba = digitalRead(4);
      if ((arriba == HIGH) && (currentMillis - lastarriba > 350)){
        if (ntrackuni < 9){ntrackuni = ntrackuni+1;}
        else {ntrackuni = 0;
        ntrackdec = ntrackdec+1;
        Display.showNumberDec(ntrackdec, false, 1, 2);}
        lastarriba = millis();
      }
       abajo = digitalRead(3);
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
      arriba = digitalRead(4);
      if ((arriba == HIGH) && (currentMillis - lastarriba > 350)){
        if (ntrackdec < 9){ntrackdec = ntrackdec+1;}
        else {ntrackdec = 0;}
        lastarriba = millis();
      }
       abajo = digitalRead(3);
      if ((abajo == HIGH) && (currentMillis - lastabajo > 350)){
        if (ntrackdec > 0){ntrackdec = ntrackdec-1;}
        else {ntrackdec = 9;}
        lastabajo = millis();
      }
      
    }
    cursorpin = digitalRead(8);
    if ((cursorpin == HIGH)&&(currentMillis - lastcursorpin > 250)){
      Display.showNumberDec(ntrackdec, false, 1, 2);
      Display.showNumberDec(ntrackuni, false, 1, 3);
      cursor1 = !cursor1;
      lastcursorpin = millis();
    }
    currentMillis = millis();
    select = digitalRead(2);
  }
  if (select == HIGH && currentMillis - lastselect > 500){
    menustate = 2;
    select = LOW;
    cursor1 = false;
    lastselect = millis();
    delay (300);
  }
}

void menu_2(){
  Display.setSegments(msg2, 2, 0);
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
      arriba = digitalRead(4);
      if ((arriba == HIGH) && (currentMillis - lastarriba > 350)){
        if (nclicksuni < 9){nclicksuni = nclicksuni+1;}
        else {nclicksuni = 0;
        nclicksdec = nclicksdec+1;
        Display.showNumberDec(nclicksdec, false, 1, 2);}
        lastarriba = millis();
      }
       abajo = digitalRead(3);
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
      arriba = digitalRead(4);
      if ((arriba == HIGH) && (currentMillis - lastarriba > 350)){
        if (nclicksdec < 9){nclicksdec = nclicksdec+1;}
        else {nclicksdec = 0;}
        lastarriba = millis();
      }
      abajo = digitalRead(3);
      if ((abajo == HIGH) && (currentMillis - lastarriba > 350)){
        if (nclicksdec > 0){nclicksdec = nclicksdec-1;}
        else {nclicksdec = 9;}
        lastarriba = millis();
      }
      
    }
    cursorpin = digitalRead(8);
    if ((cursorpin == HIGH)&&(currentMillis - lastcursorpin > 250)){
      Display.showNumberDec(nclicksdec, false, 1, 2);
      Display.showNumberDec(nclicksuni, false, 1, 3);
      cursor1 = !cursor1;
      lastcursorpin = millis();
    }
    currentMillis = millis();
    select = digitalRead(2);
  } 
  if (select == HIGH && currentMillis - lastselect > 500){
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
   mostrararray = digitalRead(7);

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

void accion_3(){
  
}
