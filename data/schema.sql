CREATE TABLE IF NOT EXISTS vitima (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    nome TEXT NOT NULL,
    idade INTEGER NOT NULL,
    estado_encontrada TEXT NOT NULL,
    causa_morte TEXT,
    horario_morte TEXT,
    observacoes TEXT
);

CREATE TABLE IF NOT EXISTS cena_crime (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    local TEXT NOT NULL,
    descricao TEXT NOT NULL,
    horario_estimado TEXT,
    clima TEXT
);

CREATE TABLE IF NOT EXISTS suspeitos (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    nome TEXT NOT NULL,
    idade INTEGER,
    relacao_vitima TEXT,
    descricao TEXT,
    possivel_motivo TEXT,
    alibe TEXT,
    culpa INTEGER NOT NULL DEFAULT 0 CHECK (culpa IN (0, 1))
);

CREATE TABLE IF NOT EXISTS pistas (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    nome TEXT NOT NULL,
    descricao TEXT NOT NULL,
    encontrada INTEGER NOT NULL DEFAULT 0 CHECK (encontrada IN (0, 1))
);

CREATE TABLE IF NOT EXISTS informacoes (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    titulo TEXT NOT NULL,
    descricao TEXT NOT NULL
);
