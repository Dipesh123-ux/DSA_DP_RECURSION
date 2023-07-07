class Solution {

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m =grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int vis[m][n];

        for(int i = 0; i <  m; i++){
            for(int j = 0; j< n; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }

        int mt = 0;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            q.pop();
            
            mt = max(mt,t);

            for(int i = 0; i < 4; i++){
                int nr = r + dx[i];
                int nc = c + dy[i];
                if(nr >= 0 &&  nr < m && nc >=0 && nc < n && vis[nr][nc] != 2 && grid[nr][nc] == 1){
                    q.push({{nr,nc},t+1});
                    vis[nr][nc] = 2;
                }
            }

        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(vis[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return mt;
       
    }
};