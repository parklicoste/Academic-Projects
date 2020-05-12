%facts
male(khushal).
male(piyush).
male(devendra).
female(sudha).
female(sarita).
female(sushila).
male(ilam).
female(vidya).
male(udayveer).
female(anaro).
female(akanksha).
father(udayveer,devendra).
mother(anaro,devendra).
father(udayveer,sushila).
mother(anaro,sushila).
married(anaro,udayveer).
father(ilam,sarita).
father(ilam,sudha).
mother(vidya,sarita).
mother(vidya,sudha).
father(devendra,khushal).
father(devendra,piyush).
father(devendra,akanksha).
mother(sarita,khushal).
mother(sarita,piyush).
mother(sarita,akanksha).
married(sarita,devendra).
male(ramesh).
married(sudha,ramesh).

%rule(s):

parent(P,Q):-
  (father(P,Q) ; mother(P,Q)).

is_mother(P):-
  (female(P), mother(P,_)).

is_father(P):-
  (male(P), father(P,_)).

aunt(P):-
  female(P),not(is_mother(P)).

uncle(P):-
  male(P),not(is_father(P)).

sister(X,Y):-
  (female(X),father(P,X),father(P,Y), mother(Q,X),mother(Q,Y)).

brother(X,Y):-
  (male(X),father(P,X),father(P,Y), mother(Q,X),mother(Q,Y)).

grandfather(X,Y):-
  male(X),father(P,Y),father(X,P).

grandmother(X,Y):-
  female(X),father(P,Y),mother(X,P).

ancestors(X,Y):-
  father(X,Y) ; mother(X,Y) ; grandfather(X,Y) ; grandmother(X,Y).
