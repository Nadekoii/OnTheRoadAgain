// Les bibliothèques
#include <QTRSensors.h>

// Variables Globales
// Pour les capteurs: 
#define SENSOR_COUNT 3 // Définir le nbr de capteurs utilisés (ici 3 car modèle à 3 capteurs)
#define TIMEOUT 2000 // Attendre 2000 microsenconds pour le timeout

QTRSensors qtr; // Déclaration du capteur 
uint16_t sensorValues[SENSOR_COUNT]; // Tableau à valeurs du capteur

// Pour les moteurs:
#define EN1 5 // Définir les PINs utilisés
#define EN2 6
#define IN1 4
#define IN2 7

#define SPEED 100  // La vitesse default, peut être modifié
#define MAX_SPEED 120 // La vitesse Max / Min , peut être modifié
#define MIN_SPEED 0

#define DANCE_MODE 0

// Pour le contrôle PID:
uint16_t position; // Pour utiliser avec readLine();
float Kp =0.35;
float Ki =0;
float Kd =3;
int P, I=0, D, PID, lastError=0;

// Fonctions utilitaires
// Fonction pour l'initialisation des capteurs
void initSensor(QTRSensors* qtr){
  qtr->setTypeRC(); // Definir le type du capteur = RC
  qtr->setSensorPins((const uint8_t[]){8, 9, 10}, SENSOR_COUNT); // Associer chaque capteur à son pin
  qtr->setTimeout(TIMEOUT); // Définir le timeout du capteur
}
// Fonction pour le calibrage des capteurs
void calibSensor(QTRSensors* qtr){
  pinMode(LED_BUILTIN, OUTPUT);
  leftMotor(SPEED);
  delay(1000);
  rightMotor(-SPEED);
  digitalWrite(LED_BUILTIN, HIGH); // Allumer le LED de l'Arduino pour annoncer le calibrage
  for (uint16_t i = 0; i < 400; i++){ // Calibrer
    qtr->calibrate();
  }
  leftMotor(0);
  rightMotor(0);
  digitalWrite(LED_BUILTIN, LOW); // Eteindre le LED de l'Arduino pour annoncer la fin du calibrage
}

// Fonction pour l'initialisation des moteurs
void initMotor(){
  int i;
  for (i = 4; i <= 7; i++)
    pinMode(i, OUTPUT);
}

// Fonction pour le changement de vitesse des moteurs
// pwm peut être positive ou négative dépendant du sens de circulation, avec -255<=pwm<=255
// pwm = 0 => Moteur ne toune plus
void leftMotor(int pwm) {
  if (pwm<0){
    analogWrite(EN1, -pwm);
    digitalWrite(IN1, LOW);
  }
  else{
    analogWrite(EN1, pwm);
    digitalWrite(IN1, HIGH);
  }
}

void rightMotor(int pwm) {
   if (pwm<0){
    analogWrite(EN2, -pwm); 
    digitalWrite(IN2, LOW);
  }

  else{
    analogWrite(EN2, pwm);
    digitalWrite(IN2, HIGH);
  }
}

// Fonction l'affichage du tableau des valeurs des capteurs
// qui ont valeurs de 0 à 1000 avec <250 = blanc et >750 = noir 
void testSensor(uint16_t pos){
  for (uint8_t i = 0; i < SENSOR_COUNT; i++)
  {
    Serial.print('[');
    Serial.print(i);    
    Serial.print("] ");
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.print("[P]");
  Serial.println(pos);
}

// Fonction pour tester les moteurs
void testMotor(){
  while (1)  {
    int x, delay_en;
    char val;
    val = Serial.read();
    if (val != -1){
      switch (val){
        case 'w':
          leftMotor(100);
          rightMotor(100);
          break;
        case 'x'://move back
          leftMotor(-100);
          rightMotor(-100);
          break;
        case 'a'://turn left
          leftMotor(-100);
          rightMotor(100);
          break;
        case 'd'://turn right
          leftMotor(100);
          rightMotor(-100);
          break;
        case 's'://stop
          leftMotor(0);
          rightMotor(0);
          break;
        case 'p':
          return;
      }
    }
  }
}

void setup() {
  Serial.begin(9600);
  initMotor(); // Initialiser les moteurs
  initSensor(&qtr); // Initialiser les capteurs et les calibrer
  calibSensor(&qtr);
  delay(1000);
}

void loop() {
  if(DANCE_MODE){
    leftMotor(250);
    rightMotor(-250);
  }
  else{
    position = qtr.readLineBlack(sensorValues); //lire la position current
    int error = 1000 - position; //1000 est le centre des capteurs
    P = error;
    I = I + error;
    D = error - lastError;
    lastError = error;
    PID = P*Kp + I*Ki + D*Kd; //calculer le PID
    
    int leftSpeed = SPEED + PID;
    int rightSpeed = SPEED - PID;
    
    if (leftSpeed > MAX_SPEED) {
      leftSpeed = MAX_SPEED;
    }
    if (rightSpeed > MAX_SPEED) {
      rightSpeed = MAX_SPEED;
    }
    if (leftSpeed < MIN_SPEED) {
      leftSpeed = 0;
    }
    if (rightSpeed  < MIN_SPEED) {
      rightSpeed = 0;
    } 
    leftMotor(leftSpeed);
    rightMotor(rightSpeed);
  }
}
