# AmpTrack

## ⚡ Simulador Interativo de Consumo de Energia

Projeto extensionista visando entender o consumo de energia elétrica residencial, utilizando simulação de hardware e interface web em tempo real.

### 📖 Sobre o Projeto

O objetivo principal é criar um produto de software/hardware simulado que funcione como um medidor de consumo de energia. Através de uma interface interativa, os usuários podem simular a ligação de múltiplos eletrodomésticos, visualizar o impacto de cada um no consumo total (Potência, Corrente e kWh) e entender visualmente como evitar sobrecargas e reduzir o valor da conta de luz.

Como projeto de extensão, a ferramenta visa traduzir conceitos técnicos de eletricidade para um painel visual acessível à comunidade em geral.

### 🎯 Funcionalidades Principais

* **Controle de Dispositivos:** Ligar e desligar aparelhos virtuais (lâmpadas, TVs, ar-condicionado, etc.) via interface web.
* **Cálculo em Tempo Real:** Atualização dinâmica de Tensão (V), Corrente Total (A) e Potência Total (W) baseada nas resistências (Ω) dos aparelhos.
* **Histórico de Consumo:** Gráfico dinâmico atualizado a cada intervalo de tempo mostrando a curva de consumo.
* **Alerta de Segurança:** Indicadores visuais de sobrecarga caso a corrente total ultrapasse o limite do disjuntor (ex: 15A).
* **Adição Customizada:** Permite ao usuário inserir novos dispositivos informando a resistência ou potência desejada.

### 🏗️ Arquitetura do Sistema

O projeto adota uma arquitetura modular, permitindo que a lógica de simulação e a interface evoluam separadamente:

1. **Motor de Simulação (C++ / Microcontrolador):** Responsável por modelar os objetos do circuito, gerenciar o estado dos interruptores e realizar os cálculos físicos ($P = V \times I$). Pode ser embarcado em um ESP32 (simulado via Wokwi) ou compilado para WebAssembly.
2. **Backend / API (Intermediário):** Gerencia o fluxo de dados e o estado da simulação, servindo como ponte entre o hardware e o painel web.
3. **Dashboard Web (Frontend):** Interface de usuário construída em HTML/CSS/JavaScript responsivo, exibindo medidores, listas de dispositivos e gráficos.

### 🛠️ Tecnologias Utilizadas

* **Lógica e Cálculos:** C++ / JavaScript (MVP)
* **Frontend:** HTML5, CSS3, JavaScript
* **Visualização de Dados:** Integração com bibliotecas de gráficos web
* **Simulação de Hardware:** Wokwi (para validação do código C++ embarcado)
