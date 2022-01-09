import java.util.Scanner;

public class Task02
{
    public static void main(String[] args) 
    {
       Scanner in = new Scanner(System.in);
       System.out.println("Input a string: ");
       String str1 = in.nextLine(); 
       
       int len = str1.length();
       String str2 = "";
        
       for(int i=0; i<len; i=i+2)
       {
           str2 = str2 + str1.charAt(i) + "*";
           if(i+1 != len)
               str2 = str2 + str1.charAt(i+1);
       }
       System.out.println(str2);
    }
}
