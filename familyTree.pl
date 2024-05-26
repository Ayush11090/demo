% facts
male(baburao).
male(surendra).
male(satish).
male(subhash).
male(kiran).
male(rahul).
male(pratik).
male(ayush).
male(sarthak).
male(vivan).

female(gulabbai).
female(vandana).
female(archana).
female(surekha).
female(shalan).
female(pradnya).
female(rutuja).
female(deepali).
female(swati).
female(jagruti).

parent(baburao,surendra).
parent(baburao,satish).
parent(baburao,subhash).
parent(baburao,shalan).
parent(surendra,ayush).
parent(surendra,pradnya).
parent(satish,pratik).
parent(satish,rutuja).
parent(subhash,rahul).
parent(subhash,swati).
parent(shalan,kiran).
parent(shalan,deepali).
parent(kiran,sarthak).
parent(kiran,jagruti).
parent(rahul,vivan).

parent(gulabbai,surendra).
parent(gulabbai,satish).
parent(gulabbai,subhash).
parent(gulabbai,shalan).
parent(vandana,ayush).
parent(vandana,pradnya).
parent(archana,pratik).
parent(archana,rutuja).
parent(surekha,rahul).
parent(surekha,swati).
parent(shalan,kiran).
parent(shalan,deepali).

% rules
father(X,Y) :- male(X), parent(X,Y).
mother(X,Y) :- female(X), parent(X,Y).

brother(X,Y) :- male(X), parent(Z,X), parent(Z,Y), X \= Y.
sister(X,Y) :- female(X), parent(Z,X), parent(Z,Y), X \= Y.

son(X,Y) :- parent(Y,X), male(X).
daughter(X,Y) :- parent(Y,X), female(X).

grandfather(X,Y) :- father(X,Z), parent(Z,Y).
grandmother(X,Y) :- mother(X,Z), parent(Z,Y).

grandson(X,Y) :- male(X), (grandfather(Y,X) ; grandmother(Y,X)).
granddaughter(X,Y) :- female(X), (grandfather(Y,X) ; grandmother(Y,X)).

sibling(X,Y) :- parent(Z,X), parent(Z,Y), X \= Y.
cousin(X,Y) :- sibling(Z,W), parent(Z,X), parent(W,Y).

husband(X,Y):- male(X), female(Y), parent(X,V), parent(Y,V).
wife(X,Y) :- husband(Y,X).

uncle(X,Y) :- sibling(X,Z), parent(Z,Y), male(X).
aunty(X,Y) :- (sibling(X,Z), parent(Z,Y), female(X)) ; (wife(X,Z), uncle(Z,Y)).

nephew(X,Y) :- male(X), (uncle(Y,X) ; aunty(Y,X)).
niece(X,Y) :- female(X), (uncle(Y,X) ; aunty(Y,X)).

greatgrandfather(X,Y) :- father(X,Z), (grandfather(Z,Y) ; grandmother(Z,Y)).
greatgrandmother(X,Y) :- mother(X,Z), (grandfather(Z,Y) ; grandmother(Z,Y)).

greatgrandson(X,Y) :- male(X), (greatgrandfather(Y,X) ; greatgrandmother(Y,X)).
greatgranddaughter(X,Y) :- female(X), (greatgrandfather(Y,X) ; greatgrandmother(Y,X)).

second_cousin(X,Y) :- cousin(Z,W), parent(Z,X), parent(W,Y).

second_uncle(X,Y) :- cousin(X,Z), parent(Z,Y), male(X).
second_aunty(X,Y) :- (cousin(X,Z), parent(Z,Y), female(X)) ; (wife(X,Z), second_uncle(Z,Y)).

second_nephew(X,Y) :- male(X), (second_uncle(Y,X) ; second_aunty(Y,X)).
second_niece(X,Y) :- female(X), (second_uncle(Y,X) ; second_aunty(Y,X)).

% To succeed after all relations are found

relation(X, Y) :-
    ( father(X,Y) -> write(X), write(" is father of "), write(Y), nl
    ; mother(X,Y) -> write(X), write(" is mother of "), write(Y), nl
    ; brother(X,Y) -> write(X), write(" is brother of "), write(Y), nl
    ; sister(X,Y) -> write(X), write(" is sister of "), write(Y), nl
    ; son(X,Y) -> write(X), write(" is son of "), write(Y), nl
    ; daughter(X,Y) -> write(X), write(" is daughter of "), write(Y), nl
    ; grandfather(X,Y) -> write(X), write(" is grandfather of "), write(Y), nl
    ; grandmother(X,Y) -> write(X), write(" is grandmother of "), write(Y), nl
    ; grandson(X,Y) -> write(X), write(" is grandson of "), write(Y), nl
    ; granddaughter(X,Y) -> write(X), write(" is granddaughter of "), write(Y), nl
    ; sibling(X,Y) -> write(X), write(" is sibling of "), write(Y), nl
    ; cousin(X,Y) -> write(X), write(" is cousin of "), write(Y), nl
    ; husband(X,Y) -> write(X), write(" is husband of "), write(Y), nl
    ; wife(X,Y) -> write(X), write(" is wife of "), write(Y), nl
    ; uncle(X,Y) -> write(X), write(" is uncle of "), write(Y), nl
    ; aunty(X,Y) -> write(X), write(" is aunty of "), write(Y), nl
    ; nephew(X,Y) -> write(X), write(" is nephew of "), write(Y), nl
    ; niece(X,Y) -> write(X), write(" is niece of "), write(Y), nl
    ; greatgrandfather(X,Y) -> write(X), write(" is great-grandfather of "), write(Y), nl
    ; greatgrandmother(X,Y) -> write(X), write(" is great-grandmother of "), write(Y), nl
    ; greatgrandson(X,Y) -> write(X), write(" is great-grandson of "), write(Y), nl
    ; greatgranddaughter(X,Y) -> write(X), write(" is great-granddaughter of "), write(Y), nl
    ; second_cousin(X,Y) -> write(X), write(" is second cousin of "), write(Y), nl
    ; second_uncle(X,Y) -> write(X), write(" is second uncle of "), write(Y), nl
    ; second_aunty(X,Y) -> write(X), write(" is second aunty of "), write(Y), nl
    ; second_nephew(X,Y) -> write(X), write(" is second nephew of "), write(Y), nl
    ; second_niece(X,Y) -> write(X), write(" is second niece of "), write(Y), nl
    ).

start:-
    write("Name of first person "),read(X),
    write("Name of second person "),read(Y),
    relation(X,Y).
