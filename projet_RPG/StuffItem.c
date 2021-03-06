#include <stdio.h>
#include <stdlib.h>
#define LIST_TYPE Items

#include "Player.h"
#include "Mob.h"
#include "Equipement.h"
#include "StuffItem.h"

void eqpStuffItem(struct StuffItem* item, struct Mob* mob);
void unEqpStuffItem(struct StuffItem* item, struct Mob* mob);
void sellStuffItem(struct StuffItem* item, struct Player* player);

struct StuffItem* StuffItem_ctor(char* name, int goldValue, int typeId, int hp, int attack, int relativeDefense, int absoluteDefense)
{
    struct StuffItem* p = malloc(sizeof(struct StuffItem));
    p->name = name;
    p->goldValue = goldValue;
    p->typeId = typeId;
    p->hp = hp;
    p->attack = attack;
    p->relativeDefense = relativeDefense;
    p->absoluteDefense = absoluteDefense;
    return p;
}

struct DlistItems *dlistItems_new(void)
{
    struct DlistItems *p_new = malloc(sizeof *p_new);
    if (p_new != NULL)
    {
        p_new->length = 0;
        p_new->p_head = NULL;
        p_new->p_tail = NULL;
    }
    return p_new;
}

// adds element at the end of the list
struct DlistItems *dlistItems_append(struct DlistItems *p_list, struct StuffItem stuffItem)
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

struct DlistItems *dlistItems_remove_id(struct DlistItems *p_list, int position)
{
    if (p_list != NULL)
    {
        struct nodeItems *p_temp = p_list->p_head;
        int i = 1;
        while (p_temp != NULL && i <= position)
        {
            if (position == i)
            {
                if (p_temp->p_next == NULL)
                {
                    p_list->p_tail = p_temp->p_prev;
                    p_list->p_tail->p_next = NULL;
                }
                else if (p_temp->p_prev == NULL)
                {
                    p_list->p_head = p_temp->p_next;
                    p_list->p_head->p_prev = NULL;
                }
                else
                {
                    p_temp->p_next->p_prev = p_temp->p_prev;
                    p_temp->p_prev->p_next = p_temp->p_next;
                }
                free(p_temp);
                p_list->length--;
            }
            else
            {
                p_temp = p_temp->p_next;
            }
            i++;
        }
    }
    return p_list;
}

struct DlistItems *dlistItems_remove(struct DlistItems *p_list, struct StuffItem stuffItem)
{
    if (p_list != NULL)
    {
        struct nodeItems *p_temp = p_list->p_head;
        int found = 0;
        while (p_temp != NULL && !found)
        {
            if (&p_temp->stuffItem == &stuffItem)
            {
                if (p_temp->p_next == NULL)
                {
                    p_list->p_tail = p_temp->p_prev;
                    p_list->p_tail->p_next = NULL;
                }
                else if (p_temp->p_prev == NULL)
                {
                    p_list->p_head = p_temp->p_next;
                    p_list->p_head->p_prev = NULL;
                }
                else
                {
                    p_temp->p_next->p_prev = p_temp->p_prev;
                    p_temp->p_prev->p_next = p_temp->p_next;
                }
                free(p_temp);
                p_list->length--;
                found = 1;
            }
            else
            {
                p_temp = p_temp->p_next;
            }
        }
    }
    return p_list;
}

size_t dlistItems_length(struct DlistItems *p_list)
{
    size_t ret = 0;
    if (p_list != NULL)
    {
        ret = p_list->length;
    }
    return ret;
}

struct StuffItem* returnListElementItem(struct DlistItems *p_list, int position)
{
    int i = 0;
    struct nodeItems *p_temp = p_list->p_head;
    for(i=0;i<position-1;i++){
        p_temp = p_temp->p_next;
    }
    struct StuffItem item_temp = p_temp->stuffItem;

    struct StuffItem* p_item = StuffItem_ctor(item_temp.name, item_temp.goldValue, item_temp.typeId, item_temp.hp, item_temp.attack,
                                              item_temp.relativeDefense, item_temp.absoluteDefense);
    return p_item;
}

// writes the whole list in a file
void writeToFileItems(struct DlistItems *p_list)
{
    FILE *fptr;
    fptr = fopen("./itemslist.txt","w+");

    struct StuffItem* stuffItem = malloc(sizeof(struct StuffItem));
    if (p_list != NULL)
    {
        struct nodeItems *p_temp = p_list->p_head;
        while (p_temp != NULL)
        {
            stuffItem = &p_temp->stuffItem;
            fwrite(stuffItem,sizeof(struct StuffItem),1,fptr);
            p_temp = p_temp->p_next;
        }
        //printf("\n");
    }
    fclose(fptr);
}

struct DlistItems* readFromFileItems()
{
    struct DlistItems *p_list = dlistItems_new();
    struct StuffItem* stuffItem = malloc(sizeof(struct StuffItem));
    FILE *fptr;

    fptr=fopen("./itemslist.txt","r");

    if (fptr) {
        /* File was opened successfully. */

        /* Attempt to read element one by one */
        while (fread(stuffItem,sizeof(struct StuffItem),1,fptr) == 1) {
            dlistItems_append(p_list, *StuffItem_ctor(stuffItem->name, stuffItem->goldValue, stuffItem->typeId, stuffItem->hp,
                                                      stuffItem->attack, stuffItem->relativeDefense, stuffItem->absoluteDefense));
        }
        //printf("\n");
    }

