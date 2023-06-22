int mod = int(1e9 + 7);


int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m; j++){
            if(mat[i][j] == -1) dp[i][j] = 0;
            else if(i == 0 && j == 0) dp[0][0] = 1;
            else{
                int l = 0 , r = 0;
                if(j> 0)  l = dp[i][j-1];
                if(i > 0) r = dp[i-1][j];
                dp[i][j] = (l + r)%mod;
            }
        }
    }
    
    return dp[n-1][m-1];
}