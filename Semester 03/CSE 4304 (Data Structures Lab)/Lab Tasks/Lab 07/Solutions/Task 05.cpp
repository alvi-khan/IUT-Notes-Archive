#include<iostream>
using namespace std;
typedef struct node Node;

struct node                 //node structure NEW STUFF
{
	int value;
	int subTreeSize;        //keeps track of number of children
	Node* leftChild;
	Node* rightChild;
	Node* parent;
};

Node* createNode(int value)     //allocating memory to node NEW STUFF
{
	Node* newNode = new Node();
	newNode->value = value;
	newNode->subTreeSize = 0;   //new nodes are always leafs, so subTreeSize is 0
	newNode->parent = NULL;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	return newNode;
}

Node* insertNode (Node* root, int value)        //node insertion NEW STUFF
{
	Node* cur = root;
	Node* newNode = createNode(value);
	if (cur == NULL)	return newNode;
	else
	{
		Node * parent;
		while (cur != NULL)
		{
			parent = cur;
			cur->subTreeSize++; //each parent of new node is getting an increased subTreeSize
			if (value > cur->value)	cur = cur->rightChild;
			else if (value <= cur->value)	cur = cur->leftChild;
		}


		newNode->parent = parent;
		if (value > parent->value)
			parent->rightChild = newNode;
		else if (value <= parent->value)
			parent->leftChild = newNode;
		return root;
	}
}

int findSmallers(Node* x, int key)
{
    int smallers = 0;                   //keeps track of smaller nodes
    while (x != NULL && x->value != key)    //finding the node
    {
        if (x->value < key)             //if value is smaller, add size of left subtree and itself
        {
            if (x->leftChild != NULL)    smallers += x->leftChild->subTreeSize + 1;
            smallers += 1;
            x = x->rightChild;
        }
        else    x = x->leftChild;   //if value is larger, do nothing
    }

    if (x == NULL)  return -1;      //if key not found
    else
    {
        if (x->leftChild != NULL)    smallers += x->leftChild->subTreeSize + 1; //add left subtree size
        return smallers;
    }
}

int main()
{
    Node* root = NULL;
    int input = 0;

    while (input != -1)     //adding nodes
    {
        cin>>input;
        if (input == -1)    break;
        root = insertNode(root, input);
    }

    int n;
    cin>>n;

    for (int i=0; i<n; i++) //queries
    {
        int query;
        cin>>query;

        cout<<findSmallers(root, query)<<endl;
    }
}
