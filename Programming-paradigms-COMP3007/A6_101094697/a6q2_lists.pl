:- module(q2, [join/3, split/3, slice/4, splice/5]).

%we have only done 2C

%=============Question 2 C ==============

slice(_,0,0,[]).
slice([],_,_,[]).

slice([_A|B],R,N,T):- R<N, R>0, slice(B,R-1,N-1,T).

slice(X,R,N,T):- R<N, R<0, slice(X,R+1,N,T).


slice([A|B],R,N,T):- 0 is R, R<N,T=[A|K], N2 is N-1, slice(B,0,N2,K).
