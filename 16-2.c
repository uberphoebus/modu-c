#include <stdio.h>

struct TEST {
    int c;
    int *pointer;
    char str[20];
    int i;
};

struct TEST2 {
    int age;
    int gender;
    char name[20];
};

int add_one(int *a);
char copy_str(char *dest, char *src);
int set_human(struct TEST2 *a, int age, int gender, const char *name);

int main() {
    struct TEST t;
    struct TEST *pt = &t;
    int i = 0;

    (*pt).c = 0;
    printf("t.c = %d\n", t.c);

    pt->c = 1;
    printf("t.c = %d\n", t.c);

    t.pointer = &i;
    *t.pointer = 3;
    printf("i = %d\n", i);

    *pt->pointer = 4;
    printf("i = %d\n", i);

    printf("t.c = %d\n", t.c);
    add_one(&t.c);
    printf("t.c = %d\n", t.c);
    add_one(&pt->c);
    printf("t.c = %d\n", t.c);

    struct TEST a, b;
    b.i = 3;
    copy_str(b.str, "hello, world");
    a = b;

    printf("a.str = %s\n", a.str);
    printf("a.i   = %d\n", a.i);

    struct TEST2 human;
    set_human(&human, 10, 1, "lee");
    printf("age = %d, gender : %d, name : %s\n", human.age, human.gender,
           human.name);

    return 0;
}

int add_one(int *a) {
    *a += 1;
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

int set_human(struct TEST2 *a, int age, int gender, const char *name) {
    a->age = age;
    a->gender = gender;
    copy_str(a->name, name);
    return 0;
}