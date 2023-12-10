#include <stdio.h>

// stream : pipe between other abstract devices

int main() {
    FILE *fp;                 // make FILE struct
    fp = fopen("a.txt", "w"); // stream pointer return
    if (fp == NULL) {         // not opened
        printf("write error!\n");
        return 0;
    }
    fputs("abcdefg", fp); // write on stream
    fclose(fp);           // close(free)

    fp = fopen("a.txt", "r");
    char buf[20];
    if (fp == NULL) {
        printf("read error!\n");
        return 0;
    }
    fgets(buf, 20, fp); // pointer, bytes, stream
    printf("content : %s\n", buf);
    fclose(fp);

    fp = fopen("a.txt", "r");
    char c;
    int size = 0;

    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
        size++;
    }
    fclose(fp);
    printf("\nsize : %d bytes\n", size);

    // position indicator
    fp = fopen("a.txt", "r");
    fgetc(fp);
    fgetc(fp);
    fgetc(fp);
    fgetc(fp);
    fseek(fp, 2, SEEK_SET);
    printf("from start : %c\n", fgetc(fp));
    fclose(fp);

    return 0;
}