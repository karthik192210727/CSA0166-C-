#include <iostream>
#include <vector>
class ShoppingList {
private:
    struct Item {
        int code;
        double price;
    };
    std::vector<Item> items;
public:
    void addItem(int code, double price) {
        Item newItem;
        newItem.code = code;
        newItem.price = price;
        items.push_back(newItem);
    }
    void deleteItem(int code) {
        for (std::vector<Item>::iterator it = items.begin(); it != items.end(); ++it) {
            if (it->code == code) {
                items.erase(it);
                std::cout << "Item with code " << code << " deleted." << std::endl;
                return;
            }
        }
        std::cout << "Item with code " << code << " not found." << std::endl;
    }
    void printTotalValue() const {
        double total = 0;
        for (std::vector<Item>::const_iterator it = items.begin(); it != items.end(); ++it) {
            total += it->price;
        }
        std::cout << "Total value of the order: $" << total << std::endl;
    }
    void displayItems() const {
        std::cout << "Shopping List:" << std::endl;
        for (std::vector<Item>::const_iterator it = items.begin(); it != items.end(); ++it) {
            std::cout << "Code: " << it->code << ", Price: $" << it->price << std::endl;
        }
    }
};
int main() {
    ShoppingList list;
    list.addItem(101, 19.99);
    list.addItem(102, 5.49);
    list.addItem(103, 3.75);
    list.displayItems();
    list.deleteItem(102);
    list.displayItems();
    list.printTotalValue();
    return 0;
}
