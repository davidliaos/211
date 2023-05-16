#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "customer.h"
#include "purchase.h"
using namespace std;
//consturctor
Customer::Customer(int id, string fn, string ln, string add, string cit, string stat, string zip, string phone) {
    this->id = id;
    firstName = fn;
    lastName = ln;
    address = add;
    city = cit;
    state = stat;
    zipcode = zip;
    phoneNumber = phone;
}
//default constructor
Customer::Customer() {
    this->id = 0;
    firstName = "";
    lastName = "";
    address = "";
    city = "";
    state = "";
    zipcode = "";
    phoneNumber = "";
}

//outputs all customors from the vector
void Customer::showCustomers(vector<Customer>& customers) {
        cout << "All Customers " << endl;

        for (auto customer : customers) {
            cout << "**************************************" << endl;
            cout << "Customer ID: " << customer.getID() << endl;
            cout << "First Name: " << customer.getFirstName() << endl;
            cout << "Last Name: " << customer.getLastName() << endl;
            cout << "Address: " << customer.getAddress() << endl;
            cout << "City: " << customer.getCity() << endl;
            cout << "State: " << customer.getState() << endl;
            cout << "Zipcode: " << customer.getZipcode() << endl;
            cout << "Phone Number: " << customer.getPhoneNumber() << endl;
        }

        cout << "**************************************" << endl;
    }

//sorting by ascending order, descending order,

//menu and user prompting for sorting options
void Customer::sortCustomers(vector<Customer>& customers) {
    int sortOption;
    cout << "Sort customers by ID in:\n1. Ascending order\n2. Descending order" << endl;
    cin >> sortOption;

    if (sortOption == 1) {
        for (int i = 1; i < customers.size(); i++) {
            for (int j = i - 1; j >= 0; j--) { // Fixed loop condition
                if (customers[j].getID() > customers[j + 1].getID()) {
                    Customer temp = customers[j];
                    customers[j] = customers[j + 1];
                    customers[j + 1] = temp;
                }
            }
        }
    } else if (sortOption == 2) {
        for (int i = 0; i < customers.size(); i++) {
            for (int j = 0; j < customers.size() - 1; j++) {
                if (customers[j].getID() < customers[j + 1].getID()) {
                    Customer temp = customers[j];
                    customers[j] = customers[j + 1];
                    customers[j + 1] = temp;
                }
            }
        }
    } else {
        cout << "Invalid sort option. Showing customers in the original order." << endl;
                for (int i = 1; i < customers.size(); i++) {
            for (int j = i - 1; j >= 0; j--) { // Fixed loop condition
                if (customers[j].getID() > customers[j + 1].getID()) {
                    Customer temp = customers[j];
                    customers[j] = customers[j + 1];
                    customers[j + 1] = temp;
                }
            }
        }
    }

    cout << "All Customers" << endl;
    for (auto customer : customers) {
        cout << "**************************************" << endl;
        cout << "Customer ID: " << customer.getID() << endl;
        cout << "First Name: " << customer.getFirstName() << endl;
        cout << "Last Name: " << customer.getLastName() << endl;
        cout << "Address: " << customer.getAddress() << endl;
        cout << "City: " << customer.getCity() << endl;
        cout << "State: " << customer.getState() << endl;
        cout << "Zipcode: " << customer.getZipcode() << endl;
        cout << "Phone Number: " << customer.getPhoneNumber() << endl;
    }

    cout << "**************************************" << endl;
}


//deletes customer entirely
void Customer::deleteCustomer(vector<Customer>& customers) {
    int idToDelete;
    cout << "Enter the ID of the customer to delete: ";
    cin >> idToDelete;

    for (int i = 0; i < customers.size(); i++) {
        if (customers[i].getID() == idToDelete) {
            customers.erase(customers.begin() + i);
            cout << "Customer with ID " << idToDelete << " has been deleted." << endl;
            return;
        }
    }

    cout << "Customer with ID " << idToDelete << " was not found." << endl;
}

//creates a customer and pushes it to the vector
void Customer::createCustomer(vector<Customer>& Customers) {

    int id;
    string fn, ln, add;
    string cit, stat;
    string zip;
    string phone;

    cout << "Enter player ID: ";
    cin >> id;
    cin.ignore(); // Ignore the remaining newline character

    cout << "Enter first name: ";
    getline(cin, fn);

    cout << "Enter last name: ";
    getline(cin, ln);

    cout << "Enter Address: ";
    getline(cin, add);

    cout << "Enter City: ";
    getline(cin, cit);

    cout << "Enter State: ";
    getline(cin, stat);

    cout << "Enter Zipcode: ";
    getline(cin, zip);

    cout << "Enter Phone number: ";
    getline(cin, phone);

    Customer newCustomer(id, fn, ln, add, cit, stat, zip, phone);
    Customers.push_back(newCustomer);

    cout << "Customer created successfully." << endl;
}

