#include <bits/stdc++.h>
using namespace std;
//Driver's Code
int main()
{
    //An array is a list of elements of the same type, identified by a pair of square brackets [ ]. It is a collection of items stored at contiguous memory locations. To use an array, you need to declare the array with 3 things: a name, a type and a dimension (or size, or length).
    
    //Syntax: data-type arrayname[length];
    
    int array[5]={2,3,4,5};//datatype:integer name:array size:5
    int x=1;//number we have to insert at beginning
    
    //Algorithm:
         //->Move other element to next position so that beginning space gets empty
         //->initialise element to index[0];
    for(int i=4;i>0;i--)
    {
        array[i]=array[i-1];
    }
    array[0]=x;
    
    for(int i=0;i<5;i++)
    {
        cout<<array[i]<<" ";
    }
    //1|2|3|4|5
}