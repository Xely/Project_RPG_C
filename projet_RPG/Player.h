#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Mob.h"

typedef struct Player
{
    int id;
    Mob mob;
    int hp;
    int gold;
    // loot
} Player;

Player* Player_ctor(int id, Mob mob, int hp, int gold) {
    Player* p = malloc(sizeof(Player));
    p->id = id;
    p->mob = mob;
    p->hp = hp;
    p->gold = gold;
    return p;
}


#endif
