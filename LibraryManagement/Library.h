#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Book {
private:
    int book_id;
    string title;
    string author;
    string publisher;
    int year;
    bool availability;

public:
    Book(int b_id, string title, string author, string publisher, int year, bool availability);
    int getBookID() const;
    string getTitle() const;
    string getAuthor() const;
    string getPublisher() const;
    int getYear() const;
    bool isAvailable() const;
    void setAvailability(bool available);
    void DisplayBook() const;
};

class Member {
private:
    int member_id;
    string member_name;
    string contact_info;
    vector<Book> borrowed_books;

public:
    Member(int id, string name, string contact);
    int getMemberID() const;
    string getMemberName() const;
    string getContactInfo() const;
    void BorrowBook(const Book& book);
    void ReturnBook(int bookID);
    void DisplayMember() const;
    const vector<Book>& getBorrowedBooks() const;
};

class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:
    void addBook(const Book& book);
    void removeBook(int bookID);
    void addMember(const Member& member);
    void removeMember(int memberID);
    void borrowBook(int memberID, int bookID);
    void returnBook(int memberID, int bookID);
    void searchBookByTitle(const string& title) const;
    void searchBookByAuthor(const string& author) const;
    void searchMemberByName(const string& name) const;
    void displayAllBooks() const;
    void displayAllMembers() const;
    void displayBorrowedBooks(int memberID) const;
};

#include "Library.cpp" 
#endif // LIBRARY_H
