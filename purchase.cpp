#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "purchase.h"
using namespace std;

void createPurchase(vector<Purchase>& purchases) {

    int id;
    string item, date;
    double price;

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

void addPurchases(vector<Purchase>& purchases) {
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
