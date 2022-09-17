int menustate = 1;
char tecla;
char nclicks;
bool menutext1 = true;
bool menutext2 = false;
bool menutext3 = false;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void menu_1(){  
while (Serial.available() == 0){
  if (menutext1 == true){
    Serial.println("quieres activar la sincronización?");
    Serial.println("Y/N");
    menutext1 = false;
  }}}
void accion_1(){
tecla = Serial.read();
if (tecla == '\n'){}
else{
Serial.print("tecla = ");
 Serial.println(tecla);
  if ((tecla == 'y')&&(menustate == 1)){
    menustate = 2;
   Serial.println("se activó la sincronización");
   menutext2 = true;
   }
 else if ((tecla == 'n')&&(menustate == 1)){
    menustate = 1;
   Serial.println("operación cancelada");
   menutext1 = true;
  }}}
  
  void menu_2(){  
while (Serial.available() == 0){
  if (menutext2 == true){
    Serial.println("selecciona el numero de clicks para inicio de loop");
    menutext2 = false;
  }}}
void accion_2(){
tecla = Serial.read();
if (tecla == '\n'){}
else{
Serial.print("tecla = ");
 Serial.println(tecla);
 nclicks = tecla;
    menustate = 3;
   Serial.print("numero de clicks = ");
   Serial.println(nclicks);
   menutext3 = true;
  }}

  void menu_3(){  
while (Serial.available() == 0){
  if (menutext3 == true){
    Serial.println("quieres sincronizar todas las funciones?");
    Serial.println("Y/N");
    menutext3 = false;
  }}}
void accion_3(){
tecla = Serial.read();
if (tecla == '\n'){}
else{
Serial.print("tecla = ");
 Serial.println(tecla);
  if ((tecla == 'y')&&(menustate == 3)){
    menustate = 1;
   Serial.println("sync all on");
   menutext1 = true;
   }
 else if ((tecla == 'n')&&(menustate == 3)){
    menustate = 1;
   Serial.println("sync all off");
   menutext1 = true;
  }}}

void loop() {
    if(menustate == 1){menu_1(); accion_1();}
    if(menustate == 2){menu_2(); accion_2();}
    if(menustate == 3){menu_3(); accion_3();}
}
