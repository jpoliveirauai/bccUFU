--DROP SCHEMA Palcos cascade;
--REVOKE CONNECT ON DATABASE rock_in_rio FROM organizador,plateia;DROP ROLE jose,joao, organizador,plateia;
--CREATE DATABASE rock_in_rio
CREATE SCHEMA Palcos;
SET search_path to Palcos;

CREATE TABLE Patrocinador(
	cod					integer,
	nome					varchar(40),
	CONSTRAINT patrocinador_pk PRIMARY KEY (cod)
);

CREATE TABLE Edicao(
	arrecadacao				numeric(20,2),
	ano					numeric(4,0) CHECK (ano > 0),
	n_pessoas				int CHECK (n_pessoas > 0),
	CONSTRAINT edicao_pk PRIMARY KEY (ano)
);

CREATE TABLE Midia(
	nome					varchar(40),
	tipo					varchar(10) check(
							tipo = 'DVD' OR
							tipo = 'CD'
						),
	CONSTRAINT midia_pk PRIMARY KEY (nome,tipo)
);


CREATE TABLE Hotel (
	nome					varchar(40),
	endereco				varchar(120),
	telefone				varchar(15),
	CONSTRAINT hotel_pk PRIMARY KEY (telefone)
);

CREATE TABLE Banda(
	cod					serial	   ,
	nome					varchar(40),
	genero					varchar(33),
	hotel					varchar(15),
	CONSTRAINT fk_banda FOREIGN KEY (hotel) REFERENCES hotel(telefone),
	CONSTRAINT banda_pk PRIMARY KEY (cod),
	CONSTRAINT generos CHECK (
		UPPER(genero) = 'Heavy Metal' OR 
		UPPER(genero) = 'MPB' OR 
		UPPER(genero) = 'JAZZ' OR 
		UPPER(genero) = 'POP' OR 
		UPPER(genero) = 'ROCK' OR
		UPPER(genero) = 'WORLD'
	)
);




CREATE TABLE Funcionario(
	cpf						varchar(11),
	nome					varchar(40),
	sexo					char,
	tipoEmpregado			varchar(120),
	funcaoVoluntario		varchar(120),
	CONSTRAINT funcionario_pk	PRIMARY KEY (cpf)
);



CREATE TABLE Palco(
	nome_palco			varchar(40),
	cod					serial,
	responsavel			varchar(11) NOT NULL,
	CONSTRAINT pk_palco PRIMARY KEY (cod),
	CONSTRAINT fk_palco FOREIGN KEY (responsavel) REFERENCES Funcionario(cpf)
);


CREATE TABLE Equipamento(
	n_serie					varchar(30),
	nome					varchar(40),
	tipo					varchar(20) 
	CONSTRAINT equipamentos CHECK (
		UPPER(tipo) = 'EFEITO ESPECIAL' OR
		UPPER(tipo) = 'ILUMINACAO' OR
		UPPER(tipo) = 'SOM' OR
		UPPER(tipo) = 'CONTROLE'
	),
	CONSTRAINT equipamento_pk PRIMARY KEY (n_serie)
);


CREATE TABLE Instrumento(
	n_serie					varchar(30),
	nome_instrumento			varchar(40),
	tipo					varchar(20),
	CONSTRAINT Instrumento_pk PRIMARY KEY (n_serie)
);

CREATE TABLE Artista(
	nome					varchar(40),
	nacionalidade				varchar(20),
	CONSTRAINT artista_pk PRIMARY KEY (nome)
);

CREATE TABLE Apresentacao(
	apresentador			integer,
	cod_palco 				integer,
	dat_hr_inicio			timestamp,
	dat_hr_fim				timestamp,
	ano 					numeric(4,0) CHECK (ano > 0),
	CONSTRAINT apresentacao_fk  FOREIGN KEY (apresentador) REFERENCES Banda(cod),
	CONSTRAINT apresentacao_fk1 FOREIGN KEY (cod_palco) REFERENCES Palco(cod),
	CONSTRAINT apresentacao_pk  PRIMARY KEY (apresentador,cod_palco,dat_hr_inicio),
	CONSTRAINT ed_fk	    FOREIGN KEY (ano) REFERENCES Edicao(ano)
);



CREATE TABLE Patrocina(
	patroc					integer,
	edicao					NUMERIC(4,0),
	contribuicao				numeric(10,2) CHECK (contribuicao > 0),
	CONSTRAINT fk_patr	 	FOREIGN KEY (patroc) REFERENCES patrocinador(cod),
	CONSTRAINT fk_edicao		FOREIGN KEY (edicao) REFERENCES edicao(ano),
	CONSTRAINT pk_patrocina 	PRIMARY KEY (patroc,edicao)	
);


CREATE TABLE Produz (
	midia					varchar(40),
	tipo					varchar(10),
	ano_ed					NUMERIC(4,0),
	CONSTRAINT fk_edicao FOREIGN KEY (ano_ed) REFERENCES edicao(ano),
	CONSTRAINT fk_tmidia FOREIGN KEY (tipo,midia) REFERENCES midia(tipo,nome),
	CONSTRAINT pk_produz PRIMARY KEY (midia,tipo,ano_ed)
);

CREATE TABLE Utiliza(
	banda					integer,
	equipamento 				varchar(30),
	CONSTRAINT utiliza_pk 	PRIMARY KEY (banda,equipamento),
	CONSTRAINT utiliza_fk	FOREIGN KEY (banda) 		REFERENCES Banda(cod),
	CONSTRAINT utiliza_fk1	FOREIGN KEY (equipamento) 	REFERENCES Equipamento(n_serie)
);

CREATE TABLE Toca_em(
	artista 			varchar(40),
	banda				integer,
	CONSTRAINT toca_em_pk 	PRIMARY KEY (artista,banda),
	CONSTRAINT toca_em_fk	FOREIGN KEY (artista) 	REFERENCES Artista(nome),
	CONSTRAINT toca_em_fk1	FOREIGN KEY (banda) 	REFERENCES Banda(cod)
);

CREATE TABLE Toca (
	artista			varchar(40),
	insts 			varchar(30),
	CONSTRAINT toca_pk 	PRIMARY KEY (artista,insts),
	CONSTRAINT toca_fk	FOREIGN KEY (artista) 	REFERENCES Artista(nome),
	CONSTRAINT toca_fk1	FOREIGN KEY (insts) 	REFERENCES instrumento(n_serie)
);

CREATE TABLE Trabalha(
	palco				integer,
	cpf 				varchar(11),
	CONSTRAINT trabalha_pk 	PRIMARY KEY (palco,cpf),
	CONSTRAINT trabalha_fk 	FOREIGN KEY (palco) REFERENCES palco(cod),
	CONSTRAINT trabalha_fk1	FOREIGN KEY (cpf) REFERENCES funcionario(cpf)
);
CREATE OR REPLACE FUNCTION contaResp() RETURNS TRIGGER AS
$$
DECLARE nResp int;
BEGIN
	SELECT COUNT(*) INTO nResp FROM Palco p WHERE p.responsavel = new.responsavel;
	IF nResp = 0 THEN
		RETURN NEW;
	ELSE
		RAISE EXCEPTION 'O funcionario com CPF % ja esta cuidando de um palco',new.responsavel
			USING HINT = 'Selecione outro funcionario para ser gerente do palco';
	END IF;
END $$ LANGUAGE 'plpgsql';

CREATE TRIGGER contaResponsavel BEFORE INSERT OR UPDATE ON Palco
FOR EACH ROW EXECUTE PROCEDURE contaResp();


CREATE FUNCTION selHotel() RETURNS TRIGGER AS 
$$
DECLARE T HOTEL.telefone%TYPE;
BEGIN
	SELECT telefone INTO T FROM Hotel ORDER BY random() LIMIT 1;
	NEW.Hotel := T;
	
	RETURN 	NEW;
