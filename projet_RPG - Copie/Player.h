

typedef struct Player{
    int id;
    Mob* mob;
    int lives;
    int gold;
    // loot
}Player;

Player* Player_ctor(int id, Mob* mob, int lives, int gold, /* loot */) {
    Player* p = malloc(sizeof(Player));
    p->id = id;
    p->mob = mob;
    p->lives = lives;
    p->gold = gold;
        return p;
}
