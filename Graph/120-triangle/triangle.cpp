class Solution {

int solve(int i,int j,vector<vector<int>>&nums){
    if(i == nums.size()-1){
        int ans = 1e9;
        for(int j = 0; j < nums[i].size();j++){
            ans = min(ans,nums[i][j]);
        }
        return ans;
    }
    int niche = nums[i][j] + solve(i+1,j,nums);
    int baju = nums[i][j] + solve(i+1,j+1,nums);

    return min(niche,baju);
}


public:
    int minimumTotal(vector<vector<int>>& t) {
        // return solve(0,0,triangle);
        int m = t.size();
        int n = t[m-1].size();
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        vector<int> prev(n,0) , curr(n,0);

        for(int j = 0; j < n; j++){
            prev[j] =  t[m-1][j];
        }

        for(int i = m -2; i >= 0; i--){
            for(int j = i; j >= 0; j--){
                int niche = t[i][j] + prev[j];
                int baju = t[i][j] + prev[j+1];
                curr[j] = min(niche,baju);
            }
            prev = curr;
        }

        return prev[0];
        
    }
};