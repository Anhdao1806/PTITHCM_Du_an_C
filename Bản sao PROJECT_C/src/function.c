
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
    printf("┌─────────────────────────────────────────┐\n");
    printf("│      Library Management System          │\n");
    printf("├─────────────────────────────────────────┤\n");
    printf("│      1. Book Managemen                  │\n");
    printf("│      2. Member Management               │\n");
    printf("│      3. Exit                            │\n");
    printf("└─────────────────────────────────────────┘\n");
    printf("👉Enter your choice: ");
}

void displayBookMenu() {
    printf("┌───────────────────────────────────┐\n");
    printf("│           Book Management         │\n");
    printf("├───────────────────────────────────┤\n");
    printf("         1. Display book list\n");
    printf("         2. Add a book\n");
    printf("         3. Edit a book\n");
    printf("         4. Delete a book\n");
    printf("         5. Sort books by price\n");
    printf("         6. Search book by title\n");
    printf("         7. Return to main menu\n");
    printf("└───────────────────────────────────┘\n");
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
    printf("───────────────────────────────────────────────────────────────────────────────────────────────\n");
    for (int i = 0; i < count; i++) {
        printf("%-10s %-30s %-20s %-10d %-10d %02d/%02d/%04d\n", books[i].bookId, books[i].title, books[i].author, books[i].quantity, books[i].price, books[i].publication.day, books[i].publication.month, books[i].publication.year);
        printf("────────────────────────────────────────────────────────────────────────────────────────────────\n");
    }
    system("clear");
}
void addBook(Book books[], int *count) {
    Book newBook;
    char buffer[100];

    // Nhập và kiểm tra Book ID (không trùng nhau, không rỗng, độ dài hợp lệ)
    while (1) {
        printf("Enter Book ID (max 9 characters, non-empty): "); // Yêu cầu nhập ID sách không rỗng và tối đa 9 ký tự
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng ở cuối chuỗi

        if (strlen(buffer) == 0) {
            printf("Book ID cannot be empty. Please try again.\n"); // Nếu rỗng thì yêu cầu nhập lại
            continue;
        }
        if (strlen(buffer) > 9) {
            printf("Book ID is too long. Maximum 9 characters allowed. Please try again.\n"); // Nếu vượt quá 9 ký tự thì yêu cầu nhập lại
            continue;
        }
        // Kiểm tra xem Book ID có bị trùng với các sách đã có hay không
        int duplicate = 0;
        for (int i = 0; i < *count; i++) {
            if (strcmp(books[i].bookId, buffer) == 0) {
                duplicate = 1;
                break;
            }
        }
        if (duplicate) {
            printf("Book ID already exists. Please enter a unique Book ID.\n"); // Thông báo nếu trùng ID
            continue;
        }
        strcpy(newBook.bookId, buffer);
        break;
    }

    // Nhập và kiểm tra Book Title (không trống, độ dài hợp lệ, không trùng nhau)
    while (1) {
        printf("Enter Book Title (max 29 characters, non-empty): "); // Yêu cầu nhập tên sách không rỗng và tối đa 29 ký tự
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if (strlen(buffer) == 0) {
            printf("Book Title cannot be empty. Please try again.\n");
            continue;
        }
        if (strlen(buffer) > 29) {
            printf("Book Title is too long. Maximum 29 characters allowed. Please try again.\n");
            continue;
        }
        // Kiểm tra xem Book Title có bị trùng với sách đã nhập hay không
        int duplicate = 0;
        for (int i = 0; i < *count; i++) {
            if (strcmp(books[i].title, buffer) == 0) {
                duplicate = 1;
                break;
            }
        }
        if (duplicate) {
            printf("Book Title already exists. Please enter a unique Book Title.\n");
            continue;
        }
        strcpy(newBook.title, buffer);
        break;
    }

    // Nhập và kiểm tra Author Name (không trống, độ dài hợp lệ)
    while (1) {
        printf("Enter Author Name (max 19 characters, non-empty): "); // Yêu cầu nhập tên tác giả không rỗng và tối đa 19 ký tự
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strlen(buffer) == 0) {
            printf("Author Name cannot be empty. Please try again.\n");
            continue;
        }
        if (strlen(buffer) > 19) {
            printf("Author Name is too long. Maximum 19 characters allowed. Please try again.\n");
            continue;
        }
        strcpy(newBook.author, buffer);
        break;
    }

    // Nhập và kiểm tra số lượng sách (quantity)
    while (1) {
        char numBuffer[20];
        printf("Enter quantity (positive integer): "); // Yêu cầu nhập số lượng sách dương
        fgets(numBuffer, sizeof(numBuffer), stdin);
        int quantity = atoi(numBuffer);
        if (quantity <= 0) {
            printf("Quantity must be a positive integer. Please try again.\n");
            continue;
        }
        newBook.quantity = quantity;
        break;
    }

    // Nhập và kiểm tra giá sách (price)
    while (1) {
        char numBuffer[20];
        printf("Enter price (positive integer): "); // Yêu cầu nhập giá sách dương
        fgets(numBuffer, sizeof(numBuffer), stdin);
        int price = atoi(numBuffer);
        if (price <= 0) {
            printf("Price must be a positive integer. Please try again.\n");
            continue;
        }
        newBook.price = price;
        break;
    }

    // Nhập và kiểm tra ngày xuất bản (day)
    while (1) {
        char numBuffer[20];
        printf("Enter publication day (1-31): "); // Yêu cầu nhập ngày xuất bản từ 1 đến 31
        fgets(numBuffer, sizeof(numBuffer), stdin);
        int day = atoi(numBuffer);
        if (day < 1 || day > 31) {
            printf("Day must be between 1 and 31. Please try again.\n");
            continue;
        }
        newBook.publication.day = day;
        break;
    }

    // Nhập và kiểm tra tháng xuất bản (month)
    while (1) {
        char numBuffer[20];
        printf("Enter publication month (1-12): "); // Yêu cầu nhập tháng xuất bản từ 1 đến 12
        fgets(numBuffer, sizeof(numBuffer), stdin);
        int month = atoi(numBuffer);
        if (month < 1 || month > 12) {
            printf("Month must be between 1 and 12. Please try again.\n");
            continue;
        }
        newBook.publication.month = month;
        break;
    }

    // Nhập và kiểm tra năm xuất bản (year)
    while (1) {
        char numBuffer[20];
        printf("Enter publication year (e.g., 2000): "); // Yêu cầu nhập năm xuất bản hợp lệ (số dương)
        fgets(numBuffer, sizeof(numBuffer), stdin);
        int year = atoi(numBuffer);
        if (year <= 0) {
            printf("Year must be a positive integer. Please try again.\n");
            continue;
        }
        newBook.publication.year = year;
        break;
    }

    // Thêm sách mới vào mảng và cập nhật số lượng sách
    books[*count] = newBook;
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
// Hàm xóa sách theo ID
void deleteBook(Book books[], int *count) {
    system("clear");
    printf("\n========== Delete a Book ==========\n");

    char id[10];
    printf("Enter the Book ID to delete (or 'q' to return): ");
    scanf("%s", id);
    getchar();  // Xóa ký tự xuống dòng trong bộ đệm

    if (strcmp(id, "q") == 0) return;  // Quay lại menu nếu nhập 'q'

    for (int i = 0; i < *count; i++) {
        if (strcmp(books[i].bookId, id) == 0) {
            // Hiển thị thông tin sách trước khi xóa
            printf("\nBook found:\n");
            printf("Title  : %s\n", books[i].title);
            printf("Author : %s\n", books[i].author);
            printf("Price  : %d\n", books[i].price);
            printf("\nAre you sure you want to delete this book? (Yes / No): ");

            char choice;
            scanf(" %c", &choice);
            getchar();

            if (choice == 'y' || choice == 'Y') {
                // Dời các sách sau sách bị xóa lên một vị trí
                for (int j = i; j < *count - 1; j++) {
                    books[j] = books[j + 1];
                }
                (*count)--;

                printf("Book deleted successfully!\n");
            } else {
                printf("Book deletion canceled.\n");
            }
            pressAnyKeyToReturn();
            break;
        }
    }
    printf("Book with ID %s not found!\n", id);
    pressAnyKeyToReturn();
}
// Hàm hiển thị menu chọn cách sắp xếp
void displaySortMenu() {
    printf("\n========== Sort Books ==========\n");
    printf("1. Sort by Price (Low to High)\n");
    printf("2. Sort by Price (High to Low)\n");
    printf("3. Return to Book Management Menu\n");
    printf("Enter your choice: ");
}