END $$ LANGUAGE 'plpgsql';

CREATE TRIGGER compHotel BEFORE INSERT ON Banda 
FOR EACH ROW EXECUTE PROCEDURE selHotel();

--DROP FUNCTION geraReceitaAte(IN anoData int)
--insert into Banda values(1,'Aerosmith','ROCK','123');
CREATE OR REPLACE FUNCTION geraReceitaAte(IN anoData int) RETURNS INT AS $$
DECLARE	contrib INT;
DECLARE arrecada INT;
BEGIN
	contrib := 0;
	arrecada  := 0;
	SELECT SUM(contribuicao)
	INTO contrib
	FROM patrocina pat
	WHERE pat.edicao<anoData;

	SELECT SUM(arrecadacao)
	INTO arrecada
	FROM Edicao e
	WHERE e.ano<anoData;
	
	RETURN contrib + arrecada;
END $$ LANGUAGE 'plpgsql';

set search_path to palcos;
insert into Hotel values ('Plaza Hotel','Rua das Alamedas',	'2132322090');
insert into Hotel values ('Hotel Roma','Rua Nova Esperanca',	'2132152880');
insert into Hotel values ('Everest Rio','Praia de Ipanema',	'2132168000');
insert into Hotel values('Arena Copacabana','Avenida Atlantica','2132339191');
insert into Hotel values ('Windsor Leme','Rua Leme',		'2132106528');
insert into Hotel values ('Rio Design EX','Praia de Copacabana','2132212320');
insert into Hotel values ('Vila Gale','Centro',			'2132171988');
insert into Hotel values ('Ritz Plaza','Leblon',		'2132218762');
insert into Hotel values ('Fasana RJ','Arpoador',		'2132772382');
insert into Hotel values ('Mar Ipanema','Praia de Ipanema',	'2132187732');
--arrecadao, ano, n_pessoas
insert into Edicao values ('13000000.00',2008,65000); -- considerando o preco do ingresso 200.00
insert into Edicao values ('20000000.00',2009,100000); -- considerando o preco do ingresso 200.00
insert into Edicao values ('39000000.00',2010,156000); -- considerando o preco do ingresso 250.00
insert into Edicao values ('42000000.00',2011,168000);	-- considerando o preco do ingresso 250.00
insert into Edicao values ('46620000.00',2012,186480); -- considerando o preco do ingresso 250.00
insert into Edicao values ('38534000.00',2013,154136); -- considerando o preco do ingresso 250.00
insert into Edicao values ('51020333.00',2014,170068); -- considerando o preco do ingresso 300.00
insert into Edicao values ('50000000.00',2015,166667); -- considerando o preco do ingresso 300.00
insert into Edicao values ('49500000.00',2016,165000); -- considerando o preco do ingresso 300.00
insert into Edicao values ('67000000.00',2017,191429); -- considerando o preco do ingresso 350.00
--nome , tipo
insert into Midia values ('Rock in Rio 2008','CD');
insert into Midia values ('Rock in Rio 2009','CD');
insert into Midia values ('Rock in Rio 2010','CD');
insert into Midia values ('Rock in Rio 2011','DVD');
insert into Midia values ('Rock in Rio 2012','DVD');
insert into Midia values ('Rock in Rio 2013','DVD');
insert into Midia values ('Rock in Rio 2014','DVD');
insert into Midia values ('Rock in Rio 2015','DVD');
insert into Midia values ('Rock in Rio 2016','DVD');
insert into Midia values ('Rock in Rio 2017','DVD');
--cpf ,nome , sexo, funcao, palco
insert into Funcionario values ('11111111111','Marcos Paulo'  ,'M','Gerente',null);
insert into Funcionario values ('22222222222','Gabriela'      ,'F','Gerente',null);
insert into Funcionario values ('33333333333','Ana'           ,'F','Apresentador',null);
insert into Funcionario values ('44444444443','Fabricio'      ,'M','Apresentador',null);
insert into Funcionario values ('44444444444','Lucas'         ,'M','Gerente',null);
insert into Funcionario values ('55555555555','Firmino'	      ,'M','Gerente',null);
insert into Funcionario values ('55555555556','Joao Agostinho','M','Montador',null);
insert into Funcionario values ('66666666666','Alvaro'        ,'M','Voluntario','Montador');
insert into Funcionario values ('77777777777','Jessica'       ,'F','Voluntario','Montador');
insert into Funcionario values ('88888888888','Pedro'         ,'M','Voluntario','Montador');
insert into Funcionario values ('99999999999','Marcelo'       ,'M','Montador',null);
insert into Funcionario values ('10110111010','Karine'        ,'F','Voluntario','Montador');
insert into Funcionario values ('00000000000','Leonardo'      ,'M','Voluntario','Gerente');
insert into Funcionario values ('11111222223','Daniela'       ,'F','Gerente',null);
insert into Funcionario values ('11111111333','Wagner'        ,'F','Gerente',null);
insert into Funcionario values ('54545454545','Lucio'         ,'M','Apresentador',null);
insert into Funcionario values ('54525454545','Luciano'       ,'M','Gerente',null);
insert into Funcionario values ('32132189899','Pamela'        ,'F','Voluntario','Apresentador');
insert into Funcionario values ('01234567890','Andreia'       ,'F','Voluntario','Apresentador');
--nome_palco,cod,responsavel
SELECT setval('palco_cod_seq', 1);
insert into Palco values ('Mundo',		currval('Palco_cod_seq'),'11111111111');
insert into Palco values ('Sunset',		nextval('Palco_cod_seq'),'22222222222');
insert into Palco values ('Rock Street',	nextval('Palco_cod_seq'),'11111222223');
insert into Palco values ('Digital Stage',	nextval('Palco_cod_seq'),'44444444444');
insert into Palco values ('Rock District',	nextval('Palco_cod_seq'),'55555555555');
insert into Palco values ('Street Dance',	nextval('Palco_cod_seq'),'00000000000');
insert into Palco values ('Eletronica',		nextval('Palco_cod_seq'),'54525454545');
--ALTER SEQUENCE banda_cod_seq RESTART WITH 1;
SELECT setval('banda_cod_seq',1);
insert into Banda values(currval('Banda_cod_seq'),'Aerosmith','ROCK',			'2132322090');
insert into Banda values(nextval('Banda_cod_seq'),'Bon Jovi','ROCK',			'2132152880');
insert into Banda values(nextval('Banda_cod_seq'),'Red Hot Chili Peppers','ROCK',	'2132168000');
insert into Banda values(nextval('Banda_cod_seq'),'Thirty Seconds to Mars','ROCK',	'2132339191');
insert into Banda values(nextval('Banda_cod_seq'),'Capital Incial','ROCK',		'2132106528');
insert into Banda values(nextval('Banda_cod_seq'),'The Offspring','ROCK',		'2132212320');
insert into Banda values(nextval('Banda_cod_seq'),'Maroon 5','POP',			'2132171988');
insert into Banda values(nextval('Banda_cod_seq'),'Frejat','MPB',			'2132218762');
insert into Banda values(nextval('Banda_cod_seq'),'Fall Out Boy','POP',			'2132772382');
insert into Banda values(nextval('Banda_cod_seq'),'Skank','POP',			'2132187732');
insert into Banda values(nextval('Banda_cod_seq'),'Foo Fighters','POP',				'Wie');
insert into Banda values(nextval('Banda_cod_seq'),'Slipknot','ROCK',				'FasRJ');
insert into Banda values(nextval('Banda_cod_seq'),'Coldplay','ROCK',				'Mara');
insert into Banda values(nextval('Banda_cod_seq'),'System of a down','ROCK',		'132');
insert into Banda values(nextval('Banda_cod_seq'),'Metallica','ROCK',				'123');
insert into Banda values(nextval('Banda_cod_seq'),'Avenged Sevenfold','POP',		'Platel');
insert into Banda values(nextval('Banda_cod_seq'),'AC/DC','ROCK',					'Plaza Hotel');
insert into Banda values(nextval('Banda_cod_seq'),'Paralamas do Sucesso','ROCK',	'Hotel Roma');
insert into Banda values(nextval('Banda_cod_seq'),'Iron Maiden','ROCK',				'io');
insert into Banda values(nextval('Banda_cod_seq'),'Ozzy Osbourne','ROCK',			'acabana');
insert into Banda values(nextval('Banda_cod_seq'),'Barao Vermelho','POP',			'eme');
insert into Banda values(nextval('Banda_cod_seq'),'Queen','POP',					'n EX');
insert into Banda values(nextval('Banda_cod_seq'),'Scorpions','Rock',				'');
insert into Banda values(nextval('Banda_cod_seq'),'Yes','Rock',						'a');
insert into Banda values(nextval('Banda_cod_seq'),'Guns N Roses','Rock',			'el');
insert into Banda values(nextval('Banda_cod_seq'),'Faith No More','MPB',			'a');
insert into Banda values(nextval('Banda_cod_seq'),'Sepultura','MPB',				'io');
insert into Banda values(nextval('Banda_cod_seq'),'Happy Mondays','POP',			'acabana');
insert into Banda values(nextval('Banda_cod_seq'),'Titas','POP',					'eme');
insert into Banda values(nextval('Banda_cod_seq'),'Judas Priest','MPB',				'');
insert into Banda values(nextval('Banda_cod_seq'),'Megadeth','ROCK',				'ma');
insert into Banda values(nextval('Banda_cod_seq'),'Engenheiros do Hawaii','ROCK',	'');
insert into Banda values(nextval('Banda_cod_seq'),'Rob Halford','ROCK',				'n EX');
insert into Banda values(nextval('Banda_cod_seq'),'Papa Roach','ROCK',				'io');
insert into Banda values(nextval('Banda_cod_seq'),'Oasis','MPB',					'a');


