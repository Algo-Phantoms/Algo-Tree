class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(),i,j;
        int dp[n+1][m+1],s=0;
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(i==1 || j==1)dp[i][j]=matrix[i-1][j-1];
                else{
                if(matrix[i-1][j-1]==1){
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
                }
                }
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
               // cout<<dp[i][j]<<" ";
                s+=dp[i][j];
            }
            //cout<<endl;
        }
        return s;
    }
};
