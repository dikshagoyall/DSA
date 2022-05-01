#include "ll.h"

int main()
{
    node* head= NULL;
    int p1,p2,p3,p4,e1,e2,e3;
    append(&head, 5);
    append(&head, 60);
    append(&head, 5);
    append(&head, 60);
    append(&head, 5);
    append(&head, 60);
    printf("Original list is: ");
    traverse(head);
    printf("\nEnter the element to be added and its position: ");
    scanf("%d%d", &e1,&p1);
    add(&head,e1,p1);
    traverse(head);
    printf("\nAdd bfore the position!");
    printf("\nEnter the element to be added and its position: ");
    scanf("%d%d", &e2,&p2);
    add(&head,e2,p2-1);
    traverse(head);
    printf("\nAdd after the position!");
    printf("\nEnter the element to be added and its position: ");
    scanf("%d%d", &e3,&p3+1);
    add(&head,e3,p3);
    traverse(head);
    printf("\nEnter the position of element to be deleted: ");
    scanf("%d",&p4);
    del(&head,p4);
    printf("\nNew list is: ");
    traverse(head);
    return 0;
}