# Ecolocalizador Tátil para Bicicletas Tandem

Dispositivo de assistência baseado em **feedback tátil** para aumentar a **segurança**, a **confiança** e a **autonomia** de pessoas com deficiência visual na condução de bicicletas tandem.

> Projeto desenvolvido para a Mostra de Computação da UFES.

[Foto do projeto montado]

---

## 📌 Contexto e Motivação

A percepção do ambiente não depende exclusivamente da visão. Casos como o de **Ben Underwood** demonstram que outros sentidos podem ser explorados para navegação espacial.

Inspirados por essa ideia e por iniciativas como o projeto **Pedal Inclusão**, que utiliza bicicletas tandem para permitir que pessoas com deficiência visual pratiquem o ciclismo, tivemos contato direto com os desafios e possibilidades dessa experiência.

Durante um desses eventos, observamos um participante com deficiência visual conduzir a bicicleta apenas com orientações verbais de sua dupla. A experiência evidenciou o potencial da atividade, mas também deixou claro que a condução exige um alto nível de confiança e depende fortemente do ciclista enxergante.

A partir dessa vivência, surgiu a necessidade de pensar em uma **solução técnica** que aumentasse a sensação de segurança e encorajasse mais pessoas com deficiência visual a assumir a condução da bicicleta, tornando a atividade mais inclusiva.

---

## 🎯 Objetivos do Projeto

- Aumentar a segurança do ciclista com deficiência visual durante a condução da bicicleta
- Reduzir a dependência exclusiva de comandos verbais
- Fornecer percepção espacial por meio de feedback tátil
- Tornar a condução mais acessível e o esporte mais inclusivo

---

## 🧠 Visão Geral do Sistema

O sistema é composto por dois módulos principais:

- **Central no guidão da bicicleta**, responsável pela detecção de obstáculos
- **Colete tátil**, responsável por transmitir informações espaciais ao ciclista por meio de vibração

A comunicação entre esses módulos permite que a presença e a direção de obstáculos sejam percebidas sem a necessidade de estímulos sonoros.

[Visão geral do sistema]

---

## 🏗️ Arquitetura do Sistema

### 🔹 Central (Guidão)

A central é responsável pela leitura do ambiente à frente da bicicleta.

Componentes principais:
- Arduino
- 3 sensores ultrassônicos
- Alimentação dedicada

Os sensores estão posicionados no guidão, cobrindo aproximadamente **120°** à frente da bicicleta.

📎 Materiais disponíveis:
- Schematic da central  
- PCB da central  
- Fotos da placa montada  

[Central no guidão]

---

### 🔹 Colete Tátil

O colete é responsável por fornecer o feedback ao ciclista.

Componentes principais:
- 3 motores de vibração
- PCB dedicada
- Estrutura vestível (colete)

Os motores estão posicionados:
- Um no centro do peito
- Um em cada ombro

📎 Materiais disponíveis:
- Schematic do colete  
- PCB do colete  
- Fotos do colete e da confecção  

[Colete tátil]
---

## 🔄 Mapeamento Sensor → Vibração

A informação captada pelos sensores é convertida em padrões de vibração, indicando a direção do obstáculo.

| Sensor | Posição no guidão | Motor ativado | Indicação |
|------|-------------------|---------------|-----------|
| Sensor esquerdo | Esquerda | Ombro esquerdo | Obstáculo à esquerda |
| Sensor central | Centro | Peito | Obstáculo frontal |
| Sensor direito | Direita | Ombro direito | Obstáculo à direita |

---

## 🧩 Componentes Utilizados

| Componente | Quantidade | Função |
|----------|------------|--------|
| Arduino | 1 | Processamento dos dados |
| Sensor ultrassônico | 3 | Detecção de obstáculos |
| Motor de vibração | 3 | Feedback tátil |
| PCB personalizada | 2 | Integração do sistema |
| Estrutura do colete | 1 | Fixação dos motores |
| Cabos e conectores | Diversos | Interligação |

---

## 🛠️ Processo de Desenvolvimento

O desenvolvimento do projeto passou pelas seguintes etapas:

- Levantamento do problema a partir de vivência prática
- Prototipação inicial em bancada
- Desenvolvimento dos esquemáticos
- Projeto e confecção das PCBs
- Montagem dos módulos
- Testes funcionais do sistema

📸 Registros fotográficos do processo estão disponíveis na pasta `docs/imagens`.

---

## 📊 Resultados e Limitações

### Resultados
- Detecção de obstáculos em tempo real
- Feedback tátil claro e direcional
- Funcionamento independente de estímulos sonoros
- Integração confortável ao corpo do usuário

### Limitações
- Sistema ainda em fase de protótipo
- Testes limitados a ambientes controlados
- Necessidade de testes com usuários finais

---

## 🔧 Como Reproduzir o Projeto

- Os esquemáticos estão disponíveis em `docs/schematics`
- Os modelos para impressão em
- Os arquivos de PCB estão disponíveis em `docs/pcb`
- O código-fonte está disponível na pasta `software`
- As imagens e diagramas estão em `docs/imagens`

---

## 👥 Equipe e Agradecimentos

Projeto desenvolvido por estudantes da UFES para a disciplina Projeto Integrado de Computação I.

Nossa equipe é composta por: André Luiz Mendes Siqueira de Freitas, Anna Raquel Sandrini, Arthur Manelli, Caetano Zandonade e Daniela Pimentel

Agradecimentos especiais:
- Projeto **Pedal Inclusão**
- A equipe de robótica da UFES: Erus
- Ao integrante do Vitória Baja: Arthur
- À professora Mariana Lyra que nos auxiliou a fazer a placa PCB
- Ao professor da disciplina Jadir
