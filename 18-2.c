#include "18-2-human.c"
#include <stdio.h>
int main() {
    struct Human Lee = Create_Human("Lee", 40, MALE);

    Print_Human(&Lee);

    return 0;
}