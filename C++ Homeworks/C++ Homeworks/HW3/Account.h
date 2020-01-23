#ifndef Account_hpp
#define Account_hpp
#include <stdio.h>
class Account{
    private :
    int id;
    double balance;
public:
    int getId();
    Account(int id,double balance);
    double getBalance();
};
#endif /* Account_hpp */
