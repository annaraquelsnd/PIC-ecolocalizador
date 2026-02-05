// ============================================================
// DEFINIÇÃO DOS PINOS
// ============================================================

// --- Lado ESQUERDO ---
#define PINO_TRIG_ESQUERDA 8
#define PINO_ECHO_ESQUERDA 7
#define PINO_VIBRACAO_ESQUERDA 11

// --- MEIO (Centro) ---
#define PINO_TRIG_MEIO 4
#define PINO_ECHO_MEIO 5
#define PINO_VIBRACAO_MEIO 10

// --- Lado DIREITO ---
#define PINO_TRIG_DIREITA 12
#define PINO_ECHO_DIREITA 2
#define PINO_VIBRACAO_DIREITA 9

// ============================================================
// CONFIGURAÇÕES GLOBAIS
// ============================================================
const int DISTANCIA_MIN = 100;  // cm (Vibração MÁXIMA)
const int DISTANCIA_MAX = 300; // cm (Vibração INICIA aqui)

void setup() {
  Serial.begin(9600);

  // Configuração Esquerda
  pinMode(PINO_TRIG_ESQUERDA, OUTPUT);
  pinMode(PINO_ECHO_ESQUERDA, INPUT);
  pinMode(PINO_VIBRACAO_ESQUERDA, OUTPUT);

  // Configuração Meio
  pinMode(PINO_TRIG_MEIO, OUTPUT);
  pinMode(PINO_ECHO_MEIO, INPUT);
  pinMode(PINO_VIBRACAO_MEIO, OUTPUT);

  // Configuração Direita
  pinMode(PINO_TRIG_DIREITA, OUTPUT);
  pinMode(PINO_ECHO_DIREITA, INPUT);
  pinMode(PINO_VIBRACAO_DIREITA, OUTPUT);
}

void loop() {
  // Chamamos a função personalizada para cada conjunto
  processarSensor(PINO_TRIG_DIREITA, PINO_ECHO_DIREITA, PINO_VIBRACAO_DIREITA, "Dir");
  processarSensor(PINO_TRIG_ESQUERDA, PINO_ECHO_ESQUERDA, PINO_VIBRACAO_ESQUERDA, "Esq");
  processarSensor(PINO_TRIG_MEIO, PINO_ECHO_MEIO, PINO_VIBRACAO_MEIO, "Meio");
  
  // Pequeno delay para não sobrecarregar processamento e dar tempo aos ecos
  delay(10); 
}

// ============================================================
// FUNÇÃO AUXILIAR: Faz tudo (Lê sensor -> Calcula -> Vibra)
// ============================================================
void processarSensor(int trigPin, int echoPin, int motorPin, String nome) {
  
  // 1. Dispara o pulso ultrassônico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // 2. Lê o retorno
  long duracao = pulseIn(echoPin, HIGH);
  int distancia = duracao * 0.034 / 2;

  // 3. Calcula a Intensidade (Lógica Inversa)
  int pwm = 0;

  // Se a distância for 0, geralmente é erro de leitura ou fora de alcance.
  // Vamos tratar como "longe" para evitar vibração falsa.
  if (distancia == 0 || distancia > DISTANCIA_MAX) {
    pwm = 0; // Desligado
  } 
  else if (distancia < DISTANCIA_MIN) {
    pwm = 255; // Vibração Máxima
  } 
  else {
    // Mapeia: Quanto mais perto, mais forte
    pwm = map(distancia, DISTANCIA_MIN, DISTANCIA_MAX, 255, 0);
  }

  // 4. Aciona o Motor
  analogWrite(motorPin, pwm);

  // 5. Debug (Opcional - para ver no Monitor Serial)
  // Descomente as linhas abaixo para testar
  
  // if (nome == "Esq"){
  //   Serial.print(nome);
  //   Serial.print(": ");
  //   Serial.print(distancia);
  //   Serial.print("cm -> PWM: ");
  //   Serial.println(pwm);
  //   delay(500);
  // }
  
}


