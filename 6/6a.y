%{
#include<stdio.h>
%}
%token A B
%%
str: s'\n' {return 1;}
s: A s B ;
| A s ;
| s B ;
| A ;
| B ;
| ;
%%
main()
{
printf("type the string ?\n");
if(yyparse())
printf("valid string\n");
}
int yyerror()
{
printf("invalid string.\n");
exit(0);
}