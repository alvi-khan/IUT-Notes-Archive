import java.util.Scanner;

public class Main
{
    public static void main(String[] args) 
    {
        Calendar c = new Calendar();
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Enter a date in the format DD/MM/YYYY: ");
        String d = sc.nextLine();
        c.setDate(d);
        
        if(c.isValidDate())
        {
            System.out.println("Leap year: " + c.isLeapYear());
            System.out.println("Day: " + c.dayOfWeek());  //Sunday/Monday/...
            System.out.println("Next date: " + c.nextDate());
            System.out.println("Previous date: " + c.previousDate());
        }
        else
        {
            System.out.println("Not a valid date.");
        }
    }
    
}
