#ifndef MOB_H_INCLUDED
#define MOB_H_INCLUDED

#include "MobRace.h"
#include "Equipement.h"

struct Mob
{
    int id;
    char* name;
    struct MobRace* mobRace;
    int hp;
    int attack;
    int relativeDefense;
    int absoluteDefense;
    int dodge;
    struct Equipment* equipment;
};

struct Mob* Mob_ctor(int id, char* name, struct MobRace* mobRace, int hp, int attack, int relativeDefense,
              int absoluteDefense,int dodge, struct Equipment* equipment);

#endif
