   /*program to convert string to lowercase and uppercase*/
   #include<iostream>
   #include<string>
   using namespace std;


   string lowercase(string s1){
      for(int i=0;i<s1.size();++i)
       {
       if(s1[i]>=65 && s1[i]<=90)
           s1[i]=s1[i]+32;//conversion to lowercase
       }
       return s1;
   }


   string uppercase(string s1)
   {
      for(int i=0;i<s1.size();++i)
      {
         if(s1[i]>=97 && s1[i]<=122)
         {
           s1[i]=s1[i]-32;//convertion to uppercase case
         }
      }
       return s1;
   }

   int main()
   {
      string s1,lowercase_string,uppercase_string;
      getline(cin,s1);
      lowercase_string=lowercase(s1);//lowercase_string will contain the string with lowercase letter
      uppercase_string=uppercase(s1);//uppercase_string will contain the string with uppercase letter
      cout<<"Lowercase ->"<<lowercase_string<<endl;
      cout<<"Uppercase ->"<<uppercase_string<<endl;
      return 0;
   }


   /*
   Test Case 1:

   input - EloQuEnT
   output - Lowercase ->eloquent
            Uppercase ->ELOQUENT


   Test Case 2:

   input - DiVeRtIcuLaR
   output - Lowercase ->diverticular
            Uppercase ->DIVERTICULAR
            
   
   Time complexity: O(n)
   Space Complexity: O(n)


   */
