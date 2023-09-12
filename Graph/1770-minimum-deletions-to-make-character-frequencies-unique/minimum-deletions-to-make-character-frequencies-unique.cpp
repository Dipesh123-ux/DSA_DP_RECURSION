class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> m;
        for(auto c : s){
            m[c]++;
        }
        int ans = 0;
        map<int,int> m1;
        for(auto p : m){
            if(m1.find(p.second) != m1.end()){
                int c = p.second;
                while(m1.find(c) != m1.end() && c >= 0){
                     c--;
                     ans++;
                }
                if(c != 0){
                m1[c]++;
                }
            }
            else{
                m1[p.second]++;
            }
        }

        return ans;
    }
};