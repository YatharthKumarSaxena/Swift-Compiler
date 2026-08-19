digit       [0-9]
digits      {digit}+
integer     {digits}
decimal     {digits}\.{digits}
exponent    [eE][+-]?{digits}
double      {decimal}{exponent}?|{integer}{exponent}
boolean     true|false

char_cont   [^'\n]
character   \'{char_cont}\'

string_cont [^"\n]
string      \"{string_cont}*\"

letter      [a-zA-Z]
letters     {letter}+