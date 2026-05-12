# 🕯️ Casa das Folhas

Um jogo investigativo de terminal feito em **C++**.

Em **Casa das Folhas**, você assume o papel de um investigador responsável por
resolver um crime dentro de uma escola. Para chegar à verdade, é preciso visitar
a cena do crime, ler o relatório da vítima, interrogar suspeitos, reunir pistas
e fazer uma acusação final.

> ⚠️ Cuidado: a acusação encerra o caso.  
> Se escolher a pessoa errada, o verdadeiro culpado escapa.

## 🔎 Sobre o Jogo

O jogo acontece inteiramente pelo terminal e usa um banco **SQLite** para guardar
os dados do caso, como vítima, suspeitos, pistas e informações importantes.

Durante a investigação, novas pistas são desbloqueadas conforme o jogador toma
certas ações. No final, o jogador deve decidir quem é o culpado.

## ✨ Funcionalidades

- 🧭 Menus interativos no terminal
- ⌨️ Efeito de digitação nos textos
- 📍 Cena do crime com pista desbloqueável
- 📝 Relatório da vítima
- 🗣️ Interrogatório de suspeitos
- 🧩 Sistema de pistas encontradas
- 📚 Informações extras do caso
- ⚖️ Acusação final com vitória ou derrota
- 🗄️ Banco de dados SQLite para organizar os dados do jogo

## 🛠️ Tecnologias

- C++
- SQLite

## 🚀 Como Compilar

Na raiz do projeto, execute:

```bash
g++ -std=c++17 main.cpp src/*.cpp -Iinclude -lsqlite3 -o game
```

## 🎮 Como Rodar

Depois de compilar:

```bash
./game
```

## 📁 Estrutura do Projeto

```text
.
├── data/
│   ├── game.sql       # Dados iniciais do caso
│   └── schema.sql     # Estrutura das tabelas
├── include/           # Arquivos de cabeçalho
├── src/               # Implementação das classes
├── main.cpp           # Entrada do programa
└── README.md
```

## 📌 Principais Arquivos

- `src/Game.cpp`: controla o fluxo principal da investigação
- `src/Menu.cpp`: exibe os menus e recebe escolhas do jogador
- `src/Database.cpp`: conecta e consulta o banco SQLite
- `src/Utils.cpp`: funções auxiliares, como limpar tela e efeito de digitação
- `data/game.sql`: personagens, pistas e informações do caso
- `data/schema.sql`: criação das tabelas do banco

## 🕵️ Objetivo

Investigue com atenção, conecte as pistas e acuse o suspeito correto.

**Uma decisão errada pode encerrar o caso para sempre.**
