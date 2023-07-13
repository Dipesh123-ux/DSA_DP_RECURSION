class Solution {

int bfs(int src,map<int,list<int>> &l,int n){
    vector<int> dis(n+1,INT_MAX);
    int ans  = INT_MAX;
    queue<int> q;
    q.push(src);
    dis[src] = 0;
    
    while(!q.empty()){
        int curr = q.front();
         q.pop();
        for(auto nbr : l[curr]){
            if(dis[nbr] == INT_MAX){
                q.push(nbr);
                dis[nbr] = dis[curr] + 1;
            }
            else if(dis[nbr] >= dis[curr]){
                ans = min(ans,dis[nbr] + dis[curr]+1);
            }
        }
    }

    return ans;
}


public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<int> dis(n+1,INT_MAX);
        map<int,list<int>> l;
        for(int i = 0; i < edges.size();i++){
            l[edges[i][0]].push_back(edges[i][1]);
            l[edges[i][1]].push_back(edges[i][0]);
        }

        int ans = n + 1;

        for(int i = 0; i < n; i++){
            if(dis[i] == INT_MAX ){
               ans = min(ans,bfs(i,l,n));
            }
        }

        if(ans == n + 1){
            return -1;
        }
        else{
            return ans;
        }

    }
};