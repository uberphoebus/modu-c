#include <stdio.h>
#include <stdlib.h>

struct Somthing {
    int a, b;
};

int main() {

    // struct array malloc

    struct Somthing *arr;
    int size, i;

    printf("struct arr size : ");
    scanf("%d", &size);

    arr = (struct Somthing *)malloc(sizeof(struct Somthing) * size);

    for (i = 0; i < size; i++) {
        printf("arr[%d].a : ", i);
        scanf("%d", &arr[i].a);
        printf("arr[%d].b : ", i);
        scanf("%d", &arr[i].b);
    }

    for (i = 0; i < size; i++) {
        printf("arr[%d].a : %d, arr[%d].b : %d\n", i, arr[i].a, i, arr[i].b);
    }
    free(arr);

    return 0;
}