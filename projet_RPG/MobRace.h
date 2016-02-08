#ifndef MOBRACE_H_INCLUDED
#define MOBRACE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


typedef struct MobRace
{
    char* name;
    int hp;
    int attack;
    int relativeDefense;
    int absoluteDefense;
    int dodge;
} MobRace;

MobRace* MobRace_ctor(char* name, int hp, int attack, int relativeDefense, int absoluteDefense, int dodge) {
    MobRace* p = malloc(sizeof(MobRace));
    p->name = name;
    p->hp = hp;
    p->attack = attack;
    p->relativeDefense = relativeDefense;
    p->absoluteDefense = absoluteDefense;
    p->dodge;
    return p;
}

struct node
{
    MobRace mobRace;
    struct node *p_next;
    struct node *p_prev;
};

typedef struct dlist
{
    size_t length;
    struct node *p_tail;
    struct node *p_head;
} Dlist;

Dlist *dlist_new(void)
{
    Dlist *p_new = malloc(sizeof *p_new);
    if (p_new != NULL)
    {
        p_new->length = 0;
        p_new->p_head = NULL;
        p_new->p_tail = NULL;
    }
    return p_new;
}

// adds element at the end of the list
Dlist *dlist_append(Dlist *p_list, MobRace mobRace)
{
    if (p_list != NULL)
    {
        struct node *p_new = malloc(sizeof *p_new);
        if (p_new != NULL)
        {
            p_new->mobRace = mobRace;
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



#endif
