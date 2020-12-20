#include <curses.h>

int main(){
    initscr();
    printw("Hello world! Curses work");
    refresh();
    getch();

    endwin();
    return 0;
}
