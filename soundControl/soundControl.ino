#include <Ultrasonic.h>
#include <Wire.h>

//#define potDig1 endereço_dele
//#define potDig2 endereço_dele

Ultrasonic uFrente(9, 8);
Ultrasonic uDireita(12, 11);
Ultrasonic uEsquerda(6, 5); 

#define DISTANCE_LIMIT 200

int ESQUERDA = 0;
int DIREITA = 0;
int FRENTE = 0;


void setResistence(byte output, pot_addr) {
  Wire.beginTransmission(pot_addr);
  Wire.write(0x00);     // comando: volume ambos canais
  Wire.write(output);   // 0–63 determina a resistência do potenciometro digital
  Wire.endTransmission();
}


void setup() {
  Serial.begin(9600);

  float pan_esquerda;
  float pan_direita;

  int output_esq;
  int output_dir;

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

  if (distFrente <= DISTANCE_LIMIT) FRENTE = 1;
  if (distEsquerda <= DISTANCE_LIMIT) ESQUERDA = 1;
  if (distDireita <= DISTANCE_LIMIT) DIREITA = 1;

  pan_esquerda = ESQUERDA * (1 - (FRENTE * 0.25)); // Considerando os pans como Total Esq = 1; Dir = 0 | Frente Esquerda Esq: 0.75; Dir = 0.25 | Frente Esq: 0.5; Dir: 0.5 | Msm para direita
  pan_direita = DIREITA * (1 - (FRENTE * 0.25)); 

  output_esq  = map((distEsquerda * pan_esquerda), 0, 200, 63, 0);
  output_dir = map((distDireita * pan_direita), 0, 200, 63, 0);

  


  delay(200);


}
