INSERT OR IGNORE INTO vitima (id, nome, idade, estado_encontrada, causa_morte, observacoes)
VALUES
    (1, 'Isabela Vale', 24, 'Encontrada deitada sobre folhas secas, com as maos cruzadas sobre o peito e marcas de lama no vestido.', 'Ainda nao confirmada pelo legista.', 'Nao havia sinais claros de luta no local, mas a posicao do corpo parecia encenada.');

INSERT OR IGNORE INTO cena_crime (id, local, descricao, horario_estimado, clima)
VALUES
    (1, 'Mata atras da antiga Casa das Folhas', 'Uma clareira pequena cercada por arvores altas. O corpo estava no centro, perto de um vaso quebrado e marcas de pegadas.', 'Entre 22:00 e 00:30', 'Noite fria, chao umido depois de chuva.');

INSERT OR IGNORE INTO suspeitos (id, nome, descricao, motivo, alibi, culpa)
VALUES
    (1, 'Carlos', 'Jardineiro da casa.', 'Foi demitido uma semana antes.', 'Diz que estava no mercado.', 1),
    (2, 'Helena', 'Irma da vitima.', 'Disputava a heranca da familia.', 'Diz que estava lendo na biblioteca.', 0),
    (3, 'Marcos', 'Vizinho curioso.', 'Queria comprar a propriedade.', 'Diz que estava dormindo.', 0);

INSERT OR IGNORE INTO pistas (id, nome, descricao, encontrada)
VALUES
    (1, 'Pegadas no jardim', 'Pegadas com lama levam ate a porta dos fundos.', 0),
    (2, 'Carta rasgada', 'Uma carta menciona uma ameaca feita dias antes.', 0),
    (3, 'Chave escondida', 'Uma chave foi encontrada dentro de um vaso quebrado.', 0);

INSERT OR IGNORE INTO informacoes (id, titulo, descricao)
VALUES
    (1, 'Nome do caso', 'Casa das Folhas'),
    (2, 'Resumo', 'Uma jovem foi encontrada morta em uma clareira atras da casa da familia. A cena parece ter sido montada para confundir a investigacao.'),
    (3, 'Objetivo', 'Descobrir quem matou Isabela Vale usando pistas, depoimentos e contradicoes.');
