#include <stdio.h>
#include <stdlib.h>

#include "Player.h"
#include "Mob.h"
#include "Equipement.h"
#include "StuffItem.h"

Player* Player_ctor(int id, Mob* mob, int lives, int gold, StuffItem** playerInventory,  StuffItem** itemsList, UsableItem** playerPotions, UsableItem** potionsList)
{
    Player* p = malloc(sizeof(Player));
    p->id = id;
    p->mob = mob;
    p->lives = lives;
    p->gold = gold;
    p->playerInventory = playerInventory;
    p->itemsList = itemsList;
    p->playerPotions = playerPotions;
    p->potionsList = potionsList;
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


Player* createPlayer(char name[20], int pointsToAttribut, DlistRace* racesList, DlistItems* itemsList, DlistItems* firstInventory, DlistUsable* potionsList)
{
    //Dlist* playerItemList = dlist_new();
    //createItemsList();

    StuffItem* phead = returnListElement(itemsList,0);
    StuffItem* pchest = returnListElement(itemsList,1);
    StuffItem* plegs = returnListElement(itemsList,2);
    StuffItem* pboots = returnListElement(itemsList,3);
    StuffItem* plefthand = returnListElement(itemsList,4);
    StuffItem* prighthand = returnListElement(itemsList,5);

    Equipment* playerEquipment = Equipment_ctor(phead, pchest, plegs, pboots, plefthand, prighthand);


    //Equipment* playerEquipment = Equipment_ctor(returnListElement(itemsList,6), returnListElement(itemsList,7), returnListElement(itemsList,8),
    //                                            returnListElement(itemsList,9), returnListElement(itemsList,10), returnListElement(itemsList,11));



    Mob* playerMob = Mob_ctor(0, name, &racesList[0], 100, 10, 50, 10, 10, playerEquipment);
    Player* playerCharacter = Player_ctor(0, playerMob, 3, 500, firstInventory, itemsList, selectFirstPotions(), potionsList);

    return playerCharacter;

}

