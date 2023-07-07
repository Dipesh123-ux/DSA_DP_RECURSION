class Solution {

int count(string nums,int k,char ch){
    int i = 0;
    int j = 0;
    int c = 0;
    int maxLen = 0;

    while(j < nums.size()){
        if(nums[j] != ch) c++;
        while(i <= j  && c > k){
             if(nums[i] != ch){
                 c--;
             }
             i++;
        }
        maxLen = max(maxLen,j-i+1);
        j++;

    }

    return maxLen;
}

public:
    int maxConsecutiveAnswers(string nums, int k) {
        return max(count(nums,k,'T'),count(nums,k,'F'));
    }
};