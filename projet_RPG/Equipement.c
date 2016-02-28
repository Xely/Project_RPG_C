#include <stdio.h>
#include <stdlib.h>
#include "Equipement.h"

struct Equipment* Equipment_ctor(struct StuffItem* head, struct StuffItem* chest, struct StuffItem* leggings,
                                 struct StuffItem* boots, struct StuffItem* leftHand, struct StuffItem* rightHand)
{
    struct Equipment* p = malloc(sizeof(struct Equipment));
    p->head = head;
    p->chest = chest;
    p->leggings = leggings;
    p->boots = boots;
    p->leftHand = leftHand;
    p->rightHand = rightHand;
    return p;
}

/*void calcAttack(struct Equipment* equipment, struct Mob* mob)
{

}

void calcRelDef(struct Equipment* equipment, struct Mob* mob)
{

}

void calcAbsDef(struct Equipment* equipment, struct Mob* mob)
{

}
*/
