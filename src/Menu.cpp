#include <iostream>
#include "../include/Menu.h"
#include "../include/Utils.h"

int Menu :: MenuInicial() {
    int opcao;

    digitarTexto("\n === Casa das Folhas ===\n", 15);
    digitarTexto("1 - Novo Jogo\n", 5);
    digitarTexto("2 - Carregar Jogo\n", 5);
    digitarTexto("3 - Sair do jogo\n", 5);
    digitarTexto("Escolha: ", 10);

    std::cin >> opcao;

    return opcao;
}

int Menu :: MenuPrincipal() {
    int acao;

    digitarTexto("\n=== Investigação ===\n", 10);
    digitarTexto("1 - Ir para cena do crime\n", 3);
    digitarTexto("2 - Ver relatorio da vitima\n", 3);
    digitarTexto("3 - Interrogar suspeitos\n", 3);
    digitarTexto("4 - Ver pistas\n", 3);
    digitarTexto("5 - Ver informacoes do caso\n", 3);
    digitarTexto("6 - Acusar suspeito\n", 3);
    digitarTexto("7 - Voltar\n", 3);
    digitarTexto("Escolha: ", 8);

    std::cin >> acao;

    return acao;
}

int Menu::InterrogarSuspeito() {
    int quem;

    digitarTexto("\n=== Sala de Interrogatório ===\n", 10);
    digitarTexto("1 - Isabela Camaro\n", 4);
    digitarTexto("2 - Alexandre Magno\n", 4);
    digitarTexto("3 - Murilo Paiva\n", 4);
    digitarTexto("Quem você deseja interrogar: ", 8);

    std::cin >> quem;

    return quem;
}

int Menu::Acusacao() {
    int quem;

    digitarTexto("\n=== Tribunal ===\n", 15);
    digitarTexto("1 - Isabela Camaro\n", 4);
    digitarTexto("2 - Alexandre Magno\n", 4);
    digitarTexto("3 - Murilo Paiva\n", 4);
    digitarTexto("Quem é o culpado: ", 12);

    std::cin >> quem;

    return quem;
}
