📡 Monitoramento e Controle com ESP32
📌 Descrição do Projeto

Este projeto utiliza o microcontrolador ESP32 para realizar o monitoramento do nível de luminosidade através de um fotorresistor (LDR), exibindo as informações em um display LCD com comunicação I2C e controlando um LED de acordo com a intensidade da luz.

O sistema também conta com um botão que alterna entre dois modos de exibição no display:

Valor bruto do sensor
Porcentagem de luminosidade
⚙️ Componentes Utilizados
ESP32
Fotorresistor (LDR)
LED
Botão
Display LCD I2C
🧠 Parte I – Avaliação Teórica
1. Resolução

a) Valor máximo do analogRead():

ESP32 (12 bits):
→ 2¹² - 1 = 4095
Arduino UNO (10 bits):
→ 2¹⁰ - 1 = 1023

Resposta:

ESP32: 4095
Arduino UNO: 1023

b) Uso da função map():

A função map() (ou um cálculo proporcional) é necessária para converter os valores do sensor analógico, que variam em uma faixa maior (ex: 0 a 4095 no ESP32), para a faixa suportada por saídas PWM (geralmente de 0 a 255).

Sem essa conversão, os valores do sensor não seriam compatíveis com a saída, comprometendo o controle do dispositivo.

2. Protocolo I2C

O protocolo I2C é vantajoso porque permite a comunicação com múltiplos dispositivos utilizando apenas dois pinos (SDA e SCL).

Cada dispositivo possui um endereço único, permitindo que o microcontrolador se comunique com vários periféricos sem a necessidade de múltiplas conexões físicas, reduzindo a complexidade do circuito.

## 💻 Funcionamento do Código

O sistema realiza a leitura do valor analógico de um fotorresistor (LDR) conectado ao ESP32, utilizando a função `analogRead()`. Esse valor representa a intensidade da luz no ambiente.

A partir dessa leitura, é feito um cálculo proporcional para converter o valor em uma porcentagem de luminosidade, facilitando a interpretação dos dados.

Com base em um valor limite pré-definido, o sistema decide automaticamente se o LED deve ser ligado ou desligado:

* Ambientes mais escuros → LED desligado
* Ambientes mais claros → LED ligado

Além disso, um botão permite alternar entre dois modos de exibição no display LCD via comunicação I2C:

* **Modo 1:** Exibe o valor bruto lido pelo sensor
* **Modo 2:** Exibe a porcentagem de luminosidade calculada

O display também informa o estado atual do LED (ligado ou desligado), permitindo um acompanhamento em tempo real do comportamento do sistema.
