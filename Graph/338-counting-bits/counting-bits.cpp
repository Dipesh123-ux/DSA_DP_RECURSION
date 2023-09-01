class Solution {
public:

   int count(int n){
       int c = 0;
       while(n != 0){
           int lb = n&1;
           if(lb){
               c++;
           }
           n = n/2;
       }
       return c;
   }


    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++){
            int res = count(i);
            ans.push_back(res);
        }

        return ans;
    }
   
};