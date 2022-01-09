import java.util.*;
public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        Student[] st = new Student[100];
        
        int choice=0;
        int y, d, p;
        int i;
        String id;
        
        while(choice != -1)
        {
            System.out.println("Enter 1 to add student");
            System.out.println("Enter 2 to verify student");
            System.out.println("Enter -1 to terminate program");
            
            choice = sc.nextInt();
            
            if(choice==1)
            {
                System.out.println("Enter student info");
                System.out.println("-------------------");
                
                System.out.print("Enter year of admission: ");
                y = sc.nextInt();                                                   //check whether the year is valid or not
                
                System.out.print("Enter Dept ID: ");                                // 1, 2, 3
                d = sc.nextInt();                                                   //check whether the dept id is within 1, 2 and 3 
                
                System.out.print("Enter Programme ID: ");                           // 1, 2, 3
                p = sc.nextInt();                                                   //check whether the prog id is within 1, 2 and 3
                
                i = Student.count;
                st[i] = new Student();
                
                if (st[i].set_year(y) && st[i].set_dept(d) && st[i].set_prog(p))    // edited this part so success message only displays if all input is correct
                {
                    st[i].create_ID();
                    System.out.println("Student record entered successfully!");
                }
                
            }
            else if(choice==2)
            {
                System.out.print("Enter student ID: ");
                sc.nextLine();                                                      // edited this part -> was taking enter key from previous input as input for check_ID function
                id = sc.nextLine();
                Student.check_ID(id);
            }
        }
        
        System.out.println("Total number of students in system: " + Student.count);
    }
}

