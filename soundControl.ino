#include <Ultrasonic.h>

Ultrasonic uFrente(9, 8);
Ultrasonic uDireita(12, 11);
Ultrasonic uEsquerda(6, 5);

void setup() {
  Serial.begin(9600);
}

void loop() {

  unsigned int distFrente  = uFrente.read();
  unsigned int distDireita = uDireita.read();
  unsigned int distEsquerda = uEsquerda.read();

  // Envia: ang1,dist1,ang2,dist2,ang3,dist3 para o Radar Debug
  Serial.print("90,");
  Serial.print(distFrente);
  Serial.print(",30,");
  Serial.print(distDireita);
  Serial.print(",150,");
  Serial.print(distEsquerda);
  Serial.println(".");

  delay(200);


}
