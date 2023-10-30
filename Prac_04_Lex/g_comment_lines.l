%{
    #include<stdio.h> 
    int count = 0; 
%} 
 
%% 
"/*"[.]*"*/" 	{count++;} "/*" 	{BEGIN C;} 
<C>"*/" 	{BEGIN 0; count++;} 
<C>\n {;} 
<C>. {;} 
\/\/.* 	{count++;} 
%% 
 
void main() 
{ 
    char file[] = "data.c"; 
    yyin = fopen("c:\\practical.txt", "r");
    yylex(); 
    printf("Number of comment lines in c file %s is %d\n", file, count);
} 
 
int yywrap() {
    return 1; 
}