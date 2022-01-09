import java.time.Year;

public class Student
{
    static int count = 0;                                                       // keeps track of total number of students
    static boolean[][][][] deptwise_students = new boolean[2100][5][5][1000];    // keeps track of number of students in each programme, department and year
    
    int year;
    int dept;
    int prog;
    String id;
    
    boolean set_year(int y)
    {
        if (y>=1 && y <= Year.now().getValue())                                 // if within time period (1 - current year)
        {
            year = y;
            return true;
        }
        else
        {
            System.out.println("Invalid year entered. Try again.");
            return false;
        }
    }
    
    boolean set_dept(int d)
    {
        if (d>=1 && d<=3)
        {
            dept = d;
            return true;
        }
        else
        {
            System.out.println("Invalid deptartment ID entered. Try again.");
            return false;
        }
    }
    
    boolean set_prog(int p)
    {
        if (p>=1 && p<=3)
        {
            prog = p;
            return true;
        }
        else
        {
            System.out.println("Invalid programme ID entered. Try again.");
            return false;
        }
    }
    
    void create_ID()
    {
        count++;
        String y = String.format("%02d", year%100);                             // get last two digits of year and ensure 2 digits are printed
        String d = Integer.toString(dept);
        String p = Integer.toString(prog);
        String newID = String.format("%03d", count);
        deptwise_students[year][dept][prog][count] = true;                      // set student for this dept, prog, year and id to true (exists)
        id = y + d + p + newID;
        System.out.println("Student ID: " + id);
    }
    
    static void check_ID(String s)
    {
        if (s.length() == 7)
        {
            int y = Integer.parseInt(s.substring(0, 2));                        // get corresponding digits so 4D array can be checked
            int d = Integer.parseInt(s.substring(2, 3));
            int p = Integer.parseInt(s.substring(3, 4));
            int stdID = Integer.parseInt(s.substring(4, 7));
            
            if (y <= Year.now().getValue()%100) y += 2000;                      // the first two digits indicate this century
            else if (y <= 100)                  y += 1900;                      // the first two diits indicate last century
            
            if (y<1 || y>Year.now().getValue() || d<1 || d>3 || p<1 || p>3)     // will cause out of bounds error
            {
                System.out.println("Invalid student ID.");
                return;
            }
            
            if (deptwise_students[y][d][p][stdID])  System.out.println("Student exists in database.");
            else                                    System.out.println("Student does not exist in database.");
        }
        else                                        System.out.println("Invalid student ID.");
    }
    
}
