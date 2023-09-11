class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        vector<vector<int>> ans;
        // vector<pair<int,int>> v;
        // for(int i = 0; i < g.size();i++){
        //      v.push_back({g[i],i});
        // }

        // sort(v.begin(),v.end());

        map<int,vector<int>> m;

        for(int i = 0 ; i < g.size();i++){
            m[g[i]].push_back(i);
        }

        for(auto p : m){
            int s = p.first;
             vector<int> v;
            for(int j = 0; j < p.second.size();j++){
                v.push_back(p.second[j]);
                if((j+1)%s == 0){
                    ans.push_back(v);
                    v.clear();
                }
            }
        }


        return ans;

    }
};