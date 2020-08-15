#include<stdio.h>
#include<stdlib.h>
int main(){
    int i=0,st=0;
    char live,instr[20];
    printf("Enter input string \t:");
    scanf("%s",instr);
    while((live=instr[i++])!='\0')
    {
    switch(st)
    {
        case 0:if(live=='a')
               st=1;
               else if(live=='b')
               st=2;
               else
               {
                   printf("Invalid token");
                   exit(0);
               }
               break;
        case 1:if(live=='a')
               st=0;
               else if(live=='b')
               st=3;
               else
               {
                   printf("Invalid token");
                   exit(0);
               }
               break;
        case 2:if(live=='a')
               st=3;
               else if(live=='b')
               st=0;
               else
               {
                   printf("Invalid token");
                   exit(0);
               }
               break;
        case 3:if(live=='a')
               st=2;
               else if(live=='b')
               st=1;
               else
               {
                   printf("Invalid token");
                   exit(0);
               }
               break;
               
    }
}
if(st==0)
    printf("\n\nString accepted\n\n");
else
    printf("\n\nString not accepted\n\n");
return  0;
}