%module(q5, [edge/3, connected/2, pathLength/3, listForPath/3, onPath/3]).
%dynamic edge/3.

%edge(X,Y,Z).

edge(a,b,2).
edge(b,c,2).
edge(c,d,2).
edge(d,a,2).

%=========== Question 5A================
%base case
connected(X,Y) :-
edge(X,Y,_).


%recursive case
connected(X,Y) :-
  edge(X,Z,_),
  \+ edge(X,Y,_)
  connected(Z,Y).



%=========== Question 5B================
%recursive case
listForPath(X, Y, L):-
  listForPath(X, Y, [], L).

%base case
listForPath(X, X, T, T).

%iterative

listForPath(X, Y, T, D) :-
    (edge(X,Z,N) ; edge(Z, X,N)),
    !,
    B = (edge(Z, X,N)),
    \+ member(B,T),
    flatten([T|B],K),
    listForPath(Z, Y, K, D).

%=========== Question 5C================
%base case
pathLength(X,Y,R):-edge(X,Y,R).



%recursive case
pathLength(X,Y,R):-
  edge(X,Z,M),
  pathLength(Z,Y,R1),
  R is M + R1.



%=========== Question 5D================

%base case
path(X,Y,[]) :- edge(X,Y,_).

%recursive case
path(X,Y,[Z|P]) :- not(X == Y), edge(X,Z,_), path(Z,Y,P), not(member(Z, P)).

onPath(X,Y,K):- path(X,Y,Z), member(K,Z).
