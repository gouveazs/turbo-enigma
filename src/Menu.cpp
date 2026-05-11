#include <iostream>
#include "../include/Menu.h"

int Menu :: MenuInicial() {
    int opcao;

    std::cout << "\n === Casa das Folhas ===\n";
    std::cout << "1 - Novo Jogo\n";
    std::cout << "2 - Carregar Jogo\n";
    std::cout << "3 - Sair do jogo\n";

    std::cin >> opcao;

    return opcao;
}

int Menu :: MenuInvestigacao() {
    int acao;

    std::cout << "\n=== Investigação ===\n";
    std::cout << "1 - Ir para cena do crime\n";
    std::cout << "2 - Ver relatorio da vitima\n";
    std::cout << "3 - Ver relatorio de suspeitos\n";
    std::cout << "4 - Ver pistas\n";
    std::cout << "5 - Ver informacoes do caso\n";
    std::cout << "6 - Acusar suspeito\n";
    std::cout << "7 - Voltar\n";
    std::cout << "Escolha: ";

    std::cin >> acao;

    return acao;
}
