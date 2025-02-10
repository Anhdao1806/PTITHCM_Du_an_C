#include <stdio.h>
#include "function.h"

#define MAX_BOOKS 100

int main() {
    Book books[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (bookCount == 0)
                    printf("No books available.\n");
                else
                    displayBooks(books, bookCount);
            break;
            case 2:
                addBook(books, &bookCount);
            break;
            case 3:
                printf("Exiting program...\n");
            break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
