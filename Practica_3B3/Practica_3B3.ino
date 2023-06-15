#include <LedControl.h>  //Libreria para controlar la matriz led
#include <Stepper.h> //Libreria para controlar el motor paso a paso

byte Nivel1_1[] = {
  B00000000,
  B00000000,
  B01000100,
  B01111110,
  B01111110,
  B01000000,
  B00000000,
  B00000000
};

byte Nivel1_0[] = {
  B11111111,
  B11111111,
  B10111011,
  B10000001,
  B10000001,
  B10111111,
  B11111111,
  B11111111
};

byte Nivel2_1[] = {
  B00000000,
  B01000100,
  B01100010,
  B01010010,
  B01001010,
  B01000100,
  B00000000,
  B00000000
};

byte Nivel2_0[] = {
  B11111111,
  B10111011,
  B10011101,
  B10101101,
  B10110101,
  B10111011,
  B11111111,
  B11111111
};

byte Nivel3_1[] = {
  B00000000,
  B01000100,
  B10010010,
  B10010010,
  B10010010,
  B10010010,
  B01111100,
  B00000000
};

byte Nivel3_0[] = {
  B11111111,
  B10111011,
  B01101101,
  B01101101,
  B01101101,
  B01101101,
  B10000011,
  B11111111
};

const int PasosT = 2048; //Se agrega la constante "PasosT" para crear una variable que sea igual a la cantidad de pasos de una vuelta del motor paso a paso
int A; //Se crea la variable "A" la cual es igual a 0
int B; //Se crea la variable "B" la cual es igual a 0
int C; //Se crea la variable "C" la cual es igual a 0
int D; //Se crea la variable "D" la cual es igual a 0

#define Pulsador_1 3 //Se define la bariable "Pulsador_1" y se le asigna el valor 3
#define Pulsador_2 4 //Se define la bariable "Pulsador_2" y se le asigna el valor 4

LedControl Matriz(11, 13, 10, 1); //Se crea la variable para la Matriz led
Stepper Motor(PasosT, 6, 8, 7, 9); //Se crea la variable para el Motor paso a paso

void setup() {
  Motor.setSpeed(70); //Se asigna la velocidad al motor paso a paso

  Matriz.shutdown(0, false); // Enciende los chips (false = encendido, true = apagado)
  Matriz.setIntensity(0, 8); // Establece la intensidad del brillo (0-15)
  Matriz.clearDisplay(0); // Limpia la matriz de LED
  Nivel1();
  
  pinMode(2, INPUT); //Se establece la variable "Pulsador" como entrad
  pinMode(Pulsador_1, INPUT); //Se establece la variable "Pulsador_1" como entrad
  pinMode(Pulsador_2, INPUT); //Se establece la variable "Pulsador_2" como entrada
}

void loop() {
  if(digitalRead(Pulsador_1)==HIGH){ //Se crea una condicion
    A = 1-A; //Se Resta el valor de A
    C = 1-C; //Se Resta el valor de C
  }
  if(A==HIGH){ //Se crea una condicion
    if(D == LOW){ //Se crea una condicion
      Motor.step(10240); //El motor paso a paso rota
      Nivel2(); //Se activa la funcion "Nivel2"
    }
    if(D == HIGH){ //Se crea una condicion 
      Motor.step(-10240); //El motor paso a paso rota al lado contrario
      Nivel2(); //Se activa la funcion "Nivel2"
      D = 1-D; //Se 1resta la variable "D"
    }
    delay(100); //Se realiza un retraso de 100ms
    A = 1-A; //Se resta la variable "A"
  }
  if(digitalRead(Pulsador_2)==HIGH){ //Se crea una condicion
    B = 1-B; //Se resta la variable "B"
    D = 1-D; //Se resta la variable "D"
  }
  if(B==HIGH){ //Se crea una condicion
    if(C == LOW){ //Se crea una condicion
      Motor.step(20480); //El motor paso a paso rota 
      Nivel3(); //Se activa la funcion "Nivel3"
    }
    if(C == HIGH){ //Se crea una condicion
      Motor.step(10240); //El motor paso a paso rota
      Nivel3(); //Se activa la funcion "Nivel3"
      C = 1-C; //Se resta la variable "C"
    }
    delay(500); //Se realiza un retraso de 500ms
    B = 1-B; //Se resta la variable "B"
  }
}

