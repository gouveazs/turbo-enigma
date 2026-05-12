#pragma once 
#include "Database.h"

class Game {
    private:
        void MenuPrincipal(Database& database);
        void InterrogarSuspeito(Database& database);
        void CenaCrime(Database& database);
        void RelatorioVitima(Database& database);
        void VerPistas(Database& Database);
        void VerInformacoes(Database& database);
    
    public:
        void run();
};