// recursive fuction to create additional customers until user exits with N
void Customer::addCustomer(vector<Customer>& customers) {
    createCustomer(customers);

    char response;
    cout << "Add another Customer? (Y/N): ";
    cin >> response;

    if (response == 'Y' || response == 'y') {
        addCustomer(customers);
    }
    else {
        cout << "Customers added successfully." << endl;
    }
}

//calculates and outputs a customer's total spend amount
void Customer::printTotalSpend(vector<Purchase>& purchases) {
    int customerId;
    double totalSpend = 0.0;

    cout << "Enter the customer ID to view total spend: ";
    cin >> customerId;

    for (const auto& purchase : purchases) {
        if (purchase.getID() == customerId) {
            totalSpend += purchase.getPrice();
        }
    }

    cout << "Total spend for customer ID " << customerId << ": $" << totalSpend << endl;
}

//updates a customer based on what user is requesting
void Customer::updateCustomer(vector<Customer>& customers) {
    int idToUpdate;
    cout << "Enter the ID of the customer to update: ";
    cin >> idToUpdate;

    bool customerFound = false;

    for (auto& customer : customers) {
        if (customer.getID() == idToUpdate) {
            customerFound = true;

            int updateOption;
            cout << "Which field would you like to update?\n1. First Name\n2. Last Name\n3. Address\n4. City\n5. State\n6. Zipcode\n7. Phone Number" << endl;
            cin >> updateOption;
            cin.ignore(); // Add this line to consume the newline character
            
            string updateValue;
            switch (updateOption) {
                case 1:
                    cout << "Enter new first name: ";
                    getline(cin, updateValue);
                    customer.setFirstName(updateValue);
                    break;
                case 2:
                    cout << "Enter new last name: ";
                    getline(cin, updateValue);
                    customer.setLastName(updateValue);
                    break;
                case 3:
                    cout << "Enter new address: ";
                    getline(cin, updateValue);
                    customer.setAddress(updateValue);
                    break;
                case 4:
                    cout << "Enter new city: ";
                    getline(cin, updateValue);
                    customer.setCity(updateValue);
                    break;
                case 5:
                    cout << "Enter new state: ";
                    getline(cin, updateValue);
                    customer.setState(updateValue);
                    break;
                case 6:
                    cout << "Enter new zipcode: ";
                    getline(cin, updateValue);
                    customer.setZipcode(updateValue);
                    break;
                case 7:
                    cout << "Enter new phone number: ";
                    getline(cin, updateValue);
                    customer.setPhoneNumber(updateValue);
                    break;
                default:
                    cout << "Invalid update option." << endl;
                    break;
            }
// all items are declared as strings so getline can be used, ID is not able to be changed for obvious reasons

            cout << "Customer information updated successfully." << endl;
            break;
        }
    }

    if (!customerFound) {
        cout << "Customer with ID " << idToUpdate << " was not found." << endl;
    }
}

//outputs the customer information and their associate purchase information
void Customer::printCustomer(vector<Purchase>& purchases,vector <Customer>& customers) {
    int idToPrint;
    cout << "Enter the ID of the customer to print: ";
    cin >> idToPrint;

    bool customerFound = false;

    for (auto& customer : customers) {
        if (customer.getID() == idToPrint) {
            customerFound = true;

            cout << "**************************************" << endl;
            cout << "Customer ID: " << customer.getID() << endl;
            cout << "First Name: " << customer.getFirstName() << endl;
            cout << "Last Name: " << customer.getLastName() << endl;
            cout << "Address: " << customer.getAddress() << endl;
            cout << "City: " << customer.getCity() << endl;
            cout << "State: " << customer.getState() << endl;
            cout << "Zipcode: " << customer.getZipcode() << endl;
            cout << "Phone Number: " << customer.getPhoneNumber() << endl;

// iterates through all purchases
    for(const auto& purchase : purchases) {
    if (purchase.getID() == idToPrint) {
        cout << "**************************************" << endl;
        cout << "Item Name: " << purchase.getItem() << endl;
        cout << "Purchase ID: " << purchase.getID() << endl;
        cout << "Date: " << purchase.getDate() << endl;
        cout << "Total Price: " << purchase.getPrice() << endl;
        
    }
}
    cout << "**************************************" << endl;
            }
        }
    }