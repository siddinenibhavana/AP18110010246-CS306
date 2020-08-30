#include<stdio.h>
#include<ctype.h>
#include<string.h>
char keywords[24][30]={"int","while","break","for","do","if","float","char","switch","double","short","long",
"unsigned","sizeof","else","register","extern","static","auto","case","break","volatile","enum","typedef"};
void store_symb_tab(char id[], char st[][30])
{
	int i;
	for(i=0; strcmp(st[i],"")&&i<20;++i)
		if(!strcmp(st[i],id))  return;
	if(i==20)
	{ 
	    printf("\nOverflow!"); 
	    return;
	}
	strcpy(st[i],id);
}
int check_keyword(char s[])
{
	for(int i=0;i<24;++i)
		if(strcmp(s,keywords[i])==0) return 1;
	return 0;
}
int main()
{
	FILE *fp1,*fp2;
	char c,id[30], num[10];
	int state=0,i=0,j=0;
	fp1=fopen("x.txt","r");
	fp2=fopen("y.txt","w");
	char st[20][30];
	for(int i=0;i<20;++i)
		strcpy(st[i],"");
	while((c=fgetc(fp1))!=EOF){
		switch(state){
			case 0: 
				if(isalpha(c)||c=='_'){ state=1; id[i++]=c; }
				else if(isdigit(c)){ state=2; num[j++]=c; }
				else if(c=='<' || c=='>')  state=3;
				else if(c=='=' || c=='!')  state=4;
				else if(c=='/')  state=5;
				else if(c==' ' || c=='\t' || c=='\n' || c=='\r');
				else
					fprintf(fp2,"\n%c",c);
				break;
			case 1:
				if(isalnum(c)||c=='_')   id[i++]=c;
				else{
					id[i]='\0';
					if(check_keyword(id))  fprintf(fp2," \n%s : keyword ",id);
					else{
						fprintf(fp2,"\n%s : identifier",id);
						store_symb_tab(id,st);
					}
					state=0;
					i=0;
					ungetc(c,fp1);
				}
				break;
			case 2:
				if(isdigit(c))  num[j++]=c;
				else{
					num[j]='\0';
					fprintf(fp2," \n%s: number",num);
					state=0;
					j=0;
					ungetc(c,fp1);
				}
				break;
			case 3:
				if(c=='='){
					fseek(fp1,-2,SEEK_CUR);
					c=fgetc(fp1);
					if(c=='<')   fprintf(fp2,"\n<=: relational operator LE");
					else         
					fprintf(fp2,"\n<=: relational operator GE");
					c=fgetc(fp1);
					state=0;
				}
				else{
					fseek(fp1,-2,SEEK_CUR);
					c=fgetc(fp1);
					if(c=='<')   fprintf(fp2,"\n<: relational operator LT");
					else
						fprintf(fp2,"\n>: relational operator GT");
					state=0;
				}
				break;
			case 4:
				if(c=='='){
					fseek(fp1,-2,SEEK_CUR);
					c=fgetc(fp1);
					if(c=='=')   fprintf(fp2,"\n==: relational operator EQ");
					else
						fprintf(fp2,"\n!=: relational operator NE");
					c=fgetc(fp1);
					state=0;
				}
				else{ 
					fprintf(fp2,"\n!");
					ungetc(c,fp1); 
					state=0; 
				}
				break;
			case 5:
				if(c=='*')
					state=6;
				else{
					fprintf(fp2,"\n/%c: invalid lexeme",c);
					state=0;
				}
				break;
			case 6: 
				if(c=='*')
					state=7;
				break;
			case 7:
				if(c=='*'); 
				else if(c=='/')
					state=0;
				else
					state=6;
				break;

		}
	}
	if(state==6)   
	    fprintf(fp2,"\ncomment did not close");
	fclose(fp1);
	fclose(fp2);
	for(int i=0; i<20&&strcmp(st[i],"");++i)
    	printf("\n%s",st[i]);
	return 0;
}