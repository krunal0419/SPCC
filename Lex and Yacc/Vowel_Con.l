%{
#include<stdio.h>
int vowel=0;
int con=0;
%}

%%
[aeiouAEIOU] {printf("Vowel\t\n");vowel++;}
[a-zA-z] {printf("Consonant\t\n");con++;}
\n    {printf("Vowel=%d and Consonant=%d\n",vowel,con);}
%%

int main()
{ printf("Enter a string\n"); yylex(); }
int yywrap()
{ return 1; }
