# Linked-List in C
## Introduction
A linked list is a linear data structure used for storing a sequence of elements, where each element is stored in a node that contains both the element and a pointer to the next node in the sequence. Unlike arrays, linked lists do not have a fixed size and can grow or shrink dynamically as elements are added or removed. Implementing linked lists in C involves defining structures to represent nodes and implementing operations to manipulate these nodes to create, insert, delete, and traverse the linked list.<br>

## Characteristics
Each node holds a single value and a reference to the next node in the list.<br>
The list has a head, which is a reference to the first node in the list.<br>
The nodes are not stored in a contiguous block of memory, but instead, each node holds the address of the next node in the list.
Accessing elements in a linked list requires traversing the list from the head to the desired node, as there is no direct access to a specific node in memory.<br>

## Singly Linked List
A singly linked list is a linear data structure in which the elements are not stored in contiguous memory locations and each element is connected only to its next element using a pointer.<br>

### functionalities
|Sl.no|Function|Description|
|-----|--------|-----------|
|01|traversal|Displays the list|
|02|add_at_end|Function to insert a node at the end of list|
|03|add_at_begin|Function to insert a node at the beginning of list using First method: Pass by value|
|04|add_beg|Function to insert a node at the beginning of list using Second mmethod: Pass by referrence|
|05|add_at_pos|Function to insert node at specific position|
|06|del_first| Function to Delete first node|
|07|del_last_single_ptr|Function to Delete Last node using single pointer|
|08|delete_at_pos|Function to Delete a node at position|
|09|delete_list|Function to Delete complete list|
|10|reverse_list|Function to reverse list|
|11|insert_into_sorted_list|Function to insert a node into a sorted list|

## Doubly Linked List
A doubly linked list is a special type of linked list in which each node contains a pointer to the previous node as well as the next node in the structure.<br>

### functionalities
|Sl.no|Function|Description|
|-----|--------|-----------|
|01|traversal|Displays the list|
|02|add_at_end|Function to insert a node at the end of list|
|03|add_at_begin|Function to insert a node at the beginning of list|
|04|add_after_pos|Function to insert in After a given position of list|
|05|add_at_pos|Function to insert node at specific position|
|06|createList|Function to create a complete list|
|07|del_first| Function to Delete first node|
|08|del_last| Function to Delete last node|
|09|delete_at_pos|Function to Delete a node at position|
|10|reverse_list|Function to reverse list|

## Circular Singly Linked List
A circular linked list is a special type of linked list in which the last node is connected to the first node, creating a continuous loop. In a circular linked list, each node has a reference to the next node in the sequence, just like in a regular linked list, but the last node’s reference points back to the first node.<br>

### functionalities
|Sl.no|Function|Description|
|-----|--------|-----------|
|01|traversal|Displays the list|
|02|add_at_end|Function to insert a node at the end of list|
|03|add_at_begin|Function to insert a node at the beginning of list|
|04|add_after_pos|Function to insert in After a given position of list|
|06|createList|Function to create a complete list|
|07|del_first| Function to Delete first node|
|08|del_last| Function to Delete last node|
|09|delete_at_pos|Function to Delete a node at position|

