class Solution {

bool solve(int i, int n,int k,vector<int>&nums,vector<vector<int>>&dp){
    if(k == 0){
        return true;
    }
    if(i >= n){
        return false;
    }

    if(dp[i][k] != -1){
        return dp[i][k];
    }

    bool p = false;
    
    if(nums[i] <= k){
        p = solve(i+1,n,k-nums[i],nums,dp);
    }

    bool np = solve(i+1,n,k,nums,dp);
    
    return dp[i][k] = (p || np);
    
}


public:
    bool canPartition(vector<int>& nums) {
        int s = 0;
        for(int i : nums){
            s += i;
        }

        if(s%2 == 1){
            return false;
        }

        int m = s/2;
        int n = nums.size();

        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        
        return solve(0,n,m,nums,dp);
    }
};