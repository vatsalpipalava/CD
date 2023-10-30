#include <stdio.h>
int main()
{
    int dfa = 0;
    char input[50];
    printf("Enter string : ");
    scanf("%s", input);

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (dfa == 0 && input[i] == 'a')
        {
            dfa = 1;
            printf("%c --> %d\n", input[i], dfa);
        }
        else if (dfa == 0 && input[i] == 'b')
        {
            dfa = 3;
            // printf("String Dose not match with RE..\n");
            // return 0;
        }
        else if (dfa == 1 && input[i] == 'b')
        {
            dfa = 1;
            printf("%c --> %d\n", input[i], dfa);
        }
        else if (dfa == 1 && input[i] == 'a')
        {
            dfa = 2;
            // printf("%c\n", input[i]);             //printf("%d\n", dfa);
            printf("%c --> %d\n", input[i], dfa);
        }
        else if (dfa == 2 && input[i] == 'b')
        {
            dfa = 3;
            // printf("String Dose not match with RE..\n");             // return 0;
        }
        else if (dfa == 2 && input[i] == 'a')
        {
            dfa = 3;
            // printf("String Dose not match with RE..\n");
            // return 0;
        }
    }
    if (dfa != 2)
    {
        printf("string not accepted..\n");
    }
    else
    {
        printf("string accepted..\n");
    }
    return 0;
}