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
LinkedList* insertIntoList(int i, int value, LinkedList* list);
LinkedList* deleteFromList(int index, LinkedList* list);
int indexInList(int index, LinkedList* list);  //DONE
int findInList(int value, LinkedList* list);  //DONE
int deleteList(LinkedList* list);  //DONE