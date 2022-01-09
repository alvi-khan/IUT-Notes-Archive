#include<iostream>
using namespace std;
typedef struct node Node;   //making life easier

struct node                 //structure for each node
{
    int value;
    Node* leftChild;
    Node* rightChild;
    Node* parent;
};

Node* createNode (int value)    //allocates memory space to a node and sets default pointers
{
    Node* newNode = new Node();
    newNode->value = value;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->parent = NULL;
    return newNode;
}

Node* searchTree (Node* x, int value)       //locating a particular node
{
    if (x == NULL || x->value == value)  return x;  //return node with value or NULL if not found
    else if (value < x->value)  return searchTree(x->leftChild, value);
    else if (value > x->value)  return searchTree(x->rightChild, value);
}

Node* insertNode (Node* root, int value)    //inserting new node
{
    Node* x = root;                         //will need actual root later, so making a copy to traverse
    Node* newNode = createNode(value);      //creating the new node
    if (x == NULL)  return newNode;         //if no root exists, the node just created must be the root
    else
    {
        Node* parent = NULL;
        while (x != NULL)                   //keep going down, keeping track of the current parent
        {
            parent = x;
            x = (x->value < value) ? x->rightChild : x->leftChild;
        }
        newNode->parent = parent;           //make parent's child as needed
        if (value > parent->value)  parent->rightChild = newNode;
        else                        parent->leftChild = newNode;
        return root;
    }
}

void inOrderTraversal (Node* x)
{
    if (x != NULL)
    {
        inOrderTraversal(x->leftChild);
        cout<<x->value<<" ";
        inOrderTraversal(x->rightChild);
    }
}

int maxBetween(Node* root, int x, int y)    //maximum value between two nodes
{
    int maximum = x;
    Node* a = searchTree(root, x);  //finding first node
    if (a == NULL)  return -1;      //if node does not exist
    while (a->parent != NULL && a->parent->value <= y)  //keep going up until pivot reached
    {
        a = a->parent;
        if (maximum < a->value) maximum = a->value; //new maximum values
    }
    while (a->value != y)   //keep going down until node two reached
    {
        if (y>a->value) a = a->rightChild;
        else            a = a->leftChild;
        if (a->value > maximum) maximum = a->value;
    }
    return maximum;

}

int main()
{
    Node* root;
    root = NULL;
    int i = 0;
    while (i != -1)
    {
        cin>>i;
        if (i == -1)    break;
        root = insertNode(root, i);
    }
    int n, x, y;
    cin>>n;
    for (int j=0; j<n; j++)
    {
        cin>>x>>y;
        cout<<maxBetween(root, x, y)<<endl;
    }
}
