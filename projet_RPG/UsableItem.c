#include <stdio.h>
#include <stdlib.h>
#include "Usableitem.h"

UsableItem* UsableItem_ctor(char* name, int goldValue, int duration, int hp,
                            int attack, int relativeDefense, int absoluteDefense, int dodge)
{
    UsableItem* p = malloc(sizeof(UsableItem));
    p->name = name;
    p->goldValue = goldValue;
    p->duration = duration;
    p->hp = hp;
    p->attack = attack;
    p->relativeDefense = relativeDefense;
    p->absoluteDefense = absoluteDefense;
    p->dodge = dodge;
    return p;
}


/*void doUsableItemEffect(UsableItem* item, Mob* mob)
{


}

void removeUsableItemEffect(UsableItem* item, Mob* mob)
{


}

void sellUsableitem(UsableItem* item, Player* player)
{


}
*/
