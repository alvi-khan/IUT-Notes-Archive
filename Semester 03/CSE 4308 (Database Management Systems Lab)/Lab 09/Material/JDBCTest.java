import java.sql.*;
public class JDBCTest
{
    public static void main(String[] args)
    {
        String username = "A";
        String password = "1234";
        String url = "jdbc:oracle:thin:@localhost:1521:orcl";
        String sqlQuery = "SELECT AVG(age) FROM customer";
        double avgAge ;

        try
        {
            // 1) Register the driver class
            Class.forName("oracle.jdbc.driver.OracleDriver");

            // 2) Create the connection object
            Connection conn = DriverManager.getConnection(url, username, password);

            // 3) Create the statement object
            Statement statement = conn.createStatement();
            System.out.println("Connection to database successful.");

            // 4) Execute the query
            ResultSet result = statement.executeQuery(sqlQuery);
            while (result.next())
            {
                avgAge = result.getLong(1);
                System.out.println("Average age: " + avgAge);
            }

            // 5) Close the objects
            conn.close();
//            statement.close();
//            result.close();
        }
        catch (SQLException e)
        {
            System.out.println("Error while connecting to the database. Exception code: " + e);
        }
        catch (ClassNotFoundException e)
        {
            System.out.println("Failed to register driver. Exception code: " + e);
        }
    }
}