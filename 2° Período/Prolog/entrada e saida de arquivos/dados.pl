raiz:-
	see('a.dat'),
	process,
	seen.
process:-
	read(Termo),
	process_termo(Termo).
process_termo(end_of_file):-
	!,
	told.
process_termo(Termo):-
	trata(Termo),
	process.
trata(Termo):-
	Exp is sqrt(Termo),
	tell('raiz.txt'),
	write(Exp),
	nl.
dialogo:-
	write('qual seu nome?'),
	read(Char),
%	get0(_),
	write('Bom dia '),
	write(Char),
	nl,
	nl.



