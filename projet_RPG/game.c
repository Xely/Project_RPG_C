#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "game.h"
#include "Player.h"

//void playerDeath(struct Player* player);
//void startGame();

// prints some lore whenever the player died but still has lives left
void playerDeath(struct Player* player)
{
    system("cls");
    int strt_tmr = clock();
    printf("After several long minutes of pain, you heart finally stops...\n\n");
    while(clock()<(strt_tmr + 5000)){
    }
    printf("But as the light was about to disapear forever inside you, \nyou start feeling energy back...\n\n");
    while(clock()<(strt_tmr + 10000)){
    }
    printf("You wake up near the tavern, as if nothing ever happened...\n");
    while(clock()<(strt_tmr + 15000)){
    }
    player->lives -= 1;
    enterTavern(player);
}

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
