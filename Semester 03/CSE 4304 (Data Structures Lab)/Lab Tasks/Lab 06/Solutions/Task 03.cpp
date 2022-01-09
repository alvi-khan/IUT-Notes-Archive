#include<iostream>
using namespace std;
typedef struct node Node;

struct node
{
    int data;
    Node* next;
    Node* prev;
};

Node* insertKey(int value, int key, Node* head)
{
    Node* temp = new Node();    //creating node
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;

    if (key == -1)  //inserting to front
    {
        temp->next = head;
        if (head != NULL)   head->prev = temp;
        return temp;
    }
    else if (key == -2) //inserting to back
    {
        if (head == NULL)  return temp; //if list was empty
        Node* cur = head;
        while (cur->next != NULL)   cur = cur->next;
        temp->prev = cur;
        cur->next = temp;
        return head;
    }
    else
    {
        Node* cur = head;
        if (cur == NULL)    //if list was empty
        {
            cout<<"Value not present. ";
            return head;
        }
        while (cur != NULL && cur->data != key) cur = cur->next;    //keep going till the end
        if (cur == NULL)
        {
            cout<<"Value not present. ";
            return head;
        }
        else
        {
            temp->prev = cur;   //changing pointers
            temp->next = cur->next;
            if (cur->next != NULL)    cur->next->prev = temp;
            cur->next = temp;
            return head;
        }
    }
}

Node* deleteKey(int key, Node* head)
{
    if (key == -1)  //deleting from front
    {
        if (head == NULL)   return NULL;
        else    return head->next;
    }
    else if (key == -2) //deleting from back
    {
        if (head == NULL || head->next == NULL) return NULL;
        Node* cur = head;
        while (cur->next != NULL)   cur = cur->next;
        cur->prev->next = NULL;
        return head;
    }
    else
    {
        if (head == NULL)   return NULL;    //if list was empty
        if (head->data == key)
        {
            head->next->prev = NULL;
            return head->next;
        }
        Node* cur = head;
        while (cur->next != NULL && cur->data != key) cur = cur->next;          //keep going till end
        if (cur->next == NULL && cur->data != key)  cout<<"Value not present. ";
        else
        {
            if (cur->next != NULL)  cur->next->prev = cur->prev;
            cur->prev->next = cur->next;
            return head;
        }
    }
}

void display(Node* head)
{
    Node* cur = head;
    while (cur != NULL)
    {
        cout<<cur->data<<" ";
        cur = cur->next;
    }
}

int main()
{
    Node* head;
    head = NULL;
    int op = -5;

    while (op != 7)
    {
        cout<<"Choose an option:\n1. Insert node to front.\n2. Insert node after an element.\n3. Insert node to end.\n4. Delete node from front.\n5. Delete node.\n6. Delete node from back.\n7. Exit.\nChoice: ";
        cin>>op;

        if (op == 1)
        {
            cout<<"Choose data value of node to insert to front: ";
            int value;
            cin>>value;
            head = insertKey(value, -1, head);
        }
        else if (op == 2)
        {
            cout<<"Choose data value of node to insert: ";
            int value;
            cin>>value;
            cout<<"Choose data value of node after which to insert: ";
            int key;
            cin>>key;
            head = insertKey(value, key, head);
        }
        else if (op == 3)
        {
            cout<<"Choose data value of node to insert to end: ";
            int value;
            cin>>value;
            head = insertKey(value, -2, head);
        }
        else if (op == 4)   head = deleteKey(-1, head);
        else if (op == 5)
        {
            cout<<"Choose data value of node to delete: ";
            int key;
            cin>>key;
            head = deleteKey(key, head);
        }
        else if (op == 6)   head = deleteKey(-2, head);
        else if (op == 7)   exit(1);
        cout<<endl<<"Current List: ";
        display(head);
        cout<<endl<<endl;
    }
}
