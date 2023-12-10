#include <stdio.h>
#include <string.h>

void print_strings(char *str1, char *str2, char *str3);

int main() {
    char str1[50] = "I love Chewing C hahaha";
    char str2[50];
    char str3[50];

    // memcpy(dst, src, len)
    memcpy(str2, str1, strlen(str1) + 1);
    memcpy(str3, "hello", 6);
    print_strings(str1, str2, str3);

    // memmove(dst, src, len) -> copies but mem can be covered
    memmove(str1 + 23, str1 + 17, 6);
    print_strings(str1, str2, str3);

    // memcmp(mem1, mem2, len)
    int arr1[10] = {1, 2, 3, 4, 5};
    int arr2[10] = {1, 2, 3, 4, 5};
    if (memcmp(arr1, arr2, 5) == 0) {
        printf("arr1 == arr2\n");
    } else {
        printf("arr1 != arr2\n");
    }

    return 0;
}

void print_strings(char *str1, char *str2, char *str3) {
    printf("str1 : %s \n", str1);
    printf("str2 : %s \n", str2);
    printf("str3 : %s \n", str3);
}