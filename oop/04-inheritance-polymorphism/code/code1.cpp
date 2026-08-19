#include<iostream>
//#define VIRTUAL
class Player {
public:
    #ifndef VIRTUAL
    void Play() const { std::cout << "Player\n"; }
    #else
    virtual void Play() const { std::cout << "Player\n"; }
    #endif
};

class AudioPlayer : public Player {
public:
    void Play() const { std::cout << "Audio\n"; }
};

void Start(const Player& player) {
    player.Play();
}

int main(){
    AudioPlayer JS;
    Start(JS);

    return 0;
}