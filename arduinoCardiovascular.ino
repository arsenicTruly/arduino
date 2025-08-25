#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

#define pinRx 10
#define pinTx 11

// DEFINIÇÕES
#define volumeMP3 30

#define DEBUG

// INSTANCIANDO OBJETOS
SoftwareSerial playerMP3Serial(pinRx, pinTx);
DFRobotDFPlayerMini playerMP3;

// DECLARAÇÃO DE FUNÇÕES

// DECLARAÇÃO DE VARIÁVEIS

void setup() {
  Serial.begin(9600);
  playerMP3Serial.begin(9600);

  Serial.println();
  Serial.println(F("Iniciando DFPlayer ... (Espere 3~5 segundos)"));

  if (!playerMP3.begin(playerMP3Serial)) {  // COMUNICAÇÃO VIA SOFTWARE SERIAL
    Serial.println(F("Falha ao iniciar:"));
    Serial.println(F("1.Confira as conexões!"));
    Serial.println(F("2.Confira o cartão SD!"));
    while (true) {
      delay(0);
    }
  }

  Serial.println(F("DFPlayer ligado!"));

  playerMP3.volume(volumeMP3);

  #ifdef DEBUG
    Serial.println("Fim Setup");
  #endif
}

void loop() {
  playerMP3.playFolder(1, 1);
  Serial.println("Tocando pasta 01, musica 001");
  delay(1000);
}

// IMPLEMENTO DE FUNÇÕES