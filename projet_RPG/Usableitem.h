

typedef struct UsableItem
{
    char* name;
    int goldValue;
    int duration;
    int hp;
    int attack;
    int relativeDefense;
    int absoluteDefense;
    int dodge;
} UsableItem;

MobRace* MobRace_ctor(char* name, int goldValue, int duration, int hp, int attack, int relativeDefense, int absoluteDefense, int dodge) {
    MobRace* p = malloc(sizeof(MobRace));
    p->name = name;
    p->goldValue = goldValue;
    p->duration = duration;
    p->hp = hp;
    p->attack = attack;
    p->relativeDefense = relativeDefense;
    p->absoluteDefense = absoluteDefense;
    p->dodge;
    return p;
}

