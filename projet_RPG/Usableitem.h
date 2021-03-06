#ifndef USABLEITEM_H_INCLUDED
#define USABLEITEM_H_INCLUDED

struct UsableItem
{
    char* name;
    int goldValue;
    int totalDuration;
    int durationLeft;
    int used;
    int hp;
    int attack;
    int relativeDefense;
    int absoluteDefense;
    int dodge;
};

struct nodeUsable
{
    struct UsableItem usableItem;
    struct nodeUsable *p_next;
    struct nodeUsable *p_prev;
};

struct DlistUsable
{
    size_t length;
    struct nodeUsable *p_tail;
    struct nodeUsable *p_head;
};

struct UsableItem* UsableItem_ctor(char* name, int goldValue, int totalDuration, int hp,
                            int attack, int relativeDefense, int absoluteDefense, int dodge);
struct DlistUsable* createUsable();
struct DlistUsable* getUsable();
struct DlistUsable* selectFirstPotions();

#endif
