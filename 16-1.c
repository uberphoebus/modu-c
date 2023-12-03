#include <stdio.h>

char copy_str(char *dest, char *src);
struct Books {
    char name[30];
    char auth[30];
    char publ[30];
    int borrowed;
};

struct test {
    int a, b;
};

int main() {
    struct Books book_list[3];

    // for (int i = 0; i < 3; i++) {
    //     printf("book %d info input : ", i);
    //     scanf("%s%s%s", book_list[i].name, book_list[i].auth,
    //           book_list[i].publ);
    //     book_list[i].borrowed = 0;
    // }

    // for (int i = 0; i < 3; i++) {
    //     printf("-----------------------------\n");
    //     printf("[book info] %s\n", book_list[i].name);
    //     printf("author    : %s\n", book_list[i].auth);
    //     printf("publisher : %s\n", book_list[i].publ);

    //     if (book_list[i].borrowed == 0) {
    //         printf("not borrowed\n");
    //     } else {
    //         printf("borrowed\n");
    //     }
    // }

    struct test st;
    struct test *ptr;
    ptr = &st;

    (*ptr).a = 1; // *ptr.a = 1 -> wrong
    (*ptr).b = 2;
    ptr->a = 3;
    ptr->b = 4;
    printf("st.a = %d\n", st.a);
    printf("st.b = %d\n", st.b);

    return 0;
}

char copy_str(char *dest, char *src) {
    while (*src) {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
    return 1;
}