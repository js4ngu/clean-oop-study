#include <iostream>

class Notifier {
public:
    Notifier() = default;
    virtual ~Notifier() = default;

    virtual std::string Send(const std::string& message) const = 0;
};


class Email_Notifier : public Notifier {
public:
    Email_Notifier()  = default;
    ~Email_Notifier() = default;

    std::string Send(const std::string& message) const override;
};

std::string Email_Notifier::Send(const std::string& message) const {
    std::cout << "Email Notifier : ";
    return message;
};


class Console_Notifier : public Notifier {
public:
    Console_Notifier()  = default;
    ~Console_Notifier() = default;

    std::string Send(const std::string& message) const override;
};

std::string Console_Notifier::Send(const std::string& message) const {
    std::cout << "Console Notifier : ";
    return message;
};

void Notify(const Notifier& notifier, const std::string& message){
    std::cout << notifier.Send(message) << std::endl;
}


int main(void){
    Email_Notifier email;
    Console_Notifier console;

    Notify(email, "EMAIL!!!");
    Notify(console,"consle");
\
    return 0;
}