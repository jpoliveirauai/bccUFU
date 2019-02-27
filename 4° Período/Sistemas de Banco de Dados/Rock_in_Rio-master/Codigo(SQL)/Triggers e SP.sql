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

SELECT geraReceitaAte(2015);