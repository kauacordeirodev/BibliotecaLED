#include <Arduino.h>
#include "LED.h"

Led ledVermelho(2);
const uint8_t pinoBotao = 4;

void setup() {
  pinMode(pinoBotao, INPUT_PULLUP);
}

void loop() {
  bool estadoAtualBotao = !digitalRead(pinoBotao);
  static bool estadoAnteriorBotao = 0;

  // Estado do LED alterna ao pressionar o botão.
  if(estadoAtualBotao && !estadoAnteriorBotao) ledVermelho.alternar();
  estadoAnteriorBotao = estadoAtualBotao;

  // Atualiza o estado do LED
  ledVermelho.update();
}