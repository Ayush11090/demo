% Facts about birds
bird(sparrow).
bird(eagle).
bird(penguin).
bird(ostrich).

% Facts about bird characteristics
can_fly(sparrow).
can_fly(eagle).
flightless(penguin).
flightless(ostrich).

has_feathers(sparrow).
has_feathers(eagle).
has_feathers(penguin).
has_feathers(ostrich).

% Rules for classification
is_bird(Bird) :- bird(Bird).

is_flying_bird(Bird) :- bird(Bird), can_fly(Bird).

is_flightless_bird(Bird) :- bird(Bird), flightless(Bird).

is_small_bird(Bird) :- bird(Bird), has_feathers(Bird), \+ flightless(Bird).

is_large_bird(Bird) :- bird(Bird), has_feathers(Bird), flightless(Bird).

% Query examples
% To find all birds:
% ?- is_bird(Bird).
%
% To find birds that can fly:
% ?- is_flying_bird(Bird).
%
% To find flightless birds:
% ?- is_flightless_bird(Bird).
%
% To find small birds:
% ?- is_small_bird(Bird).
%
% To find large flightless birds:
% ?- is_large_bird(Bird).
