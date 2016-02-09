#include "game.h"
#include "Player.h"

void startGame()
{
    Player* playerCharacter = createPlayer("Boby", 10, getRaces(), getItems(), createFirstInventory(), getUsable());
    printf("Vous, %s, avez %d hp. Votre casque est %s et donne %d hp.", playerCharacter->mob->name,
           playerCharacter->mob->hp, playerCharacter->mob->equipment->head->name, playerCharacter->mob->equipment->head->hp);


    eqpStuffItem(returnListElement(playerCharacter->itemsList, 7), playerCharacter->mob);

    printf("Vous, %s, avez %d hp. Votre casque est %s et donne %d hp.", playerCharacter->mob->name,
           playerCharacter->mob->hp, playerCharacter->mob->equipment->head->name, playerCharacter->mob->equipment->head->hp);

}
