#include <stdio.h>
#include <string.h>

#define SUCCESS 1
#define FAILED 0

int E(), Edash();

const char *cursor;
char string[64];

int main()
{
    printf("Enter a String : ");
    scanf("%s", string);

    cursor = string;
    puts("");
    puts("Start Action");
    puts("----------------------");

    if (E() && *cursor == '\0')
    {
        puts("--------------------------------------------");
        printf("String SUCCESSFULLY Parsed");
        return 0;
    }
    else
    {
        puts("--------------------------------------------");
        printf("String Parsing FAILED");
        return 1;
    }
}

// Grammer Rule : E -> iE'
int E()
{
    if (*cursor == 'i')
    {
        printf("%-16s E -> iE'\n", cursor);
        cursor++;
        if (Edash())
        {
            return SUCCESS;
        }
        else
        {
            return FAILED;
        }
    }
    else
    {
        return FAILED;
    }
}

// Grammer Rule : E' -> +iE' | $
int Edash()
{
    if (*cursor == '+')
    {
        cursor++;
        if (*cursor == 'i')
        {
            printf("%-16s E' -> +iE'\n", cursor);
            cursor++;
            if (Edash())
            {
                return SUCCESS;
            }
            else
            {
                return FAILED;
            }
        }
        else
        {
            return FAILED;
        }
    }
    else
    {
        printf("%-16s E' -> $\n", cursor);
        return SUCCESS;
    }
}