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

LinkedList* append(LinkedList* list, int num);
void printList(LinkedList* list);
void printNode(Node* node);
void printInList(LinkedList* list);
LinkedList* insert(int i, int value, LinkedList* list);
LinkedList* delete(int index, LinkedList* list);
int index(int index, LinkedList* list);
int find(int value, LinkedList* list);

