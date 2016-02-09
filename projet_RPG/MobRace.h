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

struct nodeRace
{
    MobRace mobRace;
    struct nodeRace *p_next;
    struct nodeRace *p_prev;
};

typedef struct DlistRace
{
    size_t length;
    struct nodeRace *p_tail;
    struct nodeRace *p_head;
} DlistRace;

DlistRace* dlistRace_new(void);
DlistRace* dlistRace_append(DlistRace *p_list, MobRace mobRace);
MobRace* MobRace_ctor(char* name, int hp, int attack, int relativeDefense, int absoluteDefense, int dodge);
DlistRace* createRaces();
DlistRace* getRaces();

#endif
