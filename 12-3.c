#include <stdio.h>
int main() {
    int arr[3] = {1, 2, 3};
    int *parr;
    parr = arr; // parr = &arr[0]
    printf("arr[1]  : %d \n", arr[1]);
    printf("parr[1] : %d \n", parr[1]);

    int arr2[10] = {100, 98, 97, 95, 89, 76, 92, 96, 100, 99};
    int *parr2 = arr2;
    int sum = 0;

    while (parr2 - arr2 <= 9) {
        sum += (*parr2);
        parr2++; // parr2 + int(4)
    }
    printf("sum = %d\n", sum / 10);

    int a;
    int *pa;
    int **ppa;
    pa = &a;
    ppa = &pa;
    a = 3;

    printf("a    = %d | &a   = %p\n", a, &a);
    printf("*pa  = %d | pa   = %p | &pa = %p\n", *pa, pa, &pa);
    printf("**pa = %d | *ppa = %p | ppa = %p\n", **ppa, *ppa, ppa);

    // 2dim array
    int arr3[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printf("arr3[0]     : %p \n", arr3[0]);
    printf("&arr3[0][0] : %p \n", &arr3[0][0]);

    printf("arr3[1]     : %p \n", arr3[1]);
    printf("&arr3[1][0] : %p \n", &arr3[1][0]);

    printf("total size = %d\n", sizeof(arr3)); // 24
    printf("total col  = %d\n",
           sizeof(arr3[0]) / sizeof(arr3[0][0]));                // 12 / 4 = 3
    printf("total row  = %d\n", sizeof(arr3) / sizeof(arr3[0])); // 24 / 12 = 2

    int(*parr3)[3]; // not **parr = arr
    parr3 = arr3;
    printf("parr3[1][2] = %d, arr3[1][2] = %d\n", parr3[1][2], arr3[1][2]);

    // pointer array
    int *arr4[3];
    int b = 1, c = 2, d = 3;
    arr4[0] = &b;
    arr4[1] = &c;
    arr4[2] = &d;

    printf("b = %d, *arr4[0] = %d\n", b, *arr4[0]);
    printf("c = %d, *arr4[1] = %d\n", c, *arr4[1]);
    printf("d = %d, *arr4[2] = %d\n", d, *arr4[2]);
    printf("&b = %p, arr4[0] = %p\n", &b, arr4[0]);

    return 0;
}