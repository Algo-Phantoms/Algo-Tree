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

 int main() {

	string s;
	//input from the user
	cin>>s;
    /*if length of given string is less
    than two, no such substring exist
    hence prints 0*/
	if(s.length()<2)
    cout<<0;
   
    else{
        int l=0,i=s.length()/2;

        /*loop calculating the length of
        such substring*/
         while(i<s.length())
           {
              if(s[i]==s[l])
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
            if(l>s.length()/2) 
            cout<<s.length()/2 ;
            else 
            cout<<l;
          }

	return 0;
}
