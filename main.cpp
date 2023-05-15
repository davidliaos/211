#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "customer.h"
#include "purchase.h"
using namespace std;

Purchase purchase;
Customer customer;

void readFromFile(vector<Customer>& customers, vector<Purchase>& purchases) {
    ifstream fin;
    string filename;

    // Read in Customer data
    filename = "Customers.txt";
    fin.open(filename);
    if (!fin) {
        cout << "Error: could not open file " << filename << endl;
        return;
    }

    int id;
    string fn, ln, add, city, state, zip, phone;
    while (fin >> id >> fn >> ln >> add >> city >> state >> zip >> phone) {
        Customer c(id, fn, ln, add, city, state, zip, phone);
        customers.push_back(c);
    }
    fin.close();

    // Read in Purchase data
    filename = "Purchases.txt";
    fin.open(filename);
    if (!fin) {
        cout << "Error: could not open file " << filename << endl;
        return;
    }

    int pid;
    string item, date;
    double price;
    while (fin >> pid >> item >> date >> price) {
        Purchase p(pid, item, date, price);
        purchases.push_back(p);
    }
    fin.close();
}


void exportToFile(const vector<Purchase>& purchases, const vector<Customer>& customers) {
    string filename;
    char file_choice;
    cout << "Which file would you like to modify? (P for Purchase.txt, C for Customer.txt): ";
    cin >> file_choice;

    ofstream fout;

    if (file_choice == 'P') {
        fout.open("Purchases.txt");
        if (!fout) {
            cout << "Error: could not open file Purchase.txt" << endl;
            return;
        }

        for (auto purchase : purchases) {
            fout << purchase.getID() << " "
                    << purchase.getItem() << " "
                    << purchase.getDate() << " "
                    << purchase.getPrice() << endl;
        }
        fout.close();
        cout << "Data has been saved to Purchase.txt." << endl;

    } else if (file_choice == 'C') {
        fout.open("Customers.txt");
        if (!fout) {
            cout << "Error: could not open file Customer.txt" << endl;
            return;
        }

        for (auto customer : customers) {
            fout << customer.getID() << " "
                    << customer.getFirstName() << " "
                    << customer.getLastName() << " "
                    << customer.getAddress() << " "
                    << customer.getPhoneNumber() << endl;
        }
        fout.close();
        cout << "Data has been saved to Customer.txt." << endl;

    } else {
        cout << "Invalid file choice. Please try again." << endl;
    }
}
    

void menu(vector<Customer>& customers, vector<Purchase>& purchases) {
    int choice;

    do {
    cout << "╔════════════════════════════════════════════════════════╗" << endl;
    cout << "║              Welcome to David's Grocery Store            ║" << endl;
    cout << "╟──────────────────────────────────────────────────────────╢" << endl;
    cout << "║ Please choose an option:                                 ║" << endl;
    cout << "║    1. Print out list of all customers                     ║" << endl;
    cout << "║    2. Sort and print customer list                        ║" << endl;
    cout << "║    3. Print out a specific customer's account information ║" << endl;
    cout << "║       with all purchases                                  ║" << endl;
    cout << "║    4. Print out total spend for a customer's purchases    ║" << endl;
    cout << "║    5. Add a new customer                                  ║" << endl;
    cout << "║    6. Add multiple new customers                          ║" << endl;
    cout << "║    7. Update a customer's information                     ║" << endl;
    cout << "║    8. Delete a customer's information                     ║" << endl;
    cout << "║    9. Add a new customer's purchase                       ║" << endl;
    cout << "║    10. Add multiple new customer purchases                ║" << endl;
    cout << "║    11. Save changes to file                               ║" << endl;
    cout << "║    12. Exit                                               ║" << endl;
    cout << "╚════════════════════════════════════════════════════════╝" << endl;
    cin >> choice;

    switch (choice) {
            case 1:
                customer.showCustomers(customers);
                menu(customers,purchases);
                break;
            case 2:
                customer.sortCustomers(customers);
                menu(customers,purchases);
                break;
            case 3:
                customer.printCustomer(customers, purchases);
                menu(customers,purchases);
                break;
            
            case 4:
                customer.printTotalSpend(purchases);
                menu(customers,purchases);
                break;
            case 5:
                // Add a new customer
                customer.createCustomer(customers);
                menu(customers,purchases);
                break;
            case 6:
                // Add multiple new customers
                customer.addCustomer(customers);
                menu(customers,purchases);
                break;
            case 7:
                // Update a customer's information
                customer.updateCustomer(customers);
                menu(customers,purchases);
                break;
            case 8:
                // Delete a customer's information
                customer.deleteCustomer(customers);
                menu(customers,purchases);
                break;
            case 9:
                purchase.createPurchase(purchases);
                menu(customers,purchases);
                break;
            case 10:
                purchase.addPurchases(purchases);
                menu(customers,purchases);
                break;
            case 11:
                exportToFile(purchases,customers);
                menu(customers,purchases);
                break;
            case 12:
            // Exit the program
                    return;
                break;
    }
    } while (choice != 12);
}

int main(){
    vector<Customer> customers;
    vector<Purchase> purchases;
    readFromFile(customers,purchases);
    menu(customers,purchases);

}

