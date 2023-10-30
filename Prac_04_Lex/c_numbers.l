% 
{ 
    #include<stdio.h>
    int num_count=0; 
%} 

num [0-9]+

%% 
{num} {num_count++; printf("%s",yytext);} 
%% 

int yywrap(void){}
int main() 
{ 
    yyin = fopen("c:\\practical.txt", "r");
    yylex(); 
    printf("\nTotal of numbers: %d",num_count); 
}