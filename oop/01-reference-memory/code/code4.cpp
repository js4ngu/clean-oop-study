#include <iostream>

int main() {
    int a = 10;

    int& ref1 = a;          // ref1는 a의 별명
    const int& ref2 = a;    // ref2는 a의 별명이나 읽기 전용임

    ref1 = 20;              // (ref1 = a) = 20
    //ref2 = 30;              // ref2는 읽기 전용인데 값 집어넣을려해서 에러 터질거임

    a = 40;

    const int b = 50;       // b는 상수이다 == 수정이 불가하다
    //int& ref3 = b;        // ref3는 상수 b의 멸명
                            // 내 생각인데 컴파일 에러는 안 터질 것이다. 왜냐면 값을 건들이진 않았으니깐,,, 다만 문법이 allow할지는 모르겠다
                            // 문법에서 allow 하지 않는다!
    const int& ref4 = b;    // ref4는 상수b의 읽기전용 별명이다. 전혀 문제 안된다

    std::cout << ref4 << std::endl; // 전혀 문제 안된다

    return 0;
}