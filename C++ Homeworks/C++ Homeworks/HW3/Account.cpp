#include <stdio.h>
#include <string>
#include "Account.h"
Account::Account(int id,double balance){
    this->id=id;
    this->balance=balance;
}
int Account::getId(){
    return this->id;
}
double Account::getBalance(){
    return this->balance;
}



