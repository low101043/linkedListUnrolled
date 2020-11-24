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
    //printf("Added Node: %d\n", node ->data[0]);
    return node;
}

LinkedList* append(LinkedList* list, int num){
    Node* node = list ->head;
    //printf("Adding number: %d\n", num);
    if (node == NULL){
        Node* headNode = createNode(num);
        list -> head = headNode;
        //printf("Data added: %d", headNode->data[0]);
        return list;
    }

    else
    {
        while (node ->next != NULL)
        {
            node = node -> next;
        }
        
        if (node->numberOfElements == MAXSIZE)
        {
            Node* newNode = createNode(num);
            node->next = newNode;
            return list;
        }
        else
        {
            node->data[node->numberOfElements] = num;
            node->numberOfElements = (node->numberOfElements) + 1;
            return list;
        }
        
    }
    
    /*else{           //CHANGE TO WHILE NEXT NOT NULL
        int amountInHead;
        //printf("We have got here\n");
        amountInHead = node -> numberOfElements;
        //printf("Data in node: %d\n", amountInHead);
        //printf("Got the data\n");
        int finished = 0;
        while (amountInHead >= MAXSIZE && finished == 0 /*&& node -> next != NULL){
            

            if (node -> next == NULL){
                Node* newNode = createNode(num);
                node ->next = newNode;
                finished = 1;

            }
            else{
                node = node -> next;
                amountInHead = node ->numberOfElements;
            }
        }
        if (amountInHead < MAXSIZE && node ->next == NULL){
            node -> data[amountInHead] = num;
            node -> numberOfElements = node -> numberOfElements + 1;
        }
        else if (finished == 0){
            printf("Not added %d\n", num);
            //NEED TO ADD A VALUE AT END SOMEHOW!
        }
        //printf("The data added is %d\n", node->numberOfElements);
        return list;
    }*/
    
}

void printList(LinkedList* list){
    Node* node = list -> head;
    int numOfElementsHead;
    numOfElementsHead = node -> numberOfElements;
    int iHead;
    printf("Number of elements is: %d\n", numOfElementsHead);
    for (iHead = 0; iHead < numOfElementsHead; iHead++){
        int nodeData;
        //printf("Number of data in node: %d\n", numOfElementsHead);
        nodeData = node ->data[iHead];
        printf("%d\n", nodeData);
    }
    //printf("We have got the node\n");
    
    while(node->next != NULL)
    {
        node = node -> next;
        int numOfElements;
        numOfElements = node -> numberOfElements;
        int i;
        printf("Number of elements is: %d\n", numOfElements);
        for (i = 0; i < numOfElements; i++){
            int nodeData;
            //printf("Number of data in node: %d\n", numOfElements);
            nodeData = node ->data[i];

            printf("%d\n", nodeData);
        }
        
    }
    
    //printf("WE have got the node data %d\n", data);
    //printf("%d\n", node -> data[0]);
}

void printNode(Node* node){
    int numOfElementsHead;
    numOfElementsHead = node -> numberOfElements;
    int iHead;
    for (iHead = 0; iHead < numOfElementsHead; iHead++){
        int nodeData;
        nodeData = node ->data[iHead];
        printf("%d\n", nodeData);
    }
}

void printInList(LinkedList* list){
    Node* head = list->head;

    if (head == NULL)
    {
        printf("Empty List\n");
        return;
    }
    else
    {
        while (head != NULL)
        {
            printf("New Node: ");
            for (int i = 0; i < MAXSIZE; i++)
            {
                if (i >= head->numberOfElements)
                {
                    printf("NULL ->");
                }
                else
                {
                    printf("%d ->", head->data[i]);
                }
            }
            head = head->next;
        }
        printf("End\n");
    }
}

LinkedList* insert(int i, int value, LinkedList* list){

    //NEED TO ADD ELEMENTS INTO ONE SPECIFIC PLACE
    Node* node;
    node = list ->head;
    int element;
    element = node -> numberOfElements;
    int posInList;
    posInList = i;
    
    while (node -> next != NULL && element <= i){
        node = node -> next;
        element = element + (node -> numberOfElements);
        posInList = posInList - element;

    }
    printf("Index: %d, Elements Gone Through: %d, PositionToPlace: %d\n", i, element, posInList);
    //printNode(node);
    
    if (node -> next == NULL){
        Node* newNode = createNode(value);
        node ->next = newNode;
        return list;
    }
    else{
        int elements = node ->numberOfElements;
        if (elements == MAXSIZE){
            
            int dataToMoveOn;
            //dataToMoveOn = node ->data[posInList];
            //node -> data[posInList] = value;
            for (int j = posInList; j < node->numberOfElements; j++){
                int temp = node -> data[j];
                node->data[j] = value;
                value = temp;
            }
            dataToMoveOn = value;
            int twoOn;
            twoOn = 0;
            while (twoOn < 1 && elements == MAXSIZE){
                printf("In twoOn Loop.  Also Elements: %d\n", elements);
                twoOn = twoOn + 1;
                node = node->next;
                for (int j = posInList; j < node->numberOfElements; j++){
                    int temp = node -> data[j];
                    node->data[j] = value;
                    value = temp;
                }
                dataToMoveOn = value;
                elements = node ->numberOfElements;
                printf("New data.  twoOn %d.  elements: %d\n", twoOn, elements);
            }
            printf("twoOn is %d\n", twoOn);
            if (twoOn == 1){
                printNode(node);
                Node* newNode = createNode(dataToMoveOn);
                Node* nodeToReLink;
                nodeToReLink = node -> next;
                node -> next = newNode;
                newNode -> next = nodeToReLink;
            }
            else{
                node = node -> next;
                printNode(node);
            }
        }
    }
    return list;
}

LinkedList* delete(int value, LinkedList* list){
    return NULL;
}

LinkedList* deleteIndex(int index, LinkedList* list){
    return NULL;
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
    
    //printf("Do we even start?\n");
    LinkedList *list;
    //printf("Started\n");

    list = (LinkedList *) malloc(sizeof(LinkedList));
    //printf("List Created\n");
    
    list -> head = NULL;
    list = append(list, 2);
    //printList(list);
    printf("\n\n");
    //printf("Appended 5\n");
    list = append(list, 3);
    //printList(list);
    printf("\n\n");
    //printf("Appended 6\n");
    list = append(list, 4);
    //printList(list);
    printf("\n\n");
    //printf("Appended 8\n");
    list = append(list, 5);
    //printList(list);
    printf("\n\n");
    //printf("Appended 10\n");
    list = append(list, 6);
    //printList(list);
    printf("\n\n");
    //printf("Appended 3\n");
    list = append(list, 7);
    //printList(list);
    printf("\n\n");
    list = append(list, 8);
    //printList(list);
    printf("\n\n");
    list = append(list, 9);
    //printList(list);
    printf("\n\n");
    list = append(list, 10);
    //printList(list);
    printf("\n\n");
    list = append(list, 11);
    list = append(list, 12);
    list = append(list, 13);
    printList(list);
    printf("\n\n");
    //printf("Appended 18\n");
    //printf("Destroying All\n");
    list = insert(0, 1, list);
    list = append(list, 15);
    printList(list);
    printf("\n\n");
    //printList(list);
    printInList(list);
    destroyListAll(list);
    return 0;
}