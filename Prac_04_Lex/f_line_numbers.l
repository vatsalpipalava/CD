%{ 
int line_number = 1;
%}
 
line .*\n 
 
%% 
{line} { printf("%10d %s", line_number++, yytext); } 
%% 

int yywrap(){} 
int main(int argc, char*argv[]) 
{ 
    extern FILE *yyin; 
    yyin = fopen("c:\\practical.txt", "r");
    yylex(); 
}