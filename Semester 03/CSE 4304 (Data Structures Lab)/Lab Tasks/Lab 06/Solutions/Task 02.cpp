#include<iostream>
using namespace std;
typedef struct node Node;

struct node
{
    int data;
    Node* next;
};

Node* insertFront (int value, Node* head)
{
    Node* temp = new Node();
    temp->data = value;
    temp->next = head;
    return temp;
}

Node* removeFront (Node* head)
{
    if (head == NULL)   return NULL;
    return head->next;
}

Node* removeBack (Node* head)
{
    if (head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while (temp->next->next != NULL)  temp = temp->next;
    temp->next = NULL;
    return head;
}

Node* removeKey(int key, Node* head)
{
    Node* temp = head;

    if (head == NULL)
    {
        cout<<"Value not present. ";
        return NULL;
    }
    if (head->data == key)
    {
        return head->next;
    }

    while (temp->next != NULL && temp->next->data != key) temp = temp->next;

    if (temp->next == NULL) cout<<"Value not present. ";
    else
    {
        temp->next = temp->next->next;
    }
    return head;
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
    for (int i=70; i>0; i-=10)  head = insertFront(i, head);
    display(head);

    int n;
    cin>>n;

    for (int i=0; i<n; i++)
    {
        int op;
        cin>>op;

        if (op == 1)    head = removeFront(head);
        else if (op == 2)   head = removeBack(head);
        else if (op == 3)
        {
            int key;
            cin>>key;
            head = removeKey(key, head);
        }
        display(head);
    }
}
