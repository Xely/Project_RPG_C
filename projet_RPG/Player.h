#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Mob.h"


//void createPlayer(char name[20], /*int pointsToAttribut*/ Dlist* itemsList);

typedef struct Player
{
    int id;
    Mob* mob;
    int lives;
    int gold;
    StuffItem** playerItemsList;
    UsableItem** playerUsableItemsList;
} Player;

Player* Player_ctor(int id, Mob* mob, int lives, int gold, StuffItem** playerItemsList, UsableItem** playerUsableItemsList);

#endif
