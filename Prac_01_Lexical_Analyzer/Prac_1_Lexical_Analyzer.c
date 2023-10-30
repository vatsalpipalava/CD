#include <stdio.h>
#include <string.h>
int isOperator(char c[])
{
    if (c[0] == '+' || c[0] == '-' || c[0] == '*' ||
        c[0] == '/' || c[0] == '>' || c[0] == '<' ||
        c[0] == '=')
        return 1;
    else
    {
        return 0;
    }
}
int isDelimeter(char c[])
{
    if (c[0] == ',' || c[0] == ';')
        return 1;
    else
    {
        return 0;
    }
}
int isIdentifier(char c[])
{
    if ((c[0] >= 'a' && c[0] <= 'z') || (c[0] >= 'A' && c[0] <= 'Z') || (c[0] == '_'))
        return 1;
    else
    {
        return 0;
    }
}
int isKeyword(char *str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else") || !strcmp(str, "while") || !strcmp(str, "do") ||
        !strcmp(str, "break") || !strcmp(str, "continue") || !strcmp(str, "int") || !strcmp(str, "double") ||
        !strcmp(str, "float") || !strcmp(str, "return") || !strcmp(str, "char") || !strcmp(str, "case") ||
        !strcmp(str, "char") || !strcmp(str, "sizeof") || !strcmp(str, "long") || !strcmp(str, "short") ||
        !strcmp(str, "typedef") || !strcmp(str, "switch") || !strcmp(str, "unsigned") || !strcmp(str, "void") || !strcmp(str, "static") || !strcmp(str, "struct") || !strcmp(str, "goto"))
        return 1;
    else
    {
        return 0;
    }
}
int isConstant(char *str)
{
    int i, len = strlen(str);
    for (i = 0; i < len; i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != '.' || (str[i] == '-' && i > 0))
        {
            return (0);
        }
        else
        {
            return 1;
        }
    }
}
int main()
{
    char str[100];
    char c;
    int i = 0;
    FILE *file = fopen("temp.txt", "r");
    while ((c = fgetc(file)) != EOF)
    {
        if (c != ' ')
        {
            // printf("%c\n", c);
            str[i] = c;
            i++;
        }
        else
        {
            str[i] = '\0';
            // printf("%s\n", str);
            if (isOperator(str) == 1)
            {
                printf("'%s' IS A OPERATOR\n", str);
            }
            else if (isKeyword(str) == 1)
            {
                printf("'%s' IS A KEYWORD\n", str);
            }
            else if (isIdentifier(str) == 1)
            {
                printf("'%s' IS A IDENTIFIRE\n", str);
            }
            else if (isDelimeter(str) == 1)
            {
                printf("'%s' IS A DELIMETER\n", str);
            }
            else if (isConstant(str) == 1)
            {
                printf("'%s' IS A CONSTANT\n", str);
            }
            i = 0;
        }
    }
    return 0;
}