#ifndef _Library_
#define _Library_
#include "Library.h"


// Book Class Implementation
Book::Book(int b_id, string title, string author, string publisher, int year, bool availability) 
    : book_id(b_id), title(title), author(author), publisher(publisher), year(year), availability(availability) {}

int Book::getBookID() const { return book_id; }
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getPublisher() const { return publisher; }
int Book::getYear() const { return year; }
bool Book::isAvailable() const { return availability; }

void Book::setAvailability(bool available) { availability = available; }

void Book::DisplayBook() const {
    cout << "Book ID: " << book_id << endl; 
    cout << "Book Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Year: " << year << endl;  
    cout << "Availability: " << (availability ? "Available" : "Not Available") << endl;
}

// Member Class Implementation
Member::Member(int id, string name, string contact) 
    : member_id(id), member_name(name), contact_info(contact) {}

int Member::getMemberID() const { return member_id; }
string Member::getMemberName() const { return member_name; }
string Member::getContactInfo() const { return contact_info; }

void Member::BorrowBook(const Book& book) {
    borrowed_books.push_back(book);
}

void Member::ReturnBook(int bookID) {
    auto it = remove_if(borrowed_books.begin(), borrowed_books.end(), 
                        [bookID](const Book& book) { return book.getBookID() == bookID; });
    borrowed_books.erase(it, borrowed_books.end());
}

void Member::DisplayMember() const {
    cout << "Member ID: " << member_id << endl;
    cout << "Member Name: " << member_name << endl;
    cout << "Contact Information: " << contact_info << endl;
    cout << "Borrowed Books: " << endl;
    for (const auto& book : borrowed_books) {
        book.DisplayBook(); // Assuming Book class has a DisplayBook method
    }
    cout << endl;
}

const vector<Book>& Member::getBorrowedBooks() const { return borrowed_books; }

// Library Class Implementation
void Library::addBook(const Book& book) {
    books.push_back(book);
}

void Library::removeBook(int bookID) {
    auto it = remove_if(books.begin(), books.end(), [bookID](const Book& book) { return book.getBookID() == bookID; });
    books.erase(it, books.end());
}

void Library::addMember(const Member& member) {
    members.push_back(member);
}

void Library::removeMember(int memberID) {
    auto it = remove_if(members.begin(), members.end(), [memberID](const Member& member) { return member.getMemberID() == memberID; });
    members.erase(it, members.end());
}

void Library::borrowBook(int memberID, int bookID) {
    auto memberIt = find_if(members.begin(), members.end(), [memberID](const Member& m) { return m.getMemberID() == memberID; });
    auto bookIt = find_if(books.begin(), books.end(), [bookID](const Book& b) { return b.getBookID() == bookID; });

    if (memberIt != members.end() && bookIt != books.end() && bookIt->isAvailable()) {
        memberIt->BorrowBook(*bookIt);
        bookIt->setAvailability(false);
    } else {
        cout << "Error: Member or book not found or book is already borrowed." << endl;
    }
}

void Library::returnBook(int memberID, int bookID) {
    auto memberIt = find_if(members.begin(), members.end(), [memberID](const Member& m) { return m.getMemberID() == memberID; });
    auto bookIt = find_if(books.begin(), books.end(), [bookID](const Book& b) { return b.getBookID() == bookID; });

    if (memberIt != members.end() && bookIt != books.end()) {
        memberIt->ReturnBook(bookID);
        bookIt->setAvailability(true);
    } else {
        cout << "Error: Member or book not found." << endl;
    }
}

void Library::searchBookByTitle(const string& title) const {
    for (const auto& book : books) {
        if (book.getTitle() == title) {
            book.DisplayBook();
            return;
        }
    }
    cout << "The book with title: " << title << " was not found" << endl;
}

void Library::searchBookByAuthor(const string& author) const {
    for (const auto& book : books) {
        if (book.getAuthor() == author) {
            book.DisplayBook();
            return;
        }
    }
    cout << "No books by author: " << author << " were found" << endl;
}

void Library::searchMemberByName(const string& name) const {
    for (const auto& member : members) {
        if (member.getMemberName() == name) {
            member.DisplayMember();
            return;
        }
    }
    cout << "The member with name: " << name << " was not found" << endl;
}

void Library::displayAllBooks() const {
    for (const auto& book : books) {
        book.DisplayBook();
    }
}

void Library::displayAllMembers() const {
    for (const auto& member : members) {
        member.DisplayMember();
    }
}

void Library::displayBorrowedBooks(int memberID) const {
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

#endif