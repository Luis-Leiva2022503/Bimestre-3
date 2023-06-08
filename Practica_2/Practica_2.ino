#include <Servo.h> //Incluye una libreria para controlar el servomotor
#include <LiquidCrystal_I2C.h> //Incluye una libreria para controlar el modulo I2C

#define Buzzer 3 // Define al Buzzer como pin 3
#define Pulsador_1 4 // Define al Pulsador_1 como pin 4
#define Pulsador_2 5 // Define al Pulsador_2 como pin 5
#define Pulsador_3 6 // Define al Pulsador_3 como pin 6
#define Pulsador_4 7 // Define al Pulsador_4 como pin 7
#define Potenciometro_1 A0 // Define al Potenciometro_1 como el pin A0
#define Potenciometro_2 A1 // Define al Potenciometro_2 como el pin A1
#define Potenciometro_3 A2 // Define al Potenciometro_3 como el pin A2

int PotValor_1; //Se crea la variable PotValor_1
int PotValor_2; //Se crea la variable PotValor_2
int PotValor_3; //Se crea la variable PotValor_3
int Angulo_1 = 0; //Se crea la variable Angulo_1 y se define como 0
int Angulo_2 = 0; //Se crea la variable Angulo_2 y se define como 0
int Angulo_3 = 0; //Se crea la variable Angulo_3 y se define como 0

LiquidCrystal_I2C lcd(0x27, 16, 2); //Crea la variable lcd e identifica sus pines
Servo Servomotor_1; //Crea la variable Servomotor_1
Servo Servomotor_2; //Crea la variable Servomotor_2
Servo Servomotor_3; //Crea la variable Servomotor_3

void setup(){
  lcd.init(); //Inicializa la pantalla lcd
  lcd.backlight(); //Enciende la pantalla lcd
  lcd.print("FUNCINANDO"); //Escribe "FUNCINANDO" en la pantalla lcd
  
  pinMode(Buzzer, OUTPUT);  //Configurar el pin del buzzer como salida
  pinMode(Pulsador_1, INPUT); //Configurar el pin del Pulsador_1 como entrada
  pinMode(Pulsador_2, INPUT); //Configurar el pin del Pulsador_2 como entrada
  pinMode(Pulsador_3, INPUT); //Configurar el pin del Pulsador_3 como entrada
  pinMode(Pulsador_4, INPUT); //Configurar el pin del Pulsador_4 como entrada
  pinMode(Potenciometro_1, INPUT); //Configurar el pin del Potenciometro_1 como entrada
  pinMode(Potenciometro_2, INPUT); //Configurar el pin del Potenciometro_2 como entrada
  pinMode(Potenciometro_3, INPUT); //Configurar el pin del Potenciometro_3 como entrada

  attachInterrupt(digitalPinToInterrupt(2), Interrupcion, CHANGE); //Crea una interrupcion en el pin 2

  Servomotor_1.attach(8); //Define al Servomotor_1 como pin 8
  Servomotor_2.attach(9); //Define al Servomotor_2 como pin 9
  Servomotor_3.attach(10); //Define al Servomotor_3 como pin 10
  Servomotor_1.write(0); //Pocisiona al Servomotor_1 a 0°
  Servomotor_2.write(0); //Pocisiona al Servomotor_2 a 0°
  Servomotor_3.write(0); //Pocisiona al Servomotor_3 a 0°
}

