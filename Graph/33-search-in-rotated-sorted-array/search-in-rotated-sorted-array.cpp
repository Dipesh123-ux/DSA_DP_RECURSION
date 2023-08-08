class Solution {

int minIndex(int s,int e,vector<int>&nums){
    int n = nums.size();
    while(s <= e){
        int m = s + (e-s)/2;
        int prev = (m-1+n)%n;
        int next = (m+1)%n;
        if(nums[m] <= nums[prev] && nums[m] <= nums[next]){
            return m;
        }
        else if(nums[m] > nums[e]){
            s = m + 1;
        }
        else{
            e = m -1;
        }
    }

    return -1;
}

int binary(int s,int e,int target,vector<int>&nums){
    while(s <= e){
        int m = s + (e-s)/2;
        if(nums[m] == target){
            return m;
        }
        else if(nums[m] > target){
            e = m - 1;
        }
        else{
            s = m + 1;
        }
    }
    return -1;
}

public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        int mi = minIndex(s,e,nums);
        if(nums[mi] == target) return mi;
        int ls = binary(s,mi-1,target,nums);
        int rs = binary(mi+1,e,target,nums);
        if(ls == -1 && rs == -1){
            return -1;
        }
        else if(ls == -1){
            return rs;
        }
        else{
            return ls;
        }
    }
};