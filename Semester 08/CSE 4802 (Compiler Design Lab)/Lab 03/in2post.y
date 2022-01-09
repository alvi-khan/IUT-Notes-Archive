%{
#include <stdio.h>

%}

%start list

%token NUMBER
%token IDENTIFIER

%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'
%right '^'

%%                   /* beginning of rules section */

list:                       /*empty */
         | list stat '\n'
         | list error '\n'
         {
           yyerrok;
         }
         ;

stat:    expr
         {
           printf("\n");
         };

expr:    '(' expr ')' 
         | expr '*' expr   { printf("* ");}
         | expr '/' expr   { printf("/ ");}
         | expr '%' expr { printf("% ");}
         | expr '+' expr  { printf("+ ");}
         | expr '-' expr   { printf("- ");}
	 | expr '&' expr  { printf("& ");}
         | expr '|' expr   { printf("| ");}
	 | expr '^' expr  { printf("^ ");}
         | NUMBER  { printf("%d ",yylval);}
	 | IDENTIFIER { printf("%s ", yylval);};


%%
main()
{
 return(yyparse());
}

yyerror(s)
char *s;
{
  fprintf(stderr, "%s\n",s);
}

yywrap()
{
  return(1);
}