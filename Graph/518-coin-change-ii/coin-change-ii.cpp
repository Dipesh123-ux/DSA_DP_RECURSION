class Solution {

int solve(int i,int amount,vector<int>&coins,vector<vector<int>>&dp){

  
   if(i == 0){
       if(amount % coins[0] == 0){
           return 1;
       }

       return 0;
   }

  if(dp[i][amount] != -1) return dp[i][amount];

    int p = 0;

    if(amount >= coins[i]){
        p = solve(i,amount - coins[i],coins,dp);
    }

    int np = solve(i-1,amount,coins,dp);

    return dp[i][amount] = (p + np);
}

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount+1,0);
        // return solve(n-1,amount,coins,dp);
        
        dp[0] = 1;

        for(int i = 0; i < n; i++){
            for(int j = 1; j <= amount; j++){
                if(j >= coins[i]){
                    dp[j] += dp[j-coins[i]];
                }
            }
        }

        return dp[amount];
    }
};