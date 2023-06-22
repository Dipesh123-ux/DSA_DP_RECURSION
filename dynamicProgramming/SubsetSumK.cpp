#include <bits/stdc++.h> 

//memoization

bool solve(vector<int>&arr,int idx,int t,vector<vector<int>>&dp){
    if(t == 0) return true;
    if (idx == 0) return arr[0] == t;
    if(dp[idx][t] != -1) return dp[idx][t]; 
    bool nt = solve(arr,idx-1,t,dp);
    bool ta = false;
    if(t >= arr[idx]){
        ta = solve(arr,idx-1,t-arr[idx],dp);
    }

    return dp[idx][t] =  ta || nt;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
     vector<vector<bool>> dp(n,vector<bool>(k+1,0));
     for(int i = 0; i < n;i++){
         dp[i][0] = true;
     }
     dp[0][arr[0]] = true;

     for(int i = 1; i < n;i++){
         for(int t = 1; t <= k;t++){
            bool nt = dp[i-1][t];
            bool ta = false;
            if(t >= arr[i]){
                ta = dp[i-1][t-arr[i]];       
            } 
             dp[i][t] = (nt or ta);
           
         }
     }

     return dp[n-1][k];
    
}