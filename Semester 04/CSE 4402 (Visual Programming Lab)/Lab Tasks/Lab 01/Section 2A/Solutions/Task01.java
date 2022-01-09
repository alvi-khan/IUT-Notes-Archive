import java.util.Scanner;

public class Task01
{
    public static void main(String[] args) 
    {
        Scanner in = new Scanner(System.in);
        System.out.println("Input a string: ");
        String str = in.nextLine();
        str = str.toLowerCase();
        
        String reverse = "";
        int len = str.length();
        
        for(int i=len-1; i>=0; i--)
            reverse = reverse + str.charAt(i);
        
        if (str.equals(reverse))
            System.out.println("It is a palindrome.");
        else
            System.out.println("It is not a palindrome.");
    }
    
}
