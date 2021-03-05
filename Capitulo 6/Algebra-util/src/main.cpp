#include "utils/Display.h"
#include "utils/Keyboard.h"
#include "utils/Common.h"
#include "draw.h"
//#include "curses.h"

int main(int argc, char ** argv){
    //box(dsp.getWindow(),0,0);
    Draw::drawline(Point(Display::MAX_X/2,0), Display::MAX_Y-1, Draw::VERTICAL);
    Draw::drawline(Point(0,Display::MAX_Y/2), Display::MAX_X, Draw::HORIZONTAL);
    Draw::drawCenter();
    Draw::plot();
    Draw::fn("f(x)=x");
    kbd.get();
    return 0;
}