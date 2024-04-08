#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node *NODE;
NODE insert_end(NODE first);
NODE getnode();
void display(NODE first);
NODE insert_front(NODE first);
NODE insert_pos(NODE first);
NODE delet_front(NODE first);
NODE traversing(NODE first);
NODE delet_end(NODE first);
NODE delet_pos(NODE first);
void reverse_list(NODE first);
void count_key(NODE first);
main()
{
    NODE first = NULL;
    int item, choice;
    while (1)
    {
        printf("\n\n1=insert at end\n2=display\n3=insert at front\n4=insert at specific position\n5=delete a node from front\n6=traversing the list\n7=delete from end\n8=delete at specific position\n9=reverse list\n10=count key\n11=exit(0)\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            first = insert_end(first);
            break;
        case 2:
            printf("Display list\n");
            display(first);
            break;
        case 3:
            first = insert_front(first);
            break;
        case 4:
            first = insert_pos(first);
            break;
        case 5:
            first = delet_front(first);
            break;
        case 6:
            first = traversing(first);
            break;
        case 7:
            first = delet_end(first);
            break;
        case 8:
            first = delet_pos(first);
            break;
        case 9:
            reverse_list(first);
            break;
        case 10:
            count_key(first);
        }
    }
}

NODE getnode()
{
    NODE t;
    int item;
    t = (NODE *)malloc(sizeof(struct node));
    if (t == NULL)
    {
        printf("node is not created\n");
        exit(0);
    }
    printf("enter the item to be inserted\n");
    scanf("%d", &item);
    t->data = item;
    t->next = t;
    return t;
}

void display(NODE first)
{
    NODE t;
    if (first == NULL)
    {
        printf("Empty list\n");
        exit(0);
    }

    printf("ELEMENTS OF THE LIST ARE  :\n\n");
    t = first;
    while (t->next != first)
    {
        printf("%d\t", t->data);
        t = t->next;
    }
    printf("%d\t", t->data);
    return first;
}

NODE insert_end(NODE first)
{
    NODE newnode, c;
    newnode = getnode();
    if (first == NULL)
    {
        newnode->next = newnode;
        return newnode;
    }
    c = first;
    while (c->next != first)
    {
        c = c->next;
    }
    c->next = newnode;
    newnode->next = first;
    return first;
}

NODE insert_front(NODE first)
{
    NODE newnode, c;
    newnode = getnode();
    if (first == NULL)
    {
        first = newnode;
        newnode->next = first;
        return first;
    }
    while (c->next != first)
    {
        c = c->next;
    }
    c->next = newnode;
    newnode->next = first;
    first = newnode;
    return first;
}

NODE traversing(NODE first)
{
    NODE c;
    if (first == NULL)
    {
        printf("Empty list\n");
        exit(1);
    }
    c = first;
    while (c->next != first)
    {
        printf("%d\t", c->next);
        c = c->next;
    }
    if (c->next == first)
    {
        printf("%d\t", c->next);
        return first;
    }

    return first;
}

NODE insert_pos(NODE first)
{
    NODE newnode, c, prev;
    int pos;
    int count;
    printf("enter the position to be inserted\n");
    scanf("%d", &pos);
    newnode = getnode();
    if (first == NULL && pos == 1)
        return newnode;

    if (first == NULL)
    {
        printf("invalid position\n");
        return first;
    }
    if (pos == 1)
    {
        newnode->next = first;
        return newnode;
    }
    count = 1;
    c = NULL;
    prev = first;

    while (c != first && count != pos)
    {
        c = prev;
        prev = prev->next;
        count++;
    }

    if (count == pos)
    {
        c->next = newnode;
        newnode->next = prev;
        return first;
    }
    else
    {
        printf("invalid\n");
    }
    return first;
}

NODE delet_front(NODE first)
{
    NODE t, c;
    c = first;
    if (first == NULL)
    {
        printf("empty list\n");
        return NULL;
    }

    if (c->next == first)
    {
        printf("node deleted\n");
        free(first);
        return NULL;
    }
    c = first;
    while (c->next != first)
    {
        c = c->next;
    }
    t = first;
    first = t->next;
    c->next = first;
    printf("node deleted\n");
    free(t);
    return first;
}

NODE delet_end(NODE first)
{
    NODE c = first, prev = first;
    if (first == NULL)
    {
        printf("Empty list\n");
        exit(1);
    }
    /* // case 2 : when only one is present
     if(c->next=c)
     {
         printf("node deleted\n");
         free(first);
         return NULL;
     }*/
    // case 3 : when multiple nodes are present

    while (c->next != first)
    {
        prev = c;
        c = c->next;
    }
    prev->next = c->next;
    first = prev->next;
    printf("node deleted\n");
    free(c);
    return first;
}

NODE delet_pos(NODE first)
{
    NODE c, prev;
    int count = 1, pos;
    printf("enter the position to be entered\n");
    scanf("%d", &pos);
    if (first == NULL)
    {
        printf("Empty list\n");
        exit(1);
    }
    if (pos == 1)
    {
        delet_front(first);
        return;
    }

    c = first;
    prev = NULL;
    while (c->next != first && count != pos)
    {
        prev = c;
        c = c->next;
        count++;
    }

    if (count == pos)
    {
        c = c->next;
        prev->next = c;
        return first;
    }

    else
    {
        printf("invalid position\n");
    }
    return first;
}

void reverse_list(NODE first)
{
    NODE c, prev;
    c->prev = NULL;
    if (first == NULL)
    {
        printf("%d\n", c->data);
        printf("Only one element in the List \n");
        exit(1);
    }
    c = first;
    while (c->next != first)
    {
        prev = c;
        c = c->next;
        c->prev = prev;
    }
    while (c != first)
    {
        printf("%d\t", c->data);
        c = c->prev;
    }
    printf("%d\n", c->data);
    // printf("\n");
}

void count_key(NODE first)
{
    NODE c;
    int key, count = 0;
    printf("enter the key\n");
    scanf("%d", &key);
    c = first;
    while (c != first)
    {
        if (key == c->data)
        {
            count++;
        }
        c = c->next;
    }
    printf("count =%d\n", count);
}
