#include <iostream>
#include "charset.h"

CharSet s1("abkuksdef"), s2("defrsvytghi"), s3, s4;

int main(int argc, char ** argv){
    s1.display();
    std::cout << "Cardinalidade s1 - " << s1.cardinal() << std::endl;
    s2.display();
    std::cout << "Cardinalidade s2 - " << s2.cardinal() << std::endl;
    s1.e(s3, s2);
    s3.display();
    std::cout << "Cardinalidade s3 - " << s3.cardinal() << std::endl;
    s3.remove('f');
    s3.display();
    std::cout << "Cardinalidade s3 - " << s3.cardinal() << std::endl;
    s1.ou(s4, s2);
    s4.display();
    std::cout << "Cardinalidade s4 - " << s4.cardinal() << std::endl;
    s4.insert('z');
    s4.display();
    std::cout << "Cardinalidade s4 - " << s4.cardinal() << std::endl;
}
