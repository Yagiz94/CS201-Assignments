#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std;
class Book
{
    public:
        Book(string title, string pubHouse, int pubYear);
        ~Book();
        void setTitle(string title);
        string getTitle();
        void setPubHouse(string pubHouse);
        string getPubHouse();
        void setPubYear(int pubYear);
        int getPubYear();
        void setAuthorList(string* authorList);////////////////////////////************///////////////////////////////////
        string*getAuthorList();
        void display();
        string *authorList;
        int sizeAuthorList;
        int noOfBooks;
    private:
};
#endif // BOOK_H
