#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 500
#define MAX_EMPLOYEES 15

//Structures for Books and Employees
typedef struct {
    int id;
    char title[30];
    char author[30];
    int stock;
    double price;
    int ISBN;
    int year;
} Book;

typedef struct {
    int id;
    char name[30];
    double salary;
    int age;
} Employee;

Book books[MAX_BOOKS];
Employee employees[MAX_EMPLOYEES];
int bookCount = 0;
int employeeCount = 0;

const char *bookFile = "books.txt";
const char *employeeFile = "employees.txt";

// Function-load books
void loadBooks() {
    FILE *file = fopen(bookFile, "r");
    if (file == NULL) {
        return;
    }
    bookCount = 0;
    while (fscanf(file, "%d %[^\n] %[^\n] %d %lf\n", &books[bookCount].id, books[bookCount].title,
                  books[bookCount].author, &books[bookCount].stock, &books[bookCount].price) != EOF) {
        bookCount++;
    }
    fclose(file);
}

// Function-save books
void saveBooks() {
    FILE *file = fopen(bookFile, "w");
    if (file == NULL) {
        printf("Error saving books!\n");
        return;
    }
    for (int i = 0; i < bookCount; i++) {
        fprintf(file, "%d\n%s\n%s\n%d\n%.2f\n", books[i].id, books[i].title, books[i].author, books[i].stock, books[i].price);
    }
    fclose(file);
}

// Function-load employees
void loadEmployees() {
    FILE *file = fopen(employeeFile, "r");
    if (file == NULL) {
        return;
    }
    employeeCount = 0;
    while (fscanf(file, "%d %[^\n] %lf\n", &employees[employeeCount].id, employees[employeeCount].name,
                  &employees[employeeCount].salary) != EOF) {
        employeeCount++;
    }
    fclose(file);
}

// Function-save employees
void saveEmployees() {
    FILE *file = fopen(employeeFile, "w");
    if (file == NULL) {
        printf("Error:saving employees!\n");
        return;
    }
    for (int i = 0; i < employeeCount; i++) {
        fprintf(file, "%d\n%s\n%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
    fclose(file);
}

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Amount exceeds!\n");
        return;
    }
    printf("Enter book ID: ");
    scanf("%d", &books[bookCount].id);
    printf("Enter book title: ");
    getchar();
    fgets(books[bookCount].title, sizeof(books[bookCount].title), stdin);
    strtok(books[bookCount].title, "\n");
    printf("Enter author: ");
    fgets(books[bookCount].author, sizeof(books[bookCount].author), stdin);
    strtok(books[bookCount].author, "\n");
    printf("Enter stock quantity: ");
    scanf("%d", &books[bookCount].stock);
    printf("Enter price: ");
    scanf("%lf", &books[bookCount].price);
    bookCount++;
    saveBooks();
    printf("Book added successfully!\n");
}


void updateBook() {
    int id;
    printf("Enter the book ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            printf("Updating book: %s\n", books[i].title);
            printf("Enter new stock: ");
            scanf("%d", &books[i].stock);
            printf("Enter new price: ");
            scanf("%lf", &books[i].price);
            saveBooks();
            printf("Book updated successfully!\n");
            return;
        }
    }
    printf("Error:Book not found!\n");
}

void deleteBook() {
    int id;
    printf("Enter the book ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            for (int j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1];
            }
            bookCount--;
            saveBooks();
            printf("Book deleted successfully!\n");
            return;
        }
    }
    printf("Error:Book not found!\n");
}


void viewBooks() {
    if (bookCount == 0) {
        printf("No books available!\n");
        return;
    }
    // Print table header
    printf("\n %-10s %-30s %-20s %-10s %-10s\n", "ID", "Title", "Author", "Stock", "Price");
    printf(" ---------------------------------------------------------------------------------\n");
    // Print each book as a row in the table
    for (int i = 0; i < bookCount; i++) {
        printf(" %-10d %-30s %-20s %-10d $%-10.2f\n", books[i].id, books[i].title, books[i].author, books[i].stock, books[i].price);
    }
    printf("\n\n");
}


void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Employee limit reached!\n");
        return;
    }
    printf("Enter employee ID: ");
    scanf("%d", &employees[employeeCount].id);
    printf("Enter employee name: ");
    getchar();
    fgets(employees[employeeCount].name, sizeof(employees[employeeCount].name), stdin);
    strtok(employees[employeeCount].name, "\n");
    printf("Enter salary: ");
    scanf("%lf", &employees[employeeCount].salary);
    employeeCount++;
    saveEmployees();
    printf("Employee added successfully!\n");
}


void viewEmployees() {
    if (employeeCount == 0) {
        printf("No employees found.\n");
        return;
    }
    printf("\n%-10s %-20s %-10s\n", "ID", "Name", "Salary");
    printf("--------------------------------------------\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("%-10d %-20s %-10.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
    printf("\n");
}


void deleteEmployee() {
    int id;
    printf("Enter the employee ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            saveEmployees();
            printf("Employee deleted successfully!\n");
            return;
        }
    }
    printf("Error:Employee not found!\n");
}


void updateEmployee() {
    int id;
    printf("Enter the employee ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            printf("Updating employee: %s\n", employees[i].name);
            printf("Enter new salary: ");
            scanf("%lf", &employees[i].salary);
            saveEmployees();
            printf("Employee updated successfully!\n");
            return;
        }
    }
    printf("Error:Employee not found!\n");
}


//Payment
void makePayment() {
    int bookId, quantity;
    printf("Enter book ID for payment: ");
    scanf("%d", &bookId);
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == bookId) {
            if (books[i].stock >= quantity) {
                double totalPayment = quantity * books[i].price;
                books[i].stock -= quantity;
                saveBooks();
                printf("Payment successful Total: $%.2f\n", totalPayment);
            } else {
                printf("Error:Insufficient stock!\n");
            }
            return;
        }
    }
    printf("Book not found!\n");
}
//Menu
void menu() {
    printf("  1. Add Book\n");
    printf("  2. View Books\n");
    printf("  3. Update Book\n");
    printf("  4. Delete Book\n");
    printf("  5. Add Employee\n");
    printf("  6. View Employees\n");
    printf("  7. Update Employee\n");
    printf("  8. Delete Employee\n");
    printf("  9. Make Payment\n");
    printf("  10. Exit\n\n");
    printf("  Choose an option: ");
}

//Main code
int main() {
    //Header
    printf("\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n");
    printf("\t\t\tWelcome to the Bookshop Management System    \n");
    printf("\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    //Load data from files
    loadBooks();
    loadEmployees();

    //Menu options
    int choice;
    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                updateBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                addEmployee();
                break;
            case 6:
                viewEmployees();
                break;
            case 7:
                updateEmployee();
                break;
            case 8:
                deleteEmployee();
                break;
            case 9:
                makePayment();
                break;
            case 10:
                printf("Thank you for using our system. Have a nice day!\n");
                exit(0);
            default:
                printf("Invalid option! Please enter correctly.\n");
        }
    }

    return 0;
}
