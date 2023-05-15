

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "purchase.h"

using namespace std;

class Customer {
public:
    Customer(int id, string fn, string ln, string add, string cit, string stat, string zip, string phone);

    Customer();

        string getFirstName() {
            return firstName;
        }

        string getLastName() {
            return lastName;
        }

        string getAddress() {
            return address;
        }

        string getCity() {
            return city;
        }

        string getState() {
            return state;
        }

        string getZipcode() {
            return zipcode;
        }

        string getPhoneNumber() {
            return phoneNumber;
        }

        int getID() {
            return id;
        }

    void setID(int newID) {
        this->id = newID;
    }

    void setFirstName(string newFirstName){
        this->firstName = newFirstName;
    }

    void setLastName(string newLastName){
        this->lastName = newLastName;
    }
    void setAddress(string newAddress){
        this->address = newAddress;
    }
    void setCity(string newCity){
        this->city = newCity;
}
    void setState(string newState){
        this->state = newState;
}
    void setZipcode(string newZipcode){
        this->zipcode = newZipcode;
    }
    void setPhoneNumber(string newPhoneNumber){
        this->phoneNumber = newPhoneNumber;
    }
    void showCustomers(vector<Customer>& customers);

    void sortCustomers(vector<Customer>& customers);

    void deleteCustomer(vector<Customer>& customers);

    void createCustomer(vector<Customer>& customers);
    
    void addCustomer(vector<Customer>& customers);

    void updateCustomer(vector<Customer>& customers);

    void printCustomer(vector<Purchase>& purchases,vector<Customer>& customers);
    
    void printTotalSpend(vector<Purchase>& purchases);

    void sortCustomer(int x);

    int id;
    string firstName;
    string lastName;
    string address;
    string city;
    string state;
    string zipcode;
    string phoneNumber;
};

#endif
