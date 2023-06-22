#include <bits/stdc++.h> 
// int sum(int i,int j,vector<vector<int>> &grid,vector<vector<int>>&dp){
//     if(i == 0 && j == 0){
//         return grid[0][0];
//     }
//     if(i < 0 || j < 0) return 1e9;
    
//     if(dp[i][j] != 0) return dp[i][j];
    
//     int l = grid[i][j] + sum(i,j-1,grid,dp);
//     int r = grid[i][j] + sum(i-1,j,grid,dp);
    
//     return dp[i][j] = min(l,r);
// }

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size() - 1;
    int m = grid[0].size() - 1;
    vector<vector<int> > dp(n+1,vector<int>(m+1,0));
    for(int i = 0 ; i <= n;i++ ){
        for(int j = 0 ; j <= m; j++){
            if(i==0 && j == 0) dp[i][j] = grid[0][0];
            else {
                int l = INT_MAX, r = INT_MAX;
                if(i > 0) l = grid[i][j] + dp[i-1][j];
                if(j > 0) r = grid[i][j] + dp[i][j-1];
                dp[i][j] = min(l,r);
            }
        }
    }
    return dp[n][m];
}