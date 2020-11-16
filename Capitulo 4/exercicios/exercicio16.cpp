#include <iostream>

const int LINHAS = 3, COLUNAS = 3;
const int POSICOES = LINHAS*COLUNAS;
typedef char Tabuleiro[LINHAS][COLUNAS];

int linhaCheia(int, Tabuleiro, char);
int colunaCheia(int, Tabuleiro, char);
int diagonalCheia(Tabuleiro, char);
void mostra(Tabuleiro);
int primJogada();
int jogadaValida(int, Tabuleiro);
void init (Tabuleiro);

int upperCase(int l){
    if (l>='a'&&l<='z')
        return (l-'z'+'Z');
    return l;
}
void init(Tabuleiro t){
    for(int i=0; i < POSICOES; i++){
        //t[i/COLUNAS][i%COLUNAS]=i+1+'0';
        t[i/COLUNAS][i%COLUNAS]=' ';
    }
}
void mostra(Tabuleiro t){
    for(int i=0; i<LINHAS; i++){
        std::cout << ' ' << t[i][0] << " | " << t[i][1] << " | " << t[i][2] << std::endl;
        if(i!=2)
            std::cout << "---+---+---" << std::endl;
    }
}
int primJogada(){
    char v;
    do{
        std::cout << "Quem joga primeiro (X | O) ? ";
        std::cin >> v;
        v=upperCase(v);
    }while(v!='X' && v!='O');
    return v;
}
int jogadaValida(int p, Tabuleiro t){
    char cChar = t[p/COLUNAS][p%COLUNAS];
    if(cChar=='X'||cChar=='O'){
        std::cout << "jogada inválida" << std::endl;
        return 0;
    }
    return 1;
}
int linhaCheia(int pos, Tabuleiro t, char v){
    if (t[pos][0] == v && t[pos][1] == v && t[pos][2] == v){
        return 1;
    }
    return 0;
}
int colunaCheia(int pos, Tabuleiro t, char v){
    if (t[0][pos] == v && t[1][pos] == v && t[2][pos]==v){
        return 1;
    }
    return 0;
}
int diagonalCheia(Tabuleiro t, char v){
    if ((t[0][0] == v || t[0][2] == v) && t[1][1] == v && (t[2][2]==v||t[2][0]==v)){
        return 1;
    }
    return 0;
}
int ganhou (int pos, char j, Tabuleiro t){
    return linhaCheia(pos/COLUNAS, t, j) || colunaCheia(pos%COLUNAS, t, j) || diagonalCheia(t,j);
}

int main(){
    Tabuleiro tab;
    char vez;
    int pos;
    int numJogada=0;

    vez = primJogada();
    init (tab);

    do{
        mostra(tab);

        do{
            std::cout << "Jogada para " << vez << " [1...9]? ";
            std::cin >> pos;
            pos--;
        }while(!jogadaValida(pos, tab));

        tab[pos/COLUNAS][pos%COLUNAS] = vez;

        if (ganhou(pos, vez, tab)){
            mostra(tab);
            std::cout << "Ganhou o jogador " << vez << std::endl;
            return 0;
        }

        vez = (vez == 'X'?'O':'X');

    }while (numJogada < POSICOES);

    std::cout << "Jogo Empatado" << std::endl;
    return 0;
}
