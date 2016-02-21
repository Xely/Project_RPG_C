#include <stdio.h>
#include <stdlib.h>

#include "Player.h"
#include "Mob.h"
#include "Equipement.h"
#include "StuffItem.h"

void playerPermanentDeath()
{
    char* userInput = '0';
    system("cls");
    printf("--GAME OVER--");
    printf("You have died and have no lives left.\n\n");
    printf("Here is a recap of your accomplishments during your quest:\n");
    //printf("You have killed a total of %d mobs.\n", player->mobsKilled);
    //printf("You have completed a total of %d dungeons", player->dungeonsFinished);

    printf("Press (S) to start a new game or (Q) to leave the game");
    fflush(stdin);
    scanf("%c", &userInput);
    if(userInput == 'S' || userInput == 's'){
        startGame();
    }else if(userInput == 'Q' || userInput == 'q'){
        exit(0);
    }
}

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

struct Player* Player_ctor(int id, struct Mob* mob, int lives, int gold, struct DlistItems* playerInventory,
                           struct DlistUsable* playerPotions, struct DlistMob** mobList)
{
    struct Player* p = malloc(sizeof(struct Player));
    p->id = id;
    p->mob = mob;
    p->lives = lives;
    p->gold = gold;
    p->playerInventory = playerInventory;
    p->playerPotions = playerPotions;
    p->mobList = mobList;
    return p;
}

struct Player* createPlayer(char* name, int pointsToAttribut)
{
    struct Equipment* playerEquipment = Equipment_ctor(returnListElementItem(getItems(),7), returnListElementItem(getItems(),1),
                                                       returnListElementItem(getItems(),2), returnListElementItem(getItems(),3),
                                                       returnListElementItem(getItems(),4), returnListElementItem(getItems(),5));

    struct Mob* playerMob = Mob_ctor(0, name, returnListElementRace(getRaces(), 1), 100, 10, 50, 10, 10, playerEquipment);

    /*struct DlistMob* mobsList= dlistMob_new();
    dlistMob_append(mobsList, *playerMob);
    writeToFileMob(mobsList);*/

    struct Player* playerCharacter = Player_ctor(0, playerMob, 3, 500, createFirstInventory(), selectFirstPotions(), createMob(playerMob));


    return playerCharacter;

}

