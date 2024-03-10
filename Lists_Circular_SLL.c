#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// Fucntion to create a node Circular DLL
struct node *add_to_empty(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;

    return temp;
}

void traversal(struct node *tail)
{
    struct node *ptr = tail->next;
    do
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    } while (ptr != tail->next);
}

// Function to add at beginning
struct node *add_at_begin(struct node *tail, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = tail->next;
    tail->next = temp;

    return tail;
}

// Function to add at End
struct node *add_at_end(struct node *tail, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    temp->next = tail->next;
    tail->next = temp;
    tail = tail->next;

    return tail;
}

// Function to add in between nodes
struct node *add_after_pos(struct node *tail, int data, int pos)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    struct node *ptr = tail->next;
    while (pos > 1)
    {
        ptr = ptr->next;
        pos--;
    }

    temp->next = ptr->next;
    ptr->next = temp;
    if (ptr == tail)
    {
        tail = tail->next;
    }

    return tail;
}

// Function to create a complete list
struct node *create_list(struct node *tail)
{
    int i, n, data;
    printf("Enter the number of nodes:\n");
    scanf("%d", &n);

    if (n == 0)
    {
        printf("No node in the list\n");
        return tail;
    }
    printf("Enter the node 1:");
    scanf("%d", &data);
    tail = add_to_empty(data);

    for (int i = 1; i < n; i++)
    {
        printf("Enter the node %d:", i + 1);
        scanf("%d", &data);
        tail = add_at_end(tail, data);
    }

    return tail;
}

/*
// Main function to create complete list
int main()
{
    struct node *tail = NULL;
    tail = create_list(tail);
    traversal(tail);
}*/

// Function to Delete a node at the beginning
struct node *del_first(struct node *tail)
{
    struct node *temp;
    if (tail == NULL)
    {
        printf("Empty List\n");
    }
    if (tail->next == tail)
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    temp = tail->next;
    tail->next = temp->next;
    free(temp);
    temp = NULL;

    return tail;
}

// Function to Delete a node at the end
struct node *del_last(struct node *tail)
{
    struct node *temp = tail->next;
    if (tail == NULL)
    {
        printf("Empty List\n");
    }
    if (tail->next == tail)
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = tail->next;
    free(tail);
    tail = temp;

    return tail;
}

// Function to Delete a node in between the list
struct node *delete_at_pos(struct node *tail, int pos)
{
    struct node *temp = tail->next;
    if (tail == NULL)
    {
        printf("Empty List\n");
    }
    if (tail->next == tail)
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    while (pos > 2)
    {
        temp = temp->next;
        pos--;
    }
    struct node *temp2;
    temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
    temp2 = NULL;

    return tail;
}

// Main function for operations like insertion and deletion etc..
int main()
{
    struct node *tail;
    tail = add_to_empty(34);

    // Insert a node at the beginning of list
    tail = add_at_begin(tail, 45);
    traversal(tail);
    printf("\n");

    // Insert a node at the end of list
    tail = add_at_end(tail, 25);
    traversal(tail);
    printf("\n");

    // Insert a node in between nodes of list
    tail = add_after_pos(tail, 9, 2);
    traversal(tail);
    printf("\n");

    // Delete a node at the beginning of list
    // tail = del_first(tail);
    // traversal(tail);
    // printf("\n");

    // Delete a node at the end of list
    tail = del_last(tail);
    traversal(tail);
    printf("\n");

    // Delete a node in between the list
    tail = delete_at_pos(tail,3);
    traversal(tail);
    printf("\n");
    return 0;
}
