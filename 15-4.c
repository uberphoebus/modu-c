/*
1. 책 추가 기능(100권, 제목, 저자, 출판사)
2. 제목, 저자, 출판사 검색
3. 대여
4. 반납
*/

#include <stdio.h>

int add_book(char (*book_name)[30], char (*auth_name)[30],
             char (*publ_name)[30], int *borrowed, int *num_total_book);
int compare(char *str1, char *str2);
int search_book(char (*book_name)[30], char (*auth_name)[30],
                char (*publ_name)[30], int *num_total_book);
int borrowed_book(int *borrowed);
int return_book(int *borrowed);

int main() {
    int user_choice;
    int num_total_book = 0;
    char book_name[100][30], auth_name[100][30], publ_name[100][30];
    int borrowed[100];

    while (1) {
        printf("========================\n");
        printf("== 도서 관리 프로그램 ==\n");
        printf("메뉴를 선택하세요 \n");
        printf("1. 책을 새로 추가하기 \n");
        printf("2. 책을 검색하기 \n");
        printf("3. 책을 빌리기 \n");
        printf("4. 책을 반납하기 \n");
        printf("5. 프로그램 종료 \n");

        printf("명령 선택 : ");
        scanf("%d", &user_choice);
        printf("========================\n\n");

        if (user_choice == 1) {
            add_book(book_name, auth_name, publ_name, borrowed,
                     &num_total_book);
        } else if (user_choice == 2) {
            search_book(book_name, auth_name, publ_name, num_total_book);
        } else if (user_choice == 3) {
            borrowed_book(borrowed);
        } else if (user_choice == 4) {
            return_book(borrowed);
        } else if (user_choice == 5) {
            break;
        }
    }
}

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

int compare(char *str1, char *str2) {
    while (*str1) {
        if (*str1 != *str2) {
            return 0;
        }
        str1++;
        str2++;
    }
    if (*str2 == '\0')
        return 1;

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