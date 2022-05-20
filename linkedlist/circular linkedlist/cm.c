#include "cl.h"

int main()
{
    node *head = NULL;
    append(&head, 5);
    append(&head, 60);
    append(&head, 5);
    append(&head, 60);
    add(&head, 7, 4);
    traverse(head);
    del(&head, 2);
    traverse(head);
}
