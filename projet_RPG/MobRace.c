#include <stdio.h>
#include <stdlib.h>

#include "MobRace.h"

DlistRace *dlistRace_new(void)
{
    DlistRace* p_new = malloc(sizeof *p_new);
    if (p_new != NULL)
    {
        p_new->length = 0;
        p_new->p_head = NULL;
        p_new->p_tail = NULL;
    }
    return p_new;
}

// adds element at the end of the list
DlistRace *dlistRace_append(DlistRace *p_list, MobRace mobRace)
{
    if (p_list != NULL)
    {
        struct nodeRace *p_new = malloc(sizeof *p_new);
        if (p_new != NULL)
        {
            p_new->mobRace = mobRace;
            p_new->p_next = NULL;
            if (p_list->p_tail == NULL)
            {
                p_new->p_prev = NULL;
                p_list->p_head = p_new;
                p_list->p_tail = p_new;
            }
            else
            {
                p_list->p_tail->p_next = p_new;
                p_new->p_prev = p_list->p_tail;
                p_list->p_tail = p_new;
            }
            p_list->length++;
        }
    }
    return p_list;
}

// writes the whole list in a file
void writeToFileRace(DlistRace *p_list)
{
    FILE *fptr;
    fptr = fopen("./raceslist.txt","w+");

    MobRace* mobRace = malloc(sizeof(MobRace));
    if (p_list != NULL)
    {
        struct nodeRace *p_temp = p_list->p_head;
        while (p_temp != NULL)
        {
            mobRace = &p_temp->mobRace;
            fwrite(mobRace,sizeof(MobRace),1,fptr);
            p_temp = p_temp->p_next;
        }
        //printf("\n");
    }
    fclose(fptr);
}

DlistRace* readFromFileRace(){
    DlistRace *p_list = dlistRace_new();
    MobRace* mobRace = malloc(sizeof(MobRace));
    FILE *fptr;

    fptr=fopen("./raceslist.txt","r");

    if (fptr) {
        /* File was opened successfully. */

        /* Attempt to read element one by one */
        while (fread(mobRace,sizeof(MobRace),1,fptr) == 1) {
            dlistRace_append(p_list, *MobRace_ctor(mobRace->name, mobRace->hp, mobRace->attack, mobRace->relativeDefense,
                                                   mobRace->absoluteDefense, mobRace->dodge));
        }
        //printf("\n");
    }

    fclose(fptr);

    return p_list;
}

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

// generates a list of all the races in the game
DlistRace* createRaces()
{
    DlistRace* racesList = dlistRace_new();

    MobRace* human = MobRace_ctor("Human", 100, 10, 50, 10, 10);
    dlistRace_append(racesList, *human);
    MobRace* elf = MobRace_ctor("Elf", 100, 10, 50, 10, 10);
    dlistRace_append(racesList, *elf);
    MobRace* dwarf = MobRace_ctor("Dwarf", 100, 10, 50, 10, 10);
    dlistRace_append(racesList, *dwarf);
    MobRace* goblin = MobRace_ctor("Goblin", 100, 10, 50, 10, 10);
    dlistRace_append(racesList, *goblin);
    MobRace* skeleton = MobRace_ctor("Skeleton", 100, 10, 50, 10, 10);
    dlistRace_append(racesList, *skeleton);
    MobRace* troll = MobRace_ctor("Troll", 100, 10, 50, 10, 10);
    dlistRace_append(racesList, *troll);

    writeToFileRace(racesList);

    return racesList;
}

DlistRace* getRaces()
{
    DlistRace* racesList = dlistRace_new();
    if(racesList == readFromFileRace()){
        return racesList;
    }else{
        return createRaces();
    }
}

