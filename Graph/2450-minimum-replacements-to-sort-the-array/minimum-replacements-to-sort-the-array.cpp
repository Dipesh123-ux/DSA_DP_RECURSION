class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
   
            int n = nums.size()-1;
            long long ans = 0;
            int last = nums[n];
            
            for(int i = n-1; i >= 0; i--){
                if(nums[i] > last){
                    int div = nums[i]/last;
                    if(nums[i] % last) div++;
                    
                    last = nums[i] /div;
                    ans += (div-1);
                }
                else{
                    last = nums[i];
                }
            }

            return ans;
        
    }
};