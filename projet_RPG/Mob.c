#include <stdio.h>
#include <stdlib.h>
#include "Mob.h"
#include "Equipement.h"
#include "MobRace.h"


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


/*void hitMob(Mob* attack, Mob* defence)
{

}

void hitPlayer(Mob* attack, Player* defence)
{

}

void dropLoot(Mob* mob, Player* player)
{

}

void createRandomMob(char name[20], int pointsToAttribut)
{

}
*/
