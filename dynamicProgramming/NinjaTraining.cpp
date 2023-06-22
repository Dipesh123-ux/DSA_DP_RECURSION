#include <bits/stdc++.h>

int solve(int n,vector<vector<int>> &p,int prev,vector<vector<int>>&dp){
    if(n == 0){
        int maxi = 0;
        for(int j = 0; j <= 2;j++){
            if(j != prev){
                maxi = max(maxi,p[0][j]);
            }
        }
        
        return maxi;
    }
    
    if(dp[n][prev] != -1) return dp[n][prev];

    int ans = INT_MIN;

    for(int d = 0; d < 3; d++){
         int temp = INT_MIN;
        if(d != prev){
             temp = p[n][d] + solve(n-1,p,d,dp);       
        }
        ans = max(ans,temp);
    }

    return dp[n][prev]=ans;
}

int ninjaTraining(int n, vector<vector<int>> &p)
{
    vector<vector<int>> dp(n,vector<int>(4,-1));
    dp[0][0] = max(p[0][1],p[0][2]);
    dp[0][1] = max(p[0][0],p[0][2]);
    dp[0][2] = max(p[0][0],p[0][1]);
    dp[0][3] = max(p[0][0],max(p[0][1],p[0][2]));
    // return solve(n-1,p,3,dp);
    for(int days = 1; days < n; days++){
        for(int last = 0; last <= 3; last++){
            for(int j = 0 ;  j <= 2; j++){
                if(j != last){
                     int points = p[days][j] + dp[days-1][j];
                    dp[days][last] = max(dp[days][last],points);
                }
            }
        }
    }

    return dp[n-1][3];
}