--n_serie , nome , tipo
insert into Equipamento values('12345','Amplificador','SOM');
insert into Equipamento values('67890','Microfone','SOM');
insert into Equipamento values('00345','Mesa de Mixagem','EFEITO ESPECIAL');
insert into Equipamento values('76531','Refletores','ILUMINACAO');
insert into Equipamento values('78653','Equalizador','SOM');
insert into Equipamento values('42014','Compressores','SOM');
insert into Equipamento values('89761','Central de Controle','CONTROLE');
insert into Equipamento values('56321','Canhao de Luz','ILUMINACAO');
insert into Equipamento values('33451','Caixas Acusticas Laterais','SOM');
insert into Equipamento values('24321','Mesa de Monitor','CONTROLE');
--cod,nome_instrumento,tipo
insert into Instrumento values('1','Guitarra','Corda');
insert into Instrumento values('2','Bateria','percussao');
insert into Instrumento values('3','Contrabaixo','Corda');
insert into Instrumento values('4','Violao','Corda');
insert into Instrumento values('5','Teclado','Eletrico');
insert into Instrumento values('6','Pedal','Acessorio');
insert into Instrumento values('7','Violoncelo','Corda');
insert into Instrumento values('8','Sino','Percussao');
insert into Instrumento values('9','Bata','Percussao');
insert into Instrumento values('10','Saxofone','Sopro');

--apresentador(banda que vai se apresentar) , cod_palco,data_hr_inicio,data_hr_fim
insert into Apresentacao values(11,2,'2017-12-06 20:00','2017-12-06 21:00',2017);
insert into Apresentacao values(1,1,'2017-12-06 20:00','2017-12-06 21:00',2017);
insert into Apresentacao values(2,2,'2017-12-06 20:00','2017-12-06 21:00',2017);
insert into Apresentacao values(3,3,'2017-12-06 21:15','2017-12-06 22:15',2017);
insert into Apresentacao values(4,4,'2009-12-06 22:30','2009-12-06 23:30',2009);
insert into Apresentacao values(5,5,'2009-12-06 23:45','2009-12-07 01:00',2009);
insert into Apresentacao values(6,1,'2009-12-07 20:00','2009-12-06 21:00',2009);
insert into Apresentacao values(7,2,'2016-12-07 20:00','2016-12-06 21:00',2016);
insert into Apresentacao values(8,3,'2016-12-07 21:15','2016-12-06 22:15',2016);
insert into Apresentacao values(9,4,'2017-12-07 22:15','2017-12-06 23:15',2017);
insert into Apresentacao values(10,5,'2017-12-07 23:45','2017-12-08 01:30',2017);
insert into Apresentacao values(11,1,'2010-12-06 20:00','2010-12-06 21:00',2010);
insert into Apresentacao values(12,2,'2014-12-06 20:00','2014-12-06 21:00',2014);
insert into Apresentacao values(13,3,'2010-12-06 21:15','2010-12-06 22:15',2010);
insert into Apresentacao values(14,4,'2010-12-06 22:30','2010-12-06 23:30',2010);
insert into Apresentacao values(15,5,'2010-12-06 23:45','2010-12-07 01:00',2010);
insert into Apresentacao values(16,1,'2008-12-07 20:00','2008-12-06 21:00',2008);
insert into Apresentacao values(17,2,'2008-12-07 20:00','2008-12-06 21:00',2008);
insert into Apresentacao values(18,3,'2008-12-07 21:15','2008-12-06 22:15',2008);
insert into Apresentacao values(19,1,'2011-12-06 20:00','2011-12-06 21:00',2011);
insert into Apresentacao values(20,2,'2011-12-06 20:00','2011-12-06 21:00',2011);
insert into Apresentacao values(21,3,'2011-12-06 21:15','2011-12-06 22:15',2011);
insert into Apresentacao values(22,4,'2011-12-06 22:30','2011-12-06 23:30',2011);
insert into Apresentacao values(23,5,'2011-12-06 23:45','2011-12-07 01:00',2011);
insert into Apresentacao values(24,1,'2011-12-07 20:00','2011-12-06 21:00',2011);
insert into Apresentacao values(25,2,'2011-12-07 20:00','2011-12-06 21:00',2011);
insert into Apresentacao values(26,3,'2015-12-07 21:15','2015-12-06 22:15',2015);
insert into Apresentacao values(27,1,'2012-12-06 20:00','2012-12-06 21:00',2015);
insert into Apresentacao values(21,2,'2014-12-06 20:00','2014-12-06 21:00',2014);
insert into Apresentacao values(28,3,'2014-12-06 21:15','2014-12-06 22:15',2014);
insert into Apresentacao values(29,4,'2014-12-06 22:30','2014-12-06 23:30',2014);
insert into Apresentacao values(30,5,'2012-12-06 23:45','2012-12-07 01:00',2012);
insert into Apresentacao values(31,1,'2012-12-07 20:00','2012-12-06 21:00',2012);
insert into Apresentacao values(32,2,'2012-12-07 20:00','2012-12-06 21:00',2012);
insert into Apresentacao values(33,1,'2013-12-06 20:00','2013-12-06 21:00',2013);
insert into Apresentacao values(34,2,'2013-12-06 20:00','2013-12-06 21:00',2013);
insert into Apresentacao values(35,3,'2013-12-06 21:15','2013-12-06 22:15',2013);
insert into Apresentacao values(27,3,'2014-12-06 21:15','2014-12-06 22:15',2014);
insert into Apresentacao values(15,1,'2015-12-06 20:00','2015-12-06 21:00',2015);
insert into Apresentacao values(33,4,'2015-12-06 22:30','2015-12-06 23:30',2015);
insert into Apresentacao values(20,5,'2015-12-06 23:45','2015-12-07 01:00',2015);
insert into Apresentacao values(19,3,'2016-12-06 21:15','2016-12-06 22:15',2016);
insert into Apresentacao values(11,5,'2016-12-06 23:45','2016-12-07 01:00',2016);


