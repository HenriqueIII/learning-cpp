#include <cassert>
#include <iostream>

class singleton{
    static singleton * instance;
public:
    singleton(){
        assert(instance == NULL);
        instance = this;
    }
    ~singleton(){
        delete instance;
    }
    static singleton * getInstance(){
        assert(instance != NULL);
        return instance;
    }
    void show(){
        std::cout << "Hello World from singleton\n";
    }
};

singleton * singleton::instance = new singleton;

int main(int argc, char ** argv){
    singleton::getInstance()->show();
}