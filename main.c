/* main.c */
#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main() {
    Book books[100];
    Member members[100];
    int bookCount = 0;
    int memberCount = 0;
    int choice;

    while (1) {
        displayMainMenu();
        scanf("%d", &choice);
        getchar();  // Clear newline character

        switch (choice) {
            case 1: {
                int bookChoice;
                while (1) {
                    displayBookMenu();
                    scanf("%d", &bookChoice);
                    getchar();

                    if (bookChoice == 4) break;

                    switch (bookChoice) {
                        case 1:
                            displayBooks(books, bookCount);
                            break;
                        case 2:
                            addBook(books, &bookCount);
                            break;
                        case 3:
                            editBook(books, bookCount);
                            break;
                        default:
                            printf("Invalid choice. Try again.\n");
                    }
                }
                break;
            }
            case 2: {
                int memberChoice;
                while (1) {
                    displayMemberMenu();
                    scanf("%d", &memberChoice);
                    getchar();

                    if (memberChoice == 4) break;

                    switch (memberChoice) {
                        case 1:
                            displayMembers(members, memberCount);
                            break;
                        case 2:
                            addMember(members, &memberCount);
                            break;
                        case 3:
                            editMember(members, memberCount);
                            break;
                        default:
                            printf("Invalid choice. Try again.\n");
                    }
                }
                break;
            }
            case 3:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
