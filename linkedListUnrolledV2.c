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

LinkedList* append(LinkedList* list, int num)
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

int main()
{
    LinkedList* list;
    list = createList();

    printList(list);

    list = append(list, 1);
    list = append(list, 2);
    list = append(list, 3);
    list = append(list, 4);
    list = append(list, 5);
    list = append(list, 6);
    list = append(list, 7);
    list = append(list, 8);
    list = append(list, 9);
    list = append(list, 10);
    list = append(list, 11);
    list = append(list, 12);
    list = append(list, 13);
    list = append(list, 24);

    printList(list);

    deleteList(list);
}