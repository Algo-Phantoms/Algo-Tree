/*  The algorithm finds out the first NON-REPEATING character present in the string, if NOT present it will return -1.
    
    STEPS:-
    1. Firstly, enter the string.
    2. Send the input string to the function first_nonrepeating_char().
    3. Create an array of size 26, which will hold the current count of all the characters at that point and 
       a vector  which hold the unique characters till now.
    4. If it's the first element then, simply insert it into the vector, and increase the count of the character by 1 and
       make the value pos=0.
    5. If it is not the first element ,then first  increase the count of the current index character and 
       insert it into the vector if the current index character count is 1. Check if the value at the position pos in the vector 
       is greater than 1, then simply  run a loop until we find a valid position with count=1.
    6. If the value of the pos is less than the vector size, that means there is a unique character in the string. So ,simply copy 
       the character into the answer variable. Otherwise, make the answer variable= -1.
    */




#include<bits/stdc++.h>
using namespace std;

void first_nonrepeating_char(string s,string &answer)
{
    vector<int>v;
    int a[26]={0};
    int pos=-1,n=s.length();
    for(int i=0;i<n;i++)
    {
        if(v.size()==0)
        {   
            //push the current index into vector.
            v.push_back(i);
            pos=0;
            //increase the count of character.
            a[s[i]-'a']++;
        }
        else
        {
            //increase the count of character.
            a[s[i]-'a']++;


            if(a[s[i]-'a']==1)
            {
                v.push_back(i);
            }

            if(pos<v.size() and a[s[v[pos]]-'a']>1)
            {
                while(pos<v.size() and a[s[v[pos]]-'a']>1)
                {
                    pos++;
                }
            }
        }
    }

    if(pos<int(v.size()))
    {
        cout<<"The First Non Repating character in the String is : ";
        answer=s[v[pos]];
        return;
    }
    //If there is no unique character present , it will assign answer=-1.
    cout<<"There is no unique non-repeating character in the string : ";
    answer="-1";

}



int main()
{
    string str,answer;

    cin>>str;

    first_nonrepeating_char(str,answer);
    cout<<answer<<"\n";
    return 0;
}


    /* TEST CASES:-
    1.
    input->
    
    abcdaeecd
    output->
    The First Non Repating character in the String is : b
    
    2.
    input->
    aabbbbcccdeg
    output->
    The First Non Repating character in the String is : d
    3.
    input->
    ababccdede
    output->
    There is no unique non-repeating character in the string : -1
    TIME COMPLEXITY : O(N)
    SPACE COMPLEXITY : O(1)
    */ 