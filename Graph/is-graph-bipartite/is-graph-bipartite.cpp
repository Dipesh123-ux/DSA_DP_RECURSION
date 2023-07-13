class Solution {

bool dfs(vector<vector<int>>& graph,int src,int parent,int color,vector<int>&visited){
    visited[src] = color;
    for(auto nbr : graph[src]){
        if(visited[nbr]==0){
            if(dfs(graph,nbr,src,3-color,visited) == false){
                return false;
            }
        }
        else if(nbr != parent && visited[nbr] == color){
            return false;
        }
    }
    return true;
}

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> visited(v,0);
        bool ans = false;
        for(int i = 0; i < v;i++){
            if(visited[i] == 0){
                 if(dfs(graph,i,-1,1,visited) == false){
                     return false;
                 }
            }
        }
        return true;
    }
};