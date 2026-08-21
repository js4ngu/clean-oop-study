#include <iostream>
#include <string>

template <typename T>

class pair
{
private:
    T value1_;
    T value2_;
public:
    explicit pair(const T& value1, const T& value2){
        value1_ = value1;
        value2_ = value2;
    } //생성자

    const T& value() //getter
    {
        return value1_ > value2_ ? value1_ : value2_;
    }
};


int main()
{
    pair <int> pair(3,2);
    std::cout<< pair.value() << std::endl;

    return 0;
}