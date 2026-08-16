#include <iostream>

class TextBuffer {
private:
    char* str_data;
    int str_len;
public:
    TextBuffer(const char* input);
    TextBuffer(const TextBuffer& other);
    ~TextBuffer();
    
    void Print() const;
};

TextBuffer::TextBuffer(const char* input) {
    str_len = std::strlen(input);
    str_data = new char[str_len + 1];   //new는 일종의 동적할당 (malloc)이다.
                                        //sizeof 어쩌구 알아서 해준다
    std::strcpy(str_data, input);
}

TextBuffer::TextBuffer(const TextBuffer& other) {
    str_len = other.str_len;
    str_data = new char[str_len + 1];   //new는 일종의 동적할당 (malloc)이다.
                                        //sizeof 어쩌구 알아서 해준다
    std::strcpy(str_data, other.str_data);
}

TextBuffer::~TextBuffer(){ 
    delete[] str_data;
}

void TextBuffer::Print () const{
    std::cout << str_data << std::endl;
}

int main(){
    TextBuffer original("Hello, C++");
    TextBuffer copied = original;

    original.Print();
    copied.Print();
    original.~TextBuffer();
    std::cout << "소멸자 호출 후 수행 : "<< std::endl;
    copied.Print();
}