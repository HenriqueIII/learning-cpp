#ifndef RANDOM_H
#define RANDOM_H

#include <cstdlib>
#include <ctime>
#include "Point.h"

namespace Random{
    void init (unsigned s){
        srand(s);
    }
    void init (){
        srand((unsigned) time(NULL));
    }
    unsigned get (unsigned max){
        //RAND_MAX é o máximo valor retornado por rand().
        return (int) (((long)rand()*max)/RAND_MAX +1);
    }
    unsigned get (unsigned min, unsigned max){
        return get(max - min +1) + min;
    }
    Point get(Point min, Point max){
        return Point(get(min.getX(), max.getX()), get(min.getY(), max.getY()));
    }
}

#endif