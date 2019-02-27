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
