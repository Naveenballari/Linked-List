#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node *NODE;
NODE insert_end(NODE first);
NODE getnode();
void display_forward(NODE first);
void display_backward(NODE first);
NODE delet_end(NODE first);
NODE insert_front(NODE first);
NODE insert_pos_after(NODE first);
NODE insert_pos_before(NODE first);
NODE delet_front(NODE first);
NODE delet_end(NODE first);
NODE delet_pos(NODE first);
NODE deleteAfter(NODE head);
NODE swap_two(NODE head);
main()
{
    NODE first = NULL;
    int item, choice;
    while (1)
    {
        printf("\n1=insert at end\n2=display in forward\n3=display in backward\n4=insert at front\n5=insert AFTER a selected node\n6=insert BEFORE a selected node\n7=delete a node from front\n8=delete from end\n9=delete at specific position\n10=delete after a node\n11=swap the content of position\n12=exit(0)\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            first = insert_end(first);
            break;
        case 2:
            printf("Display list\n");
            display_forward(first);
            break;
        case 3:
            printf("Display list\n");
            display_backward(first);
            break;
        case 4:
            first = insert_front(first);
            break;
        case 5:
            first = insert_pos_after(first);
            break;
        case 6:
            first = insert_pos_before(first);
            break;
        case 7:
            first = delet_front(first);
            break;
        case 8:
            first = delet_end(first);
            break;
        case 9:
            first = delet_pos(first);
            break;
        case 10:
            first = deleteAfter(first);
            break;
        case 11:
            first = swap_two(first);
            break;
        case 12:
            exit(0);
        }
    }
}

NODE getnode()
{
    NODE t;
    t = malloc(sizeof(struct node));
    int item;
    if (t == NULL)
    {
        printf("empty list\n");
        return t;
    }
    printf("enter the item to be inserted\n");
    scanf("%d", &t->data);
    t->next = t;
    t->prev = t;
    return t;
}

void display_forward(NODE first)
{
    NODE t;
    if (first == NULL)
    {
        printf("Empty list\n");
        exit(0);
    }

    printf("\nELEMENTS OF THE LIST ARE :\n");
    t = first;
    while (t->next != first)
    {
        printf("%d\t", t->data);
        t = t->next;
    }
    printf("%d\t", t->data);
}

void display_backward(NODE first)
{
    NODE c;
    if (first == NULL)
    {
        printf("Empty list\n");
        exit(0);
    }

    printf("\nELEMENTS OF THE LIST ARE :\n");
    c = first->prev;
    while (c != first)
    {
        printf("%d\t", c->data);
        c = c->prev;
    }
    printf("%d\t", c->data);
}

NODE insert_end(NODE first)
{
    NODE newnode, c, t = first;
    newnode = getnode();
    if (first == NULL)
    {
        first = newnode;
        return first;
    }
    else
    {
        c = first->prev;
        c->next = newnode;
        newnode->prev = c;
        newnode->next = first;
        first->prev = newnode;
    }
    return first;
}

NODE insert_front(NODE first)
{
    NODE newnode, c, last;
    newnode = getnode();
    if (first == NULL)
        return newnode;

    c = first;
    last = first->prev;
    last->next = newnode;
    newnode->prev = last;
    newnode->next = first;
    first->prev = newnode;
    first = newnode;
    return first;
}

NODE insert_pos_after(NODE first)
{
    NODE newnode, c, t;
    int pos, count;
    printf("enter the position to insert AFTER\n");
    scanf("%d", &pos);
    newnode = getnode();
    if (first == NULL)
    {
        printf("invalid position\n");
        return first;
    }
    c = first;
    while (c->next != first && pos != c->data)
    {
        c = c->next;
    }
    if (c->next != first && pos == c->data)
    {
        t = c->next;
        c->next = newnode;
        newnode->prev = c;
        newnode->next = t;
        t->prev = newnode;
        printf("Node inserted\n");
        return first;
    }
    else if (c->next != first && pos != c->data)
    {
        printf("invalid position !!\n");
        return first;
    }

    else
    {
        t = c->next;
        c->next = newnode;
        newnode->prev = c;
        newnode->next = t;
        t->prev = newnode;
        printf("Node inserted\n");
        return first;
    }
}

