#include <stdio.h>
#include <stdlib.h>
#define LIST_TYPE Items

#include "Player.h"
#include "Mob.h"
#include "Equipement.h"
#include "StuffItem.h"

void eqpStuffItem(StuffItem* item, Mob* mob);
void unEqpStuffItem(StuffItem* item, Mob* mob, DlistItems* itemsList);
void sellStuffItem(StuffItem* item, Player* player);

StuffItem* StuffItem_ctor(char* name, int goldValue, int typeId, int hp, int attack, int relativeDefense, int absoluteDefense)
{
    StuffItem* p = malloc(sizeof(StuffItem));
    p->name = name;
    p->goldValue = goldValue;
    p->typeId = typeId;
    p->hp = hp;
    p->attack = attack;
    p->relativeDefense = relativeDefense;
    p->absoluteDefense = absoluteDefense;
    return p;
}



DlistItems *dlistItems_new(void)
{
    DlistItems *p_new = malloc(sizeof *p_new);
    if (p_new != NULL)
    {
        p_new->length = 0;
        p_new->p_head = NULL;
        p_new->p_tail = NULL;
    }
    return p_new;
}

// adds element at the end of the list
DlistItems *dlistItems_append(DlistItems *p_list, StuffItem stuffItem)
{
    if (p_list != NULL)
    {
        struct nodeItems *p_new = malloc(sizeof *p_new);
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

StuffItem* returnListElement(DlistItems *p_list, int position)
{
    int i = 0;
    struct nodeItems *p_temp = p_list->p_head;
    for(i=0;i<position-1;i++){
        p_temp = p_temp->p_next;
    }
    StuffItem item_temp = p_temp->stuffItem;
    return &item_temp;
}

// writes the whole list in a file
void writeToFileItems(DlistItems *p_list)
{
    FILE *fptr;
    fptr = fopen("./itemslist.txt","w+");

    StuffItem* stuffItem = malloc(sizeof(StuffItem));
    if (p_list != NULL)
    {
        struct nodeItems *p_temp = p_list->p_head;
        while (p_temp != NULL)
        {
            stuffItem = &p_temp->stuffItem;
            fwrite(stuffItem,sizeof(StuffItem),1,fptr);
            p_temp = p_temp->p_next;
        }
        //printf("\n");
    }
    fclose(fptr);
}

DlistItems* readFromFileItems(){
    DlistItems *p_list = dlistItems_new();
    StuffItem* stuffItem = malloc(sizeof(StuffItem));
    FILE *fptr;

    fptr=fopen("./itemslist.txt","r");

    if (fptr) {
        /* File was opened successfully. */

        /* Attempt to read element one by one */
        while (fread(stuffItem,sizeof(StuffItem),1,fptr) == 1) {
            dlistItems_append(p_list, *StuffItem_ctor(stuffItem->name, stuffItem->goldValue, stuffItem->typeId, stuffItem->hp,
                                                      stuffItem->attack, stuffItem->relativeDefense, stuffItem->absoluteDefense));
        }
        //printf("\n");
    }

    fclose(fptr);

    return p_list;
}

DlistItems* createItemsList()
{
    DlistItems* itemsList = dlistItems_new();

    StuffItem* nohelmet = StuffItem_ctor("Rien", 0, 0, 0, 0, 0, 0);
    dlistItems_append(itemsList, *nohelmet);
    StuffItem* nochest = StuffItem_ctor("Rien", 0, 0, 0, 0, 0, 0);
    dlistItems_append(itemsList, *nochest);
    StuffItem* nolegs = StuffItem_ctor("Rien", 0, 0, 0, 0, 0, 0);
    dlistItems_append(itemsList, *nolegs);
    StuffItem* noboots = StuffItem_ctor("Rien", 0, 0, 0, 0, 0, 0);
    dlistItems_append(itemsList, *noboots);
    StuffItem* nolefthand = StuffItem_ctor("Rien", 0, 0, 0, 0, 0, 0);
    dlistItems_append(itemsList, *nolefthand);
    StuffItem* norighthand = StuffItem_ctor("Rien", 0, 0, 0, 0, 0, 0);
    dlistItems_append(itemsList, *norighthand);


    StuffItem* fatheadarmor = StuffItem_ctor("Super casque", 150, 0, 12, 0, 7, 2);
    dlistItems_append(itemsList, *fatheadarmor);
    StuffItem* fatchestarmor = StuffItem_ctor("Super torse", 230, 1, 18, 1, 12, 3);
    dlistItems_append(itemsList, *fatchestarmor);
    StuffItem* fatlegarmor = StuffItem_ctor("Supers jambis", 200, 2, 20, 0, 9, 2);
    dlistItems_append(itemsList, *fatlegarmor);
    StuffItem* fatboots = StuffItem_ctor("Super bottes", 80, 3, 12, 0, 5, 1);
    dlistItems_append(itemsList, *fatboots);
    StuffItem* fatshield = StuffItem_ctor("Super bouclier", 180, 4, 0, 0, 15, 5);
    dlistItems_append(itemsList, *fatshield);
    StuffItem* fatsword = StuffItem_ctor("Super epee", 350, 5, 0, 8, 0, 0);
    dlistItems_append(itemsList, *fatsword);

    writeToFileItems(itemsList);
    return itemsList;
}

DlistItems* getItems()
{
    DlistItems* itemsList = dlistItems_new();
    if(itemsList == readFromFileItems()){
        return itemsList;
    }else{
        return createItemsList();
    }
}

DlistItems* createFirstInventory()
{
    DlistItems* firstInventory = dlistItems_new();
    return firstInventory;
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

void unEqpStuffItem(StuffItem* item, Mob* mob, DlistItems* itemsList)
{
    /*StuffItem* nohelmet = StuffItem_ctor("Rien", 0, 0, 0, 0, 0, 0);
    StuffItem* nochest = StuffItem_ctor("Rien", 0, 0, 0, 0, 0, 0);
    StuffItem* nolegs = StuffItem_ctor("Rien", 0, 0, 0, 0, 0, 0);
    StuffItem* noboots = StuffItem_ctor("Rien", 0, 0, 0, 0, 0, 0);
    StuffItem* nolefthand = StuffItem_ctor("Rien", 0, 0, 0, 0, 0, 0);
    StuffItem* norighthand = StuffItem_ctor("Rien", 0, 0, 0, 0, 0, 0);*/

    /*StuffItem nohelmet = returnListElement(itemsList, 0);
    StuffItem nochest = returnListElement(itemsList, 1);
    StuffItem nolegs = returnListElement(itemsList, 2);
    StuffItem noboots = returnListElement(itemsList, 3);
    StuffItem nolefthand = returnListElement(itemsList, 4);
    StuffItem norighthand = returnListElement(itemsList, 5);*/

    switch(item->typeId)
    {
    case 0:

        mob->equipment->head = returnListElement(itemsList, 0);
        break;
    case 1:
        mob->equipment->chest = returnListElement(itemsList, 1);
        break;
    case 2:
        mob->equipment->leggings = returnListElement(itemsList, 2);
        break;
    case 3:
        mob->equipment->boots = returnListElement(itemsList, 3);
        break;
    case 4:
        mob->equipment->leftHand = returnListElement(itemsList, 4);
        break;
    case 5:
        mob->equipment->rightHand = returnListElement(itemsList, 5);
        break;
    }
}

void sellStuffItem(StuffItem* item, Player* player)
{
    int goldGained = (item->goldValue) * 0.7;
    player->gold += goldGained;

}
