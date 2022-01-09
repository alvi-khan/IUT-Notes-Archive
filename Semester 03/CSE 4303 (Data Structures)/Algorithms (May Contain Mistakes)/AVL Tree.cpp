#include<iostream>
#include<queue>
using namespace std;
typedef struct node Node;

struct node
{
    int value;
    int height;
    Node* leftChild;
    Node* rightChild;
    Node* parent;
};

int getMax (int a, int b)
{
    return (a > b) ? a : b;
}

int getHeight(Node* a)
{
    if (a == NULL)  return -1;
    else            return a->height;
}

Node* leftRotate(Node* x)
{
    x->rightChild->parent = x->parent;
    if (x->parent != NULL)
    {
        if (x->parent->leftChild == x)  x->parent->leftChild = x->rightChild;
        else                            x->parent->rightChild = x->rightChild;
    }
    x->parent = x->rightChild;
    x->rightChild = x->parent->leftChild;
    x->parent->leftChild = x;
    if (x->rightChild != NULL)  x->rightChild->parent = x;
    x->height = getMax(getHeight(x->leftChild), getHeight(x->rightChild)) + 1;
    x->parent->height = getMax(getHeight(x->parent->leftChild), getHeight(x->parent->rightChild)) + 1;
    return x->parent;
}

Node* rightRotate (Node* x)
{
    x->leftChild->parent = x->parent;
    if (x->parent != NULL)
    {
        if (x->parent->leftChild == x)   x->parent->leftChild = x->leftChild;
        else                            x->parent->rightChild = x->leftChild;
    }
    x->parent = x->leftChild;
    x->leftChild = x->parent->rightChild;
    x->parent->rightChild = x;
    if (x->leftChild != NULL)  x->leftChild->parent = x;
    x->height = getMax(getHeight(x->leftChild), getHeight(x->rightChild)) + 1;
    x->parent->height = getMax(getHeight(x->parent->leftChild), getHeight(x->parent->rightChild)) + 1;
    return x->parent;
}

int checkBalance(Node* parent)
{
    return getHeight(parent->leftChild) - getHeight(parent->rightChild);
}

Node* balanceNode (Node* x, int balance)
{
    if (balance > 1 && checkBalance(x->leftChild) > 0)  x = rightRotate(x);
    else if (balance < -1 && checkBalance(x->rightChild) < 0)  x = leftRotate(x);
    else if (balance > 1 && checkBalance(x->leftChild) < 0)
    {
        x->leftChild = leftRotate(x->leftChild);
        rightRotate(x);
    }
    else if (balance < -1 && checkBalance(x->rightChild) > 0)
    {
        rightRotate(x->rightChild);
        leftRotate(x);
    }
}

Node* createNode (int value)
{
    Node* newNode = new Node();
    newNode->value = value;
    newNode->height = 0;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->parent = NULL;
}

Node* searchTree (Node* x, int key)
{
    if (x == NULL || key == x->value)   return x;
    else if (key < x->value)    return searchTree(x->leftChild, key);
    else                        return searchTree(x->rightChild, key);
}

Node* findMinimum (Node* x)
{
    while (x->leftChild != NULL)    x = x->leftChild;
    return x;
}

Node* findSuccessor (Node* a, int key)
{
    Node* x = searchTree(a, key);
    if (x->rightChild != NULL)  return findMinimum(x->rightChild);
    else
    {
        Node* parent = x->parent;
        while (parent != NULL && x->value > parent->value)  parent = parent->parent;
        return parent;
    }
}

Node* insertNode(Node* root, int value)
{
    Node* cur = root;
    Node* newNode = createNode(value);
    if (cur == NULL)    return newNode;
    else
    {
        Node* parent = NULL;
        while (cur != NULL)
        {
            parent = cur;
            if (value > cur->value) cur = cur->rightChild;
            else                    cur = cur->leftChild;
        }

        newNode->parent = parent;

        if (value > parent->value)  parent->rightChild = newNode;
        else                        parent->leftChild = newNode;

        while (parent != NULL)
        {
            int newHeight = getMax(getHeight(parent->leftChild), getHeight(parent->rightChild)) + 1;
            if (newHeight > getHeight(parent))
            {
                parent->height = newHeight;
                parent = parent->parent;
            }
            else    break;
        }

        parent = newNode->parent;

        while (parent != NULL)
        {
            int balance = checkBalance(parent);
            if (balance > 1 || balance < -1)
            {
                if (parent == root) root = balanceNode(parent, balance);
                else parent = balanceNode(parent, balance);
                break;
            }
            parent = parent->parent;
        }
        return root;
    }
}

