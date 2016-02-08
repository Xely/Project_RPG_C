#ifndef EQUIPEMENT_H_INCLUDED
#define EQUIPEMENT_H_INCLUDED

#include "StuffItem.h"


typedef struct Equipment{
    StuffItem* head;
    StuffItem* chest;
    StuffItem* leggings;
    StuffItem* boots;
    StuffItem* leftHand;
    StuffItem* rightHand;
} Equipment;

Equipment* Equipment_ctor(StuffItem* head, StuffItem* chest, StuffItem* leggings,
                          StuffItem* boots, StuffItem* leftHand, StuffItem* rightHand);

#endif
