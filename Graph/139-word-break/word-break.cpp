class Solution {
public:

unordered_map<string,bool> dp;

bool solve(string s, unordered_map<string,int>&m){
    if(s.size() == 0){
        return true;
    }

    if(dp.find(s) != dp.end()){
        return dp[s];
    }

    for(int i = 0; i < s.size();i++){
        string temp = s.substr(0,i+1);
        if(m.find(temp) != m.end()){
             if(solve(s.substr(i+1),m)){
                 return dp[s] = true;
             }
        }
    }
    return dp[s] = false;
}


    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> m;
        for(string c : wordDict){
            m[c]++;
        }

        return solve(s,m);
    }
};