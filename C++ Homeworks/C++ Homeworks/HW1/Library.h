#ifndef BOOK_H
#define BOOK_H
#include "Book.h"
#include "Book.cpp"
#include <string>
using namespace std;
class Library {
public:
 Library ();
 ~Library ();
 void addBook( string bookTitle, string publishingHouse, int publishingYear );
 void removeBook( string bookTitle );
 void addCoauthor( string bookTitle, string coauthorName );
 void removeCoauthor ( string bookTitle, string coauthorName );
 void displayAllBooks();
 void displayBook( string bookTitle );
 void displayAuthor( string authorName );
 // ...
 // you may define additional member functions and data members,
 // if necessary
private:

};
