#include <stdio.h>
int main() {
    int a;
    int b;
    const int *pa = &a;

    // *pa = 3; // wrong
    pa = &b;

    // pointer add
    int c;
    char d;
    double e;
    int *pc = &c;
    char *pd = &d;
    double *pe = &e;

    printf("pc       = %p\n", pc);
    printf("(pc + 1) = %p\n", pc + 1); // pc + int(4)
    printf("pd       = %p\n", pd);
    printf("(pd + 1) = %p\n", pd + 1); // pd + char(1)
    printf("pe       = %p\n", pe);
    printf("(pe + 1) = %p\n", pe + 1); // pe + double(8)

    // array & pointer
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *parr = &arr[0];
    for (int i = 0; i < 10; i++) {
        printf("arr[%d] addr = %p\n", i, &arr[i]);
    }
    for (int i = 0; i < 10; i++) {
        printf("arr[%d] addr = %p | ", i, &arr[i]);
        printf("(parr + %d)  = %p", i, (parr + i));
        if (&arr[i] == (parr + i)) {
            printf(" --> same\n");
        }
    }

    printf("arr         = %p\n", arr);
    printf("arr[0] addr = %p\n", &arr[0]);
    printf("sizeof(arr)  : %d \n", sizeof(arr));
    printf("sizeof(parr) : %d \n", sizeof(parr));

    printf("arr[3]     = %d\n", arr[3]);
    printf("*(arr + 3) = %d\n", *(arr + 3));

    return 0;
}