insert into Patrocinador values ('1','Itau');
insert into Patrocinador values ('2','Doritos');
insert into Patrocinador values ('3','Heineken');
insert into Patrocinador values ('4','Coca-Cola');
insert into Patrocinador values ('5','Globo');
insert into Patrocinador values ('6','Sky');
insert into Patrocinador values ('7','Bobs');
insert into Patrocinador values ('8','Chillibeans');
insert into Patrocinador values ('9','Visa');
insert into Patrocinador values ('10','Tinder');
--patroc , edicao
insert into Patrocina values(1,2008,1000000.00);
insert into Patrocina values(2,2008,200100.00);
insert into Patrocina values(6,2008,250000.00);
insert into Patrocina values(2,2009,203400.00);
insert into Patrocina values(9,2009,850000.00);
insert into Patrocina values(3,2010,800000.00);
insert into Patrocina values(4,2011,900000.00);
insert into Patrocina values(2,2011,810000.00);
insert into Patrocina values(7,2012,600000.00);
insert into Patrocina values(8,2012,1200000.00);
insert into Patrocina values(6,2010,270000.00);
insert into Patrocina values(1,2013,1200000.00);
insert into Patrocina values(3,2014,900000.00);
insert into Patrocina values(4,2016,950000.00);
insert into Patrocina values(5,2014,1200000.00);
insert into Patrocina values(7,2013,670000.00);
insert into Patrocina values(9,2015,880000.00);
insert into Patrocina values(8,2015,390000.00);
insert into Patrocina values(10,2014,1850000.00);
insert into Patrocina values(1,2015,1090000.00);
insert into Patrocina values(3,2017,600000.00);
insert into Patrocina values(7,2017,790000.00);
--midia , tipo , ano_ed
insert into Produz values('Rock in Rio 2008','CD',2008);
insert into Produz values('Rock in Rio 2009','CD',2009);
insert into Produz values('Rock in Rio 2010','CD',2010);
insert into Produz values('Rock in Rio 2011','DVD',2011);
insert into Produz values('Rock in Rio 2012','DVD',2012);
insert into Produz values('Rock in Rio 2013','DVD',2013);
insert into Produz values('Rock in Rio 2014','DVD',2014);
insert into Produz values('Rock in Rio 2015','DVD',2015);
insert into Produz values('Rock in Rio 2016','DVD',2016);
insert into Produz values('Rock in Rio 2017','DVD',2017);
--banda ,equipamento
insert into Utiliza values (1,'12345');
insert into Utiliza values (1,'67890');
insert into Utiliza values (1,'00345');
insert into Utiliza values (2,'12345');
insert into Utiliza values (2,'56321');
insert into Utiliza values (2,'00345');
insert into Utiliza values (2,'76531');
insert into Utiliza values (3,'12345');
insert into Utiliza values (3,'33451');
insert into Utiliza values (3,'76531');
insert into Utiliza values (3,'24321');
insert into Utiliza values (4,'56321');
insert into Utiliza values (4,'42014');
insert into Utiliza values (4,'12345');
insert into Utiliza values (5,'12345');
insert into Utiliza values (5,'67890');
insert into Utiliza values (5,'00345');
insert into Utiliza values (5,'76531');
insert into Utiliza values (5,'33451');
insert into Utiliza values (6,'00345');
insert into Utiliza values (6,'42014');
insert into Utiliza values (6,'24321');
insert into Utiliza values (7,'12345');
insert into Utiliza values (7,'67890');
insert into Utiliza values (7,'00345');
insert into Utiliza values (7,'24321');
insert into Utiliza values (7,'76531');
insert into Utiliza values (7,'42014');
insert into Utiliza values (8,'42014');
insert into Utiliza values (8,'12345');
insert into Utiliza values (9,'56321');
insert into Utiliza values (9,'42014');
insert into Utiliza values (9,'33451');
insert into Utiliza values (10,'33451');
insert into Utiliza values (10,'76531');
insert into Utiliza values (10,'42014');
insert into Utiliza values (10,'67890');
insert into Utiliza values (11,'12345');
insert into Utiliza values (11,'67890');
insert into Utiliza values (11,'00345');
insert into Utiliza values (11,'76531');
insert into Utiliza values (12,'12345');
insert into Utiliza values (12,'67890');
insert into Utiliza values (12,'00345');
insert into Utiliza values (13,'12345');
insert into Utiliza values (13,'56321');
insert into Utiliza values (13,'00345');
insert into Utiliza values (13,'76531');
insert into Utiliza values (14,'42014');
insert into Utiliza values (14,'12345');
insert into Utiliza values (15,'12345');
insert into Utiliza values (15,'67890');
insert into Utiliza values (15,'00345');
insert into Utiliza values (15,'24321');
insert into Utiliza values (15,'76531');
insert into Utiliza values (15,'42014');
insert into Utiliza values (16,'56321');
insert into Utiliza values (16,'42014');
insert into Utiliza values (16,'33451');
insert into Utiliza values (17,'56321');
insert into Utiliza values (17,'42014');
insert into Utiliza values (17,'12345');
insert into Utiliza values (18,'12345');
insert into Utiliza values (18,'33451');
insert into Utiliza values (18,'76531');
insert into Utiliza values (19,'12345');
insert into Utiliza values (19,'33451');
insert into Utiliza values (19,'76531');
insert into Utiliza values (19,'00345');
insert into Utiliza values (19,'42014');
insert into Utiliza values (19,'24321');
insert into Utiliza values (20,'42014');
insert into Utiliza values (20,'12345');
insert into Utiliza values (20,'67890');
insert into Utiliza values (21,'76531');
insert into Utiliza values (21,'42014');
insert into Utiliza values (21,'67890');
insert into Utiliza values (22,'76531');
insert into Utiliza values (22,'33451');
insert into Utiliza values (22,'67890');
insert into Utiliza values (23,'33451');
insert into Utiliza values (23,'76531');
insert into Utiliza values (23,'12345');
insert into Utiliza values (24,'33451');
insert into Utiliza values (24,'12345');
insert into Utiliza values (24,'67890');
insert into Utiliza values (24,'00345');
insert into Utiliza values (25,'42014');
insert into Utiliza values (25,'24321');
insert into Utiliza values (25,'33451');
insert into Utiliza values (25,'12345');
insert into Utiliza values (26,'24321');
insert into Utiliza values (26,'33451');
insert into Utiliza values (26,'67890');
insert into Utiliza values (27,'42014');
insert into Utiliza values (27,'24321');
insert into Utiliza values (27,'33451');
insert into Utiliza values (27,'67890');
insert into Utiliza values (28,'42014');
insert into Utiliza values (28,'24321');
insert into Utiliza values (28,'12345');
insert into Utiliza values (28,'56321');
insert into Utiliza values (28,'00345');
insert into Utiliza values (29,'12345');
insert into Utiliza values (29,'67890');
insert into Utiliza values (29,'00345');
insert into Utiliza values (29,'24321');
insert into Utiliza values (29,'76531');
insert into Utiliza values (29,'42014');
insert into Utiliza values (30,'12345');
insert into Utiliza values (30,'67890');
insert into Utiliza values (30,'76531');
insert into Utiliza values (30,'42014');
insert into Utiliza values (31,'76531');
insert into Utiliza values (31,'24321');
insert into Utiliza values (31,'56321');
insert into Utiliza values (31,'67890');
insert into Utiliza values (32,'12345');
insert into Utiliza values (32,'76531');
insert into Utiliza values (32,'24321');
insert into Utiliza values (32,'67890');
insert into Utiliza values (33,'12345');
insert into Utiliza values (33,'76531');
insert into Utiliza values (33,'24321');
insert into Utiliza values (34,'56321');
insert into Utiliza values (34,'42014');
insert into Utiliza values (34,'33451');
insert into Utiliza values (35,'12345');
insert into Utiliza values (35,'67890');
insert into Utiliza values (35,'00345');

