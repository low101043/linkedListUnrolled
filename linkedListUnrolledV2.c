#include <stdlib.h>
#include <stdio.h>

#include "unrolledlinkedlist.h"

Node* createNode(int num)
{
    Node* node;
    node = (Node*) malloc(sizeof(Node));
    node->data[0] = num;
    node->next = NULL;
    node->numberOfElements = 1;
    return node;
}

LinkedList* createList()
{
    LinkedList* newList;
    
    newList = (LinkedList*) malloc(sizeof(LinkedList));
    newList->head = NULL;
    return newList;
}

LinkedList* appendList(LinkedList* list, int num)
{
    Node* currentNode;
    currentNode = list->head;
    if (currentNode == NULL)
    {
        Node* newNode;
        newNode = createNode(num);
        list->head = newNode;

        return list;
    }
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }

    if (currentNode->numberOfElements == MAXSIZE)
    {
        Node* newNode; 
        newNode = createNode(num);
        currentNode->next = newNode;

        return list;
    }
    else
    {
        int elements;
        elements = currentNode->numberOfElements;
        currentNode->data[elements] = num;
        currentNode->numberOfElements = elements + 1;
        return list;

    }
    
}

void printNode(Node* node)
{
    int i;

    for (i=0; i <node->numberOfElements; i++)
    {
        printf("%d\n", node->data[i]);

    }

}

void printList(LinkedList* list)
{
    Node* currentNode;
    currentNode = list->head;

    if (currentNode == NULL)
    {
        printf("\n");
    }
    else
    {
        while (currentNode != NULL)
        {
            printNode(currentNode);
            currentNode = currentNode->next;
        }   
    }
}

void printInNode(Node* node)
{
    printf("New Node: Elements in node: %d | ", node->numberOfElements);

    for (int i = 0; i < MAXSIZE; i++)
    {
        if (i >= node->numberOfElements)
        {
            printf("NULL -> ");
        }
        else
        {
            printf("%d -> ", node->data[i]);
        }
    }
}

void printInList(LinkedList* list)
{
    Node* currentNode;
    currentNode = list->head;

    if (currentNode == NULL)
    {
        printf("Empty\n");
    }
    else
    {
        while (currentNode != NULL)
        {
            printInNode(currentNode);
            currentNode = currentNode->next;
        }
        printf("End\n");
    }
    
}

LinkedList* deleteFromList(LinkedList* list, int index)
{
    int i;
    Node* node;
    int found = 0;

    node = list->head;
    i = 0;

    while (node != NULL && i <= index)
    {
        int elements;
        elements = node->numberOfElements;

        i = i + elements;
        if (i > index)
        {
            node = node;
            found = 1;
        }
        else
        {
            node = node->next;
        }
    }

    if (found)
    {
        int foundSub;
        int indexElement;
        int j;

        i = i - node->numberOfElements;
        indexElement = index - i;
        foundSub = -1;
        j = 0;
        while (foundSub != indexElement)
        {
            if (node->data[j] != NULL)
            {
                foundSub = foundSub + 1;
                j = j + 1;
            }
        }   
        
        int k;

        for (k=foundSub;k<node->numberOfElements-1;k++)
        {
            int temp;
            temp = node->data[k];
            node->data[k] = node->data[k+1];
            node->data[k+1] = temp;
        }
        node->numberOfElements = node->numberOfElements - 1;
    }
    else
    {
        printf("Not here");
    }

    return list;

}

int deleteList(LinkedList* list)
{
    Node* node = list->head;
    //printf("node to delete: %d\n", *(node->data));
    while (node != NULL)
    {
        Node* nextNode = node ->next;
        free(node);
        node = nextNode;
    }
    free(list);
    return 0;
}

int findInList(LinkedList* list, int value)
{
    int index;
    int found;
    int finalIndex;
    Node* node;

    finalIndex = -1;
    index = -1;
    found = 0;  //0 == FALSE
    node = list->head;

    while (node != NULL && found == 0)
    {
        int i;
        for (i=0; i< node->numberOfElements; i++)
        {
            index = index + 1;
            if (found == 0 && node->data[i] == value)
            {
                found = 1;
                finalIndex = index;
            }

        }
        node = node->next;
    }

    return finalIndex;
}

