#include "Book.h"
#include <iostream>
#include <string>
using namespace std;
    Book::Book(string title,string pubHouse,int pubYear){
        this->title = title;
        this->pubHouse = pubHouse;
        this->pubYear = pubYear;
        string *authorList = NULL;
        this-> authorList = authorList;
        int sizeAuthorList = 0;
        this-> sizeAuthorList = sizeAuthorList;
    }
    Book::~Book (){}
    void Book::setTitle(string title){
        this->title = title;
    }
    string Book::getTitle(){
        return title;
    }
    void Book::setPubHouse(string pubHouse){
        this->pubHouse = pubHouse;
    }
    string Book::getPubHouse(){
        return pubHouse;
    }
    void Book::setPubYear(int pubYear){
        this->pubYear = pubYear;
    }
    int Book::getPubYear(){
        return pubYear;
    }
    void Book::display(){
       cout<<"title: "<<title<<"\n"<<"pubYear: "<<pubYear<<"\n"<<"pubHouse: "<<pubHouse<<endl;
    }
