#include<iostream>
using namespace std;
typedef struct node Node;

struct node
{
    int value;
    Node* next;
};

Node* createNode(int value, Node* next) //allocating memory to node
{
    Node* newNode = new Node();
    if (newNode != NULL)    //NULL will occur if out of memory
    {
        newNode->value = value;
        newNode->next = next;
        return newNode;
    }
    return NULL;
}

Node* prepend (Node* head, int value)       //add node before head
{
    Node* newNode = createNode(value, head);
    if (newNode != NULL)    return newNode;
    else                    return head;
}

Node* insertNode(int item, Node* head, int value)   //add node elsewhere
{
    Node* temp = head;
    Node* newNode = createNode(value, NULL);

    while (temp != NULL && temp->value != item) temp = temp->next;  //find value after which to add

    if (temp != NULL && newNode != NULL)
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
}

Node* removeNode(int value, Node* head)
{
    Node* cur = head;
    Node* prev;
    while (cur != NULL && cur->value != value)  //locate value to delete
    {
        prev = cur; //keep track of previous value
        cur = cur->next;
    }

    if (cur != NULL)
    {
        if (cur == head)    return head->next;  //if head is deleted, prev wont exist
        else    prev->next = cur->next;
    }
    return head;
}

Node* flipList (Node* head) //inverting the list
{
    Node* cur = head;
    Node* prev = NULL;
    Node* after;
    while (cur != NULL)
    {
        after = cur->next;  //keep track of next value
        cur->next = prev;   //flip pointer
        prev = cur;
        cur = after;
    }
    return prev;    //the last prev value will be the last member of the array which is now the head
}

void display(Node* node)  //keep printing till NULL
{
    while (node != NULL)
    {
        cout<<node->value<<" ";
        node = node->next;
    }
    cout<<endl;
}

int main()
{
    Node* head = NULL;
}
