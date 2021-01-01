#include <iostream>
#include <curses.h>
int points=0;
int main(int argc, char** argv){
    initscr();
    noecho();
    curs_set(0);
    WINDOW * gamewin = newwin(LINES-3, COLS, 0, 0);
    WINDOW * scorewin = newwin(3 , COLS,LINES-3, 0);
    box(gamewin, 0,0);
    box(scorewin, 0,0);
    mvwprintw(scorewin, 0, 2, "SCORE");
    mvwprintw(scorewin, 1, 2, "Pontuacao: %d", points);
    wrefresh(scorewin);
    wrefresh(gamewin);
    wgetch(scorewin);
    endwin();
    return 0;
}
