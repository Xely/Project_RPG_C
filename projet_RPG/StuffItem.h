

typedef struct StuffItem
{
    char* name;
    int goldValue;
    int typeId;
    int hp;
    int attack;
    int relativeDefense;
    int absoluteDefense;
} StuffItem;

StuffItem* StuffItem_ctor(char* name, int goldValue, int typeId, int hp, int attack, int relativeDefense, int absoluteDefense) {
    StuffItem* p = malloc(sizeof(StuffItem));
    p->name = name;
    p->hp = hp;
    p->attack = attack;
    p->relativeDefense = relativeDefense;
    p->absoluteDefense = absoluteDefense;
    p->dodge;
    return p;
}

