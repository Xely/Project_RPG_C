#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Mob.h"
#include "Usableitem.h"

typedef struct Player
{
    int id;
    Mob* mob;
    int lives;
    int gold;
    StuffItem** playerItemsList;
    UsableItem** playerUsableItemsList;
} Player;

Player* Player_ctor(int id, Mob* mob, int lives, int gold, StuffItem** playerItemsList, UsableItem** playerUsableItemsList)
{
    Player* p = malloc(sizeof(Player));
    p->id = id;
    p->mob = mob;
    p->lives = lives;
    p->gold = gold;
    p->playerItemsList = playerItemsList;
    p->playerUsableItemsList = playerUsableItemsList;
    return p;
}


#endif
