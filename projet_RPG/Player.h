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
    struct DlistItems* itemsList;
    struct DlistUsable* playerPotions;
    struct DlistUsable* potionsList;
};


struct Player* Player_ctor(int id, struct Mob* mob, int lives, int gold, struct DlistItems* playerInventory,  struct DlistItems* itemsList,
                    struct DlistUsable* playerPotions, struct DlistUsable* potionsList);
struct Player* createPlayer(char* name, int pointsToAttribut);

#endif
