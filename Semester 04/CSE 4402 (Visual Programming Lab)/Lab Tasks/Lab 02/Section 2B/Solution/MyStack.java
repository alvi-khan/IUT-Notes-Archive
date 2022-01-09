public class MyStack
{
    char items[];	//private attribute
    int top;        //private attribute

    // Following is the constructor that initializes the attributes
    myStack(int size)
    {
        items = new char[size];
        top = -1;
    }
    
    public void push(char c)    // push items to stack
    {
        if (isFull())  // stack full error message
        {
            System.out.println("Stack is full. Item not added.");
            //System.exit(1);
        }
        else
        {
            top++;          // increment top
            items[top] = c; // add item to stack
        }
    }
    
    public char pop()   // pop items from stack
    {
        if(isEmpty())   // stack empty error message
        {
            System.out.println("Nothing left to pop");
            //System.exit(1);
        }
        else
        {
            top--;                  // decrement top
        }
        return items[top+1];    // return item
    }
    
    public Boolean isEmpty()    // returns true if stack is empty
    {
        return (top == -1);
    }
    
    public Boolean isFull()     // returns true if stack is full
    {
        return (top == items.length);
    }
}
