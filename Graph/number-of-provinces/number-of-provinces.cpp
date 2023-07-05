class Solution {

void dfs_helper(int src,map<int,bool>&visited,vector<vector<int>>c){
    visited[src] = true;
    for(int i = 0; i < c.size();i++){
        if(c[src][i] && !visited[i]){
            dfs_helper(i,visited,c);
        }
    }
}


int dfs(vector<vector<int>>&c){
    int n = c.size();
     map<int,bool> visited;
     for(int i = 0; i < n; i++){
         visited[i] = false;
     }
     int count = 0;

     for(int i = 0; i < n; i++){
         if(!visited[i]){
             dfs_helper(i,visited,c);
             count++;
         }
     }
     return count;
}


public:
    int findCircleNum(vector<vector<int>>& c) {
       
        return dfs(c);
    }
};