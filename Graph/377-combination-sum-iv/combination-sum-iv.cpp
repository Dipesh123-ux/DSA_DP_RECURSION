class Solution {

int solve(int i, vector<int>&nums,int t,vector<vector<int>>&dp){

  
    if(t == 0){
        return 1;
    }

    if(dp[i][t] != -1){
        return dp[i][t];
    }

    int ans = 0;

    for(int j = i; j < nums.size();j++){
        swap(nums[i],nums[j]);
        if(t >= nums[i]){
        ans += solve(i,nums,t-nums[i],dp);
        }
        swap(nums[i],nums[j]);
    }

    return dp[i][t] = ans;

}
public:
    int combinationSum4(vector<int>& nums, int target) {
       
         vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        return solve(0,nums,target,dp);
     
    }
};