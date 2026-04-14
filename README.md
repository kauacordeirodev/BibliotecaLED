# 💡 Biblioteca LED (Arduino/ESP32)

Esta biblioteca foi desenvolvida para oferecer um controle **não-bloqueante** e orientado a objetos de LEDs em projetos de sistemas embarcados. Ela abstrai a complexidade do uso de `millis()` para funções de temporização, permitindo que o microcontrolador execute múltiplas tarefas simultaneamente enquanto gerencia efeitos luminosos.

O diferencial desta biblioteca é a sua **lógica de estado determinística**: qualquer novo comando (como ligar ou alternar) interrompe automaticamente processos automáticos anteriores (como o modo piscar), garantindo que o hardware responda sempre à última intenção do programador.

---

## ✨ Funcionalidades

* **Controle Não-Bloqueante:** Gerenciamento de tempo via `millis()`, eliminando o uso de `delay()` e mantendo o processamento livre.
* **Modo Piscar:** Permite definir a frequência em Hertz (Hz) e o número exato de repetições.
* **Temporização Automática:** Função para ligar o LED por um período específico (ex: 500ms) e desligar automaticamente.
* **Abstração de Toggle (Alternar):** Método simples para inverter o estado atual do LED, ideal para interações com botões.
* **Arquitetura Escalável:** Desenvolvida em C++ com encapsulamento, facilitando o controle de múltiplos LEDs com instâncias independentes.

---

## 🛠️ Tecnologias e Conceitos

* **C++ (Arduino SDK):** Utilização de classes e listas de inicialização para otimização de memória e performance.
* **Orientação a Objetos (POO):** Encapsulamento de estados internos (pino, frequência, repetições) para um código mais limpo.
* **Máquina de Estados:** Gerenciamento interno para garantir que modos automáticos e manuais não entrem em conflito.
* **Desenvolvimento de Sistemas:** Ideal para uso em projetos que exigem alta responsividade.

---

## 📂 Estrutura de Métodos

| Método | Descrição |
| :--- | :--- |
| `ligar()` | Liga o LED continuamente. |
| `ligar(ms)` | Liga o LED por um tempo determinado em milissegundos. |
| `desligar()` | Desliga o LED e reseta qualquer modo automático. |
| `alternar()` | Inverte o estado atual (High/Low). |
| `piscar(freq)` | Inicia o piscar contínuo na frequência desejada (Hz). |
| `piscar(freq, n)` | Pisca na frequência definida por `n` vezes e para. |
| `update()` | Atualiza o estado físico do pino e processa temporizadores. |