// Hàm sắp xếp sách theo giá
void sortBooksByPrice(Book books[], int count) {
    if (count == 0) {
        printf("\nNo books available to sort!\n");
        pressAnyKeyToReturn();
        return;
    }

    int choice;
    while (1) {
        system("clear");
        displaySortMenu();
        scanf("%d", &choice);
        getchar();

        if (choice == 3) return;  // Quay lại menu quản lý sách

        if (choice != 1 && choice != 2) {
            printf("Invalid choice. Try again.\n");
            pressAnyKeyToReturn();
            continue;
        }

        // Sắp xếp nổi bọt theo giá
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                int swap = 0;
                if ((choice == 1 && books[j].price > books[j + 1].price) ||  // Giá tăng dần
                    (choice == 2 && books[j].price < books[j + 1].price)) { // Giá giảm dần
                    swap = 1;
                }

                if (swap) {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }

        printf("\nBooks sorted successfully!\n");

        // Hiển thị danh sách sau khi sắp xếp
        printf("\n%-10s %-30s %-20s %-10s %-10s %-10s\n", "Book ID", "Title", "Author", "Quantity", "Price", "Pub. Date");
        printf("-------------------------------------------------------------------------------\n");
        for (int i = 0; i < count; i++) {
            printf("%-10s %-30s %-20s %-10d %-10d %02d/%02d/%04d\n",
                   books[i].bookId, books[i].title, books[i].author,
                   books[i].quantity, books[i].price,
                   books[i].publication.day, books[i].publication.month, books[i].publication.year);
        }

    }
}
// Hàm tìm kiếm sách theo tên
void searchBookByTitle(Book books[], int count) {
    char keyword[30];
    printf("Enter the name of the book you want to search: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = 0; // Loại bỏ ký tự xuống dòng ở cuối chuỗi

    int found = 0; // Biến kiểm tra xem có sách nào được tìm thấy hay không
    printf("Search results:\n");
    printf("%-10s %-30s %-20s %-10s %-10s %-10s\n", "Book ID", "Title", "Author", "Quantity", "Price", "Pub. Date");

    for (int i = 0; i < count; i++) {
        if (strstr(books[i].title, keyword) != NULL) { // Kiểm tra xem chuỗi nhập vào có trong tên sách không
            found = 1;
            printf("%-10s %-30s %-20s %-10d %-10d %d/%d/%d\n",
                   books[i].bookId, books[i].title, books[i].author,
                   books[i].quantity, books[i].price,
                   books[i].publication.day, books[i].publication.month, books[i].publication.year);
        }
    }

    if (!found) {
        printf("No books found!\n"); // Nếu không có kết quả, thông báo cho người dùng
    }
}
// Hàm lưu danh sách sách vào file nhị phân
void saveBooksToFile(Book books[], int bookCount) {
    FILE *file = fopen("books.bin", "wb"); // Mở file ở chế độ ghi nhị phân (write binary)
    if (!file) {
        printf("Cannot open file\n");
        return;
    }
    fwrite(&bookCount, sizeof(int), 1, file); // Ghi số lượng sách vào file
    fwrite(books, sizeof(Book), bookCount, file); // Ghi danh sách sách vào file
    fclose(file);
    printf("Book data has been added to the file\n");
}
// Hàm đọc danh sách sách từ file nhị phân
void loadBooksFromFile(Book books[], int *bookCount) {
    FILE *file = fopen("books.bin", "rb"); // Mở file ở chế độ đọc nhị phân (read binary)
    if (!file) {
        printf("Cannot open file\n");
        *bookCount = 0;
        return;
    }
    fread(bookCount, sizeof(int), 1, file); // Đọc số lượng sách từ file
    fread(books, sizeof(Book), *bookCount, file); // Đọc danh sách sách từ file
    fclose(file);
    printf("Book data is read from file\n");
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