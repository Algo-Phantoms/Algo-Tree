/*
-LONGEST PREFIX SUFFIX
-Given a string, find the length of longest substring that is both prefix and suffix
-overlapping of prefix and suffix not allowed

-idea is to divide the given string from between and check if both string are equal
-if so return the length of that substring
-otherwise check for the shorter length
-cpp code
 */

 #include <iostream>
 using namespace std;

//function to find the length of longest substring

int pre_suff(string str)
{
    /*if length of given string is less
    than two, no such substring exist
    hence returns 0*/
    if(str.length() < 2)
    {
    return 0;
    }

    int l=0,i=str.length()/2;

    /*loop calculating the length of
    such substring*/
    while(i<str.length())
        {
            if(str[i]==str[l])
            {
             ++l;
             ++i;
            }
            else
            {
            i=i-l+1;
            l=0;
            }
        }
    /*as overlapping is not allowed*/
    return (l> str.length()/2) ? str.length()/2 : l;
}
//main
int main() {

	string s;
	//input from the user
	cin>>s;
	//calling pre_suff(.)
	cout<<pre_suff(s);

	return 0;
}


/*

    Test Cases

Test Case-1
 Input = "rrrrr"
 Output = 2

Test Case-2
 Input = "abcdabc"
 Output = 3

Time complexity = O(n)
Space complexity = O(n)

*/
