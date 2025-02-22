%option noyywrap
%{
	#include<stdio.h>
	int nchar, nword, nline;
%}

%%
\n { nline++; nchar++; }
[^ \t\n]+ { nword++, nchar += yyleng; }
%%


int main() 
{
FILE *f;
char file[10];
printf("Enter File Name : ");
scanf("%s",file);
f = fopen(file,"r");
yyin = f;
yylex();
printf("Number of characters = %d\n", nchar);
printf("Number of words = %d\n", nword);
printf("Number of lines = %d\n", nline);
fclose(yyin);

	return 0;
}