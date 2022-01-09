import java.util.Scanner;

public class Solution
{
    static void anagramCheck(String str1, String str2)
    {
        str1 = str1.toLowerCase();  // convert to lower case to avoid case conflicts
        str2 = str2.toLowerCase();
        
        int len1 = str1.length();
        boolean arr[] = new boolean[26];    // corresponding indices will be set to true
        
        for (int i=0; i<len1; i++)   arr[str1.charAt(i) - 96] = true;
        
        int len2 = str2.length();
        boolean invalid = false;
        
        if (len2 != len1)   invalid = true; // if lengths do not match, cannot be anagrams
        else
        {
            for (int i=0; i<len2; i++)  // check if any of the corresponding indices were false
                if (arr[str2.charAt(i) - 96] != true)
                {
                    invalid = true;
                    break;
                }
        }
        
        if (invalid)    System.out.println("Given strings are NOT anagrams of each other.");
        else            System.out.println("Given strings are anagrams of each other.");
    }
    
    static void stringStar(String str1)
    {
        String str2 = "";   // output string
        for (int i=0; i<str1.length(); i++) // for each of the characters
        {
            str2 += str1.charAt(i); // add the character to output
            if ((i + 1) % 2 != 0)   str2 += '*';    // if in 'odd' position, add a star to output
        }
        System.out.println(str2);
    }
    
    public static void main(String[] args)
    {
        //====================== Task 1 =========================
        System.out.println("============== Task 1 ===============\n");
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the first string: ");
        String str1 = sc.nextLine();
        System.out.println("\nEnter the second string: ");
        String str2 = sc.nextLine();
        anagramCheck(str1, str2);
        
        //====================== Task 2 =========================
        System.out.println("\n============== Task 2 ===============\n");
        System.out.println("Enter the input string: ");
        str1 = sc.nextLine();
        stringStar(str1);
    }
    
}
