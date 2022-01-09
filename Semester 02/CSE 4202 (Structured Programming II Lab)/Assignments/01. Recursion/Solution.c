#include<stdio.h>

char arr[101][101];

depo_count(int i, int j)
{
    arr[i][j] = '*';
    if(arr[i][j+1] == '@')      depo_count(i, j+1);
    if(arr[i][j-1] == '@')      depo_count(i, j-1);
    if(arr[i+1][j] == '@')      depo_count(i+1, j);
    if(arr[i+1][j+1] == '@')    depo_count(i+1, j+1);
    if(arr[i+1][j-1] == '@')    depo_count(i+1, j-1);
    if(arr[i-1][j] == '@')      depo_count(i-1, j);
    if(arr[i-1][j+1] == '@')    depo_count(i-1, j+1);
    if(arr[i-1][j-1] == '@')    depo_count(i-1, j-1);
    else                        return;

}

int main()
{
    int a, b, i, j, oil_count;
    while(a != 0)
    {
        oil_count=0;
        scanf("%d %d", &a, &b);
        if(a == 0)  break;
        for(i=0; i<a; i++)  scanf("%s", &arr[i]);

        for(i=0; i<a; i++)
        {
            for(j=0; j<b; j++)
            {
                if(arr[i][j] == '@')
                {
                    depo_count(i, j);
                    oil_count++;
                }
            }
        }
        printf("%d\n", oil_count);
    }
}
