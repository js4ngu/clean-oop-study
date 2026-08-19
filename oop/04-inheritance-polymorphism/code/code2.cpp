#include<iostream>

class Formatter {
public:
    virtual std::string Format() const = 0;
};

class JsonFormatter : public Formatter {
public:
    std::string Format() const override;
};

std::string JsonFormatter::Format() const{
    return "JSON Format";
}

int main(){
    JsonFormatter A;
    std::cout << A.Format() << std::endl;

    return 0;
}