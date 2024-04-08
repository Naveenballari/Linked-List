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
void display(NODE first);
NODE insert_front(NODE first);
NODE insert_pos(NODE first);
NODE delet_front(NODE first);
NODE traversing(NODE first);
NODE delet_end(NODE first);
NODE delet_pos(NODE first);
NODE reverse_list(NODE first);
void count_key(NODE first);
main()
{
    NODE first = NULL;
    int item, choice;
    while (1)
    {
        printf("\n1=insert at end\n2=display\n3=insert at front\n4=insert at specific position\n5=delete a node from front\n6=traversing the list\n7=delete from end\n8=delete at specific position\n9=reverse the list\n10=count the element repeated\n11=exit(0)\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            first = insert_end(first);
            break;
        case 2:
            printf("Display list :\n");
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
            first = reverse_list(first);
            break;
        case 10:
            count_key(first);
            break;
        case 11:
            exit(0);
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
    t->next = NULL;
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

    printf("\nELEMENTS OF THE LIST ARE :\n");
    t = first;
    while (t != NULL)
    {
        printf("%d\t", t->data);
        t = t->next;
    }
    return first;
}

NODE insert_end(NODE first)
{
    NODE newnode, c;
    newnode = getnode();
    if (first == NULL)
        return newnode;
    c = first;
    while (c->next != NULL)
    {
        c = c->next;
    }
    c->next = newnode;
    return first;
}

NODE insert_front(NODE first)
{
    NODE newnode, c;
    newnode = getnode();
    if (first == NULL)
        return newnode;
    newnode->next = first;
    first = newnode;
    return first;
}

NODE traversing(NODE first)
{
    NODE c;
    c = first;
    if (first == NULL)
    {
        printf("Empty list\n");
        exit(1);
    }
    while (c != NULL)
    {
        printf("%d\t", c->next);
        c = c->next;
    }
    // printf("\n");

    return first;
}

NODE insert_pos(NODE first)
{
    NODE newnode, c, prev, forth;
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

    while (forth != NULL && count != pos)
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
    NODE c;
    if (first == NULL)
    {
        printf("Empty list\n\n");
        exit(1);
    }
    c = first;
    first = c->next;
    free(c);
    return first;
}

NODE delet_end(NODE first)
{
    NODE c, prev;
    if (first == NULL)
    {
        printf("Empty list\n");
        exit(1);
    }
    c = first;
    while (c->next != NULL)
    {
        prev = c;
        c = c->next;
    }
    prev->next = NULL;
    free(c);
    return first;
}

NODE delet_pos(NODE first)
{
    NODE temp = first, prev;
    int num, check = 1;
    printf("Enter the specific point you want to Delete : ");
    scanf("%d", &num);
    if (check == 1)
    {
        prev = temp->next;
        free(temp);
        return prev;
    }
    while (temp != NULL)
    {
        if (check == num && check > 1)
        {
            break;
        }
        prev = temp;
        temp = temp->next;
        check++;
    }
    prev->next = temp->next;
    free(temp);
    return first;
}

NODE reverse_list(NODE first)
{
    NODE temp, prev;
    first->prev = NULL;
    if (first == NULL)
    {
        printf("%d\n", first->data);
        printf("Only one element in the List \n");
        exit(1);
    }
    temp = first;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
        temp->prev = prev;
    }
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void count_key(NODE first)
{
    NODE c;
    int key, count = 0;
    printf("enter the key\n");
    scanf("%d", &key);
    c = first;
    while (c != NULL)
    {
        if (key == c->data)
        {
            count += 1;
        }
        c = c->next;
    }
    printf("count of the element is = %d\n", count);

    return first;
}
