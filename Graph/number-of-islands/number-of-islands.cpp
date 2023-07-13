class Solution {

void bfs(int i, int j,vector<vector<int>>&visited,int n,int m,vector<vector<char>> grid){
    visited[i][j] = 1;
    queue<pair<int,int>> q;
    q.push({i,j});
    int dx[] = {-1,0,1,0};
    int dy[] = {0,1,0,-1};
    

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int k = 0; k <= 3; k++){
                int nr = r + dx[k];
                int nc = c + dy[k];
                if(nr >= 0 && nc >=0 && nr < n && nc < m && visited[nr][nc] == 0 && grid[nr][nc] == '1'){
                    visited[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
    }

}



public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m  = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(visited[i][j] == 0 && grid[i][j] == '1'){
                    ans++;
                    bfs(i,j,visited,n,m,grid);
                }
            }
        }

        return ans;
    }
};