#include <Monster.h>

void Monster::setPos(const Point & p){
    position=p;
}

Monster::Monster(const Point & p){
    setPos(p);
}
Monster::~Monster(){
    hide();
}
void Monster::hide() const{
    // Ocultar a imagem do monstro no ecrã
    dsp.putc(position.getX(), position.getY(), ' ');
}
void Monster::show() const{
    // Visualiza o monstro no ecrã
    dsp.putc(position.getX(), position.getY(), 'M', Display::RED);
}
const Point & Monster::getPos() const{
    return position;
}
void Monster::translate(const Point & dest){
    // Afecta aux com o calculo do salto unitário
    Point aux = dest.sub(getPos());
    if(aux.getX())
        aux.setX(aux.getX() > 0 ? 1 : -1);
    if(aux.getY())
        aux.setY(aux.getY() > 0 ? 1 : -1);
    // Atualiza as coordenadas do monstro somando aux
    if(aux.getX() || aux.getY())
        setPos(aux.add(getPos()));
}