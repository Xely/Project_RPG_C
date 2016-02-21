#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "game.h"
#include "Player.h"

//void playerDeath(struct Player* player);
//void startGame();

// prints some lore whenever the player died but still has lives left


// manages the main parts of the game
void startGame()
{
    int flagAlive = 1;
    /*char name[20];

    printf("Hello young aventurer, and welcome to the blabla.\nWhat is your name ?");
    scanf("%s", name);*/

    struct Player* playerCharacter = createPlayer("Bobby", 10);

    //enterTavern(playerCharacter);
    while(flagAlive){
        startDungeon(playerCharacter);
        enterTavern(playerCharacter);
    }

    //doUsableItemEffect(returnListElementUsable(playerCharacter->playerPotions, 2), playerCharacter->mob);
    //removeUsableItemEffect(returnListElementUsable(playerCharacter->playerPotions, 2), playerCharacter->mob);

}
