%{
#include <stdio.h>
#include <math.h>

int regs[26];
int base;

%}

%start list

%token LETTER NUMBER

%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'
%right '^'
%left UMINUS  /*supplies precedence for unary minus */

%%                   /* beginning of rules section */

list:                       /*empty */
         | list stat '\n'
         | list error '\n'
         {
           yyerrok;
         }
         ;

stat:    expr { printf("%d\n",$1); }
        | LETTER '=' expr { regs[$1] = $3;}
         ;

expr:    '(' expr ')' { $$ = $2; }
         | expr '*' expr   { $$ = $1 * $3;  }
         | expr '/' expr   { $$ = $1 / $3;  }
         | expr '%' expr { $$ = $1 % $3; }
         | expr '+' expr  { $$ = $1 + $3;  }
         | expr '-' expr   { $$ = $1 - $3;  }
         | expr '&' expr  { $$ = $1 & $3;  }
         | expr '|' expr   {  $$ = $1 | $3;  }
         | '-' expr %prec UMINUS { $$ = -$2; }
	 | expr '^' expr  {$$ = pow($1, $3);}
         | LETTER { $$ = regs[$1]; }
         | NUMBER  { $$ = $1; };

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