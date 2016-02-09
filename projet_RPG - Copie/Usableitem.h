

typedef struct UsableItem{
    char* name;
    int goldValue;
    int duration;
    /*
    action hp
    action attack
    action relative defense
    action absolute defense
    action dodge
    */
}UsableItem;

UsableItem* UsableItem_ctor(char* name, int goldValue, int duration) {
    UsableItem* p = malloc(sizeof(UsableItem));
    p->name = name;
    p->goldValue = goldvalue;
    p->duration = duration;
    return p;
}
