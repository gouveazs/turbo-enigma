# Casa das Folhas

Casa das Folhas é um jogo investigativo em terminal feito em C++ com SQLite.
O jogador assume o papel de investigador, analisa a cena do crime, consulta o
relatório da vítima, interroga suspeitos, encontra pistas e decide quem acusar.

## Funcionalidades

- Menu interativo no terminal
- Efeito de digitação nos textos
- Banco de dados SQLite para guardar vítima, suspeitos, pistas e informações
- Pistas desbloqueadas conforme o jogador investiga
- Sistema de acusação com final de vitória ou derrota

## Tecnologias

- C++
- SQLite

## Como Compilar

```bash
g++ -std=c++17 main.cpp src/*.cpp -Iinclude -lsqlite3 -o game
```

## Como Rodar

```bash
./game
```

## Estrutura

- `main.cpp`: entrada do programa
- `src/Game.cpp`: fluxo principal do jogo
- `src/Menu.cpp`: menus do terminal
- `src/Database.cpp`: conexão e consultas no banco
- `src/Utils.cpp`: funções auxiliares, como limpar tela e efeito de digitação
- `data/schema.sql`: criação das tabelas
- `data/game.sql`: dados iniciais do caso

## Objetivo

Investigue o caso, reúna as pistas e acuse o suspeito correto. A acusação
encerra o jogo, seja com sucesso ou com fracasso.