Node* deleteNode (Node* root, int key)
{
    Node* x = searchTree(root, key);
    if (x != NULL)
    {
        Node* parent = x->parent;
        Node* beginChanges = x->parent;

        if (x->leftChild != NULL && x->rightChild != NULL)
        {
            Node* replacement = findMinimum(x->rightChild);
            beginChanges = replacement;
            if (replacement->parent != x)
            {
                beginChanges = replacement->parent;
                replacement->parent->leftChild = replacement->rightChild;
                replacement->rightChild = x->rightChild;
            }
            replacement->parent = x->parent;
            replacement->leftChild = x->leftChild;
            if (x->parent == NULL)  root = replacement;
            else if (x->parent->leftChild == x) x->parent->leftChild = replacement;
            else                                x->parent->rightChild = replacement;
        }
        else if (x->leftChild != NULL)
        {
            x->leftChild->parent = x->parent;
            if (x->parent == NULL)  root = x->leftChild;
            else if (x->parent->leftChild == x) x->parent->leftChild = x->leftChild;
            else                                x->parent->rightChild = x->leftChild;
        }
        else
        {
            if (x->rightChild != NULL)  x->rightChild->parent = x->parent;
            if (x->parent == NULL)  root = x->rightChild;
            else if (x->parent->leftChild == x) x->parent->leftChild = x->rightChild;
            else                                x->parent->rightChild = x->rightChild;
        }

        Node* temp = beginChanges;

        while (beginChanges != NULL)
        {
            int newHeight = getMax(getHeight(beginChanges->leftChild), getHeight(beginChanges->rightChild)) + 1;
            if (newHeight != getHeight(beginChanges))   beginChanges->height = newHeight;
            beginChanges = beginChanges->parent;
        }

        beginChanges = temp;

        while (beginChanges != NULL)
        {
            int balance = checkBalance(beginChanges);
            if (balance > 1 || balance < -1)
            {
                if (beginChanges == root) root = balanceNode(beginChanges, balance);
                else beginChanges = balanceNode(beginChanges, balance);
            }
            beginChanges = beginChanges->parent;
        }
    }
    return root;
}



void inOrder (Node* x)
{
    if (x != NULL)
    {
        inOrder(x->leftChild);
        cout<<x->value<<" ";
        inOrder(x->rightChild);
    }
}

void levelOrder(Node* x)
{
    queue <Node*> a;
    a.push(x);
    while (!a.empty())
    {
        cout<<a.front()->value<<" ";
        if (a.front()->leftChild != NULL)   a.push(a.front()->leftChild);
        if (a.front()->rightChild != NULL)  a.push(a.front()->rightChild);
        a.pop();
    }
    cout<<endl;
}

int main()
{
    Node* root = NULL;
    root = insertNode(root, 100);
    levelOrder(root);
    root = insertNode(root, 150);
    levelOrder(root);
    root = insertNode(root, 200);
    levelOrder(root);
    root = insertNode(root, 250);
    levelOrder(root);
    root = insertNode(root, 225);
    levelOrder(root);
    root = insertNode(root, 210);
    levelOrder(root);
    root = insertNode(root, 110);
    levelOrder(root);
    root = deleteNode(root, 150);
    levelOrder(root);
    root = insertNode(root, 220);
    levelOrder(root);
    root = insertNode(root, 205);
    levelOrder(root);
    root = insertNode(root, 115);
    levelOrder(root);
    root = deleteNode(root, 110);
    levelOrder(root);
    root = deleteNode(root, 100);
    levelOrder(root);
}
