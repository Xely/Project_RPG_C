#ifndef TAVERN_H_INCLUDED
#define TAVERN_H_INCLUDED

#include "Player.h"

int printWeapon(int n);
void tavernBuyWeapons(struct Player* player);
void tavernBuyArmors(struct Player* player);
void tavernBuyPotions(struct Player* player);
void tavernBuy(struct Player* player);
void tavernSell(struct Player* player);
int tavernTrade(struct Player* player);
void tavernRest(struct Player* player);
void enterTavern(struct Player* player);

#endif // TAVERN_H_INCLUDED
