#include <iostream>
#include "Library.h"

using namespace std;


int main() {
    Library library;
    int choice;
    
    do {
        cout << "---------- Library Management System ----------" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Remove Book" << endl;
        cout << "3. Add Member" << endl;
        cout << "4. Remove Member" << endl;
        cout << "5. Borrow Book" << endl;
        cout << "6. Return Book" << endl;
        cout << "7. Search Book by Title" << endl;
        cout << "8. Search Book by Author" << endl;
        cout << "9. Search Member by Name" << endl;
        cout << "10. Display All Books" << endl;
        cout << "11. Display All Members" << endl;
        cout << "12. Display Borrowed Books of a Member" << endl;
        cout << "13. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int bookID, year;
                string title, author, publisher;
                bool availability;
                cout << "Enter Book ID: ";
                cin >> bookID;
                cout << "Enter Title: ";
                cin.ignore(); // We use cin.ignore(); after we get a numeric input with cin to ensure that getline works properly.Specifically useful when dealing with cin for numeric input
                getline(cin, title);
                cout << "Enter Author: ";
                getline(cin, author);
                cout << "Enter Publisher: ";
                getline(cin, publisher);
                cout << "Enter Year: ";
                cin >> year;
                cout << "Is the book available (1 for Yes, 0 for No): ";
                cin >> availability;

                Book book(bookID, title, author, publisher, year, availability);
                library.addBook(book);
                cout << "Book added successfully." << endl;
                break;
            }
            case 2: {
                int bookID;
                cout << "Enter Book ID to remove: ";
                cin >> bookID;
                library.removeBook(bookID);
                cout << "Book removed successfully." << endl;
                break;
            }
            case 3: {
                int memberID;
                string name, contact;
                cout << "Enter Member ID: ";
                cin >> memberID;
                cout << "Enter Member Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Contact Info: ";
                getline(cin, contact);

                Member member(memberID, name, contact);
                library.addMember(member);
                cout << "Member added successfully." << endl;
                break;
            }
            case 4: {
                int memberID;
                cout << "Enter Member ID to remove: ";
                cin >> memberID;
                library.removeMember(memberID);
                cout << "Member removed successfully." << endl;
                break;
            }
            case 5: {
                int memberID, bookID;
                cout << "Enter Member ID: ";
                cin >> memberID;
                cout << "Enter Book ID to borrow: ";
                cin >> bookID;
                library.borrowBook(memberID, bookID);
                cout << "Book borrowed successfully." << endl;
                break;
            }
            case 6: {
                int memberID, bookID;
                cout << "Enter Member ID: ";
                cin >> memberID;
                cout << "Enter Book ID to return: ";
                cin >> bookID;
                library.returnBook(memberID, bookID);
                cout << "Book returned successfully." << endl;
                break;
            }
            case 7: {
                string title;
                cout << "Enter Book Title to search: ";
                cin.ignore();
                getline(cin, title);
                library.searchBookByTitle(title);
                break;
            }
            case 8: {
                string author;
                cout << "Enter Book Author to search: ";
                cin.ignore();
                getline(cin, author);
                library.searchBookByAuthor(author);
                break;
            }
            case 9: {
                string name;
                cout << "Enter Member Name to search: ";
                cin.ignore();
                getline(cin, name);
                library.searchMemberByName(name);
                break;
            }
            case 10: {
                cout << "Displaying all books:" << endl;
                library.displayAllBooks();
                break;
            }
            case 11: {
                cout << "Displaying all members:" << endl;
                library.displayAllMembers();
                break;
            }
            case 12: {
                int memberID;
                cout << "Enter Member ID to display borrowed books: ";
                cin >> memberID;
                library.displayBorrowedBooks(memberID);
                break;
            }
            case 13: {
                cout << "Exiting the system." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    } while (choice != 13);

    return 0;
}
