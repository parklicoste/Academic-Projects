%player(name(First,Last),team(City),pos(Position),stats(Goals,Assists,Shots))
player(name(alex,ovechkin),team(was),pos(lw),stats(51,38,338)).
player(name(marcus,pettersson),team(pit),pos(d),stats(2,23,87)).
player(name(kevin,fiala),team(min),pos(lw),stats(13,26,174)).
player(name(ryan,hartman),team(min),pos(rw),stats(12,14,145)).
player(name(leon,driasaitl),team(edm),pos(c),stats(50,55,231)).
player(name(john,tavares),team(tor),pos(c),stats(47,41,286)).
player(name(steven,stamkos),team(tb),pos(c),stats(45,53,234)).
player(name(nikita,kucherov),team(tb),pos(rw),stats(41,87,246)).
player(name(nathan,mackinnon),team(col),pos(c),stats(41,58,365)).
player(name(alex,debrincat),team(chi),pos(rw),stats(41,35,220)).
player(name(jake,guentzel),team(pit),pos(lw),stats(40,36,227)).
player(name(jeff,skinner),team(buf),pos(lw),stats(40,23,268)).
player(name(mark,scheifele),team(wpg),pos(c),stats(38,46,199)).
player(name(johnny,gaudreau),team(cgy),pos(lw),stats(36,63,245)).
player(name(mike,hoffman),team(fla),pos(lw),stats(36,34,253)).
player(name(aleksander,barkov),team(fla),pos(c),stats(35,61,206)).
player(name(morgan,rielly),team(tor),pos(d),stats(20,52,223)).
player(name(brent,burns),team(sj),pos(d),stats(16,67,300)).
player(name(patrick,kane),team(chi),pos(rw),stats(44,66,341)).

%A) On what team does Mike Hoffman play, and in what position?
% ?- player(name(mike,hoffman),Team,Position,_).

%B)What is the last name of any player who has at least 52 assists?
% ?- player(name(_,LastName),_,_,stats(_,Assists,_)), Assists>=52.

%C)Who plays centre?
% ?- player(Name,_,pos(c),_).

%D)What teams have a player with the first name "John"?
% ?- player(name(john,_),Team,_,_).

%E)What pairs of players play on the same team?
% ?- player(Name1,Team,_,_),player(Name2,Team,_,_),Name1\=Name2.

%F)What players have fewer than 100 points? (where points = goals + assists)
% ?- player(Name,_,_,stats(X,Y,_)),X+Y<100.

%G)What is the shot accuracy of the player with the most goals? (where shot accuracy = goals / shots)
% ?- player(_,_,_,stats(Goals,_,Shots)),X is Goals/Shots, not(player(_,_,_,stats(Goals2,_,Shots2)),Y is Goals2/Shots2, X<Y).

%H)Who is the least accurate right wing player?
% ?- player(Name1,_,pos(rw),stats(Goals1,_,Shots1)), X is Goals1/Shots1, not(( player(Name2,_,pos(rw),stats(Goals2,_,Shots2)), Y is Goals2/Shots2,Y<X)).
