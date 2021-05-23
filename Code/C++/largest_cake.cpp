/*
Question:
 
   It's Gary's birthday today and he has ordered his favorite square cake consisting of '0's and'1's. But Gary wants the biggest piece of '1's and no '0's. A piece of cake is defined as a part that consists of only '1's, and all '1's share an edge with each other on the cake. Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary? */

//Main Function

// 1 .Takint the input of 2-D vector  cake[n X n] n:size of the cake , where 0 represent no piece cake and 1 represent the piece of cake .
//2. calling the function getBiggestPieceSize(cake,n) ,will return the size of the biggest piece of the cake

//Algorithm for getBiggestPieceSize(vector<vector<int>> &cake, int n)

//1.Create a 2-D array -  visited, that will store the record ,whether a block (i,j) has been visited yet or not;.We are maintaining this because we can travel in all 4 directions so to avoid the recursive call on already visited i,j th block we need this visited array;Initially Mark every block as false,since we have not visited any (i,j)th block yet. Also there can be no of components of connected 1's ,so to traverse every component only one time ,visited array can help.

//2.Since the 1's reperest the piece of cake and there can be a no of  components of connected 1's in the 2-d array ,means there can be any no of piece of cake with different size. but we need to get the piece of cake with the maximum size.So,we will traverse over the cakes array and if we find that cakes[i][j]==1 && !visited[i][j] ,we will call the function to get the size of the cake piece starting from i,j position .To find the size we use the dfs approach .And we will maintain variable ans that will store tha maximum size of the cake so far .Intially assign it with INT_MIN;


/*Algorithm for helper(vector<vector<int>> &cake,bool**visited,int i,int j, int n)

this function will return no of connected  1's  starting from (i,j) position ,i.e it will return the size of the cake that we can get from the i,j th position.
we can traverse in all 4 directions and will  add the  result provided by these 4 calls  together to get the size and at the end adding 1 for this i,j th block .


1. if(i>=n||j>=n||i<0||j<0) checking for the edges  that if the i,j gets out of range just simply return 0 in this case as we can't find any piece of cake.
2.if cakes[i][j]==0 ,if we ae the block whose value is 0 that means the we can't go further from this posotion as we can't get the connected 1's due to this 0 .and we know that 0 means no piece of cake is there .,so return 0 in this cake
3 if(visited[i][j]==1,means that the i,j position u have alreday visited u can't get to this again.,return 0;
4.If none of the above condition satisfies that means we can move futher with i,j th block.
5.So makrd visited[i][j]=true; so that we can't get to this position again
6.Call recursion on all the 4 directions  and add their ans together  */


    /*int small_ans=helper(cake,visited,i-1,j,n);//top
     ans+=small_ans;
     small_ans=helper(cake,visited,i+1,j,n);//down
     ans+=small_ans;
     small_ans=helper(cake,visited,i,j-1,n); //left
     ans+=small_ans;
     small_ans=helper(cake,visited,i,j+1,n); //right
     ans+=small_ans;
     */

/*
7. ans=ans+1 //for the i,j the block as this will also count in the size;
8. return ans ;

9.After returning check if this ans is greter than the already stored ans ,if yes then update your ans with this calculated ans .
10.at end when u traverse over evry 1 u will have the size of the largest piece of cake in the variable ans. ,so return this ans .
 */




#include<iostream>
using namespace std;
#include<vector>

#include<climits>
int helper(vector<vector<int>> &cake,bool**visited,int i,int j, int n)
{
    //base cases
    if( i>=n || j >=n || i<0 || j<0 )
    {
        return 0;
    }
    if( cake[i][j] == 0 )
    {
        return 0;
    }
    if( visited[i][j] == 1 )
    {
        return 0;
    }
    
    
    int ans = 0;
    visited[i][j] = 1;
    
    //just checking in all the 4 directions and adding their respective ans into our main ans
    //since the piece of the cake can be of any shape but it should be continuous,i.e the
    //connected component of 1's will give you the length of a  piece of cake ;
   
    //top
    int small_ans = helper( cake , visited , i-1 , j , n );
    ans+= small_ans;
   //down
    small_ans = helper(cake , visited , i+1 , j , n );
    ans+= small_ans;
    
   //left
    small_ans = helper( cake , visited , i ,j-1 ,n );
    ans+= small_ans;
   //right
    small_ans = helper( cake , visited , i , j+1 , n );
    ans+= small_ans;
    
    return ans+1;
    
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n)
{
    bool**visited = new bool*[ n ];
    for(int i = 0 ; i<n ; i++)
    {
        visited[i]=new bool[n];
        for(int j = 0 ; j<n ; j++ )
        {
            visited[i][j] = false;
        }
    }
    int ans = INT_MIN;
    for(int i = 0 ;i < n ; i++ )
    {
        for(int j = 0 ;j < n ; j++ )
        {
            if(cake[i][j] == 1 && !visited[i][j])
            {
                int small = helper( cake , visited , i , j ,n );
                //checking for all the  different size of the cake given  in the input and updating our ans accordingly
                //i.e getting the length of the each connected component of 1's in the graph and updating the ans ;
                ans = max( ans , small );
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> cake;
    for(int i = 0 ;i < n; i++ )
    {
        vector<int>v;
        cake.push_back(v);
    }
    for (int i = 0; i < n; ++i) {
           for (int j = 0; j < n; ++j) {
               cin >> cake[i][j];
           }
       }
    cout << getBiggestPieceSize(cake, n) << endl;;
}


/*Example 1:

n= 4
0 1 0 0
1 1 0 0
1 0 1 1
0 0 1 0

output: 4

*/


/*
Explaination :
there are 2 componets of connected 1's in the given 2-d vector
ans=INT_MAX;
the first one is 0 1 0 0
                 1 1 0 0
                 1 0 0 0      size: 4;
                 0 0 0 0      ans=max(ans,size)
ans=4;
the second one is
0 0 0 0
0 0 0 0                      size: 3;
0 0 1 1                      ans=max(ans,size)
0 0 0 1

ans=4
*/



/*
Example:2

n= 3
1 1 0
0 0 0
1 0 1

Output: 2;

*/

/*
Explaination :
there are 2 componets of connected 1's in the given 2-d vector
ans=INT_MAX;
the first one is 1 0 0
                 1 0 0
                 1 0 0        size: 2;
                              ans=max(ans,size)
ans=2;
the second one is
0 0 0
0 0 0                      size:1;
1 0 0                      ans=max(ans,size)


ans=1
the second one is
0 0 0
0 0 0                      size:1;
0 0 1                      ans=max(ans,size)


ans=1


 Ans: 2;
*/



//TIME COMPLEXITY:  O(n^2)


//SPACE COMPLEXITY: O(n^2)


//n:size of the square cake

