#include <iostream> 
#include "../include/Game.h"
#include "../include/Menu.h"
#include "../include/Database.h"
#include "../include/Utils.h"

void Game :: run() {
    Database database;

    if(!database.connect("data/game.db")) {
        return;
    }
    if(!database.executeFile("data/schema.sql")) {
        return;
    }
    if(!database.executeFile("data/game.sql")) {
        return;
    }

    Menu menu;
    int opcao = 0;

    while(opcao != 1) {
        opcao = menu.MenuInicial();

        switch (opcao) {
            case 1:
                limparTela();
                digitarTexto("Iniciando novo jogo...\n", 35);
                MenuPrincipal(database);
                break;
            default:
                digitarTexto("Opção inválida!\n", 20);
                break;
        }
    }
}

void Game::MenuPrincipal(Database& database) {
    Menu menu;
    int opcao = 0;

    while(opcao != 7) {
        opcao = menu.MenuPrincipal();

        switch(opcao) {
            case 1: {
                CenaCrime(database);
                break;
            }
            case 2: { 
                RelatorioVitima(database);
                break;
            }
            case 3: {
                InterrogarSuspeito(database);
                break;
            }
            case 4: {
                VerPistas(database);
                break;
            }
            case 5: {
                VerInformacoes(database);
                break;
            }
            case 6: {
                if(AcusarSuspeito(database)) {
                    return;
                }
                break;
            }
            case 7: {
                break;
            }
            default: {
                digitarTexto("Opção inválida!\n", 20);
                break;
            }
        };
    }
}

void Game::InterrogarSuspeito(Database& database) {
    limparTela();
    
    Menu menu;
    int escolha = menu.InterrogarSuspeito();
    std::vector<Suspect> suspeitos = database.listarSuspeitos();

    for(const Suspect& suspeito : suspeitos) {
        if(suspeito.id == escolha) {
            digitarTexto("\n === Interrogatório ===\n", 12);
            digitarTexto("Nome: " + suspeito.nome + "\n", 8);
            digitarTexto("Idade: " + std::to_string(suspeito.idade) + "\n", 8);
            digitarTexto("Relação com a vítima: " + suspeito.relacao_vitima + "\n", 8);
            digitarTexto("Descricao: " + suspeito.descricao + "\n", 8);
            digitarTexto("Possível motivo: " + suspeito.possivel_motivo + "\n", 8);
            digitarTexto("Alibe: " + suspeito.alibe + "\n\n", 8);
            if(suspeito.id == 2) {
                database.marcarPistaEncontrada(3);
                digitarTexto("Você encontrou uma pista! Acesse opção pistas para ver.\n", 15);
            }
            else if(suspeito.id == 3) {
                database.marcarPistaEncontrada(2);
                digitarTexto("Você encontrou uma pista! Acesse opção pistas para ver.\n", 15);
            }
            return;
        }
    }

    digitarTexto("Suspeito inválido!\n", 20);
}

bool Game::AcusarSuspeito(Database& database) {
    limparTela();

    Menu menu;
    int quem = menu.Acusacao();
    std::vector<Suspect> suspeitos = database.listarSuspeitos();

    for(const Suspect& suspeito : suspeitos) {
        if(suspeito.id == quem) {
            if(suspeito.culpa == 1) {
                digitarTexto("O verdadeiro assasino foi preso.\n", 35);
                digitarTexto("Parabéns você resolveu o caso!\n\n", 35);
            } else {
                digitarTexto("Você acusou uma pessoa inocênte...\n", 35);
                digitarTexto("O verdadeiro assasino fugiu.\n", 35);
                digitarTexto("Você não resolveu o caso!\n\n", 35);
            }
            return true;
        }
    }

    digitarTexto("Suspeito inválido!\n", 20);
    return false;
}

void Game::CenaCrime(Database& database) {
    limparTela();

    Cena_crime cena = database.verCenaCrime();
    database.marcarPistaEncontrada(1);

    digitarTexto("\n=== Cena do Crime ===\n", 12);
    digitarTexto("Local: " + cena.local + "\n", 10);
    digitarTexto("Descricao: " + cena.descricao + "\n", 10);
    digitarTexto("Horario estimado: " + cena.horario_estimado + "\n", 10);
    digitarTexto("Clima: " + cena.clima + "\n\n", 10);
    digitarTexto("Você encontrou uma pista! Acesse opção pistas para ver.\n", 15);
}

void Game::RelatorioVitima(Database& database) {
    limparTela();
    
    Vitima vitima = database.relatorioVitima();

    digitarTexto("\n === Relatório da Vítima ===\n", 12);
    digitarTexto("Nome: " + vitima.nome + "\n", 10);
    digitarTexto("Sexo: Feminino\n", 10);
    digitarTexto("Idade: " + std::to_string(vitima.idade) + "\n", 10);
    digitarTexto("Estado encontrada: " + vitima.estado_encontrada + "\n", 10);
    digitarTexto("Causa da morte: " + vitima.causa_morte + "\n", 10);
    digitarTexto("Horário da morte: " + vitima.horario_morte + "\n", 10);
    digitarTexto("Observações: " + vitima.observacoes + "\n\n", 10);
}

void Game::VerPistas(Database& database) {
    limparTela();
    
    std::vector<Pista> pistas = database.verPistas();

    digitarTexto("\n === Pistas do Caso ===\n", 12);
    for(const Pista& pista : pistas) {
        digitarTexto("Título: " + pista.nome + "\n", 8);
        digitarTexto("Descricao: " + pista.descricao + "\n\n", 8);
    }
}

void Game::VerInformacoes(Database& database) {
    limparTela();
    
    std::vector<Informacao> infos = database.verInformacoes();
        
    digitarTexto("\n === Informações do Caso ===\n", 12);
    for(const Informacao& info : infos) {
        digitarTexto("Título: " + info.titulo + "\n", 8);
        digitarTexto("Descrição: " + info.descricao + "\n\n", 8);
    }
}
