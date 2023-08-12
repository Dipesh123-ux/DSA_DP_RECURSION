class Solution {

int solve(int i, int j,vector<vector<int>> &nums,vector<vector<int>>&dp){
    if(i < 0 || j < 0) return 0;
    if(nums[i][j] == 1) return 0;
    if(i == 0 && j == 0) return 1;

    if(dp[i][j] != -1) return dp[i][j];

    int l = solve(i,j-1,nums,dp);
    int t = solve(i-1,j,nums,dp);

    return dp[i][j] =  l + t;

}

public:
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
      int m = obstacleGrid.size();
      int n = obstacleGrid[0].size();
      vector<vector<int>> dp(m,vector<int>(n,0));
      dp[0][0] = 1;
      vector<int> prev(n,0);

      for(int i = 0; i < m; i++){
          vector<int> curr(n,1);
          for(int j = 0; j < n; j++){
              if(obstacleGrid[i][j] == 1) curr[j] = 0;
              else if(i == 0 && j == 0 ) curr[j] = 1;
              else{
              int l = 0 , r = 0;
              if(i > 0) {l = prev[j];}
              if(j > 0){ r = curr[j-1];}
              curr[j] = l + r;
              }
          }
          prev = curr;
      }

      return prev[n-1];

    }
};