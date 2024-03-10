#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

// Function add a node to an Empty list
struct node *add_To_Empty(struct node *head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;

    return head;
}

void traversal(struct node *head)
{
    int count = 0;
    if (head == NULL)
    {
        printf("List is empty!\n");
    }
    struct node *ptr = NULL;
    ptr = head;
    // printf("%d\t",ptr->data);
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        count++;
        ptr = ptr->next;
    }
    // printf("\nCount is: %d",count);
}

/*
//Program for creating a node
int  main(){
    struct node *head = malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = 10;
    head->next = NULL;
}

int main(){
    struct node *head = NULL;
    head = addToEmpty(head,45);
    printf("%d",head->data);

    return 0;
}*/

// Function to insert a node at the beginning of the list
struct node *add_at_begin(struct node *head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;

    return head;
}

// function to insert at the End of the list
struct node *add_at_end(struct node *head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    struct node *ptr;
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;

    return head;
}

// Insert in After a given position of list
struct node *add_after_pos(struct node *head, int data, int pos)
{
    struct node *newP = NULL;
    struct node *temp = head;
    struct node *temp2 = NULL;
    newP = add_To_Empty(newP, data);

    while (pos != 1)
    {
        temp = temp->next;
        pos--;
    }
    if (temp->next == NULL)
    {
        temp->next = newP;
        newP->prev = temp;
    }
    else
    {
        temp2 = temp->next;
        temp->next = newP;
        temp2->prev = newP;
        newP->next = temp2;
        newP->prev = temp;
    }

    return head;
}

// Insert in At a given position of list
struct node *add_at_pos(struct node *head, int data, int pos)
{
    struct node *newP = NULL;
    struct node *temp = head;
    struct node *temp2 = NULL;
    newP = add_To_Empty(newP, data);

    while (pos > 2)
    {
        temp = temp->next;
        pos--;
    }
    if (pos == 1)
    {
        head = add_at_begin(head, data);
    }
    else if (temp->next == NULL)
    {
        head = add_at_end(head, data);
    }
    else
    {
        temp2 = temp->next;
        temp->next = newP;
        temp2->prev = newP;
        newP->next = temp2;
        newP->prev = temp;
    }

    return head;
}

// function for creating a complete list
struct node *createList(struct node *head)
{
    int n, data, i;
    printf("Enter the number of elemens\n");
    scanf("%d", &n);
    if (n == 0)
    {
        return head;
    }

    printf("Enter the element for node 1:\n");
    scanf("%d", &data);
    head = add_To_Empty(head, data);

    for (int i = 1; i < n; i++)
    {
        printf("Enter the element for the node %d:\n", i + 1);
        scanf("%d", &data);
        head = add_at_end(head, data);
    }

    return head;
}

/*
// Main function for creating a complete list
int main(){
    struct node* head = NULL;
    struct node* ptr;
    head = createList(head);

    ptr= head;
    while(ptr != NULL){
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}*/

// Function to Delete the First node of list
struct node *del_first(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    struct node *temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    free(temp);

    return head;
}

// Function to Delete Lastnode of list
struct node *del_last(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    struct node *temp = head;
    struct node *temp2;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp2 = temp->prev;
    temp2->next = NULL;
    free(temp);

    return head;
}

// Function to delete inter mediate node of list
struct node *del_at_pos(struct node *head, int pos)
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }

    struct node *temp = head;
    struct node *temp2;

    if (pos == 1)
    {
        head = del_first(head);
    }
    while (pos > 1)
    {
        temp = temp->next;
        pos--;
    }
    if (temp->next == NULL)
    {
        head = del_last(head);
    }
    else
    {
        temp2 = temp->prev;
        temp2->next = temp->next;
        temp->next->prev = temp2;
        free(temp);
    }

    return head;
}

// Reverse the given list
struct node *reverse_list(struct node *head)
{
    struct node *ptr1 = head;
    struct node *ptr2 = ptr1->next;

    ptr1->next = NULL;
    ptr1->prev = ptr2;

    while (ptr2 != NULL)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    head = ptr1;

    return head;
}

// Main function for all list operations like insertion , deletion etc..
int main()
{
    struct node *head = NULL;
    struct node *ptr;
    head = add_To_Empty(head, 45);

    // Insert at beginning of list
    head = add_at_begin(head, 34);
    // traversal(head);
    printf("\n");

    // Insert at End of list
    head = add_at_end(head, 9);
    traversal(head);
    printf("\n");

    // Insert at the given position of list
    head = add_after_pos(head, 25, 2);
    traversal(head);
    printf("\n");

    // Insert in between given position of list / At specific position
    head = add_at_pos(head, 75, 3);
    printf("Working List:\n");
    traversal(head);
    printf("\n");

    // Delete the first node of list
    // head = del_first(head);
    // traversal(head);

    // Delete the Last node of list
    // head = del_last(head);
    // traversal(head);

    // Delete the inter mediate node of list / At specific position
    // head = del_at_pos(head, 3);
    // traversal(head);

    // Reverse the list
    printf("Before Reversing the list:\n");
    traversal(head);
    head = reverse_list(head);
    printf("\nAfter Reversing the list:\n");
    traversal(head);
    return 0;
}
