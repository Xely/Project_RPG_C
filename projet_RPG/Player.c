#include <stdio.h>
#include <stdlib.h>

#ifndef PLAYER_C_INCLUDED
#define PLAYER_C_INCLUDED

#include "StuffItem.h"
#include "Equipement.h"
#include "Mob.h"
#include "StuffItem.c"

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


void createPlayer(char name[20], /*int pointsToAttribut*/ Dlist* itemsList)
{
    //Dlist* playerItemList = dlist_new();
    //createItemsList();

    StuffItem temp_head = returnListElement(itemsList,6);
    StuffItem* phead = &temp_head;
    StuffItem temp_chest = returnListElement(itemsList,7);
    StuffItem* pchest = &temp_chest;
    StuffItem temp_legs = returnListElement(itemsList,8);
    StuffItem* plegs = &temp_legs;
    StuffItem temp_boots = returnListElement(itemsList,9);
    StuffItem* pboots = &temp_boots;
    StuffItem temp_lefthand = returnListElement(itemsList,10);
    StuffItem* plefthand = &temp_lefthand;
    StuffItem temp_righthand = returnListElement(itemsList,11);
    StuffItem* prighthand = &temp_righthand;

    Equipment* playerEquipment = Equipment_ctor(phead, pchest, plegs, pboots, plefthand, prighthand);

    /*Mob* playerMob = Mob_ctor(0, name[20], human, 100, 10, 50, 10, 10, playerEquipment);
    Player* player = Player_ctor(0, playerMob, 3, 500, playerItemList);*/

}


#endif
