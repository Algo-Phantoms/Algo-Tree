/*   Program to  get the maximum occurring character in a string.
     
     Steps:-
     1.String to be entered by user.

     2.Initializing the string, an output variable to store the maximum occured character, getmax .

     3.Calculate the string length by using strlen function.

     4.Using a for loop it will do the comparison to find out the maximum occured character.

     5.If character count==1, it will give no character repeated else it will print the character repeated.


*/ 


#include<bits/stdc++.h>

using namespace std;

int main()
{   char str[256];
    
    //creating an array namely count to keep track of individual count of characters.
    //here used 256 as we have total 256 ASCII characters.
    int count[256]={0};
    
    // 'output' will store the maximum occuring character in the string.
    int output;
    int getmax=0;

    cout<<"Enter the String:-\n";
    cin>>str;

    //this 'strlen' will calculate the length of the string 
    int length=strlen(str);

    //it will give the maximum occured character
    for(int i=0;i<length;i++)
    {   
       count[str[i]]++;
        if (getmax < count[str[i]]) 
        {
            getmax = count[str[i]];
            output = int(str[i]);
        }

       
    }
    //if no character repeated i.e. count is 1.
    if(count[output]==1)
    {
        cout<<"No duplicate exists";
    }
    //it will print the maximum occured character
    else
    cout<<char(output);
}



/*  Testcases:

    1.Input:
        Enter the String:-
        acbd
      Output:
        No duplicate exists

    2.Input:
        Enter the String:-
        alliswellattheend
      Output:
        l


    Complexity:
        Time Complexity-O(n)
        Space Complexity-0(1)


*/