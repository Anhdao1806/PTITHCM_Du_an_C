/* function.h */
#ifndef FUNCTION_H
#define FUNCTION_H

#include "datatype.h"

void displayMainMenu();
void displayBookMenu();
void displayMemberMenu();
void displayBooks(Book books[], int count);
void addBook(Book books[], int *count);
void editBook(Book books[], int count);
void displayMembers(Member members[], int count);
void addMember(Member members[], int *count);
void editMember(Member members[], int count);

#endif
