class Solution {
map<char,int> track,m;
unordered_map<string,long long> dp;
vector<int>power;
long long mod = 1e9 + 7;
int mb = 0;
long long solve(int i,int k,int mb){
   
   if(i == power.size()){
       return (k==0 && mb == 0);
   }

    string f = to_string(i) + "#" + to_string(k) + "#" + to_string(mb);

    if(dp.find(f) != dp.end()){
        return dp[f];
    }
   
  
    long long  p =  power[i]*solve(i+1,k-1,mb-power[i])%mod;
 
    long long np = solve(i+1,k,mb)%mod;

    return dp[f] = (p + np)%mod;
}

    
public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        int n = s.size();
        for(auto c : s){
            m[c]++;
        }

        if(k > m.size()) return 0;
        
    
        for(auto p : m){
            power.push_back(p.second);
        }
        sort(power.rbegin(), power.rend());

        for(int i = 0; i < k; i++){
            if(i >= power.size())return 0;
            mb += power[i];
        }
     
        return solve(0,k,mb);
        
    }
};