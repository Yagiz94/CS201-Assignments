#include "Library.h"
#include "Book.h"
#include "Book.cpp"
#include <string>
Library::Library(){
    Book * libraryArr = new Book[noOfBooks];
    for(int i = 0; i < noOfBooks; i++){
        libraryArr[i] = new Book(title, pubHouse, pubYear);
    }
}
Library::~Library(){
    if(noOfBooks>0)
        delete[] libraryArr;
}
void addBook(string bookTitle,string publishingHouse, int publishingYear){
    for(int i = 0; i < noOfBooks; i++){
        if(bookTitle == libraryArr[i].getTitle()){
            cout<<"Warning"<<endl;
            break;
        }
        else{
            Book bookObj = new Book(bookTitle, publishingHouse, publishingYear);
            Book *libraryArr2 = new Book[noOfBooks + 1];
            for(int i = 0; i < noOfBooks; i++){
                libraryArr2[i] = libraryArr[i];
            }
            libraryArr2[noOfBooks] = BookObj;
            delete[]libraryArr;
            libraryArr = NULL;
            noOfBooks++;
            libraryArr = libraryArr2;
        }
    }
}
void removeBook(string bookTitle){
    for(int i = 0; i < noOfBooks; i++){
        if(bookTitle == libraryArr[i].getTitle()){
            delete libraryArr[i];
            noOfBooks--;
        }
        else{
            cout<<"Warning"<<endl;
            break;
        }
    }
    noOfBooks--;
    Book *libraryArr2 = new Book[noOfBooks];
    for(int i = 0; i < noOfBooks; i++){
        libraryArr2[i]= libraryArr[i];
    }
    delete[]libraryArr;
    libraryArr = NULL;
    libraryArr = libraryArr2;
}
void addCoauthor(string bookTitle, string coauthorName){                    //continue later!
    for(int i = 0; i < noOfBooks; i++){
        if(bookTitle == *libraryArr[i].getTitle()){
            string temp = new string[sizeAuthorList+1];
            for(int j = 0; j < sizeAuthorList; j++){
                temp = libraryArr[i][j];
                temp[j+1] = coauthorName;
            }
            delete[]arr[i];
        }
        else{
            cout<<"Warning"<<endl;
            break;
        }
    }
}
void removeCoauthor (string bookTitle, string coauthorName);
void displayAllBooks(){
    for(int i = 0; i < noOfBooks; i++){
        cout<<"Book #"<< i <<" "<<endl;
        cout<<libraryArr[i].printBook();
        cout<<endl;
        }
}
void displayBook(string bookTitle){
    for(int i = 0; i < noOfBooks; i++){
        if(bookTitle == libraryArr[i].getTitle()){
                cout<<libraryArr[i].printBook();
                for(int i = 0; i < sizeAuthorList; i++){
                cout<<"authorList for author: "<<i<<endl;
                cout<<libraryArr[i]<<endl;
        }
    }
}
void displayAuthor(string authorName){
    for(int i = 0; i < noOfBooks; i++){
        for(int j = 0; j < sizeAuthorList; j++){
            if(libraryArr[i][j] == authorName){
                cout<<*libraryArr[i].printBook();
                cout<<endl;
            }
        }
    }
}
