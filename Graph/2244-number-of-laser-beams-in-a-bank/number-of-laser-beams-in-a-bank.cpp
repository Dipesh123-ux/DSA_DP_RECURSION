class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
       
       vector<int> v;

       for(auto i : bank){
           int ct = 0;
           for(auto c : i){
               if(c == '1'){
                   ct++;
               }
           }
           v.push_back(ct);
       }

       int ans = 0;
       int prev = 0;

       for(int i = 0; i < v.size();i++){
           if(v[i] == 0){
               continue;
           }
           ans += (v[i]*prev);
           prev =  v[i];
       }

       return ans;
      
    }
};