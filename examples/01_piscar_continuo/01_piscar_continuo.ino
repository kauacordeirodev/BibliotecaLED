#include <Arduino.h>
#include "LED.h"

Led ledVermelho(2);

void setup() {
  // Inicia o modo de piscar (frequência padrão: 1Hz)
  ledVermelho.piscar();
}

void loop() {
  // Atualiza o estado do LED
  ledVermelho.update();
}