#ifndef MONSTERS_H
#define MONSTERS_H

#include <Point.h>
#include <Monster.h>

class Monsters{
    //  Limite máximo permitido para inicio do jogo
    enum { MAX_MONSTERS=100 };
    //  Array de apontadores para monstros.
    Monster * monster[MAX_MONSTERS];
    //  Número de monstros corrente.
    int numOfMonsters;
    //  Número de monstros inicial.
    int maxOfMonsters;
    //  Ocultar todos os monstros.
    void hide() const;
    //  Deslocamento de todos os monstros em direcção a dest.
    void translate(const Point &);
    //  Remove os monstros que colidiram entre si.
    void removeCollisions();
public:
    Monsters();
    //  Inserir apontador para monstro m na cauda do array
    void insert(Monster *);
    //  Mostrar todos os monstros
    void show() const;
    //  Mover todos os monstros
    void move(const Point &);
    //  Retorna true se detectar colisões com pos (pessoa).
    bool detectCollisions(const Point &) const;
    /*  Remove todos os monstros que colidiram.
        Retorna true se morreram todos.                     */
    bool allDead();
};

#endif