#include <iostream>
#include <stdexcept>
#define USE_EXPLICT

class Product {
private:
    const char* name_;
    int price_;

public:
    Product(int price, const char* name);

    #ifdef USE_EXPLICT
        explicit Product(int price);
    #else
        Product(int price);
    #endif

    ~Product();

    void name() const;
    void price() const;
    bool IsCheaperThan(int amount) const;

};

Product::Product(int price, const char* name){
    if(price < 0){
        throw std::invalid_argument("가격은 음수가 될 수 없습니다."); //
    }
    price_= price;
    name_ = name;
}

Product::Product(int price){
    if(price < 0){
        throw std::invalid_argument("가격은 음수가 될 수 없습니다."); //
    }
    price_= price;
}

Product::~Product(){};

void Product::name() const{
    std::cout<< name_ <<std::endl;
}

void Product::price() const{
    std::cout<< price_ <<std::endl;
}

bool Product::IsCheaperThan(int amount) const{
    if (amount > price_){
        std::cout<< "상품가는 " << price_ << "이며, "<< amount << "보다 저렴합니다." <<std::endl;
        return true;
    }
    return false;
}

int main(){
    Product keyboard(50000, "Keyboard");

    keyboard.name();
    keyboard.price();
    keyboard.IsCheaperThan(60000);

    Product unnamed{30000};  // 명시적 생성
    Product invalid = 30000;

    return 0;
}