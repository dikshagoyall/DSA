#include "dl.h"

int main()
{
    Node *head = NULL, *tail = NULL;

    add_end(&head, &tail, 5);
    add_end(&head, &tail, 10);
    add_end(&head, &tail, 15);
    add_end(&head, &tail, 20);
    add_end(&head, &tail, 25);
    add_begin(&head, &tail, 60);
    delete_begin(&head);

    traverse_next(head);
    traverse_prev(tail);

    add_in_between_after(head, 3, 30);
    add_in_between_before(head, 3, 30);
    delete_in_between_after(head, 3);
    delete_in_between_before(head, 3);

    traverse_next(head);

    return 0;
}
