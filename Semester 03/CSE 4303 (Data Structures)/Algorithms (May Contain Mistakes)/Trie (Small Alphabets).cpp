#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

struct node
{
    bool endMark;	//word flag
    int words;      //keeps track of number of words that start with the node
    node* next[26];	//array of pointers for alphabets
    node* parent;   //parent pointer needed for deletion function
    node ()		    //constructor
    {
        endMark = false;
        words = 0;
        parent = NULL;
        for (int i=0; i<26; i++)    next[i] = NULL;
    }
};

//void insert (char* str, node* x)
//{
//    int len = strlen(str);
//    for (int i=0; i<len; i++)
//    {
//        x->words++;   //increment node's word count
//        int id = str[i] - 'a';   //finding which of the 26 nodes to use
//        if (x->next[id] == NULL)  x->next[id] = new node(); //if node did not exist, create it
//        x->next[id]->parent = x;    //setting parent;
//        x = x->next[id];	//go to next node
//    }
//    x->words++;   //increment node's word count
//    x->endMark = true;	//set endMark at end of word
//}

void insert(char* str, node* root)
{
    int len = strlen(str);
    node* current = root;
    for(int i=0; i<len; i++)
    {
        int id = str[i] - 'a';
        if(current->next[id] == NULL)
            current->next[id] = new node();
        current->next[id]->parent = current;
        current = current->next[id];
    }
    current->endMark = true;
}

bool searchTree (char* str, node* x)
{
    int len = strlen(str);
    for (int i=0; i<len; i++)
    {
        int id = str[i] - 'a';
        if (x->next[id] == NULL)  return false;	//word not found
        else    x = x->next[id];
    }
    return x->endMark;  //confirm if word or not
}

void remove (char* str, node* x)
{
    int len = strlen(str);
    for (int i=0; i<len; i++)
    {
        int id = str[i] - 'a';
        if (x->next[id] == NULL)  return;	//word does not exist
        else    x = x->next[id];
    }
    x->endMark = false;	//removing marker for word
    node* temp = x;   //keep track of string end
    while (x != NULL)
    {
        x->words--;   //decrement word count
        x = x->parent;
    }
    x = temp;
    int j = len - 1;	//will be used to go from end to beginning of input
    while (x != NULL)
    {
        if (x->endMark == true)   return;	//another word ends here
        for (int i=0; i<26; i++)    if (x->next[i] != NULL)   return; //node is part of other words
        x = x->parent;
        if (x == NULL)    return;	//parent of root reached
        int id = str[j] - 'a';	//locating alphabet of word
        x->next[id] = NULL;	//removing alphabet
        j--;
    }
}

char* longestPrefix(node* x, int j = 0, char* oldarr = new char)    //allocate memory to array by default when no array present
{
    char* arr = oldarr; //copy array so that allocated memory can be deleted, memory leak otherwise
    delete oldarr;
    arr[j] = '\0';    //arr is an array, end is marked
    if (x->endMark == true) return arr;   //return the array if a word ends
    int id, flag = 0;   //flag for multiple nodes
    for (int i=0; i<26; i++)
    {
        if (x->next[i] != NULL && flag == 0)
        {
            flag = 1;
            id = i; //id tracks next child position for single nodes
        }
        else if(x->next[i] != NULL && flag == 1)    return arr;   //if multiple nodes, return a
    }
    arr[j] = id + 'a';    //add next child to array
    return longestPrefix(x->next[id], j+1, arr);  //recursive call on next child
}

//void display (node* x, int j = -1, queue <char> arr = queue <char>())   //new queue by default when no queue is present
//{
//    if (j != -1)    arr.push(j+'a');    //push character into queue if not at root
//    if (x->endMark == true)
//    {
//        queue <char> print = arr;   //make a copy
//        while (!print.empty())      //print the copy
//        {
//            cout<<print.front();
//            print.pop();
//        }
//        cout<<endl;
//    }
//    for (int i=0; i<26; i++)    if (x->next[i] != NULL) display(x->next[i], i, arr);    //call recursively on all childred
//}

void display (node* x, int j = -1, queue <char> arr = queue <char>())
//new queue by default when no queue is present
{
    if (j != -1)
        arr.push(j+'a');
    //push character into queue if not at root
    if (x->endMark == true)
    {
        //int count = 0;
        queue <char> print = arr;   //make a copy
        while (!print.empty())      //print the copy
        {
            //count++;
            cout<<print.front();
            print.pop();
        }
        cout<<endl;
        //cout<<count<<endl;
    }
    for (int i=0; i<26; i++)
        if (x->next[i] != NULL)
            display(x->next[i], i, arr);
    //call recursively on all childred
}

void autoComplete (char* arr, node* x)
{
    int len = strlen(arr);
    int id;
    for (int i=0; i<len; i++)
    {
        id = arr[i] - 'a';    //next child index
        if (x->next[id] == NULL)  return; //input not present
        else    x = x->next[id];
    }
    queue <char> displayarr;    //queue for display function
    for (int i=0; i<len-1; i++) displayarr.push(arr[i]);    //adding prior alphabets to queue
    display(x, id, displayarr);    //print from node cur, with queue already containing prior alphabets
}

int countChildren (char* arr, node* x)
{
    int len = strlen(arr);
    int id;
    for (int i=0; i<len; i++)
    {
        id = arr[i] - 'a';
        if (x->next[id] == NULL)  return 0;
        else    x = x->next[id];
    }
    return x->words;
}

int main()
{
    node* root = new node();
    insert("alg", root);
    insert("algea", root);
    insert("also", root);
    /*insert("bat", 3, root);
    insert("bata", 4, root);
    insert("tom", 3, root);
    cout<<searchTree("algo", 4, root)<<endl;
    cout<<searchTree("algea", 5, root)<<endl;
    cout<<searchTree("also", 4, root)<<endl;
    cout<<searchTree("bat", 3, root)<<endl;
    cout<<searchTree("bata", 4, root)<<endl;
    cout<<searchTree("al", 2, root)<<endl;
    cout<<searchTree("tom", 3, root)<<endl;
    deleteString("tom", 3, root);
    cout<<searchTree("tom", 3, root)<<endl;
    deleteString("bat", 3, root);
    cout<<searchTree("bat", 3, root)<<endl;*/
    cout<<longestPrefix(root)<<endl;
    display(root);
//    node* root = new node();
//    insert("a", root);
//    insert("algo", root);
//    insert("algea", root);
//    insert("also", root);
//    insert("bat", root);
//    insert("bata", root);
//    insert("tom", root);
//    remove("bat", root);
//    display(root);
//    cout<<searchTree("algo", root)<<endl;
//    autoComplete("al", root);
//    cout<<longestPrefix(root)<<endl;
//    cout<<countChildren("", root);
}
