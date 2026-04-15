//EXEMPLO 03
/**
 * Descrição: Este exemplo demonstra o LED piscando na frequencia que o usuário escolher até as repetições acabarem.
 */


#include <Arduino.h>
#include "LED.h"

Led ledVermelho(2);

void setup() {
  // Inicia o modo de piscar (frequência: 2Hz)
  // Pisca 10 vezes completas, o LED desliga após a finalização das repetições.
  ledVermelho.piscar(2, 10);
}

void loop() {
  // Atualiza o estado do LED
  ledVermelho.update();
}
