import java.io.*;
import java.util.Scanner;
import java.io.FileWriter;   
import java.io.IOException; 

public class Solution
{
    public static String decrypt_vigenere(String c, String k)
    {
        int l = k.length() - 1;
        String K = "";
        int ki = 0;
	for(int i = 0; i < c.length(); i++)
        {
            if(c.charAt(i) >= 65 && c.charAt(i) <= 90)
                K = K + k.charAt(ki%l);
            else
            {
                K = K + c.charAt(i);
                ki--;
            }
            
            ki++;
        }
        System.out.println(K);

        int t;
        String p = "";
        for(int i = 0; i < c.length(); i++)
        {
            if(c.charAt(i) >= 65 && c.charAt(i) <= 90)
            {
            int temp1 = c.charAt(i);
            int temp2 = K.charAt(i);
            if(temp2 > temp1)
                t = temp1+26 - temp2 + 65;
            else
                t = (temp1 - temp2) + 65; 
            char ch = (char)t;
            String st = Character.toString(ch);
            p += st;
            }
            else
                p += c.charAt(i);
        }
        
        return p;
    }

    
    public static void main(String[] args) 
    {
       try{
            File in1 = new File ("Files\\input.txt");		// you may have to change this part depending on your file location
            Scanner fileReader1 = new Scanner(in1);
            String ciphertext = "";
            
            while(fileReader1.hasNextLine()){
                ciphertext = ciphertext + fileReader1.nextLine() + "\n";
            }
            
            System.out.println("Ciphertext:\n" + ciphertext);
            
            fileReader1.close();
            
            File in2 = new File ("Files\\key.txt");	// you may need to change this part depending on your file location
            Scanner fileReader2 = new Scanner(in2);
            String key = "";
            
            while(fileReader2.hasNextLine()){
                key = key + fileReader2.nextLine() + "\n";
            }
            
            System.out.println("Key:\n" + key);
            
            String plaintext = decrypt_vigenere(ciphertext, key);    //Implement the decrypt function yourself
            System.out.println("Decrypted plaintext:\n"+plaintext);
            
            try 
            {
                FileWriter myWriter = new FileWriter("Files\\output.txt");
                myWriter.write(plaintext);
                myWriter.close();
                System.out.println("Successfully wrote to the file.");
            } 
            catch (IOException e) 
            {
                System.out.println("An error occurred.");
                e.printStackTrace();
            }
            
        }
        catch(FileNotFoundException e)
        {
            System.out.println("An error occurred while processing file");
            e.printStackTrace();
        }
    }  

}
    

