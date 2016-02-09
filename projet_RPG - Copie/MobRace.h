#include "listFunctions.c"

typedef struct MobRaceBonus
{
    int id;
    char* name;
    int hp;
    int attack;
    int relativeDefense;
    int absoluteDefense;
    int dodge;
} MobRaceBonus;

MobRaceBonus* MobRaceBonus_ctor(int id, char* name, int hp, int attack, int relativeDefense, int absoluteDefense, int dodge)
{
    MobRaceBonus* p = malloc(sizeof(MobRaceBonus));
    p->id = id;
    p->name = name;
    p->hp = hp;
    p->attack = attack;
    p->relativeDefense = relativeDefense;
    p->absoluteDefense = absoluteDefense;
    p->dodge = dodge;
    return p;
}

struct node
{
    MobRaceBonus mobRaceBonus;
    struct node *p_next;
    struct node *p_prev;
};

typedef struct dlist
{
    size_t length;
    struct node *p_tail;
    struct node *p_head;
} Dlist;

// creates a new list
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
Dlist *dlist_append(Dlist *p_list, MobRaceBonus mobRaceBonus)
{
    if (p_list != NULL)
    {
        struct node *p_new = malloc(sizeof *p_new);
        if (p_new != NULL)
        {
            p_new->mobRaceBonus = mobRaceBonus;
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

int main()
{
    Dlist* racesList = dlist_new();

    MobRaceBonus nightelf;
    nightelf.id = 0;
    nightelf.name = "Night Elf";
    nightelf.hp = 120;
    nightelf.attack = 8;
    nightelf.relativeDefense = 40;
    nightelf.absoluteDefense = 10;
    nightelf.dodge = 6;
    dlist_append(racesList,nightelf);

    MobRaceBonus human;
    human.id = 1;
    human.name = "Human";
    human.hp = 100;
    human.attack = 10;
    human.relativeDefense = 50;
    human.absoluteDefense = 10;
    human.dodge = 0;
    dlist_append(racesList,human);

    MobRaceBonus goblin;
    goblin.id = 2;
    goblin.name = "Goblin";
    goblin.hp = 0;
    goblin.attack = 0;
    goblin.relativeDefense = 0;
    goblin.absoluteDefense = 0;
    goblin.dodge = 0;
    dlist_append(racesList,goblin);

    MobRaceBonus troll;
    troll.id = 3;
    troll.name = "Troll";
    troll.hp = 0;
    troll.attack = 0;
    troll.relativeDefense = 0;
    troll.absoluteDefense = 0;
    troll.dodge = 0;
    dlist_append(racesList,troll);

    MobRaceBonus orc;
    orc.id = 4;
    orc.name = "Orc";
    orc.hp = 0;
    orc.attack = 0;
    orc.relativeDefense = 0;
    orc.absoluteDefense = 0;
    orc.dodge = 0;
    dlist_append(racesList,orc);

    MobRaceBonus dwarf;
    dwarf.id = 5;
    dwarf.name = "Dwarf";
    dwarf.hp = 0;
    dwarf.attack = 0;
    dwarf.relativeDefense = 0;
    dwarf.absoluteDefense = 0;
    dwarf.dodge = 0;
    dlist_append(racesList,dwarf);

    MobRaceBonus skeleton;
    skeleton.id = 6;
    skeleton.name = "Skeleton";
    skeleton.hp = 0;
    skeleton.attack = 0;
    skeleton.relativeDefense = 0;
    skeleton.absoluteDefense = 0;
    skeleton.dodge = 0;
    dlist_append(racesList,skeleton);

}
