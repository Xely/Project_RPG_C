#ifndef MOBRACE_H_INCLUDED
#define MOBRACE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Usableitem.h"



typedef struct MobRace
{
    char* name;
    int hp;
    int attack;
    int relativeDefense;
    int absoluteDefense;
    int dodge;
} MobRace;

MobRace* MobRace_ctor(char* name, int hp, int attack, int relativeDefense, int absoluteDefense, int dodge);
void defineRaces();

#endif
