#include <stdio.h>
#include <stdlib.h>

#ifndef STUFFITEM_C_INCLUDED
#define STUFFITEM_H_INCLUDED

#include "StuffItem.h"
#include "Equipement.h"
#include "Mob.h"
#include "player.h"

struct node
{
    StuffItem stuffItem;
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
Dlist *dlist_append(Dlist *p_list, StuffItem stuffItem)
{
    if (p_list != NULL)
    {
        struct node *p_new = malloc(sizeof *p_new);
        if (p_new != NULL)
        {
            p_new->stuffItem = stuffItem;
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

void createItemsList()
{
    Dlist* itemsList = dlist_new();

    StuffItem* nohelmet = StuffItem_ctor("Rien", 0, 0, 0, 0, 0, 0);
    dlist_append(itemsList, *nohelmet);
    StuffItem* nochest = StuffItem_ctor("Rien", 0, 0, 0, 0, 0, 0);
    dlist_append(itemsList, *nochest);
    StuffItem* nolegs = StuffItem_ctor("Rien", 0, 0, 0, 0, 0, 0);
    dlist_append(itemsList, *nolegs);
    StuffItem* noboots = StuffItem_ctor("Rien", 0, 0, 0, 0, 0, 0);
    dlist_append(itemsList, *noboots);
    StuffItem* nolefthand = StuffItem_ctor("Rien", 0, 0, 0, 0, 0, 0);
    dlist_append(itemsList, *nolefthand);
    StuffItem* norighthand = StuffItem_ctor("Rien", 0, 0, 0, 0, 0, 0);
    dlist_append(itemsList, *norighthand);

    StuffItem* fatheadarmor = StuffItem_ctor("Super casque", 150, 0, 12, 0, 7, 2);
    dlist_append(itemsList, *fatheadarmor);
    StuffItem* fatchestarmor = StuffItem_ctor("Super torse", 230, 1, 18, 1, 12, 3);
    dlist_append(itemsList, *fatchestarmor);
    StuffItem* fatlegarmor = StuffItem_ctor("Supers jambis", 200, 2, 20, 0, 9, 2);
    dlist_append(itemsList, *fatlegarmor);
    StuffItem* fatboots = StuffItem_ctor("Super bottes", 80, 3, 12, 0, 5, 1);
    dlist_append(itemsList, *fatboots);
    StuffItem* fatshield = StuffItem_ctor("Super bouclier", 180, 4, 0, 0, 15, 5);
    dlist_append(itemsList, *fatshield);
    StuffItem* fatsword = StuffItem_ctor("Super epee", 350, 5, 0, 8, 0, 0);
    dlist_append(itemsList, *fatsword);


    createPlayer("Julien", itemsList);

}


void eqpStuffItem(StuffItem* item, Mob* mob)
{
    switch(item->typeId)
    {
    case 0:
        mob->equipment->head = item;
        break;
    case 1:
        mob->equipment->chest = item;
        break;
    case 2:
        mob->equipment->leggings = item;
        break;
    case 3:
        mob->equipment->boots = item;
        break;
    case 4:
        mob->equipment->leftHand = item;
        break;
    case 5:
        mob->equipment->rightHand = item;
        break;
    }
}

void unEqpStuffItem(StuffItem* item, Mob* mob)
{
    StuffItem* nohelmet = StuffItem_ctor("Rien", 0, 0, 0, 0, 0, 0);
    StuffItem* nochest = StuffItem_ctor("Rien", 0, 0, 0, 0, 0, 0);
    StuffItem* nolegs = StuffItem_ctor("Rien", 0, 0, 0, 0, 0, 0);
    StuffItem* noboots = StuffItem_ctor("Rien", 0, 0, 0, 0, 0, 0);
    StuffItem* nolefthand = StuffItem_ctor("Rien", 0, 0, 0, 0, 0, 0);
    StuffItem* norighthand = StuffItem_ctor("Rien", 0, 0, 0, 0, 0, 0);

    switch(item->typeId)
    {
    case 0:
        mob->equipment->head = nohelmet;
        break;
    case 1:
        mob->equipment->chest = nochest;
        break;
    case 2:
        mob->equipment->leggings = nolegs;
        break;
    case 3:
        mob->equipment->boots = noboots;
        break;
    case 4:
        mob->equipment->leftHand = nolefthand;
        break;
    case 5:
        mob->equipment->rightHand = norighthand;
        break;
    }
}

void sellStuffItem(StuffItem* item, Player* player)
{
    int goldGained = (item->goldValue) * 0.7;
    player->gold += goldGained;

}


#endif
