class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int ans = 0;

        int c = 0;

        while(j < nums.size()){
            if(nums[j] == 0){
                c++;
            }
            if(c <= 1){
                j++;
                ans = max(ans,j-i-1);
            }
            else{
                while(c != 1){
                    if(nums[i] == 0){
                        c--;
                    }
                    i++;
                }
                j++;
            }
        }

        return ans;

    }
};