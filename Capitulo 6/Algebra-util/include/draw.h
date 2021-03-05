#ifndef DRAW_H
#define DRAW_H

#include "utils/Point.h"
#include "utils/DeltaTime.h"
#include <cstring>

namespace Draw{
    void fn(const char *);

    enum Direction {HORIZONTAL=0, VERTICAL=1};
    void drawline(Point base, int len, Direction dir){
        if (dir){
            dsp.putc(base.getX(),base.getY(),'^');
            base.setY(base.getY()+1);
        }
        for (int i=0; i<len; i++){
            if (dir){
                dsp.putc(base.getX(),base.getY(),'|');
                base.setY(base.getY()+1);
            }else{
                dsp.putc(base.getX(),base.getY(),'-');
                base.setX(base.getX()+1);
            }
        }
        if(!dir){
            dsp.putc(base.getX(),base.getY(),'>');
        }
    }
    void drawCenter(){
        int centerX, centerY;
        centerX=Display::MAX_X/2;
        centerY=(Display::MAX_Y-1)/2;
        dsp.putc(centerX,centerY,'+');
    }
    void plot(){
        DeltaTime timer(0.15F);
        for (int i=-30; i<31;i++){
            timer.start();
            int x = (i+((Display::MAX_X-1))/4);
            x=x*2;
            //int y = i; // função f(x)=x
            int y = i * i + 1; // função f(x)=x²+1
            y = (((Display::MAX_Y) - y + ((Display::MAX_Y-2)/2))/2);
            dsp.putc(x,y,'*',Display::YELLOW);
            char tmp[8];
            memset(tmp,' ',7);
            strcpy(tmp,"(");
            strcat(tmp,Common::itoa(x));
            strcat(tmp,",");
            strcat(tmp,Common::itoa(y));
            strcat(tmp,")");
            fn(tmp);
            timer.wait();
        }
    }
    void fn(const char * str){
        dsp.setCursor(Display::MIN_X+2, Display::MAX_Y);
        for(int i=0; i<8; i++)
            dsp.putc(' ');
        dsp.setCursor(Display::MIN_X+2, Display::MAX_Y);
        dsp.setForeground(Display::RED);
        dsp.puts(str);
    }    
};

#endif