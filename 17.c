#include <stdio.h>

int function1() {
    static int how_many_called = 0;
    how_many_called++;
    printf("function1 called : %d\n", how_many_called);
    return 0;
}

int function2() {
    static int how_many_called = 0;
    how_many_called++;
    printf("function2 called :   %d\n", how_many_called);
    return 0;
}

int global = 3;

int main() {
    function1();
    function2();
    function1();
    function2();
    function2();
    function2();
    function1();
    function1();
    function2();

    int i;
    char *str = "Hello, Baby";
    char arr[20] = "WHATTHEHECK";

    printf("global : %p\n", &global);
    printf("i      : %p\n", &i);
    printf("str    : %p\n", &str);
    printf("arr    : %p\n", arr);

    return 0;
}
