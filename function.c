/* function.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

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
    printf("Title: "); scanf(" %[^\n]", books[*count].title);
    printf("Author: "); scanf(" %[^\n]", books[*count].author);
    printf("Quantity: "); scanf("%d", &books[*count].quantity);
    printf("Price: "); scanf("%d", &books[*count].price);
    printf("Publication Date (dd mm yyyy): ");
    scanf("%d %d %d", &books[*count].publication.day, &books[*count].publication.month, &books[*count].publication.year);

    (*count)++;
    printf("Book added successfully!\n");
}

void editBook(Book books[], int count) {
    char id[10];
    printf("Enter the book ID to edit: ");
    scanf("%s", id);

    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].bookId, id) == 0) {
            printf("Enter new title: "); scanf(" %[^\n]", books[i].title);
            printf("Enter new author: "); scanf(" %[^\n]", books[i].author);
            printf("Enter new quantity: "); scanf("%d", &books[i].quantity);
            printf("Enter new price: "); scanf("%d", &books[i].price);
            printf("Enter new publication date (dd mm yyyy): ");
            scanf("%d %d %d", &books[i].publication.day, &books[i].publication.month, &books[i].publication.year);
            printf("Book information updated successfully!\n");
            return;
        }
    }
    printf("Book with ID %s not found!\n", id);
}
void displayMembers(Member members[], int count) {
    printf("\n%-10s %-20s %-10s\n", "Member ID", "Name", "Phone");
    printf("------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10s %-20s %-10s\n", members[i].memberId, members[i].name, members[i].phone);
    }
}

void addMember(Member members[], int *count) {
    printf("\nEnter member details:\n");
    printf("Member ID: "); scanf("%s", members[*count].memberId);
    printf("Name: "); scanf(" %[^\n]", members[*count].name);
    printf("Phone: "); scanf("%s", members[*count].phone);

    (*count)++;
    printf("Member added successfully!\n");
}

void editMember(Member members[], int count) {
    char id[10];
    printf("Enter the member ID to edit: ");
    scanf("%s", id);

    for (int i = 0; i < count; i++) {
        if (strcmp(members[i].memberId, id) == 0) {
            printf("Enter new name: "); scanf(" %[^\n]", members[i].name);
            printf("Enter new phone: "); scanf("%s", members[i].phone);
            printf("Member information updated successfully!\n");
            return;
        }
    }
    printf("Member with ID %s not found!\n", id);
}
