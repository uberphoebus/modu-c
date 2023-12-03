#include <stdio.h>

int pswap(int **pa, int **pb);
int add1_element(int (*arr)[2], int row);
int read_val(const int val);
int max(int a, int b);

int main() {
    // double pointer
    int a, b;
    int *pa, *pb;

    pa = &a;
    pb = &b;

    printf("pa pointing addr = %p\n", pa);
    printf("pa addr          = %p\n", &pa);
    printf("pb pointing addr = %p\n", pb);
    printf("pb addr          = %p\n", &pb);

    printf("call pswap start\n");
    pswap(&pa, &pb);
    printf("call pswap end\n");

    printf("pa pointing addr = %p\n", pa);
    printf("pa addr          = %p\n", &pa);
    printf("pb pointing addr = %p\n", pb);
    printf("pb addr          = %p\n", &pb);

    // 2dim array
    int arr[3][2] = {1, 2, 3, 4, 5, 6};
    add1_element(arr, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
        }
    }

    // const
    int c = 5;
    read_val(c);

    // function pointer
    int d, e;
    d = 10;
    e = 15;
    int (*pmax)(int, int);
    pmax = max;
    printf("max(a, b)  = %d\n", max(d, e));
    printf("pmax(a, b) = %d\n", pmax(d, e));

    return 0;
}

int pswap(int **ppa, int **ppb) {
    int *temp = *ppa;
    printf("ppa pointing addr = %p\n", ppa);
    printf("ppb pointing addr = %p\n", ppb);

    *ppa = *ppb;
    *ppb = temp;
    return 0;
}

int add1_element(int (*arr)[2], int row) { // int arr[][2]
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < 2; j++) {
            arr[i][j]++;
        }
    }
    return 0;
}

int read_val(const int val) {
    // val = 5; error
    return 0;
}

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
    return 0;
}