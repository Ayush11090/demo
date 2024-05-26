%facts
vehicle(car).
vehicle(motorcycle).
vehicle(bicycle).

has_engine(car).
has_engine(motorcycle).

wheels(car,4).
wheels(motorcycle,2).
wheels(bicycle,2).

%rules
motorized(Vehicle) :- vehicle(Vehicle),has_engine(Vehicle).

four_wheel(Vehicle) :- vehicle(Vehicle), wheels(Vehicle,4).

two_wheel(Vehicle) :- vehicle(Vehicle), wheels(Vehicle,2).

start :-
    write("Enter Vehicle Name: "), read(V),

    (   motorized(V)-> write("Vehicle has Motor"), nl ; true),
    (   four_wheel(V)->  write("Vehicle has four wheels"), nl ; true),
    (   two_wheel(V)->  write("Vehicle has two wheels"), nl ; true).
