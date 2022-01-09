#include<stdio.h>
#include<string.h>

char exp[1000];

int add (int a, int b)                          //function to add two numbers
{
    return a+b;
}

int mul (int a, int b)                          //function to multiple two numbers
{
    return a*b;
}

int SolveExpression (char exp[1000])            //function that evaluates input
{
    int len, i, fin=0, j=0, addnum[1000];
    len = strlen(exp);

    if (exp[1] == '+')
    {
        addnum[j] = exp[0] - '0';
        j++;
        fin++;
    }

    /*
        all numbers to be added are being added to an array called addnum.
        exp[i] - '0' converts char to corresponding int
        j++ increases current index of array of numbers of add.
        f++ counts end point of that array
    */

    for (i=1; i<len; i+=2)
    {
        //if current operation is addition and next operation is not multiplication, add the next integer
        if (exp[i] == '+' && exp[i+2] != 'x')
        {
            addnum[j] = exp[i+1] - '0';
            j++;
            fin++;
        }

        //if current operation is multiplication and previous operation was not multiplication, add the product of the integer immediately before and after
        else if (exp[i] == 'x' && exp[i-2] != 'x')
        {
            addnum[j] = mul(exp[i-1] - '0', exp[i+1] - '0');
            j++;
            fin++;
        }

        //if current and previous operation are both multiplication, add the product of the next integer and the result of the previous multiplication
        else if (exp[i] == 'x' && exp[i-2] == 'x')
        {
            j--;
            //j must be decreased to go back to the previous index and get the result of the previous multiplication
            addnum[j] = mul(exp[i+1] - '0', addnum[j]);
            j++;
        }
    }

    for (i=1; i<fin; i++)   addnum[0] = add(addnum[0], addnum[i]);
    //add all numbers in addnum and store result in addnum[0]

    return addnum[0];
}

int main ()
{
    scanf("%s", &exp);
    int a = SolveExpression (exp);
    printf("%d", a);

}
