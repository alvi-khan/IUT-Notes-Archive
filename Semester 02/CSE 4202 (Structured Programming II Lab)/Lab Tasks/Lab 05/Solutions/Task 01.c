#include<stdio.h>
#include<stdlib.h>

struct linkedlist                   //structure for list members
{
	int data;
	struct linkedlist *next;		//self-referencing pointer
};

typedef struct linkedlist *node;

node head = NULL;                   //assign initial head to NULL

node createNode()                   //create temporary node with next member pointing to NULL
{
	node temp;
	temp = (node) malloc(sizeof(struct linkedlist));
	temp->next = NULL;
	return temp;
}

void addNode(int value)
{
	node temp = createNode(), p;			//p is being used like an iterator
	temp->data = value;

	if (head == NULL)   head = temp;        //if first member, assign to head
	else                                    //else find last member, i.e. has next member as NULL, and assign there
	{
		p = head;
		while (p->next != NULL)	p = p->next;
		p->next = temp;
	}
}

int main()
{
    int option, value;
    node p;
    choice:
    printf("Choose an option:\n0. Exit.\n1. Add a node.\n2. Print list\nOption: ");
    scanf("%d", &option);

    if (option == 0)    exit(1);
    else if (option == 1)
    {
        printf("Enter a value: ");
        scanf("%d", &value);
        addNode(value);
        goto choice;
    }
    else
    {
         p = head;
         while (p->next != NULL)
         {
             printf("%d\n", p->data);
             p = p->next;
         }
         printf("%d", p->data);
    }
}
