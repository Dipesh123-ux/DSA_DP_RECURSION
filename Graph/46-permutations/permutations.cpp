class Solution {

void solve(int i,vector<int>&nums,vector<int>&v,vector<vector<int>>&ans){
    if(v.size() == nums.size()){
        ans.push_back(v);
        return;
    }

    for(int j = i; j < nums.size();j++){
        swap(nums[i],nums[j]);
        v.push_back(nums[i]);
        solve(i+1,nums,v,ans);
        swap(nums[i],nums[j]);
        v.pop_back();
    }
}

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        solve(0,nums,v,ans);
        return ans;
    }
};