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

    while(opcao != 3) {
        opcao = menu.MenuInicial();

        switch (opcao) {
            case 1:
                //limparTela();
                std::cout << "Iniciando novo jogo...\n";
                //digitarTexto("Inciando novo jogo...\n", 35);
                MenuInvestigacao(database);
                break;
            
            case 2:
                std::cout << "Carregando jogo salvo...";
                break;

            case 3:
                std::cout << "Abandonando distintivo...";
                break;

            default:
                std::cout << "Opção inválida!";
                break;
        }
    }
}

void Game::MenuInvestigacao(Database& database) {
    Menu menu;
    int opcao = 0;

    while(opcao != 7) {
        opcao = menu.MenuInvestigacao();

        switch(opcao) {
            case 1: {
                Cena_crime cena = database.verCenaCrime();

                std::cout << "\n=== Cena do Crime ===\n";
                std::cout << "Local: " << cena.local << "\n";
                std::cout << "Descricao: " << cena.descricao << "\n";
                std::cout << "Horario estimado: " << cena.horario_estimado << "\n";
                std::cout << "Clima: " << cena.clima << "\n";

                break;
            }
            case 2: { 
                Vitima vitima = database.relatorioVitima();

                std::cout << "\n === Relatório da Vítima ===\n";
                std::cout << "Nome: " << vitima.nome << "\n";
                std::cout << "Sexo: Feminino\n";
                std::cout << "Idade: " << vitima.idade << "\n";
                std::cout << "Estado encontrada: " << vitima.estado_encontrada << "\n";
                std::cout << "Causa da morte: " << vitima.causa_morte << "\n";
                std::cout << "Observações: " << vitima.observacoes << "\n";
                
                break;
            }
            case 3: {
                std::vector<Suspect> suspeitos = database.listarSuspeitos();

                std::cout << "\n === Relatório de Suspeitos ===\n";
                for(const Suspect& suspeito : suspeitos) {
                    std::cout << "Nome: " << suspeito.nome << "\n";
                    std::cout << "Descricao: " << suspeito.descricao << "\n";
                    std::cout << "Motivo: " << suspeito.motivo << "\n";
                    std::cout << "Alibi: " << suspeito.alibe << "\n\n";
                }

                break;
            }
            case 4: {
                std::vector<Pista> pistas = database.verPistas();

                std::cout << "\n === Pistas do Caso ===\n";
                for(const Pista& pista : pistas) {
                    std::cout << "Título: " << pista.nome << "\n";
                    std::cout << "Descricao: " << pista.descricao << "\n";
                }

                break;
            }
            case 5: {
                std::vector<Informacao> infos = database.verInformacoes();
                
                std::cout << "\n === Informações do Caso ===\n";
                for(const Informacao& info : infos) {
                    std::cout << "Título: " << info.titulo << "\n";
                    std::cout << "Descrição: " << info.descricao << "\n\n";
                }

                break;
            }
            case 6: {
                //funcaoAcusarSuspeito();
            }
            default: {
                std::cout << "Opção inválida!";
                break;
            }
        };
    }
}
