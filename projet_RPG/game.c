#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "game.h"
#include "Player.h"

//void playerDeath(struct Player* player);
//void startGame();

void printGameWelcomeMenu()
{
    printf(" =================================  \n");
    printf("||                               || \n");
    printf("||                               || \n");
    printf("||           Welcome to          || \n");
    printf("||                               || \n");
    printf("||       THE CHRONICLES OF       || \n");
    printf("||                               || \n");
    printf("||            VALHORA            || \n");
    printf("||                               || \n");
    printf("||                               || \n");
    printf(" =================================  \n");
}


// manages the main parts of the game
void startGame()
{
    //printGameWelcomeMenu();
    int flagAlive = 1;
    /*char name[20];

    printf("Hello young aventurer, and welcome to the blabla.\nWhat is your name ? ");
    scanf("%s", name);*/

    struct Player* playerCharacter = createPlayer("Bobby", 10);

    while(flagAlive){
        startDungeon(playerCharacter);
        enterTavern(playerCharacter);
    }

    //doUsableItemEffect(returnListElementUsable(playerCharacter->playerPotions, 2), playerCharacter->mob);
    //removeUsableItemEffect(returnListElementUsable(playerCharacter->playerPotions, 2), playerCharacter->mob);

}
