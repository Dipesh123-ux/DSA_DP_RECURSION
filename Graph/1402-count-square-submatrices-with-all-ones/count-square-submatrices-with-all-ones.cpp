class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(j == m-1 || i == n-1){
                    dp[i][j] = matrix[i][j];
                }
                else{
                    if(matrix[i][j] != 0){
                    int m = min(dp[i][j+1],dp[i+1][j]);
                    dp[i][j] = 1 + min(m,dp[i+1][j+1]);
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
            }
        }

        int s = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                 s += dp[i][j];
            }
        }


        return s;
        

    }
};