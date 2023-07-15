class Solution {

bool cycle_helper(vector<int> l[],int node , vector<int> &visited,vector<bool> &stack,vector<int>&ordering){
        visited[node] = true;
        stack[node] = true;

        for(int i : l[node]){
            if(stack[i]==true){
                return true;
            }
            else if(visited[i] == false){
                bool cycle_found = cycle_helper(l,i,visited,stack,ordering);
                if(cycle_found){
                    return true;
                }
            }
        }
        
        ordering.push_back(node);
        stack[node] = false;
        return false;
    }

public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> ordering;
        vector<int> l[n];
        vector<int> visited(n,0);

        for(int i = 0; i < p.size();i++){
            l[p[i][0]].push_back(p[i][1]);
        }

        vector<bool> stack(n,false);
        for(int i = 0; i < n;i++){
            visited[i] = 0;
        }

        bool ans = false;

        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                ans = ans || cycle_helper(l,i,visited,stack,ordering);
            }
        }
        
        if(ans){
            vector<int> v;
            return v;
        }
        else{
            return ordering;
        }


    }
};