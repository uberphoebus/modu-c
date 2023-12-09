#include "18-1-book_function.c"
#include <stdio.h>

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
