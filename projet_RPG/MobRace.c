#ifndef MOBRACE_C_INCLUDED
#define MOBRACE_C_INCLUDED

#include "MobRace.h"

void defineRaces()
{
    Dlist* racesList = dlist_new();

    MobRace human;
    human.name = "Human";
    human.hp = 100;
    human.attack = 10;
    human.relativeDefense = 50;
    human.absoluteDefense = 10;
    human.dodge = 10;
    dlist_append(racesList,human);

    MobRace elf;
    elf.name = "Elf";
    elf.hp = 100;
    elf.attack = 10;
    elf.relativeDefense = 50;
    elf.absoluteDefense = 10;
    elf.dodge = 10;
    dlist_append(racesList,elf);

    MobRace dwarf;
    dwarf.name = "Dwarf";
    dwarf.hp = 100;
    dwarf.attack = 10;
    dwarf.relativeDefense = 50;
    dwarf.absoluteDefense = 10;
    dwarf.dodge = 10;
    dlist_append(racesList,dwarf);

    MobRace goblin;
    goblin.name = "Goblin";
    goblin.hp = 100;
    goblin.attack = 10;
    goblin.relativeDefense = 50;
    goblin.absoluteDefense = 10;
    goblin.dodge = 10;
    dlist_append(racesList,human);

    MobRace skeleton;
    skeleton.name = "Skeleton";
    skeleton.hp = 100;
    skeleton.attack = 10;
    skeleton.relativeDefense = 50;
    skeleton.absoluteDefense = 10;
    skeleton.dodge = 10;
    dlist_append(racesList,skeleton);

    MobRace troll;
    troll.name = "Troll";
    troll.hp = 100;
    troll.attack = 10;
    troll.relativeDefense = 50;
    troll.absoluteDefense = 10;
    troll.dodge = 11;
    dlist_append(racesList,troll);

    printf("lala");

}


#endif
