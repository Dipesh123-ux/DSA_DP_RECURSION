class Solution {
public:
  
  bool solve(int i,int n,vector<int>&nums,vector<int>&dp){
      if(i == n){
          return true;
      }
      bool  res = false;
      if(dp[i] != -1){
          return dp[i];
      }
      if((i < n-1) && (nums[i] == nums[i+1])){
         res = solve(i+2,n,nums,dp);
      }
        if(i < n-2){
          if((nums[i] == nums[i+1] && nums[i+1] == nums[i+2]) || (nums[i] + 1 == nums[i+1] && nums[i+1] == nums[i+2] -1) ){
              res = res or solve(i+3,n,nums,dp);
          }
      }

      return dp[i] = res;
  }


    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(0,nums.size(),nums,dp);
    }
};