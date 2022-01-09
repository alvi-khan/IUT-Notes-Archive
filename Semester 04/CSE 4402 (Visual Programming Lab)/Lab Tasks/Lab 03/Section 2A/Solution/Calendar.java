public class Calendar 
{
    String d;
    int date;
    int month;
    int year;
    
    public void setDate(String s)
    {
        d = s;
        int temp1 = d.charAt(0); 
        temp1 = temp1 - 48;
        int temp2 = d.charAt(1);
        temp2 = temp2 - 48;
        date = temp1 * 10 + temp2;
        
        temp1 = d.charAt(3); 
        temp1 = temp1 - 48;
        temp2 = d.charAt(4);
        temp2 = temp2 - 48;
        month = temp1 * 10 + temp2;
        
        temp1 = d.charAt(6); 
        temp1 = temp1 - 48;
        temp2 = d.charAt(7);
        temp2 = temp2 - 48;
        int temp3 = d.charAt(8);
        temp3 = temp3 - 48;
        int temp4 = d.charAt(9);
        temp4 = temp4 - 48;
        year = temp1 * 1000 + temp2 * 100 + temp3 * 10 + temp4;  
    }
    
    public String isLeapYear()
            {
                if(year % 4 == 0)
                {
                    if(year % 100 == 0)
                    {
                        if(year % 400 == 0)
                            return "Yes";
                        else
                            return "No";
                    }
                    else
                        return "Yes";
                }
                else
                    return "No";
            }
    
    public String dayOfWeek()
    {
        int d = date;
        int m = month;
        int y = year;
        if (month < 3) 
        {
            m += 12;
            y--;
        }
        int temp; 
        temp = (int)((d + ((m+1)*2.6) +  y + (y/4) + 6*(y/100) + (y/400) + 6) % 7);
        
        if(temp == 0)
            return "Sunday";
        else if(temp == 1)
            return "Monday";
        else if(temp == 2)
            return "Tuesday";
        else if(temp == 3)
            return "Wednesday";
        else if(temp == 4)
            return "Thursday";
        else if(temp == 5)
            return "Friday";
        else 
            return "Saturday";
    }
    
    public Boolean isValidDate()
    {
        if(isLeapYear() == "Yes" && month == 2 && date >= 1 && date <= 29 && year >= 1 && year <= 9999)
            return true;
        else if(isLeapYear() == "No" && month == 2 && date >= 1 && date <= 28 && year >= 1 && year <= 9999)
            return true;
        else if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && date >= 1 && date <= 31 && year >= 1 && year <= 9999)
            return true;
        else if(date >= 1 && date <= 30 && month >= 1 && month <= 12 && year >= 1 && year <= 9999)
            return true;
        else
            return false;
    }
    
    public String nextDate()
    {
        int d = date;
        int m = month;
        int y = year;
        if(month == 12 && date == 31)
        {
            y++;
            m = 1;
            d = 1;
        }
        else if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) && date == 31)
        {
            d = 1;
            m++;
        }
        else if((month == 3 || month == 6 || month == 9 || month == 11) && date == 30)
        {
            d = 1;
            m++;
        }
        else if(month == 2 && (date == 28 || date == 29))
        {
            d = 1;
            m++;
        }
        else
            d++;
        
        return d + "/" + m + "/" + y;
    }
    
    public String previousDate()
    {
        int d = date;
        int m = month;
        int y = year;
        
        if(month == 1 && date == 1)
        {
            y--;
            m = 12;
            d = 31;
        }
        else if((month == 12 || month == 5 || month == 7 || month == 10) && date == 1)
        {
            d = 30;
            m--;
        }
        else if((month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11) && date == 30)
        {
            d = 31;
            m--;
        }
        else if(month == 3 && date == 1)
        {
            if(isLeapYear() == "Yes")
                d = 29;
            else
                d = 28;
            
            m--;
        }
        else
            d--;
        
        return d + "/" + m + "/" + y;
    }
    
}
