#include <iostream>
#include <string>
#define INT 0
#define DOUBLE 1
#define ANSWER DOUBLE

template <typename T>
T add(const T& a, const T& b){
    return a > b ? a : b;
}

int main(){
    #if ANSWER == INT
    std::cout << add(10, 20) << '\n';
    #elif ANSWER == DOUBLE
    std::cout << add(10, 20) << '\n';
    #endif

    return 0;
}