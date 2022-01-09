public class MyStack 
{
    char items[];	
    int top;	

    myStack(int size)
    {
        items = new char[size];
        top = -1;
    }    
    
    public void push(char c)
    {
        top++;
        items[top] = c;
    }
    
    public char pop()
    {
        if(isEmpty()){
            System.out.println("Nothing left to pop");
            System.exit(1);
        }
      
        top--;
        return items[top+1];
    }
    
   public Boolean isEmpty()
   {
       if(top < 0)
           return true;
       else
           return false;
    }   

}
