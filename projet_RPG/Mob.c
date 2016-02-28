#include <stdio.h>
#include <stdlib.h>
#include "Mob.h"
#include "Equipement.h"
#include "MobRace.h"


struct Mob* Mob_ctor(int id, char* name, struct MobRace* mobRace, int hp, int attack, int relativeDefense, int absoluteDefense,
               int dodge, struct Equipment* equipment)
{
    struct Mob* p = malloc(sizeof(struct Mob));
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


/*void hitMob(struct Mob* attacker, struct Mob* defender)
{

}

void hitPlayer(struct Mob* attacker, struct Player* defender)
{

}

void dropLoot(struct Mob* mob, struct Player* player)
{

}


void createRandomMob(char name[20], int pointsToAttribut)
{
    struct Mob* randomMob = MobRace_ctor(name, 70, 5, 20, 3, 20);
    return randomMob;
}

*/
