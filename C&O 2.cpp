#include <iostream>
#include <vector>
#include <algorithm> // Include this for std::remove_if

class Item {
public:
    int code;
    float price;

    Item(int c, float p) : code(c), price(p) {}
};

class ShoppingList {
    std::vector<Item> items;

public:
    void addItem(int code, float price) {
        items.push_back(Item(code, price)); // Use push_back instead of emplace_back
    }

    void deleteItem(int code) {
        for (std::vector<Item>::iterator it = items.begin(); it != items.end(); ) {
            if (it->code == code) {
                it = items.erase(it);
            } else {
                ++it;
            }
        }
    }

    float totalValue() {
        float total = 0;
        for (std::vector<Item>::iterator it = items.begin(); it != items.end(); ++it) {
            total += it->price;
        }
        return total;
    }

    void printList() {
        for (std::vector<Item>::iterator it = items.begin(); it != items.end(); ++it) {
            std::cout << "Code: " << it->code << ", Price: " << it->price << std::endl;
        }
        std::cout << "Total value: " << totalValue() << std::endl;
    }
};

int main() {
    ShoppingList list;
    list.addItem(101, 29.99);
    list.addItem(102, 49.99);
    list.addItem(103, 19.99);

    std::cout << "Shopping List:" << std::endl;
    list.printList();

    list.deleteItem(102);

    std::cout << "Updated Shopping List:" << std::endl;
    list.printList();

    return 0;
}
