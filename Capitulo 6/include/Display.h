#ifndef DISPLAY_H
#define DISPLAY_H

class Display{
    
public:
    enum {
        // Cores escuras
        BLACK,BLUE,GREEN,CYAN,RED,MAGENTA,BROWN,DARKGRAY,
        // Cores claras
        LIGHTGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN,
        LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
    };
    enum {MIN_X=0,MIN_Y=0,MAX_X=79,MAX_Y=49};

    // Programar a carta de video em modo texto 80x50, 16 cores e ocultar o cursor.
    Display();
    // Alterar a cor dos caracteres a escrever, para uma das 16 cores disponiveis.
    void setForeground(int color);
    // Alterar a cor de fundo dos caracteres, para uma das 16 cores disponiveis.
    void setBackground(int color);
    // Ocultar cursor.
    void cursorOff();
    // Mostrar cursor.
    void cursorOn();
    // Posicionar o cursor no ponto do ecrã de coordenadas (x,y).
    void setCursor(int x, int y);
    // Escrever o caracter chr na posição corrente do cursor.
    void putc(int chr);
    // Escrever o caracter chr no ponto de coordenadas (x,y) com a cor col.
    void putc(int x, int y, int chr, int col = WHITE);
    // Escrever a string str com inicio na posição corrente do cursor.
    void puts( char * str);
    // Repor a placa de video no estado em que se encontrava, com o cursor visivel.
    ~Display();
};

extern Display dsp;

#endif