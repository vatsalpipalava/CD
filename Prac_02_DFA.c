#include <stdio.h>

int main() {
    int dfa = 0, pos = 0;
    int length;
    char str[100];  // Static memory allocation with a maximum length of 100 characters

    printf("Enter the length you are entering: ");
    scanf("%d", &length);

    if (length > 100) {
        printf("Input length exceeds the maximum allowed length.\n");
        return 1;
    }

    printf("Enter the string: ");
    scanf("%s", str);
    printf("The string is %s\n", str);

    while (pos < length) {
        if (dfa == 0 && str[pos] == 'a') {
            dfa = 1;
            printf("The character %c\n", str[pos]);
            printf("The state %d\n", dfa);
            printf("The pos %d\n", pos);
            pos++;
        } else if (dfa == 0 && str[pos] == 'b') {
            dfa = 3;
            printf("The character %c\n", str[pos]);
            printf("The state %d\n", dfa);
            printf("The pos %d\n", pos);
            pos++;
        } else if (dfa == 1 && str[pos] == 'b') {
            printf("The character %c\n", str[pos]);
            printf("The state %d\n", dfa);
            printf("The pos %d\n", pos);
            pos++;
        } else if (dfa == 1 && str[pos] == 'a') {
            dfa = 2;
            printf("The character %c\n", str[pos]);
            printf("The state %d\n", dfa);
            printf("The pos %d\n", pos);
            pos++;
        } else if (dfa == 2 && (str[pos] == 'a' || str[pos] == 'b')) {
            dfa = 3;
            printf("The character %c\n", str[pos]);
            printf("The state %d\n", dfa);
            printf("The pos %d\n", pos);
            pos++;
            break;
        } else {

            break;

        }
    }

    if (dfa == 2 && pos == length) {

        printf("The String matches the regular expression ab*a\n");

    } else {

        printf("The String doesn't match the regular expression ab*a\n");
    }

    return 0;
}
