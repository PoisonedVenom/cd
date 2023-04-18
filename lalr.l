%option noyywrap
%{
    #include "y.tab.h"
    extern int yylval;
%}

%%
[0-9]+      { yylval = atoi(yytext); 
                return NUMBER; }
\n         { return 0;}
[ \t\r]     ;
. return yytext[0];
%%
