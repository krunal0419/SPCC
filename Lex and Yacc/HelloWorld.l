%option noyywrap
%{
#include<stdio.h>
%}

%%
"Hello World" {printf("GOOD BYE \n");}
, ;
%%
int main()
{
yylex();
return 0;
}