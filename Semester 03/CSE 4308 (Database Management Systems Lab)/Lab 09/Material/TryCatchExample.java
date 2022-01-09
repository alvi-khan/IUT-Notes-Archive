public class TryCatchExample
{
    public static void main(String[] args)
    {
        int number, result;
        number = 40;
        try
        {
            result = number/0;
            System.out.println(result);
        }
        catch(ArithmeticException e )
        {
            System.out.println("Error in try block. Exception: " + e);
            result = number/10;
            System.out.println(result);
        }
        catch(Exception e)
        {
            System.out.println("Error in try block. Exception: " + e);
        }
    //        result = number/0;
    //        System.out.println(result);
        System.out.println("Code completed.");
    }
}