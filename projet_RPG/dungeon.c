#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "dungeon.h"
#include "Player.h"


//void startDungeon(struct Player* player);

void printPotionFight(struct Player* player, int n, int* pBoost, char* boostedStat, int* pDuration)
{
    int potionMax = dlistUsable_length(player->playerPotions);
    struct UsableItem* potion = returnListElementUsable(player->playerPotions, n);

    printf("\n#### Potion %d/%d: ####\n", n, potionMax);
    printf("%s\n", potion->name);
    printf("This potion gives");
    if(potion->hp != 0){
        printf(" %d hp ", potion->hp);
        boostedStat = 'h';
        *pBoost = potion->hp;
    }else if(potion->attack !=0){
        printf(" %d attack ", potion->attack);
        boostedStat = 'a';
        *pBoost = potion->attack;
    }else if(potion->relativeDefense !=0){
        printf(" %d relative defense ", potion->relativeDefense);
        boostedStat = 'd';
        *pBoost = potion->relativeDefense;
    }else if(potion->absoluteDefense !=0){
        printf(" %d absolute defense ", potion->absoluteDefense);
        boostedStat = 'D';
        *pBoost = potion->absoluteDefense;
    }else if(potion->dodge !=0){
        printf(" %d dodge ", potion->dodge);
        boostedStat = 'e';
        *pBoost = potion->dodge;
    }
    if(potion->duration != 0){
        printf("for %d turns", potion->duration);
        *pDuration = potion->duration;
    }
    printf(".\n");
    printf("Use (U), check the next potion (N) or go back to the fight (Q) ? ");
}

int usePotionFight(struct Player* player, int* pBoost, char* boostedStat, int* pDuration)
{
    int i = 1;
    char* userInput = '0';
    int potionMax = dlistUsable_length(player->playerPotions);

    while(1){
        printPotionFight(player, i, pBoost, boostedStat, pDuration);
        fflush(stdin);
        scanf("%c", &userInput);
        if(userInput == 'U' ||userInput == 'u'){
            struct UsableItem* potion = returnListElementUsable(player->playerPotions, i);
            printf("%s used!\n", potion->name);
            dlistUsable_remove_id(player->playerPotions, i);
            return 1;
        }else if(userInput == 'N' || userInput == 'n'){
            if(i == dlistUsable_length(player->playerPotions)){
                i = 1;
            }else{
                i++;
            }
        }else if(userInput == 'Q' || userInput == 'q'){
            return 0;
        }
    }
}

// simulates the battle between the player and a mob, until one of them dies
void fightMob(struct Player* player,struct Mob* mob)
{
    // flag will detect if either the player or the mob dies during the encounter
    int flag = 1;
    int flagPotion = 0;
    int timer;
    //int potionUsed = 0;
    int boost = 0;
    int* pBoost = &boost;
    char* boostedStat = '0';
    int duration = 0;
    int* pDuration = &duration;
    char* userInput = '0';

    printf("You encounter a new monster: %s.\n", mob->name);
    printf(">>> The fight starts! <<<\n");

    while(flag){
        while(userInput != 'A' & userInput != 'a'){
            if(flagPotion){
                printf("Your potion effect is still active for %d turn" , duration);
                printf(duration == 1 ? ".\n" : "s.\n");
            }
            Label: printf("\nWhat do you want to do ?\n");
            printf("Attack the monster (A) or use a potion (P) ? ");
            fflush(stdin);
            scanf("%c", &userInput);
            if(userInput == 'P' || userInput == 'p'){
                if(flagPotion){
                    printf("You already have an active potion effect.\n");
                    goto Label;
                }
                flagPotion = usePotionFight(player, pBoost, boostedStat, pDuration);
            }
        }

        hitMob(player->mob, mob, flagPotion, boost, boostedStat);
        if(mob->hp < 1){
            flag = 0;
            fflush(stdout);
            printf("You defeated %s!\n", mob->name);
        }

        hitPlayer(mob, player, flagPotion, boost, boostedStat);
        if(player->mob->hp < 1) {
            flag = 0;
            printf("You died! RIP\n");
            printf("(Press (ENTER) to continue)");
            enterToContinue();
            if(player->lives > 0){
                playerDeath(player);
            }
        }

        if(flagPotion){
            duration -= 1;
            if(duration == 0){
                flagPotion = 0;
                printf("Your potion effect wore off.\n");
            }
        }
        userInput = '0';
    }
}

void endDungeon(struct Player* player)
{
    int userInput = '0';
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

// manages the dungeons fights and ending
void startDungeon(struct Player* player)
{
    int i = 0;
    int mobNumber = 3; //doRand(5, 10);

    printf("You enter in the dungeon.\n");
    createDungeonMobs(mobNumber, player);
    printf("There are %d monsters in the dungeon.\n", dlistMob_length(player->mobList) - 1);

    for(i=0; i<dlistMob_length(player->mobList)-1; i++){
        struct Mob* mob = returnListElementMob(player->mobList, i+2);
        fightMob(player, mob);
        if(i == dlistMob_length(player->mobList) - 2){
            printf("(Press (ENTER) to continue) ");
            enterToContinue();
            endDungeon(player);
        }
    }
}
