#include <stdio.h>

// marcro functions : done before compile
#define square(x) (x) * (x)
#define RADTODEG(x) (x) * 57.295
#define PrintVariableName(var) printf(#var "\n");
#define AddName(x, y) x##y

// inline functions -> sim with macro, but sim with normal functinos
inline int square2(int a) { return a * a; };

int main() {
    printf("square(3) : %d\n", square(3 + 1));
    printf("5 rad 는 : %f 도\n", RADTODEG(5));

    int a = 10;
    PrintVariableName(a);

    int AddName(a, b);
    ab = 3;
    printf("%d\n", ab);

    printf("inline square : %d\n", square2(3));

    return 0;
}

// __inline int square2(int a) { return a * a; }