--nome , nacionalidade
insert into Artista values ('Steven Tyler','Estadounidense'); --Aerosmith qlqr instrumento/vocal
insert into Artista values ('Tom Hamilton','Estadounidense'); --Aerosmith contrabaixo
insert into Artista values ('Samuel Rosa','Brasileiro'); -- Skank violao
insert into Artista values ('Henrique Portugal','Brasileiro'); -- Skank teclado
insert into Artista values ('Flea','Australiano'); -- Red Hot bateria
insert into Artista values ('Chad Smith','Estadounidense'); -- Red Hot  percussao
insert into Artista values ('Dinho Ouro Preto','Brasileiro'); --Capital Inicial /violao/guitarra
insert into Artista values ('Fe Lemos','Brasileiro'); --Capital Inicial / bateria
insert into Artista values ('Flavio Lemos','Brasileiro'); -- Capital Inicial /Contra-baixo
insert into Artista values ('Dexter Holland','Estadounidense'); --The Offspring Vocal
insert into Artista values ('Peter Parada','Estadounidense'); --The Offspring Guitarra
insert into Artista values ('Greg K.','Estadounidense'); --The Offspring Baixo
insert into Artista values ('Adam Levine','Estadounidense'); -- Maroon 5 / guitarra
insert into Artista values ('Patrick Stump','Italiano'); --Fall Out Boy /guitarrista
insert into Artista values ('Ben Rose','Japones'); -- Fall Out Boy / Baterista
insert into Artista values ('Kevin Drake','Holandes'); -- Thirty Seconds to Mars / Guitarra 
insert into Artista values ('Braxton Olita','Alemao'); -- Thirty Seconds to Mars / Contrabaixo
insert into Artista values ('Stephen Aiellio','Mexicano'); -- Thirty Seconds to Mars / Teclado
insert into Artista values ('Max Lover','Estadounidense'); -- Bon Jovi / Teclado
insert into Artista values ('Jovi','Frances'); -- Bon Jovi / Guitarra
insert into Artista values ('Dave Grohl','Estadounidense'); 
insert into Artista values ('Nate Mendel','Estadounidense'); --baixo
insert into Artista values ('Taylor Hawkins','Estadounidense'); --bateria
insert into Artista values ('Chris Shiflett','Estadounidense'); --guitarra
insert into Artista values ('Pat Smear','Estadounidense'); --guitarra
insert into Artista values ('James Root','Estadounidense'); --guitara
insert into Artista values ('Craig Jones','Estadounidense'); --teclado
insert into Artista values ('Mick Thomson','Estadounidense'); --guitarra
insert into Artista values ('Corey Taylor','Estadounidense'); 
insert into Artista values ('Jay Weinberg','Estadounidense'); --bateria
insert into Artista values ('Alessandro Venturella','Britanico'); --bateria
insert into Artista values ('Jesse Carmichael','Estadounidense'); --teclado
insert into Artista values ('Mickey Madden ','Estadounidense'); --baixo
insert into Artista values ('James Valentine','Estadounidense'); --guitarra
insert into Artista values ('Matt Flynn','Estadounidense'); --bateria
insert into Artista values ('PJ Morton','Estadounidense'); --teclado
insert into Artista values ('Guy Berryman','Escoces'); --baixo
insert into Artista values ('Jonny Buckland','Ingles'); --guitarra
insert into Artista values ('Will Champion','Ingles'); --bateria
insert into Artista values ('Serj Tankian','Estadounidense'); --teclado
insert into Artista values ('Daron Malakian','Armeno-Americano'); --guitarra
insert into Artista values ('Shavo Odadjian','Armeno-Americano'); --baixo
insert into Artista values ('Jonh Dolmayan','Armeno-Americano'); --bateria
insert into Artista values ('M Shadow','Estadounidense'); --vocal
insert into Artista values ('Zacky Vengeance','Dinamarques'); --guitarra
insert into Artista values ('Synyster Gate','Estadounidense'); --guitarra
insert into Artista values ('Johnny Christ','Estadounidense'); --baixo
insert into Artista values ('Brooks Wackerman','Estadounidense'); --bateria
insert into Artista values ('Jared Leto',7); --vocal
insert into Artista values ('Shannon Leto',2); --bateria
insert into Artista values ('Tomo Milicevic',1); --guitara
insert into Artista values ('Anthony Kiedis','Estadounidense'); --vocal
insert into Artista values ('Josh Klinghoffer','Estadounidense'); --guitarra
insert into Artista values ('Jon Bon Jovi','Estadounidense'); --vocal
insert into Artista values ('Phil X','Greco-Canadense'); --guitarra
insert into Artista values ('Hugh McDonald','Estadounidense'); --baixo
insert into Artista values ('Tico Torres','Cubano'); --bateria
insert into Artista values ('David Bryan','Estadounidense'); --teclado
insert into Artista values ('Thiago Castanho','Brasileiro'); --guitarra
insert into Artista values ('Yves Passarel','Brasileiro'); --violao
insert into Artista values ('James Hetfield','Estadounidense'); --vocal
insert into Artista values ('Lars Ulrich','Dinamarques'); --bateria
insert into Artista values ('Kirk Hammett','Estadounidense'); --guitarra
insert into Artista values ('Robert Trujillo','Estadounidense'); --baixo
insert into Artista values ('Liam Gallagher','Britanico'); --vocal
insert into Artista values ('Noel Gallagher','Britanico'); --guitarra
insert into Artista values ('Gem Archer','Ingles'); --guitarra
insert into Artista values ('Andy Bell','Britanico'); --baixo
insert into Artista values ('Chris Sharrock','Britanico'); --bateria
insert into Artista values ('Shaun Ryder','Britanico'); --vocalista/guitarra
insert into Artista values ('Paul Ryder','Estdanounidense'); --baixista
insert into Artista values ('Paul Davis','Estadounidense'); --teclado
insert into Artista values ('Gary Whelan','Ingles'); --baterista
insert into Artista values ('Branco Mello','Brasileiro'); --baixo
insert into Artista values ('Sergio Britto','Brasileiro'); --teclado
insert into Artista values ('Tony Belloto','Brasileiro'); --violao
insert into Artista values ('Ian Hill','Ingles'); --baixo
insert into Artista values ('Rob Halford','Ingles'); --vocal
insert into Artista values ('Glen Tipton','Ingles'); --guitarra
insert into Artista values ('Scott Travis','Estadunidense'); --bateria
insert into Artista values ('Rich Faulkner','Britanico'); --guitarra
insert into Artista values ('Dave Mustaine','Ingles'); --vocal
insert into Artista values ('David Ellefson','Estadounidense'); --baixo
insert into Artista values ('Kiko Loureiro','Brasileiro'); --guitarra
insert into Artista values ('Dirk Verbeuren','Belga'); --bateria
insert into Artista values ('Humberto Gessinger','Brasileiro'); --vocal
insert into Artista values ('Glaucio Ayala','Brasileiro'); --bateria
insert into Artista values ('Fernando Aranha','Brasileiro'); --guitarra
insert into Artista values ('Pedro Augusto','Brasileiro'); --teclado
insert into Artista values ('Steve Harris','Ingles'); --baixo
insert into Artista values ('Adrian Smith','Britanico'); --guitarra
insert into Artista values ('Bruce Dickinson','Britanico'); --vocal
insert into Artista values ('Janick Gers','Ingles'); -- guitarra
insert into Artista values ('Jacoby Shaddix','Estadounidense'); --vocal
insert into Artista values ('Jerry Horton','Estadounidense'); --guitarra
insert into Artista values ('Tobin Esperance','Estadounidense'); --baixo
insert into Artista values ('Tony Palermo','Estadounidense'); --bateria
insert into Artista values ('Cazuza','Brasileiro'); --Vocal
insert into Artista values ('Guto Goffi','Brasileiro'); --baterista
insert into Artista values ('Roberto Frejat','Brasileiro'); --guitarrista
insert into Artista values ('De','Brasileiro'); --baixo
insert into Artista values ('Mauricio Barros','Brasileiro'); --teclado
insert into Artista values ('Freddie Mercury','Ingles'); --Vocal
insert into Artista values ('Brian May','Ingles'); --guitarrista
insert into Artista values ('Rudolf Schenker','Alemao'); --guitarra
insert into Artista values ('Klaues Meine','Alemao'); --vocal
insert into Artista values ('Matthias Jab','Alemao'); --guitarra
insert into Artista values ('Pawel Maciwoda','Polones'); --baixo
insert into Artista values ('Mikkey Dee','Sueco'); --baterista
insert into Artista values ('Steve Howe','Ingles'); --guitarra
insert into Artista values ('Rick Wakeman','Ingles'); --vocal/teclado
insert into Artista values ('Jon Anderson','Britanico'); --guitarra
insert into Artista values ('Alan White','Ingles'); --baterista
insert into Artista values ('Axl Rose','Estadounidense'); --vocal/teclado
insert into Artista values ('Slash','Estadounidense'); --guitarrista
insert into Artista values ('DuffMcKagan','Estadounidense'); --guitarra
insert into Artista values ('Frank Ferrer','Estadounidense'); --baterista
insert into Artista values ('Melissa Reese','Estadounidense'); 
insert into Artista values ('Mike Patton','Estadounidense'); --vocal
insert into Artista values ('Billy Gould','Estadounidense'); --baixo
insert into Artista values ('Mike Bordin','Estadounidense'); --bateria
insert into Artista values ('Roddy Bottum','Estadounidense'); --teclado
insert into Artista values ('Jon Hudson','Estadounidense');  --guitarra
insert into Artista values ('Paulo Jr.','Brasileiro'); --baixo
insert into Artista values ('Andreas Kisser','Brasileiro'); --guitarra
insert into Artista values ('Derrick Green ','Estadounidense'); --vocal/percussao
insert into Artista values ('Eloy Casagrande','Brasileiro'); --bateria
insert into Artista values ('Dave Evans','Austrialano'); --Vocal
insert into Artista values ('Angus Young','Austrialano'); --guitarrista
insert into Artista values ('Stevie Young','Escoces'); --guitarrista
insert into Artista values ('Chris Slade','Gales'); --baterista
insert into Artista values ('Herbert Vianna','Brasileiro'); --Vocal e guitarra
insert into Artista values ('Bi Ribeiro','Brasileiro'); --Baixo
insert into Artista values ('Joao Barane','Brasileiro'); --Baterista
insert into Artista values ('Dave Murray','Britanico'); --guitarrista
insert into Artista values ('Nicko McBrain','Ingles'); --bateria
insert into Artista values ('Jacnick Gears','Ingles'); --guitarrista
insert into Artista values ('Ozzy Osbourne','Ingles'); --baixo
--arista,instrumento(codigo)
insert into Toca values ('Adam Levine',1); -- Maroon 5 / guitarra
insert into Toca values ('Adrian Smith',1);
insert into Toca values ('Alan White',2);
insert into Toca values ('Alessandro Venturella',3); --bateria
insert into Toca values ('Andreas Kisser',1);
insert into Toca values ('Andy Bell',3); --baixo
insert into Toca values ('Angus Young',1);
insert into Toca values ('Axl Rose',5);
insert into Toca values ('Ben Rose',2); -- Fall Out Boy / Baterista
insert into Toca values ('Bi Ribeiro',3);
insert into Toca values ('Billy Gould',3);
insert into Toca values ('Branco Mello',3);
insert into Toca values ('Braxton Olita',3); -- Thirty Seconds to Mars / Contrabaixo
insert into Toca values ('Brian May',1);
insert into Toca values ('Brooks Wackerman',2); --bateria
insert into Toca values ('Bruce Dickinson',10); --vocal
insert into Toca values ('Chad Smith',10); -- Red Hot  percussao
insert into Toca values ('Chris Sharrock',2); --bateria
insert into Toca values ('Chris Shiflett',1); --guitarra
insert into Toca values ('Chris Slade',2);
insert into Toca values ('Craig Jones',5); --teclado
insert into Toca values ('Dave Evans',9);
insert into Toca values ('Dave Murray',1); --guitarrista
insert into Toca values ('Dave Mustaine',9);
insert into Toca values ('David Bryan',5); --teclado
insert into Toca values ('David Ellefson',3);
insert into Toca values ('Dexter Holland',8); --The Offspring Vocal
insert into Toca values ('Dinho Ouro Preto',1); --vocal
insert into Toca values ('Dirk Verbeuren',2);
insert into Toca values ('DuffMcKagan',1);
insert into Toca values ('De',3);
insert into Toca values ('Eloy Casagrande',2);
insert into Toca values ('Fe Lemos',2); --guitarra
insert into Toca values ('Fernando Aranha',1);
insert into Toca values ('Flavio Lemos',1); --guitarra
insert into Toca values ('Flavio Lemos',5); -- Capital Inicial /Contra-baixo
insert into Toca values ('Flea',2); -- Red Hot bateria
insert into Toca values ('Frank Ferrer',2);
insert into Toca values ('Freddie Mercury',9);
insert into Toca values ('Gary Whelan',2);
insert into Toca values ('Gem Archer',1); --guitarra
insert into Toca values ('Glaucio Ayala',2);
insert into Toca values ('Glen Tipton',1);
insert into Toca values ('Greg K.',3); --The Offspring Baixo
insert into Toca values ('Guto Goffi',2);
insert into Toca values ('Guy Berryman',3); --baixo
insert into Toca values ('Henrique Portugal',5);
insert into Toca values ('Herbert Vianna',1);
insert into Toca values ('Hugh McDonald',3); --baixo
insert into Toca values ('Humberto Gessinger',4);
insert into Toca values ('Ian Hill',3);
insert into Toca values ('Jacnick Gears',1); --guitarrista
insert into Toca values ('Jacoby Shaddix',4); --vocal
insert into Toca values ('James Hetfield',8); --vocal
insert into Toca values ('James Root',1); --guitara
insert into Toca values ('James Valentine',1); --guitarra
insert into Toca values ('Jay Weinberg',2); --bateria
insert into Toca values ('Jerry Horton',1); --guitarra
insert into Toca values ('Jesse Carmichael',5); --teclado
insert into Toca values ('Johnny Christ',3); --baixo
insert into Toca values ('Jon Anderson',1);
insert into Toca values ('Jon Bon Jovi',4); --vocal
insert into Toca values ('Jon Hudson',1); 
insert into Toca values ('Jonh Dolmayan',2); 
insert into Toca values ('Jonny Buckland',1); --guitarra
insert into Toca values ('Jovi',1); -- Bon Jovi / Guitarra
insert into Toca values ('Joao Barane',2);
insert into Toca values ('Kevin Drake',1); -- Thirty Seconds to Mars / Guitarra 
insert into Toca values ('Kiko Loureiro',1);
insert into Toca values ('Kirk Hammett',1); --guitarra
insert into Toca values ('Klaues Meine',4);
insert into Toca values ('Lars Ulrich',2); --bateria
insert into Toca values ('Liam Gallagher',10); --vocal
insert into Toca values ('Matt Flynn',2); --bateria
insert into Toca values ('Matthias Jab',1);
insert into Toca values ('Mauricio Barros',5);
insert into Toca values ('Max Lover',5); -- Bon Jovi / Teclado
insert into Toca values ('Melissa Reese',7);
insert into Toca values ('Mick Thomson',1); --guitarra
insert into Toca values ('Mickey Madden ',3); --baixo
insert into Toca values ('Mike Bordin',2);
insert into Toca values ('Mike Patton',8);
insert into Toca values ('Mikkey Dee',2);
insert into Toca values ('Nate Mendel',3); --baixo
insert into Toca values ('Nicko McBrain',2); --bateria
insert into Toca values ('Noel Gallagher',1); --guitarra
insert into Toca values ('Ozzy Osbourne',8); --vocal
insert into Toca values ('PJ Morton',5); --teclado
insert into Toca values ('Pat Smear',1); --guitarra
insert into Toca values ('Patrick Stump',1); --Fall Out Boy /guitarrista
insert into Toca values ('Paul Davis',5);
insert into Toca values ('Paul Ryder',3);
insert into Toca values ('Paulo Jr.',3);
insert into Toca values ('Pawel Maciwoda',3);
insert into Toca values ('Pedro Augusto',5);
insert into Toca values ('Peter Parada',1); --The Offspring Guitarra
insert into Toca values ('Phil X',1); --guitarra
insert into Toca values ('Rich Faulkner',1);
insert into Toca values ('Rick Wakeman',5);
insert into Toca values ('Rob Halford',7);
insert into Toca values ('Robert Trujillo',3); --baixo
insert into Toca values ('Roberto Frejat',1);
insert into Toca values ('Roberto Frejat',9); -- Frejat /violao/guitarra/Sino
insert into Toca values ('Roddy Bottum',5);
insert into Toca values ('Rudolf Schenker',1);
insert into Toca values ('Samuel Rosa',4);
insert into Toca values ('Scott Travis',2);
insert into Toca values ('Sergio Britto',5);
insert into Toca values ('Serj Tankian',5); 
insert into Toca values ('Shaun Ryder',1);
insert into Toca values ('Shavo Odadjian',3); 
insert into Toca values ('Slash',1);
insert into Toca values ('Stephen Aiellio',5); -- Thirty Seconds to Mars / Teclado
insert into Toca values ('Steve Harris',3); --baixo
insert into Toca values ('Steve Harris',8);
insert into Toca values ('Steve Howe',1);
insert into Toca values ('Steven Tyler',7);
insert into Toca values ('Stevie Young',1);
insert into Toca values ('Synyster Gate',1); --guitarra
insert into Toca values ('Taylor Hawkins',2); --bateria
insert into Toca values ('Thiago Castanho',3); --baixo
insert into Toca values ('Tico Torres',2); --bateria
insert into Toca values ('Tobin Esperance',3); --baixo
insert into Toca values ('Tom Hamilton',3);
insert into Toca values ('Tony Belloto',4);
insert into Toca values ('Tony Palermo',2); --bateria
insert into Toca values ('Will Champion',2); --bateria
insert into Toca values ('Yves Passarel',4);--violao
insert into Toca values ('Zacky Vengeance',1); --guitarra

