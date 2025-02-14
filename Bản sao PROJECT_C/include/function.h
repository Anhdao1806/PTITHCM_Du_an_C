
#ifndef FUNCTION_H
#define FUNCTION_H

#include "datatype.h"
void pressAnyKeyToReturn();//HÀM NHẤN PHÍM BẤT KÌ ĐỂ QUAY LẠI
void displayMainMenu();//HÀM HIỂN THỊ MENU CHÍNH
void displayBookMenu();//HÀM HIỂN THỊ MENU SÁCH
void displayMemberMenu();//HÀM HIỂN THỊ MENU THÀNH VIÊN
void displaySortMenu();// HÀM HIỂN THỊ TÙY CHỌN MUỐN SẮP XẾP

//BOOK
void displayBooks(Book books[], int count);//HÀM HIỂN THỊ SÁCH
void addBook(Book books[], int *count);//HÀM THÊM SÁCH MỚI
void editBook(Book books[], int count);//HÀM CHỈNH SỬA THÔNG TIN SÁCH
void deleteBook(Book books[], int *count);//HÀM XÓA SÁCH
void sortBooksByPrice(Book books[], int count);//HÀM SẮP XẾP SÁCH
void searchBookByTitle(Book books[], int count);

// MEMBER
void displayMembers(Member members[], int count);//HÀM HIỂN THỊ THÀNH VIÊN
void addMember(Member members[], int *count);//HÀM THÊM THÀNH VIÊN MỚI
void editMember(Member members[], int count);//HÀM CHỈNH SỬA THÔNG TIN THÀNH VIÊN

//file
void saveBooksToFile(Book books[], int bookCount); // Hàm lưu sách vào file nhị phân
void loadBooksFromFile(Book books[], int *bookCount); // Hàm đọc sách từ file nhị phân

#endif