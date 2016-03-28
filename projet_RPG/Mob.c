#include <stdio.h>
#include <stdlib.h>
#include "Mob.h"
#include "Equipement.h"
#include "MobRace.h"
#include "Player.h"

struct DlistMob *dlistMob_new(void)
{
    struct DlistMob* p_new = malloc(sizeof *p_new);
    if (p_new != NULL)
    {
        p_new->length = 0;
        p_new->p_head = NULL;
        p_new->p_tail = NULL;
    }
    return p_new;
}

// adds element at the end of the list
struct DlistMob *dlistMob_append(struct DlistMob *p_list, struct Mob mob)
{
    if (p_list != NULL)
    {
        struct nodeMob *p_new = malloc(sizeof *p_new);
        if (p_new != NULL)
        {
            p_new->mob = mob;
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

size_t dlistMob_length(struct DlistMob *p_list)
{
    size_t ret = 0;
    if (p_list != NULL)
    {
        ret = p_list->length;
    }
    return ret;
}

struct Mob* returnListElementMob(struct DlistMob *p_list, int position)
{
    int i = 0;
    struct nodeMob *p_temp = p_list->p_head;
    for(i=0;i<position-1;i++){
        p_temp = p_temp->p_next;
    }
    struct Mob mob_temp = p_temp->mob;

    struct Mob* p_mob = Mob_ctor(mob_temp.id,  mob_temp.name, mob_temp.mobRace, mob_temp.hp, mob_temp.attack,
                                 mob_temp.relativeDefense, mob_temp.absoluteDefense, mob_temp.dodge, mob_temp.equipment);
    return p_mob;
}

// writes the whole list in a file
void writeToFileMob(struct DlistMob *p_list)
{
    FILE *fptr;
    fptr = fopen("./moblist.txt","w+");

    struct Mob* mob = malloc(sizeof(struct Mob));
    if (p_list != NULL)
    {
        struct nodeMob *p_temp = p_list->p_head;
        while (p_temp != NULL)
        {
            mob = &p_temp->mob;
            fwrite(mob,sizeof(struct Mob),1,fptr);
            p_temp = p_temp->p_next;
        }
        //printf("\n");
    }
    fclose(fptr);
}

struct DlistMob* readFromFileMob()
{
    struct DlistMob *p_list = dlistMob_new();
    struct Mob* mob = malloc(sizeof(struct Mob));
    FILE *fptr;

    fptr=fopen("./moblist.txt","r");

    if (fptr) {
        /* File was opened successfully. */

        /* Attempt to read element one by one */
        while (fread(mob,sizeof(struct Mob),1,fptr) == 1) {
            dlistMob_append(p_list, *Mob_ctor(mob->id, mob->name, mob->mobRace, mob->hp, mob->attack,
                                              mob->relativeDefense, mob->absoluteDefense, mob->dodge, mob->equipment));
        }
        //printf("\n");
    }

    fclose(fptr);

    return p_list;
}

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

// generates a list of mobs with only the player in it
struct DlistMob* createMob(struct Mob* playerMob)
{
    struct DlistMob* mobList = dlistMob_new();
    dlistMob_append(mobList, *playerMob);

    writeToFileMob(mobList);

    return mobList;
}

struct DlistMob* getMobs(struct Mob* playerMob)
{
    struct DlistMob* mobList = dlistMob_new();
    if(mobList == readFromFileMob()){
        return mobList;
    }else{
        return createMob(playerMob);
    }
}

// attack of the player againt a monster
void hitMob(struct Mob* attacker, struct Mob* defender)
{
    int hit = 0;
    int playerAttack = attacker->attack;
    int playerAbsDef = attacker->absoluteDefense;
    int playerRelDef = attacker->relativeDefense;
    int playerDodge = attacker->dodge;

    int dodgeRand = dice(defender->dodge);
    printf("You attack %s ", defender->name);

    hit += dice(6) + dice(attacker->attack) + dice(attacker->attack);
    hit = hit * (1 - (int) (defender->relativeDefense / 100));
    hit = hit - defender->absoluteDefense;
    hit = max(hit, 0);

    if(dodgeRand != 1) {
        defender->hp -= hit;
        printf("and inflicts %d damage.\n", hit);
    } else {
        printf("but %s dodges the hit!\n", defender->name);
    }
}

// attack of a monster gainst the player
void hitPlayer(struct Mob* attacker, struct Player* defender, int flagPotion, int boost, char* boostedStat, int duration)
{
    int hit = 0;
    int dodgeRand = dice(defender->mob->dodge);
    printf("%s attacks you ", attacker->name);

    hit += dice(6) + dice(attacker->attack) + dice(attacker->attack);
    hit = hit * (1 - (int) (defender->mob->relativeDefense / 100));
    hit = hit - defender->mob->absoluteDefense;
    hit = max(hit, 0);

    if(dodgeRand != 1) {
        defender->mob->hp -= hit;
        printf("and inflicts %d damage to you!\n", hit);
    } else {
        printf("but you dodge the hit!\n");
    }
}
/*
void dropLoot(struct Mob* mob, struct Player* player)
{

}
*/

void createRandomMob(int id, int raceNumber, int pointsToAttribut, struct Player* player)
{
    struct StuffItem* mobEquipment = Equipment_ctor(returnListElementItem(getItems(),0), returnListElementItem(getItems(),1),
                                                   returnListElementItem(getItems(),2), returnListElementItem(getItems(),3),
                                                   returnListElementItem(getItems(),4), returnListElementItem(getItems(),5));

    /*char* mobName[50];
    char* race = ;
    strcpy(mobName, race);
    strcat(mobName, " mage");*/

    struct Mob* randomMob = Mob_ctor(id, returnListElementRace(getRaces(), raceNumber)->name, returnListElementRace(getRaces(), raceNumber),
                                     70, 5, 20, 3, 20, mobEquipment);

    dlistMob_append(player->mobList, *randomMob);
}

void createDungeonMobs(int mobNumber, struct Player* player)
{
    int mobRaceRandom = 0;
    int i = 0;
    for(i=0;i<mobNumber;i++){
        mobRaceRandom = doRand(0,6);
        createRandomMob(i + 1, mobRaceRandom, 5, player);
    }
}
