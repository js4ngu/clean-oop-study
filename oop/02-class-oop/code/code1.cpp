#include <iostream>

class Battery {
private:
    int level_;
    
public:
    Battery();
    ~Battery();
    void Charge(int amount);
    bool Use(int amount);
    int level() const;

};

Battery::Battery() {
    level_ = 0;
}

Battery::~Battery() {
}

void Battery::Charge(int amount){
    if (amount > 0) {
        level_ = level_ + amount;
    }
    
}

bool Battery::Use(int amount){
    if(level_ >= amount){
        level_ = level_ - amount;
        return true;
    }
    else{
        return false;
    }
}

int Battery::level() const{
    return level_;
}


int main(){
    Battery battery;
    battery.Charge(50);

    std::cout << battery.Use(20) << '\n';  // 성공
    std::cout << battery.level() << '\n';  // 30
    std::cout << battery.Use(40) << '\n';  // 실패
    std::cout << battery.level() << '\n';  // 30

    return 0;
}