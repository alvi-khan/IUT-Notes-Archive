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

void addNodehead()
{
	node temp = createNode();

	printf("Enter a value: ");
    scanf("%d", &temp->data);

	temp->next = head;                      //current head is new member's next member
	temp->prev = NULL;                      //previous member will become NULL
	head = temp;                            //set head to new member

	if (tail == NULL)   tail = temp;        //if first member, tail is also temp
	else	head->next->prev = temp;        //else tail is unchanged. current head's next member's previous member is temp
}

void addNodetail()
{
	node temp = createNode();

	printf("Enter a value: ");
    scanf("%d", &temp->data);

    temp->next = NULL;                      //next member will become NULL
    temp->prev = tail;                      //current tail is new member's previous member
    tail = temp;                            //set tail to new member

	if (head == NULL)   head = temp;        //if first member, head is also temp
	else    tail->prev->next = temp;        //else head is unchanged. current tail's previous member's next member is temp
}

void updateNode()
{
    node i = head;
    int value;

    if (i == NULL)                          //empty list error
    {
        printf("Error. List is empty.");
        return 0;
    }

    printf("Please enter value to update: ");
    scanf("%d", &value);
    while (i != NULL)
    {
        if (i->data == value)               //when element to be updated is found, update
        {
            printf("Please enter new value: ");
            scanf("%d", &i->data);
            return 0;                       //exit function if update is made
        }
        i = i->next;                        //go to next element if update not made
    }

    printf("Error. Value does not exist in list."); //end of list reached without update
}

void deleteNode()
{
    node i = head;
    int value;

    if (i == NULL)
    {
        printf("Error. List is empty.");    //empty list error
        return 0;
    }

    printf("Please enter value to delete: ");
    scanf("%d", &value);

    while (i != NULL)
    {
        if (i->data == value)               //when value found
        {
            if (i->next == NULL)        tail = i->prev;             //if last element, set new tail since next has no prev
            else                        i->next->prev = i->prev;    //else next element's prev has to be edited
            if (i->prev == NULL)        head = i->next;             //if first element, set new head since prev has no next
            else                        i->prev->next = i->next;    //else prev element's next has to be edited
            free(i);    //free memory
            return 0;   //exit function if deletion done
        }
        i = i->next;    //go to next element otherwise
    }

    printf("Error. Value does not exist in list."); //end of list reached without any deletion
}

void insertNodehead()
{
    node i = head;                                  //start iterator at head
    int mark;
    if (i == NULL)                                  //if first element, go to addNodehead
    {
        printf("List is empty. Adding first element.\n");
        addNodehead();
        return 0;
    }

    printf("Enter value before which to add new element: ");
    scanf("%d", &mark);

    while (i != NULL)
    {
        if (i->data == mark)                    //find element before which to add
        {
            node temp = createNode();           //create temp node
            if (i->prev != NULL)    i->prev->next = temp;   //unless mark was first value, edit mark's prev's next
            else                    head = temp;            //else set new head to temp
            temp->prev = i->prev;                           //temp's prev is mark's prev
            i->prev = temp;                                 //mark's prev is temp
            temp->next = i;                                 //temp's next is mark
            printf("Enter value of new element: ");
            scanf("%d", &temp->data);
            return 0;
        }
        i = i->next;                                //iterate i until mark is found
    }
    printf("Error. Value does not exist in list."); //if mark is not found
}

void insertNodetail()
{
    node i = tail;                                  //start iterator at tail
    int mark;
    if (i == NULL)                                  //if first element, go to addNodetail
    {
        printf("List is empty. Adding first element.\n");
        addNodetail();
        return 0;
    }

    printf("Enter value after which to add new element: ");
    scanf("%d", &mark);

    while (i != NULL)
    {
        if (i->data == mark)                        //find element after which to add
        {
            node temp = createNode();               //create temp node
            if (i->next != NULL)    i->next->prev = temp;   //unless mark was last value, edit mark's next's prev
            else                    tail = temp;            //else set new tail to temp
            temp->next = i->next;                           //temp's next is mark's next
            i->next = temp;                                 //mark's next is temp
            temp->prev = i;                                 //temp's prev is mark
            printf("Enter value of new element: ");
            scanf("%d", &temp->data);
            return 0;
        }
        i = i->prev;                                //iterate until mark is found
    }
    printf("Error. Value does not exist in list."); //if mark is not found
}

void printNodehead()
{
    node p = head;
    if (p == NULL)  printf("List is empty.");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void printNodetail()
{
    node p = tail;
    if (p == NULL)  printf("List is empty.");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->prev;
    }
}

int main()
{
    int option;

    choice:
    printf("Choose an option:\n\n0. Exit.\n1. Add element (front).\n2. Add element (back).\n3. Update an element.\n4. Delete an element.\n5. Insert an element before another element.\n6. Insert an element after another element.\n7. Print list from front.\n8. Print list from back.\n\nOption: ");
    scanf("%d", &option);
    printf("\n\n");

    if (option == 0)        exit(1);
    else if (option == 1)   addNodehead();
    else if (option == 2)   addNodetail();
    else if (option == 3)   updateNode();
    else if (option == 4)   deleteNode();
    else if (option == 5)   insertNodehead();
    else if (option == 6)   insertNodetail();
    else if (option == 7)   printNodehead();
    else if (option == 8)   printNodetail();
    else                    printf("Invalid choice.");

    printf("\n\n");

    goto choice;
}
