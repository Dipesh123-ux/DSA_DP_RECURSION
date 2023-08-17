class Solution {


public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       int n = mat.size();
       int m = mat[0].size();
       vector<vector<int>> visited(n,vector<int>(m,0));
       vector<vector<int>> dis(n,vector<int>(m,0));

       queue<pair<pair<int,int>,int>> q;

       for(int i = 0; i < n; i++){
           for(int j = 0; j < m; j++){
               if(mat[i][j] == 0){
                   q.push({{i,j},0});
                   visited[i][j] = 1;
               }
           }
       }

       int dx[] = {1,-1,0,0};
       int dy[] = {0,0,1,-1};

       while(!q.empty()){
           int r = q.front().first.first;
           int c = q.front().first.second;
           int distance = q.front().second;
           q.pop();
           dis[r][c] = distance;

           for(int k = 0; k < 4; k++){
               int nr = r + dx[k];
               int nc = c + dy[k];
               if(nr >= 0 && nc >= 0 && nr < n && nc < m && visited[nr][nc] == 0 && mat[nr][nc] == 1){
                   q.push({{nr,nc},distance+1});
                   visited[nr][nc] = 1;

               }
           }
       }

       return dis;
    }
};