#ifndef POINT_H
#define POINT_H

class Point{
    int x, y;
public:
    Point(int xT, int yT){
        x=xT;
        y=yT;
    }
    // Definição do construtor sem parâmetros
    Point(){}
    
    Point add(const Point & p) const{
        return Point ( x+p.x, y+p.y);
    }

    Point & addEqual(const Point & p){
        x += p.x;
        y += p.y;
        return *this;
    }

    Point sub (const Point & p) const{
        return Point(x-p.x, y-p.y);
    }
    
    int getX() const{
        return x;
    }

    int getY() const{
        return y;
    } 

    bool isEqual(const Point & p) const{
        return x==p.x && y==p.y;
    }
    //Roda 90 graus com centro na origem
    Point & rotateRight(){
        int aux = x;
        x=y;
        y = -aux;
        return *this;
    }
};
#endif