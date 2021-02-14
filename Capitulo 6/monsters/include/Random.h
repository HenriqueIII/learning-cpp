#ifndef RANDOM_H
#define RANDOM_H

#include "Point.h"

namespace Random{
    void init (unsigned s);
    void init ();
    unsigned get (unsigned max);
    unsigned get (unsigned min, unsigned max);
    Point get(Point min, Point max);
}

#endif