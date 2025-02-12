
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

void pressAnyKeyToReturn() {
    char input;
    printf("\nPress 'q' to return to the previous menu... ");

    while (1) {
        input = getchar();
        if (input == 'q' || input == 'Q') break;  // Nếu nhấn 'q' hoặc 'Q' thì thoát
    }
}

void displayMainMenu() {
    printf("========== Library Management System ==========\n");
    printf("1. Book Management\n");
    printf("2. Member Management\n");
    printf("3. Exit\n");
    printf("==============================================\n");
    printf("Enter your choice: ");
}

void displayBookMenu() {
    printf("========== Book Management ==========\n");
    printf("1. Display book list\n");
    printf("2. Add a book\n");
    printf("3. Edit a book\n");
    printf("4. Return to main menu\n");
    printf("======================================\n");
    printf("Enter your choice: ");
}

void displayMemberMenu() {
    printf("========== Member Management ==========\n");
    printf("1. Display member list\n");
    printf("2. Add a member\n");
    printf("3. Edit a member\n");
    printf("4. Return to main menu\n");
    printf("======================================\n");
    printf("Enter your choice: ");
}
void displayBooks(Book books[], int count) {
    printf("\n%-10s %-30s %-20s %-10s %-10s %-10s\n", "Book ID", "Title", "Author", "Quantity", "Price", "Pub. Date");
    printf("-------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10s %-30s %-20s %-10d %-10d %02d/%02d/%04d\n", books[i].bookId, books[i].title, books[i].author, books[i].quantity, books[i].price, books[i].publication.day, books[i].publication.month, books[i].publication.year);
    }
}
void addBook(Book books[], int *count) {
    printf("\nEnter book details:\n");
    printf("Book ID: "); scanf("%s", books[*count].bookId);
    getchar();  // Xóa ký tự '\n' còn sót lại trong bộ đệm

    printf("Title: ");
    fgets(books[*count].title, sizeof(books[*count].title), stdin);
    if (strchr(books[*count].title, '\n')) books[*count].title[strcspn(books[*count].title, "\n")] = '\0';

    printf("Author: ");
    fgets(books[*count].author, sizeof(books[*count].author), stdin);
    if (strchr(books[*count].author, '\n')) books[*count].author[strcspn(books[*count].author, "\n")] = '\0';

    printf("Quantity: "); scanf("%d", &books[*count].quantity);
    printf("Price: "); scanf("%d", &books[*count].price);
    printf("Publication Date (dd mm yyyy): ");
    scanf("%d %d %d", &books[*count].publication.day, &books[*count].publication.month, &books[*count].publication.year);

    (*count)++;
    printf("Book added successfully!\n");
}

void editBook(Book books[], int count) {
    while (1) {
        system("clear");
        printf("\n========== Edit a Book ==========\n");

        char id[10];
        printf("Enter the Book ID to edit (or 'q' to return): ");
        scanf("%s", id);
        getchar();

        if (strcmp(id, "q") == 0) return;  // Quay lại menu nếu nhập 'q'

        for (int i = 0; i < count; i++) {
            if (strcmp(books[i].bookId, id) == 0) {
                // Hiển thị thông tin sách hiện tại
                printf("\nCurrent Information:\n");
                printf("Book ID       : %s\n", books[i].bookId);
                printf("Title         : %s\n", books[i].title);
                printf("Author        : %s\n", books[i].author);
                printf("Quantity      : %d\n", books[i].quantity);
                printf("Price         : %d\n", books[i].price);
                printf("Publication Date: %02d/%02d/%04d\n",
                       books[i].publication.day,
                       books[i].publication.month,
                       books[i].publication.year);

                printf("\nEnter new information (leave empty to keep current value):\n");

                // Nhập tiêu đề mới
                printf("New Title: ");
                char newTitle[30];
                fgets(newTitle, sizeof(newTitle), stdin);
                if (newTitle[0] != '\n') {
                    newTitle[strcspn(newTitle, "\n")] = '\0';
                    strcpy(books[i].title, newTitle);
                }

                // Nhập tác giả mới
                printf("New Author: ");
                char newAuthor[20];
                fgets(newAuthor, sizeof(newAuthor), stdin);
                if (newAuthor[0] != '\n') {
                    newAuthor[strcspn(newAuthor, "\n")] = '\0';
                    strcpy(books[i].author, newAuthor);
                }

                // Nhập số lượng mới
                printf("New Quantity (enter -1 to keep current): ");
                int newQuantity;
                scanf("%d", &newQuantity);
                if (newQuantity != -1) books[i].quantity = newQuantity;

                // Nhập giá mới
                printf("New Price (enter -1 to keep current): ");
                int newPrice;
                scanf("%d", &newPrice);
                if (newPrice != -1) books[i].price = newPrice;

                // Nhập ngày xuất bản mới
                printf("New Publication Date (dd mm yyyy, enter -1 to keep current): ");
                int newDay, newMonth, newYear;
                scanf("%d %d %d", &newDay, &newMonth, &newYear);
                if (newDay != -1) {
                    books[i].publication.day = newDay;
                    books[i].publication.month = newMonth;
                    books[i].publication.year = newYear;
                }

                printf("\nBook information updated successfully!\n");
                pressAnyKeyToReturn();  // Chờ người dùng nhấn 'q' để quay lại menu
                return;
            }
        }
        printf("Book with ID %s not found! Try again.\n", id);
        pressAnyKeyToReturn();
    }
}

void addMember(Member members[], int *count) {
    printf("\nEnter member details:\n");
    printf("Member ID: "); scanf("%s", members[*count].memberId);
    getchar(); // Xóa ký tự '\n' còn sót lại trong bộ đệm

    printf("Name: ");
    fgets(members[*count].name, sizeof(members[*count].name), stdin);
    if (strchr(members[*count].name, '\n')) members[*count].name[strcspn(members[*count].name, "\n")] = '\0';

    printf("Phone: "); scanf("%s", members[*count].phone);

    (*count)++;
    printf("Member added successfully!\n");
}
void displayMembers(Member members[], int count) {
    printf("\n%-10s %-20s %-10s\n", "Member ID", "Name", "Phone");
    printf("------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10s %-20s %-10s\n", members[i].memberId, members[i].name, members[i].phone);
    }
}

void editMember(Member members[], int count) {
    char id[10];
    printf("Enter the member ID to edit: ");
    scanf("%s", id);
    getchar(); // Xóa ký tự '\n' còn sót lại trong bộ đệm

    for (int i = 0; i < count; i++) {
        if (strcmp(members[i].memberId, id) == 0) {
            printf("Enter new name: ");
            fgets(members[i].name, sizeof(members[i].name), stdin);
            if (strchr(members[i].name, '\n')) members[i].name[strcspn(members[i].name, "\n")] = '\0';

            printf("Enter new phone: "); scanf("%s", members[i].phone);

            printf("Member information updated successfully!\n");
            return;
        }
    }
    printf("Member with ID %s not found!\n", id);
}