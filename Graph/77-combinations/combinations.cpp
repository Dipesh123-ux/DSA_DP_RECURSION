class Solution {

void solve(int i,int n,int k,vector<vector<int>>&ans,vector<int>v){
    
    if(v.size() == k){
        ans.push_back(v);
       return;
    }
  
  for(int j = i; j <= n; j++){
    v.push_back(j);
    solve(j+1,n,k,ans,v);
    v.pop_back();
  }
}

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
         solve(1,n,k,ans,v);
         return ans;
    }
};