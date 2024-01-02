class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {

 map<int,int> m;
 for(int i : nums){
     m[i]++;
 }

 int ma = 0;

 for(auto p : m){
     if(p.second > ma){
         ma = p.second;
     }
 }

 vector<vector<int>> ans;

 for(int i = 0; i < ma; i++){
     vector<int> v;
     for(auto p : m){
         if(p.second > 0){
             v.push_back(p.first);
             m[p.first]--;
         }
     }
     ans.push_back(v);
 }

 return ans;

    }
};