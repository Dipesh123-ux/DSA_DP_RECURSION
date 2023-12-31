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

        // vector<vector<bool>>dp(n,vector<bool>(m+1,false));
         vector<bool> prev(m+1,false) , curr(m+1,false);
      
            prev[0] = true;
        

        for(int i = 1; i < n; i++){
            for(int k = 0; k <= m; k++){
                bool p = false;
                if(nums[i] <= k){
                    p = prev[k-nums[i]];
                }
                bool np = prev[k];
                curr[k] = p || np;
            }
            prev = curr;
        }

        return prev[m];
        
        // return solve(0,n,m,nums,dp);
    }
};