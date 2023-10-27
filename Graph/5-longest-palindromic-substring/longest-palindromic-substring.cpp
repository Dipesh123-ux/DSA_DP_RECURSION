class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        string ans = "";

        if(s.size() == 1){
            return s;
        }
        
        for(int g = 0; g < n;g++){
            for(int i = 0, j = g; j < n; i++,j++){
                if(g == 0){
                    dp[i][j] = 1;
                }
                else if(g == 1){
                    dp[i][j] = s[i] == s[j];
                }
                else{
                    if(s[i] == s[j] && dp[i+1][j-1] > 0){
                        dp[i][j] = 1;
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }

            }
        }

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(dp[i][j] == 1){
                   string k = s.substr(i,j-i+1);
                   if(k.size() > ans.size()){
                       ans = k;
                   }
                }
            }
            // cout<<endl;
        }




        return ans;

    }
};