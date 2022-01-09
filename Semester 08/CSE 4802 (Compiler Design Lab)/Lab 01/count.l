%{
// Declarations
%}

%%
[\t ]+                          ;                                       // do nothing on tab
[a-zA-Z]+                       {printf("%s:word\n",yytext);}           // print word
[+-]?([0-9]*[.])?[0-9]+         {printf("%s: number\n",yytext);}        // print number
.                               {printf("%s: unknown\n",yytext);}       // print other characters
%%

// Subroutines
int main()
{
        printf("Enter a string: ");
        yylex();
}

int yywrap() { return 1; }
