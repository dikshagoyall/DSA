#include "ll.h"

node* create(int value)
{
    node* temp;
    temp= (node*)malloc(sizeof(node));
    temp->data= value;
    temp->next= NULL;
    return temp;
}

void append(node** head,int value)
{
    node* temp;
    temp= create(value);
    node* current= *head;
    if(*head==NULL)
    {
        *head= temp;
        return;
    }
    while(current->next!=NULL)
        current = current->next;
    current->next= temp;
}

void traverse(node* pthead)
{
    while (pthead!= NULL)
    {
        printf("%d ", pthead->data);
        pthead= pthead->next;
    }
    printf("\n");
}

void del(node** head,int pos)
{
    node* temp= *head;
    int i;
    if(pos==1)
    {
        *head= temp->next;
    }
    else
    {
        for(i=2;temp!=NULL && i<pos;i++)
            temp = temp->next;
        temp->next= temp->next->next;
        
    }
}

void add(node** head,int value,int pos)
{
    int i;
    node* temp;
    temp= create(value);
    node* current= *head;
    for(i=2;current!=NULL && i<pos;i++)
        current = current->next;
    temp->next= current->next;
    current->next= temp;
}