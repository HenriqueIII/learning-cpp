#ifndef DELTATIME_H
#define DELTATIME_H

#include <ctime>

class DeltaTime{
    clock_t init;       // Valor retornado por clock()
    unsigned delta;     // Valor de tempo a definir
public:
    DeltaTime (float sec = 1){
        setDelta(sec);
    }
    // Converte os segundos em ticks de clock.
    void setDelta(float sec){
        delta = CLOCKS_PER_SEC * sec;
    }
    void start(){
        init = clock();
    }
    bool dttimeout(){
        return clock() - init >= delta; 
    }
    void wait(){
        while ( ! dttimeout());
    }
};

#endif