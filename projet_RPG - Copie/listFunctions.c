

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

//add element at the start of the list
Dlist *dlist_prepend(Dlist *p_list, int data)
{
    if (p_list != NULL)
    {
        struct node *p_new = malloc(sizeof *p_new);
        if (p_new != NULL)
        {
            p_new->data = data;
            p_new->p_prev = NULL;
            if (p_list->p_tail == NULL)
            {
                p_new->p_next = NULL;
                p_list->p_head = p_new;
                p_list->p_tail = p_new;
            }
            else
            {
                p_list->p_head->p_prev = p_new;
                p_new->p_next = p_list->p_head;
                p_list->p_head = p_new;
            }
            p_list->length++;
       }
    }
    return p_list;
}

//inserts an element at the position choice
//warning : position has to start
Dlist *dlist_insert(Dlist *p_list, int data, int position)
{
    if (p_list != NULL)
    {
        struct node *p_temp = p_list->p_head;
        int i = 1;
        while (p_temp != NULL && i <= position)
        {
            if (position == i)
            {
                if (p_temp->p_next == NULL)
                {
                    p_list = dlist_append(p_list, data);
                }
                else if (p_temp->p_prev == NULL)
                {
                    p_list = dlist_prepend(p_list, data);
                }
                else
                {
                    struct node *p_new = malloc(sizeof *p_new);;
                    if (p_new != NULL)
                    {
                        p_new->data = data;
                        p_temp->p_next->p_prev = p_new;
                        p_temp->p_prev->p_next = p_new;
                        p_new->p_prev = p_temp->p_prev;
                        p_new->p_next = p_temp;
                        p_list->length++;
                    }
                }
            }
            else
            {
                p_temp = p_temp->p_next;
            }
            i++;
        }
    }
    return p_list;
}

void dlist_delete(Dlist **p_list)
{
    if (*p_list != NULL)
    {
        struct node *p_temp = (*p_list)->p_head;
        while (p_temp != NULL)
        {
            struct node *p_del = p_temp;
            p_temp = p_temp->p_next;
            free(p_del);
        }
        free(*p_list), *p_list = NULL;
    }
}

void dlist_display(Dlist *p_list)
{
    if (p_list != NULL)
    {
        struct node *p_temp = p_list->p_head;
        while (p_temp != NULL)
        {
            printf("%d -> ", p_temp->data);
            fflush(stdout);
            p_temp = p_temp->p_next;
        }
    }
    printf("NULL\n");
}

Dlist *dlist_remove(Dlist *p_list, int data)
{
    if (p_list != NULL)
    {
        struct node *p_temp = p_list->p_head;
        int found = 0;
        while (p_temp != NULL && !found)
        {
            if (p_temp->data == data)
            {
                if (p_temp->p_next == NULL)
                {
                    p_list->p_tail = p_temp->p_prev;
                    p_list->p_tail->p_next = NULL;
                }
                else if (p_temp->p_prev == NULL)
                {
                    p_list->p_head = p_temp->p_next;
                    p_list->p_head->p_prev = NULL;
                }
                else
                {
                    p_temp->p_next->p_prev = p_temp->p_prev;
                    p_temp->p_prev->p_next = p_temp->p_next;
                }
                free(p_temp);
                p_list->length--;
                found = 1;
            }
            else
            {
                p_temp = p_temp->p_next;
            }
        }
    }
    return p_list;
}

Dlist *dlist_remove_all(Dlist *p_list, int data)
{
    if (p_list != NULL)
    {
        struct node *p_temp = p_list->p_head;
        while (p_temp != NULL)
        {
            if (p_temp->data == data)
            {
                struct node *p_del = p_temp;
                p_temp = p_temp->p_next;
                if (p_del->p_next == NULL)
                {
                    p_list->p_tail = p_del->p_prev;
                    p_list->p_tail->p_next = NULL;
                }
                else if (p_del->p_prev == NULL)
                {
                    p_list->p_head = p_del->p_next;
                    p_list->p_head->p_prev = NULL;
                }
                else
                {
                    p_del->p_next->p_prev = p_del->p_prev;
                    p_del->p_prev->p_next = p_del->p_next;
                }
                free(p_del);
                p_list->length--;
            }
            else
            {
                p_temp = p_temp->p_next;
            }
        }
    }
    return p_list;
}

Dlist *dlist_remove_id(Dlist *p_list, int position)
{
    if (p_list != NULL)
    {
        struct node *p_temp = p_list->p_head;
        int i = 1;
        while (p_temp != NULL && i <= position)
        {
            if (position == i)
            {
                if (p_temp->p_next == NULL)
                {
                    p_list->p_tail = p_temp->p_prev;
                    p_list->p_tail->p_next = NULL;
                }
                else if (p_temp->p_prev == NULL)
                {
                    p_list->p_head = p_temp->p_next;
                    p_list->p_head->p_prev = NULL;
                }
                else
                {
                    p_temp->p_next->p_prev = p_temp->p_prev;
                    p_temp->p_prev->p_next = p_temp->p_next;
                }
                free(p_temp);
                p_list->length--;
            }
            else
            {
                p_temp = p_temp->p_next;
            }
            i++;
        }
    }
    return p_list;
}

size_t dlist_length(Dlist *p_list)
{
    size_t ret = 0;
    if (p_list != NULL)
    {
        ret = p_list->length;
    }
    return ret;
}

Dlist *dlist_find(Dlist *p_list, int data)
{
    Dlist *ret = NULL;
    if (p_list != NULL)
    {
        struct node *p_temp = p_list->p_head;
        int found = 0;
        while (p_temp != NULL && !found)
        {
            if (p_temp->data == data)
            {
                ret = dlist_new();
                ret = dlist_append(ret, data);
                found = 1;
            }
            else
            {
                p_temp = p_temp->p_next;
            }
        }
    }
    return ret;
}

Dlist *dlist_find_all(Dlist *p_list, int data)
{
    Dlist *ret = NULL;
    if (p_list != NULL)
    {
        struct node *p_temp = p_list->p_head;
        while (p_temp != NULL)
        {
            if (p_temp->data == data)
            {
                if (ret == NULL)
                {
                    ret = dlist_new();
                }
                ret = dlist_append(ret, data);
            }
            p_temp = p_temp->p_next;
        }
    }
    return ret;
}
