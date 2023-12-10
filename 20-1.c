#include <stdio.h>
#include <stdlib.h>

void get_average(int **arr, int numStudent, int numSubject);

int main(int argc, char **argv) {

    int i, j, input;
    int subject = 3;
    int students = 2;
    int **arr; // arr[subject][students]

    arr = (int **)malloc(sizeof(int *) * subject);
    for (i = 0; i < subject; i++) {
        arr[i] = (int *)malloc(sizeof(int) * students);
    }

    for (i = 0; i < subject; i++) {
        printf("subject %d score -----\n", i);
        for (j = 0; j < students; j++) {
            printf("student %d score : ", j);
            scanf("%d", &input);
            arr[i][j] = input;
        }
    }

    get_average(arr, students, subject);

    for (i = 0; i < subject; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

void get_average(int **arr, int numStudent, int numSubject) {
    int i, j, sum;

    for (i = 0; i < numSubject; i++) {
        sum = 0;
        for (j = 0; j < numStudent; j++) {
            sum += arr[i][j];
        }
        printf("subject %d avg score = %d\n", i, sum / numStudent);
    }
}