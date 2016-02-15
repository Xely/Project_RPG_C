#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "dungeon.h"
#include "Player.h"


// simulates the battle between the player and a mob, until one of them dies
int fightMob(struct Player* player, struct Mob* mob)
{
    // flag will detect i either the player or the mob dies during the encounter
    int flag = 1;
    int timer;
    printf("\nYou encounter a new monster: %s.\n", mob->name);
    printf("The fight starts!\n");

    while(flag == 1) {
        hitMob(player->mob, mob);
        if(mob->hp < 1){
            flag = 0;
            printf("You defeated %s!\n", mob->name);
            return flag;
        }
        hitPlayer(mob, player);
        if(player->mob->hp < 1) {
            flag = -1;
            printf("You died! RIP\n");
            timer = clock();
            while(clock()<(timer + 3000)){
            }
            if(player->lives > 0){
                    playerDeath(player);
            }
        }
    }
}

// manages the dungeons fights and ending
void startDungeon(struct Player* player)
{
    int i = 0;
    int fightResult = 1;
    int mobNumber = doRand(5, 10);
    int userInput = '0';

    printf("You enter in the dungeon.\n");
    createDungeonMobs(mobNumber, player);
    printf("There are %d monsters in the dungeon.\n", dlistMob_length(player->mobList) - 1);

    for(i=0; i<dlistMob_length(player->mobList)-1; i++){
        fightMob(player, returnListElementMob(player->mobList, i+2));
        if(i == dlistMob_length(player->mobList) - 2){
            int timer = clock();
            while(clock()<(timer + 3000)){
            }
            system("cls");
            printf("\nAs you defeat the last remaining monster in the dungeon, you walk forward \n");
            printf("and enter in what appears to be the former treasure room of the dungeon...\n\n");
            while(clock()<(timer + 9000)){
            }
            printf("Most of the treasures seems to be gone...\n\n");
            while(clock()<(timer + 13000)){
            }
            printf("However, in the back of the room, under a pile of junk,\n");
            printf("you find a item that could very well serve you...\n\n");
            while(clock()<(timer + 19000)){
            }
            // loot item
            printf("--SUPER ITEM has been added to your inventory!!!--\n\n");
            printf("After an entire day in this dungeon,  you feel exhausted and could use some rest at the local tavern.\n");
            printf("(Press enter to continue)");
            while (userInput != '\r' && userInput != '\n') {
                userInput = getchar();
            }
        }
    }
}
