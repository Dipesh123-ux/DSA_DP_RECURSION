#include <bits/stdc++.h> 


//memoization

int solve(int n, vector<int> &h,vector<int> &dp){
    if(n == 0) return 0;

    if(dp[n] !=-1) return dp[n];
  
    int l = solve(n-1,h,dp) + abs(h[n] - h[n-1]);
    int r = INT_MAX;
    if(n > 1){
        r = solve(n-2,h,dp) + abs(h[n]-h[n-2]);
    }

    return dp[n-1] = min(l,r);

}

int solve2(int n,vector<int> &h){
    vector<int> dp(n+1,0);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        int l = abs(h[i]-h[i-1]) + dp[i-1];
        int r = INT_MAX;
        if(i > 1){
        r = abs(h[i] - h[i-2]) + dp[i-2];
        }
       dp[i] = min(l,r);
    }

    return dp[n];
}

int frogJump(int n, vector<int> &heights)
{
   vector<int> dp(n,-1);
//    return solve(n-1,heights,dp);
return solve2(n-1,heights);
}