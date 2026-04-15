//EXEMPLO 05
/**
 * Descrição: Este exemplo demonstra o LED acionando por um tempo determinado pelo usuário, após o final desse tempo o LED desliga.
 */


#include <Arduino.h>
#include "LED.h"

Led ledVermelho(2);

void setup()
{
    // Liga o LED e após 2 segundos desliga.
    ledVermelho.ligar(2000);
}

void loop()
{
    // Atualiza o estado do LED
    ledVermelho.update();
}