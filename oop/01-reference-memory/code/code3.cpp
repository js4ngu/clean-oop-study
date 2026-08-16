#include <iostream>

void change(int& x)
{
    x = x + 10;
}

int main()
{
    int a = 5;
    int& b = a; // b는 a의 별명이다.

    b = 20;     // b=20 => b는 a의 별명이다 => b=a=20!!!
    change(a);  // b = b + 10 => (b = a) = 20 + 10 = 30

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    return 0;
}

