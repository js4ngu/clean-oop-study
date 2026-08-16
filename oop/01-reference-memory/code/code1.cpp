#include <iostream>

class person {
public:
    person() : name("홍길동"), age(20) {
        std::cout << age << "살 " << name << "님이 생성되었습니다" << std::endl;
    }
    ~person() {
        std::cout << name << "님이 소멸되었습니다" << std::endl;
    }

private:
    std::string name;
    int age;
};


int main(){
    person* p1 = new person(); // 포인터로 접근 +  힘에 메모리 할당됨
    delete p1;
 
    person p2; // 스텍에 직접 객체 생성, 중괄호를 벗어나면 객체는 자동으로 삭제됨
               // 인자가 없는 기본 생성자는 괄호를 생략해야함
}

