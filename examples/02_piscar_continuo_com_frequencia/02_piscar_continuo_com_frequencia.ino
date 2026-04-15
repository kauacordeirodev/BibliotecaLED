//EXEMPLO 02
/**
 * Descrição: Este exemplo demonstra o LED piscando na frequencia que o usuário escolher.
 */


#include <Arduino.h>
#include "LED.h"

Led ledVermelho(2);

void setup() {
  // Inicia o modo de piscar (frequência: 4Hz)
  ledVermelho.piscar(4);
}

void loop() {
  // Atualiza o estado do LED
  ledVermelho.update();
}
