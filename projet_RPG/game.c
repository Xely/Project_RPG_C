#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "Player.h"

void startGame()
{

    Player* playerCharacter = createPlayer("Boby", 10, getRaces(), getItems(), createFirstInventory(), getUsable());


    printf("Votre casque est %s et donne %d hp.\n", playerCharacter->mob->equipment->head->name, playerCharacter->mob->equipment->head->hp);
    printf("Votre casque est %s et donne %d hp.\n", playerCharacter->mob->equipment->head->name, playerCharacter->mob->equipment->head->hp);
    printf("Votre casque est %s et donne %d hp.\n", playerCharacter->mob->equipment->head->name, playerCharacter->mob->equipment->head->hp);
    printf("Votre casque est %s et donne %d hp.\n", playerCharacter->mob->equipment->head->name, playerCharacter->mob->equipment->head->hp);
    printf("Votre casque est %s et donne %d hp.\n", playerCharacter->mob->equipment->head->name, playerCharacter->mob->equipment->head->hp);
    printf("Votre casque est %s et donne %d hp.\n", playerCharacter->mob->equipment->head->name, playerCharacter->mob->equipment->head->hp);
    printf("Votre casque est %s et donne %d hp.\n", playerCharacter->mob->equipment->head->name, playerCharacter->itemsList->);


    //eqpStuffItem(returnListElement(playerCharacter->itemsList, 6), playerCharacter->mob);
    //printf("J'equipe le casque.\n");

    /*printf("Vous, %s, avez %d hp. Votre casque est %s et donne %d hp.\n", playerCharacter->mob->name, playerCharacter->mob->hp, playerCharacter->mob->equipment->head->name, playerCharacter->mob->equipment->head->hp);
    printf("Vous, %s, avez %d hp. Votre arme est %s et donne %d d'attaque.\n", playerCharacter->mob->name,playerCharacter->mob->hp,
        playerCharacter->mob->equipment->rightHand->name, playerCharacter->mob->equipment->rightHand->attack);

    eqpStuffItem(returnListElement(playerCharacter->itemsList, 12), playerCharacter->mob);
    printf("j'equipe l'epee.\n");
    printf("Vous, %s, avez %d hp. Votre arme est %s et donne %d d'attaque.\n", playerCharacter->mob->name,playerCharacter->mob->hp,
        playerCharacter->mob->equipment->rightHand->name, playerCharacter->mob->equipment->rightHand->attack);

    unEqpStuffItem(returnListElement(playerCharacter->itemsList, 12), playerCharacter->mob, playerCharacter->itemsList);
    printf("je vire l'epee.\n");*/
    //printf("Vous, %s, avez %d hp. Votre casque est %s et donne %d hp.\n", playerCharacter->mob->name,
      //     playerCharacter->mob->hp, playerCharacter->mob->equipment->chest->name, playerCharacter->mob->equipment->head->hp);


}
