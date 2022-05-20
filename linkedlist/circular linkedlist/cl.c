#include "cl.h"

node *create(int value)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

void append(node **head, int value)
{
    node *temp;
    temp = create(value);
    if (*head == NULL)
    {
        *head = temp;
        temp->next = *head;
        return;
    }
    node *current = *head;
    while (current->next != *head)
        current = current->next;
    current->next = temp;
    current->next->next = *head;
}

void add(node **head, int value, int pos)
{
    node *temp = create(value);
    node *current = *head;
    int i;
    if (*head == NULL)
    {
        *head = temp;
        temp->next = *head;
        return;
    }
    while (current->next != *head)
        current = current->next;
    if (pos == 1)
    {
        current->next = temp;
        temp->next = *head;
        *head = temp;
    }
    else if (current->next!= *head)
    {
        current->next = temp;
        temp->next = *head;
    }
    else
    {
        current = *head;
        for (i = 2; i < pos; i++)
            current = current->next;         
        temp->next = current->next;
        current->next = temp;
    }
}

void del(node **head, int pos)
{
    node *current = *head, *temp=*head, *last;
    int i;
    if (*head == NULL)
    {
        printf("\nList is empty");
        return;
    }
    while (temp->next != *head)                           
        temp = temp->next;
    if (pos == 1)
    {
        temp->next = current->next;
        *head = temp->next;                        
    }
    else if (temp->next != *head)
    {
        while (current->next != *head)
        {
            last = current;
            current = current->next;
        }
        last->next = *head;
    }
    else
    {
        current= *head;
        for (i = 1; i < pos - 1; i++)
            current = current->next;
        current->next = current->next->next;
    }
}

void traverse(node *pthead)
{
    if (pthead == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }
    node *temp = pthead;
    while (temp->next != pthead)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d \n", temp->data);
    return;
}

