%{
int l=0;
%}
%%
\n ++l;
%%
main()
{
yylex();
printf(“Total number of lines :: %d”,l);
}
int yywrap()
{
return 1;
}