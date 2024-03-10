#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

/*

//Program to  create a SLL and Traversal
int main(){
    struct node *head;
    head = (struct node*) malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data = 98;
    current->link = NULL;
    head->link = current;

    struct node *tail = malloc(sizeof(struct node));
    tail->data = 3;
    tail->link = NULL;
    // current->link = tail  // Unnecessary creation of pointer and wastage of memory,so we use second method
    head->link->link = tail;

    //Traversing the list
    int count = 0 ;
    if(head == NULL){
        printf("List is empty!\n");
    }
    struct node *ptr = NULL;
    ptr = head;
    // printf("%d\t",ptr->data);
    while(ptr != NULL){
        printf("%d\t",ptr->data);
        count++;
        ptr = ptr->link;
    }
    printf("\nCount is: %d",count);

}*/



void traversal(struct node *head){
    int count = 0 ;
    if(head == NULL){
        printf("List is empty!\n");
    }
    struct node *ptr = NULL;
    ptr = head;
    // printf("%d\t",ptr->data);
    while(ptr != NULL){
        printf("%d\t",ptr->data);
        count++;
        ptr = ptr->link;
    }
    // printf("\nCount is: %d",count);
}

//Program to insert a node at the end of SLL
// Uses while loop for traversal before insert at end so   - time complexity : O(n)
// void add_at_end(struct node *head, int data){
//     struct node *ptr, *temp;
//     ptr = head;
//     temp = (struct node*) malloc(sizeof(struct node));
    
//     temp->data = data;
//     temp->link = NULL;

//     while(ptr->link != NULL){
//         ptr = ptr->link;
//     }
//     ptr->link = temp;
    
// }

//Optimized code to insert node at the end  - time complexity : O(1)
struct node* add_at_end(struct node *ptr, int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    ptr->link = temp;
    return temp;
}

//First mmethod: Pass by value - Function to insert at beginning of the list 
struct node* add_at_begin(struct node *ptr, int data){
    struct node *temp = malloc(sizeof(struct node)) ;
    temp->data = data;
    temp->link = NULL;

    temp->link = ptr;
    ptr = temp;

    return ptr;
}


//Second mmethod: Pass by referrence - Function to insert at beginning of the list 
void add_beg(struct node **ptr,int data){
    struct node *temp = malloc(sizeof(struct node)) ;
    temp->data = data;
    temp->link = NULL;

    temp->link = *ptr;
    *ptr = temp;
}

//Function to insert node at specific position
struct node* add_at_pos(struct node *ptr, int data,int pos){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    pos--;
    while(pos != 1){
        ptr = ptr->link;
        pos--; 
    }
    temp->link = ptr->link;
    ptr->link = temp;
    return ptr;
}

// Function to Delete first node
struct node* del_first(struct node *ptr){
    if(ptr == NULL){
        printf("List is empty\n");
    }
    struct node *temp = ptr;
    ptr = ptr->link;
    free(temp);
    temp = NULL;

    return ptr;
}

// Function to Delete Last node : Returns the head pointer // which is no necessary
// struct node* del_last(struct node *ptr){
//     if(ptr == NULL){
//         printf("List is empty\n");
//     }
//     else if(ptr->link == NULL){
//         free(ptr);
//         ptr = NULL;
//     }
//     else{
//     struct node *temp = ptr;
//     struct node *prev = ptr;
//     while(temp->link != NULL){
//         prev = temp;
//         temp = temp->link;
//     }
//     prev->link = NULL;
//     free(temp);
//     temp = NULL;
//     }
//     return ptr;
// }

// Function to Delete Last node : Doesn't returns the head pointer 
// Using double pointer
void del_last_double_ptr(struct node *ptr){
    if(ptr == NULL){
        printf("List is empty\n");
    }
    else if(ptr->link == NULL){
        free(ptr);
        ptr = NULL;
    }
    else{
    struct node *temp = ptr;
    struct node *prev = ptr;
    while(temp->link != NULL){
        prev = temp;
        temp = temp->link;
    }
    prev->link = NULL;
    free(temp);
    temp = NULL;
    }

}

