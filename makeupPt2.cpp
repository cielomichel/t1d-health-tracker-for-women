#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Makeup {
public:
    std::string name;
    std::string brand;
    double price;

    Makeup(std::string n, std::string b, double p)
        : name(n), brand(b), price(p) {}

    void print() const {
        std::cout << brand << " - " << name << " ($" << price << ")\n";
    }
};

int main() {

    std::vector<Makeup> bag = {
        Makeup("Bronzer", "Charlotte Tilbury", 40.00),
        Makeup("Concealer", "Dior", 48.00),
        Makeup("Blush", "Charlotte Tilbury", 43.00),
        Makeup("Mascara", "Maybelline", 10.00),
        Makeup("Lipstick", "MAC", 38.00)
    };

    std::cout << "Original List\n";
    for (const auto& item : bag)
        item.print();

    std::sort(bag.begin(), bag.end(),
        [](const Makeup& a, const Makeup& b) {
            return a.price < b.price;
        });

    std::cout << "\nSorted by Price (Low to High)\n";
    for (const auto& item : bag)
        item.print();

    int expensiveCount = std::count_if(bag.begin(), bag.end(),
        [](const Makeup& m) {
            return m.price > 30.00;
        });

    std::cout << "\nItems over $30: " << expensiveCount << "\n";

    auto it = std::find_if(bag.begin(), bag.end(),
        [](const Makeup& m) {
            return m.brand == "Dior";
        });

    if (it != bag.end()) {
        std::cout << "\nFound Dior Item\n";
        it->print();
    }

    bag.erase(
        std::remove_if(bag.begin(), bag.end(),
            [](const Makeup& m) {
                return m.price < 20.00;
            }),
        bag.end());

    std::cout << "\nAfter Removing Items Under $20\n";
    for (const auto& item : bag)
        item.print();

    return 0;
    
}
