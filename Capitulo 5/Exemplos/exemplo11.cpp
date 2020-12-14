#include <iostream>

class Count{
    const unsigned mod;
    unsigned val;
public:
    Count(unsigned m):mod(m){ val = 0;               }
    unsigned get() const    {return val;             }
    void set(unsigned v)    {val = v % mod           }
    void inc()              {
        if (++val==mod)
            val = 0;
        return *this;
    }
};

int main(){

}
