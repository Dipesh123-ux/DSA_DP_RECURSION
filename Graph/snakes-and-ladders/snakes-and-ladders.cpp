class Solution {

    int bfs(int src , int dest,map<int,list<int>> l){
        map<int,int> dist;
        queue<int> q; 

        for(auto pair : l){
            int node = pair.first;
            dist[node] = -1;
        }

        q.push(src);
        dist[src] = 0;

        while(!q.empty()){
            int node = q.front();
              q.pop();

           for(int i : l[node])
            {
                if(dist[i] == -1){
                    q.push(i);
                    dist[i]= dist[node] + 1;
                }
            }
        }

        return dist[dest];
    }
 public:
    int snakesAndLadders(vector<vector<int>>& board) {
        map<int,list<int>> l;
        int n = board.size();
        vector<int> newboard(n*n+1,0);
        int d = true;
        int k = 1;

        for(int i = n -1; i >= 0; i--){
            if(d){
                for(int j = 0; j < n; j++){
                    newboard[k++] = board[i][j];
                }
            }
            else{
                for(int j = n-1; j >= 0; j--){
                    newboard[k++] = board[i][j];
                }
            }
            d = !d;
        }

        for(int i = 0; i <= n*n; i++){
            for(int j = 1; j <= 6; j++){
                int m = i + j;
                
                if(m <= n*n){
                    if(newboard[m] == -1){
                        newboard[m] = m;
                    }
                    l[i].push_back(newboard[m]);
                }
            }
        }

   
        
        l[n*n].push_back(n*n);

        
        int ans = bfs(1,n*n,l);

        return ans;
        

        

    }
};