class Solution {

    long long mod = 1e9+7;
    
    int solve(int n,int x,int i,vector<vector<long long>>&dp){
      if(n == 0) return 1;
      if(n < 0) return 0;
      int power = pow(i,x);
      if(power > n){
          return 0;
      }

      if(dp[n][i] != -1) return dp[n][i];

      int p = solve(n-power,x,i+1,dp)%mod;
      int np = solve(n,x,i+1,dp)%mod;
      return dp[n][i] = (p + np)%mod;

    }
    
public:
    int numberOfWays(int n, int x) {
      vector<vector<long long>> dp(n+1,vector<long long>(n+1,-1));
       return solve(n,x,1,dp);
    }
};