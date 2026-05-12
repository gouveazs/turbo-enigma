#pragma once
#include <string>

class Suspect {
    public:
        int id;
        std::string nome;
        int idade;
        std::string relacao_vitima;
        std::string descricao;
        std::string possivel_motivo;
        std::string alibe;
        bool culpa;
};