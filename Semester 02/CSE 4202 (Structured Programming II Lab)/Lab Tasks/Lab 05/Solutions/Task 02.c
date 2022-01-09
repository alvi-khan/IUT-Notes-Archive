#include<stdio.h>
#include<stdlib.h>

struct linkedlist                   //structure for list members
{
	int data;
	struct linkedlist *next;		//self-referencing pointer
	struct linkedlist *prev;
};

typedef struct linkedlist *node;

node head = NULL;                   //create initial node head
node tail = NULL;                   //create initial node tail

node createNode()                   //create a node by allocating memory
{
	node temp;
	temp = (node) malloc(sizeof(struct linkedlist));
	return temp;
}

void addNodetail()
{
	node temp = createNode();

	int value;
	printf("Enter a value: ");
    scanf("%d", &value);

	temp->data = value;
    temp->next = NULL;                      //next member will become NULL
    temp->prev = tail;                      //current tail is new member's previous member
    tail = temp;                            //set tail to new member

	if (head == NULL)   head = temp;        //if first member, head is also temp
	else    tail->prev->next = temp;        //else head is unchanged. current tail's previous member's next member is temp
}

void addNodehead()
{
	node temp = createNode();

	int value;
	printf("Enter a value: ");
    scanf("%d", &value);

	temp->data = value;
	temp->next = head;                      //current head is new member's next member
	temp->prev = NULL;                      //previous member will become NULL
	head = temp;                            //set head to new member

	if (tail == NULL)   tail = temp;        //if first member, tail is also temp
	else	head->next->prev = temp;        //else tail is unchanged. current head's next member's previous member is temp
}

void printing()
{
    node p;
    printf("Printing Head to Tail:\n");
    p = head;
    while (p->next != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("%d\n", p->data);

    printf("Printing Tail to Head:\n");
    p = tail;
    while (p->prev != NULL)
    {
        printf("%d ", p->data);
        p = p->prev;
    }
    printf("%d\n", p->data);
}

int main()
{
    int option, value;
    node p;
    choice:
    printf("Choose an option:\n0. Exit.\n1. Add a node to tail.\n2. Add a node to head.\n3. Print list\nOption: ");
    scanf("%d", &option);

    if (option == 0)        exit(1);
    else if (option == 1)   addNodetail();
    else if (option == 2)   addNodehead();
    else if (option = 3)    printing();
    else                    printf("Invalid choice.");

    goto choice;
}
