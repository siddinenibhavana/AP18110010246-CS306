%{ 
    int vownum=0; 
    int consnum=0; 
%} 
  
%% 
[aeiouAEIOU] {vownum++;} 
[a-zA-Z] {consnum++;} 
%% 
int yywrap(){} 
int main() 
{ 
    printf("Enter the string of vowels and consonants:"); 
    yylex(); 
    printf("Number of vowels are:: %d\n", vownum); 
    printf("Number of consonants are::%d\n", consnum); 
    return 0; 
}  