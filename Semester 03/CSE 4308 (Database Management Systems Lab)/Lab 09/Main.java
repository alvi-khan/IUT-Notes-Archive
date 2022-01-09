import java.sql.*;  // package for SQL functions

public class Main {
    public static void main(String[] args)
    {
        String username = "a";   // database username
        String password = "1234";   // database password
        String url = "jdbc:oracle:thin:@localhost:1521/orcl";   // URL to connect to database; note: standard edition being used
        String sqlQuery = "SELECT a_id, amount, type FROM transactions";    // SQL query to run; retrieve information about transactions

        // data from each record retrieved by query is stored in these variables
        int account;    // account id
        int amount;     // transaction amount
        String type;    // transaction type

        // these arrays store the information about the accounts (index position = account id assuming ids < 1000)
        int[] totalBalance = new int[1000];     // filled with 0s by default
        int[] totalTransactions = new int[1000];

        try
        {
            Class.forName("oracle.jdbc.driver.OracleDriver");   // registering driver class
            Connection conn = DriverManager.getConnection(url, username, password); //creating connection object
            Statement statement = conn.createStatement();   // creating statement object
            System.out.println("Successfully connected to database.");
            ResultSet result = statement.executeQuery(sqlQuery);    // execute query and store result

            while (result.next())   // for each tuple in result
            {
                account = result.getInt("a_id");    // get account id
                amount = result.getInt("amount");   // get transaction amount
                type = result.getString("type");    // get transaction type

                if (type.equals("0"))   totalBalance[account] += amount;    // money added to account
                else                    totalBalance[account] -= amount;    // money removed from account

                totalTransactions[account] += amount;  // total transactions always increase

                //System.out.println(account + " " + amount + " " + type);  // prints every transaction
            }

            conn.close();       // closing connection, statement and result objects
            statement.close();
            result.close();

            // these variables store the number of accounts in each category
            int totalAccounts = 0;
            int totalCIPAccounts = 0;
            int totalVIPAccounts = 0;
            int totalOrdinaryAccounts = 0;

            for (int i=0; i<1000; i++)
            {
                int currentAccountBalance = totalBalance[i];
                int currentAccountTotalTransactions = totalTransactions[i];
                if (currentAccountTotalTransactions != 0)  // account present
                {
                    if (currentAccountBalance > 1000000 && currentAccountTotalTransactions > 5000000)   totalCIPAccounts++;
                    else if (currentAccountBalance > 500000 && currentAccountBalance < 900000 && currentAccountTotalTransactions > 3500000 && currentAccountTotalTransactions < 4500000)    totalVIPAccounts++;
                    else if (currentAccountBalance < 40000 && currentAccountTotalTransactions < 3000000)    totalOrdinaryAccounts++;
                    totalAccounts++;
                }
            }

            System.out.println("Total Number of Accounts: " + totalAccounts);
            System.out.println("CIP Count: " + totalCIPAccounts);
            System.out.println("VIP Count: " + totalVIPAccounts);
            System.out.println("Ordinary Count: " + totalOrdinaryAccounts);
            System.out.println("Uncategorized: " + (totalAccounts - totalCIPAccounts - totalVIPAccounts - totalOrdinaryAccounts));
        }
        catch(SQLException e)   // database connection error
        {
            System.out.println("Error while connection to database.\nError Code: " + e);
        }
        catch (ClassNotFoundException e)    // driver error
        {
            System.out.println("Failed to register driver.\nException Code: " + e);
        }
    }
}
