class Solution {

void dfs_helper(int src,map<int,bool>&visited,map<int,list<int>>l){
    visited[src] = true;
    for(auto nbr : l[src]){
        if(!visited[nbr]){
            dfs_helper(nbr,visited,l);
        }
    }
}


int dfs(map<int,list<int>>&l){
     map<int,bool> visited;
     for(auto p : l){
         visited[p.first] = false;
     }
     int count = 0;

     for(auto node : l){
         if(!visited[node.first]){
             dfs_helper(node.first,visited,l);
             count++;
         }
     }
     return count;
}


public:
    int findCircleNum(vector<vector<int>>& c) {
        map<int,list<int>> l;
        int n =c.size();
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                if(c[i][j] == 1){
                    l[i+1].push_back(j+1);
                }
            }

        }

        return dfs(l);
    }
};