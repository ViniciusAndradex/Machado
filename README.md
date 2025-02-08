# Machado Bet
Máquina caça-níquel para sistemas embarcados

## Visão Geral

A **Machado Bet** é uma máquina caça-níquel desenvolvida para sistemas embarcados. Este projeto não só oferece uma experiência de jogo completa como também explora e demonstra diversos aspectos de programação em sistemas embarcados, como interfaces de hardware (PWM, I2C, ADC), além de interações com componentes como LEDs, botões, tela OLED e joystick.

O jogo é projetado para ser **legítimo e justo**, com um RTP (Return to Player) de **85.6%**, o que garante uma jogabilidade equilibrada sem manipulação de dados. A mecânica do jogo é baseada em um algoritmo de sorteio de números, sem qualquer tipo de interferência externa.

## Teoria do Jogo

O conceito central por trás da **Machado Bet** é o retorno ao jogador (RTP), que é a porcentagem do dinheiro apostado que o jogo devolve aos jogadores ao longo do tempo. Com um RTP de **85.6%**, o jogo é ajustado para ser justo, proporcionando uma experiência de cassino legítima.

### Como Funciona o RTP

O **RTP (Return to Player)** é um índice matemático que representa a quantidade do valor apostado que, em média, é devolvida ao jogador em forma de prêmios. O valor de 85.6% indica que, para cada 100 unidades apostadas, 85.6 unidades serão devolvidas ao longo de várias jogadas. Esse valor é essencial para a transparência e justiça do jogo, pois garante que os jogadores tenham uma expectativa de retorno previsível e adequada.

### Estrutura do Jogo

- **Sorteios Justos**: O jogo sorteia números aleatórios para gerar combinações em três colunas. Não há manipulação ou favorecimento, garantindo um jogo justo.
- **Padrões de Premiação**:
    - Trinca de '0': 15x o valor apostado.
    - Trinca de qualquer outro número (111, 222, ..., 999): 6.5x o valor apostado.
    - Dupla de '0' (00, 100, 200, ...): 5.5x o valor apostado.
    - Dupla de qualquer outro número (11, 22, ..., 99): 3.2x o valor apostado.

## Aspectos Técnicos

### Hardware

A **Machado Bet** foi desenvolvida utilizando a placa **BitDogLab**, que oferece uma plataforma robusta para sistemas embarcados. Para a implementação do jogo, foram utilizados os seguintes componentes de hardware:

- **LEDs**: Para criar efeitos visuais durante o sorteio e quando o jogador ganhar.
- **Botões**: Para interagir com o jogo, permitindo o jogador fazer apostas e iniciar o sorteio.
- **Tela OLED**: Utilizada para exibir as combinações sorteadas e informações do jogo.
- **Joystick**: Para adicionar uma camada extra de interatividade, permitindo ao jogador ajustar a aposta ou navegar pelas opções do jogo.

### Interfaces de Comunicação

O projeto explora várias interfaces de hardware para garantir uma operação eficiente:

- **PWM (Pulse Width Modulation)**: Usado para controlar a intensidade dos LEDs e gerar efeitos visuais durante o sorteio. Além disso, o PWM é configurado para controlar os **buzzers**, emitindo alertas sonoros durante o jogo.
- **I2C (Inter-Integrated Circuit)**: Usado para comunicação com a tela OLED, permitindo a exibição dinâmica das informações do jogo.
- **ADC (Analog-to-Digital Converter)**: Utilizado para ler o estado do joystick, interpretando os movimentos analógicos do jogador.

### Algoritmo de Sorteio

O sorteio das colunas é baseado em um algoritmo legítimo que gera números aleatórios, garantindo que o jogo seja justo e transparente. O uso de funções de geração de números aleatórios com semente baseada em fatores imprevisíveis (como a leitura de sensores analógicos) garante que o jogo seja imprevisível e sem manipulação externa.

## Conclusão

A **Machado Bet** é uma demonstração poderosa de como a programação de sistemas embarcados pode ser utilizada para criar jogos complexos e interativos, com uma interface de hardware envolvente e uma lógica de jogo transparente. O projeto não só serve como uma aplicação de entretenimento, mas também como um exemplo de como explorar diversas interfaces e técnicas em sistemas embarcados.

## Licença

Este projeto é licenciado sob a MIT License - consulte o arquivo LICENSE para mais detalhes.

## Desenvolvedor
Vinicius Andrade de Moura

### Projeto
> Embarcatech
