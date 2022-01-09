#include <iostream>
using namespace std;

char image[25][25]; // matrix for image

void dfs(int dim, int i, int j) // dfs traversal
{
    if(i < 0 || j < 0 || i >= dim || j >= dim || image[i][j] == '0')  return;   // if out of bounds or not an eagle, return
    image[i][j] = '0';  // if eagle part is visited already mark as zero -> same thing as visited array
    for(int k = -1; k < 2; k++)
    {
        for(int l = -1; l < 2; l++) // for valid indexes
        {
            if (k || l)  dfs(dim, i+k, j+l);    // if there is an eagle part, run dfs on it
        }
    }
}

int eagleCount(int dim) // run dfs on all eagle parts
{
    int count = 0;
    for (int i=0; i<dim; i++)
    {
        for (int j=0; j<dim; j++)
        {
            if (image[i][j] == '1') // if eagle part is found
            {
                dfs(dim, i, j); // dfs will traverse all eagle parts that are joint to this one; thus just one count
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int dim, images = 0;
    while (cin>>dim)
    {
        images++;   // number of images
        for (int i=0; i<dim; i++)   // input for images
        {
           cin>>image[i];
        }
        cout<<"Image number "<<images<<" contains "<<eagleCount(dim)<<" war eagles."<<endl;
    }
}