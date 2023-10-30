%option noyywrap
%{ 
    #include "stdio.h"
    #include "test.tab.h"
    extern int yylval; 
%}

%% 
[0-9]+ {yylval=atoi(yytext);return number;} \+ { return plus;} 
\- { return minus;} 
\* { return multiply;} 
\/ {return divide;} 
. {return yytext[0];} [\t]+; 
\n return 0; 
%%