void Interrupcion(){ //Se crea una funcion llamada "Interrupcion"
  if(D == HIGH){ //Se crea una condicion
    Motor.step(-20480); //El motor paso a paso rota en sentido contrario
    Nivel1(); //Se activa la funcion "Nivel1"
    D = 1-D; //Se resta la variable "D"
    }
  if(D == LOW){ //Se crea una condicion
    Motor.step(-10240); //El motor paso a paso rota en sentido contrario
    Nivel1(); //Se activa la funcion "Nivel1"
    C = 1-C; //Se resta la variable "C"
  }
}

void Nivel1(){ //Se crea la funcion "Nivel1"
  Matriz.setRow(0, 0, Nivel1_0[0]);
  Matriz.setRow(0, 1, Nivel1_0[1]);
  Matriz.setRow(0, 2, Nivel1_0[2]);
  Matriz.setRow(0, 3, Nivel1_0[3]);
  Matriz.setRow(0, 4, Nivel1_0[4]);
  Matriz.setRow(0, 5, Nivel1_0[5]);
  Matriz.setRow(0, 6, Nivel1_0[6]);
  Matriz.setRow(0, 7, Nivel1_0[7]);
  delay(1000);
  Matriz.setRow(0, 0, Nivel1_1[0]);
  Matriz.setRow(0, 1, Nivel1_1[1]);
  Matriz.setRow(0, 2, Nivel1_1[2]);
  Matriz.setRow(0, 3, Nivel1_1[3]);
  Matriz.setRow(0, 4, Nivel1_1[4]);
  Matriz.setRow(0, 5, Nivel1_1[5]);
  Matriz.setRow(0, 6, Nivel1_1[6]);
  Matriz.setRow(0, 7, Nivel1_1[7]);
  delay(1000);
}
//La funcion forma el numero 1 en la matriz led
void Nivel2(){ //Se crea la funcion "Nivel1"
  Matriz.setRow(0, 0, Nivel2_0[0]);
  Matriz.setRow(0, 1, Nivel2_0[1]);
  Matriz.setRow(0, 2, Nivel2_0[2]);
  Matriz.setRow(0, 3, Nivel2_0[3]);
  Matriz.setRow(0, 4, Nivel2_0[4]);
  Matriz.setRow(0, 5, Nivel2_0[5]);
  Matriz.setRow(0, 6, Nivel2_0[6]);
  Matriz.setRow(0, 7, Nivel2_0[7]);
  delay(1000);
  Matriz.setRow(0, 0, Nivel2_1[0]);
  Matriz.setRow(0, 1, Nivel2_1[1]);
  Matriz.setRow(0, 2, Nivel2_1[2]);
  Matriz.setRow(0, 3, Nivel2_1[3]);
  Matriz.setRow(0, 4, Nivel2_1[4]);
  Matriz.setRow(0, 5, Nivel2_1[5]);
  Matriz.setRow(0, 6, Nivel2_1[6]);
  Matriz.setRow(0, 7, Nivel2_1[7]);
  delay(1000);
}
//La funcion forma el numero 2 en la matriz led
void Nivel3(){ //Se crea la funcion "Nivel1"
  Matriz.setRow(0, 0, Nivel3_0[0]);
  Matriz.setRow(0, 1, Nivel3_0[1]);
  Matriz.setRow(0, 2, Nivel3_0[2]);
  Matriz.setRow(0, 3, Nivel3_0[3]);
  Matriz.setRow(0, 4, Nivel3_0[4]);
  Matriz.setRow(0, 5, Nivel3_0[5]);
  Matriz.setRow(0, 6, Nivel3_0[6]);
  Matriz.setRow(0, 7, Nivel3_0[7]);
  delay(1000);
  Matriz.setRow(0, 0, Nivel3_1[0]);
  Matriz.setRow(0, 1, Nivel3_1[1]);
  Matriz.setRow(0, 2, Nivel3_1[2]);
  Matriz.setRow(0, 3, Nivel3_1[3]);
  Matriz.setRow(0, 4, Nivel3_1[4]);
  Matriz.setRow(0, 5, Nivel3_1[5]);
  Matriz.setRow(0, 6, Nivel3_1[6]);
  Matriz.setRow(0, 7, Nivel3_1[7]);
  delay(1000);
}
//La funcion forma el numero 3 en la matriz led