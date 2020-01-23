#include <stdio.h>
#include <string>
#include "Customer.h"
#include "Account.h"
#include <iostream>
Customer::Customer(int id,std::string name,std::string lname)
    {
        this->id=id;
        this->name=name;
        this->lastName=lname;
        this->accountsHead=NULL;
    }
Customer::~Customer(){

    node* current=accountsHead;
    while(current!=NULL)
    {
        node* temp=current;
        current=current->next;
        delete temp->acc;
        delete  temp;
    }
}

int Customer::getId(){
    return this->id;
}
std::string Customer::getName(){
    return this->name;
}
std::string Customer::getLastName(){
    return this->lastName;
}
void Customer::printAccounts(){

    node* current=accountsHead;
    while(current!=NULL)
    {

        std::cout<<"\n"<<current->acc->getId()<<"\t"<<getId()<<"\t"<<getName()<<"\t"<<getLastName()<<"\t"<<current->acc->getBalance();
        current=current->next;
    }
}
bool Customer::deleteAccount(int id){

    node* current=accountsHead;
    if(current!=NULL&&current->acc->getId()==id)
    {
        accountsHead=accountsHead->next;
        delete current;
        return true;
    }
        if(accountsHead==NULL)
            return false;
        if(accountsHead->acc->getId()==id){
            std::cout<<"Account "<<id<<" has been deleted\n";
            delete accountsHead;
            accountsHead=accountsHead->next;
            return true;
        }
            while(current->next!=NULL)
            {
                if(current->next->acc->getId()==id){
                    node* temp=current->next;
                    current->next=current->next->next;
                    delete temp;
                    std::cout<<"Account "<<id<<" has been deleted\n";
                    return false;
                }
                current=current->next;
            }
    return false;
}
int Customer::getNoOfAccounts(){
    //int cnt = 0;
    int cnt = 0;
    node* curr = accountsHead;
    while(curr!= NULL)
    {
        cnt++;
        curr= curr->next;
    }
    return cnt;
}
void Customer::showCustomer(){

    std::cout<<"\nCustomer id:"<<getId()<<"  Customer name:"<<getName()<<"  NumberOfAccounts:"<<getNoOfAccounts();
    if(getNoOfAccounts() == 0){
            std::cout<<"\nAccount with ID: "<<getId()<<" does not exist";
    }
    if(getNoOfAccounts() > 0)
    {
        std::cout<<"\nAccounts of this customer:\nAccount id\tBalance";
        node* curr= accountsHead;
        while(curr!=NULL)
        {
            std::cout<<"\n"<<curr->acc->getId()<<"\t"<<curr->acc->getBalance();
            curr=curr->next;
        }
    }
}
void Customer::addAccount(Account* account)
{
    node* newNode=new node();
    newNode->next=NULL;
    newNode->acc=account;

    if(this->accountsHead==NULL){
        accountsHead=newNode;
        return;
    }
    else{
        struct node *current = this-> accountsHead;

        while ( current->next!=NULL && ( current->next->acc->getId() < account->getId())){
            current = current->next;
        }
        current->next=newNode;
    }
}


