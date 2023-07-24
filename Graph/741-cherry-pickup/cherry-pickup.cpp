class Solution {



// void cp1(int i,int j,int m,int n,vector<vector<int>>&grid,int cc,int &ans){

//    if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == -1) return;

//    if(i == m-1 && j == n-1){
//        int cherries = grid[i][j];
//        grid[i][j] = 0;
//        helper(i,j,m,n,grid,cc+cherries,ans);
//        grid[i][j] = cherries;
//    }

//     int cherries = grid[i][j];
//     grid[i][j] = 0;
//     cp1(i+1,j,m,n,grid,cc+cherries,ans);
//     cp1(i,j+1,m,n,grid,cc+cherries,ans);
//     grid[i][j] = cherries;

// }

// void helper(int i,int j,int m,int n,vector<vector<int>>&grid,int cc,int &ans){
//      if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == -1) return;

//      if(i == 0 && j == 0){
//          ans = max(ans,cc);
//          return;
//      }
//     int cherries = grid[i][j];
//     grid[i][j] = 0;
//     helper(i-1,j,m,n,grid,cc+cherries,ans);
//     helper(i,j-1,m,n,grid,cc+cherries,ans);
//     grid[i][j] = cherries;
// }

int cp1(int r1,int c1,int r2,int c2,vector<vector<int>>&grid,vector<vector<vector<vector<int>>>>&dp,int n){
      if(r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1) return INT_MIN;
       
      if(r1 == n-1 && c1 == n-1){
          return grid[r1][c1];
      }

      if(dp[r1][c1][r2][c2] != -1) return dp[r1][c1][r2][c2];

      int cherries = 0;

      if(r1 == r2 && c1 == c2){
          cherries += grid[r1][c1];
      }
      else{
          cherries += (grid[r1][c1] + grid[r2][c2]);
      }

      int f1 = cp1(r1+1,c1,r2+1,c2,grid,dp,n);
      int f2 = cp1(r1+1,c1,r2,c2+1,grid,dp,n);
      int f3 = cp1(r1,c1+1,r2+1,c2,grid,dp,n);
      int f4 = cp1(r1,c1+1,r2,c2+1,grid,dp,n);

      cherries += max(max(f1,f2),max(f3,f4));

      return dp[r1][c1][r2][c2] = cherries;
}


public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<vector<vector<vector<int>>>> dp(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));
     return (cp1(0,0,0,0,grid,dp,n) < 0 ? 0 :  cp1(0,0,0,0,grid,dp,n));
    }
};