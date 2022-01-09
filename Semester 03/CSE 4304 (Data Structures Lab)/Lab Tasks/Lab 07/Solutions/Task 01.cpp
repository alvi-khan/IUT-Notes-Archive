#include<iostream>
using namespace std;
typedef struct node Node;

int flag = 0;

struct node             //structure of the node
{
	int value;
	Node* leftChild;
	Node* rightChild;
	Node* parent;
};

Node* createNode(int value)     //function to allocate memory to a new node
{
	Node* newNode = new Node();
	newNode->value = value;
	newNode->parent = NULL;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	return newNode;
}

Node* insertNode (Node* root, int value)        //inserting new nodes
{
	Node* cur = root;
	Node* newNode = createNode(value);
	if (cur == NULL)	return newNode;         //if we have no root, new node is root
	else
	{
		Node * parent;
		while (cur != NULL)                     //keep going left if smaller and right if bigger
		{                                       //when NULL is reached, we have an empty spot to put node in
			parent = cur;                       //store the parent of the spot where node will be inserted
			if (value > cur->value)	cur = cur->rightChild;
			else if (value <= cur->value)	cur = cur->leftChild;
		}


		newNode->parent = parent;               //set node's parent
		if (value > parent->value)              //set node to right or left child
			parent->rightChild = newNode;
		else if (value <= parent->value)
			parent->leftChild = newNode;
		return root;
	}
}

int searchTree (Node* x, int key)               //search tree to check for occupied spots
{
	int flag = 0;
	while (x != NULL)
	{
		if (x->value > key && (x->value - key) <= 3) break;         //if occupied, then x never reaches empty NULL spot
		else if (x->value < key && (key - x->value) <= 3)    break;
		else if (key > x->value)		x = x->rightChild;          //if key is outside occupied range then keep searching for smaller or higher accordingly
		else if (key < x->value)	x = x->leftChild;               //e.g. if key is too small, we might have smaller values that are within range, so we need to check smaller values only
	}
	if (x != NULL)  flag = 1;
	return flag;
}


void inorder (Node* x)
{
    if (x != NULL)
    {
        inorder(x->leftChild);      //print left child's tree
        cout<<x->value<<" ";        //print yourself
        inorder(x->rightChild);     //print right child's tree
    }
}

int main()
{
    Node* root = NULL;
    int input = 0;

    while (input != -1)
    {
        cin>>input;
        if (input == -1)    break;

        if (searchTree(root, input) == 1)           //searchTree returns 1 if occupied
        {
            inorder(root);
            cout<<"(Reservation failed)"<<endl;
        }
        else
        {
            root = insertNode(root, input);         //insert the node and print tree
            inorder(root);
            cout<<endl;
        }
    }
}
