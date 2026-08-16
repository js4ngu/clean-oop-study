#include <iostream>

class Session {
private:
    static int active_count_;

public:
    Session();
    Session(const Session& other);  //복사 생성자 => 얕은 복사임

    ~Session();

    static int ActiveCount();
};

int Session::active_count_ = 0;

Session::Session() {
    active_count_++;
    //std::cout << "생성자 호출 : " << active_count_ << std::endl;
}
Session::Session(const Session& other){ //복사 생성자
    active_count_++;
}

Session::~Session() {
    active_count_--;
}

int Session::ActiveCount(){
    return active_count_;
};

int main(){
    Session first;
//    std::cout << "현 상태 " << Session::ActiveCount() << '\n';  // 3
    {
        Session second;
        Session Session(second);
        std::cout << "현 상태 " << Session::ActiveCount() << '\n';  // 3
    } // 중괄호 나오면서 객체 2개가 없어지는거임
    std::cout  << "현 상태 " << Session::ActiveCount() << '\n';    // 1
}