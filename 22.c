#include <stdio.h>

#pragma pack(1) // 구조체를 n바이트 단위로 정렬
#pragma once    // includes header once

struct HUMAN {
    int age;
    int height;
    int weight;
    int gender;
};

typedef struct HUMAN Human;

typedef int CAL_TYPE;

typedef struct SENSOR {
    int sensor_flag;
    int data;
} SENSOR;

int Print_Status(struct HUMAN Human);

struct Weird {
    char arr[2]; // char * 2 = 2
    int i;       // 4
};

int main() {
    // typedef struct
    Human Adam = {31, 182, 75, 0};
    Human Eve = {27, 166, 48, 1};

    Print_Status(Adam);
    Print_Status(Eve);

    // typedef types
    CAL_TYPE a = 10;
    CAL_TYPE b = 20;
    printf("%d\n", a + b);

    // volatile : ???
    volatile SENSOR *sensor;
    while (!(sensor->sensor_flag)) {
    }
    printf("data : %d\n", sensor->data);

    // pragma : 전처리기 명령
    struct Weird w;
    printf("size of a : %ld\n", sizeof(w)); // 2 + 4 != 8

    return 0;
}

int Print_Status(Human human) {
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