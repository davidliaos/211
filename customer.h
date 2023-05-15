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

    string getFirstName();

    string getLastName();

    string getAddress();

    string getCity();

    string getState();

    string getZipcode();

    string getPhoneNumber();

    int getID();

    void setID(int newID);

    void setFirstName(string newFirstName);

    void setLastName(string newLastName);

    void setAddress(string newAddress);

    void setCity(string newCity);

    void setState(string newState);

    void setZipcode(string newZipcode);

    void setPhoneNumber(string newPhoneNumber);

    void showCustomers(vector<Customer>& customers);

    void sortCustomers(vector<Customer>& customers);

    void deleteCustomer(vector<Customer>& customers);

    void createCustomer(vector<Customer>& customers);
    
    void addCustomer(vector<Customer>& customers);

    void updateCustomer(vector<Customer>& customers);

    void printCustomer(vector<Customer>& customers,vector<Purchase>& purchases);
    
    void printTotalSpend(vector<Purchase>& purchases);

private:
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