--Toca_em (artista (artista.nome) , banda(banda.cod))
insert into Toca_em values ('Tom Hamilton',1);
insert into Toca_em values ('Samuel Rosa',10);
insert into Toca_em values ('Henrique Portugal',10);
insert into Toca_em values ('Flea',3);
insert into Toca_em values ('Chad Smith',3);
insert into Toca_em values ('Dinho Ouro Preto',5);
insert into Toca_em values ('Fe Lemos',5);
insert into Toca_em values ('Flavio Lemos',5);
insert into Toca_em values ('Dexter Holland',6);
insert into Toca_em values ('Peter Parada',6);
insert into Toca_em values ('Greg K.',6);
insert into Toca_em values ('Adam Levine',7);
insert into Toca_em values ('PJ Morton',7);
insert into Toca_em values ('Roberto Frejat',8);
insert into Toca_em values ('Patrick Stump',9);
insert into Toca_em values ('Ben Rose',9);
insert into Toca_em values ('Kevin Drake',4);
insert into Toca_em values ('Braxton Olita',4);
insert into Toca_em values ('Stephen Aiellio',4);
insert into Toca_em values ('Steven Tyler',1);
insert into Toca_em values ('Jovi',2);
insert into Toca_em values ('Max Lover',2);

--Inserts do farofa em toca_em
insert into Toca_em values ('Dave Grohl', 11);
insert into Toca_em values ('Nate Mendel', 11);
insert into Toca_em values ('Taylor Hawkins', 11);
insert into Toca_em values ('Chris Shiflett', 11);
insert into Toca_em values ('Pat Smear', 11);
insert into Toca_em values ('James Root', 12);
insert into Toca_em values ('Craig Jones', 12);
insert into Toca_em values ('Mick Thomson',12);
insert into Toca_em values ('Corey Taylor', 12);
insert into Toca_em values ('Jay Weinberg', 12);
insert into Toca_em values ('Alessandro Venturella', 12);
insert into Toca_em values ('Jesse Carmichael', 7);
insert into Toca_em values ('Mickey Madden ', 7);
insert into Toca_em values ('James Valentine', 7);
insert into Toca_em values ('Matt Flynn', 7);
insert into Toca_em values ('Guy Berryman', 13);
insert into Toca_em values ('Jonny Buckland', 13);
insert into Toca_em values ('Will Champion', 13);
insert into Toca_em values ('Serj Tankian', 14);
insert into Toca_em values ('Daron Malakian', 14);
insert into Toca_em values ('Shavo Odadjian', 14);
insert into Toca_em values ('Jonh Dolmayan', 14);
insert into Toca_em values ('M Shadow', 16);
insert into Toca_em values ('Zacky Vengeance', 16);
insert into Toca_em values ('Synyster Gate', 16);
insert into Toca_em values ('Johnny Christ', 16);
insert into Toca_em values ('Brooks Wackerman', 16);
insert into Toca_em values ('Jared Leto', 4);
insert into Toca_em values ('Shannon Leto', 4);
insert into Toca_em values ('Tomo Milicevic', 4);
insert into Toca_em values ('Anthony Kiedis', 3);
insert into Toca_em values ('Josh Klinghoffer', 3);
insert into Toca_em values ('Jon Bon Jovi', 2);
insert into Toca_em values ('Phil X', 2);
insert into Toca_em values ('Hugh McDonald', 2);
insert into Toca_em values ('Tico Torres', 2);
insert into Toca_em values ('David Bryan', 2);
insert into Toca_em values ('Thiago Castanho', 5);
insert into Toca_em values ('Yves Passarel',5);
insert into Toca_em values ('James Hetfield', 15);
insert into Toca_em values ('Lars Ulrich', 15);
insert into Toca_em values ('Kirk Hammett', 15);
insert into Toca_em values ('Robert Trujillo', 15);
insert into Toca_em values ('Liam Gallagher', 35);
insert into Toca_em values ('Noel Gallagher', 35);
insert into Toca_em values ('Gem Archer', 35);
insert into Toca_em values ('Andy Bell', 35);
insert into Toca_em values ('Chris Sharrock',35);
insert into Toca_em values ('Shaun Ryder', 28);
insert into Toca_em values ('Paul Ryder', 28);
insert into Toca_em values ('Paul Davis', 28);
insert into Toca_em values ('Gary Whelan', 28);
insert into Toca_em values ('Branco Mello', 29);
insert into Toca_em values ('Sergio Britto', 29);
insert into Toca_em values ('Tony Belloto', 29);
insert into Toca_em values ('Ian Hill', 30);
insert into Toca_em values ('Rob Halford', 30);
insert into Toca_em values ('Rob Halford', 33);
insert into Toca_em values ('Glen Tipton', 33);
insert into Toca_em values ('Scott Travis', 33);
insert into Toca_em values ('Rich Faulkner', 33);
insert into Toca_em values ('Dave Mustaine', 31);
insert into Toca_em values ('David Ellefson', 31);
insert into Toca_em values ('Kiko Loureiro', 31);
insert into Toca_em values ('Dirk Verbeuren', 31);
insert into Toca_em values ('Humberto Gessinger', 32);
insert into Toca_em values ('Glaucio Ayala', 32);
insert into Toca_em values ('Fernando Aranha', 32);
insert into Toca_em values ('Pedro Augusto', 32);
insert into Toca_em values ('Steve Harris', 19);
insert into Toca_em values ('Adrian Smith', 19);
insert into Toca_em values ('Bruce Dickinson', 19);
insert into Toca_em values ('Janick Gers', 19);
insert into Toca_em values ('Jacoby Shaddix', 34);
insert into Toca_em values ('Jerry Horton', 34);
insert into Toca_em values ('Tobin Esperance', 34);
insert into Toca_em values ('Tony Palermo', 34);
insert into Toca_em values ('Cazuza', 21);
insert into Toca_em values ('Guto Goffi', 21);
insert into Toca_em values ('Roberto Frejat', 21);
insert into Toca_em values ('De', 21);
insert into Toca_em values ('Mauricio Barros', 21);
insert into Toca_em values ('Freddie Mercury', 22);
insert into Toca_em values ('Brian May', 22);
insert into Toca_em values ('Rudolf Schenker', 23);
insert into Toca_em values ('Klaues Meine', 23);
insert into Toca_em values ('Matthias Jab', 23);
insert into Toca_em values ('Pawel Maciwoda', 23);
insert into Toca_em values ('Mikkey Dee', 23);
insert into Toca_em values ('Steve Howe', 24);
insert into Toca_em values ('Rick Wakeman', 24);
insert into Toca_em values ('Jon Anderson', 24);
insert into Toca_em values ('Alan White',24);
insert into Toca_em values ('Axl Rose', 25);
insert into Toca_em values ('Slash', 25);
insert into Toca_em values ('DuffMcKagan', 25);
insert into Toca_em values ('Frank Ferrer', 25);
insert into Toca_em values ('Melissa Reese', 25);
insert into Toca_em values ('Mike Patton', 26);
insert into Toca_em values ('Billy Gould', 26);
insert into Toca_em values ('Mike Bordin', 26);
insert into Toca_em values ('Roddy Bottum', 26);
insert into Toca_em values ('Jon Hudson', 26);
insert into Toca_em values ('Paulo Jr.', 27);
insert into Toca_em values ('Andreas Kisser', 27);
insert into Toca_em values ('Derrick Green ', 27);
insert into Toca_em values ('Eloy Casagrande', 27);
insert into Toca_em values ('Dave Evans', 17);
insert into Toca_em values ('Angus Young', 17);
insert into Toca_em values ('Stevie Young', 17);
insert into Toca_em values ('Chris Slade', 17);
insert into Toca_em values ('Herbert Vianna', 18);
insert into Toca_em values ('Bi Ribeiro', 18);
insert into Toca_em values ('Joao Barane', 18);
insert into Toca_em values ('Dave Murray', 19);
insert into Toca_em values ('Nicko McBrain', 19);
insert into Toca_em values ('Jacnick Gears', 19);
insert into Toca_em values ('Ozzy Osbourne',20);


