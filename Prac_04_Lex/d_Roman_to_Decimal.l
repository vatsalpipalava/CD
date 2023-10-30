%{ 
    #include <stdio.h> 
    int romanToDecimal(char *roman); 
%} 
 
%% 
[IVXLCDM]+
{ 
    int decimal = romanToDecimal(yytext);
    printf("%s => %d\n", yytext, decimal); 
} 
.|\n; 
%% 
 
int main(int argc, char* argv[]) 
{ 
    yylex();
    return 0; 
} 
 
int romanToDecimal(char *roman) { 
    int values [] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}; 
    char* numerals [] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}; 
 
    int result = 0; 
    int i = 0;
    while (*roman) { 
        for (int j = 0; j < 13; j++) { 
            if (strncmp(roman, numerals[j], strlen(numerals[j])) == 0) {
                result += values[j];
                roman += strlen(numerals[j]);
                break; 
            } 
        } 
    } 
    return result; 
} 