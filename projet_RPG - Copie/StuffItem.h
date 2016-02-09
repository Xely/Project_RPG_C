

typedef struct StuffItem{
    // mob wearing item ?
    char* name;
    int goldValue;
    int type;
    int hp;
    int attack;
    int relativeDefense;
    int absoluteDefense;
}StuffItem;

StuffItem* StuffItem_ctor(char* name, int goldValue, int type, int hp, int attack, int relativeDefense, int absoluteDefense) {
    StuffItem* p = malloc(sizeof(StuffItem));
    p->name = name;
    p->goldValue = goldValue;
    p->type = type;
    p->hp = hp;
    p->attack = attack;
    p->relativeDefense = relativeDefense;
    p->absoluteDefense = absoluteDefense;
    return p;
}
