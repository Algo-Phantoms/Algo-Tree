class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int n=mat.size(),m=mat[0].size();
        int ps[n+1][m+1],i,j,k,l,p;
        memset(ps,0,sizeof(ps));
       
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                ps[i][j]=ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1]+mat[i-1][j-1];
            }
        }
        
        int dp[n][m],r1,r2,c1,c2;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                r1=max(0,i-K);
                r2=min(i+K,n-1);
                c1=max(0,j-K);
                c2=min(j+K,m-1);
                dp[i][j]=ps[r2+1][c2+1]-ps[r1][c2+1]-ps[r2+1][c1]+ps[r1][c1];
            }
        }
        vector<vector<int>> an;
            
        for(i=0;i<n;i++){
            vector<int> aa;
             for(j=0;j<m;j++) aa.push_back(dp[i][j]);
            an.push_back(aa);
        }
        return an;
    }
};
