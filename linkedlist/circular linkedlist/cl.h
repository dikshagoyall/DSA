#include <stdio.h>
#include <stdlib.h>

typedef struct st
{
    int data;
    struct st *next;
} node;

node *create(int value);
void append(node **head, int value);
void add(node **head, int value, int pos);
void del(node **head, int pos);
void traverse(node *pthead);