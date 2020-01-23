#include <stdio.h>
#include <string>
#include "BankingSystem.h"
#include "Customer.h"
#include <iostream>
BankingSystem::BankingSystem(){

    customersHead=NULL;
    accountCount=0;
    userCount=0;
}
BankingSystem::~BankingSystem(){
    CustomerNode* cur=customersHead;
    while(cur!=NULL)
    {
        CustomerNode* temp=cur;
        cur=cur->next;
        delete temp;
    }
}
void BankingSystem::addCustomer(const int customerid, const std::string firstName, const std::string lastName){

    if(idExist(customerid)){
        std::cout<<"Customer "<<customerid<<" already exists\n";
        return;
    }
    if(checkExist(firstName,lastName)){
        std::cout<<"Customer "<<firstName<<" "<<lastName<<" already exists\n";
        return;
    }
        CustomerNode *newNode=new CustomerNode;
        Customer* newCustomer=new Customer(customerid,firstName,lastName);
        newNode->next=NULL;
        newNode->customer=newCustomer;
        if(customersHead==NULL){
            customersHead=newNode;
        }
        else{
            struct CustomerNode *prev = customersHead;
            struct CustomerNode *current = customersHead;
            while ( current!=NULL){
                if(lastName.compare(current->customer->getLastName()) > 0){
                    prev=current;
                    current=current->next;
                }
                else if(lastName.compare(current->customer->getLastName())>0){
                    if(firstName.compare(current->customer->getName())>0){
                        prev=current;
                        current=current->next;
                    }
                    else{
                        break;
                    }
                }
                else{
                    while(current!=NULL&&lastName.compare(current->customer->getLastName()) == 0){
                        if(firstName.compare(current->customer->getName()) > 0){
                            prev=current;
                            current=current->next;
                        }
                        else if(firstName.compare(current->customer->getName()) > 0){
                            if(firstName.compare(current->customer->getName()) > 0){
                                prev=current;
                                current=current->next;
                            }
                            else{
                                break;
                            }
                        }
                    }
                    break;
                }
            }
            if(prev == customersHead){
                newNode->next=customersHead;
                customersHead=newNode;
                std::cout<<"Customer "<<customerid<<" has been added\n";
                return;
            }
            if(current!=customersHead)
                newNode->next=current;
            prev->next=newNode;
        }
        std::cout<<"Customer "<<customerid<<" has been added\n";
}
void BankingSystem::showAllAccounts(){
    std::cout<<"Account id\tCustomer id\tCustomer name\tBalance\n";
    CustomerNode* curr=customersHead;
    while(curr!=NULL){
        curr->customer->printAccounts();
        curr=curr->next;
    }
    std::cout<<"\n";
}
void BankingSystem::deleteCustomer(const int id){
    if(customersHead==NULL)
        return;
    if(customersHead->customer->getId()==id){
        delete customersHead;
        customersHead=customersHead->next;
        std::cout<<"Customer "<<id<<" has been deleted\n";

        return;
    }
    if(idExist(id)){
        CustomerNode *current=customersHead;

        while(current->next!=NULL)
        {
            if(current->next->customer->getId()==id){


                CustomerNode* temp=current->next;
                current->next=current->next->next;
                delete temp;
                std::cout<<"Customer "<<id<<" has been deleted\n";
                return;
            }
            current=current->next;
        }
    }
    std::cout<<"Customer "<<id<<" does not exist\n";
}
void BankingSystem::showAllCustomers(){
    std::cout<<"\nCustomer id\t Customer name";
    CustomerNode * curr=customersHead;
    while(curr!=NULL){
        std::cout<<"\n"<<curr->customer->getId()<<"\t"<<curr->customer->getName()<<" "<<curr->customer->getLastName();
        curr=curr->next;
    }
}
void BankingSystem::showCustomer(const int id){
    std::cout<<"\n";
    CustomerNode * curr=customersHead;
    while(curr!=NULL){
        if(curr->customer->getId()==id){
            curr->customer->showCustomer();
        }
        curr=curr->next;
    }
}
void BankingSystem::deleteAccount(const int id){
    CustomerNode* current=customersHead;
    bool done=false;
    while(current!=NULL){
       bool res= current->customer->deleteAccount(id);
        if(res==true){
            done=true;
            break;
        }
        current=current->next;
    }
    if(done){
        std::cout<<"Account "<<id<<" has been deleted\n";
    }
}
int BankingSystem::addAccount(const int id, const double balance){
    if(idExist(id)==false){
        std::cout<<"Customer "<<id<<" does not exist\n";
        return -1;
    }
    else{
        Account* account=new Account(++accountCount,balance);

        CustomerNode* node=customersHead;
        while(node!=NULL){
            if(node->customer->getId()==id){
                node->customer->addAccount(account);
                std::cout<<"Account "<<accountCount<<" added for customer "<<node->customer->getId()<<"\n";
            }
            node=node->next;
        }
    }
    return accountCount;
}
bool BankingSystem::checkExist(std::string name,std::string lastname){
    CustomerNode* current=customersHead;
    bool exist=false;
    while(current!=NULL){
        if(!current->customer->getName().compare(name) &&!current->customer->getLastName().compare(lastname)){
            exist=true;
        }
        current=current->next;
    }
    return exist;
}
bool BankingSystem::idExist(int id){
    CustomerNode* current=customersHead;
    bool exist=false;
    while(current!=NULL){
        if(current->customer->getId()==id){

            exist=true;
        }
        current=current->next;
    }
    return exist;
}
