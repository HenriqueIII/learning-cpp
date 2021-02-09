#include <iostream>
#include <ncurses.h>
#include "Display.h"

Display dsp;

Display::Display(){
    if(this!=&dsp){
        std::cerr << "The only instance of Display is \"dsp\"" << std::endl;
        exit(1);
    }
    WINDOW *my_win;         //container window
    int startx,starty;      //where window start
    int width = 80, height=24;      //dimension of window
    initscr();              //start curses mode
    cbreak();           
    keypad(stdscr, TRUE);   //Functions key
    noecho();
    if(has_colors()==FALSE){
        std::cerr << "Your terminal does not support colors." << std::endl;
        exit(1);
    }
    width = width <= COLS ? width : COLS;
    height = height <= LINES ? height : LINES;

    starty = (LINES - height) / 2;
    startx = (COLS - width) / 2;
    my_win = newwin(height, width, starty, startx);
    refresh();
    box(my_win, 0, 0);
    wrefresh(my_win);
    getch();
}
Display::~Display(){
    endwin();
}