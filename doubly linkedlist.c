#include <stdio.h>
#include <stdlib.h>

// Define the structure for the doubly linked list node
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}


void forwardTransversal(struct node* head) {
    struct node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}


void backwardTransversal(struct node* tail) {
    struct node* curr = tail;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->prev;
    }
    printf("\n");
}

int main() {

    struct node* head = createnode(1);
    struct node* second = createnode(2);
    struct node* third = createnode(3);

    // Link nodes
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;


    printf("Forward Transversal:\n");
    forwardTransversal(head);

    printf("Backward Transversal:\n");
    backwardTransversal(third);

  
    free(head);
    free(second);
    free(third);

    return 0;
}
