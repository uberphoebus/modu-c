#include "18-1-book_function.h"
#include "18-1-str.c"
#include <stdio.h>

int add_book(char (*book_name)[30], char (*auth_name)[30],
             char (*publ_name)[30], int *borrowed, int *num_total_book) {
    printf("[add] title     : ");
    scanf("%s", book_name[*num_total_book]);
    printf("[add] author    : ");
    scanf("%s", auth_name[*num_total_book]);
    printf("[add] publisher : ");
    scanf("%s", publ_name[*num_total_book]);

    borrowed[*num_total_book] = 0;
    printf("[add] done!\n\n");
    (*num_total_book)++;

    return 0;
}

int search_book(char (*book_name)[30], char (*auth_name)[30],
                char (*publ_name)[30], int *num_total_book) {
    int user_input;
    char user_search[30];

    printf("[search] input search category\n");
    printf("1. title\n");
    printf("2. author\n");
    printf("3. publisher\n");
    scanf("%d", &user_input);
    printf("[search] input search keyword : ");
    scanf("%s", &user_search);
    printf("[search] search result\n");
    if (user_input == 1) {
        for (int i = 0; i < num_total_book; i++) {
            if (compare(book_name[i], user_search)) {
                printf("[search] num : %d | title : %s | author : %s | "
                       "publisher : %s\n",
                       i, book_name[i], auth_name[i], publ_name[i]);
            }
        }
    } else if (user_input == 2) {
        for (int i = 0; i < num_total_book; i++) {
            if (compare(auth_name[i], user_search)) {
                printf("[search] num : %d | title : %s | author : %s | "
                       "publisher : %s\n",
                       i, book_name[i], auth_name[i], publ_name[i]);
            }
        }
    } else if (user_input == 3) {
        for (int i = 0; i < num_total_book; i++) {
            if (compare(publ_name[i], user_search)) {
                printf("[search] num : %d | title : %s | author : %s | "
                       "publisher : %s\n",
                       i, book_name[i], auth_name[i], publ_name[i]);
            }
        }
    }
    return 0;
}

int borrowed_book(int *borrowed) {
    int book_num;
    printf("[borrow] input num to borrow\n");
    printf("[borrow] book num : ");
    scanf("%d", &book_num);

    if (borrowed[book_num] == 1) {
        printf("[borrow] already borrowed\n");
    } else {
        printf("[borrow] successfuly borrowed\n");
        borrowed[book_num] = 1;
    }
    return 0;
}

int return_book(int *borrowed) {
    int num_book;

    printf("[return] book to return\n");
    printf("[return] book num : ");
    scanf("%d", &num_book);

    if (borrowed[num_book] == 0) {
        printf("[return] already returned\n");
    } else {
        borrowed[num_book] = 0;
        printf("[return] successfuly returned\n");
    }
    return 0;
}