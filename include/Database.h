#pragma once

#include <string>
#include <sqlite3.h>
#include <vector>

#include "Suspect.h"
#include "Victim.h"
#include "Crime_Scene.h"
#include "Clues.h"
#include "Info.h"

class Database {

private:
    sqlite3* db;

public:
    Database();
    ~Database();

    bool connect(const std::string& name);

    bool execute(const std::string& sql);

    bool executeFile(const std::string& path);

    bool isOpen() const;

    void close();

    Vitima relatorioVitima();
    Cena_crime verCenaCrime();
    std::vector<Suspect> listarSuspeitos();
    std::vector<Pista> verPistas();
    std::vector<Informacao> verInformacoes();
};
