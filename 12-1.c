#include <stdio.h>

int main() {
    int *p;
    int a = 2;
    int b = 4;
    p = &a; // alloc a addr to pointer p

    printf("addr of p : %p\n", p);
    printf("addr of &a : %p\n", &a);

    printf("value of a : %d\n", a);
    printf("value of *p : %d\n", *p);

    p = &a;
    *p = 2;
    p = &b;
    *p = 4;
    printf("a : %d \n", a);
    printf("b : %d \n", b);

    return 0;
}