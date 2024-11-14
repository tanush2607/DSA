#include <stdio.h>
#include <stdlib.h>

// Define the structure for each node in the priority queue
struct node {
    int data;
    int priority;
    struct node *next;
};

// Function to peek at the top element of the priority queue
int peek(struct node *head) {
    if (head == NULL) {
        printf("Priority queue is empty.\n");
        return -1; // Return a default value or handle error accordingly
    }
    return head->data; // Return the data of the head node
}

// Function to pop (remove) the top element of the priority queue
struct node *pop(struct node *head) {
    if (head == NULL || head->next==NULL) {
        printf("Priority queue is empty.\n");
        return NULL; // Return NULL if the queue is empty
    }
    struct node *temp = head;
    head = head->next;
    free(temp); // Free the memory of the removed node
    return head; // Return the updated head pointer
}

// Function to push (insert) a new element into the priority queue
struct node *push(int data, int priority, struct node *head) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->priority = priority;
    newnode->next = NULL; // Initialize next pointer to NULL
    
    // If the priority queue is empty or new node has highest priority
    if (head == NULL || head->priority < priority) {
        newnode->next = head;
        return newnode; // New node becomes the new head
    }
    
    struct node *ptr = head;
    while (ptr->next != NULL && ptr->next->priority > priority) {
        ptr = ptr->next; // Traverse until the correct position is found
    }
    
    newnode->next = ptr->next;
    ptr->next = newnode; // Insert the new node
    
    return head; // Return the head of the updated priority queue
}

int main() {
    struct node *head = NULL; // Initialize an empty priority queue
    
    // Push elements into the priority queue
    head = push(20, 2, head);
    head = push(40, 4, head);
    head = push(50, 5, head);
    head = push(10, 1, head);
    head = push(60, 6, head);
    head = push(55, 5, head);
    
    // Print and peek at the top element of the priority queue
    printf("Top element: %d\n", peek(head));
    
    // Pop elements from the priority queue
    head = pop(head);
    head = pop(head);
    
    // Print and peek again after popping
    printf("Top element after popping: %d\n", peek(head));
    
    // Free the remaining nodes in the priority queue
    while (head != NULL) {
        head = pop(head);
    }
    
    return 0;
}