void loop(){
  //Se condiciona el uso de la funcion Posicion_1 con el Pulsador_1 el cual tiene que estar en estado alto para cumplir la condición
  if(digitalRead(Pulsador_1)==HIGH){
    Posicion_1();
  }   
  //Se condiciona el uso de la funcion Posicion_2 con el Pulsador_2 el cual tiene que estar en estado alto para cumplir la condición
  if(digitalRead(Pulsador_2)==HIGH){
    Posicion_2();
  }
  //Se condiciona el uso de la funcion Posicion_3 con el Pulsador_3 el cual tiene que estar en estado alto para cumplir la condición
  if(digitalRead(Pulsador_3)==HIGH){
    Posicion_3(); 
  }
  //Se condiciona el uso de la funcion Posicion_4 con el Pulsador_4 el cual tiene que estar en estado alto para cumplir la condición
  if(digitalRead(Pulsador_4)==HIGH){
    Posicion_4();
  }
  PotValor_1 = analogRead(Potenciometro_1); //La variable PotValor_1 lee el estado del Potenciometro_1
  Angulo_1 = map(PotValor_1, 0, 1023, 0, 180); //Angulo_1 es igual que map
  Servomotor_1.write(Angulo_1); // El Servomotor_1 se mueve segun el estado de Angulo_1

  PotValor_2 = analogRead(Potenciometro_2); //La variable PotValor_2 lee el estado del Potenciometro_2
  Angulo_2 = map(PotValor_2, 0, 1023, 0, 180); //Angulo_2 es igual que map
  Servomotor_2.write(Angulo_2); // El Servomotor_2 se mueve segun el estado de Angulo_3

  PotValor_3 = analogRead(Potenciometro_3); //La variable PotValor_3 lee el estado del Potenciometro_3
  Angulo_3 = map(PotValor_3, 0, 1023, 0, 180);//Angulo_2 es igual que map
  Servomotor_3.write(Angulo_3); // El Servomotor_3 se mueve segun el estado de Angulo_3
}
//Establece una funcion llamada Interrupcion
void Interrupcion(){
  lcd.clear(); //Limpia la pantalla lcd
  lcd.setCursor(2, 0); //Posiciona el cursor
  lcd.print("Interrupcion"); //Escribe Interrupcion en la pantalla lcd
  lcd.setCursor(3, 1); //Se pocisiona el cursor
  lcd.print("en proceso"); //Escribe en proceso en la pantalla lcd
  Servomotor_1.write(0); //Posiciona el Servomotor_1 a 0°
  Sonido(); //Ejecuta una funcion llamada Sonido
  delay(1000); //Establece un restraso de 1 segundo
  Servomotor_2.write(0); //Posiciona el Servomotor_2 a 0°
  Sonido(); //Ejecuta una funcion llamada Sonido
  delay(1000); //Establece un restraso de 1 segundo
  Servomotor_3.write(0); //Posiciona el Servomotor_3 a 0°
  Sonido(); //Ejecuta una funcion llamada Sonido
  delay(1000); //Establece un restraso de 1 segundo
}
//Establece una funcion llamada Posicion_1
void Posicion_1(){
  lcd.clear(); //Limpia la pantalla lcd
  lcd.setCursor(0, 1); //Posiciona el cursor
  lcd.print("Posicion 1"); //Escribe Posicion 1 en la pantalla lcd
  Servomotor_1.write(90); //Posiciona el Servomotor_1 a 90°
  Sonido(); //Ejecuta una funcion llamada Sonido
  delay(1000); //Establece un restraso de 1 segundo
  Servomotor_2.write(0); //Posiciona el Servomotor_2 a 90°
  Sonido(); //Ejecuta una funcion llamada Sonido
  delay(1000); //Establece un restraso de 1 segundo
  Servomotor_3.write(0); //Posiciona el Servomotor_3 a 90°
  Sonido(); //Ejecuta una funcion llamada Sonido
  delay(1000); //Establece un restraso de 1 segundo
}
//Establece una funcion llamada Posicion_2
void Posicion_2(){
  lcd.clear(); //Limpia la pantalla lcd
  lcd.setCursor(0, 1); //Posiciona el cursor
  lcd.print("Posicion 2"); //Escribe Posicion 2 en la pantalla lcd
  Servomotor_1.write(180); //Posiciona el Servomotor_1 a 180°
  Sonido(); //Ejecuta una funcion llamada Sonido
  delay(1000); //Establece un restraso de 1 segundo
  Servomotor_2.write(180); //Posiciona el Servomotor_2 a 180°
  Sonido(); //Ejecuta una funcion llamada Sonido
  delay(1000); //Establece un restraso de 1 segundo
  Servomotor_3.write(180); //Posiciona el Servomotor_3 a 180°
  Sonido(); //Ejecuta una funcion llamada Sonido
  delay(1000); //Establece un restraso de 1 segundo
}
//Establece una funcion llamada Posicion_3
void Posicion_3(){
  lcd.clear(); //Limpia la pantalla lcd
  lcd.setCursor(0, 1); //Posiciona el cursor
  lcd.print("Posicion 3"); //Escribe Posicion 3 en la pantalla lcd
  Servomotor_1.write(50); //Posiciona el Servomotor_1 a 50°
  Sonido(); //Ejecuta una funcion llamada Sonido
  delay(1000); //Establece un restraso de 1 segundo
  Servomotor_2.write(50); //Posiciona el Servomotor_2 a 50°
  Sonido(); //Ejecuta una funcion llamada Sonido
  delay(1000); //Establece un restraso de 1 segundo
  Servomotor_3.write(50); //Posiciona el Servomotor_3 a 50°
  Sonido(); //Ejecuta una funcion llamada Sonido
  delay(1000); //Establece un restraso de 1 segundo
}
//Establece una funcion llamada Posicion_4
void Posicion_4(){
  lcd.clear(); //Limpia la pantalla lcd
  lcd.setCursor(0, 1); //Posiciona el cursor
  lcd.print("Posicion 4"); //Escribe Posicion 4 en la pantalla lcd
  Servomotor_1.write(120); //Posiciona el Servomotor_1 a 120°
  Sonido(); //Ejecuta una funcion llamada Sonido
  delay(1000); //Establece un restraso de 1 segundo
  Servomotor_2.write(120); //Posiciona el Servomotor_2 a 120°
  Sonido(); //Ejecuta una funcion llamada Sonido
  delay(1000); //Establece un restraso de 1 segundo
  Servomotor_3.write(120); //Posiciona el Servomotor_3 a 120°
  Sonido(); //Ejecuta una funcion llamada Sonido
  delay(1000); //Establece un restraso de 1 segundo
}
//Establece una funcion llamada Sonido
void Sonido() {
  // Serie de tonos para simular el movimiento del brazo mecánico
  int tones[] = {262, 294, 330, 349, 392, 440, 494, 523};
  // Reproducir cada tono en secuencia
  for (int i = 0; i < sizeof(tones) / sizeof(tones[0]); i++) {
    tone(Buzzer, tones[i]);  // Generar el tono en el buzzer
    delay(100);  // Mantener el tono durante la duración especificada
    noTone(Buzzer);  // Detener el tono
  }
}