    fclose(fptr);

    return p_list;
}

/*Struct StuffItem* idToSlot(struct Mob* mob, int id)
{
    switch(id){
    case 0:
        return mob->equipment->head;
        break;
    case 1:
        return mob->equipment->chest;
        break;
    case 2:
        return mob->equipment->leggings;
        break;
    case 3:
        return mob->equipment->boots;
        break;
    case 4:
        return mob->equipment->leftHand;
        break;
    case 5:
        return mob->equipment->rightHand;
        break;
    }
}*/

struct DlistItems* createItemsList()
{
    struct DlistItems* itemsList = dlistItems_new();

    struct StuffItem* nohelmet = StuffItem_ctor("Empty", 0, 0, 0, 0, 0, 0);
    dlistItems_append(itemsList, *nohelmet);
    struct StuffItem* nochest = StuffItem_ctor("Empty", 0, 1, 0, 0, 0, 0);
    dlistItems_append(itemsList, *nochest);
    struct StuffItem* nolegs = StuffItem_ctor("Empty", 0, 2, 0, 0, 0, 0);
    dlistItems_append(itemsList, *nolegs);
    struct StuffItem* noboots = StuffItem_ctor("Empty", 0, 3, 0, 0, 0, 0);
    dlistItems_append(itemsList, *noboots);
    struct StuffItem* nolefthand = StuffItem_ctor("Empty", 0, 4, 0, 0, 0, 0);
    dlistItems_append(itemsList, *nolefthand);
    struct StuffItem* norighthand = StuffItem_ctor("Empty", 0, 5, 0, 0, 0, 0);
    dlistItems_append(itemsList, *norighthand);


    struct StuffItem* fatheadarmor = StuffItem_ctor("Super casque", 150, 0, 12, 0, 7, 2);
    dlistItems_append(itemsList, *fatheadarmor);
    struct StuffItem* fatchestarmor = StuffItem_ctor("Super torse", 230, 1, 18, 1, 12, 3);
    dlistItems_append(itemsList, *fatchestarmor);
    struct StuffItem* fatlegarmor = StuffItem_ctor("Supers jambis", 200, 2, 20, 0, 9, 2);
    dlistItems_append(itemsList, *fatlegarmor);
    struct StuffItem* fatboots = StuffItem_ctor("Super bottes", 80, 3, 12, 0, 5, 1);
    dlistItems_append(itemsList, *fatboots);
    struct StuffItem* fatshield = StuffItem_ctor("Super bouclier", 180, 4, 0, 0, 15, 5);
    dlistItems_append(itemsList, *fatshield);
    struct StuffItem* fatsword = StuffItem_ctor("Super epee", 350, 5, 0, 8, 0, 0);
    dlistItems_append(itemsList, *fatsword);

    writeToFileItems(itemsList);
    return itemsList;
}

struct DlistItems* getItems()
{
    struct DlistItems* itemsList = dlistItems_new();
    if(itemsList == readFromFileItems()){
        return itemsList;
    }else{
        return createItemsList();
    }
}

struct DlistItems* createFirstInventory()
{
    struct DlistItems* firstInventory = dlistItems_new();
    return firstInventory;
}

void eqpStuffItem(struct StuffItem* item, struct Mob* mob)
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

void unEqpStuffItem(struct StuffItem* item, struct Mob* mob)
{
    switch(item->typeId)
    {
    case 0:

        mob->equipment->head = returnListElementItem(getItems(), 0);
        break;
    case 1:
        mob->equipment->chest = returnListElementItem(getItems(), 1);
        break;
    case 2:
        mob->equipment->leggings = returnListElementItem(getItems(), 2);
        break;
    case 3:
        mob->equipment->boots = returnListElementItem(getItems(), 3);
        break;
    case 4:
        mob->equipment->leftHand = returnListElementItem(getItems(), 4);
        break;
    case 5:
        mob->equipment->rightHand = returnListElementItem(getItems(), 5);
        break;
    }
}

void replaceItemEquip(struct Player* player, int i)
{
    struct StuffItem* itemToEquip = returnListElementItem(player->playerInventory, i);
    struct StuffItem* currentItem;

    switch(itemToEquip->typeId){
    case 0:
        currentItem = player->mob->equipment->head;
        break;
    case 1:
        currentItem = player->mob->equipment->chest;
        break;
    case 2:
        currentItem = player->mob->equipment->leggings;
        break;
    case 3:
        currentItem = player->mob->equipment->boots;
        break;
    case 4:
        currentItem = player->mob->equipment->leftHand;
        break;
    case 5:
        currentItem = player->mob->equipment->rightHand;
        break;
    }
    printf("You have equipped %s. ", itemToEquip->name);
    if(currentItem->name != "Empty"){
        printf("%s has been placed in your inventory.", currentItem->name);
        dlistItems_append(player->playerInventory, *currentItem);
    }
    printf("\n");
    eqpStuffItem(itemToEquip, player->mob);
    if(dlistItems_length(player->playerInventory) == 1){
        player->playerInventory = dlistItems_new();
    }else{
        dlistItems_remove_id(player->playerInventory, i);
    }
}

void sellStuffItem(struct StuffItem* item, struct Player* player)
{
    int goldGained = (item->goldValue) * 0.7;
    player->gold += goldGained;
}
