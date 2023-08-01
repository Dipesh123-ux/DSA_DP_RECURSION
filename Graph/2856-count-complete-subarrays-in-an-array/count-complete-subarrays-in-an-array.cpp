class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int i = 0, j = 0;
        map<int,int> m1;
        for(int i : nums){
            m1[i]++;
        }
        int k = m1.size();
        int ans = 0;
        int c = 0;
        map<int,int> m;
        while( j < nums.size()){
            
                m[nums[j]]++;
            
                while(m.size() == k){
                    m[nums[i]]--;
                    if(m[nums[i]] == 0){
                        m.erase(nums[i]);
                    }
                    i++;
                    ans += (nums.size()-j);
                }

            j++;
        }
       
        return ans;
    }
};