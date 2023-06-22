#include <bits/stdc++.h> 

int solve(int n, vector<int> &nums,vector<int> &dp){
    if(n < 0) return 0;
    if(n == 0) return nums[0];

    if(dp[n] != -1) return dp[n];

    int l = nums[n] + solve(n-2,nums,dp);
    int r = solve(n-1,nums,dp);
 
    return dp[n] = max(l,r);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,-1);
    // return solve(n-1,nums,dp);
    dp[0] = nums[0];

    for(int i = 1; i < n; i++){
        int l = nums[i] + ((i > 1) ? dp[i-2] : 0);
        int r = dp[i-1];
        dp[i] = max(l,r);
    }

   return dp[n-1];
}