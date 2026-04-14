#ifndef LED_h
#define LED_h

#include <Arduino.h>

// CLASSE
class Led
{

private:
    // ENCAPSULAMENTO
    uint8_t pinoLed;
    bool estado;

    uint32_t tempoProximaTroca;
    bool desligadoNoMomento;

    uint32_t tempoAnteriorPiscar;
    uint32_t tempoEspera;
    bool estadoPiscar;
    uint8_t repeticoes;

    void funcaoPiscar();
    void funcaoProcessar();
    void alterarEstado();

public:
    // * MÉTODOS
    Led(uint8_t pinoLed);

    void ligar();
    void ligar(uint16_t tempoligado_ms);

    void desligar();

    // * GETTERS E SETTERS
    bool getEstado();
    void setEstado(bool estado);

    uint8_t getPinoLed();

    void alternar();

    void piscar();
    // * SOBRECARGAS
    void piscar(float frequencia);
    void piscar(float frequencia, uint16_t repeticoes);

    void update();
};

#endif