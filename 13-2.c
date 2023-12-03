#include <stdio.h>

// prototype
int change_val(int *pi);
int swap(int *a, int *b);
int add_number(int *parr);
int max_number(int *parr);

int main() {
    // pointer function
    int i, j;

    i = 0;
    printf("i addr = %p\n", &i);
    printf("before call i = %d\n", i);
    change_val(&i);
    printf("after call  i = %d\n", i);

    i = 3;
    j = 5;
    printf("before swap : i = %d, j = %d\n", i, j);
    swap(&i, &j);
    printf("after swap  : i = %d, j = %d\n", i, j);

    // array function
    int arr[3] = {10, 11, 15};
    add_number(arr);
    printf("arr = %d, %d, %d\n", arr[0], arr[1], arr[2]);

    int arr2[10] = {100, 50, 102, 300, 900, 700, 550, 400, 800, 600};
    printf("max num = %d\n", max_number(arr2));

    return 0;
}

int change_val(int *pi) {
    printf("----- in change_val start -----\n");
    printf("pi  = %p\n", pi);
    printf("*pi = %d\n", *pi);

    *pi = 3;
    printf("----- in change_val end   -----\n");
    return 0;
}

int swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

int add_number(int *parr) {
    int i;
    for (i = 0; i < 3; i++) {
        parr[i]++;
    }
    return 0;
}

int max_number(int *parr) {
    int max = parr[0];
    for (int i = 1; i < 10; i++) {
        if (max < parr[i]) {
            max = parr[i];
        }
    }
    return max;
}