#include <stdio.h>

struct employee {
    int age;
    int salary;
};

struct company {
    struct employee data;
    char name[10];
};

struct AA {
    int i;
};

struct obj {
    char name[20];
    int x, y;
} Ball;

int Print_Obj_Status(struct obj OBJ);
char copy_str(char *dest, char *src);

struct AA function(int j);

struct HUMAN {
    int age;
    int height;
    int weight;
    int gender;
};
int Print_Status(struct HUMAN human);

enum { RED, BLUE, WHITE, BLACK };

int main() {
    // struct in struct
    struct company Kim;

    Kim.data.age = 31;
    Kim.data.salary = 3000000;

    printf("Kim age    = %d\n", Kim.data.age);
    printf("Kim salary = %d\n", Kim.data.salary);

    // struct return function
    struct AA a;
    a = function(10);
    printf("a.i = %d\n", a.i);

    // declare1
    Ball.x = 3;
    Ball.y = 4;
    copy_str(Ball.name, "RED BALL");
    Print_Obj_Status(Ball);

    // declare2
    struct HUMAN Adam = {31, 182, 75, 0};
    struct HUMAN Eve = {27, 166, 48, 1};

    Print_Status(Adam);
    Print_Status(Eve);

    int palette = RED;
    switch (palette) {
    case RED:
        printf("palette : RED\n");
        break;
    case BLUE:
        printf("palette : BLUE\n");
        break;
    case WHITE:
        printf("palette : WHITE\n");
        break;
    case BLACK:
        printf("palette : BLACK\n");
        break;
    }

    return 0;
}

struct AA function(int j) {
    struct AA A;
    A.i = j;
    return A;
}

int Print_Obj_Status(struct obj OBJ) {
    printf("location of %s\n", OBJ.name);
    printf("( %d , %d ) \n", OBJ.x, OBJ.y);
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

int Print_Status(struct HUMAN human) {
    if (human.gender == 0) {
        printf("MALE \n");
    } else {
        printf("FEMALE \n");
    }
    printf("AGE : %d / Height : %d / Weight : %d \n", human.age, human.height,
           human.weight);
    if (human.gender == 0 && human.height >= 180) {
        printf("HE IS A WINNER!! \n");
    } else if (human.gender == 0 && human.height < 180) {
        printf("HE IS A LOSER!! \n");
    }
    printf("------------------------------------------- \n");
    return 0;
}