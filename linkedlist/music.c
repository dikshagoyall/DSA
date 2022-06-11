#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st
{
    struct st *next;
    struct st *prev;
    char *data;
} Node;

Node *create_node(char *value);
void add_end(Node **head, Node **tail, char *value);
Node *search_by_position(Node *head, int position);
void play(Node *pos);
void add_after(Node *head, int pos, char *value, FILE *fp);
void add_before(Node *head, int pos, char *value, FILE *fp);
void delete (Node *head, int p);
void sort_list(Node **head, FILE *fp);
void insert_sorted(Node **head, Node *tmp);
void traverse(Node *head);
void rev(Node *tail);

int main()
{
    FILE *fp;
    int p;
    char c, t[40], dump;
    char music[100];
    Node *head = NULL, *tail = NULL, *pos = NULL, *curr;

    fp = fopen("music.txt", "r");

    while ((fgets(music, 40, fp)))
        add_end(&head, &tail, music);

    do
    {
        printf("\nS start the player.");
        printf("\nJ jump to a specific track.");
        printf("\nN next track.");
        printf("\nP previous track.");
        printf("\nF first track.");
        printf("\nL last track.");
        printf("\nA add a track after an existing track.");
        printf("\nB add a track before an existing track.");
        printf("\nR remove a specific track from the list.");
        printf("\nO sort the tracks in alphabetical order.");

        printf("\nEnter your choice: ");
        scanf("%c%c", &c, &dump);

        switch (c)
        {
        case 'S':
            curr = head;
            play(curr);
            break;
        case 'J':
            printf("\nEnter a position: ");
            scanf("%d", &p);
            pos = search_by_position(head, p);
            play(pos);
            break;
        case 'N':
            if (curr->next == NULL)
            {
                curr = head;
                play(curr);
            }
            else
            {
                play(curr->next);
                curr = curr->next;
            }
            break;

        case 'P':
            if (curr->prev == NULL)
                break;
            else
            {
                play(curr->prev);
                curr = curr->prev;
            }
            break;

        case 'F':
            play(head);
            break;

        case 'L':
            play(tail);
            break;

        case 'A':
            printf("\nEnter a pos: ");
            scanf("%d%c", &p, &dump);
            printf("\nEnter a track: ");
            fgets(t, sizeof(t), stdin);
            add_after(head, p, t, fp);
            break;
        case 'B':
            printf("\nEnter a pos: ");
            scanf("%d%c", &p, &dump);
            printf("\nEnter a track: ");
            fgets(t, sizeof(t), stdin);
            add_before(head, p, t, fp);
            break;

        case 'R':
            printf("\nEnter a pos: ");
            scanf("%d", &p);
            delete (head, p);
            break;

        case 'O':
            sort_list(&head, fp);
            break;

        case 'T':
            traverse(head);
            break;

        case 'y':
            continue;

        case 'n':
            return 0;

        default:
            break;
        }
        printf("\nDo you want to continue? ");
        scanf("%c%c", &c, &dump);
    } while (c != 'n');

    fclose(fp);

    return 0;
}

Node *create_node(char *value)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = strdup(value);
    temp->next = NULL;
    temp->prev = NULL;

    return temp;
}

void add_end(Node **head, Node **tail, char *value)
{
    Node *new_node = create_node(value);

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

Node *search_by_position(Node *head, int position)
{
    int i = 1, count = 1;
    Node *tmp = head;

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

void play(Node *pos)
{
    printf("%s ", pos->data);
}

void add_after(Node *head, int pos, char *value, FILE *fp)
{
    Node *temp, *pos_node = NULL;

    temp = create_node(value);
    pos_node = search_by_position(head, pos);

    temp->prev = pos_node;
    temp->next = pos_node->next;
    pos_node->next->prev = temp;
    pos_node->next = temp;

    fp = fopen("music.txt", "w");
    while (head != NULL)
    {
        fprintf(fp, "%s", head->data);
        head = head->next;
    }
}

void add_before(Node *head, int pos, char *value, FILE *fp)
{
    Node *temp, *pos_node = NULL;

    temp = create_node(value);
    pos_node = search_by_position(head, pos);

    temp->prev = pos_node->prev;
    temp->next = pos_node;
    pos_node->prev->next = temp;
    pos_node->prev = temp;

    fp = fopen("music.txt", "w");
    while (head != NULL)
    {
        fprintf(fp, "%s", head->data);
        head = head->next;
    }
}

void delete (Node *head, int p)
{
    Node *pos_node = NULL;

    pos_node = search_by_position(head, p);
    Node *tmp = pos_node->prev;
    tmp->next = pos_node->next;
    pos_node->next->prev = tmp;
}

void sort_list(Node **head, FILE *fp)
{
    Node *curr = *head, *tmp = NULL, *nh = NULL;

    while (curr != NULL)
    {
        tmp = curr->next;
        insert_sorted(&nh, create_node(curr->data));
        free(curr);
        curr = tmp;
    }

    curr = nh;

    fp = fopen("music.txt", "w");
    while (curr != NULL)
    {
        fprintf(fp, "%s", (curr)->data);
        curr = (curr)->next;
    }
}

void insert_sorted(Node **head, Node *tmp)
{
    Node *curr = *head;

    if (*head == NULL)
    {
        *head = tmp;
        return;
    }

    if (strcmp((*head)->data, tmp->data) > 0)
    {
        tmp->next = *head;
        tmp->prev = NULL;
        (*head)->prev = tmp;
        *head = tmp;
        return;
    }
    while ((curr->next != NULL) && (strcmp(curr->next->data, tmp->data) < 0))
        curr = curr->next;

    tmp->next = curr->next;
    tmp->prev = curr;
    curr->next = tmp;
    if (curr->next != NULL)
        curr->next->prev = tmp;
}

void traverse(Node *head)
{
    while (head != NULL)
    {
        printf("%s ", head->data);
        head = head->next;
    }
}