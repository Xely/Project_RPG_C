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

UsableItem* UsableItem_ctor(char* name, int goldValue, int duration, int hp, int attack, int relativeDefense, int absoluteDefense, int dodge);

#endif
