#include<iostream>
using namespace std;

typedef struct node Node;

struct node
{
    int data;
    Node* next;
};

Node* createNode(int value, Node* next)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = next;
    return newNode;
}

Node* insertFront(int value, Node* head)
{
    Node* temp = createNode(value, head);
    return temp;
}

Node* insertBack(int value, Node* head)
{
    Node* temp = createNode(value, NULL);
    if (head == NULL)   return temp;
    Node* cur = head;
    while (cur->next != NULL)   cur = cur->next;
    cur->next = temp;
    return head;
}

void insertMiddle(int value, int key, Node* head)
{
    Node* temp = createNode(value, NULL);
    Node* cur = head;
    while (cur != NULL && cur->data != key) cur = cur->next;
    if (cur == NULL)    cout<<"Value not found. ";
    else
    {
        temp->next = cur->next;
        cur->next = temp;
    }
}

void display(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* head;
    head = NULL;

    int n;
    cin>>n;

    for (int i=0; i<n; i++)
    {
        int op;
        cin>>op;

        if (op == 1)
        {
            int value;
            cin>>value;
            head = insertFront(value, head);
        }
        else if (op == 2)
        {
            int value;
            cin>>value;
            head = insertBack(value, head);
        }
        else if (op == 3)
        {
            int value, key;
            cin>>value>>key;
            insertMiddle(value, key, head);
        }
        display(head);
    }
}
