#include <iostream>

class Product {
private:
    const char* name_;
    int price_;
public:
    Product(const char* name, int price);
    ~Product() = default;

    bool operator==(const Product &other) const;
};

Product::Product(const char* name, int price) {
    name_ = name;
    price_ = price;
}

bool Product::operator==(const Product &other) const{
    return {(name_ == other.name_) && (price_ == other.price_)};
}

int main(){
    Product first{"Keyboard", 50000};
    Product second{"Keyboard", 50000};
    Product third{"Mouse", 30000};

    std::cout << (first == second) << '\n';  // true
    std::cout << (first == third) << '\n';   // false
}