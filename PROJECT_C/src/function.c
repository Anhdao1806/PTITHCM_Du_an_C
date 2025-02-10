
#includ#include <stdio.h>
#include <string.h>
#include "function.h"

void displayMenu() {
    printf("========== Library Management System ==========\n");
    printf("1. Display book list\n");
    printf("2. Add a book\n");
    printf("3. Exit\n");
    printf("==============================================\n");
    printf("Enter your choice: ");
}

void displayBooks(Book books[], int count) {
    printf("\n%-10s %-30s %-20s %-10s %-10s %-10s\n",
           "Book ID", "Title", "Author", "Quantity", "Price", "Pub. Date");
    printf("-------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10s %-30s %-20s %-10d %-10d %02d/%02d/%04d\n",
               books[i].bookId, books[i].title, books[i].author,
               books[i].quantity, books[i].price,
               books[i].publication.day, books[i].publication.month, books[i].publication.year);
    }
}

void addBook(Book books[], int *count) {
    printf("\nEnter book details:\n");
    printf("Book ID: "); scanf("%s", books[*count].bookId);
    printf("Title: "); scanf(" %[^\n]", books[*count].title);
    printf("Author: "); scanf(" %[^\n]", books[*count].author);
    printf("Quantity: "); scanf("%d", &books[*count].quantity);
    printf("Price: "); scanf("%d", &books[*count].price);
    printf("Publication Date (dd mm yyyy): ");
    scanf("%d %d %d", &books[*count].publication.day, &books[*count].publication.month, &books[*count].publication.year);

    (*count)++;
    printf("Book added successfully!\n");
}
