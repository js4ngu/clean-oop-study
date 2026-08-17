#include <iostream>
#define ASNSWER

class Point {
private:
    int x_;
    int y_;
    
public:
    Point(int x, int y) : x_(x), y_(y){};
    ~Point(){};

    #ifdef ANSWER
    Point operator+(const Point &other) const;
    #else
    Point& operator+(const Point& other);
    #endif

    void Print() const {
      std::cout << '(' << Point::x_ << ", " << Point::y_ << ")\n";
    }

};


#ifdef ANSWER
Point Point::operator+(const Point &other) const{
    return {Point(x_ + other.x_ , y_ + other.y_)};
}
#else
Point&  Point::operator+(const Point& other) {
  x_ += other.x_;
  y_ += other.y_;
  return *this;
}
#endif
/*
a + b를 실행했을 때 a가 어떻게 되는가? => a += b;와 동일한 연산효과
일반적인 +의 의미와 일치하는가?        => 아니다
어떤 반환형과 구현이 더 적절한가?       => 
*/



int main() {
    Point a{1, 2};
    Point b{3, 4};


    #ifdef ANSWER
    Point c = a + b;
    c.Print();

    #else
    a + b;
    a.Print();
    #endif


    return 0;
}