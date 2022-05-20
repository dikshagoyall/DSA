#include "dl.h"

Node *create_node(int value)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;

    return temp;
}

void add_end(Node** head, Node** tail, int value)
{
    Node* new_node = create_node(value);

    if (*head == NULL)
    {
        *head = new_node;
        *tail = new_node;
        return;
    }

    new_node->prev = *tail;
    (*tail)->next = new_node;
    *tail = new_node;
}

void add_begin(Node **head, Node **tail, int value)
{
    Node *new_node = create_node(value);

    if (*head == NULL)
    {
        *head = new_node;
        *tail = new_node;
        return;
    }

    new_node->next = *head;
    (*head)->prev = new_node;
    *head = new_node;
}

void traverse_next(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void traverse_prev(Node *tail)
{
    while (tail != NULL)
    {
        printf("%d ", tail->data);
        tail = tail->prev;
    }
    printf("\n");
}

void delete_end(Node** tail)
{
    Node* temp;

    if (*tail == NULL)
        return;
    
    temp = *tail;
    (*tail)->prev->next = NULL;
    *tail = (*tail)->prev;
    free(temp);
}

void delete_begin(Node** head)
{
    Node* temp;

    if (*head == NULL)
        return;

    temp = *head;

    (*head)->next->prev = NULL;           
    (*head) = (*head)->next;
    free(temp);
}

Node* search_by_pos(Node* head, int position)
{
    int i = 1, count = 1;
    Node* tmp= head;

    if (head == NULL)
        return NULL;

    if (position <= 0)
    {
        printf("Invalid Position\n");
        return NULL;
    }

    while (head->next != NULL)
    {
        head = head->next; 
        count++;                           
    }
    
    if (position > count)
    {
        printf("Invalid Position\n");
        return NULL;
    }
    
    for (i = 1; i < position; i++)                 
        tmp = tmp->next;   
        
    return tmp;
}

void add_in_between_after(Node* head, int pos, int value)
{
    Node *temp,*pos_node=NULL;
                                            
    temp = create_node(value);
    pos_node = search_by_pos(head, pos);    
                                                    
    temp->prev = pos_node;                     
    temp->next = pos_node->next;
    pos_node->next->prev = temp;
    pos_node->next = temp;
}

void add_in_between_before(Node* head, int pos, int value)
{
    Node *temp,*pos_node=NULL;
                                            
    temp = create_node(value);
    pos_node = search_by_pos(head, pos);    
                                                    
    temp->prev = pos_node->prev;                     
    temp->next = pos_node;
    pos_node->prev->next = temp;
    pos_node->prev = temp;
}

void delete_in_between_after(Node* head, int pos)
{
    Node* pos_node=NULL;

    pos_node = search_by_pos(head, pos);     
    Node* tmp= pos_node->next;
    pos_node->next= pos_node->next->next;
    free(tmp);
}

void delete_in_between_before(Node* head, int pos)
{
    Node* pos_node=NULL;

    pos_node = search_by_pos(head, pos);     
    Node* tmp= pos_node->prev;                            
    pos_node->prev= pos_node->prev->prev;
    pos_node->prev->next= pos_node;               

    free(tmp);
}