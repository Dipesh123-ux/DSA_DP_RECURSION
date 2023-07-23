class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        
        long long sum = 0, ans = 0;

        for(int i = nums.size()-1; i >= 0; i--){
            
            sum = (nums[i] > sum) ? nums[i] : nums[i] + sum;
            ans = max(ans,sum);
        }

     return ans;

    }
};