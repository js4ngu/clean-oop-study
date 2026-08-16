#include <iostream>

class Point{
public:
    Point(int _x, int _y){
        x = _x;
        y = _y;
    }
    
    // ~Point(); <= 특별히 소멸자를 정의할 필요가 없으면 선언 안해도됨!
    
    void print(){
        std::cout << "x: " << x << ", y: " << y << std::endl;
    }
private:
    int x;
    int y;
};

int main(){
    Point* pt1 = new Point(10, 20); // 포인터로 힙에 할당된 객체를 잡음
    pt1->print();                   // 포인터로 잡기에 주소값으로 접근
    delete pt1;

    Point pt2(20,30); // 스택에 직접 객체 생성
    pt2.print();      // 중괄호를 벗어나면 객체는 자동으로 삭제됨
}