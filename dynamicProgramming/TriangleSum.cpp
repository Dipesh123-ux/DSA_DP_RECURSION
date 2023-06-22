#include <bits/stdc++.h> 

// int solve(int i,int j,int n,vector<vector<int>> &t,vector<vector<int>> &dp){
//     if(i == n){
//         return t[i][j];
//     }
//     if(dp[i][j] != 0) return dp[i][j];
//     int l = t[i][j] + solve(i+1,j,n,t,dp);
//     int r = t[i][j] + solve(i+1,j+1,n,t,dp);
//     return dp[i][j] = min(l,r);
// }

int minimumPathSum(vector<vector<int>>& t, int n){
    vector<vector<int>> dp(n,vector<int>(n,0));
     
    for(int j = 0; j < t[n-1].size();j++){
        dp[n-1][j] = t[n-1][j];
    }
    
    for(int i = n-2; i >= 0; i--){
        for(int j = i; j >= 0; j--){
            int l = t[i][j] + dp[i+1][j];
            int r = t[i][j] + dp[i+1][j+1];
            dp[i][j] = min(l,r);
        }
    }
    
    return dp[0][0];
}