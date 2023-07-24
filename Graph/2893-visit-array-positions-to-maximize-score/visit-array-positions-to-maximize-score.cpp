class Solution {

long long solve(int i, vector<int>&nums,int x, int p,vector<vector<long long>>&dp){
    if(i == nums.size()) return 0;

    if(dp[i][p] !=-1) return dp[i][p];
    
    long long pi = 0;
    if(nums[i]%2 == p){
        pi =  nums[i] + solve(i+1,nums,x,nums[i]%2,dp);
    }
    else{
        pi = nums[i] - x + solve(i+1,nums,x,nums[i]%2,dp);
    }

    long long np = solve(i+1,nums,x,p,dp);

    return dp[i][p] = max(pi,np);
}

public:
    long long maxScore(vector<int>& nums, int x) {
       vector<vector<long long>> dp(nums.size(),vector<long long>(2,-1));
        return nums[0] + solve(1,nums,x,nums[0]%2,dp);
    }
};