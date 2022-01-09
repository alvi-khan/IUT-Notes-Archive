#include <cstdio>
#include <cstdlib>
#include <ctime>

bool leap(int year)
{
    if((year%400==0 || year%100) &&(year%4==0)) return true;
    else    return false;
}

int main()
{
    freopen("table.sql", "w", stdout);
    int a_id;
    int t_id=1;
    printf("DROP TABLE ORDERS CASCADE CONSTRAINTS;\n");
    printf("DROP TABLE ORDER_ITEMS CASCADE CONSTRAINTS;\n");
    printf("CREATE TABLE ORDERS\n(\n\tORDER_ID INT, \n\tCLIENT_ID INT, \n\tORDER_YEAR INT, \n\tSTATUS INT, \n\tPRIMARY KEY (ORDER_ID)\n);\n");
    printf("\n");
    printf("CREATE TABLE ORDER_ITEMS\n(\n\tORDER_ID INT, \n\tITEM_ID INT, \n\tQUANTITY INT, \n\tPPU NUMBER, \n\tFOREIGN KEY (ORDER_ID) REFERENCES ORDERS\n);\n");
    printf("\n\n");
    srand(time(NULL));
    int no_of_orders=100+rand()%200;
    int no_of_clients = 50;
    for(int i=0; i<no_of_orders; i++)
    {
        int year = rand()%20+2000;
        int client_id = rand()%no_of_clients+1;
        int status = rand()%2; // 0 = not shipped, 1 = shipped
        printf("INSERT INTO ORDERS VALUES(%d, %d, %d, %d);\n", i+1, client_id, year, status);
    }
    printf("\n");
    for(int i=0; i<no_of_orders; i++)
    {
        int times=rand()%10+1;
        for(int k=0; k<times; k++)
        {
            int item_id = rand()%5+1; //5 items in total
            int ppu;
            int quantity = rand()%50+1;
            if (item_id==1)         ppu = 5;
            else if (item_id==2)    ppu = 7;
            else if (item_id==3)    ppu = 9;
            else if (item_id==4)    ppu = 4;
            else if (item_id==5)    ppu = 8;
            printf("INSERT INTO ORDER_ITEMS VALUES(%d, %d, %d, %d);\n", i+1, item_id, quantity, ppu);
        }
    }
    printf("COMMIT;\n");

    return 0;
}