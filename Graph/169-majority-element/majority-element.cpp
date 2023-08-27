class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = 1;
        int idx = 0;
        for(int i = 1; i < nums.size();i++){
            if(nums[idx] == nums[i]){
                c++;
            }
            else{
                c--;
            }
            if(c == 0){
                c = 1;
                idx = i;
            }
        }

        int count = 0;
        int ele = nums[idx];

        for(int i = 0; i < nums.size();i++){
            if(nums[i] == ele){
                count++;
            }
        }

        if(count > nums.size()/2){
            return ele;
        }
        else{
            return -1;
        }
    }
};