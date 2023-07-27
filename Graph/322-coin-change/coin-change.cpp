class Solution {


int solve(int i,vector<int>&coins,int amt,vector<vector<int>>&dp){
    if(i == 0){
        if(amt % coins[0] == 0){
            return (amt/coins[0]);
        }
        return 1e9;
    }

    if(dp[i][amt] != -1) return dp[i][amt];

    int p = INT_MAX;
    if(amt >= coins[i]){
        p = 1 + solve(i,coins,amt-coins[i],dp);
    }
    int np = solve(i-1,coins,amt,dp);

    return dp[i][amt] = min(p,np);
}

public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(n-1,coins,amount,dp) == 1e9 ? -1 : solve(n-1,coins,amount,dp);
    }
};