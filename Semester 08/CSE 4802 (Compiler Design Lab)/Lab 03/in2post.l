%option noyywrap

%{
#include <stdio.h>
#include "y.tab.h"
char identifier[100];
int c;
extern int yylval;
%}

%%
" "       ;

[0-9]+     {
            yylval = atoi(yytext);
            return(NUMBER);
          }
[a-zA-Z][a-zA-Z0-9]* {
	strncpy(identifier, yytext, 100);
	yylval = (int) identifier;
	return (IDENTIFIER);
}

[^a-z0-9\b]    {
                 c = yytext[0];
                 return(c);
               }

%%