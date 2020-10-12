%%
[0-9]*00 {printf(“String is ending with 00”);}
[0-9]* {printf(“String is not ending with 00”);}
%%
main()
{
yylex();
}
int yywrap()
{
return 1;
}