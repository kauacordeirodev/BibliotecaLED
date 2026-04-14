#include "LED.h"

Led::Led(uint8_t pinoLed) : // * LISTA DE INICIALIZAÇÃO
                            pinoLed(pinoLed),
                            estado(LOW),
                            tempoProximaTroca(0),
                            desligadoNoMomento(true),
                            tempoAnteriorPiscar(0),
                            tempoEspera(0),
                            estadoPiscar(false),
                            repeticoes(0)
{
    pinMode(pinoLed, OUTPUT);
}

void Led::ligar()
{
    estadoPiscar = false;
    estado = HIGH;
}

void Led::ligar(uint16_t tempoligado_ms)
{
    estadoPiscar = false;
    estado = HIGH;
    desligadoNoMomento = false;
    tempoProximaTroca = millis() + tempoligado_ms;
}

void Led::desligar()
{
    estadoPiscar = false;
    estado = LOW;
}

bool Led::getEstado()
{
    return estado;
}

void Led::setEstado(bool estado)
{
    estadoPiscar = false;
    this->estado = estado;
}

uint8_t Led::getPinoLed()
{
    return pinoLed;
}

void Led::alternar()
{
    estadoPiscar = false;
    estado = !estado;
}

void Led::piscar()
{
    desligadoNoMomento = true;
    estadoPiscar = true;
    tempoEspera = 500;
    tempoAnteriorPiscar = millis();
    estado = HIGH;
}

void Led::piscar(float frequencia)
{
    desligadoNoMomento = true;
    estadoPiscar = true;
    tempoEspera = 1000.0f / (frequencia * 2.0f);
    tempoAnteriorPiscar = millis();
    estado = HIGH;
}

void Led::piscar(float frequencia, uint16_t repeticoes)
{
    desligadoNoMomento = true;
    estadoPiscar = true;
    tempoEspera = 1000.0f / (frequencia * 2.0f);
    tempoAnteriorPiscar = millis();
    estado = HIGH;

    this->repeticoes = repeticoes * 2;
}

void Led::funcaoPiscar()
{
    if (estadoPiscar)
    {
        if (millis() - tempoAnteriorPiscar >= tempoEspera)
        {
            estado = !estado;
            tempoAnteriorPiscar = millis();

            if (repeticoes > 0)
            {
                repeticoes--;
                if (repeticoes == 0)
                {
                    estadoPiscar = false;
                    estado = LOW;
                }
            }
        }
    }
}

void Led::funcaoProcessar()
{
    if (!desligadoNoMomento)
    { // ? LED DESLIGADO?
        if (millis() >= tempoProximaTroca)
        { // ? PASSOU O TEMPO DETERMINADO?
            estado = LOW;
            desligadoNoMomento = true;
        }
    }
}

void Led::alterarEstado()
{
    digitalWrite(pinoLed, estado);
}

void Led::update()
{
    alterarEstado();
    funcaoProcessar();
    funcaoPiscar();
}