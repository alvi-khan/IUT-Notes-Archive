/*
    Shortcomings of program:
        Product and Customer names cannot have spaces
        Files have been opened and closed too many times. Messy.
*/

#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

void userChoice();

int createFile()
{
    string fileName;
    char ans1, ans2;
    cout<<"Please choose a file to create:\n1. Customer.txt\n2. Product.txt\nChoice: ";
    {
        cin>>ans1;
        if (ans1 == '1')    fileName = "Customer.txt";
        else if (ans1 == '2')   fileName = "Product.txt";
        else
        {
            cout<<"Invalid choice."<<endl;
            return 0;
        }

    }
    cout<<"Warning! Any existing file named "<<fileName<<" will be permanently removed and all data lost.\nAre you certain you want to continue? (Y/N): ";
    cin>>ans2;
    if (ans2 == 'Y' || ans2 == 'y')
    {
        ofstream newFile (fileName);
        if (newFile.is_open())
        {
            if (fileName == "Customer.txt")
                newFile<<"Customer_id name age gender no_of_purchases customer_type"<<endl;
            else if (fileName == "Product.txt")
                newFile<<"Product_id Name Price($) Weight(Kg)"<<endl;
            cout<<"File created successfully."<<endl;
        }
        else
        {
            cout<<"Error during file creation."<<endl;
        }
        newFile.close();
    }
    else
    {
        cout<<"File not created."<<endl;
    }
    return 0;
}

int addData()
{
    string fileName;
    char ans1;
    cout<<"Please choose a file to edit:\n1. Customer.txt\n2. Product.txt\nChoice: ";
    {
        cin>>ans1;
        if (ans1 == '1')    fileName = "Customer.txt";
        else if (ans1 == '2')   fileName = "Product.txt";
        else
        {
            cout<<"Invalid choice."<<endl;
            return 0;
        }

    }
    string line;
    ifstream oldFile (fileName);
    ofstream newFile ("newFile.txt");

    if (oldFile.is_open())
    {
        if (newFile.is_open())
        {
            while (getline(oldFile, line))
            {
                newFile<<line<<endl;        //gets every line from the old file and adds it to the new
            }
        }
        else
        {
            cout<<"Unable to create new file."<<endl;
            return 0;
        }
        oldFile.close();
    }
    else
    {
        cout << "Unable to open file "<<fileName<<endl;
        oldFile.close();
        newFile.close();
        remove("newFile.txt");
        return 0;
    }

    if (newFile.is_open())              //adding new information
    {
        if (fileName == "Customer.txt")
        {
            cout<<"Enter Customer ID: ";
            cin>>line;
            newFile<<line<<" ";
            cout<<"Enter Customer Name: ";
            cin>>line;
            newFile<<line<<" ";
            cout<<"Enter Customer Age: ";
            cin>>line;
            newFile<<line<<" ";
            cout<<"Enter Customer Gender: ";
            cin>>line;
            newFile<<line<<" ";
            cout<<"Enter Customer No of Purchases: ";
            cin>>line;
            newFile<<line<<" ";
            cout<<"Enter Customer Type: ";
            cin>>line;
            newFile<<line;
            newFile.close();
            remove("Customer.txt");
            rename("newFile.txt", "Customer.txt");
        }
        else if (fileName == "Product.txt")
        {
            cout<<"Enter Product ID: ";
            cin>>line;
            newFile<<line<<" ";
            cout<<"Enter Product Name: ";
            cin>>line;
            newFile<<line<<" ";
            cout<<"Enter Product Price (in USD): ";
            cin>>line;
            newFile<<line<<" ";
            cout<<"Enter Product Weight (in Kg): ";
            cin>>line;
            newFile<<line;
            newFile.close();
            remove("Product.txt");
            rename("newFile.txt", "Product.txt");
        }
    }
    return 0;
}

int showCustomerInfo()
{
    string customerID;
    cout<<"Please enter customer ID: ";
    cin>>customerID;
    string line;
    ifstream openFile("Customer.txt");
    if (openFile.is_open())
    {
        getline(openFile, line);    //skipping over first line since thats labels
        while (getline(openFile, line))
        {
            char tempID[100];
            int j = 0;
            for (int i=0; i<line.length(); i++)
            {
                if (line.at(i) == 32) break;    //for every line, until the first space, everything is part of ID
                tempID[j] = line.at(i); //store ID in char array
                j++;
            }
            tempID[j] = '\0';
            if (atoi(tempID) == stoi(customerID))  //convert string/char array to int and compare
            {
                string labels[6] = {"Customer ID: ", "Name: ", "Age: ", "Gender: ", "No. of Purchases: ", "Customer Type: "};
                int k=0;
                for (int i=0; i<line.length(); i++)
                {
                    cout<<endl<<labels[k];  //print label
                    k++;

                    while (line.at(i) != 32)
                    {
                        cout<<line.at(i);   //keep printing data until next space
                        i++;
                        if (i>= line.length())  break;  //break if end of line
                    }
                }
                cout<<endl<<endl;
                openFile.close();
                return 0;
            }
        }
        cout<<endl<<"Customer not found."<<endl;        //will not reach this line if customer was found
        openFile.close();
        return 0;
    }
    else
    {
        cout<<"Error. Unable to open file 'Customer.txt'."<<endl;
        return 0;
    }
}

