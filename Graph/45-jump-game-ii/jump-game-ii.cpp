class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
         vector<int> dp(n,INT_MAX);

         dp[n-1] = 0;
         
        for(int i = n-2; i >=0 ; i--){
            int steps = nums[i];
            int ans = n;
            for(int j = 1; j <= steps && (i+j) < n; j++){
                 ans = min(ans,dp[i+j]);
            }
            dp[i] = 1 + ans;
        }

        return dp[0];
    }
};