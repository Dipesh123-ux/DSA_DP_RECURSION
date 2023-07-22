class Solution {
public:

int solve(int i,int j,vector<vector<int>>grid){
    if(i == 0 && j == 0){
        return grid[i][j];
    }
    if(i < 0 || j < 0) return 1e9;

    int up = grid[i][j] + solve(i-1,j,grid);
    int left = grid[i][j] + solve(i,j-1,grid);

    return min(up,left);
}


    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        // return solve(m-1,n-1,grid);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    dp[0][0] = grid[i][j];
                    continue;
                }
                int up = grid[i][j] + (i>0 ? dp[i-1][j] : 1e9);
                int left = grid[i][j] + (j>0 ? dp[i][j-1] : 1e9);
                dp[i][j] = min(up,left);
            }
        }
        return dp[m-1][n-1];
    }
};