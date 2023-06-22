class Solution {
public:
    // int countPaths(int i,int j,int n,int m,vector<vector<int>> &dp){
    //     if((i==n-1) && (j==m-1)){
    //         return 1;
    //     }
    //     if(i>=n || j>=m){
    //         return 0;
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     else{
    //         return dp[i][j]=countPaths(i+1,j,n,m,dp)+countPaths(i,j+1,n,m,dp);
    //     }
    // }
    int uniquePaths(int m, int n) {
        int count[m][n];
        
        for(int i=0; i<m; i++){
            count[i][0] = 1;
        }
        
        for(int i=0; i<n; i++){
            count[0][i] = 1;
        }
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                count[i][j] = count[i-1][j] + count[i][j-1];
            }
        }
        return count[m-1][n-1];
//         vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
//         int num=countPaths(0, 0, m, n, dp);
//         if(m==1 && n==1){
//             return num;
//         }
//         return dp[0][0];
    }
};