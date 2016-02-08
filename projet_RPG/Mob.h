#ifndef MOB_H_INCLUDED
#define MOB_H_INCLUDED

#include "MobRace.h"
#include "Equipement.h"

typedef struct Mob
{
    int id;
    char* name;
    MobRace* mobRace;
    int hp;
    int attack;
    int relativeDefense;
    int absoluteDefense;
    int dodge;
    Equipment* equipment;
    // loot
} Mob;

Mob* Mob_ctor(int id, char* name, MobRace* mobRace, int hp, int attack, int relativeDefense,
              int absoluteDefense,int dodge, Equipment* equipment);

#endif
