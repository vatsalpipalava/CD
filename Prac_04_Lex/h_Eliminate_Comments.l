% 
{ 
    #include<stdio.h> 
%} 
 
%% 
\/\/(.*) {}; 
\/\*(.*\n)*.*\*\/ {}; 
%% 
 
int yywrap() { 
    return 1; 
} 
 
int main() { 
    yyin=fopen("c:\\practical.txt", "r"); 
    yyout=fopen("C:\\out.c","w"); yylex();
    return 0; 
}