class Solution {
public:

   void solve(int n,string s,vector<string>&ans,int op,int cl){
       if(s.size() == 2*n){
           ans.push_back(s);
           return;
       }

       if(op < n){
           solve(n,s+'(',ans,op+1,cl);
       }

       if(cl < op){
           solve(n,s+')',ans,op,cl+1);
       }

      return;

   }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        solve(n,s,ans,0,0);
        return ans;
    }
};