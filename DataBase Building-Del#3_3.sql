DROP DATABASE IF EXISTS rummykub;
CREATE DATABASE rummykub;

USE rummykub;

-- Tabla de jugadores
CREATE TABLE jugadors (
    id_jugador INT AUTO_INCREMENT PRIMARY KEY,
    nom VARCHAR(50),
    edat INT,
    nacionalitat VARCHAR(50),
    punts_totals INT
);

-- Tabla de partidas
CREATE TABLE partides (
    id_partida INT AUTO_INCREMENT PRIMARY KEY,
    record_punts INT,
    punts_totals_partida INT 
);

-- Tabla de relación entre jugadores y partidas
CREATE TABLE jugador_partida (
    id_jugador INT,   -- Foreign key a jugadors
    id_partida INT,   -- Foreign key a partides
    punts INT,        -- Puntos obtenidos en la partida
    PRIMARY KEY (id_jugador, id_partida), -- Clave primaria compuesta
    FOREIGN KEY (id_jugador) REFERENCES jugadors(id_jugador) ON DELETE CASCADE,
    FOREIGN KEY (id_partida) REFERENCES partides(id_partida) ON DELETE CASCADE
);

-- Insertar jugadores
INSERT INTO jugadors (nom, edat, nacionalitat, punts_totals) 
VALUES 
    ('Raúl', 20, 'Espanyol', 1200),
    ('Claudia', 20, 'Espanyola', 950),
    ('Laura', 19, 'Francesa', 800);

-- Insertar partidas
INSERT INTO partides (record_punts, punts_totals_partida)  
VALUES 
    (681, 1257), 
    (250, 300);

-- Insertar relación jugadores-partidas
INSERT INTO jugador_partida (id_jugador, id_partida, punts) 
VALUES 
    (1, 1, 120),  -- Raúl jugó en la partida 1 y obtuvo 120 puntos
    (2, 1, 251),  -- Claudia jugó en la partida 1 y obtuvo 251 puntos
    (3, 2, 300);  -- Laura jugó en la partida 2 y obtuvo 300 puntos

