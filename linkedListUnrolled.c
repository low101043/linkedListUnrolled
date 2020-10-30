#define MAXSIZE 4
#include <stdlib.h>
#include <stdio.h>


typedef struct Node{
    int numberOfElements;
    int data[MAXSIZE];
    struct Node* next;
} Node;

typedef struct LinkedList{
    Node* head;
} LinkedList;

Node* createNode(int value){
    Node *node;

    node = (Node *) malloc(sizeof(Node));
    node -> numberOfElements = 1;
    node -> data[0] = value;
    node -> next = NULL;
    printf("Added Node: %d\n", node ->data[0]);
    return node;
}

LinkedList* append(LinkedList* list, int num){
    Node* node = list ->head;
    printf("Adding number: %d\n", num);
    if (node == NULL){
        Node* headNode = createNode(num);
        list -> head = headNode;
        printf("Data added: %d", headNode->data[0]);
        return list;
    }
    else{
        int amountInHead;
        printf("We have got here\n");
        amountInHead = node -> numberOfElements;
        printf("Got the data\n");
        int finished = 0;
        while (amountInHead >= MAXSIZE && finished == 0){

            if (node -> next== NULL){
                Node* newNode = createNode(num);
                node ->next = newNode;
                finished = 1;

            }
            else{
                node = node -> next;
            }
        }
        if (amountInHead < MAXSIZE){
            node -> data[amountInHead] = num;
            node -> numberOfElements = node -> numberOfElements + 1;
        }
        printf("The data added is %d\n", node->numberOfElements);
        return list;
    }
    
}

void printList(LinkedList* list){
    Node* node = list -> head;
    printf("We have got the node\n");
    int data = node -> numberOfElements;
    printf("WE have got the node data %d\n", data);
    printf("%d\n", node -> data[0]);
}

int destroyListAll(LinkedList* list){
    Node* node = list->head;
    //printf("node to delete: %d\n", *(node->data));
    while (node != NULL){
        Node* nextNode = node ->next;
        free(node);
        node = nextNode;
    }
    free(list);
    return 0;
}

int main(){
    
    printf("Do we even start?\n");
    LinkedList *list;
    printf("Started\n");

    list = (LinkedList *) malloc(sizeof(LinkedList));
    printf("List Created\n");
    
    list -> head = NULL;
    list = append(list, 5);
    //printf("Appended 5\n");
    list = append(list, 6);
    //printf("Appended 6\n");
    list = append(list, 8);
    //printf("Appended 8\n");
    list = append(list, 10);
    //printf("Appended 10\n");
    list = append(list, 3);
    //printf("Appended 3\n");
    list = append(list, 18);
    //printf("Appended 18\n");
    printf("Destroying All\n");
    printList(list);
    destroyListAll(list);
    return 0;
}