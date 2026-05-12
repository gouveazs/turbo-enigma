INSERT OR IGNORE INTO vitima (id, nome, idade, estado_encontrada, causa_morte, horario_morte, observacoes)
VALUES
    (1, 'Laura Silva', 17, 'Encontrada atrás da escola com marcas no pescoço.', 'Asfixia.', '8:44 da manhã', 'Encontrada doses de cocaína e LSD em seu sangue.');

INSERT OR IGNORE INTO cena_crime (id, local, descricao, horario_estimado, clima)
VALUES
    (1, 'Fundos da escola.', 'Local atrás da quadra da escola, cercado por árvores. Há pegadas em volta de onde a vitima foi encontrada.', '10:35 da manhã', 'Umido pois choveu no dia passado.');

INSERT OR IGNORE INTO suspeitos (id, nome, idade, relacao_vitima, descricao, possivel_motivo, alibe, culpa)
VALUES
    (1, 'Isabela Camaro', 16, 'Melhor amiga da vítima.', 'Cabelos castanhos bagunçados, olheras e pupílas dilatadas.', 'Invejava beleza da amiga.', 'Diz estar na aula no horário do crime.', 0),
    (2, 'Alexandre Magno', 18, 'Ex-namorado da vítima.', 'Cabelo corte social, dentes amarelados e olhar cansado.', 'Descobrimento de uma traição por parte da vítima.', 'Diz estar em casa no dia do crime.', 0),
    (3, 'Murilo Paiva', 17, 'Namorado atual da vítima.', 'Cabelos longos, nariz escorrendo e dentes amarelados.', 'Sem motivos aparentes.', 'Diz estar na aula no horário do crime.', 1);
    
INSERT OR IGNORE INTO pistas (id, nome, descricao, encontrada)
VALUES
    (1, 'Pista 1', 'Um maço de cigarro foi encontrado na cena do crime.', 0),
    (2, 'Pista 2', 'Murilo possui marcas de arranhão no rosto e no pescoço.', 0),
    (3, 'Pista 3', 'Os sapatos de Alexandre estão sujos de terra.', 0);

INSERT OR IGNORE INTO informacoes (id, titulo, descricao)
VALUES
    (1, 'Informação 1', 'De acordo com a escola não há registros de que Isabela foi para aula no dia do crime.'),
    (2, 'Informação 2', 'Laura sempre se encontrava com seus namorados nos fundos da escola no começo da manhã.'),
    (3, 'Informação 3', 'Laura e seu atual namorado viviam discutindo muito recentemente.'),
    (4, 'Informação 4', 'Pessoas dizem ter ouvido uma discussão entre oque parecia uma mulher e um homem nos fundos da escola perto do horário do crime.');
