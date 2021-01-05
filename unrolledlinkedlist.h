#define MAXSIZE 4
typedef struct Node
{
    int numberOfElements;
    int data[MAXSIZE];
    struct Node* next;

} Node;

typedef struct LinkedList
{
    Node* head;

} LinkedList;

LinkedList* createList();  //DONE
LinkedList* appendList(LinkedList* list, int num);  //DONE
void printList(LinkedList* list);  //DONE
void printNode(Node* node);  //DONE
void printInList(LinkedList* list);  //DONE
LinkedList* insertIntoList(LinkedList* list, int i, int value);
LinkedList* deleteFromList(LinkedList* list, int index);
int indexInList(LinkedList* list, int index);  //DONE
int findInList(LinkedList* list, int value);  //DONE
int deleteList(LinkedList* list);  //DONE