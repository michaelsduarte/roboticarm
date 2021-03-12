/*
CONTROLE DA GARRA MAGNÉTICA E DA ESTEIRA (Arduíno NANO)
10/02/2021
Aluno: Paulo Victor Pereira Lima  - Turma: Eletrônica S6
Disciplina: Projeto integrador  - Professor: Michael Duarte
*/

#include <Servo.h> //Incluindo biblioteca para controle dos servomotores

#define pinServo1 9   //Associando constantes aos pinos dos servos
#define pinServo2 10  
#define pinServo3 11  

#define esteira 5 //Definindo o pino da esteira no arduíno

#define ima 3 //Definindo o pino do ímã no arduíno

Servo servo1; //Declarando servos
Servo servo2;
Servo servo3;

void setup() {
  
  servo1.attach(pinServo1); //Definindo pinos dos servos
  servo2.attach(pinServo2);
  servo3.attach(pinServo3);
  
  servo1.write(50); //Definindo posicao inicial da garra
  servo2.write(135);
  servo3.write(90);

  pinMode(esteira, OUTPUT); //Definindo esteira
  digitalWrite(esteira, LOW);

  pinMode(ima, OUTPUT);  //Definindo ima
  digitalWrite(3, LOW);

  delay(4000);
  
}

void loop() {
  
servo1.write(50); //Controle da posicao da garra: definido posicoes diretamente para uma maior velocidade no movimento 
  servo2.write(135);
  servo3.write(90);
  delay(2000);

  digitalWrite(ima, HIGH);

  int tempo=10;
  int i1=50;
  for(int i2=135;i2>73;i2--)  //Controle da posicao da garra: utilizando 'for' para uma maior suavidade no movimento 
  {
    if (i1<87) i1++;
    
    servo1.write(i1);
    servo2.write(i2);
    delay(tempo);
  }
  delay(250);


  digitalWrite(esteira, HIGH);
  delay(10000); 
  digitalWrite(esteira, LOW);


  tempo=10;
  i1=87;
  for(int i2=73;i2<135;i2++)
  {
    if (i1>50) i1--;
    
    servo2.write(i2);
    servo1.write(i1);
    delay(tempo);
  }
  delay(350);


  tempo=6;
  for(int i3=90;i3<180;i3++)
  {
    servo3.write(i3);
    delay(tempo);
  }
  delay(350); 


  tempo=8;
  i1=50;
  for(int i2=135;i2>45;i2--)
  {
    if (i1<130) i1++;
    
    servo1.write(i1);
    servo2.write(i2);
    delay(tempo);
  }
  delay(1000);
  
  digitalWrite(ima, LOW); 
  delay(1000);
  
  servo1.write(50);
  servo2.write(135);
  servo3.write(179);
  delay(360);
  
}
