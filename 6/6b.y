%{
#include<stdio.h>
%}
%token A B
%%
str: s'\n' {return 0;}
s: A s B ;
| ;
%%
main()
{
printf("type the string ?\n");
if(!yyparse())
printf("valid string\n");
}
int yyerror()
{
printf("invalid string.\n");
exit(0);
}