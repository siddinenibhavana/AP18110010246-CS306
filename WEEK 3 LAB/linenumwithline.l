%{
#include
#include
int ln=0
%}
%%
"\n"{}
.*{ln++;fprintf(yyout,"\n%d.%s",ln,yytext);}
%%
main()
{
yyin=fopen("try1.txt","r");
yyout=fopen(try2.txt","w");
yy.lex();
return 0;
}
int yywrap()
{

} 