# Bookshop Management System with - C

This is a simple command-line CRUD (Create, Read, Update, Delete) system for managing a bookshop. The system allows you to manage books, employees, stock count, and payments.

## Features

- **Books Management**: Add, view, update, and delete books.
- **Employees Management**: Add, view, update, and delete employees.
- **Payments Management**: Make payments.

## Getting Started
### Prerequisites
- **C Compiler**: Ensure you have a C compiler installed (e.g., GCC).

## Usage
### 1.Run with Code::Blocks or VS Code
Just run as the usual way.
### 2.Run with cmd
1. **Compile the Program**:
    ```sh
    gcc -o bookshopCrud.c -o bookshopCrud.exe
    ```
2. **Run the Program**:
    ```sh
    bookshopCrud.exe
    ```
3. Follow the on-screen instructions to perform CRUD operations on books, employees, and payments..
   
## File Structure

- `main.c`: The main source code file containing the implementation of the CRUD system.
- `books.txt`: txt file to store book records.
- `employees.txt`: txt file to store employee records.

## Functions

### Books

- `addBook()`: Adds a new book to the system.
- `viewBooks()`: Displays all books in the system.
- `updateBook()`: Updates the details of an existing book.
- `deleteBook()`: Deletes a book from the system.

### Employees

- `addEmployee()`: Adds a new employee to the system.
- `viewEmployees()`: Displays all employees in the system.
- `updateEmployee()`: Updates the details of an existing employee.
- `deleteEmployee()`: Deletes an employee from the system.

### Payments

- `addPayment()`: Make a new payment to the system.
- `viewPayments()`: Displays all payments in the system.

## Contributing

Contributions are welcome! Please fork this repository and submit a pull request for any improvements or bug fixes.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments
- Inspired by various CRUD system examples and tutorials.
- Special thanks to the open-source community for their invaluable resources and support.
