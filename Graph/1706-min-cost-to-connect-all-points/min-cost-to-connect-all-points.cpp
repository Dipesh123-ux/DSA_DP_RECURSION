class DSU{

    int *parent;
    int *rank;

    public:
    DSU(int n){
        parent = new int[n];
        rank = new int[n];

        for(int i = 0; i <n; i++){
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int  find_Set(int i){
        if(parent[i] == -1){
            return i;
        }

        return parent[i] =find_Set(parent[i]);
    }

    void unite(int x  , int y){
        int s1 = find_Set(x);
        int s2 = find_Set(y);
        
        if(s1 != s2){
            if(rank[s1] < rank[s2]){
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else{
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }

};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
         int ans = 0;
         int n = p.size();
         vector<vector<int> >edgelist;

         for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                int w = abs(p[i][0]-p[j][0]) + abs(p[i][1]-p[j][1]);
                edgelist.push_back({w,i,j});
            }
         }

        DSU s(n);

        sort(edgelist.begin(),edgelist.end());

          for(auto edge : edgelist){
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            if(s.find_Set(x) != s.find_Set(y)){
                s.unite(x,y);
                ans += w;
            }
        }

       
         return ans;
    }
};