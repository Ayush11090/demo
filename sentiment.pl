% Sentiment Lexicon
word_sentiment(good, positive).
word_sentiment(great, positive).
word_sentiment(awesome, positive).
word_sentiment(bad, negative).
word_sentiment(terrible, negative).
word_sentiment(awful, negative).
word_sentiment(fantastic, positive).
word_sentiment(horrible, negative).
word_sentiment(excellent, positive). % New positive sentiment
word_sentiment(terrible, negative). % New negative sentiment
word_sentiment(amazing, positive). % New positive sentiment
word_sentiment(awful, negative). % New negative sentiment
word_sentiment(superb, positive). % New positive sentiment
word_sentiment(atrocious, negative). % New negative sentiment
word_sentiment(_, neutral). % Default to neutral if sentiment is unknown

% Predicate to determine the overall sentiment of a list of words
sentiment_analysis([], neutral).
sentiment_analysis([Word|Words], Sentiment) :-
    word_sentiment(Word, WordSentiment),
    sentiment_analysis(Words, RestSentiment),
    combine_sentiments(WordSentiment, RestSentiment, Sentiment).

% Combining sentiments
combine_sentiments(positive, neutral, positive).
combine_sentiments(negative, neutral, negative).
combine_sentiments(neutral, Sentiment, Sentiment) :- \+ Sentiment = neutral.
combine_sentiments(positive, negative, neutral).
combine_sentiments(negative, positive, neutral).
combine_sentiments(neutral, neutral, neutral).

% Example usage:
%?- sentiment_analysis([good, great, terrible, awesome, fantastic, horrible, excellent, amazing, awful, superb, atrocious], Sentiment).
% Sentiment = neutral. % In this example, there's still a mix of positive and negative sentiments resulting in neutral.