// Using Single pointer: Delete node at the end
void del_last_single_ptr(struct node *ptr){
    if(ptr == NULL){
        printf("\nList is empty");
    }
    else if(ptr->link == NULL){
        free(ptr);
        ptr == NULL;
    }
    else{
        struct node *temp = ptr;
        while(temp->link->link != NULL){
            temp = temp->link;
        }
        free(temp->link);
        temp->link = NULL;
    }
}

// Delete a node at position
void delete_at_pos(struct node **ptr,int pos){
    struct node *current = *ptr;
    struct node *previous = *ptr;
    if(*ptr == NULL){
        printf("Empty Lsit\n");
    }
    else if(pos == 1){
        *ptr = current->link;
        free(current);
        current = NULL;
    }
    else{
        while(pos != 1){
            previous = current;
            current = current->link;
            pos--;
        }
        previous->link = current->link;
        free(current);
        current = NULL; 
    }
}

// Function to Delete whole list
struct node* delete_list(struct node *ptr){
    struct node *temp = ptr;
    while(temp != NULL){
        temp = temp->link;
        free(ptr);
        ptr = temp;
    }
    return ptr;
}

// Function to Reverse list
struct node* reverse_list(struct node *ptr){
    struct node *prev = NULL;
    struct node *next = NULL;
    while(ptr != NULL){
        next = ptr->link;
        ptr->link = prev;
        prev = ptr;
        ptr = next;
    }
    ptr = prev;
    return ptr;
}

// Function to insert a node into a sorted list
struct node* insert_into_sorted_list(struct node *head, int data){
    struct node *temp = head;
    struct node *newP = malloc(sizeof(struct node));
    newP->data = data;
    newP->link = NULL;
    int key = data;
    
    if(head == NULL || key < head->data){
        newP->link = head;
        head = newP;
    }
    else{
        temp = head;
        while(temp->link != NULL && temp->link->data <key){
            temp = temp->link;
        }
        newP->link = temp->link;
        temp->link = newP;
    }
    
    return head;
}

int main(){
    // struct node *head;
    // head = (struct node*) malloc(sizeof(struct node));
    struct node *head;
    head = (struct node*) malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;
   

    // Insert at end part of code
    // add_at_end(head, 98);
    // add_at_end(head, 3);
    struct node *ptr = head;
    ptr = add_at_end(ptr, 93);
    ptr = add_at_end(ptr, 30);
    ptr = add_at_end(ptr, 67);
    printf("Insert at end list:\n");
    ptr = head;
    traversal(ptr);
    printf("\n");


    // Insert at beginning part of code
    // ptr = add_at_begin(ptr, 33); //First mmethod: Pass by value - Function to insert at beginning of the list 
    // ptr = add_at_begin(ptr, 25);
    // printf("Insert at beginning: Pass by value\n");
    // traversal(ptr); // Latest ptr pointing to head of the list

    // printf("\n");
    // add_beg(&ptr, 44); //Second mmethod: Pass by referrence - Function to insert at beginning of the list 
    // add_beg(&ptr, 56);
    // printf("Insert at beginning: Pass by Reference\n");
    // traversal(ptr); // accessing first node throgh ptr 
    // head = ptr; //Assigning ptr to head, now head is pointing to first node
    // traversal(head);


    // Insert node at specific position
    // ptr = add_at_pos(ptr, 55, 3);
    // ptr = head;
    // traversal(ptr);
    // printf("\n");
    // ptr = add_at_pos(ptr, 35, 4);
    // ptr = head;
    // traversal(ptr);
    // printf("\n");
    // ptr = add_at_pos(ptr, 66, 2);
    // ptr = head;
    // traversal(ptr);


    // Delete first node of list
    // ptr = del_first(head);
    // traversal(ptr);


    // Delete last node of list
    // ptr = del_last(head); // It returns head
    // del_last_double_ptr(head); //  Head isnot returned which is not necessary since last node is deleted
    // traversal(ptr);

    // del_last_single_ptr(head); //  Head isnot returned which is not necessary since last node is deleted
    // traversal(ptr);


    // Delete a node at a position
    // delete_at_pos(&ptr,3);
    // traversal(ptr);


    // Delete whole SLL
    // ptr = delete_list(ptr);
    // traversal(ptr);


    // Reverse the list
    // ptr = reverse_list(ptr);
    // traversal(ptr);


    // Insert a node into a sorted list list
    // ptr = insert_into_sorted_list(ptr,77);
    // traversal(ptr);

}

