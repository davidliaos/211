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

    const int& getID()const{
        return id;
    }
    const std::string& getDate() const{
        return date;
    }
    double getPrice() const{
        return price;
    }
    const std::string& getItem() const{
        return item;
    }
    
    void createPurchase(std::vector<Purchase>& purchases);
    void addPurchases(std::vector<Purchase>& purchases);

};
#endif // PURCHASE_H
