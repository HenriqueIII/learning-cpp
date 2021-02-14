#ifndef PERSON_H
#define PERSON_H

#include <Point.h>

class Person{
    // Coordenadas correntes do player.
    Point position; 
    // Afeta a posição com Point
    void setPos(const Point &);
public:
    //  Posiciona a pessoa no centro do ecrã
    Person();
    /*  Retorna uma referência para Point constante,
        impedindo assim a violação do encapsulamento.   */
    const Point & getPos() const;
    //  Ocultar a imagem de pessoa no ecrã.
    void hide() const;
    //  Pôr como marca da pessoa no ecrã, o caracter 'P'
    void show() const;
    //  Deslocar a pessoa de uma distância delta.
    bool drag(const Point &);
    /*  Promove um salto da pessoa para um ponto com
        cordenadas aleatórias dentro do ecrã            */
    void jump();
};

#endif