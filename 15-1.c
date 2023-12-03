#include <stdio.h>

int str_length(char *str);

int main() {
    // null chars
    char null_1 = '\0';
    char null_2 = 0;
    char null_3 = (char)NULL;

    char not_null = '0';

    printf("NULL ASCII 1 = %d\n", null_1);
    printf("NULL ASCII 2 = %d\n", null_2);
    printf("NULL ASCII 3 = %d\n", null_3);
    printf("'0' ASCII    = %d\n", not_null);
    printf("\n");

    char sentence_1[4] = {'P', 's', 'i', '\0'};
    char sentence_2[4] = {'P', 's', 'i', 0};
    char sentence_3[4] = {'P', 's', 'i', (char)NULL};
    char sentence_4[4] = {"Psi"};
    char sentence_5[4] = "Psi";

    printf("sentence_1 : %s\n", sentence_1);
    printf("sentence_2 : %s\n", sentence_2);
    printf("sentence_3 : %s\n", sentence_3);
    printf("sentence_4 : %s\n", sentence_4);
    printf("sentence_5 : %s\n", sentence_5);
    printf("\n");

    char word[] = {"long sentence"};
    char *str = word;
    printf("str : %s\n", str);
    word[0] = 'a';
    word[1] = 'b';
    word[2] = 'c';
    word[3] = 'd';
    printf("str : %s\n", str);

    char str2[] = "What is your name?";
    printf("str length = %d\n", str_length(str2));

    return 0;
}

int str_length(char *str) {
    int i = 0;
    while (str[i]) {
        i++;
    }
    return i;
}