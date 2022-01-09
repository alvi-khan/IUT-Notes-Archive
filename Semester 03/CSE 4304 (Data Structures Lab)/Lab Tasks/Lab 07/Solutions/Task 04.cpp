#include<iostream>
#include<queue>
using namespace std;
typedef struct node Node;

struct node                 //node structure
{
	int value;
	Node* leftChild;
	Node* rightChild;
	Node* parent;
};

Node* createNode(int value)     //allocating memory to node
{
	Node* newNode = new Node();
	newNode->value = value;
	newNode->parent = NULL;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	return newNode;
}

Node* insertNode (Node* root, int value)    //inserting a node
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

Node* searchTree (Node* x, int key)                 //locating a particular node
{
	while (x != NULL && x->value != key)
	{
		if (key > x->value)		x = x->rightChild;
		else if (key < x->value)	x = x->leftChild;
	}
	return x;
}

Node* findMinimum (Node* x)                         //smallest descendant of a node
{
	while (x->leftChild != NULL)	x = x->leftChild;
	return x;
}

Node* findMaximum (Node* x)                         //largest descendant of a node
{
	while (x->rightChild != NULL)	x = x->rightChild;
	return x;
}

Node* findSuccessor (Node* x, int key)              //successor is smallest from the higher values
{                                                   //or next smallest value parent
	if (x->rightChild != NULL)	return findMinimum(x->rightChild);
	else
	{
		Node* parent = x->parent;
		while (parent != NULL && x->value > parent->value)
			parent = parent->parent;
		return parent;
	}
}

Node* findPredecessor (Node* x, int key)            //predecessor is largest from the lower values
{                                                   //of previous largest value parent
	if (x->leftChild != NULL)	return findMaximum(x->leftChild);
	else
	{
		Node* parent = x->parent;
		while (parent != NULL && x->value < parent->value)
			parent = parent->parent;
		return parent;
	}
}


int main()
{
    Node* root = NULL;
    int input = 0;

    while (input != -1)                     //inserting nodes
    {
        cin>>input;
        if (input == -1)    break;
        root = insertNode(root, input);
    }

    int n;
    cin>>n;

    for (int i=0; i<n; i++)
    {
        int query;
        cin>>query;

        Node* queryNode = searchTree(root, query);      //searching for value

        if (queryNode == NULL)  cout<<"Reservation not found!"<<endl;   //value not in tree
        else
        {
            Node* temp = findPredecessor(queryNode, query);
            if (temp == NULL)   cout<<"NULL ";              //smallest value in tree
            else                cout<<temp->value<<" ";
            temp = findSuccessor(queryNode, query);
            if (temp == NULL)   cout<<"NULL"<<endl;         //largest value in tree
            else                cout<<temp->value<<endl;
        }
    }
}
