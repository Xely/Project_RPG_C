#include <stdio.h>
#include <stdlib.h>
#include "Usableitem.h"



struct DlistUsable *dlistUsable_new(void)
{
    struct DlistUsable* p_new = malloc(sizeof *p_new);
    if (p_new != NULL)
    {
        p_new->length = 0;
        p_new->p_head = NULL;
        p_new->p_tail = NULL;
    }
    return p_new;
}

// adds element at the end of the list
struct DlistUsable* dlistUsable_append(struct DlistUsable *p_list, struct UsableItem usableItem)
{
    if (p_list != NULL)
    {
        struct nodeUsable *p_new = malloc(sizeof *p_new);
        if (p_new != NULL)
        {
            p_new->usableItem = usableItem;
            p_new->p_next = NULL;
            if (p_list->p_tail == NULL)
            {
                p_new->p_prev = NULL;
                p_list->p_head = p_new;
                p_list->p_tail = p_new;
            }
            else
            {
                p_list->p_tail->p_next = p_new;
                p_new->p_prev = p_list->p_tail;
                p_list->p_tail = p_new;
            }
            p_list->length++;
        }
    }
    return p_list;
}

// writes the whole list in a file
void writeToFileUsable(struct DlistUsable *p_list)
{
    FILE *fptr;
    fptr = fopen("./usablelist.txt","w+");

    struct UsableItem* usableItem = malloc(sizeof(struct UsableItem));
    if (p_list != NULL)
    {
        struct nodeUsable *p_temp = p_list->p_head;
        while (p_temp != NULL)
        {
            usableItem = &p_temp->usableItem;
            fwrite(usableItem,sizeof(struct UsableItem),1,fptr);
            p_temp = p_temp->p_next;
        }
        //printf("\n");
    }
    fclose(fptr);
}

struct DlistUsable* readFromFileUsable(){
    struct DlistUsable *p_list = dlistUsable_new();
    struct UsableItem* usableItem = malloc(sizeof(struct UsableItem));
    FILE *fptr;

    fptr=fopen("./usablelist.txt","r");

    if (fptr) {
        /* File was opened successfully. */

        /* Attempt to read element one by one */
        while (fread(usableItem,sizeof(struct UsableItem),1,fptr) == 1) {
            dlistUsable_append(p_list, *UsableItem_ctor(usableItem->name, usableItem->goldValue, usableItem->duration, usableItem->hp,usableItem->attack,
                                                         usableItem->relativeDefense, usableItem->absoluteDefense, usableItem->dodge));
        }
        //printf("\n");
    }

    fclose(fptr);

    return p_list;
}

struct UsableItem* UsableItem_ctor(char* name, int goldValue, int duration, int hp,
                            int attack, int relativeDefense, int absoluteDefense, int dodge)
{
    struct UsableItem* p = malloc(sizeof(struct UsableItem));
    p->name = name;
    p->goldValue = goldValue;
    p->duration = duration;
    p->hp = hp;
    p->attack = attack;
    p->relativeDefense = relativeDefense;
    p->absoluteDefense = absoluteDefense;
    p->dodge = dodge;
    return p;
}

// generates a list of all the usable items in the game
struct DlistUsable* createUsable()
{
    struct DlistUsable* usableList = dlistUsable_new();

    struct UsableItem* nhealthp = UsableItem_ctor("Instant health potion", 30, 0, 25, 0, 0, 0, 0);
    dlistUsable_append(usableList, *nhealthp);
    struct UsableItem* atkp = UsableItem_ctor("Moderate attack potion", 20, 3, 0, 8, 0, 0, 0);
    dlistUsable_append(usableList, *atkp);
    struct UsableItem* armp = UsableItem_ctor("Greater armor potion", 50, 3, 0, 0, 25, 0, 0);
    dlistUsable_append(usableList, *armp);
    /*struct UsableItem* goblin = UsableItem_ctor("Goblin", 100, 10, 50, 10, 10);
    dlistUsable_append(usableList, *goblin);
    struct UsableItem* skeleton = UsableItem_ctor("Skeleton", 100, 10, 50, 10, 10);
    dlistUsable_append(usableList, *skeleton);
    struct UsableItem* troll = UsableItem_ctor("Troll", 100, 10, 50, 10, 10);
    dlistUsable_append(usableList, *troll);*/

    writeToFileUsable(usableList);

    return usableList;
}

struct DlistUsable* getUsable()
{
    struct DlistUsable* usableList = dlistUsable_new();
    if(usableList == readFromFileUsable()){
        return usableList;
    }else{
        return createUsable();
    }
}

struct DlistUsable* selectFirstPotions()
{
    return getUsable();
}


/*void doUsableItemEffect(struct UsableItem* item, struct Mob* mob)
{


}

void removeUsableItemEffect(struct UsableItem* item, struct Mob* mob)
{


}

void sellUsableitem(struct UsableItem* item, struct Player* player)
{


}
*/
