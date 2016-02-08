#ifndef MOB_H_INCLUDED
#define MOB_H_INCLUDED

#include "Equipement.h"
#include "MobRace.h"

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

Mob* Mob_ctor(int id, char* name, MobRace* mobRace, int hp, int attack, int relativeDefense, int absoluteDefense,
               int dodge, Equipment* equipment)
{
    Mob* p = malloc(sizeof(Mob));
    p->id = id;
    p->name = name;
    p->mobRace = mobRace;
    p->hp = hp;
    p->attack = attack;
    p->relativeDefense = relativeDefense;
    p->absoluteDefense = absoluteDefense;
    p->dodge = dodge;
    p->equipment = equipment;

    return p;
}

#endif
