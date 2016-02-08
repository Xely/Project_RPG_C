

typedef struct MobRace
{
    char* name;
    int hp;
    int attack;
    int relativeDefense;
    int absoluteDefense;
    int dodge;
}

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
    int data;
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

//add element at the end of the list
Dlist *dlist_append(Dlist *p_list, int data)
{
    if (p_list != NULL)
    {
        struct node *p_new = malloc(sizeof *p_new);
        if (p_new != NULL)
        {
            p_new->data = data;
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

    MobRace human;
    human.name = "Human";
    human.hp = 100;
    human.attack = 10;
    human.relativeDefense = 50;
    human.absoluteDefense = 10;
    human.dodge = 10;
    dlist_append(racesList,human);

    MobRace elf;
    elf.name = "Elf";
    elf.hp = 100;
    elf.attack = 10;
    elf.relativeDefense = 50;
    elf.absoluteDefense = 10;
    elf.dodge = 10;
    dlist_append(racesList,elf);

    MobRace dwarf;
    dwarf.name = "Dwarf";
    dwarf.hp = 100;
    dwarf.attack = 10;
    dwarf.relativeDefense = 50;
    dwarf.absoluteDefense = 10;
    dwarf.dodge = 10;
    dlist_append(racesList,dwarf);

    MobRace goblin;
    goblin.name = "Goblin";
    goblin.hp = 100;
    goblin.attack = 10;
    goblin.relativeDefense = 50;
    goblin.absoluteDefense = 10;
    goblin.dodge = 10;
    dlist_append(racesList,human);

    MobRace skeleton;
    skeleton.name = "Skeleton";
    skeleton.hp = 100;
    skeleton.attack = 10;
    skeleton.relativeDefense = 50;
    skeleton.absoluteDefense = 10;
    skeleton.dodge = 10;
    dlist_append(racesList,skeleton);

    MobRace troll;
    troll.name = "Troll";
    troll.hp = 100;
    troll.attack = 10;
    troll.relativeDefense = 50;
    troll.absoluteDefense = 10;
    troll.dodge = 10;
    dlist_append(racesList,troll);

}
