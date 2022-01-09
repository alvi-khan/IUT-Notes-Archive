import java.util.Scanner;

public class Main
{
    public static Boolean isOperator (char c)      // checks if character is an operator
    {
        return (!Character.isDigit(c) && !Character.isLetter(c));
    }
    
    public static int getPriority (char c)         // returns priority of operator
    {
        if (c == '-' || c == '+')       return 1; 
        else if (c == '*' || c == '/')  return 2; 
        else if (c == '^')              return 3;
        else                            return 0;
    }
    
    
    
    public static String infixToPostfix (String infix)  // converts infix string to postfix
    {
        infix = '(' + infix + ')';
        int size = 100;
        myStack st = new MyStack(size);                 // custom stack class
        String postfix = ""; 
  
        for (int i=0; i<infix.length(); i++)
        {
            char c = infix.charAt(i);
            if (!isOperator(c))     postfix += c;
            else if (c == '(')      st.push('(');
            else if (c == ')')
            {
                char top = st.pop();
                st.push(top);
                
                while (top != '(')
                {
                    postfix += top;
                    st.pop();
                    top = st.pop();
                    st.push(top);
                }
                st.pop();
            }
            else
            { 
                char top = st.pop();
                st.push(top);
                if(isOperator(top))
                { 
                    while (getPriority(c) <= getPriority(top))
                    { 
                        postfix += top;
                        st.pop();
                        top = st.pop(); 
                        st.push(top);
                    }
                    st.push(c); 
                }
            }
        }
        return postfix; 
    }
    
    public static String infixToPrefix (String infix)   // converts infix to prefix
    {
        String infixReversed = new StringBuilder(infix).reverse().toString();
        
        String corrected = "";
        for (int i=0; i<infixReversed.length(); i++)
        {
            char c = infixReversed.charAt(i);
            
            if (c == '(')       corrected += ')';
            else if (c == ')')  corrected += '(';
            else                corrected += c;
        }
        
        String postfix = infixToPostfix(corrected);
        String prefix = new StringBuilder(postfix).reverse().toString();
        return prefix;
    }
    
    public static void main(String[] args)
    {  
        Scanner input = new Scanner(System.in);
        
        String infix = input.nextLine();
        
        String prefix = infixToPrefix(infix);
        System.out.println(prefix);
    }
    // Reference: https://www.geeksforgeeks.org/convert-infix-prefix-notation/
}
