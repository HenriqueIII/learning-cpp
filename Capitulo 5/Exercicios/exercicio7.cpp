/** Acrescente à classe String dinâmica analisada no texto e que consta do
 *  CD-ROM, os seguintes métodos:
 *      // Construir por cópia.
 *      String(const String & s);
 *      // Acrescentar à string receptora, a cadeia de caracteres
 *      // da string que lhe seja passada como parâmetro.
 *      concate(const String & s);
 * 
 *  a)  Escrever um programa que teste os métodos agora definidos, sugerindo-se
 *      que cumpra as seguintes acções:
 *      - Criar dois pequenos ficheiros de texto com frases triviais.
 *      - Ler dos ficheiros para os objectos String s1 e s2.
 *      - Criar uma string s3 por cópia de s1.
 *      - Concatenar s1 com s2.
 *      - Mostrar no ecrã as três Strings resultantes.
 */

#include <iostream>
#include <fstream>
#include "String.h"

void create(String * & s, const char * filename){
    std::ifstream f;
    f.open(filename);
    if(!f){
        std::cout << "Error opening \"" << filename << "\"" << std::endl;
        exit(1);
    }
    char c;
    while(f.get(c)){
        if(c=='\n')
            continue;
        char res[2];
        res[0]=c;
        res[1]='\0';
        s->concate(String(res));
    }
}

void a(){
    String s1("");
    String s2("");
    String * s1ptr = &s1;
    String * s2ptr = &s2;
    create(s1ptr, "texto1.txt");
    create(s2ptr, "texto2.txt");
    String s3(s1);
    s1.concate(s2);

    std::cout << "s1: " << s1.getStr() << std::endl;
    std::cout << "s2: " << s2.getStr() << std::endl;
    std::cout << "s3: " << s3.getStr() << std::endl;
}

int main(int argc, char ** argv){
    a();
    return 0;
}