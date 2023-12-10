#include <stdio.h>
int main() {
    FILE *fp = fopen("some_data.txt", "r");
    char data[10];
    char c;

    if (fp == NULL) {
        printf("file open error ! \n");
        return 0;
    }

    fgets(data, 5, fp);
    printf("입력 받은 데이터 : %s \n", data);

    c = fgetc(fp);
    printf("그 다음에 입력 받은 문자 : %c \n", c);

    fseek(fp, -1, SEEK_CUR);

    c = fgetc(fp);
    printf("그렇다면 무슨 문자가? : %c \n", c);

    fseek(fp, -1, SEEK_END);
    c = fgetc(fp);
    printf("파일 마지막 문자 : %c \n", c);
    fclose(fp);

    fp = fopen("some_data.txt", "r+");
    char data2[100];
    fgets(data2, 100, fp);
    printf("curr data : %s\n", data2);
    fseek(fp, 5, SEEK_SET);
    fputs("is nothing on this file", fp);
    fclose(fp);

    fp = fopen("alpha.txt", "r+");
    char f;
    if (fp == NULL) {
        printf("파일 열기를 실패하였습니다! \n");
        return 0;
    }

    while ((c = fgetc(fp)) != EOF) {
        if (65 <= c && c <= 90) {
            fseek(fp, -1, SEEK_CUR);
            fputc(c + 32, fp);
            fseek(fp, 0, SEEK_CUR); // fflush(fp);
        } else if (97 <= c && c <= 122) {
            fseek(fp, -1, SEEK_CUR);
            fputc(c - 32, fp);
            fseek(fp, 0, SEEK_CUR); // fflush(fp);
        }
    }
    fclose(fp);

    fp = fopen("some_data.txt", "r+");
    char data3[100];
    if (fp == NULL) {
        printf("파일 열기 오류! \n");
        return 0;
    }

    printf("---- 입력 받은 단어들 ---- \n");

    // fgets -> \n vs. fscanf -> \t, \n
    while (fscanf(fp, "%s", data) != EOF) {
        printf("%s \n", data);
    }
    fclose(fp);

    return 0;
}