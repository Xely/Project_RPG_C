#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Mob.h"


struct Player
{
    int id;
    struct Mob* mob;
    int lives;
    int gold;
    struct DlistItems* playerInventory;
    struct DlistUsable* playerPotions;
    struct DlistMob* mobList;
};


struct Player* Player_ctor(int id, struct Mob* mob, int lives, int gold, struct DlistItems* playerInventory, struct DlistUsable* playerPotions,
                           struct DlistMob** mobList);
struct Player* createPlayer(char* name, int pointsToAttribut);
void playerDeath(struct Player* player);

#endif
