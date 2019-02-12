--REVOKE ALL ON DATABASE rock_in_rio FROM organizador,plateia; REVOKE ALL ON SCHEMA Palcos FROM organizador,plateia; REVOKE ALL ON SEQUENCE Palco_cod_seq,Banda_cod_seq FROM organizador,plateia; DROP ROLE jose,joao; DROP ROLE organizador,plateia;
--DROP DATABASE rock_in_rio cascade
CREATE ROLE organizador WITH NOSUPERUSER CREATEDB CREATEROLE INHERIT NOLOGIN NOREPLICATION CONNECTION LIMIT -1;   --grupo de organizadores
CREATE ROLE plateia WITH NOSUPERUSER NOCREATEDB NOCREATEROLE INHERIT NOLOGIN NOREPLICATION CONNECTION LIMIT -1;  --grupo dos participantes da plateia
GRANT CONNECT ON DATABASE rock_in_rio TO organizador,plateia;
GRANT USAGE ON SCHEMA Palcos TO organizador,plateia;

GRANT SELECT (cod,nome,genero) ON Banda TO plateia;
GRANT SELECT ON Toca_em, Artista,Hotel TO plateia;
REVOKE INSERT, DELETE, UPDATE ON Banda, Toca_em,Artista,Hotel FROM plateia;
GRANT SELECT,INSERT,DELETE,UPDATE ON Banda, Toca_em, Artista, Hotel TO organizador;

GRANT SELECT ON SEQUENCE Banda_cod_seq TO plateia;
GRANT ALL ON SEQUENCE    Banda_cod_seq TO organizador;

CREATE ROLE joao    WITH LOGIN ENCRYPTED PASSWORD '123' ;
CREATE ROLE jose    WITH LOGIN ENCRYPTED PASSWORD '123';

GRANT plateia TO joao;
GRANT organizador TO jose;
