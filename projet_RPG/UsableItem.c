#include <stdio.h>
#include <stdlib.h>
#include "Usableitem.h"
#include "Player.h"


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

struct Dlistusable *dlistUsable_remove_id(struct DlistUsable *p_list, int position)
{
    if (p_list != NULL)
    {
        struct nodeUsable *p_temp = p_list->p_head;
        int i = 1;
        while (p_temp != NULL && i <= position)
        {
            if (position == i)
            {
                if (p_temp->p_next == NULL)
                {
                    p_list->p_tail = p_temp->p_prev;
                    p_list->p_tail->p_next = NULL;
                }
                else if (p_temp->p_prev == NULL)
                {
                    p_list->p_head = p_temp->p_next;
                    p_list->p_head->p_prev = NULL;
                }
                else
                {
                    p_temp->p_next->p_prev = p_temp->p_prev;
                    p_temp->p_prev->p_next = p_temp->p_next;
                }
                free(p_temp);
                p_list->length--;
            }
            else
            {
                p_temp = p_temp->p_next;
            }
            i++;
        }
    }
    return p_list;
}

size_t dlistUsable_length(struct DlistUsable *p_list)
{
    size_t ret = 0;
    if (p_list != NULL)
    {
        ret = p_list->length;
    }
    return ret;
}

struct UsableItem* returnListElementUsable(struct DlistUsable *p_list, int position)
{
    int i = 0;
    struct nodeUsable *p_temp = p_list->p_head;
    for(i=0;i<position-1;i++){
        p_temp = p_temp->p_next;
    }
    struct UsableItem usable_temp = p_temp->usableItem;

    struct UsableItem* p_usable = UsableItem_ctor(usable_temp.name, usable_temp.goldValue, usable_temp.duration, usable_temp.hp,
                                                  usable_temp.attack, usable_temp.relativeDefense, usable_temp.absoluteDefense, usable_temp.dodge);
    return p_usable;
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


void doUsableItemEffect(struct UsableItem* item, struct Mob* mob)
{
    if(item->attack != 0){
        mob->attack += item->attack;
        printf("You gain %d attack for %d turns!.\n", item->attack, item->duration);
    }
    if(item->hp != 0){
        mob->hp += item->hp;
        printf("You gained %d hp!.\n", item->hp);
    }
    if(item->absoluteDefense != 0){
        mob->absoluteDefense += item->absoluteDefense;
        printf("You gain %d Absolute Defense for %d turns!.\n", item->absoluteDefense, item->duration);
    }
    if(item->relativeDefense != 0){
        mob->relativeDefense += item->relativeDefense;
        printf("You gain %d Relative Defense for %d turns!.\n", item->relativeDefense, item->duration);
    }
    if(item->dodge != 0){
        mob->dodge += item->dodge;
        printf("You gain %d dodge for %d turns!.\n", item->dodge, item->duration);
    }
}

void removeUsableItemEffect(struct UsableItem* item, struct Mob* mob)
{
    if(item->attack != 0){
        mob->attack -= item->attack;
        printf("You lost the effect of your %s.\n", item->name);
    } else if(item->hp != 0){
        mob->hp -= item->hp;
        printf("You lost the effect of your %s.\n", item->name);
    }else if(item->absoluteDefense != 0){
        mob->absoluteDefense -= item->absoluteDefense;
        printf("You lost the effect of your %s.\n", item->name);
    }else if(item->relativeDefense != 0){
        mob->relativeDefense -= item->relativeDefense;
        printf("You lost the effect of your %s.\n", item->name);
    }else if(item->dodge != 0){
        mob->dodge -= item->dodge;
        printf("You lost the effect of your %s.\n", item->name);
    }
}

void sellUsableitem(struct UsableItem* item, struct Player* player)
{
    int goldGained = (item->goldValue) * 0.7;
    player->gold += goldGained;
}
