#include <stdio.h>
#include <stdlib.h>
#include "Usableitem.h"



DlistUsable *dlistUsable_new(void)
{
    DlistUsable* p_new = malloc(sizeof *p_new);
    if (p_new != NULL)
    {
        p_new->length = 0;
        p_new->p_head = NULL;
        p_new->p_tail = NULL;
    }
    return p_new;
}

// adds element at the end of the list
DlistUsable *dlistUsable_append(DlistUsable *p_list, UsableItem usableItem)
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
void writeToFileUsable(DlistUsable *p_list)
{
    FILE *fptr;
    fptr = fopen("./usablelist.txt","w+");

    UsableItem* usableItem = malloc(sizeof(UsableItem));
    if (p_list != NULL)
    {
        struct nodeUsable *p_temp = p_list->p_head;
        while (p_temp != NULL)
        {
            usableItem = &p_temp->usableItem;
            fwrite(usableItem,sizeof(UsableItem),1,fptr);
            p_temp = p_temp->p_next;
        }
        printf("\n");
    }
    fclose(fptr);
}

DlistUsable* readFromFileUsable(){
    DlistUsable *p_list = dlistUsable_new();
    UsableItem* usableItem = malloc(sizeof(UsableItem));
    FILE *fptr;

    fptr=fopen("./usablelist.txt","r");

    if (fptr) {
        /* File was opened successfully. */

        /* Attempt to read element one by one */
        while (fread(usableItem,sizeof(UsableItem),1,fptr) == 1) {
            dlistUsable_append(p_list, *UsableItem_ctor(usableItem->name, usableItem->goldValue, usableItem->duration, usableItem->hp,usableItem->attack,
                                                         usableItem->relativeDefense, usableItem->absoluteDefense, usableItem->dodge));
        }
        printf("\n");
    }

    fclose(fptr);

    return p_list;
}

UsableItem* UsableItem_ctor(char* name, int goldValue, int duration, int hp,
                            int attack, int relativeDefense, int absoluteDefense, int dodge)
{
    UsableItem* p = malloc(sizeof(UsableItem));
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
DlistUsable* createUsable()
{
    DlistUsable* usableList = dlistUsable_new();

    UsableItem* nhealthp = UsableItem_ctor("Instant health potion", 30, 0, 25, 0, 0, 0, 0);
    dlistUsable_append(usableList, *nhealthp);
    UsableItem* atkp = UsableItem_ctor("Moderate attack potion", 20, 3, 0, 8, 0, 0, 0);
    dlistUsable_append(usableList, *atkp);
    UsableItem* armp = UsableItem_ctor("Greater armor potion", 50, 3, 0, 0, 25, 0, 0);
    dlistUsable_append(usableList, *armp);
    /*UsableItem* goblin = UsableItem_ctor("Goblin", 100, 10, 50, 10, 10);
    dlistUsable_append(usableList, *goblin);
    UsableItem* skeleton = UsableItem_ctor("Skeleton", 100, 10, 50, 10, 10);
    dlistUsable_append(usableList, *skeleton);
    UsableItem* troll = UsableItem_ctor("Troll", 100, 10, 50, 10, 10);
    dlistUsable_append(usableList, *troll);*/

    writeToFileUsable(usableList);

    return usableList;
}

DlistUsable* getUsable()
{
    DlistUsable* usableList = dlistUsable_new();
    if(usableList == readFromFileUsable()){
        return usableList;
    }else{
        return createUsable();
    }
}

DlistUsable* selectFirstPotions()
{
    return getUsable();
}


/*void doUsableItemEffect(UsableItem* item, Mob* mob)
{


}

void removeUsableItemEffect(UsableItem* item, Mob* mob)
{


}

void sellUsableitem(UsableItem* item, Player* player)
{


}
*/