int indexInList(LinkedList* list, int index)
{
    int indexAt;
    Node* node;

    indexAt = -1;
    node = list->head;

    while (node != NULL && indexAt < index)
    {
        int arrayIndex;
        for (arrayIndex=0; arrayIndex<node->numberOfElements; arrayIndex++)
        {
            indexAt = indexAt + 1;
            if (indexAt == index)
            {
                return (node->data[arrayIndex]);
            }
        }
        node = node->next;
    }

    return -1;
}

LinkedList* insertIntoList(LinkedList* list, int i, int value)
{
    Node* node;
    int index;
    int found;
    node = list->head;
    index = -1;
    found = 0;

    while (node != NULL && index < i)
    {
        int elements;
        elements = node->numberOfElements;
        index = index + elements;

        if (index >= i)
        {
            found = 1;
        }
        else
        {
            node = node->next;
        }
        
    }

    if (found == 0)
    {
        appendList(list, value);
        return list;
    }
    else
    {

        //printf("Inserting\n");
        //printInNode(node);
        if (node->numberOfElements != MAXSIZE)
        {
            int numHere;
            numHere = node->numberOfElements;

            index = index - numHere;
            int indexToAdd;
            indexToAdd = i - index - 1;

            int k;

            //printf("Insert at: %d\n", indexToAdd);
            
            for (k=indexToAdd;k<node->numberOfElements;k++)
            {
                int temp;
                temp = node->data[k]; 
                //printf("%d\n", temp);
                node->data[k] = value;
                value = temp;
                //printf("%d\n", value);
            }
            node->data[k] = value;
            node->numberOfElements = node->numberOfElements+1;
        }
        else
        {
            int finished;
            finished = 0;

            int numHere;
            numHere = node->numberOfElements;

            index = index - numHere;
            int indexToAdd;
            indexToAdd = i - index - 1;

            

            const int NODES_TO_CHECK = 2;
            int checkedNodes = 0;


            while (checkedNodes < NODES_TO_CHECK && finished == 0)   
            {   
                int k;
                for (k=indexToAdd;k<node->numberOfElements;k++)
                {
                    int temp;
                    temp = node->data[k]; 
                    //printf("%d\n", temp);
                    node->data[k] = value;
                    value = temp;
                    //printf("%d\n", value);
                }

                
                checkedNodes = checkedNodes + 1;
                if (node->numberOfElements != MAXSIZE)
                {
                    node->data[k] = value;
                    node->numberOfElements = node->numberOfElements + 1;
                    finished = 1;
                }

                else
                {
                    if (checkedNodes < NODES_TO_CHECK)
                    {
                        if (node->next == NULL)
                        {
                            Node* newNode;

                            newNode = createNode(value);
                            node->next = newNode;
                            finished = 1;
                        }
                        else
                        {
                            node = node->next;
                            indexToAdd = 0;
                        }
                       
                    }
                    else
                    {
                        Node* newNode;

                        newNode = createNode(value);
                        Node* nextNode = node->next;
                        node->next = newNode;
                        newNode->next = nextNode;
                        finished = 1;
                    }
                   
                }
               
            }
            return list; 

        }
        
        return list;
    }
    
    
}

int main()
{
    //This code is for testing and showing the code working.  Please edit!
    LinkedList* list;
    list = createList();

    printList(list);
    printInList(list);
    printf("\n\n");

    

    list = appendList(list, 1);
    list = appendList(list, 2);
    list = appendList(list, 3);
    list = appendList(list, 4);
    list = appendList(list, 5);
    list = appendList(list, 6);
    list = appendList(list, 7);
    list = appendList(list, 8);
    list = appendList(list, 9);
    list = appendList(list, 10);
    list = appendList(list, 11);
    list = appendList(list, 12);
    list = appendList(list, 13);
    list = appendList(list, 24);

    printf("\n\n");
    printf("Deleting\n");
    printInList(list);
    list = deleteFromList(list, 10);
    printInList(list);
    printf("\n\n");
    list = deleteFromList(list, 11);
    list = deleteFromList(list, 10);
    printInList(list);
    printf("\n\n");

    ///list = insertIntoList(list, 8, 50);
    //list = insertIntoList(list, 9, 51);
    printf("\n\n");
    printInList(list);

    printf("\n\n");


    //printList(list);
    printInList(list);

    list = insertIntoList(list,5,100);
    printf("\n\n");

    printInList(list);


    deleteList(list);
}