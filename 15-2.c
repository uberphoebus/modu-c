#include <stdio.h>

int main() {
    // buffer
    int num;
    char c;
    char str[30];

    printf("input int : ");
    scanf("%d", &num);
    printf("num : %d\n", num);

    char ch = getchar(); // returns one char from stdin(NULL)
    printf("getchar : %c\n", ch);
    printf("input char : ");
    scanf("%c", &c);
    printf("char : %c\n", c);
    printf("input str : ");
    scanf("%s", &str);
    printf("str : %s\n", str);

    return 0;
}