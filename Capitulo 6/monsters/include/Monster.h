#ifndef MONSTER_H
#define MONSTER_H

#include <Point.h>
#include <Display.h>

class Monster{
    // Posição corrente do monstro
    Point position;
    // Alterar a posição corrente
    void setPos(const Point &);
public:
    Monster(const Point &);
    ~Monster();
    // Ocultar a imagem do monstro no ecrã
    void hide() const;
    // Visualiza o monstro como 'M'
    void show() const;
    // Devolve a posição do monstro
    const Point & getPos() const;
    // Salto unitário na direcção dest (posiçao da pessoa)
    void translate(const Point &);
};

#endif