%  
{   
    #include<studio.h>
    int n_chars=0;  
    int n_lines=0;
    int n_words = 0;  
%}  
  
%%  
  
\n {n_chars++;n_lines++;}  
[^ \n\t]+ {n_words++, n_chars=n_chars+yyleng;} 
 
. {n_chars++;}  
  
%%  
  
int yywrap(){}  
int main(int argc[],char *argv[])  
{  
    yyin=fopen("c:\\practical.txt", "r");
    yylex();  
    printf("no of characters: %d",n_chars);
    printf("\n"); 
    printf("no of lines: %d",n_lines);
    printf("\n"); 
    printf("no of words: %d",n_words);
    printf("\n");  
    return 0;  
} 
