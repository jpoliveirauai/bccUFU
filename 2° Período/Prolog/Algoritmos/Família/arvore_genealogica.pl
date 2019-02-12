pai(Z,Y):-
	mae(X,Y),
	esposa(X,Z).
pai(joao,antonio).
pai(joao,sebastiao).
pai(joao,sebastiana).
pai(joao,luzia).
pai(antonio,marcia).
pai(antonio,marcone).
pai(antonio,maria_dalva).
esposa(X,Y):-
	marido(Y,X).
mae(sebastiana,tianinha).
mae(sebastiana,ana).
mae(sebastiana,ratinho).
mae(ana,bruno).
mae(ana,leonardo).
mae(tianinha,aline).
mae(luzia,netinho).
mae(luzia,esqueci).
mae(marcia,joao_p).
mae(marcia,lucas).
mae(maria,maria_fernanda).
mae(Z,Y):-
	pai(X,Y),
	esposa(Z,X).
marido(newton,marcia).
marido(luiz,maria).
marido(calado,luzia).
marido(antonio,maria).
marido(leonardo,ana).
marido(joao,ana).
ancestral(X,Y):- pai(X,Y).
ancestral(X,_):-
	pai(Z,X),
	ancestral(_,Z).



















