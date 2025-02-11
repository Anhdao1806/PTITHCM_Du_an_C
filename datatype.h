/* datatype.h */
#ifndef DATATYPE_H
#define DATATYPE_H

#include <stdbool.h>

typedef struct {
    int month, day, year;
} Date;

typedef struct {
    char bookId[10];
    char title[30];
    char author[20];
    int quantity;
    int price;
    Date publication;
} Book;

typedef struct {
    char memberId[10];
    char name[20];
    char phone[10];
    bool status;
    int borrowedCount;
} Member;

#endif