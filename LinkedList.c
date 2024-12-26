#include <stdio.h>
#include <stdlib.h>
struct node{
 int a;
 struct node *link;
 };

 // Function to delete a node at a specific position
struct node* deleteAtPosition(struct node *head, int position) {
    if (position == 0) {
        // Delete the head node
        struct node *temp = head->link;
        head->link = temp->link;
        free(temp);
        return;
    }

    struct node *current = head;
    struct node *prev = NULL;
    for (int i = 0; i < position; i++) {
        prev = current;
        current = current->link;
    }

    prev->link = current->link;
    free(current);
    return head;
}

// Function to insert a node at a specific position
struct node* insertAtPosition(struct node *head, int data, int position) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->a = data;
    newNode->link = NULL;

    if (position == 0) {
        // Insert at the head
        newNode->link = head;
        head = newNode;
        return;
    }
    else
    {

        struct node *current = head;
        for (int i = 0; i < position - 1; i++) {
            current = current->link;
        }

        newNode->link = current->link;
        current->link = newNode;
    }
    return head;
}
// Function to search for a value in the linked list
int search(struct node *head, int key) {
    struct node *current = head;
    int position = 0;

    while (current != NULL) {
        if (current->a == key) {
            return position;  // Return the position where the key is found
        }
        current = current->link;
        position++;
    }

    return -1;  // Return -1 if the key is not found
}


int main(){
    int N;
    scanf("%d",&N);
    struct node *head=NULL;
    struct node *current=NULL;
    for(int i=0;i<N;i++){
				//Creating Node
        struct node *NewNode=malloc(sizeof(struct node));
        NewNode->a=rand()%100; //scanf("%d",&NewNode->a);
        NewNode->link=NULL;
				//Creating Linked list
        if(head==NULL) {
            head=NewNode;
            current=head;    }
        else {
             current->link = NewNode;
             current=NewNode; }
    }
		//Traversing the linked list
    struct node *currentNode;
    currentNode=head;
    while(currentNode!=NULL)
    {
        printf("%d ", currentNode->a);
        currentNode=currentNode->link;
    }

    // Insert a new node at a specific position
    int data, position;
    printf("\nEnter the data and position to insert:\n");
    scanf("%d %d", &data, &position);
    head=insertAtPosition(head, data, position);

    // Traversing the linked list after insertion
    currentNode = head;
    printf("\nLinked list after insertion:\n");
    while (currentNode != NULL) {
        printf("%d ", currentNode->a);
        currentNode = currentNode->link;
    }
    printf("\n");

     // Delete a node at a specific position
    printf("\nEnter the position to delete:\n");
    scanf("%d", &position);
    head=deleteAtPosition(head, position);

    // Traversing the linked list after deletion
    currentNode = head;
    printf("\nLinked list after deletion:\n");
    while (currentNode != NULL) {
        printf("%d ", currentNode->a);
        currentNode = currentNode->link;
    }
    printf("\n");


    int key;
    printf("\nEnter the value to search for:\n");
    scanf("%d", &key);
    int foundPosition = search(head, key);

    if (foundPosition != -1) {
        printf("Value %d found at position %d.\n", key, foundPosition);
    } else {
        printf("Value %d not found in the list.\n", key);
    }

    return 0;
}

