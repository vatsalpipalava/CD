#include <stdio.h>
#include <conio.h>

int ninputs;

// Function declaration
int check(char, int);
int dfa[10][10];
char c[10], string[10];

int main()
{
    int nstates, nfinals;
    int f[10];
    int i, j, s = 0, final = 0;

    printf("Enter the number of states that your DFA consists of: ");
    scanf("%d", &nstates);
    printf("Enter the number of input symbols that the DFA has: ");
    scanf("%d", &ninputs);

    printf("\nEnter input symbols:\n");
    for (i = 0; i < ninputs; i++)
    {
        printf("Input %d: ", i + 1);
        printf("%c", c[i] = getch());
    }

    printf("\nEnter the number of final states: ");
    scanf("%d", &nfinals);

    for (i = 0; i < nfinals; i++)
    {
        printf("Final state %d: q", i + 1);
        scanf("%d", &f[i]);
    }

    printf("\nDefine transition rules as (initial state, input symbol) = final state:\n");
    for (i = 0; i < nstates; i++)
    {
        for (j = 0; j < ninputs; j++)
        {
            printf("(q%d, %c) = q", i, c[j]);
            scanf("%d", &dfa[i][j]);
        }
    }

    do
    {
        i = 0;
        printf("\n\nEnter Input String: ");
        scanf("%s", string);
        s = 0;

        while (string[i] != '\0')
        {
            if ((s = check(string[i++], s)) < 0)
                break;
        }

        final = 0;
        for (i = 0; i < nfinals; i++)
        {
            if (f[i] == s)
            {
                final = 1;
                break;
            }
        }

        if (final == 1)
            printf("Valid string\n");
        else
            printf("Invalid string\n");

        printf("Do you want to continue? (y/n): ");
    } while (getch() == 'y');

    getch();
    return 0;
}

int check(char b, int d)
{
    int j;
    for (j = 0; j < ninputs; j++)
    {
        if (b == c[j])
        {
            return dfa[d][j];
        }
    }
    return -1;
}
