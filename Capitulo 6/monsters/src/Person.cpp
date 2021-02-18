#include <Person.h>

Person::Person(){
    setPos(Point((dsp.MAX_X + dsp.MIN_X)/2, (dsp.MAX_Y + dsp.MIN_Y)/2));
}

bool Person::drag(const Point & delta){
    // Somar delta à position
    Point aux = position.add(delta);
    int y=aux.getY(), x=aux.getX();
    // Caso não saia fora movimenta a pessoa para a
    // nova posição e retorna true
    if(x >= dsp.MIN_X && x <= dsp.MAX_X && y >= dsp.MIN_Y && y <= dsp.MAX_Y){
        hide();
        setPos(aux);
        show();
        return true;
    }
    return false;
}

const Point & Person::getPos() const{
    return position;
}

void Person::setPos(const Point & p){
    position=p;
}

void Person::hide() const{
    dsp.putc(position.getX(), position.getY(), ' ');
}

void Person::show() const{
    dsp.putc(position.getX(), position.getY(), 'P', Display::YELLOW);
}

void Person::jump(){
    hide();
    setPos(Random::get(Point(0,0),Point(dsp.MAX_X,dsp.MAX_Y)));
    show();
}
