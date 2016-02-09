
#define RW_STRUCT struct mobRace
#define STRUCT_ATTRIBUTS data->id,data->name,data->mark
#define LIST_STRUCT Dlist
#define LIST_STRUCT_LOWER dlist


struct mobRace
{
    int id;
    char* name;
    int mark;
};

struct mobRace* MobRace_ctor(int id, char* name, int mark) {
  struct mobRace* p = malloc(sizeof(struct mobRace));
  p->id = id;
  p->name = name;
  p->mark = mark;
  return p;
}

struct node
{
    RW_STRUCT data;
    struct node *p_next;
    struct node *p_prev;
} Node;

typedef struct LIST_STRUCT_LOWER
{
    size_t length;
    struct node *p_tail;
    struct node *p_head;
} LIST_STRUCT;

//Allow to display correct info of list items
void printf_struct(RW_STRUCT* data)
{
    printf("%d %s %d\n",STRUCT_ATTRIBUTS);
}

int* display_list_ids(LIST_STRUCT *p_list)
{
}

//Create a new list
LIST_STRUCT *LIST_STRUCT_LOWER_new(void)
{
    LIST_STRUCT *p_new = malloc(sizeof *p_new);
    if (p_new != NULL)
    {
        p_new->length = 0;
        p_new->p_head = NULL;
        p_new->p_tail = NULL;
    }
    return p_new;
}

//Add element at the end of the list
LIST_STRUCT *LIST_STRUCT_LOWER_append(LIST_STRUCT *p_list, RW_STRUCT data)
{
    if (p_list != NULL) /* On v�rifie si notre liste a �t� allou�e */
    {
        struct node *p_new = malloc(sizeof *p_new); /* Cr�ation d'un nouveau node */
        if (p_new != NULL) /* On v�rifie si le malloc n'a pas �chou� */
        {
            p_new->data = data; /* On 'enregistre' notre donn�e */
            p_new->p_next = NULL; /* On fait pointer p_next vers NULL */
            if (p_list->p_tail == NULL) /* Cas o� notre liste est vide (pointeur vers fin de liste �  NULL) */
            {
                p_new->p_prev = NULL; /* On fait pointer p_prev vers NULL */
                p_list->p_head = p_new; /* On fait pointer la t�te de liste vers le nouvel �l�ment */
                p_list->p_tail = p_new; /* On fait pointer la fin de liste vers le nouvel �l�ment */
            }
            else /* Cas o� des �l�ments sont d�j� pr�sents dans notre liste */
            {
                p_list->p_tail->p_next = p_new; /* On relie le dernier �l�ment de la liste vers notre nouvel �l�ment (d�but du cha�nage) */
                p_new->p_prev = p_list->p_tail; /* On fait pointer p_prev vers le dernier �l�ment de la liste */
                p_list->p_tail = p_new; /* On fait pointer la fin de liste vers notre nouvel �l�ment (fin du cha�nage: 3 �tapes) */
            }
            p_list->length++; /* Incr�mentation de la taille de la liste */
        }
    }
    return p_list; /* on retourne notre nouvelle liste */
}

//Write the whole list in a file
void writeToFile(LIST_STRUCT *p_list){
    FILE *fptr;
    fptr=fopen("./list.txt","w+");

    RW_STRUCT* data = malloc(sizeof(RW_STRUCT));
    if (p_list != NULL)
    {
        struct node *p_temp = p_list->p_head;
        while (p_temp != NULL)
        {
            data = p_temp->data;
            fwrite(data,sizeof(RW_STRUCT),1,fptr);
            p_temp = p_temp->p_next;
        }
        printf("\n");
    }
    fclose(fptr);
}

//Read a list of structure to display it
LIST_STRUCT* readFromFile(){
    LIST_STRUCT *p_list = LIST_STRUCT_LOWER_new();
    RW_STRUCT* data = malloc(sizeof(RW_STRUCT));
    FILE *fptr;

    fptr=fopen("./list.txt","r");

    if (fptr) {
        /* File was opened successfully. */

        /* Attempt to read element one by one */
        while (fread(data,sizeof(RW_STRUCT),1,fptr) == 1) {
            LIST_STRUCT_LOWER_append(p_list, *Student_ctor(STRUCT_ATTRIBUTS));
        }
        printf("\n");
    }

    fclose(fptr);

    return p_list;
}
