#include "MobRace.h"

/*struct node
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
*/

MobRace* MobRace_ctor(char* name, int hp, int attack, int relativeDefense, int absoluteDefense, int dodge)
{
    MobRace* p = malloc(sizeof(MobRace));
    p->name = name;
    p->hp = hp;
    p->attack = attack;
    p->relativeDefense = relativeDefense;
    p->absoluteDefense = absoluteDefense;
    p->dodge = dodge;
    return p;
}

void defineRaces()
{
    //Dlist* racesList = dlist_new();

    MobRace* human = MobRace_ctor("Human", 100, 10, 50, 10, 10);
    //dlist_append(racesList, human);
    MobRace* elf = MobRace_ctor("Elf", 100, 10, 50, 10, 10);
    //dlist_append(racesList, elf);
    MobRace* dwarf = MobRace_ctor("dwarf", 100, 10, 50, 10, 10);
    //dlist_append(racesList, dwarf);
    MobRace* goblin = MobRace_ctor("goblin", 100, 10, 50, 10, 10);
    //dlist_append(racesList, goblin);
    MobRace* skeleton = MobRace_ctor("skeleton", 100, 10, 50, 10, 10);
    //dlist_append(racesList, skeleton);
    MobRace* troll = MobRace_ctor("troll", 100, 10, 50, 10, 10);
    //dlist_append(racesList, troll);

}

