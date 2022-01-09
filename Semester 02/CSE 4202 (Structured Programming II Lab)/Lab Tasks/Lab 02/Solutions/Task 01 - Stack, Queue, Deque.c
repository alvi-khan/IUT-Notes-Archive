#include<stdio.h>\

int stack_array[5], q_array[5], dq_array[5], type = 0, command, s_top = 0, q_top = 0, q_bottom = 0, q_reved = 0, dq_top = 0, dq_bottom = 0, dq_dir = 0, dq_reved = 0;

void push()
{
    if (type == 1)
    {
        if (s_top == 5)    printf("Error. Stack array is full.\n");     //for a stack, if the stack is full, the top will be 5
        else
        {
            printf("Enter element to push: ");
            scanf("%d", &stack_array[s_top]);                           //if not full, element added to current top
            s_top++;
        }
    }
    else if (type == 2)
    {
        if ((q_bottom == q_top) && (q_reved != 0)) printf("Error. Queue array is full.\n");
        //q_reved refers to the q_bottom being before q_top as would happen if an element is popped from the front and then another element added to the 'bottom'. Whenever the queue is full, q_bottom and q_top are equal and q_bottom is 'before' q_top.
        else
        {
            printf ("Enter element to push: ");
            scanf("%d", &q_array[q_bottom]);            //add to q_bottomth index
            q_bottom++;
            if (q_bottom == 5)                          //if q_bottom reaches end, set it to beginning
            {
                q_bottom = 0;
                q_reved = 1;
            }
        }
    }
    else if (type == 3)
    {
        if ((dq_reved == 1) && (dq_top < dq_bottom))    printf("Error. Deque array is full.\n");
        else
        {
            printf("Choose direction:\n1. Top\n2. Bottom\nDirection: ");
            scanf("%d", &dq_dir);
            printf("Enter element to push: ");

            if (dq_dir == 1)
            {
                scanf("%d", &dq_array[dq_top]);
                dq_top--;
                if (dq_top == -1)
                {
                    dq_top = 4;
                    dq_reved = 1;
                }
            }
            else if (dq_dir == 2)
            {
                scanf("%d", &dq_array[dq_bottom]);
                dq_bottom++;
                if (dq_bottom == 5)
                {
                    dq_bottom = 0;
                    dq_reved = 1;
                }
            }
        }
    }
}

void pop()
{
    if (type == 1)
    {
        if (s_top == 0)     printf("Error. Stack array is empty.\n");       //if a stack is empty, the top will be 0
        else
        {
            printf("The element popped was: %d\n", stack_array[s_top-1]);   //if not full, top-1th index popped
            s_top--;
        }
    }
    else if (type == 2)
    {
        if ((q_top == q_bottom) && (q_reved == 0))  printf("Error. Queue array is empty.\n");
        //queue is empty when q_top and q_bottom are equal, the q_bottom is 'greater' than q_top
        else
        {
            printf("The element popped was: %d\n", q_array[q_top]); //pop q_topth element
            q_top++;
            if (q_top == 5)                                         //if q_top reaches end, set it to 0
            {
                q_top = 0;
                q_reved = 0;
            }
        }
    }
    else if (type == 3)
    {
        if (((dq_reved == 0) && (dq_bottom - dq_top == 1)) || (dq_bottom == 0 && dq_top == 4))  printf("Error. Deque array is empty.\n");

        else
        {
            printf("Choose direction:\n1. Top\n2. Bottom\nDirection: ");
            scanf("%d", &dq_dir);
            if (dq_dir == 1)
            {
                dq_top++;
                if (dq_top == 5)
                {
                    dq_top = 0;
                    dq_reved = 0;
                }
                printf("The element popped was: %d\n", dq_array[dq_top]);
            }
            else if (dq_dir == 2)
            {
                dq_bottom--;
                if (dq_bottom == -1)
                {
                    dq_bottom = 4;
                    dq_reved = 0;
                }
                printf("The element popped was: %d\n", dq_array[dq_bottom]);
            }
        }
    }
}

void display()
{
    int i;
    if (type == 1)
    {
        if (s_top == 0)    printf("The stack array is empty.");       //print the stack unless its empty
        else    for (i=0; i<s_top; i++) printf("%d ", stack_array[i]);
    }
    else if (type == 2)
    {
        if (q_reved == 0)                        //if q_top < q_bottom and equal then queue is empty as explained earlier
        {
            if (q_bottom == q_top)    printf("The queue array is empty.");
            else    for (i=q_top; i<q_bottom; i++)  printf("%d ", q_array[i]);
            //other than that print from q_top to q_bottom
        }
        else                                    //if q_bottom < q_top, print from q_top to end and then from start to q_bottom
        {
            for (i=q_top; i<5; i++)     printf("%d ", q_array[i]);
            for (i=0; i<q_bottom; i++)  printf("%d ", q_array[i]);
        }
    }
    else if (type == 3)
    {
        if (((dq_reved == 0) && (dq_bottom - dq_top == 1)) || (dq_bottom == 0 && dq_top == 4))  printf("Deque array is empty.");
        else if (dq_reved == 0) for (i=dq_top+1; i<dq_bottom; i++)  printf("%d", dq_array[i]);
        else
        {
            for (i=dq_top+1; i<5; i++)  printf("%d ", dq_array[i]);
            for (i=0; i<dq_bottom; i++) printf("%d ", dq_array[i]);
        }
    }
    printf("\n");
}

int main()
{
   while (type != 4)
   {
        printf("Choose the type of array to use:\n1. Stack\n2. Queue\n3. Deque\n4. Exit\nType: ");
        scanf("%d", &type);

        if (type == 1)  printf("Choose a command for the stack:\n1. Push an element.\n2. Pop an element.\n3. Display stack.\nCommand: ");
        if (type == 2)  printf("Choose a command for the queue:\n1. Push an element.\n2. Pop an element.\n3. Display queue.\nCommand: ");
        if (type == 3)  printf("Choose a command for the deque:\n1. Push an element.\n2. Pop an element.\n3. Display deque.\nCommand: ");
        else if (type == 4) exit(1);

        scanf("%d", &command);

        if (command == 1)       push();
        else if (command == 2)  pop();
        else if (command == 3)  display();
        printf("\n");
   }
}
