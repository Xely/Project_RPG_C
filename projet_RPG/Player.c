#include <stdio.h>
#include <stdlib.h>

#include "Player.h"
#include "Mob.h"
#include "Equipement.h"
#include "StuffItem.h"

struct Player* Player_ctor(int id, struct Mob* mob, int lives, int gold, struct DlistItems* playerInventory,
                           struct DlistUsable* playerPotions, struct DlistMob** mobList)
{
    struct Player* p = malloc(sizeof(struct Player));
    p->id = id;
    p->mob = mob;
    p->lives = lives;
    p->gold = gold;
    p->playerInventory = playerInventory;
    p->playerPotions = playerPotions;
    p->mobList = mobList;
    return p;
}

/*struct node
{
    MobRace mobRace;
    struct node *p_next;
    struct node *p_prev;
};

typedef struct dlist
{
    size_t length;
    struct node *p_tail;
    struct node *p_head;
} Dlist;

Dlist *dlist_new(void)
{
    Dlist *p_new = malloc(sizeof *p_new);
    if (p_new != NULL)
    {
        p_new->length = 0;
        p_new->p_head = NULL;
        p_new->p_tail = NULL;
    }
    return p_new;
}

// adds element at the end of the list
Dlist *dlist_append(Dlist *p_list, MobRace mobRace)
{
    if (p_list != NULL)
    {
        struct node *p_new = malloc(sizeof *p_new);
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
}*/


struct Player* createPlayer(char* name, int pointsToAttribut)
{
    struct Equipment* playerEquipment = Equipment_ctor(returnListElementItem(getItems(),7), returnListElementItem(getItems(),1),
                                                       returnListElementItem(getItems(),2), returnListElementItem(getItems(),3),
                                                       returnListElementItem(getItems(),4), returnListElementItem(getItems(),5));

    struct Mob* playerMob = Mob_ctor(0, name, returnListElementRace(getRaces(), 1), 100, 10, 50, 10, 10, playerEquipment);

    /*struct DlistMob* mobsList= dlistMob_new();
    dlistMob_append(mobsList, *playerMob);
    writeToFileMob(mobsList);*/

    struct Player* playerCharacter = Player_ctor(0, playerMob, 3, 500, createFirstInventory(), selectFirstPotions(), createMob(playerMob));


    return playerCharacter;

}

