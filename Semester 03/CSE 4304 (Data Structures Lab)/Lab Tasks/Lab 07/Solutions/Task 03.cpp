#include<iostream>
#include<queue>
using namespace std;
typedef struct node Node;

int maxKills;               //stores the lowest level possible

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

Node* insertNode (Node* root, int value)        //inserting node !! NEW STUFF !!
{
	Node* cur = root;
	Node* newNode = createNode(value);
	if (cur == NULL)	return newNode;
	else
	{
		int curKill = 0;                        //for every node, we store the lowest level it goes to
		Node * parent;
		while (cur != NULL)
		{
			parent = cur;
			if (value > cur->value)         cur = cur->rightChild;
			else if (value <= cur->value)	cur = cur->leftChild;
			curKill++;
		}

        if (curKill > maxKills) maxKills = curKill;     //if lowest level for this new node is lower than the previous maximum

		newNode->parent = parent;
		if (value > parent->value)
			parent->rightChild = newNode;
		else if (value <= parent->value)
			parent->leftChild = newNode;
		return root;
	}
}

int main()
{
    Node* root = NULL;
    int input = 0;
    maxKills = 0;

    while (input != -1)
    {
        cin>>input;
        if (input == -1)    break;
        root = insertNode(root, input);
    }
    cout<<maxKills;
}
