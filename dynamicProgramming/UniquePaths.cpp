#include <bits/stdc++.h> 

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n));
     dp[0][0] = 1;
     
     for(int  i = 0 ; i < m; i++){
         for(int j = 0 ; j < n; j++){
            if(i == 0 && j == 0) dp[0][0] = 1;
            else{
                int l = 0, r = 0 ;
               if(j > 0){  l = dp[i][j-1];}
                if(i > 0){
                r = dp[i-1][j];
                    }
                dp[i][j] = l + r;
            }
         }
         
     }
    
    return dp[m-1][n-1];
}