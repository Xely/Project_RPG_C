#ifndef USABLEITEM_H_INCLUDED
#define USABLEITEM_H_INCLUDED




typedef struct UsableItem
{
    char* name;
    int goldValue;
    int duration;
    int hp;
    int attack;
    int relativeDefense;
    int absoluteDefense;
    int dodge;
} UsableItem;

struct nodeUsable
{
    UsableItem usableItem;
    struct nodeUsable *p_next;
    struct nodeUsable *p_prev;
};

typedef struct DlistUsable
{
    size_t length;
    struct nodeUsable *p_tail;
    struct nodeusable *p_head;
} DlistUsable;

UsableItem* UsableItem_ctor(char* name, int goldValue, int duration, int hp, int attack, int relativeDefense, int absoluteDefense, int dodge);
DlistUsable* createUsable();
DlistUsable* getUsable();
DlistUsable* selectFirstPotions();

#endif
