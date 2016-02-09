


typedef struct Mob{
    int id;
    char* name;
    int mobRace;
    int hp;
    int attack;
    int relativeDefense;
    int absoluteDefense;
    int dodge;
    //equipement
    //loot
}Mob;

Mob* Mob_ctor(int id, char* name, int mobrace, int hp, int attack, int relativeDefense, int absoluteDefense, int dodge) {
    Mob* p = malloc(sizeof(Mob));
    p->id = id;
    p->name = name;
    p->mobRace = mobRace;
    p->hp = hp;
    p->attack = attack;
    p->relativeDefense = relativeDefense;
    p->absoluteDefense = absoluteDefense;
    p->dodge = dodge;

    return p;
}
