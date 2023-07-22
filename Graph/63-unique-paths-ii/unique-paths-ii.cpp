class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {

    int m = obs.size();
    int n = obs[0].size();

     vector<vector<int>> dp(m,vector<int>(n,0));

          for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(obs[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                if(i == 0 && j ==0 ){
                    dp[i][j] = 1;
                    continue;
                }
             
                int up =(i > 0 ?  dp[i-1][j] : 0);
                int left =(j > 0 ? dp[i][j-1] : 0);
                dp[i][j] = up + left;
            }
        }

        return dp[m-1][n-1];
    }
};