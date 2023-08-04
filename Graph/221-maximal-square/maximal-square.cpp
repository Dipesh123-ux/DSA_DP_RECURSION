class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i = m-1;i >= 0;i--){
            for(int j = n-1;j >= 0; j--){
                if(i == m-1 && j == n-1){
                    dp[i][j] = matrix[i][j]-'0';
                }
                else if(i == m-1){
                    dp[i][j] = matrix[i][j]-'0';
                }
                else if(j == n-1){
                    dp[i][j] = matrix[i][j]-'0';
                }
                else{
                    if(matrix[i][j]-'0' == 0){
                        dp[i][j] = 0;
                    }
                    else{
                        int mi = min(dp[i][j+1],dp[i+1][j]);
                        mi = min(mi,dp[i+1][j+1]);
                        dp[i][j] = 1 + mi;
                    }
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans,dp[i][j]);
            }
        }

        return ans*ans;
    }
};