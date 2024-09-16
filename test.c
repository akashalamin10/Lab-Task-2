#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
   
}node;

node *head = NULL;
node *temp = NULL;
node *newnode = NULL;

void createnode(int n){
    for(int i = 0; i < n; i++){
        newnode = (node *)(malloc(sizeof(node)));
        if(newnode == NULL){
            printf("No memory allocation\n");
            return;
        }
        printf("Enter data to store in the linked list: \n");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head==NULL){
            head = newnode;
            temp = newnode;
        }
        else{
            temp->next = newnode;
            temp = temp->next;
        }
    }
}



void insertnewnode(int data){
    newnode = (node *)(malloc(sizeof(node)));
    if(newnode == NULL){
        printf("Memory not allocated: \n");
        return;
    }
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

void insertAtEnd(int data) {
    newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Unable to allocate memory\n");
        return;
    }
    newnode->data = data;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
    }
}

void display(){
    if(head == NULL){
        printf("The link list is empty\n");
        return;
    }
    temp = head;
    while (temp != NULL)
    {
        printf("Data = %d\n", temp->data);
        temp = temp->next;
    }
    
}

int main(){

int n, data;

printf("Enter the number of nodes: \n");
scanf("%d", &n);
createnode(n);


printf("Insert the data at the beginning: \n");
scanf("%d", &data);
insertnewnode(data);


    printf("Enter data to insert at the end\n");
    scanf("%d", &data);
    insertAtEnd(data);

display();

return 0;





}