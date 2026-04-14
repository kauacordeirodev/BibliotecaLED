#ifndef LED_h
#define LED_h

#include <Arduino.h>

/**
 * @class Led
 * @brief Classe para controle não bloqueante de um LED.
 * Permite ligar, desligar, ligar por tempo determinado, piscar continuamente e piscar por quantidade definida
 * @note O método update() deve ser chamado continuamente dentro do loop().
 */
class Led
{
private:
    uint8_t pinoLed;
    bool estado;

    uint32_t tempoProximaTroca;
    bool desligadoNoMomento;

    uint32_t tempoAnteriorPiscar;
    uint32_t tempoEspera;
    bool estadoPiscar;
    uint8_t repeticoes;

    /**
     * @brief Processa a lógica de piscada do LED.
     */
    void funcaoPiscar();

    /**
     * @brief Processa o desligamento temporizado.
     */
    void funcaoProcessar();

    /**
     * @brief Processa a alteração de estado do LED.
     */
    void alterarEstado();

public:
    /**
     * @brief Constrói um objeto Led.
     * @param pinoLed Número do pino digital onde o LED está conectado.
     */
    Led(uint8_t pinoLed);

    /**
     * @brief Liga o LED continuamente.
     */
    void ligar();

    /**
     * @brief Liga o LED por um tempo determinado.
     * @param tempoLigado_ms Tempo, em milissegundos, que o LED ficará ligado.
     */
    void ligar(uint16_t tempoligado_ms);

    /**
     * @brief Desliga o LED e cancela os modos automáticos.
     */
    void desligar();

    /**
     * @brief Retorna o estado do LED
     */
    bool getEstado();

    /**
     * @brief Altera manualmente o estado do LED para o parâmetro recebido.
     * @param estado true para ligado, false para desligado.
     */
    void setEstado(bool estado);

    /**
     * @brief Retorna o número do pino digital onde o LED está conectado.
     */
    uint8_t getPinoLed();

    /**
     * @brief Alterna o nivel lógico do LED.
     */
    void alternar();

    /**
     * @brief Inicia a piscada contínua em 1 Hz.
     */
    void piscar();

    /**
     * @brief Inicia a piscada contínua com a frequencia definida.
     * @param frequencia Frequencia da piscada em hertz.
     */
    void piscar(float frequencia);

    /**
     * @brief Inicia a piscada uma quantidade definida de vezes.
     * @param frequencia Frequência da piscada em hertz.
     * @param repeticoes Quantidade de piscadas completas.
     */
    void piscar(float frequencia, uint16_t repeticoes);

    /**
     * @brief Atualiza constantemente os processos e estado do LED.
     */
    void update();
};

#endif