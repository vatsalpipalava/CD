%{ 
%} 

%% 
"<"[^>]*> {printf("%s\n", yytext); } /* if anything enclosed in these <> occur print text*/ 
. ; // else do nothing 
%% 

int yywrap(){} 
int main(int argc, char*argv[]) 
{ 
    // Open tags.txt in read mode extern 
    FILE *yyin = fopen("tags.txt","r"); // The function that starts the analysis
    yylex(); 
    return 0; 
} 