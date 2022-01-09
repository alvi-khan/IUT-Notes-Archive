#include<iostream>
#include<string.h>
#include<queue>     //required for display function
#include<tgmath.h>  //required to calculate maximum length of binary strings
using namespace std;
#define MAXNUM 16   //maximum decimal value that will be used

struct node
{
    bool endMark;   //end of number
    node* next[2];  //array for pointers for binary digits
    node* parent;
    node()          //constructor
    {
        endMark = false;
        for (int i=0; i<2; i++) next[i] = NULL;
        parent = NULL;
    }
};

char* numToBin (int n)      //converts decimal number to binary string
{
    int i;
    char* resTemp = new char;   //memory allocation workaround; otherwise crash at remove function; no clue why
    char* res = resTemp;
    delete resTemp;
    if (MAXNUM <= 0)    i = 0;
    else    i = log2(MAXNUM);
    res[i+1] = '\0';
    res[i] = '0';
    while (n != 0)
    {
        res[i] = (n%2) + '0';
        n = n/2;
        i--;
    }
    while (i>-1)
    {
        res[i] = '0';
        i--;
    }
    return res;
}

int binToNum (queue <char> str)     //converts binary char queue from display function to decimal number
{
    int i, res = 0;
    if (MAXNUM <= 0)    i = 0;
    else    i = log2(MAXNUM);
    while (!str.empty())
    {
        if (str.front() == '1') res += pow(2, i);
        i--;
        str.pop();
    }
    return res;
}

void insert(int n, node* x)
{
    char* str = numToBin(n);
    int len = strlen(str);
    for (int i=0; i<len; i++)
    {
        int id = str[i] - '0';  //finding which of the two nodes to use
        if (x->next[id] == NULL)    x->next[id] = new node();   //if node did not exist, create it
        x->next[id]->parent = x;    //setting parent
        x = x->next[id];    //go to next node
    }
    x->endMark = true;  //set endMark at end of number
}

bool searchTree(int n, node* x)
{
    char* str = numToBin(n);
    int len = strlen(str);
    for (int i=0; i<len; i++)
    {
        int id = str[i] - '0';
        if (x->next[id] == NULL)    return false;   //number not found
        x = x->next[id];
    }
    return x->endMark;  //confirm if number or not
}

void remove(int n, node* x)
{
    char* str = numToBin(n);
    int len = strlen(str);
    for (int i=0; i<len; i++)
    {
        int id = str[i] - '0';
        if (x->next[id] == NULL)    return; //number does not exist
        x = x->next[id];
    }
    x->endMark = false; //remove marker for number
    int j = len-1;  //will be used to go from end to beginning of input
    while (x != NULL)
    {
        if (x->endMark == true) return; //there's another number ending here
        for (int i=0; i<2; i++) if (x->next[i] != NULL) return; //node is part of other number
        x = x->parent;
        if (x == NULL)  return; //root reached;
        int id = str[j] - '0';  //location binary digit of number
        x->next[id] = NULL; //removing digit
        j--;
    }
}

void display(node* x, int j = -1, queue <char> arr = queue <char>())    //new queue by default when no queue is present
{
    if (j != -1)    arr.push(j+'0');    //push character into queue if not at root
    if (x->endMark == true) cout<<binToNum(arr)<<endl;
    for (int i=0; i<2; i++)    if (x->next[i] != NULL)  display(x->next[i], i, arr);
}

int maxXOR (int n, node* x)
{
    char* str = numToBin(n);
    queue <char> res;
    int len = strlen(str);
    for (int i=0; i<len; i++)
    {
        int id = str[i] - '0';
        if (x->next[!id] != NULL)   //if opposite digit is available
        {
            x = x->next[!id];
            res.push('1');  //result for digit is 1
        }
        else
        {
            x = x->next[id];
            res.push('0');  //result for digit is 0
        }
    }
    return binToNum(res);
}

int main()
{
    node* root = new node();
    insert(4, root);
    insert(2, root);
    cout<<searchTree(2, root)<<endl;
    display(root);
    remove(2, root);
    cout<<searchTree(2, root)<<endl;
    display(root);
    cout<<maxXOR(8, root);
}
