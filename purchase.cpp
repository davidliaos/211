#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "purchase.h"
using namespace std;
//constructor
    Purchase::Purchase(int id, const std::string item, const std::string date, string price){
        this->id = id;
        this->item = item;
        this->date = date;
        this->price = price;
    }
//default constructor
    Purchase::Purchase() : id(0), item(""), date(""), price(0.0) {}

// normal non recursive function to add purchase to a customer
void Purchase::createPurchase(vector<Purchase>& purchases) {

    int id;
    string item, date;
    string price;
    cout << "Enter Customer ID: ";
    cin >> id;
    cout << "Enter item: ";
    cin >> item;
    cout << "Enter date: ";
    cin >> date;
    cout << "Enter price: ";
    cin >> price;

    Purchase newPurchase(id, item, date, price);
    purchases.push_back(newPurchase);

    cout << "Purchase created successfully." << endl;
}

//same recursive function to add additional customers upon request
void Purchase::addPurchases(vector<Purchase>& purchases) {
    createPurchase(purchases);

    char response;
    cout << "Add another purchase? (Y/N): ";
    cin >> response;

    if (response == 'Y' || response == 'y') {
        addPurchases(purchases);
    }
    else {
        cout << "Purchases added successfully." << endl;
    }
}