import java.util.Scanner;       // package for I/O

public class HelloWorld {
    private static class MyClass
    {
        public int id;
        public String name;
    }
    public static void main(String[] args)
    {
        MyClass myObj = new MyClass();
        Scanner input = new Scanner(System.in);
        System.out.println("What's your ID?");
        myObj.id = input.nextInt();
        myObj.name = "A";
        System.out.println("My name is " + myObj.name + ", ID " + myObj.id);
    }
}
