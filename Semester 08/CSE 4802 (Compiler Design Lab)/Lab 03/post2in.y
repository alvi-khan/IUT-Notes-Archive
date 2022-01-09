%{
#include <stdio.h>
#include<string.h>

char st[100][50];
int indx=0;
void push();
char* top();
void process(char* a);

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
           printf("\n=%s\n",top());
         };

expr:    expr expr '*' { process(" * ");}
         | expr expr '/' { process(" / ");}
         | expr expr '%' { process(" % ");}
         | expr expr '+' { process(" + ");}
         | expr expr '-' { process(" - ");}
         | expr expr '&' { process(" & ");}
	 | expr expr '|' { process(" | ");}
	 | expr expr '^' { process(" ^ ");}
         | NUMBER  { push($1); }
	 | IDENTIFIER { pushChar($1);
	 };



%%
main()
{
 return(yyparse());
}

void push(int a)
{  char tmp[20]; 	
   sprintf(tmp, "%d", a);
   strcpy(st[indx++],tmp);
}

void pushChar(char a[])
{  char tmp[20]; 	
   sprintf(tmp, "%s", a);
   strcpy(st[indx++],tmp);
}

char* pop()
{
    return st[--indx];
}

char* top()
{
    return st[indx-1];
}

void process(char* a)
{
    char buffer[50];
    char* c1=pop();
    char* c2=pop();
    //bzero(buffer,20);
    memset(buffer, 0, 50);
    strcat(buffer,"(");
    strcat(buffer,c2);
    strcat(buffer,a);
    strcat(buffer,c1);
    strcat(buffer,")");
    strcpy(st[indx++],buffer);
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