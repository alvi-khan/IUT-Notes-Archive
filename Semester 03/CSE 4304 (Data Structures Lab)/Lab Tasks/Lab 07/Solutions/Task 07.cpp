#include<iostream>
#include<queue>             //required for level order traversal
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

Node* findMinimum (Node* x)     //keep going left as far as possible
{
    while (x != NULL && x->leftChild != NULL)    x = x->leftChild;
    return x;
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

Node* deleteNode (Node* root, int value)    //deleting a node
{
    Node* x = searchTree(root, value);      //confirm node exists
    if (x != NULL)
    {
        if (x->leftChild != NULL && x->rightChild != NULL)      //both children present
        {
            Node* replacement = findMinimum(x->rightChild);     //replacement is successor
            if (replacement->parent != x)
            {
                replacement->parent->leftChild = replacement->rightChild;   //imagine changes
                replacement->rightChild = x->rightChild;
                x->rightChild->parent = replacement;
            }
            replacement->leftChild = x->leftChild;
            x->leftChild->parent = replacement;
            replacement->parent = x->parent;
            if (x->parent == NULL)  return replacement;     //if x was root, we have a new root
            else if (x->parent->leftChild == x) x->parent->leftChild = replacement;
            else    x->parent->rightChild = replacement;
        }
        else if (x->leftChild != NULL)
        {
            x->leftChild->parent = x->parent;               //since no other children, no complications
            if (x->parent == NULL)  return x->leftChild;    //if x was root, we have a new root
            else if (x->parent->leftChild == x) x->parent->leftChild = x->leftChild;
            else    x->parent->rightChild = x->leftChild;
        }
        else
        {
            if (x->rightChild != NULL)  x->rightChild->parent = x->parent; //rightChild may or may not exist
            if (x->parent == NULL)  return x->rightChild;   //if x was root, we have a new root; this may be NULL
            else if (x->parent->leftChild == x) x->parent->leftChild = x->rightChild;   //parent's new child may be NULL
            else x->parent->rightChild = x->rightChild;
        }
    }
    return root;        //return root if node does not exist or if root is not being deleted
}

void levelOrderTraversal (Node* x)
{
    queue <Node*> line;
    if (x != NULL)  line.push(x);
    while (!line.empty())
    {
        x = line.front();               //set x to front of line every time
        cout<<line.front()->value<<" "; //print out front of line
        if (x->leftChild != NULL)   line.push(x->leftChild);    //add children
        if (x->rightChild != NULL)  line.push(x->rightChild);
        line.pop();                     //'increment' queue
    }
    cout<<endl;
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

    levelOrderTraversal(root);

    int n;
    cin>>n;

    for (int j=0; j<n; j++)
    {
        int del;
        cin>>del;
        root = deleteNode(root, del);
        levelOrderTraversal(root);
    }
}
