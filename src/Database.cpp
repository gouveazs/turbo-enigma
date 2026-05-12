#include "../include/Database.h"
#include <fstream>
#include <iostream>
#include <sstream>

Database::Database() {
    db = nullptr;
}

Database::~Database() {
    close();
}

bool Database::connect(const std::string& name) {

    int result = sqlite3_open(name.c_str(), &db);

    if(result != SQLITE_OK) {

        std::cout << "Erro ao abrir banco: "
                  << sqlite3_errmsg(db) << "\n";

        return false;
    }

    return true;
}

bool Database::execute(const std::string& sql) {

    char* errMsg = nullptr;

    int result = sqlite3_exec(
        db,
        sql.c_str(),
        nullptr,
        nullptr,
        &errMsg
    );

    if(result != SQLITE_OK) {

        std::cout << "Erro SQL: "
                  << errMsg << "\n";

        sqlite3_free(errMsg);

        return false;
    }

    return true;
}

bool Database::executeFile(const std::string& path) {
    std::ifstream file(path);

    if(!file.is_open()) {
        std::cout << "Erro ao abrir arquivo SQL: "
                  << path << "\n";

        return false;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    return execute(buffer.str());
}

bool Database::isOpen() const {
    return db != nullptr;
}

void Database::close() {

    if(db != nullptr) {

        sqlite3_close(db);

        db = nullptr;
    }
}

Vitima Database::relatorioVitima() {
    sqlite3_stmt* stmt;
    Vitima vitima;

    const char* sql = "SELECT id, nome, idade, estado_encontrada, causa_morte, horario_morte, observacoes FROM vitima ORDER BY id;";

    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    if(result != SQLITE_OK) {
        return vitima;
    }

    while(sqlite3_step(stmt) == SQLITE_ROW) {
        vitima.id = sqlite3_column_int(stmt, 0);
        vitima.nome = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        vitima.idade = sqlite3_column_int(stmt, 2);
        vitima.estado_encontrada = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        vitima.causa_morte = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        vitima.horario_morte = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
        vitima.observacoes = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
    }

    sqlite3_finalize(stmt);

    return vitima;
}

Cena_crime Database::verCenaCrime() {
    Cena_crime cena;
    sqlite3_stmt* stmt;

    const char* sql = "SELECT id, local, descricao, horario_estimado, clima FROM cena_crime ORDER BY id;";
    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

     if(result != SQLITE_OK) {
        return cena;
    }

    while(sqlite3_step(stmt) == SQLITE_ROW) {
        cena.id = sqlite3_column_int(stmt, 0);
        cena.local = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        cena.descricao = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        cena.horario_estimado = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        cena.clima = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
    }

    sqlite3_finalize(stmt);

    return cena;
}

bool Database::marcarPistaEncontrada(int id) {
    std::string sql = "UPDATE pistas SET encontrada = 1 WHERE id = " + std::to_string(id) + ";";
    return execute(sql);
}

std::vector<Suspect> Database::listarSuspeitos() {
    std::vector<Suspect> suspeitos;
    sqlite3_stmt* stmt;

    const char* sql = "SELECT id, nome, idade, relacao_vitima, descricao, possivel_motivo, alibe, culpa FROM suspeitos ORDER BY id;";

    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    if(result != SQLITE_OK) {
        return suspeitos;
    }

    while(sqlite3_step(stmt) == SQLITE_ROW) {
        Suspect suspeito;

        suspeito.id = sqlite3_column_int(stmt, 0);
        suspeito.nome = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        suspeito.idade = sqlite3_column_int(stmt, 2);
        suspeito.relacao_vitima = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        suspeito.descricao = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        suspeito.possivel_motivo = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
        suspeito.alibe = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
        suspeito.culpa = sqlite3_column_int(stmt, 7) == 1;

        suspeitos.push_back(suspeito);
    }

    sqlite3_finalize(stmt);

    return suspeitos;
}

std::vector<Pista> Database::verPistas() {
    std::vector<Pista> pistas;
    sqlite3_stmt* stmt;

    const char* sql = "SELECT id, nome, descricao, encontrada FROM pistas WHERE encontrada = 1 ORDER BY id;";
    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    if (result != SQLITE_OK) {
        return pistas;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Pista pista;
        pista.id = sqlite3_column_int(stmt, 0);
        pista.nome = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        pista.descricao = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        pista.encontrada = sqlite3_column_int(stmt, 3) == 1;

        pistas.push_back(pista);
    }

    sqlite3_finalize(stmt);

    return pistas;
}

std::vector<Informacao> Database::verInformacoes() {
    sqlite3_stmt* stmt;
    std::vector<Informacao> infos;

    const char* sql = "SELECT id, titulo, descricao FROM informacoes ORDER BY id;";
    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    if (result != SQLITE_OK) {
        return infos;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Informacao info;
        info.id = sqlite3_column_int(stmt, 0);
        info.titulo = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        info.descricao = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
    
        infos.push_back(info);
    }

    sqlite3_finalize(stmt);

    return infos;
}
