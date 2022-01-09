#include<stdio.h>
#include<string.h>

char str[1000];

int add(int a, int b)                                   // function to add two numbers
{
    int c = a + b;
    return c;
}

int sub(int a, int b)                                   // function to subtract two numbers
{
    int c = a - b;
    return c;
}

int div(int a, int b)                                   // function to divide two numbers
{
    int c = a/b;
    return c;
}

int SolveExpression (char str[1000])                    // function that evaluates input
{
    int i, res = 0, len = strlen(str);
    for (i=0; i<len; i++)
    {
        /* Add number to res unless next operation is division, since the division must be done before adding*/
        if (str[i] == '+' && str[i+2] != '/')
        {
            int temp1 = str[i+1] - '0';                 // convert char to int
            res = add(res, temp1);
        }

        /* Subtract number from res unless next operation is division, since the division must be done before subtracting*/

        else if (str[i] == '-' && str[i+2] != '/')
        {
            int temp1 = str[i+1] - '0';
            res = sub(res, temp1);
        }

        /* If repeated divisions are found, the loop divides the numbers one by one from left to right*/

        else if (str[i] == '/' && str[i+2] == '/')
        {
            char temp = str[i-2];
            /*store the previous operator so we know if we have to add or subtract*/
            int temp1 = str[i-1] - '0';
            int temp2 = str[i+1] - '0';
            int c = div(temp1, temp2);
            /*perform first division and store result in c*/
            i+=2;

            while(str[i] == '/')            //keep dividing until division signs aren't a thing anymore
            {
                int temp2 = str[i+1] - '0';
                int c = div(c, temp2);
                i+=2;
            }
            if (temp == '-')    res = sub(res, c);
            else                res = add(res, c);
            i--;
            /* Go back one step cuz otherwise operation just after division is ignored*/
        }

        else if (str[i] == '/' && str[i-2] == '-')
        /* If subtraction sign was present immediately before division operation, subtract, else add*/
        {
            int temp1 = str[i-1] - '0';
            int temp2 = str[i+1] - '0';
            int c = div(temp1, temp2);
            res = sub(res, c);
        }

        else if (str[i] == '/')
        {
            int temp1 = str[i-1] - '0';
            int temp2 = str[i+1] - '0';
            int c = div(temp1, temp2);
            res = add(res, c);
        }
    }

    /* None of these conditions work if first operation is not divison, so add the first number to res in that case*/

    if (str[1] != '/')  res+= str[0] - '0';
    printf("%d\n", res);
}

int main()
{
    start:
    scanf("%s", &str);
    SolveExpression(str);
    goto start;
}

