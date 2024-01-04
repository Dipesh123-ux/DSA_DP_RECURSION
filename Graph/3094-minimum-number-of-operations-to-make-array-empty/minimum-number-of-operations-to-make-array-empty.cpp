class Solution {
public:
    int minOperations(vector<int>& nums) {
       map<int,int> m;
       for(auto i : nums){
           m[i]++;
       }
       int ans = 0;
       for(auto p : m){
           if(p.second == 1){
               return -1;
           }
           
           if(p.second%3 == 0){
               ans += (p.second/3);
           }
           else{
               ans += ((p.second/3)+1);
           }

       }

       return ans;
    }
};