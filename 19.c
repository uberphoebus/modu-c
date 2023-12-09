#include <stdio.h>
int read_char(void *p, int byte);

int main(int argc, char **argv) {
    int arr[1] = {0x12345678};

    printf("%x \n", arr[0]);
    read_char(arr, 4);

    int i;
    printf("받은 인자의 개수 : %d \n", argc);

    for (i = 0; i < argc; i++) {
        printf("이 프로그램이 받은 인자 : %s \n", argv[i]);
    }
}

int read_char(void *p, int byte) {
    do {
        printf("%x \n", *(char *)p);
        byte--;

        p = (char *)p + 1;
    } while (p && byte);

    return 0;
}