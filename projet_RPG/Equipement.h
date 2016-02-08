

typedef struct Equipment
{
    StuffItem head;
    StuffItem chest;
    StuffItem leggings;
    StuffItem boots;
    StuffItem leftHand;
    StuffItem rightHand;
} Equipment;

Equipment* Equipment_ctor(StuffItem head, StuffItem chest, StuffItem leggings, StuffItem boots, StuffItem leftHand, StuffItem rightHand) {
    Equipment* p = malloc(sizeof(Equipment));
    p->head = head;
    p->chest = chest;
    p->leggings = leggings;
    p->boots = boots;
    p->leftHand = leftHand;
    p->rightHand = rightHand;
    return p;
}
