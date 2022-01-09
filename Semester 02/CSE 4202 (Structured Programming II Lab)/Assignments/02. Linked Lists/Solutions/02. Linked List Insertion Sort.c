#include<stdio.h>
#include<stdlib.h>

struct linkedlist                   //structure for list members
{
	int data;
	struct linkedlist *next;		//self-referencing pointer
	struct linkedlist *prev;
};

typedef struct linkedlist *node;

node head = NULL;                   //assign initial head to NULL

node createNode()                   //create temporary node with next member pointing to NULL
{
	node temp;
	temp = (node) malloc(sizeof(struct linkedlist));
	return temp;
}

void addNode(int value)
{
	node temp = createNode(), i = head;		//i is being used like an iterator
	temp->data = value;
	temp->next = NULL;                      //next value of new member is null since one directional

	if (head == NULL)                       //if first member, assign to head
    {
        temp->prev  = NULL;                 //previous value will be null
        head = temp;
    }
	else                                    //else find last member, i.e. has next member as NULL, and assign there
	{
		while (i->next != NULL)	i = i->next;
		temp->prev = i;                     //previous value of new member will be previous end member
		i->next = temp;
	}
}

void sortNode()
{
    node i = head->next, j;                 //i and j used as iterators, i = 1
    int key;                                //key to store value

    while (i != NULL)                       //until end of list is reached
    {
        key = i->data;
        j = i->prev;                        //j = i-1

        while (j->prev != NULL && j->data > key)    //while j is not first member and has value greater than key
        {
            j->next->data = j->data;                //j+1 data = j data
            j = j->prev;                            //j--
        }

        if (j->data > key)  j->next->data = j->data;    //if first member is also greater than key, j+1 data = j data
        else                j = j->next;                //else j++ to go to second member

        j->data = key;                                  //set current j value to key
        i = i->next;
    }
}

void printNode()                                    //print from head to end
{
    node i = head;
    while (i->next != NULL)
    {
        printf("%d ", i->data);
        i = i->next;
    }
    printf("%d\n", i->data);
}

int main()
{
    int i, value;
    printf("Please enter 5 values: ");
    for (i=0; i<5; i++)
    {
        scanf("%d", &value);
        addNode(value);
    }
    printf("Before sorting: ");
    printNode();
    sortNode();
    printf("After sorting: ");
    printNode();
}
