:-op(0, xfx,mais).
:-op(0,xfx,eh).
eh(_,_).
eh(X,A):-
	X = A.
eh(X,A):-
	X is A.
mais(A,B):-

	A+B.
