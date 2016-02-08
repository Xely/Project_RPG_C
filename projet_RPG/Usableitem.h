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

UsableItem* UsableItem_ctor(char* name, int goldValue, int duration, int hp, int attack, int relativeDefense, int absoluteDefense, int dodge) {
    UsableItem* p = malloc(sizeof(UsableItem));
    p->name = name;
    p->goldValue = goldValue;
    p->duration = duration;
    p->hp = hp;
    p->attack = attack;
    p->relativeDefense = relativeDefense;
    p->absoluteDefense = absoluteDefense;
    p->dodge;
    return p;
}


#endif
