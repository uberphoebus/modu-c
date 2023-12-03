#include <stdio.h>

int copy_str(char *dest, char *src);
int stradd(char *dest, char *src);
int compare(char *str1, char *str2);

int main() {
    // string literal : fixed value in source code -> read only
    char str[] = "sentence"; // array of chars -> changable
    char *pstr = "sentence";
    str[1] = 'a';
    // pstr[1] = 'a';

    printf("str  : %s\n", str);
    printf("pstr : %s\n", pstr);
    printf("\n");

    // copy string
    char str1[] = "hello";
    char str2[] = "hi";
    printf("before copy : %s\n", str1);
    copy_str(str1, str2);
    printf("after copy  : %s\n", str1);
    printf("\n");

    // concat strings
    char str3[100] = "hello my name is ";
    char str4[] = "Psi";
    printf("before add : %s\n", str3);
    stradd(str3, str4);
    printf("after add  : %s\n", str3);

    // compare strings
    char str5[20] = "hello every1";
    char str6[20] = "hello everyone";
    char str7[20] = "hello every1 hi";
    char str8[20] = "hello every1";

    printf("str5 == str6 : %d\n", compare(str5, str6));
    printf("str5 == str7 : %d\n", compare(str5, str7));
    printf("str5 == str8 : %d\n", compare(str5, str8));

    return 0;
}

int copy_str(char *dest, char *src) {
    while (*src) { // while NULL
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
    return 1;
}

int stradd(char *dest, char *src) {
    while (*dest) {
        dest++;
    }
    while (*src) {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';

    return 1;
}

int compare(char *str1, char *str2) {
    while (*str1) {
        if (*str1 != *str2) {
            return 0;
        }
        str1++;
        str2++;
    }
    if (*str2 == '\0') {
        return 1;
    }
    return 0;
}
