#include <iostream>
#include <fstream>
#include <cstring>

const int MAX_FILENAME=255, MAX_PWORD=29;

int main(){
    char filename[MAX_FILENAME], word[MAX_PWORD], sword[MAX_PWORD], tmpword[MAX_PWORD]="", ch;
    int ccount, ocur=0, cpos=0,i=0,numcharo,numchard;

    //std::cout << "Qual o ficheiro que deseja abrir -> ";
    //std::cin.getline(filename, MAX_FILENAME);

    std::fstream file("texto.txt", std::ios::in|std::ios::out);

    if(!file){
        std::cout<<"Error opening file.";
        return 0;
    }

    std::cout << "Palavra a procurar -> ";
    std::cin >> sword;

    std::cout << "Palavra substituta -> ";
    std::cin >> word;

    file.seekg(0,file.end);
    ccount=file.tellg();

    file.seekg(file.beg);


    while((ch = file.get()) != EOF){
        if(!isalnum(ch)){
            if (strcmp(tmpword,sword)==0){
                    ocur++;
                    std::cout << ocur << " Ocorrencia ->" << std::endl;

                    cpos=file.tellg();
                    cpos = cpos < 15 ? -(strlen(sword)+1) : -15;
                    file.seekg(cpos,file.cur);

                    for (int k=0; k<40; k++){
                        ch = file.get();
                        std::cout.put(ch);
                    }

                    cpos = file.tellg();
                    cpos = cpos==40? -40:-25-strlen(sword)-1;
                    file.seekp(cpos, file.cur);

subs:
                    std::cout <<std::endl << "Deseja substituir?(s/n/ . p sair) ";
                    ch = tolower(std::cin.get());
                    std::cin.ignore(256,'\n');

                    if (ch == 's'){
                            numcharo=strlen(word);
                            numchard=strlen(sword);

                            for(int k=0;k<numcharo;k++){
                                file.put(word[k]);
                            }

                    }
                    else if (ch=='n'){
                        file.seekg(strlen(sword), file.cur);
                        continue;
                    }

                    else if (ch=='.')
                        break;
                    else
                        goto subs;



                    //std::cout << tmpword << std::endl;
            }

            i=0;
            for(int j=0;j<MAX_PWORD-1;j++)
                tmpword[j]='\0';
            continue;
        }
        tmpword[i++]=tolower(ch);
    }

    std::cout << ccount;

}
