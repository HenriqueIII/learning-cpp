#include <Monsters.h>
#include <Monster.h>
#include <iostream>
Monsters::Monsters(){
    numOfMonsters = maxOfMonsters = 0;
}
void Monsters::insert(Monster * m){
    // Se maxOfMonsters  >= MAX_MONSTERS aborta o programa
    if(!(maxOfMonsters<MAX_MONSTERS))
        exit(1);
    // Inserir m na cauda
    monster[maxOfMonsters++]=m;
    // Incrementar o número de monstros
    ++numOfMonsters;
}
void Monsters::hide() const{
    for (int curr = 0; curr < maxOfMonsters; ++curr)
        if(monster[curr])
            monster[curr]->hide();
}
void Monsters::show() const{
    for (int curr = 0; curr < maxOfMonsters; ++curr)
        if(monster[curr])
            monster[curr]->show();
}
void Monsters::translate(const Point & dest){
    for (int curr = 0; curr < maxOfMonsters; ++curr)
        if(monster[curr])
            monster[curr]->translate(dest);
}
void Monsters::move(const Point & dest){
    hide();
    translate(dest);
    show();
}
bool Monsters::detectCollisions(const Point & pos) const {
    for (int curr=0; curr < maxOfMonsters; ++curr)
        if(monster[curr] && monster[curr]->getPos().isEqual(pos))
            return true;
    return false;
}
void Monsters::removeCollisions(){
    for (int i = 0; i < maxOfMonsters; ++i){
        if (!monster[i])
            continue;
        Point p = monster[i]->getPos();
        int collisions = 0;
        for (int j = i+1; j < maxOfMonsters; ++j){
            if(monster[j] && p.isEqual(monster[j]->getPos())){
                ++collisions;
                delete monster[j];
                monster[j]=NULL;
            }
        }
        if (collisions){
            numOfMonsters -= collisions+1;
            delete monster[i];
            monster[i]=NULL;
        }
    }
}
bool Monsters::allDead(){
    removeCollisions();
    return numOfMonsters==0;
}
