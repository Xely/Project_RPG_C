#ifndef STUFFITEM_H_INCLUDED
#define STUFFITEM_H_INCLUDED

// contains every non-usable item in the game

typedef struct StuffItem{
    char* name;
    int goldValue;
    // typeId : 0=head, 1=chest, 2=leggings, 3=boots, 4=lefthand, 5=righthand
    int typeId;
    int hp;
    int attack;
    int relativeDefense;
    int absoluteDefense;
} StuffItem;

struct node
{
    StuffItem stuffItem;
    struct node *p_next;
    struct node *p_prev;
};

typedef struct Dlist
{
    size_t length;
    struct node *p_tail;
    struct node *p_head;
} Dlist;


StuffItem* StuffItem_ctor(char* name, int goldValue, int typeId, int hp,
                          int attack, int relativeDefense, int absoluteDefense);


Dlist *dlist_new(void);
Dlist *dlist_append(Dlist *p_list, StuffItem stuffItem);
StuffItem returnListElement(Dlist *p_list, int position);
int returnListElementGold(Dlist *p_list, int position);
void createItemsList();
//void eqpStuffItem(StuffItem* item, Mob* mob);
//void unEqpStuffItem(StuffItem* item, Mob* mob);
//void sellStuffItem(StuffItem* item, Player* player);
#endif
