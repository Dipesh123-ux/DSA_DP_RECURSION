class Solution {

int res;

void solve(int i,vector<pair<int,int>>&v2,vector<vector<int>>&grid,int sum){
    if(i == v2.size()){
        res = min(res,sum);
        return;
    }

   int x = v2[i].first;
   int y = v2[i].second;

   if(grid[x][y] == 1){
       solve(i+1,v2,grid,sum);
       return;
   }

   for(int m = 0; m < 3; m++){
       for(int j = 0; j < 3; j++){
           if(grid[m][j] == 0){
               int d = abs(x-m) + abs(y-j);
               grid[x][y]--;
               grid[m][j] = 1;
               solve(i,v2,grid,sum+d);
               grid[x][y]++;
               grid[m][j] = 0;
           }
       }
   }

   return;

}

public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int,int>> v2;
        res = INT_MAX;

        for(int i = 0; i < 3;i++){
            for(int j = 0; j < 3; j++){
                if(grid[i][j] > 1){
                    v2.push_back({i,j});
                }
            }
        }


         solve(0,v2,grid,0);

         return res;
    }
};