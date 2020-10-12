%option noyywrap
digit [+-]?[0-9]+
id [a-zA-Z_][a-zA-Z0-9_]*
num [+-]?[0-9]*\.[0-9]+
exp {digit}[e]{digit}
keyword "int"|"char"|"float"|"void"|"double"|"if"|"else"|"for"|"while"|"do"|"switch"|"case"|"break"|"unsigned"|"main"
%{
#include<string.h>
char st[20][30];
void storesymbtab(char* id);
%}
%%
"/"([^]|\+[^/])\+"/" fprintf(yyout,"multi-line comment\n");
"//".*\n   fprintf(yyout,"single-line comment\n");
{keyword} fprintf(yyout,"%s - Keyword\n",yytext);
"<="       fprintf(yyout,"%s - Relational operator LE\n",yytext);
"<"	   fprintf(yyout,"%s - Relational operator LT\n",yytext);
">="       fprintf(yyout,"%s - Relational operator GE\n",yytext);
">"	   fprintf(yyout,"%s - Relational operator GT\n",yytext);
"=="	   fprintf(yyout,"%s - Relational operator EQ\n",yytext);
"!="	   fprintf(yyout,"%s - Relational operator NE\n",yytext);
"="	   fprintf(yyout,"%s - Assignment operator\n",yytext);
{exp}	   fprintf(yyout,"%s - Exponential float\n",yytext);
{num}	   fprintf(yyout,"%s - Fractional float\n",yytext);
{digit}    fprintf(yyout,"%s - Digit\n",yytext);
{id}     { fprintf(yyout,"%s - Identifier\n",yytext); storesymbtab(yytext); }
" "|\n   
.	   fprintf(yyout,"%s: \n",yytext);
%%
main(int a,char **s)
{
 yyin=fopen(s[1],"r");
 yyout=fopen("out.txt","w"); 
 yylex();
 fprintf(yyout,"\nSymbol table:\n");
 int i=0;
 for(;strcmp(st[i],"")&&i<20;++i)
   fprintf(yyout,"\n%d. %s",i+1,st[i]);
}
void storesymbtab(char* id)
{
  int i;
  for(i=0; strcmp(st[i],"")&&i<20;++i)
    if(!strcmp(st[i],id))
      return;
  if(i==20)
  { fprintf(yyout,"Overflow!\n"); return;}     
  strcpy(st[i],id);		
}