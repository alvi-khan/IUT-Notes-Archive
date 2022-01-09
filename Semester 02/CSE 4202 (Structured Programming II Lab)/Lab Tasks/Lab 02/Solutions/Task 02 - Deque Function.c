#include<stdio.h>

int dq_array[5];
int choice = 0, dq_top = 0, dq_bottom = 1; dq_reved = 0, dq_dir;

void push()
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

void pop()
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

void display()
{
    int i;
    if (((dq_reved == 0) && (dq_bottom - dq_top == 1)) || (dq_bottom == 0 && dq_top == 4))  printf("Deque array is empty.");
    else if (dq_reved == 0) for (i=dq_top+1; i<dq_bottom; i++)  printf("%d", dq_array[i]);
    else
    {
        for (i=dq_top+1; i<5; i++)  printf("%d ", dq_array[i]);
        for (i=0; i<dq_bottom; i++) printf("%d ", dq_array[i]);
    }
    printf("\n");
}

int main()
{
    while (choice != 4)
    {
        printf("Choose an option:\n1. Push\n2. Pop\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1)    push();
        else if (choice == 2)   pop();
        else if (choice == 3)   display();
    }
}
