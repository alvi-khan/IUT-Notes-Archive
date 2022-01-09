import java.util.Scanner;

public class Main
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int size = 100;
        myStack st = new MyStack(size);
        
        String brackets = sc.nextLine();
        
        for(int i=0; i<brackets.length(); i++)
        {
            char c = '\0';
            if(brackets.charAt(i) == ')')
            {
                if(!st.isEmpty())
                    c = st.pop();
                
                if(c != '(')
                {
                    System.out.println("Not Balanced");
                    System.exit(0);
                }
            }
            
            else if(brackets.charAt(i) == '}')
            {
                if(!st.isEmpty())
                    c = st.pop();
                
                if(c != '{')
                {
                    System.out.println("Not Balanced");
                    System.exit(0);
                }
            }
            
            else if(brackets.charAt(i) == ']')
            {
                if(!st.isEmpty())
                    c = st.pop();
                
                if(c != '[')
                {
                    System.out.println("Not Balanced");
                    System.exit(0);
                }
            }
            
            else if(brackets.charAt(i) == '(' || brackets.charAt(i) == '{' || brackets.charAt(i) == '[')
                st.push(brackets.charAt(i));
        }
        
        System.out.println("Balanced");

    }
    
}
