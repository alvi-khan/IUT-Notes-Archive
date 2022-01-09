#include <cstdio>           // same as stdio.h
using namespace std;

int heights[50000] = {-1};  // array of heights

void binSearch(int query, int lb, int ub)   // binary search
{
    int shorter = -1, taller = -1, mid;
    while(lb <= ub)                         // while within limits
    {
        mid = (lb + ub) / 2;                // mid-point of range
        if(heights[mid] == query)           // same height found
        {
            int temp = mid;
            while (heights[mid] == query)   mid--;  // find immediate shorter height
            shorter = heights[mid];
            while (heights[temp] == query)  temp++; // find immediate taller height
            taller = heights[temp];
            break;
        }

        else if(heights[mid] > query)       // mid-point value is too big
        {
            taller = heights[mid];          // this might be the immediate taller height
            ub = mid - 1;                   // change upper bound
        }
        else                                // mid-point value is too small
        {
            shorter = heights[mid];         // this might be the immediate shorter height
            lb = mid + 1;                   // change lower bound
        }
    }
    if (shorter == -1 || shorter == 0)  printf("X ");   // if invalid
    else                                printf("%d ", shorter);
    if (taller == -1 || taller == 0)    printf("X\n");
    else                                printf("%d\n", taller);
}

int main()
{
    int N, Q, query;
    scanf("%d", &N);    // input for array size

    for (int i=0; i<N; i++)    scanf("%d", &heights[i]);    // input for heights

    scanf("%d", &Q);    // input for query number

    for (int i=0; i<Q; i++)
    {
        scanf("%d", &query);    // input for queries
        binSearch(query, 0, N-1);
    }
}