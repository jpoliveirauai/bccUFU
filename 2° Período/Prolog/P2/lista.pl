concatena([],[X|Y],[X|Y]).
concatena([X|Y],Y1,[X|L]):-
	concatena(Y,Y1,L).

n_esimo(1,[X|_],X).
n_esimo(R,[_|Y],A):-
	n_esimo(R1,Y,A),
	R is R1+1.

nelementos(0,[
	   ]).
nelementos(R,[_|Y]):-
	nelementos(R1,Y),
	R is R1+1.

tiraelemento(X,[X|Y],Y).
tiraelemento(_,[],[]).
tiraelemento(A,[X|Y],[X|O]):-
	A\=X,
	tiraelemento(A,Y,O).
retira(_,[],[]).
retira(A,[A|B],L):-
       retira(A,B,L).
retira(A,[X|Y],[X|L]):-
	A\=X,
	retira(A,Y,L).
