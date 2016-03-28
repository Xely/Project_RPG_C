#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "game.h"
#include "Player.h"

//void playerDeath(struct Player* player);
//void startGame();

void saveGame(struct Player* player)
{
    FILE *fptr;
    fptr = fopen("./gamesave.txt","wb");

    fwrite(player->mob->mobRace, sizeof(struct MobRace),1,fptr);
    // equipment
    /*fwrite(player->mob->equipment->head, sizeof(struct StuffItem),1,fptr);
    fwrite(player->mob->equipment->chest, sizeof(struct StuffItem),1,fptr);
    fwrite(player->mob->equipment->leggings, sizeof(struct StuffItem),1,fptr);
    fwrite(player->mob->equipment->boots, sizeof(struct StuffItem),1,fptr);
    fwrite(player->mob->equipment->leftHand, sizeof(struct StuffItem),1,fptr);
    fwrite(player->mob->equipment->rightHand, sizeof(struct StuffItem),1,fptr);
    // mob
    fwrite(player->mob, sizeof(struct Mob),1,fptr);
    // inventory
    struct StuffItem* stuffItem = malloc(sizeof(struct StuffItem));
    if (player->playerInventory != NULL)
    {
        struct nodeItems *p_temp = player->playerInventory->p_head;
        while (p_temp != NULL)
        {
            stuffItem = &p_temp->stuffItem;
            fwrite(stuffItem,sizeof(struct StuffItem),1,fptr);
            p_temp = p_temp->p_next;
        }
    }
    // potions
    struct UsableItem* usableItem = malloc(sizeof(struct UsableItem));
    if (player->playerPotions != NULL)
    {
        struct nodeUsable *p_temp = player->playerPotions->p_head;
        while (p_temp != NULL)
        {
            usableItem = &p_temp->usableItem;
            fwrite(usableItem,sizeof(struct UsableItem),1,fptr);
            p_temp = p_temp->p_next;
        }
    }
    // mob list
    struct Mob* mob = malloc(sizeof(struct Mob));
    if (player->mobList != NULL)
    {
        struct nodeMob *p_temp = player->mobList->p_head;
        while (p_temp != NULL)
        {
            mob = &p_temp->mob;
            fwrite(mob,sizeof(struct Mob),1,fptr);
            p_temp = p_temp->p_next;
        }
    }

    fwrite(player, sizeof(struct Player),1,fptr);*/
    fclose(fptr);
}

struct Player* loadGame()
{
    struct MobRace* mobRace = malloc(sizeof(struct MobRace));
    struct Equipment* equipment = malloc(sizeof(struct Equipment));
    struct StuffItem* stuffItem = malloc(sizeof(struct StuffItem));
    struct Mob* mob = malloc(sizeof(struct Mob));
    struct UsableItem* usableItem = malloc(sizeof(struct UsableItem));
    struct DlistItems *inventory = dlistItems_new();
    struct DlistUsable *potions = dlistUsable_new();
    struct DlistMob *mobList = dlistMob_new();
    struct Player* playerC = malloc(sizeof(struct Player));
    struct Player* player = malloc(sizeof(struct Player));

    FILE *fptr;
    fptr = fopen("./gamesave.txt","rb");

    if (fptr) {
        fread(mobRace, sizeof(struct MobRace),1,fptr);
        player->mob->mobRace = MobRace_ctor(mobRace->name, mobRace->hp, mobRace->attack, mobRace->relativeDefense, mobRace->absoluteDefense, mobRace->dodge);
        printf("race : %s", mobRace->name);
/*
        fread(stuffItem, sizeof(struct StuffItem),1,fptr);
        equipment->head = StuffItem_ctor(stuffItem->name, stuffItem->goldValue, stuffItem->typeId, stuffItem->hp, stuffItem->attack, stuffItem->relativeDefense, stuffItem->absoluteDefense);
        fread(stuffItem, sizeof(struct StuffItem),1,fptr);
        equipment->chest = StuffItem_ctor(stuffItem->name, stuffItem->goldValue, stuffItem->typeId, stuffItem->hp, stuffItem->attack, stuffItem->relativeDefense, stuffItem->absoluteDefense);
        fread(stuffItem, sizeof(struct StuffItem),1,fptr);
        equipment->leggings = StuffItem_ctor(stuffItem->name, stuffItem->goldValue, stuffItem->typeId, stuffItem->hp, stuffItem->attack, stuffItem->relativeDefense, stuffItem->absoluteDefense);
        fread(stuffItem, sizeof(struct StuffItem),1,fptr);
        equipment->boots = StuffItem_ctor(stuffItem->name, stuffItem->goldValue, stuffItem->typeId, stuffItem->hp, stuffItem->attack, stuffItem->relativeDefense, stuffItem->absoluteDefense);
        fread(stuffItem, sizeof(struct StuffItem),1,fptr);
        equipment->leftHand = StuffItem_ctor(stuffItem->name, stuffItem->goldValue, stuffItem->typeId, stuffItem->hp, stuffItem->attack, stuffItem->relativeDefense, stuffItem->absoluteDefense);
        fread(stuffItem, sizeof(struct StuffItem),1,fptr);
        equipment->rightHand = StuffItem_ctor(stuffItem->name, stuffItem->goldValue, stuffItem->typeId, stuffItem->hp, stuffItem->attack, stuffItem->relativeDefense, stuffItem->absoluteDefense);

        fread(mob, sizeof(struct Mob),1,fptr);
        printf("nom est %s", mob->name);
        player->mob = Mob_ctor(mob->id, mob->name, mobRace, mob->hp, mob->attack, mob->relativeDefense, mob->absoluteDefense, mob->dodge, equipment);

        fread(stuffItem,sizeof(struct StuffItem),1,fptr);
        dlistItems_append(inventory, *StuffItem_ctor(stuffItem->name, stuffItem->goldValue, stuffItem->typeId, stuffItem->hp,
                                                      stuffItem->attack, stuffItem->relativeDefense, stuffItem->absoluteDefense));

        fread(usableItem,sizeof(struct UsableItem),1,fptr);
        dlistUsable_append(potions, *UsableItem_ctor(usableItem->name, usableItem->goldValue, usableItem->totalDuration, usableItem->hp,usableItem->attack,
                                                         usableItem->relativeDefense, usableItem->absoluteDefense, usableItem->dodge));

        fread(mob,sizeof(struct Mob),1,fptr);
        dlistMob_append(mobList, *Mob_ctor(mob->id, mob->name, mob->mobRace, mob->hp, mob->attack,
                                              mob->relativeDefense, mob->absoluteDefense, mob->dodge, mob->equipment));

        fread(playerC, sizeof(struct Player),1,fptr);
        player = Player_ctor(playerC->id, mob, playerC->lives, playerC->gold, inventory, potions, mobList);
        printf("nom est %s", mob->name);*/
    }
    fclose(fptr);

    return player;
}

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

    /*while(flagAlive){
        startDungeon(playerCharacter);
        enterTavern(playerCharacter);
    }*/

    saveGame(playerCharacter);
    printf("Votre race est %s", playerCharacter->mob->mobRace->name);

    struct Player* player = loadGame();
    printf("lala");
    printf("Votre hp est %d", player->mob->mobRace->hp);
    printf("Votre race est %s", player->mob->mobRace->name);



    //doUsableItemEffect(returnListElementUsable(playerCharacter->playerPotions, 2), playerCharacter->mob);
    //removeUsableItemEffect(returnListElementUsable(playerCharacter->playerPotions, 2), playerCharacter->mob);

}
