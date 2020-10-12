%{
#include
int count=0,ncnt=1;
%}

opening “(”
closing “)”

%%
{opening} {count++;}
{closing} {count–;}
n {
if(count==0)
printf(“n No error”);
else
{
if(count<0)
printf("n Closing Paranthesis are more by %d on
%d",(-1)*count,ncnt);
else
printf("n Opening Paranthesis are more by %d on
%d",count,ncnt);
}
ncnt++;
count=0;
}
.
%%
int main(int argc,char *argv[])
{
yyin=fopen(argv[1],"r+");
yylex();
return(0);
}