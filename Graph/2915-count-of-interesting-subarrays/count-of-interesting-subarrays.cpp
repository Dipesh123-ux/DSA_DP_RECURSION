class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        long long pre = 0;

        long long ans = 0;
        unordered_map<long long,long long> mp;

        mp[0] = 1;

        for(int i = 0; i < nums.size();i++){

            if(nums[i]%m == k){
                pre++;
            }

            pre = pre%m;
           
           if(mp.find((pre-k+m)%m) != mp.end()){
               ans += mp[(pre-k+m)%m];
           } 

          mp[pre]++;
           
        }
    

        return ans;
    }
};