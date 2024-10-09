#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Book {
private:
    int book_id;
    string title;
    string author;
    string publisher;
    int year;
    bool availability; // true if the book is available, false otherwise

public:
    // Constructor
    Book(int b_id, string title, string author, string publisher, int year, bool availability) 
        : book_id(b_id), title(title), author(author), publisher(publisher), year(year), availability(availability) {}

    // Getter methods for book properties 
    int getBookID() const { return book_id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getPublisher() const { return publisher; }
    int getYear() const { return year; }
    bool isAvailable() const { return availability; }

    // Setter method for availability
    void setAvailability(bool available) { availability = available; }

    // Display Book Information
    void DisplayBook() const {
        cout << "Book ID: " << book_id << endl; 
        cout << "Book Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Year: " << year << endl;  
        cout << "Availability: " << (availability ? "Available" : "Not Available") << endl;
    }
};

class Member {
private:
    int member_id;
    string member_name;
    string contact_info;
    vector<Book> borrowed_books; // Vector of actual Book objects

public:
    // Member Constructor
    Member(int id, string name, string contact) 
        : member_id(id), member_name(name), contact_info(contact) {}

    // Getter methods for member attributes
    int getMemberID() const { return member_id; }
    string getMemberName() const { return member_name; }
    string getContactInfo() const { return contact_info; }

    // Push the borrowed book to the vector 
    void BorrowBook(const Book& book) {
        borrowed_books.push_back(book);
    }

    // Return a book by its ID
    void ReturnBook(int bookID) {
        auto it = remove_if(borrowed_books.begin(), borrowed_books.end(), 
                            [bookID](const Book& book) { return book.getBookID() == bookID; });
        borrowed_books.erase(it, borrowed_books.end());
    }

    // Display Member Information 
    void DisplayMember() const {
        cout << "Member ID: " << member_id << endl;
        cout << "Member Name: " << member_name << endl;
        cout << "Contact Information: " << contact_info << endl;
        cout << "Borrowed Books: " << endl;
        for (const auto& book : borrowed_books) {
            book.DisplayBook(); // Assuming Book class has a DisplayBook method
        }
        cout << endl;
    }

    // Get borrowed books
    const vector<Book>& getBorrowedBooks() const { return borrowed_books; }
};

class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:
    // Adding and Removing Books and Members
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void removeBook(int bookID) {
        auto it = remove_if(books.begin(), books.end(), [bookID](const Book& book) { return book.getBookID() == bookID; });
        books.erase(it, books.end());
    }

    void addMember(const Member& member) {
        members.push_back(member);
    }

    void removeMember(int memberID) {
        auto it = remove_if(members.begin(), members.end(), [memberID](const Member& member) { return member.getMemberID() == memberID; });
        members.erase(it, members.end());
    }

    // Borrowing and Returning Books
    void borrowBook(int memberID, int bookID) {
        auto memberIt = find_if(members.begin(), members.end(), [memberID](const Member& m) { return m.getMemberID() == memberID; });
        auto bookIt = find_if(books.begin(), books.end(), [bookID](const Book& b) { return b.getBookID() == bookID; });

        if (memberIt != members.end() && bookIt != books.end() && bookIt->isAvailable()) {
            memberIt->BorrowBook(*bookIt);
            bookIt->setAvailability(false);
        } else {
            cout << "Error: Member or book not found or book is already borrowed." << endl;
        }
    }

    void returnBook(int memberID, int bookID) {
        auto memberIt = find_if(members.begin(), members.end(), [memberID](const Member& m) { return m.getMemberID() == memberID; });
        auto bookIt = find_if(books.begin(), books.end(), [bookID](const Book& b) { return b.getBookID() == bookID; });

        if (memberIt != members.end() && bookIt != books.end()) {
            memberIt->ReturnBook(bookID);
            bookIt->setAvailability(true);
        } else {
            cout << "Error: Member or book not found." << endl;
        }
    }

    // Search Functions
    void searchBookByTitle(const string& title) const {
        for (const auto& book : books) {
            if (book.getTitle() == title) {
                book.DisplayBook();
                return;
            }
        }
        cout << "The book with title: " << title << " was not found" << endl;
    }

    void searchBookByAuthor(const string& author) const {
        for (const auto& book : books) {
            if (book.getAuthor() == author) {
                book.DisplayBook();
                return;
            }
        }
        cout << "No books by author: " << author << " were found" << endl;
    }

    void searchMemberByName(const string& name) const {
        for (const auto& member : members) {
            if (member.getMemberName() == name) {
                member.DisplayMember();
                return;
            }
        }
        cout << "The member with name: " << name << " was not found" << endl;
    }

    // Display Functions
    void displayAllBooks() const {
        for (const auto& book : books) {
            book.DisplayBook();
        }
    }

    void displayAllMembers() const {
        for (const auto& member : members) {
            member.DisplayMember();
        }
    }

    void displayBorrowedBooks(int memberID) const {
        // Find the member by ID
        auto memberIt = find_if(members.begin(), members.end(), 
                                [memberID](const Member& m) { return m.getMemberID() == memberID; });

        // If member is found, display their borrowed books
        if (memberIt != members.end()) {
            cout << "Borrowed Books for Member ID: " << memberID << endl;
            for (const auto& book : memberIt->getBorrowedBooks()) {
                book.DisplayBook();
            }
        } 
        // If member is not found, print an error message
        else {
            cout << "Error: Member not found." << endl;
        }
    }
};

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
                cin.ignore();
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
