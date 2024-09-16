//5.write any Self-Referential Structure code.  
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;
node *temp = NULL;
node *newnode = NULL;

void createnode(int n) {
    for (int i = 0; i < n; i++) {
        newnode = (node *)malloc(sizeof(node));
        if (newnode == NULL) {
            printf("Unable to allocate memory\n");
            return;
        }
        printf("Enter the data to store in the linked list: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = temp->next;
        }
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    while (temp != NULL) {
        printf("Data = %d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);

    createnode(n);
    display();

    return 0;
}
