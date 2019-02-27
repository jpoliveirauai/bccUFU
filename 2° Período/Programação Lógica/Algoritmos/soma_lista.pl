soma_lista([X],X).
soma_lista([_|Y],R):-
	soma_lista(Y,R1),
	R is R+R1.
maior(X,Y,X):-
	X>Y.
maior(X,Y,Y):-
	Y>X.
pertence(X,[X|_]).
pertence(P,[X|Y]):-
	X\=P,
	pertence(P,Y),!.
tamanho([],0).
tamanho([_|Y],R):-
	tamanho(Y,R1),
	R is R1+1.
ultimo([X],X).
ul