insert into Trabalha values (1,'11111111111');
insert into Trabalha values (2,'22222222222');
insert into Trabalha values (1,'33333333333');
insert into Trabalha values (2,'44444444444');
insert into Trabalha values (1,'55555555555');
insert into Trabalha values (2,'66666666666');
insert into Trabalha values (1,'77777777777');
insert into Trabalha values (2,'88888888888');
insert into Trabalha values (1,'99999999999');
insert into Trabalha values (2,'10110111010');

--1) Número de instrumentos que cada artista toca
SELECT a.nome,COUNT(*) "N de instumentos"
FROM Artista a, Instrumento i, Toca t
WHERE a.nome=t.artista AND i.n_serie=t.insts
GROUP BY a.nome,ARTISTA;

--2) Média de contribuição do festival por edição
SELECT AVG(contribuicao) "Media de contribuicao"
FROM Patrocina p;

--3) Contribuição dos patrocinadores em cada edição do festival em ordem crescente
SELECT edicao , SUM(contribuicao) Patrocinio
FROM PATROCINA, edicao
GROUP BY edicao
ORDER BY edicao asc;

--4)Quais equipamentos foram utilizados pelas bandas que tocaram no palco Sunset
SELECT DISTINCT e.nome
FROM equipamento e, banda b, apresentacao a, palco p, utiliza u
WHERE e.n_serie = u.equipamento AND u.banda=b.cod AND b.cod=a.apresentador AND 
	a.cod_palco = p.cod AND p.nome_palco='Sunset';

