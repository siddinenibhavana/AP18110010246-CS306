%%
[0-9]*000[0-9]* { printf(“String has three consecutive zeroes”);}
[0-9]* { printf(“String doesn't have three consecutive zeroes”);}
%%
main()
{
yylex();
}
int yywrap()
{
return 1;
}