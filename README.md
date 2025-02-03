<h1 align="left">
  Microcontroladores – Interrupções e Controle de LEDs
  <br>
</h1>
<div align="left">

</div>

<div align="left"> 
  
Esta atividade tem como objetivo aplicar interrupções em microcontroladores utilizando a placa BitDogLab, controlando LEDs comuns e uma matriz de LEDs WS2812 (5x5). O projeto inclui a exibição de números na matriz de LEDs e a manipulação por meio de botões físicos, com tratamento de bouncing via software.
</div>




</details>

## Requisitos

O projeto deve cumprir os seguintes requisitos:

1. **Uso de interrupções (IRQ)**: Todas as funcionalidades acionadas pelos botões devem ser implementadas por meio de interrupções.
2. **Debouncing**: Deve ser implementado software para evitar o bouncing nos botões.
3. **Controle de LEDs**:
    - **Matriz de LEDs WS2812 (5x5)**: Exibição de números de 0 a 9 com um formato fixo ou criativo.
    - **LED RGB**: O LED vermelho deve piscar continuamente 5 vezes por segundo.
4. **Botões físicos**:
    - **Botão A (GPIO 5)**: Incrementa o número exibido na matriz de LEDs.
    - **Botão B (GPIO 6)**: Decrementa o número exibido na matriz de LEDs.
5. **Organização do código**: O código deve ser bem estruturado e comentado.

## Componentes Utilizados

1. **Placa BitDogLab**: Microcontrolador RP2040.
2. **Matriz de LEDs WS2812 (5x5)**: Conectada à GPIO 7.
3. **LED RGB**: Conectado às GPIOs 11, 12 e 13.
4. **Botões físicos**: Conectados às GPIOs 5 e 6.
5. **VS Code**: Ambiente de desenvolvimento.
6. **Simulador Wokwi**: Para simulação do circuito.

<div align="let">
    <img width="800px" src="https://github.com/Kenjibercysec/EmbarcaTech_UN4_Matriz/blob/main/image.png" />
    <p>Fig 1. Projeto no simulador.</p>
</div>

## Estrutura do Projeto

- **led_control.c**: Código para controle dos LEDs WS2812 e LED RGB.
- **interrupts.c**: Implementação das interrupções para os botões.
- **debounce.c**: Funções para tratamento de bouncing.
- **display.c**: Funções para exibir números na matriz de LEDs.
- **main.c**: Código principal do projeto.

## Funcionalidades

- **LED RGB**: O LED vermelho pisca continuamente 5 vezes por segundo.
- **Botão A**: Incrementa o número na matriz de LEDs.
- **Botão B**: Decrementa o número na matriz de LEDs.
- **Matriz de LEDs 5x5**: Exibe números de 0 a 9 em um formato fixo ou criativo.
- **Debouncing**: Tratamento de bouncing nos botões.
- **Uso de interrupções**: Garantia de resposta rápida ao pressionamento dos botões.

## Como Executar

### Pré-requisitos

1. **Git**: Certifique-se de ter o Git instalado.
2. **VS Code**: Instale o Visual Studio Code.
3. **Pico SDK**: Configure o SDK do Raspberry Pi Pico (RP2040).
4. **Simulador Wokwi**: Opcional, para testes sem a placa física.
5. **Conexão USB**: Para carregar o código na placa BitDogLab.

### Passos para Execução

1. **Clonar o repositório**:
   ```bash
   git clone https://github.com/SEU_REPOSITORIO_AQUI.git


2. Abrir no VS Code e compilar o código.

3. Gravar na placa e testar as funcionalidades.

Testes Realizados

1. Interrupções e Debouncing: Verificação do correto funcionamento dos botões.

2. Exibição na Matriz de LEDs: Teste de números de 0 a 9.

3. Piscar do LED RGB: Validação da frequência de 5Hz.

Vídeo Demonstração

[Link para o vídeo](https://youtu.be/4Xuo4_k5qHc)


