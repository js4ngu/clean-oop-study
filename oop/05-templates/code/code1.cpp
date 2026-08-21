#include <iostream>
#include <string>


template <typename T>
T add(const T& a, const T& b){
    return a+b;
}

int main(){
    std::cout << add(3, 7) << '\n';             // T는 int
    std::cout << add(3.1, 7.2) << '\n';             // T는 int
    std::cout << add<std::string>("a", "b") << '\n';             // T는 int
}