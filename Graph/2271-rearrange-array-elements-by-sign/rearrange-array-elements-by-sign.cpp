class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> a1;
        vector<int> a2;
        for(auto i  : nums){
            if(i > 0){
                a1.push_back(i);
            }
            else{
                a2.push_back(i);
            }
        }

        int n = a1.size();
        int k = 0;

        for(int i = 0; i < n;i++){
            nums[k] = a1[i];
            nums[k+1] = a2[i];
            k += 2;
        }

        return nums;
    }
};