#ifndef STUFFITEM_H_INCLUDED
#define STUFFITEM_H_INCLUDED
//#include "Player.h"

// contains every non-usable item in the game

typedef struct StuffItem
{
    char* name;
    int goldValue;
    // typeId : 0=head, 1=chest, 2=leggings, 3=boots, 4=lefthand, 5=righthand
    int typeId;
    int hp;
    int attack;
    int relativeDefense;
    int absoluteDefense;
} StuffItem;

struct nodeItems
{
    StuffItem stuffItem;
    struct nodeItems *p_next;
    struct nodeItems *p_prev;
};

typedef struct DlistItems
{
    size_t length;
    struct nodeItems *p_tail;
    struct nodeItems *p_head;
} DlistItems;

StuffItem* StuffItem_ctor(char* name, int goldValue, int typeId, int hp,
                          int attack, int relativeDefense, int absoluteDefense);
DlistItems *dlistItems_new(void);
DlistItems *dlistItems_append(DlistItems *p_list, StuffItem stuffItem);
StuffItem returnListElement(DlistItems *p_list, int position);
DlistItems* createItemsList();
DlistItems* getItems();

#endif
