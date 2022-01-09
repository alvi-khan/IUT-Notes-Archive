import java.io.*;
import java.util.Scanner;
import java.io.FileWriter;

public class Solution
{
    public static String decrypt_vigenere(String c, String k)
    {
	String result = "";
        
        int j = 0;
        for (int i=0; i<c.length(); i++)
        {
            if (c.charAt(i) > 'Z' || c.charAt(i) < 'A') result += c.charAt(i);  // if not capital letter, take as is
            else
            {
                int temp = c.charAt(i) - k.charAt(j);   // remove cypher
                if (temp < 0)   temp += 26;             // if out of bounds, bring back in
                result += (char)(temp + 65);            // add corresponding character to result
                j = (j+1)%(k.length()-1);               // increment key
            }
        }
        return result;
    }

    public static void main(String[] args)
    {
        try{
            File in1 = new File ("Files\\input.txt"); // relative path inside Files folder of project
            Scanner fileReader1 = new Scanner(in1);
            String ciphertext = "";
            
            while(fileReader1.hasNextLine())
            {
                ciphertext = ciphertext + fileReader1.nextLine() + "\n";
            }
            
            System.out.println("Ciphertext:\n" + ciphertext);
            
            fileReader1.close();
            
            File in2 = new File ("Files\\key.txt");   // relative path inside Files folder of project
            Scanner fileReader2 = new Scanner(in2);
            String key = "";
            
            while(fileReader2.hasNextLine())
            {
                key = key + fileReader2.nextLine() + "\n";
            }
            
            System.out.println("Key:\n" + key);
            
            String plaintext = decrypt_vigenere(ciphertext, key);    // decrypting text
            System.out.println("Decrypted plaintext:\n"+plaintext);
            
            // Logic for writing the plaintext into another file named output.txt
            // Reference: https://stackabuse.com/java-save-write-string-into-a-file/
            try
            {
                File out1 = new File("Files\\output.txt");
                FileWriter writer = new FileWriter(out1);
                writer.write(plaintext);
                writer.close();
            }
            catch (IOException e)
            {
                System.out.println("An error occured while writing output to file.");
            }
        }
        catch(FileNotFoundException e)
        {
            System.out.println("An error occurred while processing file");
            e.printStackTrace();
        }
    }  
}