NODE insert_pos_before(NODE first)
{
    NODE newnode, c, t;
    int pos, count;
    printf("enter the position to insert BEFORE\n");
    scanf("%d", &pos);
    newnode = getnode();
    if (first == NULL)
    {
        printf("invalid position\n");
        return first;
    }
    c = first;
    while (c->next != first && pos != c->data)
    {
        c = c->next;
    }
    if (c->next != first && pos == c->data)
    {
        t = c->prev;
        c->prev = newnode;
        newnode->next = c;
        newnode->prev = t;
        t->next = newnode;
        printf("Node inserted\n");
        return first;
    }
    else if (c->next != first && pos != c->data)
    {
        printf("invalid position !!\n");
        return first;
    }

    else
    {
        t = c->prev;
        c->prev = newnode;
        newnode->next = c;
        newnode->prev = t;
        t->next = newnode;
        printf("Node inserted\n");
        return first;
    }
}

NODE delet_front(NODE first)
{
    NODE c = first, last = first->prev;
    if (first == NULL)
    {
        printf("Empty list\n\n");
        exit(1);
    }
    if (first->next == NULL && first->prev == NULL)
    {
        printf("%d is deleted\n", first->data);
        free(first);
        return first;
    }
    c = first;
    first = first->next;
    first->prev = last;
    last->next = first;
    printf("node deleted\n");
    free(c);

    return first;
}

NODE delet_end(NODE first)
{
    NODE c, last;
    if (first == NULL)
    {
        printf("Empty list\n");
        exit(1);
    }
    if (first->next == NULL && first->prev == NULL)
    {
        printf("%d is deleted\n", first->data);
        free(first);
        return first;
    }

    last = first->prev;
    last->prev->next = first;
    first->prev = last->prev;
    printf("node deleted\n");
    free(c);
    return first;
}

NODE delet_pos(NODE first)
{
    NODE newnode, c, t;
    int pos, count;
    printf("enter the item to delete\n");
    scanf("%d", &pos);
    if (first == NULL)
    {
        printf("invalid position\n");
        return first;
    }
    c = first;
    while (c->next != first && pos != c->data)
    {
        t = c;
        c = c->next;
    }
    if (c->next == first && pos == c->data)
    {
        first = delet_end(first);
        return first;
    }
    else if (c->next != first && pos != c->data)
    {
        printf("invalid position\n");
        return first;
    }

    else
    {
        t->next = c->next;
        c->next->prev = t;
        free(c);
        printf("Node deleted\n");
        return first;
    }
}

NODE deleteAfter(NODE first)
{
    NODE temp1 = first, temp2 = NULL;
    int key;
    printf("Enter the number to searchand delete after\n");
    scanf("%d", &key);
    if (first == NULL)
    {
        printf("not possible as the list is empty\n");
        return first;
    }
    while (temp1->next != first && temp1->data != key)
    {

        temp1 = temp1->next;
    }
    if (temp1->next == first && temp1->data == key) // lastnode
    {

        // first=delete_front(first);
        return first;
    }
    else if (temp1->next == first && temp1->data != key)
    {
        printf("Entered node not found!! cant delete node \n");
        return first;
    }

    else
    {

        temp2 = temp1->next;
        temp1->next = temp2->next;
        temp2->next->prev = temp1;
        printf("%d is deleted\n", temp2->data);
        free(temp2);
        return first;
    }
}

NODE swap_two(NODE head)
{
    NODE c;
    int count = 1, pos, temp;
    if (head == NULL)
        printf("Empty List\n");
    else
    {
        printf("Enter the position of element to be swapped with first\n");
        scanf("%d", &pos);
        c = head;
        while (c->next != head && count != pos)
        {
            c = c->next;
            count++;
        }
        if (pos > 1 && pos <= count)
        {

            temp = c->data;
            c->data = head->data;
            head->data = temp;
        }
        else
            printf("Invalid Position\n");
        return head;
    }
}
