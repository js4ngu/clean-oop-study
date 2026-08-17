#include <iostream>

class Point {
private:
    int x_;
    int y_;
    
public:
    Point(int x, int y) : x_(x), y_(y){};
    ~Point(){};
    
    void Print() const {
      std::cout << '(' << Point::x_ << ", " << Point::y_ << ")\n";
    }

    Point operator+(const Point& other) const{  //새로운 객체를 생성하는 것이기에 const 함수
        return Point{x_ + other.x_, y_ + other.y_};
    }

    bool operator==(const Point& other) const {
        return x_ == other.x_ && y_ == other.y_;
    }

    bool operator!=(const Point& other) const {
        return x_ != other.x_ && y_ != other.y_;
    }
};

class Counter {
private:
    int x_;
public:
    Counter(int x) : x_(x) {};
    ~Counter() = default;

    Counter operator+(const Counter& other) const{ //새로운 객체를 생성하는 것이기에 const 함수
        return {Counter(x_ + other.x_) };
    }

    Counter& operator+=(const Counter& other){  // 값을 수정하는 거기에 const 키워듣도 없고 포인터로 반환
        x_ = x_ + other.x_;
        return *this;
    }

    int value() const{
        return x_;
    }
};


int main() {
    Point a{1, 2};
    Point b{3, 4};

    std::cout << (a != b) << '\n';  // true

    Counter c{10};
    Counter d{5};
    Counter e = c + d;
    std::cout << e.value() << std::endl;
    c += d;
    std::cout <<c.value() << std::endl;
    
    return 0;
}