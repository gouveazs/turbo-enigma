std::vector<Suspect> suspeitos = database.listarSuspeitos();

                std::cout << "\n === Relatório de Suspeitos ===\n";
                for(const Suspect& suspeito : suspeitos) {
                    std::cout << "Nome: " << suspeito.nome << "\n";
                    std::cout << "Idade: " << suspeito.idade << "\n";
                    std::cout << "Relação com a vítima: " << suspeito.relacao_vitima << "\n";
                    std::cout << "Descricao: " << suspeito.descricao << "\n";
                    std::cout << "Possível motivo: " << suspeito.possivel_motivo << "\n";
                    std::cout << "Alibe: " << suspeito.alibe << "\n\n";
                }

                break;