#ifndef STUFFITEM_H_INCLUDED
#define STUFFITEM_H_INCLUDED

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




#endif
