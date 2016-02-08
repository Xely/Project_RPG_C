#include <stdio.h>
#include <stdlib.h>

#ifndef STUFFITEM_C_INCLUDED
#define STUFFITEM_H_INCLUDED

#include "StuffItem.h"
#include "Equipement.h"
#include "Mob.h"

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

void unEqpStuffItem(StuffItem* item, Mob* mob)
{
    switch(item->typeId;)
    {
    case 0:
        mob->equipment->head = itemList[0];
        break;
    case 1:
        mob->equipment->chest = itemList[0];
        break;
    case 2:
        mob->equipment->leggings = itemList[0];
        break;
    case 3:
        mob->equipment->boots = itemList[0];
        break;
    case 4:
        mob->equipment->leftHand = itemList[0];
        break;
    case 5:
        mob->equipment->rightHand = itemList[0];
        break;
    }
}

void sellStuffItem(StuffItem* item, Player* player)
{

}


#endif
