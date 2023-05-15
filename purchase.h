#ifndef PURCHASE_H
#define PURCHASE_H

#include <string>
#include <vector>

class Purchase {
public:
    int id;
    std::string item;
    std::string date;
    double price;
    Purchase(int id, std::string item, std::string date, double price);
    Purchase();

    int getID() const;
    const std::string& getDate() const;
    double getPrice() const;
    const std::string& getItem() const;
    
    void createPurchase(std::vector<Purchase>& purchases);
    void addPurchases(std::vector<Purchase>& purchases);

};
#endif // PURCHASE_H
