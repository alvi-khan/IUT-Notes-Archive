#include<iostream>
#include<queue>
using namespace std;
typedef struct node Node;

struct node                     //node structure
{
	int value;
	Node* leftChild;
	Node* rightChild;
	Node* parent;
};

Node* createNode(int value)     //node memory allocation
{
	Node* newNode = new Node();
	newNode->value = value;
	newNode->parent = NULL;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	return newNode;
}

Node* insertNode (Node* root, int value)        //node insertion
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

void levelOrder (Node* x)               //printing level by level
{
    queue <Node*> line;
    line.push(x);                       //store root
    while (!line.empty())
    {
        cout<<x->value<<" ";            //print a node and store both its children in queue
        line.pop();                     //hint! visualize the queue
        if (x->leftChild != NULL)   line.push(x->leftChild);
        if (x->rightChild != NULL)  line.push(x->rightChild);
        x = line.front();
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
        root = insertNode(root, input);
    }
    levelOrder(root);
}
