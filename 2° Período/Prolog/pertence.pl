%pertence(X,[X|_]).
%pertence(X,[Y|Z]):-
	%X\=Y,
	%pertence(X,Z).

%n_esimo(X,[X|_],1).
%n_esimo(X,[_|Z],R):-
	%n_esimo(X,Z,R1),
	%R is R1+1.
%n_esimo(1,X,[X|_]).
%n_esimo(N,X,[_|Z]):-
%	n_esimo(N1,X,Z),
%	N is N1+1 .

pertence(X,[X|_]).
pertence(X,[Y|Z]):-
	X\=Y,
	pertence(X,Z).
n_esimo(1,[X|_],X).
n_esimo(N,[_|Y],R):-
	n_esimo(N1,Y,R),
	N is N1 +1.
n_elementos(0,[]).
n_elementos(X,[_|Y]):-
	n_elementos(X1,Y),
	X is X1+1.
%insere(X,[],[X]).
%insere(X,[_|_],[X|_]).
%insere(X,[Y|Z],[A|B]):-
inserir_N(X,1,Y,[X|Y]).
inserir_N(X,N,[X1|Y1],[X1|Y]):-
	M is N-1,
	inserir_N(X,M,Y1,Y).

tire_elemento(_,[],[]).
tire_elemento(X,[X|Y],Y).
tire_elemento(X,[Y|R],[Y|R1]):-
	X\=Y ,
	tire_elemento(X,R,R1).
concatenar([],[X|Y],[X|Y]).
concatenar([X|Y1],Y2,[X|Y3]):-
	concatenar(Y1,Y2,Y3).
