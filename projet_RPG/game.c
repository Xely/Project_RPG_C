#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "Player.h"

int fightMob(struct Player* player, struct Mob* mob);
void startDungeon(struct Player* player);


// simulates the battle between the player and a mob, until one of them dies
int fightMob(struct Player* player, struct Mob* mob)
{
    // flag will detect i either the player or the mob dies during the encounter
    int flag = 1;
    printf("You encounter a new monster: %s.\n", mob->name);
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
            printf("You died!\n");
            //playerDeath();
        }
    }

}

void startDungeon(struct Player* player)
{
    int i = 0;
    int fightResult = 1;
    printf("You enter in the dungeon.\n");
    createDungeonMobs(10, player);
    printf("There are %d monsters in the dungeon.\n", dlistMob_length(player->mobList)-1);
    printf("The first monster is %s. He has %d hp and %d attack.\n", returnListElementMob(player->mobList, 2)->name,
           returnListElementMob(player->mobList, 2)->hp, returnListElementMob(player->mobList, 2)->attack);

    for(i=0; i<dlistMob_length(player->mobList)-1; i++) {
        fightMob(player, returnListElementMob(player->mobList, i+2));
    }
}

void startGame()
{
    /*char name[20];

    printf("Hello young aventurer, and welcome to the blabla.\nWhat is your name ?");
    scanf("%s", name);*/

    struct Player* playerCharacter = createPlayer("Bobby", 10);

    //printf("Your name is %s", playerCharacter->mob->name);
    startDungeon(playerCharacter);




    //doUsableItemEffect(returnListElementUsable(playerCharacter->playerPotions, 2), playerCharacter->mob);
    //removeUsableItemEffect(returnListElementUsable(playerCharacter->playerPotions, 2), playerCharacter->mob);


}
