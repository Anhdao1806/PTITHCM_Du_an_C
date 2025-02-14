#include <stdio.h>
#include <stdlib.h> // Thêm thư viện để dùng system("clear")
#include "datatype.h"   // Thêm dòng này để nhận diện Book và Member
#include "function.h"

int main() {
    Book books[100];
    Member members[100];
    int bookCount = 0, memberCount = 0;
    int choice;
    loadBooksFromFile(books, &bookCount); // Load dữ liệu sách từ file books.bin

    while (1) {
        system("clear");  // Xóa màn hình trước khi hiển thị menu chính
        displayMainMenu();
        scanf("%d", &choice);
        getchar();  // Xóa ký tự '\n' còn sót lại

        switch (choice) {
            case 1: {
                int bookChoice;
                while (1) {
                    system("clear");  // Xóa màn hình khi vào menu quản lý sách
                    displayBookMenu();
                    scanf("%d", &bookChoice);
                    getchar();

                    if (bookChoice == 7) break;  // Quay lại menu chính

                    switch (bookChoice) {
                        case 1:
                            system("clear");
                            displayBooks(books, bookCount);
                            pressAnyKeyToReturn();
                            break;
                        case 2:
                            system("clear");
                            addBook(books, &bookCount);
                        saveBooksToFile(books, bookCount); // Ghi dữ liệu sách vào file books.bin

                             pressAnyKeyToReturn();

                            break;
                        case 3:
                            system("clear");
                            editBook(books, bookCount);
                        saveBooksToFile(books, bookCount); // Ghi dữ liệu sách vào file books.bin

                              pressAnyKeyToReturn();

                            break;
                        case 4:
                            system("clear");
                            deleteBook(books, &bookCount);
                        saveBooksToFile(books, bookCount); // Ghi dữ liệu sách vào file books.bin
                        pressAnyKeyToReturn();
                        break;
                        case 5:
                            system("clear");
                        sortBooksByPrice(books, bookCount);
                        pressAnyKeyToReturn();
                        case 6:
                            system("clear");
                        searchBookByTitle(books, bookCount); // Gọi hàm tìm kiếm sách
                        pressAnyKeyToReturn();
                        break;
                        break;
                        default:
                            printf("Invalid choice. Try again.\n");
                            pressAnyKeyToReturn();
                    }
                }
                break;
            }
            case 2: {
                int memberChoice;
                while (1) {
                    system("clear");  // Xóa màn hình khi vào menu quản lý thành viên
                    displayMemberMenu();
                    scanf("%d", &memberChoice);
                    getchar();

                    if (memberChoice == 4) break;

                    switch (memberChoice) {
                        case 1:
                            system("clear");
                            displayMembers(members, memberCount);
                            pressAnyKeyToReturn();
                            break;
                        case 2:
                            system("clear");
                            addMember(members, &memberCount);
                              pressAnyKeyToReturn();
                            break;
                        case 3:
                            system("clear");
                            editMember(members, memberCount);
                              pressAnyKeyToReturn();
                            break;
                        default:
                            printf("Invalid choice. Try again.\n");
                            pressAnyKeyToReturn();
                    }
                }
                break;
            }
            case 3:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                pressAnyKeyToReturn();
        }
    }
    return 0;
}
