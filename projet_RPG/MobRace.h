#ifndef MOBRACE_H_INCLUDED
#define MOBRACE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


typedef struct MobRace
{
    char* name;
    int hp;
    int attack;
    int relativeDefense;
    int absoluteDefense;
    int dodge;
} MobRace;

MobRace* MobRace_ctor(char* name, int hp, int attack, int relativeDefense, int absoluteDefense, int dodge)
{
    MobRace* p = malloc(sizeof(MobRace));
    p->name = name;
    p->hp = hp;
    p->attack = attack;
    p->relativeDefense = relativeDefense;
    p->absoluteDefense = absoluteDefense;
    p->dodge = dodge;
    return p;
}



#endif
