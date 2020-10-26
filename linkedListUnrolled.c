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
}

LinkedList* append(LinkedList* list, int num){
    Node* node = list ->head;
    //printf("Adding number: %d\n", num);
    if (node == NULL){
        Node* head = createNode(num);
        return list;
    }
    else{
        int amountInHead;
        amountInHead = node -> numberOfElements;
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
        return list;
    }
    
}

void printList(Node* head){
    ;
}

int destroyListAll(LinkedList* list){
    Node* node = list->head;
    while (node != NULL){
        Node* nextNode = node ->next;
        free(node);
        node = nextNode;
    }
    free(list);
    return 0;
}

int main(){
    
    LinkedList *list;

    list = (LinkedList *) malloc(sizeof(LinkedList));
    
    list -> head = NULL;
    list = append(list, 5);
    list = append(list, 6);
    list = append(list, 8);
    list = append(list, 10);
    list = append(list, 5);
    list = append(list, 6);
    list = append(list, 8);
    list = append(list, 10);
    list = append(list, 5);
    list = append(list, 6);
    list = append(list, 8);
    list = append(list, 10);
    destroyListAll(list);
    return 0;
}