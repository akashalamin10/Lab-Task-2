#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;

// Function to create nodes
void createnode(int n) {
    for (int i = 0; i < n; i++) {
        node *newnode = (node *)malloc(sizeof(node));
        if (newnode == NULL) {
            printf("Unable to allocate memory\n");
            return;
        }
        printf("Enter the data to store in the linked list: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
}

// Function to insert a node at the end
void insertAtEnd(int data) {
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Unable to allocate memory\n");
        return;
    }
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// Function to display the linked list
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node *temp = head;
    while (temp != NULL) {
        printf("Data = %d\n", temp->data);
        temp = temp->next;
    }
}

// Function to free the allocated memory
void freeList() {
    node *current = head;
    node *nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    head = NULL;
}

int main() {
    int n, data;

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);

    createnode(n);

    printf("Enter data to insert at the end: ");
    scanf("%d", &data);
    insertAtEnd(data);

    display();
    freeList();

    return 0;
}
