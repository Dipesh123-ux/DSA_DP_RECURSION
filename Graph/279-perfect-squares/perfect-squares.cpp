class Solution {
public:
    int numSquares(int n) {
      vector<int> dp(n+1,0);
      for(int i = 1; i <= n; i++){
          int ans = INT_MAX;
          for(int j = 1; j <= i; j++){
              if(j*j <= i){
                  ans = min(ans,1+dp[i-j*j]);
              }
          }
          dp[i] = ans;
      }

      return dp[n];
    }
};