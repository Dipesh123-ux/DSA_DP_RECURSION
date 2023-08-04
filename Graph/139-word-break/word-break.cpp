class Solution {
public:

bool solve(int i,vector<int>&dp,string s,set<string>&st){
    if(i == s.size()){
        return true;
    }

    if(dp[i] != -1){
        return dp[i];
    }
    string temp;
    for(int j = i; j < s.size();j++){
         temp += s[j];
         if(st.contains(temp)){
             if(solve(j+1,dp,s,st)){
                 return dp[i] = true;
             }
         }

    }

    return dp[i] = false;
}

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        for(auto c : wordDict){
            st.insert(c);
        }
        int n = s.size();
        vector<int> dp(n+1,0);
         
        dp[n] = 1;

        for(int i = n-1; i >= 0; i--){
            string temp;
            for(int j = i; j < n; j++){
                temp += s[j];
                if(st.contains(temp)){
                    if(dp[j+1]){
                        dp[i] = true;
                    }
                }
            }
        }

        return dp[0];



        
        // return solve(0,dp,s,st);

    }
};