int updateProductList()
{
    cout<<endl<<"Removing...";
    string line;
    ifstream oldFile ("Product.txt");
    ofstream newFile ("newFile.txt");

    if (oldFile.is_open())
    {
        if (newFile.is_open())
        {
            getline(oldFile, line);
            newFile<<line<<endl;
            while (getline(oldFile, line))
            {
                int tabCount = 0, j=0;
                char price[11];
                for (int i=0; i<line.length(); i++)
                {

                    if (line.at(i) == 32) tabCount++;   //for every line, keep detecting spaces

                    if (tabCount == 2)  //price comes after 2nd space
                    {
                        i++;
                        while (line.at(i) != 32)    //everything until next space is part of price
                        {
                            price[j] = line.at(i);
                            j++;
                            i++;
                        }
                        break;  //price found, no need to continue
                    }
                }
                price[j] = '\0';
                int x = atoi(price);    //convert char array to int
                if (x<1000) newFile<<line<<endl;
            }
            cout<<"done!"<<endl;
        }
        else
        {
            cout<<"Error. Unable to create new file."<<endl;
            return 0;
        }
        oldFile.close();
    }
    else
    {
        cout << "Unable to open file 'Product.txt'."<<endl;
        newFile.close();
        remove("newFile.txt");
        return 0;
    }
    newFile.close();
    remove("Product.txt");
    rename("newFile.txt", "Product.txt");
    return 0;
}

int updateCustomerList()
{
    cout<<endl<<"Updating...";
    string line;
    ifstream oldFile ("Customer.txt");
    ofstream newFile ("newFile.txt");

    if (oldFile.is_open())
    {
        if (newFile.is_open())
        {
            getline(oldFile, line);
            newFile<<line<<endl;
            while (getline(oldFile, line))
            {
                int tabCount = 0, j=0, lastTabPos;
                char purchases[11];
                for (int i=0; i<line.length(); i++)
                {

                    if (line.at(i) == 32) tabCount++;   //for every line, keep detecting spaces

                    if (tabCount == 4)  //customer purchase no is after 4th space
                    {
                        lastTabPos = i; //need to store position at which this was found so change can be made after that position
                        i++;
                        while (line.at(i) != 32)    //everything until next space is part of purchase no.
                        {
                            purchases[j] = line.at(i);
                            j++;
                            i++;
                        }
                        break;  //found purchase no. no need to continue
                    }
                }
                purchases[j] = '\0';
                int x = atoi(purchases);    //converting to integer
                if (x<20) newFile<<line<<endl;
                else
                {
                    for (int i=0; i<=lastTabPos; i++)   //print everything until purchase no.
                    {
                        newFile<<line.at(i);
                    }
                    line = purchases;
                    newFile<<line<<" ";     //print purchase no.
                    line = "Frequent";      //print new customer type
                    newFile<<line<<endl;
                }
            }
            cout<<"done!"<<endl;
        }
        else
        {
            cout<<"Unable to create new file."<<endl;
            return 0;
        }
        oldFile.close();
    }
    else
    {
        cout << "Unable to open file 'Customer.txt'."<<endl;
        newFile.close();
        remove("newFile.txt");
        return 0;
    }
    newFile.close();
    oldFile.close();
    remove("Customer.txt");
    rename("newFile.txt", "Customer.txt");
    return 0;
}

void userChoice()
{
    int action = 0;
    while (action == 0)
    {
        system("pause");    //waits for user to press some key. displays after each function
        system("CLS");      //clears the screen
        cout<<endl<<"1. Create a new file."<<endl<<"2. Add data to an existing file."<<endl;
        cout<<"3. View customer data."<<endl<<"4. Remove products costing more than $1000."<<endl;
        cout<<"5. Update customer ranking."<<endl<<"6. Exit Program."<<endl;

        cout<<endl<<"Choose an action: ";
        cin>>action;

        switch (action)
        {
        case 1:
            {
                system("CLS");
                action = createFile();      //every function returns 0 always
                continue;
            }
        case 2:
            {
                system("CLS");
                action = addData();
                continue;
            }
        case 3:
            {
                system("CLS");
                action = showCustomerInfo();
                continue;
            }
        case 4:
            {
                system("CLS");
                action = updateProductList();
                continue;
            }
        case 5:
            {
                system("CLS");
                action = updateCustomerList();
                continue;
            }
        case 6:
            {
                system("CLS");
                exit(1);
            }
        default:
            {
                cout<<"Incorrect input."<<endl;
                action = 0;
            }
        }
    }
}

int main()
{
    userChoice();
}