--5)Quais funcionários do sexo masculino trabalharam no palco mundo e o nome começa com a letra M
SELECT f.nome
FROM funcionario f, trabalha t, palco p
WHERE f.cpf=t.cpf AND t.palco=p.cod AND f.sexo='M' AND p.nome_palco='Mundo' AND f.nome LIKE 'M%';

--6) Qual Hotel hospeda o maior numero de bandas?
SELECT h.nome
FROM hotel h, banda b
WHERE h.telefone = b.hotel
GROUP BY h.nome
HAVING count(*)=(SELECT MAX(cnt)
	FROM (SELECT count(*) cnt
	FROM hotel h, banda b
	WHERE h.telefone = b.hotel
	GROUP BY h.nome) ct);

--7)Qual a média das contribuições feitas pela Sky
SELECT avg(contribuicao)
FROM patrocinador p, patrocina pat
WHERE p.cod = pat.patroc AND p.nome='Sky';

--8)Qual banda tem o menor número de artistas?

SELECT b.nome
FROM banda b, toca_em t, artista a
WHERE b.cod=t.banda AND a.nome=t.artista
GROUP BY b.nome
HAVING count(*)=(SELECT MIN(cnt)
	FROM (SELECT count(*) cnt
	FROM banda b, toca_em t, artista a
	WHERE b.cod=t.banda AND a.nome=t.artista
	GROUP BY b.nome) ct);


--9)Quais bandas apresentaram entre de 2013 à 1015?
SELECT b.nome
FROM banda b, apresentacao aP
WHERE b.cod=ap.apresentador AND ap.dat_hr_inicio BETWEEN '2013-01-01 00:00:00' AND '2015-12-31 23:59:00'
GROUP BY B.nome;

--10)Edição e valor do total arrecadado, sendo esse maior que 50000000.00
SELECT edicao, SUM(contribuicao) totalArrecadado
FROM ((SELECT edicao,contribuicao FROM patrocina )UNION(SELECT ano,arrecadacao FROM EDICAO))total
GROUP BY edicao
HAVING SUM(contribuicao) > 50000000.00;

--11) Média de apresentações feitas por festival
SELECT e.ano, avg(apPorAno.count)
FROM Apresentacao ap, edicao e,(SELECT ed.ano, count(*)
		FROM Apresentacao ap, edicao ed
		group by ed.ano) apPorAno
WHERE ap.ano=e.ano
GROUP BY e.ano

--12) Quais funcionários resposaveis pelos palcos nos shows do Foo Fighthers?
SELECT f.nome
FROM banda b, apresentacao ap, palco p,  funcionario f
WHERE b.nome='Foo Fighters' AND b.cod = ap.apresentador AND ap.cod_palco = p.cod AND
	p.responsavel=f.cpf
